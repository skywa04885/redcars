#pragma once

#include "../payment/PaymentSystem.hpp"
#include "../repo/Repository.hpp"
#include "../mail/EmailSystem.hpp"
#include "../delivery/DeliverySystem.hpp"
#include "../view/View.hpp"


#include <ostream>

namespace redcars::mock {
    class CliMock
            : public payment::PaymentSystem,
              public repo::Repository,
              public repo::CustomerRepository,
              public repo::BankAccountRepository,
              public mail::EmailSystem,
              public delivery::DeliverySystem,
              public repo::CardRepository,
              public repo::VehicleRepository,
              public repo::ReservationRepository,
              public view::View {
    public:
        CliMock(std::ostream &output, std::istream &input);

        bool fulfillCharge(model::Charge &charge, const model::BankAccount &from) override;

        CustomerRepository &customers() override;

        void createCustomer(const model::Customer &customer) override;

        bool requestAutomaticCharging(const model::BankAccount &account) override;

        std::optional<model::BankAccount> getBankAccountByNumber(const std::string &number) override;

        BankAccountRepository &bankAccounts() override;

        void verifyCustomerEmail(model::Customer &customer) override;

        std::optional<model::Customer> getCustomerByEmail(const std::string &email) override;

        model::Money deliverToCustomer(const model::Customer &customer, const model::Card &card) override;

        CardRepository &cards() override;

        void registerCard(const model::Card &card) override;

        VehicleRepository &vehicles() override;

        std::vector<model::Vehicle> searchVehicles(model::GeoPosition position, model::Distance maxDistance) override;

        model::Customer getCurrentCustomer() override;

        ReservationRepository &reservations() override;

        void addReservation(const model::Reservation &reservation) override;

        model::Card generateCard() override;

        bool fulfillCharge(model::Charge &charge, const model::Customer &customer) override;

        void getInput(const char *valueName, std::string &target) override;

        void getInput(const char *valueName, unsigned int &target) override;

        bool confirm(const char *msg) override;

        void getInput(const char *valueName, char &target) override;

        void displayErrorMessage(const char *msg) override;

        void displayMessage(const char *msg) override;

    private:
        std::ostream &output;
        std::istream &input;
    };
}