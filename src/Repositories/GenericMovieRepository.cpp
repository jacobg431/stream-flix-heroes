#include "GenericMovieRepository.hpp"
#include "../Database/DbConnection.hpp"

GenericMovieRepository::GenericMovieRepository(DbConnection &dbConnection) : _dbConnection(dbConnection)
{
}

std::vector<Movie> GenericMovieRepository::selectMostWatchedMovies(int amount) const
{
    std::string query = std::string("")
        + "SELECT WatchHistory.MovieId, "
        + "Movies.Title, Movies.Genre, Movies.ReleaseYear, Movies.Rating, Movies.Duration, "
        + "COUNT(*) AS WatchCount "
        + "FROM WatchHistory "
        + "INNER JOIN Movies ON WatchHistory.MovieId = Movies.MovieId "
        + "GROUP BY MovieId "
        + "ORDER BY WatchCount DESC "
        + "LIMIT " + std::to_string(amount) + ";";

    PGresult *result = _dbConnection.Execute(query);

    std::vector<Movie> movies;
    int rows = PQntuples(result);

    for (int i = 0; i < rows; ++i)
    {
        int movieId = std::stoi(PQgetvalue(result, i, 0));
        std::string title = PQgetvalue(result, i, 1);
        std::string genre = PQgetvalue(result, i, 2);
        int releaseYear = std::stoi(PQgetvalue(result, i, 3));
        double rating = std::stod(PQgetvalue(result, i, 4));
        int duration = std::stoi(PQgetvalue(result, i, 5));

        movies.emplace_back(title, movieId, genre, releaseYear, rating, duration);
    }

    return movies;
}

std::string GenericMovieRepository::selectMostPopularGenre(const User &user) const
{
    std::string query = std::string("")
        + "SELECT genre, COUNT(*) as genreCount FROM WatchHistory WH "
        + "INNER JOIN Movies M ON WH.movieId = M.movieId "
        + "WHERE WH.userId = " + std::to_string(user.getId()) + " "
        + "GROUP BY genre "
        + "ORDER BY genreCount DESC "
        + "LIMIT 1;";

    PGresult* result = _dbConnection.Execute(query);
    if (PQntuples(result) > 0)
    {
        return PQgetvalue(result, 0, 0);
    }

    throw std::runtime_error("No watch history found for user");
}