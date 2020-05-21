#pragma once

#include "core.h"

namespace octo
{
  class OCTO_API Application
  {
public:
    Application();
    virtual ~Application();
    void Run();
  };

  // To be defined in client
  Application* CreateApplication();
}

