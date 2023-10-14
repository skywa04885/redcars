#include "VehicleSearchController.hpp"
#include <sstream>

bool redcars::controllers::VehicleSearchController::run(view::View &view) {
    std::string location;
    unsigned int maxDistanceKm;

    view.getInput("location", location);
    view.getInput("max distance (km)", maxDistanceKm);

    model::Distance maxDistance = model::Distance::fromKm((int) maxDistanceKm);

    std::vector<model::Vehicle> searchResult = repo.vehicles().searchVehicles(model::GeoPosition(10, 10), maxDistance);

    while (true) {
        for (std::size_t i = 0; i < searchResult.size(); ++i) {
            std::stringstream ss;
            ss << "#";
            ss << i + 1;
            view.displayMessage(ss.str().c_str());
        }

        unsigned int selectedVehicle;

        while (true) {
            std::string selectedVehicleInput;
            view.getInput("Choose a vehicle", selectedVehicle);
            selectedVehicle -= 1;


            if (selectedVehicle > (unsigned int) searchResult.size()) {
                view.displayErrorMessage("Please enter a valid id");
                continue;
            }

            break;
        }

        view.displayMessage("Selected:");

        switch (searchResult[selectedVehicle].getKind()) {

            case model::VehicleKind::Station:
                view.displayMessage("\tstation wagon");
                break;
            case model::VehicleKind::Personal:
                view.displayMessage("\tpersonal vehicle");
                break;
        }

        if (view.confirm("is this correct?")) {
            selected = searchResult[selectedVehicle];
            break;
        }
    }

    return true;
}

redcars::controllers::VehicleSearchController::VehicleSearchController(redcars::repo::Repository &repo) : repo(repo) {}

const std::optional<redcars::model::Vehicle> &redcars::controllers::VehicleSearchController::getSelected() const {
    return selected;
}
