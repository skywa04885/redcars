#pragma once

#include "Controller.hpp"
#include "../repo/Repository.hpp"

namespace redcars::controllers {
    class VehicleSearchController : public Controller {
    public:
        explicit VehicleSearchController(repo::Repository &repo);

        /**
         * pre-conditions: none
         * post-conditions:
         * - (when true is returned) a vehicle is selected.
         * */
        bool run(view::View &view) override;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        const std::optional<model::Vehicle> &getSelected() const;

    private:
        repo::Repository &repo;
        std::optional<model::Vehicle> selected;
    };
}
