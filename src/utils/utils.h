//
// Created by james-tognola on 22/04/2026.
//

#ifndef GLOBAL_COMMAND_UTILS_H
#define GLOBAL_COMMAND_UTILS_H
#include <string>
#include <vector>

using namespace std;

namespace utils {
    class Utils {
        public:
            static vector<string> getListCommand(const string& command);
            static string joinToStringArray(const string &prev, const string &curr);
    };

    class Programs {
        public:
            static vector<string> getPrograms();
    };
} // utils

#endif //GLOBAL_COMMAND_UTILS_H