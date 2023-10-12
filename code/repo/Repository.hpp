#pragma once

#include "CustomerRepository.hpp"

namespace redcars::repo {
    class Repository {
    public:
        virtual ~Repository() = default;

        virtual CustomerRepository &customers() = 0;
    };
}
