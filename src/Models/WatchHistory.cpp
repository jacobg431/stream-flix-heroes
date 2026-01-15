#include "WatchHistory.hpp"

WatchHistory::WatchHistory(
    int userId,
    int watchId,
    int movieId,
    std::chrono::system_clock::time_point watchDate,
    double completionPercentage
)
    : _userId(userId),
      _watchId(watchId),
      _movieId(movieId),
      _watchDate(watchDate),
      _completionPercentage(completionPercentage)
{
}

int WatchHistory::getUserId() const
{
    return _userId;
}

int WatchHistory::getWatchId() const
{
    return _watchId;
}

int WatchHistory::getMovieId() const
{
    return _movieId;
}

std::chrono::system_clock::time_point WatchHistory::getWatchDate() const
{
    return _watchDate;
}

double WatchHistory::getCompletionPercentage() const
{
    return _completionPercentage;
}
