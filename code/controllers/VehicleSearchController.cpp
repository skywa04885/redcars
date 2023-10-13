#include "VehicleSearchController.hpp"

bool redcars::controllers::VehicleSearchController::runInteractive(std::istream &input, std::ostream &output) {
    std::string location;
    unsigned int maxDistanceKm;

    getInput(input, output, "location", location);
    getInput(input, output, "max distance (km)", maxDistanceKm);

    model::Distance maxDistance = model::Distance::fromKm((int) maxDistanceKm);

    std::vector<model::Vehicle> searchResult = repo.vehicles().searchVehicles(model::GeoPosition(10, 10), maxDistance);

    while (true) {
        for (std::size_t i = 0; i < searchResult.size(); ++i) {
            output << "#" << i + 1 << std::endl;
        }

        unsigned int selectedVehicle;

        while (true) {
            std::string selectedVehicleInput;
            getInput(input, output, "Choose a vehicle", selectedVehicle);
            selectedVehicle -= 1;


            if (selectedVehicle > (unsigned int) searchResult.size()) {
                output << "Please enter a valid id" << std::endl;
                continue;
            }

            break;
        }

        output << "Selected a ";

        switch (searchResult[selectedVehicle].getKind()) {

            case model::VehicleKind::Station:
                output << "station wagon";
                break;
            case model::VehicleKind::Personal:
                output << "personal vehicle";
                break;
        }

        output << std::endl;

        if (confirm(input, output, "is this correct?")) {
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
