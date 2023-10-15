#pragma once

#include "../payment/PaymentSystem.hpp"
#include "../repo/Repository.hpp"
#include "../mail/EmailSystem.hpp"
#include "../delivery/DeliverySystem.hpp"
#include "../view/View.hpp"
#include "../vehicle/VehicleComs.hpp"


#include <ostream>

namespace redcars::mock {

    // As a quick note, all pre- / post-conditions are all none. Because that's the point of mocking.

    class CustomerMockRepo : public redcars::repo::CustomerRepository {
    public:
        explicit CustomerMockRepo(std::ostream &output);

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        void create(const model::Customer &t) override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        void remove(const model::Customer &t) override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        std::vector<model::Customer> search(const std::string &query) override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        void update(const model::Customer &t) override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        std::optional<model::Customer> getCustomerByEmail(const std::string &email) override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        model::Customer getCurrentCustomer() override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        void setCustomerSubscription(model::Customer &customer, model::Subscription &sub) override;

    private:
        std::ostream &output;
    };

    class StationMockRepo : public repo::StationRepository {
    public:
        explicit StationMockRepo(std::ostream &output);

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        void create(const model::Station &t) override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        void remove(const model::Station &t) override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        std::vector<model::Station> search(const std::string &query) override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        void update(const model::Station &t) override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        std::optional<model::Station> getClosestStation(model::GeoPosition pos, model::Distance maxDistance) override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        int getConnectedVehicleCount(const model::Station &station) override;

    private:
        std::ostream &output;
    };

    class VehicleMockRepo : public repo::VehicleRepository {
    public:
        explicit VehicleMockRepo(std::ostream &output);

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        void create(const model::Vehicle &t) override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        void remove(const model::Vehicle &t) override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        std::vector<model::Vehicle> search(const std::string &query) override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        void update(const model::Vehicle &t) override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        std::vector<model::Vehicle> searchVehicles(model::GeoPosition position, model::Distance maxDistance) override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        model::Vehicle getCurrentVehicle() override;
    private:
        std::ostream &output;
    };

    class CliMock
            : public payment::PaymentSystem,
              public repo::Repository,
              public repo::BankAccountRepository,
              public mail::EmailSystem,
              public delivery::DeliverySystem,
              public repo::CardRepository,
              public repo::ReservationRepository,
              public view::View,
              public vehicle::VehicleComs {
    public:
        CliMock(std::ostream &output, std::istream &input);


        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        bool fulfillCharge(model::Charge &charge, const model::BankAccount &from) override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        repo::CustomerRepository &customers() override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        bool requestAutomaticCharging(const model::BankAccount &account) override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        std::optional<model::BankAccount> getBankAccountByNumber(const std::string &number) override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        BankAccountRepository &bankAccounts() override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        void verifyCustomerEmail(model::Customer &customer) override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        model::Money deliverToCustomer(const model::Customer &customer, const model::Card &card) override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        CardRepository &cards() override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        void registerCard(const model::Card &card) override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        ReservationRepository &reservations() override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        void addReservation(const model::Reservation &reservation) override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        model::Card generateCard() override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        bool fulfillCharge(model::Charge &charge, const model::Customer &customer) override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        void getInput(const char *valueName, std::string &target) override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        void getInput(const char *valueName, unsigned int &target) override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        bool confirm(const char *msg) override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        void getInput(const char *valueName, char &target) override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        void displayErrorMessage(const char *msg) override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        void displayMessage(const char *msg) override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        void openDoor(const model::Vehicle &vehicle) override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        void closeDoor(const model::Vehicle &vehicle) override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        void enableEngine(const model::Vehicle &vehicle) override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        void disableEngine(const model::Vehicle &vehicle) override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        void displayLights(const model::Vehicle &vehicle, bool keepOn) override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        model::Distance requestDistanceDriven(const model::Vehicle &vehicle) override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        std::optional<model::Reservation> getActiveReservationByCard(const model::Card &card) override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        void addReservationUsage(model::Reservation &reservation, model::Usage newUsage) override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        repo::StationRepository &stations() override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        model::GeoPosition requestVehiclePosition(const model::Vehicle &vehicle) override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        repo::VehicleRepository &vehicles() override;
    private:
        std::ostream &output;
        std::istream &input;

        CustomerMockRepo customerMockRepo;
        StationMockRepo stationMockRepo;
        VehicleMockRepo vehicleMockRepo;
    };
}