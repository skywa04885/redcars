#pragma once

#include "../model/Customer.hpp"

namespace redcars::mail {
    class EmailSystem {
    public:
        virtual void verifyCustomerEmail(model::Customer& customer) = 0;
    };
}
