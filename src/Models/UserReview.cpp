#include <chrono>
#include "UserReview.hpp"

UserReview::UserReview(int userId, int reviewId, int movieId, double rating, std::string comment, std::chrono::system_clock::time_point reviewDate) :
    _userId(userId), _reviewId(reviewId), _movieId(movieId), _rating(rating), _comment(comment), _reviewDate(reviewDate)
{}
    
int UserReview::getUserId() { return _userId; }
int UserReview::getReviewId() { return _reviewId; }
int UserReview::getMovieId() { return _movieId; }
double UserReview::getRating() { return _rating; }
std::string UserReview::getComment() { return _comment; }
std::chrono::system_clock::time_point UserReview::getReviewDate() { return _reviewDate; }