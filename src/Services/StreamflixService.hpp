#pragma once
#include <vector>
#include <string>
#include "../Repositories/IMovieRepository.hpp"
#include "../Repositories/IUserRepository.hpp"
#include "../Models/User.hpp"
#include "../Models/Movie.hpp"
// Include other repositories

class StreamflixService
{
private:
    IMovieRepository &_movieRepository;
    IUserRepository &_userRepository;

public:
    StreamflixService(IUserRepository &userRepository, IMovieRepository &movieRepository);

    User getUserById(int id);

    User getUserByName(const std::string &firstName, const std::string &lastName);

    std::vector<User> getMultipleUsers(int amount, int offset);

    void addUser(const User &user);

    void updateUser(const User &user);
};