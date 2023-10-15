#pragma once

#include "Controller.hpp"
#include "../repo/CrudRepository.hpp"
#include <sstream>

namespace redcars::controllers {
    template<typename T>
    class AdminController : public Controller {
    public:
        explicit AdminController(repo::CrudRepository<T> &repo) : repo(repo) {}

        /**
         * pre-conditions:
         * - The current user is logged in.
         * - The current user is an admin.
         *
         * post-conditions (one of the following):
         * - Nothing (the user canceled the request)
         * - A resource has been deleted
         * - A resource has been edited
         * - A resource has been created
         * */
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
                action = (char) std::toupper(action);

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

        /**
         * pre-conditions: none
         * post-conditions:
         * - The passed resource has been edited
         * */
        void editAction(view::View &view, T &value) {
            show(view, value);
            value = create(view);
            repo.update(value);
        }

        /**
         * pre-conditions: none
         * post-conditions:
         * - The passed resource has been deleted
         * */
        void deleteAction(T &value) {
            repo.remove(value);
        }

        /**
         * pre-conditions: none
         * post-conditions:
         * - A new resource has been created
         * */
        void createAction(view::View &view) {
            T newValue = create(view);
            show(view, newValue);
            repo.create(newValue);
        }

        /**
         * pre-conditions: none
         * post-conditions:
         * - A representation of the resource has been displayed
         * */
        virtual void show(view::View &view, const T &value) = 0;

        /**
         * preconditions: none
         * post-conditions:
         * - A new (in-memory only) resource has been created.
         * */
        virtual T create(view::View &view) = 0;

    private:
        repo::CrudRepository<T> &repo;
    };
}