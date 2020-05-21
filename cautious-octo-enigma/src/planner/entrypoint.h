#pragma once

#ifdef OCTO_PLATFORM_WINDOWS

extern octo::Application* octo::CreateApplication();

int main(int argc, int** argv)
{
  octo::Log::Init();
  OCTO_CORE_FATAL("Initialized core");
  int a = 10;
  OCTO_INFO("Initialized client. Var: {0}", a);
  auto app = octo::CreateApplication();
  app->Run();
  delete app;
}

#endif // OCTO_PLATFORM_WINDOWS
