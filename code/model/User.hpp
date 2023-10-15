#pragma once

#include <string>

namespace redcars::model {
    class User {
    public:
        User(std::string firstname, std::string lastname, std::string email, bool emailVerified);

        virtual ~User() = default;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        const std::string &getFirstname() const;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        const std::string &getLastname() const;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        const std::string &getEmail() const;

    private:
        std::string firstname;
        std::string lastname;
        std::string email;
        bool emailVerified;
    };
}
