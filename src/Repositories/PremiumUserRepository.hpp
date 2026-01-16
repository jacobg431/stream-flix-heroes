#pragma once
#include "IUserRepository.hpp"
#include "GenericUserRepository.hpp"

class PremiumUserRepository : public GenericUserRepository {};

PremiumUserRepository::PremiumUserRepository()
{
    _queryWhereClause = "WHERE subscriptionType = 'Premium'";
}

PremiumUserRepository::insertUser(const User &user) override
{
    if (user.getSubscriptionType() != "Premium")
    {
        throw std::invalid_argument("Cannot insert non-premium user in PremiumUserRepository");
    }
    GenericUserRepository::insertUser(user);
}

PremiumUserRepository::updateUser(const User &user) override
{
    if (user.getSubscriptionType() != "Premium")
    {
        throw std::invalid_argument("Cannot update non-premium user in PremiumUserRepository");
    }
    GenericUserRepository::updateUser(user);
}