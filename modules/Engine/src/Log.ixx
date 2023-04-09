module;

#include <cstdio>
#include <stdarg.h>
#include <string>

export module G4.Engine.Log;

//import std;

//import <string>;
//import <iostream>;
//import <cstdio>;

export class Log
{
public:
  template<typename... TArgs>
  static void Info(const std::string& format, TArgs...args)
  {
    Print("INFO", format, args...);
  }

  template<typename... TArgs>
  static void Debug(const std::string& format, TArgs...args)
  {
    Print("DEBUG", format, args...);
  }

  template<typename... TArgs>
  static void Warn(const std::string& format, TArgs...args)
  {
    Print("WARN", format, args...);

  }

  template<typename... TArgs>
  static void Error(const std::string& format, TArgs...args)
  {
    Print("ERROR", format, args...);
  }

  template<typename... TArgs>
  static void Print(const std::string& prefix, const std::string& format, TArgs...args)
  {
    printf("[%s]: ", prefix.c_str());
    printf(format.c_str(), args...);
    printf("\n");
  }
};
