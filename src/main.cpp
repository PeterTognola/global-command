#include <iostream>
#include <saucer/smartview.hpp>
#include <saucer/embedded/all.hpp>

#include "utils/utils.h"
#include "webview/webview.h"

int main()
{
    /*
     * todo
     * - Search and launch apps.
     * - Search files (not sure how to do this properly yet).
     * - Allow calculations.
     * - Run bash commands.
     */
    for (const auto& file: Programs::getPrograms()) std::cout << "test " << file << std::endl;

    return application::create({.id = "command"})->run(WebView::start);
}