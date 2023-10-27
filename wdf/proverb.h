#pragma once
#include "wisdom.h"

class Proverb : public Wisdom {
public:
    Proverb(const std::string& content, const std::string& country);

    std::string getCountry() const;
    void printType() const override;
    void printDetails() const override;

private:
    std::string country;
};