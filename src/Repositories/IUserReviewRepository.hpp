#pragma once
#include "../Models/UserReview.hpp"
#include "../Models/User.hpp"
#include <vector>
#include <string>

class IUserReviewRepository
{
public:
    virtual ~IUserReviewRepository() = default;

    virtual std::vector<UserReview> selectReviewsByUser(const int userId) const = 0;

    virtual std::vector<UserReview> selectReviewsOfMovie(const int movieId) const = 0;

protected:
    std::string queryWhereClause;
};