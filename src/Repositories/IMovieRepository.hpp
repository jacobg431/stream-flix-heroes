#pragma once
#include "../Models/Movie.hpp"
#include "../Models/User.hpp"
#include <vector>
#include <string>

class IMovieRepository
{
public:
    virtual ~IMovieRepository() = default;

    virtual std::vector<Movie> selectMostWatchedMovies(int amount) const = 0;

    virtual std::string selectMostPopularGenre(const User &user) const = 0;

protected:
    std::string queryWhereClause;
};