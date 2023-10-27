#include "wisdom.h"

Wisdom::Wisdom(const std::string& content) : content(content) {}

std::string Wisdom::getContent() const {
    return content;
}
