//
// Created by james-tognola on 21/04/2026.
//

#include "webview.h"

#include <iostream>
#include <numeric>
#include <saucer/embedded/all.hpp>
#include "saucer/smartview.hpp"
#include "saucer/window.hpp"
#include <print>

#include "../utils/utils.h"

stray WebView::start(application *app) {
    auto window  = window::create(app).value();
    auto webview = smartview::create({.window = window});

    webview -> embed(embedded::all());
    webview -> set_dev_tools(true);

    window -> set_decorations(window::decoration::none);

    window -> set_title("Global Command");

    window -> set_min_size({720, 80});
    window -> set_size({720, 80});
    window -> set_resizable(false);

    webview -> expose("search", [&]() -> task<double>
    {
        auto random = *co_await webview->evaluate<double>("Math.random()");
        std::println("Random: {}", random);
        co_return random;
    });

    webview -> inject({
        .code = "window.apps = ['1','2','3']",
        .run_at = script::time::creation
    });

    webview -> expose("close", [window]() -> task<void> {
        window -> hide();
    });

    webview -> serve("/index.html");

    window -> show();

    co_await app->finish();
}

script WebView::createAppInjection() {
    auto files = utils::Programs::getPrograms();

    auto alt = std::accumulate(
    std::next(files.begin()),
    files.end(),
    files[0],
    [](std::string a, std::string b) {
        return a + "," + format("\"{}\"", b);
    }
);

    return {
        .code = format("window.apps = [{}]", alt),
        .run_at = script::time::creation
    };
}