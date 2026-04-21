#include <iostream>
#include <saucer/smartview.hpp>
#include <saucer/embedded/all.hpp>
#include "webview/webview.h"

class Programs {
public:
    static std::vector<std::string> getPrograms();
};

std::vector<std::string> runAndGetResultsFromCommand(const char* command) {
    std::vector<std::string> results;

    system(command);

    std::ifstream in("gc-program-results.txt");
    std::string line;
    while(getline(in, line)) results.push_back(line);

    in.close();

    remove("gc-program-results.txt");

    return results;
}

std::vector<std::string> Programs::getPrograms() {
    return runAndGetResultsFromCommand("ls /usr/share/applications | awk -F '.desktop' ' { print $1}' - > gc-program-results.txt"); // todo take out > gc-program-results.txt
}

int main()
{
    for (auto file: Programs::getPrograms()) {
        std::cout << "test " << file << std::endl;
    }

    return application::create({.id = "hello-world"})->run(WebView::start);
}