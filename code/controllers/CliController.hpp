#pragma once


#include <map>
#include <string>

#include "Controller.hpp"
#include "RegisterController.hpp"
#include "ReservationController.hpp"
#include "CheckInController.hpp"
#include "CheckOutController.hpp"

namespace redcars::controllers {
    class CliController : public Controller {
    public:
        CliController(redcars::controllers::RegisterController &registerController,
                      ReservationController &reservationController,
                      CheckInController& checkInController,
                      CheckOutController& checkOutController,
                      std::ostream &output);

        bool run(view::View& view) override;

    private:
        void showHelp() const;

        struct ControllerEntry {
            std::string description;
            Controller &controller;
        };

        std::map<char, ControllerEntry> controllers;
        std::ostream& output;
    };

}


