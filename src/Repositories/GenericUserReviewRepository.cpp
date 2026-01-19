#include <sstream>
#include <stdexcept>
#include "GenericUserReviewRepository.hpp"

GenericUserReviewRepository::GenericUserReviewRepository(DbConnection &dbConnection) 
    : _dbConnection(dbConnection)
{}

std::vector<UserReview> GenericUserReviewRepository::selectReviewsByUser(const int userId)
{
    std::string query = std::string("")
                        + "SELECT \"ReviewId\", \"MovieId\", \"Rating\", \"Comment\", \"ReviewDate\" "
                        + "FROM \"Reviews\" "
                        + "WHERE \"UserId\" = " + std::to_string(userId) + ";";
                        
    PGresult *result = _dbConnection.Execute(query);

    std::vector<UserReview> userReviews;
    int rows = PQntuples(result);

    for (int i = 0; i < rows; ++i)
    {
        int reviewId = std::stoi(PQgetvalue(result, i, 0));
        int movieId = std::stoi(PQgetvalue(result, i, 1));
        double rating = std::stod(PQgetvalue(result, i, 2));
        std::string comment = PQgetvalue(result, i, 3);
        std::string reviewDateString = PQgetvalue(result, i, 4);

        std::stringstream ss(reviewDateString);
        std::chrono::system_clock::time_point reviewDate;
        ss >> std::chrono::parse("%F %T", reviewDate);

        if (ss.fail())
        {
            throw std::runtime_error("SQL DATETIME to chrono time point object conversion failed");
        }

        UserReview userReview(userId, reviewId, movieId, rating, comment, reviewDate);
        userReviews.push_back(userReview);
    }

    return userReviews;
}

std::vector<UserReview> GenericUserReviewRepository::selectReviewsOfMovie(const int movieId)
{
    std::string query = std::string("")
                        + "SELECT \"ReviewId\", \"UserId\", \"Rating\", \"Comment\", \"ReviewDate\" "
                        + "FROM \"Reviews\" "
                        + "WHERE \"MovieId\" = " + std::to_string(movieId) + ";";
                        
    PGresult *result = _dbConnection.Execute(query);

    std::vector<UserReview> userReviews;
    int rows = PQntuples(result);

    for (int i = 0; i < rows; ++i)
    {
        int reviewId = std::stoi(PQgetvalue(result, i, 0));
        int userId = std::stoi(PQgetvalue(result, i, 1));
        double rating = std::stod(PQgetvalue(result, i, 2));
        std::string comment = PQgetvalue(result, i, 3);
        std::string reviewDateString = PQgetvalue(result, i, 4);

        std::stringstream ss(reviewDateString);
        std::chrono::system_clock::time_point reviewDate;
        ss >> std::chrono::parse("%F %T", reviewDate);

        if (ss.fail())
        {
            throw std::runtime_error("SQL DATETIME to chrono time point object conversion failed");
        }

        UserReview userReview(userId, reviewId, movieId, rating, comment, reviewDate);
        userReviews.push_back(userReview);
    }

    return userReviews;
}