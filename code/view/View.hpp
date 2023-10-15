#pragma once

#include <string>

namespace redcars::view {
    class View {
    public:
        /**
          * pre-conditions: none
          * post-conditions:
          * - An error message has been displayed
          * */
        virtual void displayErrorMessage(const char *msg) = 0;

        /**
          * pre-conditions: none
          * post-conditions:
          * - A message has been displayed
          * */
        virtual void displayMessage(const char *msg) = 0;

        /**
          * pre-conditions: none
          * post-conditions:
          * - Input has been requested from the user
          * */
        virtual void getInput(const char *valueName, std::string &target) = 0;

        /**
          * pre-conditions: none
          * post-conditions:
          * - Input has been requested from the user
          * */
        virtual void getInput(const char *valueName, unsigned int &target) = 0;

        /**
          * pre-conditions: none
          * post-conditions:
          * - Input has been requested from the user
          * */
        virtual void getInput(const char *valueName, char &target) = 0;

        /**
          * pre-conditions: none
          * post-conditions:
          * - Input has been requested from the user
          * */
        virtual bool confirm(const char *msg) = 0;
    };
}
