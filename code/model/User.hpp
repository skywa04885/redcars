#pragma once

#include <string>

namespace redcars::model {
    class User {
    public:
        User(std::string firstname, std::string lastname, std::string email, bool emailVerified);

        virtual ~User() = default;

        const std::string &getFirstname() const;

        const std::string &getLastname() const;

        const std::string &getEmail() const;

    private:
        std::string firstname;
        std::string lastname;
        std::string email;
        bool emailVerified;
    };
}
