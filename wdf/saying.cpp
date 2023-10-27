#include "saying.h"
#include <iostream>

Saying::Saying(const std::string& content, const std::string& country)
    : Wisdom(content), country(country) {}

std::string Saying::getCountry() const {
    return country;
}

void Saying::printType() const {
    std::cout << "Type: Saying" << std::endl;
}

void Saying::printDetails() const {
    std::cout << "Country: " << getCountry() << std::endl;
}
