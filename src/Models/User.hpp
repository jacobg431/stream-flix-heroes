#pragma once
#include <string>
#include "UserSubscriptionType.hpp"
#include <chrono>


class User{
private:
    std::string _name; 
    int _userId; 
    std::string _email; 
    UserSubscriptionType _subscriptionType; 
    std::chrono::system_clock::time_point _dateJoined; 


public:
    User(std::string name, int userId, std::string email, UserSubscriptionType subscriptionType);
    std::string getName();
    int getId(); 
    std::string getEmail(); 
    UserSubscriptionType getSubscriptionType();
    std::chrono::system_clock::time_point getDateJoined();


};