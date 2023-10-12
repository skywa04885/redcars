#include "CliController.hpp"

void redcars::controllers::CliController::runInteractive(std::istream &input, std::ostream &output) {
    showHelp(output);

    while (true) {

        output << "Choose your action: ";

        char action;
        input >> action;

        if (action == 'Q') {
            break;
        } else if (action == 'H') {
            showHelp(output);
            continue;
        }

        auto controller = controllers.find(action);

        if (controller == controllers.end()) {
            output << "Unknown action \"" << action << "\"" << std::endl;
            continue;
        }

        output << "Running action \"" << controller->second.description << "\"" << std::endl;
        controller->second.controller.runInteractive(input, output);
        output << "Action finished" << std::endl;
    }
}

redcars::controllers::CliController::CliController(redcars::controllers::RegisterController &registerController) {
    controllers.insert({'R', {"Register as customer", registerController}});
}

void redcars::controllers::CliController::showHelp(std::ostream &output) const {
    for (auto &[action, controller]: controllers) {
        output << action << " = " << controller.description << std::endl;
    }

    output << "Q = quit" << std::endl;
    output << "H = help" << std::endl;
}
