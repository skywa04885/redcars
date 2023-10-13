#pragma once

#include <istream>
#include <ostream>
#include <string>

namespace redcars::controllers {
    class Controller {
    public:
        virtual ~Controller() = default;

        virtual bool runInteractive(std::istream &input, std::ostream &output) = 0;

        void getInput(std::istream &input, std::ostream &output, const char *valueName, std::string &target);
        void getInput(std::istream &input, std::ostream &output, const char *valueName, unsigned int &target);

        bool confirm(std::istream &input, std::ostream &output, const char *msg);
    };
}