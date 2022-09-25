#include <glad/glad.h>
#include <oglr/extra/logger.hpp>
#include <oglr/window.hpp>

namespace oglr {
Window::Window(const WindowSettings& wm)
    : m_wm(wm)
{
    initGLFW();
    createWindow();
    initGLAD();
    glfwSetWindowSizeCallback(m_window, static_windowCallback);
    glfwSetKeyCallback(m_window, static_keyboardCallback);
}

Window::~Window()
{
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

void Window::initGLFW()
{
    if (!glfwInit()) {
        OGLR_CORE_ERROR("GLFW could not be initialized... exiting");
        exit(-1);
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);

    OGLR_CORE_DEBUG("GLFW Initialised");
}
void Window::createWindow()
{
    m_window = glfwCreateWindow(m_wm.windowWidth, m_wm.windowHeight, m_wm.windowTitle.c_str(), NULL, NULL);
    if (m_window == NULL) {
        OGLR_CORE_ERROR("Window could not be initalized... exiting");
        exit(-2);
    }
    glfwMakeContextCurrent(m_window);
    OGLR_CORE_DEBUG("Window initialised");
}
void Window::initGLAD()
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        OGLR_CORE_ERROR("GLAD could not be initalized... exiting");
        exit(-3);
    }
    glViewport(m_wm.windowWidth, m_wm.windowWidth, 0, 0);
}
void Window::static_windowCallback(GLFWwindow* window, int width, int height)
{
    // doing this since we cannot access member vars in static functions
    Window* actualWindow = (Window*)glfwGetWindowUserPointer(window);
    actualWindow->windowCallback(width, height);
}
void Window::static_keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    Window* actualWindow = (Window*)glfwGetWindowUserPointer(window);
    actualWindow->keyboardCallback(key, scancode, action, mode);
}

void Window::keyboardCallback(int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(m_window, true);
}
void Window::windowCallback(int width, int height)
{

    glfwSetWindowSize(m_window, width, height);
    glViewport(width, height, 0, 0);

    m_wm.windowWidth = width;
    m_wm.windowHeight = height;
}
}
