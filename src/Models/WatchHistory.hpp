#pragma once
#include <chrono>


class WatchHistory
{
private:
    int _userId; 
    int _watchId;
    int _movieId; 
    std::chrono::system_clock::time_point _watchDate;
    double _completionPercentage; 

public:
    WatchHistory(
        int userId,
        int watchId,
        int movieId,
        std::chrono::system_clock::time_point watchDate,
        double completionPercentage
    );

    int getUserId() const;
    int getWatchId() const;
    int getMovieId() const;
    std::chrono::system_clock::time_point getWatchDate() const;
    double getCompletionPercentage() const;
};
