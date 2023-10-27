#include "container.h"
#include "wisdom.h"
#include "aphorism.h"
#include "saying.h"
#include "proverb.h"
#include <iostream>

void Container::add(Wisdom* wisdom) {
    Wisdoms.push_front(wisdom);
}

void Container::removeWisdoms(const std::string& type, const std::string& comparison, int number) {
    auto isToRemove = [comparison, number](Wisdom* wisdom) {
        if (comparison == "<") {
            return wisdom->getContent().length() < number;
        }
        else if (comparison == "<=") {
            return wisdom->getContent().length() <= number;
        }
        else if (comparison == ">") {
            return wisdom->getContent().length() > number;
        }
        else if (comparison == ">=") {
            return wisdom->getContent().length() >= number;
        }
        else if (comparison == "=") {
            return wisdom->getContent().length() == number;
        }
        else if (comparison == "!=") {
            return wisdom->getContent().length() != number;
        }
        return false;
        };

    Wisdoms.remove_if([&](Wisdom* wisdom) {
        if (type == "all" ||
            (type == "aphorism" && dynamic_cast<Aphorism*>(wisdom) != nullptr) ||
            (type == "saying" && dynamic_cast<Saying*>(wisdom) != nullptr) ||
            (type == "proverb" && dynamic_cast<Proverb*>(wisdom) != nullptr)) {
            return isToRemove(wisdom);
        }
        return false;
        });
}

void Container::printWisdoms() const {
    for (const auto& wisdom : Wisdoms) {
        wisdom->printType();
        std::cout << "Content: " << wisdom->getContent() << std::endl;
        wisdom->printDetails();
        std::cout << std::endl;
    }
}

void Container::clear() {
    for (auto wisdom : Wisdoms) {
        delete wisdom;
    }
    Wisdoms.clear();
}
