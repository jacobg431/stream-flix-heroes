#pragma once
#include "../Models/WatchHistory.hpp"
#include "../Models/Movie.hpp"
#include "../Models/User.hpp"
#include <vector>
#include <string>

class IWatchHistoryRepository
{
public:
    virtual ~IWatchHistoryRepository() = default;

    virtual WatchHistory selectWatchHistoryById(int watchId) const = 0;

    virtual WatchHistory selectWatchHistoryByUserIdAndMovieId(int userId, int movieId) const = 0;

    virtual std::vector<WatchHistory> selectWatchHistoriesWithCompletionPercentage(double completionPercentage) const = 0;

    virtual std::vector<WatchHistory> selectWatchHistoriesLaterThan(std::chrono::system_clock::time_point dateWatched) const = 0;

protected:
    std::string queryWhereClause;
};