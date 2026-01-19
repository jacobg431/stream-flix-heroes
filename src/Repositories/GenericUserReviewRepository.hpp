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

    std::vector<UserReview> selectReviewsByUser(const User &user);

    std::vector<UserReview> selectReviewsOfMovie(const User &user);

private:
    DbConnection &_dbConnection;
};
