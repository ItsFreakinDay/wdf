// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include <regex>
#include <fstream>
#include <string>
#include <iostream>
#include "wisdom.h"
#include "aphorism.h"
#include "saying.h"
#include "proverb.h"
#include "container.h"

void processLine(const std::string& line, Container& container, const std::regex& wisdomsPattern, const std::regex& removePattern) {
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

bool readInputFile(const std::string& filename, Container& container) {
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Error opening file" << std::endl;
        return false;
    }

    std::string line;
    std::regex wisdomsPattern("ADD (aphorism|saying|proverb) \"(.+)\" ([A-Z]\\.[A-Z]\\.[A-Za-z]+|[A-Za-z]+)");
    std::regex removePattern("REM\\s+(aphorism|proverb|saying|all)\\s+([<>=!]=?)\\s+(\\d+)");

    while (std::getline(inputFile, line)) {
        processLine(line, container, wisdomsPattern, removePattern);
    }

    inputFile.close();
    return true;
}

int main() {
    /*std::ifstream inputFile("commands.txt");
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
    container.clear();*/

    Container container;
    if (!readInputFile("commands.txt", container)) {
        return 1; 
    }

    container.clear();
}
