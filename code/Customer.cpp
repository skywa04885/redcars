#include "Customer.hpp"
#include <optional>

Customer::Customer(std::string firstname, std::string lastname, std::string email, std::optional<Card> card)
	: User(firstname, lastname, email), card(card) {}

