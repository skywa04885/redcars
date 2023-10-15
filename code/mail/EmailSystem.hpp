#pragma once

#include "../model/Customer.hpp"

namespace redcars::mail {
    class EmailSystem {
    public:

        /**
         * pre-conditions:
         * - the customer's email is syntactically valid, for example: "()<>[]:,;@\\"!#$%&'-/=?^_`{}| ~.a"@example.org
         *
         * post-conditions:
         * - A email has been sent with a verification link.
         *
         * */
        virtual void verifyCustomerEmail(model::Customer &customer) = 0;
    };
}
