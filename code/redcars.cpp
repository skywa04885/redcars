#include "controllers/Controller.hpp"
#include "controllers/CliController.hpp"
#include "mock/CliMock.hpp"

#include <iostream>

using namespace redcars;

void runController(controllers::Controller &controller) {
    controller.runInteractive(std::cin, std::cout);
}

int main() {
    using namespace controllers;

    mock::CliMock mock(std::cout);

    RegisterController registerController(mock, mock);

    CliController cliController(registerController);
    runController(cliController);


    return 0;
}
