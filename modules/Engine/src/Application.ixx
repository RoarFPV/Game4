module;
//#include "Tracy.hpp"

export module G4.Engine.Application;

import G4.Core;
import G4.Engine.Log;

//import Tracy;

export class Application
{
public:
  virtual void Run()
  {
    Log::Info("Running");
    //TracyCZoneN(Run, "Application::Run", true);
    Init();

    bool run = false;
    do
    {
      run = RunUpdate();
    } while (run);

    Shutdown();

  }

private:
  bool RunUpdate()
  {
    //ZoneScoped;
    return Update();
  }

protected:
  virtual void Init() = 0;
  virtual bool Update() = 0;
  virtual void Shutdown() = 0;
};

