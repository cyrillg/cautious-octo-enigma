#pragma once

#include <memory>
#include "core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace octo
{
  class OCTO_API Log
  {
  public:
    static void Init();

    inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_core_logger_; }
    inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_client_logger_; }
    ~Log();

  private:
    static std::shared_ptr<spdlog::logger> s_core_logger_;
    static std::shared_ptr<spdlog::logger> s_client_logger_;
  };
}

#define OCTO_CORE_TRACE(...)  ::octo::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define OCTO_CORE_INFO(...)   ::octo::Log::GetCoreLogger()->info(__VA_ARGS__)
#define OCTO_CORE_WARN(...)   ::octo::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define OCTO_CORE_ERROR(...)  ::octo::Log::GetCoreLogger()->error(__VA_ARGS__)
#define OCTO_CORE_FATAL(...)  ::octo::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define OCTO_TRACE(...)       ::octo::Log::GetClientLogger()->trace(__VA_ARGS__)
#define OCTO_INFO(...)        ::octo::Log::GetClientLogger()->info(__VA_ARGS__)
#define OCTO_WARN(...)        ::octo::Log::GetClientLogger()->warn(__VA_ARGS__)
#define OCTO_ERROR(...)       ::octo::Log::GetClientLogger()->error(__VA_ARGS__)
#define OCTO_FATAL(...)       ::octo::Log::GetClientLogger()->critical(__VA_ARGS__)