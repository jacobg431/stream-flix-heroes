#include "User.hpp"    
#include <string>
    
    
    
User::User(std::string name, int userId, std::string email, UserSubscriptionType subscriptionType){
    _name = name; 
    _id = userId; 
    _email = email; 
    _subscriptionType = subscriptionType; 
};

std::string User::getName(){
    return _name; 
}

int User::getId(){
    return _userId; 
}

std::string User::getEmail(){
    return _email;
} 
UserSubscriptionType User::getSubscriptionType(){
    return _subscriptionType; 
}

std::chrono::system_clock::time_point User::getDateJoined(){
    return _dateJoined; 
}


