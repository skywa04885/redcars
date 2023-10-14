#include "controllers/CliController.hpp"
#include "mock/CliMock.hpp"

#include <iostream>



int main() {
    using namespace redcars;
    using namespace controllers;

    mock::CliMock mock(std::cout, std::cin);

    RegisterController registerController(mock, mock, mock, mock);
    VehicleSearchController vehicleSearchController(mock);
    ReservationController reservationController(vehicleSearchController, mock, mock);
    CheckInController checkInController(mock, mock);
    CheckOutController checkOutController(mock, mock, mock);
    SubscribeController subscribeController(mock, mock);

    CliController cliController(registerController, reservationController, checkInController, checkOutController, subscribeController, std::cout);

    // run the application.
    cliController.run(mock);

    return 0;
}
