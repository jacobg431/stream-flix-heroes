#pragma once
#include "IWatchHistoryRepository.hpp"
#include "../Models/Movie.hpp"
#include "../Models/User.hpp"
#include "../Database/DbConnection.hpp"

class GenericWatchHistoryRepository implements IWatchHistoryRepository
{
public:
    GenericWatchHistoryRepository(DbConnection &dbConnection);

    WatchHistory selectWatchHistoryByMovieAndUser(Movie &movie, User &user);

    std::vector<WatchHistory> selectWatchHistoriesWithCompletionPercentage(double completionPercentage);

    std::vector<WatchHistory> selectWatchHistoriesLaterThan(std::chrono::system_clock::time_point dateWatched);
private:
    DbConnection &_dbConnection;
};
