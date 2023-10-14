#include "CliController.hpp"

bool redcars::controllers::CliController::run(view::View& view) {
    showHelp();

    while (true) {
        char action;
        view.getInput("action", action);
        action = (char) std::toupper((char) action);

        if (action == 'Q') {
            break;
        } else if (action == 'H') {
            showHelp();
            continue;
        }

        auto controller = controllers.find(action);

        if (controller == controllers.end()) {
            output << "Unknown action \"" << action << "\"" << std::endl;
            continue;
        }

        output << "Running action \"" << controller->second.description << "\"" << std::endl;
        bool result = controller->second.controller.run(view);
        output << "Action finished " << (result ? "successfully" : "and failed") << std::endl;
    }

    return true;
}

redcars::controllers::CliController::CliController(redcars::controllers::RegisterController &registerController,
                                                   ReservationController &reservationController,
                                                   CheckInController& checkInController,
                                                   std::ostream &output) : output(output) {
    controllers.insert({'R', {"Register as customer", registerController}});
    controllers.insert({'P', {"Create reservation", reservationController}});
    controllers.insert({'I', {"check in", checkInController}});
}

void redcars::controllers::CliController::showHelp() const {
    for (auto &[action, controller]: controllers) {
        output << action << " = " << controller.description << std::endl;
    }

    output << "Q = quit" << std::endl;
    output << "H = help" << std::endl;
}
