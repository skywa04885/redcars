#include "../model/Customer.hpp"
#include "CrudRepository.hpp"

namespace redcars::repo {
    class CustomerRepository : public CrudRepository<model::Customer> {
    public:
        virtual ~CustomerRepository() = default;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        virtual std::optional<model::Customer> getCustomerByEmail(const std::string &email) = 0;

        /**
         * pre-conditions:
         * - The user is logged in.
         * - The user is a customer.
         * post-conditions: none
         * */
        virtual model::Customer getCurrentCustomer() = 0;


        /**
         * pre-conditions:
         * - The customer exists.
         * post-conditions:
         * - The customer's subscription has been updated.
         * */
        virtual void setCustomerSubscription(model::Customer &customer, model::Subscription &sub) = 0;
    };
}