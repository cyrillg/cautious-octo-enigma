#include "log.h"

namespace octo
{
  std::shared_ptr<spdlog::logger> Log::s_core_logger_;
  std::shared_ptr<spdlog::logger> Log::s_client_logger_;

  void Log::Init()
  {
    spdlog::set_pattern("%^[%T] %n: %v%$");
    s_core_logger_ = spdlog::stdout_color_mt("OCTO");
    s_core_logger_->set_level(spdlog::level::trace);
    s_client_logger_ = spdlog::stdout_color_mt("APP");
    s_client_logger_->set_level(spdlog::level::trace);
  };
}