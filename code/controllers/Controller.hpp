#pragma once

#include <istream>
#include <ostream>
#include <string>

namespace redcars::controllers {
    class Controller {
    public:
        virtual ~Controller() = default;

        virtual void runInteractive(std::istream &input, std::ostream &output) = 0;

        void getInput(std::istream &input, std::ostream &output, const char *valueName, std::string &target);

        bool confirm(std::istream &input, std::ostream &output, const char *msg);
    };
}