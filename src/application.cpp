#include "oglr/extra/logger.hpp"
#include <glad/glad.h>
#include <oglr/application.hpp>

namespace oglr {
Application::Application()
{
    Log::CoreInit();
    OGLR_CORE_INFO("Application Initialised");
}
Application::~Application()
{
    if (window != nullptr)
        DestroyWindow();

    OGLR_CORE_INFO("Application De-Initialised");
}
void Application::CreateWindow(const WindowSettings& windowSettings)
{
    window = new Window(windowSettings);
}
void Application::DestroyWindow()
{
    delete window;
}
}
