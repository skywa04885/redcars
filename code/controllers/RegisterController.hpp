#pragma once

#include "Controller.hpp"

namespace redcars::controllers {
    class RegisterController : public Controller {
    public:
        void runInteractive(std::istream &input, std::ostream &output) override;
    };
}
