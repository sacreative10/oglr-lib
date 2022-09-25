#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>
#include <cstdint>
#include <string>
namespace oglr {
struct WindowSettings {
    uint32_t windowWidth;
    uint32_t windowHeight;
    std::string windowTitle;
};
class Window {
public:
    Window(const WindowSettings& WS);
    ~Window();

    inline GLFWwindow* getGLFWWindowHandle() { return m_window; }

private:
    void initGLFW();
    void createWindow();
    void initGLAD();

    static void static_keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
    static void static_windowCallback(GLFWwindow* window, int width, int height);

    void keyboardCallback(int key, int scancode, int action, int mode);
    void windowCallback(int width, int height);

private:
    GLFWwindow* m_window = nullptr;
    WindowSettings m_wm;
};
}

#endif // WINDOW_H
