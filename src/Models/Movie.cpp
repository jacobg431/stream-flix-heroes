#include "Movie.hpp"



Movie::Movie(std::string title, int movieId, std::string genre, int releaseYear, double rating, int duration){
    _title = title; 
    _movieId = movieId; 
    _genre = genre; 
    _releaseYear = releaseYear; 
    _rating = rating; 
    _duration = duration; 
}

std::string Movie::getTitle(){
    return _title; 
}

int Movie::getId(){
    return _movieId; 
}

std::string Movie::getGenre(){
    return _genre; 
}

int Movie::getReleaseYear(){
    return _releaseYear; 
}

double Movie::getRating(){
    return _rating; 
}

int Movie::getDuration(){
    return _duration; 
}