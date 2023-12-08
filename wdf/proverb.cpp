// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "proverb.h"
#include <iostream>

Proverb::Proverb(const std::string& content, const std::string& country)
    : Wisdom(content), country(country) {}

std::string Proverb::getCountry() const {
    return country;
}

void Proverb::printType() const {
    std::cout << "Type: Proverb" << std::endl;
}

void Proverb::printDetails() const {
    std::cout << "Country: " << getCountry() << std::endl;
}
