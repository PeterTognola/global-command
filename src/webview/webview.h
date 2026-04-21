//
// Created by james-tognola on 21/04/2026.
//

#ifndef GLOBAL_COMMAND_WEBVIEW_H
#define GLOBAL_COMMAND_WEBVIEW_H
#include "coco/stray/stray.hpp"
#include "saucer/app.hpp"

using namespace coco;
using namespace saucer;

class WebView {
public:
    static stray start(application *app);
};


#endif //GLOBAL_COMMAND_WEBVIEW_H