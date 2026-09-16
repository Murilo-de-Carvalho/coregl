#pragma once
#include "macros.hpp"

std::vector<std::string> split(std::string line, std::string delimiter) {

    std::vector<std::string> split_line;

    size_t pos = 0;
    std::string token;

    // Finds token + delimiter, keeps token and erase both from the line until can't find delimiter
    while ( (pos = line.find(delimiter)) != std::string::npos ) {

        token = line.substr(0, pos);
        split_line.push_back(token);
        line.erase(0, pos + delimiter.size());

    }

    // Since it finds the delimiter AFTER the token, final token might not have a delimiter
    // So we append the rest of the line
    split_line.push_back(line);

    return split_line;
}