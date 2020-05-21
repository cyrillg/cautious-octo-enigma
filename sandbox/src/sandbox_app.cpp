#include <octo.h>

class Sandbox : public octo::Application
{
public:
  Sandbox() {};

  ~Sandbox() {};
};

octo::Application* octo::CreateApplication()
{
  return new Sandbox();
}