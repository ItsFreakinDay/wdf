#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <forward_list>
#include <algorithm>
#include "wisdom.h"
#include "aphorism.h"
#include "saying.h"
#include "proverb.h"
#include "container.h"

int main() {
    std::ifstream inputFile("commands.txt");
    if (!inputFile) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::string line;
    std::regex wisdomsPattern("ADD (aphorism|saying|proverb) \"(.+)\" ([A-Z]\\.[A-Z]\\.[A-Za-z]+|[A-Za-z]+)");
    std::regex removePattern("REM\\s+(aphorism|proverb|saying|all)\\s+([<>=!]=?)\\s+(\\d+)");

    Container container;

    while (std::getline(inputFile, line)) {
        std::smatch matches;
        if (std::regex_search(line, matches, wisdomsPattern)) {
            Wisdom* wisdom = nullptr;
            std::string type = matches[1].str();
            std::string content = matches[2].str();
            std::string details = matches[3].str();

            if (type == "aphorism") {
                wisdom = new Aphorism(content, details);
            }
            else if (type == "saying") {
                wisdom = new Saying(content, details);
            }
            else if (type == "proverb") {
                wisdom = new Proverb(content, details);
            }

            if (wisdom) {
                container.add(wisdom);
            }
        }
        else if (std::regex_search(line, matches, removePattern)) {
            std::string type = matches[1].str();
            std::string comparison = matches[2].str();
            int number = std::stoi(matches[3].str());
            container.removeWisdoms(type, comparison, number);
        }
        else if (line.compare(0, 5, "PRINT") == 0) {
            container.printWisdoms();
        }

    }
    inputFile.close();
    container.clear();
}
