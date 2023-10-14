#pragma once

#include <istream>
#include <ostream>
#include <string>
#include "../view/View.hpp"

namespace redcars::controllers {
    class Controller {
    public:
        virtual ~Controller() = default;

        virtual bool run(view::View &view) = 0;
    };
}