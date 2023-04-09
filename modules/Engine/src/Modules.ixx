module;
//#include "Tracy.hpp"

export module G4.Engine.Modules;

import G4.Core;
import G4.Core.Types;
import G4.Engine.Log;

class Engine;

export class EngineModule
{
public:
  void Attach(std::shared_ptr<Engine> owner)
  {
    engine = owner;
    OnAttach();
  }

  void Detach(bool engineDetach=true);

  virtual ~EngineModule()
  {
    Detach();
  }

protected:

  virtual void OnAttach() = 0;
  virtual void OnDetach() = 0;

  std::shared_ptr<Engine> engine;
private:

};


export class Engine
{
public:
  Engine()
  {
    instance = std::shared_ptr<Engine>(this);
  }

  static Engine& Get()
  {
    //(instance != nullptr);
    return *instance;
  }

  template<typename TModuleType> 
  static std::shared_ptr<TModuleType> Module()
  {
    return instance->Get<TModuleType>();
  }

  template<typename TRegType>
  void Attach(std::shared_ptr<EngineModule> mod)
  {
    //TODO: overwrite for now?
    modules.emplace(Types::Id<TRegType>(),mod);
    mod->Attach(instance);
  }


  void Detach(EngineModule* mod)
  {
    // Remove all pairs of types registered to the same value
    std::erase_if(modules,
      [&](const auto& item) {
        auto const& [key, value] = item;
        if (value.get() == mod)
        {
          mod->Detach();
          return true;
        }

        return false;
      }
    );
  }

  void DetachAll()
  {
    modules.clear();
  }

  template<typename TModuleType>
  bool Has() const
  {
    return modules.contains(Types::Id<TModuleType>());
  }

  template<typename TModuleType>
  std::shared_ptr<TModuleType> Get() const
  {
    return modules.at(Types::Id<TModuleType>());
  }

private:
  std::unordered_map<TypeId, std::shared_ptr<EngineModule>> modules;

  static std::shared_ptr<Engine> instance;
};

void EngineModule::Detach(bool engineDetach)
{
  OnDetach();

  if(engineDetach)
    engine->Detach(this);

  engine = nullptr;
}
export using Engine_stpr = std::shared_ptr<Engine>;

std::shared_ptr<Engine> Engine::instance;







