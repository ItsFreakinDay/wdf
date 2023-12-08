// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
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
