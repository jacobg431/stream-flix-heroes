#include "Movie.hpp"

Movie::Movie(std::string title, int movieId, std::string genre, int releaseYear, double rating, int duration) : _title(title), _movieId(movieId), _genre(genre), _releaseYear(releaseYear), _rating(rating), _duration(duration) {}

void Movie::setTitle(const std::string &title)
{
    _title = title;
}
std::string Movie::getTitle() const
{
    return _title;
}

void Movie::setId(int movieId)
{
    _movieId = movieId;
}
int Movie::getId() const
{
    return _movieId;
}

void Movie::setGenre(const std::string &genre)
{
    _genre = genre;
}
std::string Movie::getGenre() const
{
    return _genre;
}

void Movie::setReleaseYear(int releaseYear)
{
    _releaseYear = releaseYear;
}
int Movie::getReleaseYear() const
{
    return _releaseYear;
}

void Movie::setRating(double rating)
{
    _rating = rating;
}
double Movie::getRating() const
{
    return _rating;
}

void Movie::setDuration(int duration)
{
    _duration = duration;
}
int Movie::getDuration() const
{
    return _duration;
}