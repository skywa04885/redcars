#pragma once

#include <string>

namespace redcars::view {
    class View {
    public:
        virtual void displayErrorMessage(const char *msg) = 0;

        virtual void displayMessage(const char *msg) = 0;

        virtual void getInput(const char *valueName, std::string &target) = 0;

        virtual void getInput(const char *valueName, unsigned int &target) = 0;

        virtual void getInput(const char *valueName, char &target) = 0;

        virtual bool confirm(const char *msg) = 0;
    };
}
