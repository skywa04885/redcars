#include "../model/Customer.hpp"

namespace redcars::repo {
    class CustomerRepository {
    public:
        virtual ~CustomerRepository() = default;

        virtual void createCustomer(const model::Customer &customer) = 0;
        virtual std::optional<model::Customer> getCustomerByEmail(const std::string& email) = 0;

        virtual model::Customer getCurrentCustomer() = 0;
        virtual void setCustomerSubscription(model::Customer& customer, model::Subscription& sub) = 0;
    };
}