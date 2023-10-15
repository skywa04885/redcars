#include "CliMock.hpp"
#include <ctime>
#include <algorithm>
#include <iostream>

using namespace redcars::model;

redcars::mock::CliMock::CliMock(std::ostream &output, std::istream &input) : output(output), input(input), customerMockRepo(output),
                                                                             stationMockRepo(output) {
}

bool redcars::mock::CliMock::fulfillCharge(Charge &charge, const BankAccount &from) {
    output << "Getting €" << charge.getAmount().eurosAsFloat() << " from " << from.getNumber() << std::endl;
    return true;
}

redcars::repo::CustomerRepository &redcars::mock::CliMock::customers() {
    return customerMockRepo;
}

void redcars::mock::CustomerMockRepo::createCustomer(const Customer &customer) {
    output << "Creating customer: " << customer.getFirstname() << " " << customer.getLastname() << " "
           << customer.getEmail() << std::endl;
}

bool redcars::mock::CliMock::requestAutomaticCharging(const BankAccount &account) {
    output << "Request automatic charging for " << account.getNumber() << ", success!" << std::endl;
    return true;
}

std::optional<redcars::model::BankAccount> redcars::mock::CliMock::getBankAccountByNumber(const std::string &number) {
    output << "Checking for bank account with number " << number << ", none found" << std::endl;
    return std::nullopt;
}

redcars::repo::BankAccountRepository &redcars::mock::CliMock::bankAccounts() {
    return *this;
}

void redcars::mock::CliMock::verifyCustomerEmail(Customer &customer) {
    output << "Verifying email: " << customer.getEmail() << ", success!" << std::endl;
}

std::optional<redcars::model::Customer> redcars::mock::CustomerMockRepo::getCustomerByEmail(const std::string &email) {
    output << "Checking for account with email " << email << ", none found" << std::endl;
    return std::nullopt;
}

Money redcars::mock::CliMock::deliverToCustomer(const Customer &customer, const model::Card &card) {
    output << "Delivery card " << card.getNumber() << " to customer " << customer.getAddress() << std::endl;
    return model::Money(1000, std::time(nullptr));
}

redcars::repo::CardRepository &redcars::mock::CliMock::cards() {
    return *this;
}

Card redcars::mock::CliMock::generateCard() {
    output << "Generating card" << std::endl;
    return model::Card("0xdeadbeef");
}

void redcars::mock::CliMock::registerCard(const Card &card) {
    output << "Registering card " << card.getNumber() << std::endl;
}

redcars::repo::VehicleRepository &redcars::mock::CliMock::vehicles() {
    return *this;
}

std::vector<redcars::model::Vehicle>
redcars::mock::CliMock::searchVehicles(GeoPosition position, Distance maxDistance) {
    output << "Searching vehicles" << std::endl;

    std::vector<model::Vehicle> vehicles = {
            model::Vehicle(GeoPosition(10, 10), std::time(nullptr), model::VehicleKind::Personal, std::string()),
            model::Vehicle(GeoPosition(11, 11), std::time(nullptr), model::VehicleKind::Personal, std::string()),
            model::Vehicle(GeoPosition(9, 9), std::time(nullptr), model::VehicleKind::Station, std::string()),
    };

    vehicles.erase(std::remove_if(vehicles.begin(), vehicles.end(), [&](const Vehicle &vehicle) {
        Distance distance = vehicle.getPosition().distanceFrom(position);
        return distance > maxDistance;
    }), vehicles.end());

    return vehicles;
}

Customer redcars::mock::CustomerMockRepo::getCurrentCustomer() {
    output << "Getting current customer" << std::endl;

    return model::Customer("John", "Doe", "basicjohn@hotmail.co.uk", true,
                           "somewhere green", std::optional(model::Card("1")), BankAccount("1234"),
                           std::optional<Subscription>(), false);
}

redcars::repo::ReservationRepository &redcars::mock::CliMock::reservations() {
    return *this;
}

void redcars::mock::CliMock::addReservation(const Reservation &) {
    output << "Adding reservation" << std::endl;
}

bool redcars::mock::CliMock::fulfillCharge(Charge &charge, const Customer &customer) {
    return fulfillCharge(charge, customer.getBankAccount());
}

void redcars::mock::CliMock::getInput(const char *valueName, std::string &target) {
    output << "Enter your " << valueName << ": ";
    input >> target;
}

void redcars::mock::CliMock::getInput(const char *valueName, unsigned int &target) {
    std::string buff;

    while (true) {
        getInput(valueName, buff);

        try {
            target = std::abs(std::stoi(buff));
            break;
        }
        catch (std::exception &e) {
            output << "Please enter a number" << std::endl;
        }
    }
}

