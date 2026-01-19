#pragma once
#include "IUserReviewRepository.hpp"
#include "../Models/Movie.hpp"
#include "../Models/User.hpp"
#include "../Models/UserReview.hpp"
#include "../Database/DbConnection.hpp"

class GenericUserReviewRepository : public IUserReviewRepository
{
public:
    GenericUserReviewRepository(DbConnection &dbConnection);

    std::vector<UserReview> selectReviewsByUser(const int userId);

    std::vector<UserReview> selectReviewsOfMovie(const int movieId);

private:
    DbConnection &_dbConnection;
};
