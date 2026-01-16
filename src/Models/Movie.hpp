#pragma once
#include <string>

class Movie
{
private:
    std::string _title;
    int _movieId;
    std::string _genre;
    int _releaseYear;
    double _rating;
    int _duration;

public:
    Movie(std::string title, int movieId, std::string genre, int releaseYear, double rating, int duration);

    void setTitle(const std::string &title);
    std::string getTitle() const;

    void setId(int movieId);
    int getId() const;

    void setGenre(const std::string &genre);
    std::string getGenre() const;

    void setReleaseYear(int releaseYear);
    int getReleaseYear() const;
    
    void setRating(double rating);
    double getRating() const;

    void setDuration(int duration);
    int getDuration() const;
};