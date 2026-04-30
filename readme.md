# Global Command

There are two parts to this project:

- **Webview**: The webview component is responsible for rendering the user interface, handling user interactions, and low level system actions.
- **UI**: The UI component is responsible for managing the application's state and coordinating interactions between the webview and the operating system.

# Prerequisites

- CMake 4.1+
- Node.js 22+
- NPM 10+

# Building

Building the project as a whole is simple and cmake handles the building of the UI. 

```shell
cmake -B cmake-build-debug
```