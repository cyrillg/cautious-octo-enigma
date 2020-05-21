#pragma once

#ifdef OCTO_PLATFORM_WINDOWS

extern octo::Application* octo::CreateApplication();

int main(int argc, int** argv)
{
  auto app = octo::CreateApplication();
  app->Run();
  delete app;
}

#endif // OCTO_PLATFORM_WINDOWS