bool redcars::mock::CliMock::confirm(const char *msg) {
    char answer;

    while (true) {
        output << msg << " [Y/N]: ";
        input >> answer;
        answer = (char) std::toupper((char) answer);

        switch (answer) {
            case 'Y':
                return true;
            case 'N':
                return false;
            default:
                output << "Invalid input!" << std::endl;
        }
    }
}

void redcars::mock::CliMock::getInput(const char *valueName, char &target) {
    output << "Enter your " << valueName << ": ";
    input >> target;
}

void redcars::mock::CliMock::displayErrorMessage(const char *msg) {
    output << "ERROR: " << msg << std::endl;
}

void redcars::mock::CliMock::displayMessage(const char *msg) {
    output << msg << std::endl;
}

void redcars::mock::CliMock::openDoor(const Vehicle &) {
    output << "Opening door" << std::endl;
}

void redcars::mock::CliMock::closeDoor(const Vehicle &) {
    output << "Closing door" << std::endl;
}

void redcars::mock::CliMock::enableEngine(const Vehicle &) {
    output << "Enabling engine" << std::endl;
}

void redcars::mock::CliMock::disableEngine(const Vehicle &) {
    output << "Disabling engine" << std::endl;
}

void redcars::mock::CliMock::displayLights(const model::Vehicle &, bool) {
    output << "Displaying lights" << std::endl;
}

Distance redcars::mock::CliMock::requestDistanceDriven(const Vehicle &) {
    output << "Requesting distance driven from vehicle" << std::endl;
    return model::Distance::fromKm(1000);
}

Vehicle redcars::mock::CliMock::getCurrentVehicle() {
    output << "Getting current vehicle" << std::endl;
    return model::Vehicle(model::GeoPosition(10, 10), std::time(nullptr), model::VehicleKind::Personal, std::string());
}

std::optional<redcars::model::Reservation> redcars::mock::CliMock::getActiveReservationByCard(const Card &) {
    output << "Getting active reservation" << std::endl;
    return model::Reservation({}, model::TimeFrame(std::time(nullptr), 1000),
                              model::Charge(true, model::Money(50, std::time(
                                      nullptr))), model::Vehicle(model::GeoPosition(10, 10), std::time(nullptr),
                                                                 model::VehicleKind::Personal, std::string()),
                              model::Customer("John", "Doe", "justjohn@hotmail.com", true, "1234AD", {},
                                              model::BankAccount("123455"), std::nullopt, true));
}

void redcars::mock::CliMock::addReservationUsage(Reservation &, Usage) {
    output << "Adding new usage" << std::endl;
}

redcars::repo::StationRepository &redcars::mock::CliMock::stations() {
    return stationMockRepo;
}

std::optional<redcars::model::Station> redcars::mock::StationMockRepo::getClosestStation(GeoPosition pos, Distance) {
    output << "Getting closest station" << std::endl;
    return model::Station(pos, 5);
}

GeoPosition redcars::mock::CliMock::requestVehiclePosition(const Vehicle &) {
    output << "Requesting vehicle position" << std::endl;
    return model::GeoPosition(10, 10);
}

int redcars::mock::StationMockRepo::getConnectedVehicleCount(const Station &) {
    output << "Counting connected vehicles" << std::endl;
    return 4;
}

void redcars::mock::CustomerMockRepo::setCustomerSubscription(Customer &, Subscription &) {
    output << "Adding subscription to customer" << std::endl;
}

void redcars::mock::CustomerMockRepo::remove(const Customer &) {
    output << "Removing a customer" << std::endl;
}

void redcars::mock::CustomerMockRepo::create(const Customer &) {
    output << "Creating a customer" << std::endl;
}

std::vector<redcars::model::Customer> redcars::mock::CustomerMockRepo::search(const std::string &query) {
    output << "Searching customers:" << query << std::endl;

    return {
            model::Customer("John", "Doe", "justjohn@hotmail.com", true, "1234AD", {},
                            model::BankAccount("123455"), std::nullopt, false)
    };
}

void redcars::mock::CustomerMockRepo::update(const Customer &) {
    output << "Updating a customer" << std::endl;
}

redcars::mock::CustomerMockRepo::CustomerMockRepo(std::ostream &output) : output(output) {}

void redcars::mock::StationMockRepo::create(const Station &) {
    output << "Creating a station" << std::endl;

}

void redcars::mock::StationMockRepo::remove(const Station &) {
    output << "Removing a station" << std::endl;
}

std::vector<redcars::model::Station> redcars::mock::StationMockRepo::search(const std::string &query) {
    output << "Searching stations:" << query << std::endl;

    return {
        model::Station(model::GeoPosition(10, 10), 5)
    };
}

void redcars::mock::StationMockRepo::update(const Station &) {
    output << "Updating a station" << std::endl;
}

redcars::mock::StationMockRepo::StationMockRepo(std::ostream &output) : output(output) {}
