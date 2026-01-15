#pragma once
#include <string>


class Movie{
private: 
    std::string _title; 
    int _movieId; 
    std::string _genre; 
    int _releaseYear; 
    double _rating; 
    int _duration; 


public: 
    Movie(std::string title, int movieId, std::string genre, int releaseYear, double rating, int duration); 
    std::string getTitle(); 
    int getId(); 
    std::string getGenre(); 
    int getReleaseYear(); 
    double getRating(); 
    int getDuration(); 



}; 