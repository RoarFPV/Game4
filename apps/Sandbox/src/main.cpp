import Sandbox;


int main()
{
  Engine engine;

  auto sanbox = std::make_shared<Sandbox>();
  engine.Attach<Application>(sanbox);
  // TODO: engine.Run()???
  sanbox->Run();
  return 0;
}
