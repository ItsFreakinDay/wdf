#pragma once
#include "wisdom.h"
#include <forward_list>

class Container {
public:
    void add(Wisdom* wisdom);
    void removeWisdoms(const std::string& type, const std::string& comparison, int number);
    void printWisdoms() const;
    void clear();

private:
    std::forward_list<Wisdom*> Wisdoms;
};

