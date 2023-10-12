#pragma once

#include <istream>
#include <ostream>

namespace redcars::controllers {

    class Controller {
    public:
        virtual ~Controller() = default;

        virtual void runInteractive(std::istream &input, std::ostream &output) = 0;
    };

}