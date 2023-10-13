#include "User.hpp"

redcars::model::User::User(std::string firstname, std::string lastname, std::string email, bool emailVerified)
        : firstname(firstname), lastname(lastname), email(email), emailVerified(emailVerified) {}

const std::string &redcars::model::User::getFirstname() const {
    return firstname;
}

const std::string &redcars::model::User::getLastname() const {
    return lastname;
}

const std::string &redcars::model::User::getEmail() const {
    return email;
}

