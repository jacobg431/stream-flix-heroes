#pragma once
#include "IWatchHistoryRepository.hpp"
#include "../Models/Movie.hpp"
#include "../Models/User.hpp"
#include "../Database/DbConnection.hpp"

class GenericWatchHistoryRepository : public IWatchHistoryRepository
{
public:
    GenericWatchHistoryRepository(DbConnection &dbConnection);

    WatchHistory selectWatchHistoryById(int watchId);

    WatchHistory selectWatchHistoryByUserIdAndMovieId(int userId, int movieId);

    std::vector<WatchHistory> selectWatchHistoriesWithCompletionPercentage(double completionPercentage);

    std::vector<WatchHistory> selectWatchHistoriesLaterThan(std::chrono::system_clock::time_point dateWatched);
private:
    DbConnection &_dbConnection;
};
