#pragma once

#include "Controller.hpp"
#include "../repo/CrudRepository.hpp"
#include <sstream>

namespace redcars::controllers {
    template<typename T>
    class AdminController : public Controller {
    public:
        explicit AdminController(repo::CrudRepository<T> &repo) : repo(repo) {}

        bool run(view::View &view) override {
            view.displayMessage("S = search");
            view.displayMessage("C = create");

            char action;

            while (true) {
                view.getInput("action", action);

                if (action == 'S' || action == 'C') {
                    break;
                }
            }

            switch (action) {
                case 'S':
                    return searchAction(view);
                case 'C':
                    createAction(view);
                    return true;
                default:
                    return false;
            }
        }

        bool searchAction(view::View &view) {
            std::string query;
            view.getInput("search query", query);

            auto results = repo.search(query);

            for (size_t i = 0; i < results.size(); ++i) {
                std::stringstream ss;
                ss << "#" << i + 1;
                view.displayMessage(ss.str().c_str());
            }

            unsigned int selection;

            while (true) {
                view.getInput("Choose a vehicle", selection);
                selection -= 1;


                if (selection > (unsigned int) results.size()) {
                    view.displayErrorMessage("Please enter a valid id");
                    continue;
                }

                break;
            }

            T &value = results[selection];

            view.displayMessage("D = delete");
            view.displayMessage("E = edit");

            char action;
            while (true) {
                view.getInput("action", action);
                action = (char)std::toupper(action);

                if (action == 'E' || action == 'D') {
                    break;
                }
            }

            switch (action) {
                case 'E':
                    editAction(view, value);
                    break;
                case 'D':
                    deleteAction(value);
                    break;
                default:
                    return false;
            }

            return true;
        }

        void editAction(view::View &view, T &value) {
            show(view, value);
            value = create(view);
            repo.update(value);
        }

        void deleteAction(T &value) {
            repo.remove(value);
        }

        void createAction(view::View &view) {
            T newValue = create(view);
            show(view, newValue);
            repo.create(newValue);
        }

        virtual void show(view::View &view, const T &value) = 0;

        virtual T create(view::View &view) = 0;

    private:
        repo::CrudRepository<T> &repo;
    };
}