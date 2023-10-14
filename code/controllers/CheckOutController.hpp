#pragma once

#include "Controller.hpp"

namespace redcars::controllers {
    class CheckOutController : public Controller {
    public:
        bool run(view::View &view) override;
    };
}
