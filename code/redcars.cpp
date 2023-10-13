#include "controllers/Controller.hpp"
#include "controllers/CliController.hpp"
#include "mock/CliMock.hpp"

#include <iostream>

using namespace redcars;


int main() {
    using namespace controllers;

    mock::CliMock mock(std::cout, std::cin);

    RegisterController registerController(mock, mock, mock, mock);
    VehicleSearchController vehicleSearchController(mock);
    ReservationController reservationController(vehicleSearchController, mock, mock);

    CliController cliController(registerController, reservationController, std::cout);

    // run the application.
    cliController.run(mock);

    return 0;
}
