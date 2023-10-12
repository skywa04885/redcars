#pragma once

#include <string>
class User {
public:
  User(std::string firstname, std::string lastname, std::string email);
  virtual ~User() = default;

private:
  std::string firstname;
  std::string lastname;
  std::string email;
};
