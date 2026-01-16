#include "User.hpp"
#include <string>

User::User(std::string name, int userId, std::string email, std::string subscriptionType) : _name(name), _userId(userId), _email(email), _subscriptionType(subscriptionType) {}

std::string User::getName() const
{
    return _name;
}

int User::getId() const
{
    return _userId;
}

std::string User::getEmail() const
{
    return _email;
}
std::string User::getSubscriptionType() const
{
    return _subscriptionType;
}

std::chrono::system_clock::time_point User::getDateJoined() const
{
    return _dateJoined;
}
