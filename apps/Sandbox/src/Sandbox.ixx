
module;

export module Sandbox;

export import G4.Engine;
//import "TracyC.h";
import Tracy;



export class Sandbox : public Application, public EngineModule
{
  std::int32_t initCount;
  std::int32_t updateCount;
  std::int32_t shutdownCount;

public:
  Sandbox()
    : initCount(0)
    , updateCount(0)
    , shutdownCount(0)
  {

  }

  void OnAttach() override
  {
    Log::Info("Sandbox attached: %d", initCount);
  }

  void OnDetach() override
  {
    Log::Info("Sandbox detached: %d", initCount);
  }

protected:

  int32_t updateTimeMs;

  void Init() override
  {
    //TracyCZone(Init, true);
    ++initCount;
    Log::Info("Sandbox initialized: %d", initCount);
    //TracyCZoneEnd(Init);
  }

  bool Update() override
  {
    TracyCFrameMark;
    TracyCZoneN(Update,"UpdatE", true);

    auto start = std::chrono::steady_clock::now();

    ++updateCount;
    Log::Debug("Update Count: %d, init: %d, us: %d", updateCount, initCount, updateTimeMs);


    auto end = std::chrono::steady_clock::now();
    auto updateTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    updateTimeMs = (int32_t)updateTime.count();
    auto sleepTime = std::chrono::milliseconds(16) - updateTime;
    std::this_thread::sleep_for(sleepTime);

    TracyCZoneEnd(Update);

    return initCount == 1 && shutdownCount == 0 && updateCount < std::numeric_limits<int32_t>::max();
  }
  void Shutdown() override
  {
    //TracyCZone(Shutdown, true);
    ++shutdownCount;
    Log::Info("Sandbox shutdown: %d init: %d, update: %d"
      , shutdownCount, initCount, updateCount);
    //TracyCZoneEnd(Shutdown);
  }
};
