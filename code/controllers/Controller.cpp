#include "Controller.hpp"

void redcars::controllers::Controller::getInput(std::istream &input, std::ostream &output, const char *valueName,
                                                std::string &target) {
    output << "Enter your " << valueName << ": ";
    input >> target;
}

bool redcars::controllers::Controller::confirm(std::istream &input, std::ostream &output, const char *msg) {
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
