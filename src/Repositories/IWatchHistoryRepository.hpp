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

    virtual WatchHistory selectWatchHistoriyByMovieAndUser(Movie &movie, User &user) const = 0;

    virtual std::vector<WatchHistory> selectWatchHistoriesWithCompletionPercentage(double completionPercentage) const = 0;

    virtual std::vector<WatchHistory> selectWatchHistoriesLaterThan(int year, int month, int day) const = 0;

protected:
    std::string queryWhereClause;
};