#pragma once


#include <map>
#include <string>
#include "Controller.hpp"
#include "RegisterController.hpp"

namespace redcars::controllers {
    class CliController : public Controller {
    public:
        CliController(RegisterController &registerController);

        void runInteractive(std::istream &input, std::ostream &output) override;

    private:
        void showHelp(std::ostream& output) const;

        struct ControllerEntry {
            std::string description;
            Controller &controller;
        };

        std::map<char, ControllerEntry> controllers;
    };

}


