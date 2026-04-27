//
// Created by james-tognola on 21/04/2026.
//

#include "webview.h"
#include <saucer/embedded/all.hpp>
#include "saucer/smartview.hpp"
#include "saucer/window.hpp"
#include <print>

stray WebView::start(application *app) {
    auto window  = window::create(app).value();
    auto webview = smartview::create({.window = window});

    webview -> embed(embedded::all());
    webview -> set_dev_tools(true);

    window -> set_decorations(window::decoration::none);

    window -> set_title("Global Command");

    window -> set_size({720, 140});
    window -> set_resizable(false);

    webview -> expose("search", [&](bool force) -> task<double>
    {
        auto random = *co_await webview->evaluate<double>("Math.random()");
        std::println("Random: {}", random);
        co_return random;
    });

    webview -> serve("/index.html");

    window -> show();

    co_await app->finish();
}
