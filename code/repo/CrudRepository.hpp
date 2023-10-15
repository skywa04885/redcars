#pragma once

#include <vector>
#include <string>

namespace redcars::repo {
    template<typename T>
    class CrudRepository {
    public:
        /**
         * pre-conditions:
         * - The resource does not conflict with existing resources.
         * post-conditions:
         * - The resource has been created.
         * */
        virtual void create(const T &) = 0;

        /**
         * pre-conditions:
         * - The resource exists.
         * post-conditions:
         * - The resource has been removed.
         * */
        virtual void remove(const T &) = 0;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        virtual std::vector<T> search(const std::string &query) = 0;

        /**
         * pre-conditions:
         * - The resource exists.
         * post-conditions:
         * - The resource has been updated.
         * */
        virtual void update(const T &) = 0;
    };
}
