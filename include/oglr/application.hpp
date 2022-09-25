#ifndef APPLICATION_H
#define APPLICATION_H

#include <cstdint>
#include <string>

#include <oglr/window.hpp>
namespace oglr {

class Application {
public:
    Application();
    ~Application();

    void CreateWindow(const WindowSettings& windowSettings);
    void DestroyWindow();

private:
    Window* window = nullptr;
};
}

#endif // APPLICATION_H
