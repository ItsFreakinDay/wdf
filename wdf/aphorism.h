#pragma once
#include "wisdom.h"

class Aphorism : public Wisdom {
public:
    Aphorism(const std::string& content, const std::string& author);

    std::string getAuthor() const;
    void printType() const override;
    void printDetails() const override;

private:
    std::string author;
};
