#include <oglr/extra/logger.hpp>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace oglr {

std::shared_ptr<spdlog::logger> Log::pr_CoreLogger;
std::shared_ptr<spdlog::logger> Log::pr_ClientLogger;

void Log::CoreInit()
{
    spdlog::set_pattern("%^[%T] %n: %v%$");
    pr_CoreLogger = spdlog::stdout_color_mt("OGLR");
    pr_CoreLogger->set_level(spdlog::level::trace);
}
void Log::ClientInit()
{
    spdlog::set_pattern("%^[%T] %n: %v%$");
    pr_ClientLogger = spdlog::stdout_color_mt("APP");
    pr_ClientLogger->set_level(spdlog::level::trace);
}
}
