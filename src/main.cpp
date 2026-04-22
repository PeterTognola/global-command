#include <iostream>
#include <saucer/smartview.hpp>
#include <saucer/embedded/all.hpp>

#include "utils/utils.h"
#include "webview/webview.h"

class Programs {
public:
    static std::vector<std::string> getPrograms();
};

std::vector<std::string> Programs::getPrograms() {
    return utils::Utils::getListCommand("ls /usr/share/applications | awk -F '.desktop' ' { print $1}' -");
}

int main()
{
    for (const auto& file: Programs::getPrograms()) std::cout << "test " << file << std::endl;

    return application::create({.id = "hello-world"})->run(WebView::start);
}