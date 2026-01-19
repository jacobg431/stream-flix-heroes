#include <sstream>
#include "GenericWatchHistoryRepository.hpp"

GenericWatchHistoryRepository::GenericWatchHistoryRepository(DbConnection &dbConnection) :
    _dbConnection(dbConnection)
{}

WatchHistory GenericWatchHistoryRepository::selectWatchHistoryById(int watchId)
{
    std::string query = std::string("")
                        + "SELECT \"UserId\", \"MovieId\", \"WatchDate\", \"CompletionPercentage\" "
                        + "FROM \"WatchHistory\" "
                        + "WHERE \"WatchId\" = " + std::to_string(watchId) + " "
                        + "LIMIT 1;";
     
    PGresult *result = _dbConnection.Execute(query);

    int userId = std::stoi(PQgetvalue(result, 0, 0));
    int movieId = std::stoi(PQgetvalue(result, 0, 1));
    std::string watchDateString = PQgetvalue(result, 0, 2);
    double completionPercentage = std::stod(PQgetvalue(result, 0, 3));
    
    std::stringstream ss(watchDateString);
    std::chrono::system_clock::time_point watchDate;
    ss >> std::chrono::parse("%F %T", watchDate);

    if (ss.fail())
    {
        throw std::runtime_error("SQL DATETIME to chrono time point object conversion failed");
    }

    WatchHistory(userId, watchId, movieId, watchDate, completionPercentage);
}

WatchHistory GenericWatchHistoryRepository::selectWatchHistoryByUserIdAndMovieId(int userId, int movieId)
{
    std::string query = std::string("")
                        + "SELECT \"WatchId\", \"WatchDate\", \"CompletionPercentage\" "
                        + "FROM \"WatchHistory\" "
                        + "WHERE \"UserId\" = " + std::to_string(userId) + " AND \"MovieId\" = " + std::to_string(movieId) + " "
                        + "LIMIT 1;";
     
    PGresult *result = _dbConnection.Execute(query);

    int watchId = std::stoi(PQgetvalue(result, 0, 0));
    std::string watchDateString = PQgetvalue(result, 0, 1);
    double completionPercentage = std::stod(PQgetvalue(result, 0, 2));
    
    std::stringstream ss(watchDateString);
    std::chrono::system_clock::time_point watchDate;
    ss >> std::chrono::parse("%F %T", watchDate);

    if (ss.fail())
    {
        throw std::runtime_error("SQL DATETIME to chrono time point object conversion failed");
    }

    WatchHistory(userId, watchId, movieId, watchDate, completionPercentage);
}


std::vector<WatchHistory> GenericWatchHistoryRepository::selectWatchHistoriesWithCompletionPercentage(double completionPercentage)
{
    std::string query = std::string("")
                        + "SELECT \"WatchId\", \"UserId\", \"MovieId\", \"WatchDate\", \"CompletionPercentage\" "
                        + "FROM \"WatchHistory\" "
                        + "WHERE \"CompletionPercentage\" >= " + completionPercentage + ";";
     
    PGresult *result = _dbConnection.Execute(query);

    std::vector<WatchHistory> watchHistories;
    int rows = PQntuples(result);

    for (int i = 0; i < rows; ++i)
    {
        int watchId = std::stoi(PQgetvalue(result, i, 0));
        int userId = std::stoi(PQgetvalue(result, i, 1));
        int movieId = std::stoi(PQgetvalue(result, i, 2));
        std::string watchDateString = PQgetvalue(result, i, 3);
        double completionPercentage = std::stod(PQgetvalue(result, i, 4));

        std::stringstream ss(watchDateString);
        std::chrono::system_clock::time_point watchDate;
        ss >> std::chrono::parse("%F %T", watchDate);

        if (ss.fail())
        {
            throw std::runtime_error("SQL DATETIME to chrono time point object conversion failed");
        }

        WatchHistory watchHistory(userId, watchId, movieId, watchDate, completionPercentage);
        watchHistories.push_back(watchHistory);
    }

}

std::vector<WatchHistory> GenericWatchHistoryRepository::selectWatchHistoriesLaterThan(std::chrono::system_clock::time_point watchDate)
{
    std::string watchDateString = std::chrono::format("%F %T", watchDate);

    std::string query = std::string("")
        + "SELECT \"WatchId\", \"UserId\", \"MovieId\", \"WatchDate\", \"CompletionPercentage\" "
        + "FROM \"WatchHistory\" "
        + "WHERE \"WatchDate\" >= '" + watchDateString + "';";

    PGresult *result = _dbConnection.Execute(query);

    std::vector<WatchHistory> watchHistories;
    int rows = PQntuples(result);

    for (int i = 0; i < rows; ++i)
    {
        int watchId = std::stoi(PQgetvalue(result, i, 0));
        int userId = std::stoi(PQgetvalue(result, i, 1));
        int movieId = std::stoi(PQgetvalue(result, i, 2));
        std::string watchDateString = PQgetvalue(result, i, 3);
        double completionPercentage = std::stod(PQgetvalue(result, i, 4));

        std::stringstream ss(watchDateString);
        std::chrono::system_clock::time_point watchDate;
        ss >> std::chrono::parse("%F %T", watchDate);

        if (ss.fail())
        {
            throw std::runtime_error("SQL DATETIME to chrono time point object conversion failed");
        }

        WatchHistory watchHistory(userId, watchId, movieId, watchDate, completionPercentage);
        watchHistories.push_back(watchHistory);
    }
}