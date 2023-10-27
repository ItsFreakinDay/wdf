#pragma once
#include "wisdom.h"
#include <string>
class Saying : public Wisdom {
public:
    Saying(const std::string& content, const std::string& country);

    std::string getCountry() const;
    void printType() const override;
    void printDetails() const override;

private:
    std::string country;
};
