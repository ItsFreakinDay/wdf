#pragma once
#include <string>

class Wisdom {
public:
    Wisdom(const std::string& content);

    std::string getContent() const;
    virtual void printType() const = 0;
    virtual void printDetails() const = 0;

private:
    std::string content;
};
