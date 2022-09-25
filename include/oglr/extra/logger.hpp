#pragma once

#include <memory>
#include <spdlog/spdlog.h>

namespace oglr {
class Log {
public:
    static void CoreInit();
    static void ClientInit();

    inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return pr_CoreLogger; }
    inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return pr_ClientLogger; }

private:
    static std::shared_ptr<spdlog::logger> pr_CoreLogger;
    static std::shared_ptr<spdlog::logger> pr_ClientLogger;
};
}

#define OGLR_CORE_TRACE(...) ::oglr::Log::getCoreLogger()->trace(__VA_ARGS__)
#define OGLR_CORE_INFO(...) ::oglr::Log::getCoreLogger()->info(__VA_ARGS__)
#define OGLR_CORE_WARN(...) ::oglr::Log::getCoreLogger()->warn(__VA_ARGS__)
#define OGLR_CORE_ERROR(...) ::oglr::Log::getCoreLogger()->error(__VA_ARGS__)
#define OGLR_CORE_FATAL(...) ::oglr::Log::getCoreLogger()->fatal(__VA_ARGS__)
#define OGLR_CORE_DEBUG(...) ::oglr::Log::getCoreLogger()->debug(__VA_ARGS__)

#define CLIENT_TRACE(...) ::oglr::Log::getClientLogger()->trace(__VA_ARGS__)
#define CLIENT_INFO(...) ::oglr::Log::getClientLogger()->info(__VA_ARGS__)
#define CLIENT_WARN(...) ::oglr::Log::getClientLogger()->warn(__VA_ARGS__)
#define CLIENT_ERROR(...) ::oglr::Log::getClientLogger()->error(__VA_ARGS__)
#define CLIENT_FATAL(...) ::oglr::Log::getClientLogger()->fatal(__VA_ARGS__)
#define CLIENT_DEBUG(...) ::oglr::Log::getClientLogger()->debug(__VA_ARGS__)
