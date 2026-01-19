#pragma once
#include <string>
#include <chrono>

class User
{
private:
    std::string _firstName;
    std::string _lastName;
    int _userId;
    std::string _email;
    std::string _subscriptionType;
    std::chrono::system_clock::time_point _dateJoined;

public:
    User(std::string firstName, std::string lastName, int userId, std::string email, std::string subscriptionType);
    std::string getName() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    int getId() const;
    std::string getEmail() const;
    std::string getSubscriptionType() const;
    std::chrono::system_clock::time_point getDateJoined() const;

    bool operator==(const User &other) const;
};