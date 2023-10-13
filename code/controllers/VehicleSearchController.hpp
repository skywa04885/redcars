#pragma once

#include "Controller.hpp"
#include "../repo/Repository.hpp"

namespace redcars::controllers {
    class VehicleSearchController : public Controller {
    public:
        explicit VehicleSearchController(repo::Repository &repo);

        bool runInteractive(std::istream &input, std::ostream &output) override;

        const std::optional<model::Vehicle> &getSelected() const;

    private:
        repo::Repository& repo;
        std::optional<model::Vehicle> selected;
    };
}
