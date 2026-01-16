#include "StreamflixService.hpp"

StreamflixService::StreamflixService(IUserRepository &userRepository, IMovieRepository &movieRepository)
    : _userRepository(userRepository), _movieRepository(movieRepository)
{
}

User StreamflixService::getUserById(int id)
{
    return _userRepository.selectUserById(id);
}

User StreamflixService::getUserByName(const std::string &firstName, const std::string &lastName)
{
    return _userRepository.selectUserByName(firstName, lastName);
}

std::vector<User> StreamflixService::getMultipleUsers(int amount, int offset)
{
    return _userRepository.selectMultipleUsers(amount, offset);
}

void StreamflixService::addUser(const User &user)
{
    _userRepository.insertUser(user);
}

void StreamflixService::updateUser(const User &user)
{
    _userRepository.updateUser(user);
}