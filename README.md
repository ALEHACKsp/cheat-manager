# Cheat Manager
## About
A simple cheat manager, written in Modern C++.

## How to use
Simply put this source into your project.

**Register the cheats like so:**
```cpp
/// Simple infinite ammo cheat.
CheatManager::Register("CheatName", []() -> bool
{
  /// Do your cheat code in here.
  static auto Ammo = 0xC0FFEE;
  
  *reinterpret_cast<std::uintptr_t*>(Ammo) = 69420;
  
  return true;
})
```

**Call them like so:**
```cpp
const bool Success = CheatManager::Call("CheatName");
```
