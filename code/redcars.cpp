#include "controllers/Controller.hpp"
#include "controllers/CliController.hpp"

#include <iostream>

using namespace redcars;

void runController(controllers::Controller &controller) {
    controller.runInteractive(std::cin, std::cout);
}

int main() {
    using namespace controllers;

    RegisterController registerController;

    CliController cliController(registerController);
    runController(cliController);


    return 0;
}
