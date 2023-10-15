#include "AdminStationController.hpp"

void
redcars::controllers::AdminStationController::show(redcars::view::View &view, const redcars::model::Station &value) {
    view.displayMessage("Station:");
    view.displayMessage(std::to_string(value.getMaxVehicleCount()).c_str());
}

redcars::model::Station redcars::controllers::AdminStationController::create(redcars::view::View &view) {
    unsigned int longitude;
    unsigned int latitude;
    unsigned int maxVehicleCount;

    view.getInput("longitude", longitude);
    view.getInput("latitude", latitude);
    view.getInput("max vehicle count", maxVehicleCount);

    return model::Station(model::GeoPosition((double) longitude, (double) latitude), (int) maxVehicleCount);
}
