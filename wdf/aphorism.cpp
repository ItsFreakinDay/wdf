#include "aphorism.h"
#include <iostream>

Aphorism::Aphorism(const std::string& content, const std::string& author)
    : Wisdom(content), author(author) {}

std::string Aphorism::getAuthor() const {
    return author;
}

void Aphorism::printType() const {
    std::cout << "Type: Aphorism" << std::endl;
}

void Aphorism::printDetails() const {
    std::cout << "Author: " << getAuthor() << std::endl;
}