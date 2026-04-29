//
// Created by james-tognola on 22/04/2026.
//

#include "utils.h"
#include <fstream>
#include <iostream>

namespace utils {
    vector<string> Utils::getListCommand(const string& command) {
        const auto filename = "command-results.txt";
        const auto output = command + " > " + filename;

        vector<std::string> results;

        system(output.c_str());

        ifstream in(filename);
        string line;
        while(getline(in, line)) results.push_back(line);

        in.close();

        remove(filename);

        return results;
    }

    string Utils::joinToStringArray(const string &prev, const string &curr) {
        return format(
            // Our string template.
            "{}, '{}'",
            // If this is our first element, format differently.
            prev.contains("', '") ? prev : format("'{}'", prev),
            // Curr will feel left out if not comment...
            curr);
    }

    std::vector<std::string> Programs::getPrograms() {
        return Utils::getListCommand("ls /usr/share/applications | awk -F '.desktop' ' { print $1}' -");
    }
} // utils