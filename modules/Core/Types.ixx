module;
//#include "Tracy.hpp"

export module G4.Core.Types;

import <cstdint>;

export namespace Types
{
  template<typename TType>
  uint64_t Id()
  {
    static uint32_t id = 0;
    return reinterpret_cast<uint64_t>(&id);
  }
}

export typedef uint64_t TypeId;







