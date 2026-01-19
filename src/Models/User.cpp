#include "User.hpp"
#include <string>

User::User(std::string firstName, std::string lastName, int userId, std::string email, std::string subscriptionType) : _firstName(firstName), _lastName(lastName), _userId(userId), _email(email), _subscriptionType(subscriptionType) {}

std::string User::getName() const
{
    return getFirstName() + " " + getLastName();
}

std::string User::getFirstName() const
{
    return _firstName;
}

std::string User::getLastName() const
{
    return _lastName;
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

bool User::operator==(const User &other) const
{
    return _userId == other._userId
        && _firstName == other._firstName
        && _lastName == other._lastName
        && _email == other._email
        && _subscriptionType == other._subscriptionType;
}