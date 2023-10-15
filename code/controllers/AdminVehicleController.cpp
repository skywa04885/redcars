
#include "AdminVehicleController.hpp"

redcars::model::Vehicle redcars::controllers::AdminVehicleController::create(redcars::view::View &view) {
    unsigned int longitude;
    unsigned int latitude;

    view.getInput("longitude", longitude);
    view.getInput("latitude", latitude);
    bool isPersonal = view.confirm("Is personal vehicle");

    std::string licensePlate;
    view.getInput("license plate", licensePlate);

    return redcars::model::Vehicle(model::GeoPosition((double) longitude, double(latitude)), std::time(nullptr),
                                   isPersonal ? model::VehicleKind::Personal : model::VehicleKind::Station,
                                   licensePlate);
}

void
redcars::controllers::AdminVehicleController::show(redcars::view::View &view, const redcars::model::Vehicle &value) {
    view.displayMessage("Vehicle:");
    view.displayMessage(value.getKind() == model::VehicleKind::Station ? "Station" : "Personal");
    view.displayMessage(value.getLicencePlate().c_str());
}
