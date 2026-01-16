#pragma once
#include <string>
#include <chrono>



class UserReview
{
private:
    int _userId;
    int _reviewId; 
    int _movieId; 
    double _rating; 
    std::string _comment; 
    std::chrono::system_clock::time_point _reviewDate; 

public:
    UserReview(int userId, int reviewId, int moveId, double rating, std::string comment, std::chrono::system_clock::time_point reviewDate);
    int getUserId();
    int getReviewId();
    int getMovieId();
    double getRating();
    std::string getComment();
    std::chrono::system_clock::time_point getReviewDate();
};

