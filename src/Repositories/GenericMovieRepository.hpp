#pragma once
#include "IMovieRepository.hpp"
#include "../Database/DbConnection.hpp"

class GenericMovieRepository : public IMovieRepository
{
public:
    GenericMovieRepository(DbConnection &dbConnection);

    std::vector<Movie> selectMostWatchedMovies(int amount) const override;

    std::string selectMostPopularGenre(const User &user) const override;

private:
    std::string _subscriptionType;
    DbConnection &_dbConnection;
};
