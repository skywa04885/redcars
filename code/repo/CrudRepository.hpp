#pragma once

#include <vector>
#include <string>

namespace redcars::repo {
    template<typename T>
    class CrudRepository {
    public:
        virtual void create(const T &) = 0;

        virtual void remove(const T &) = 0;

        virtual std::vector<T> search(const std::string &query) = 0;

        virtual void update(const T &) = 0;
    };
}
