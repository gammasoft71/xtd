#ifdef _WIN32_WCE

#pragma once;

#include <string>
#include "ModuleInformation.h"
#include "StackFrame.h"

namespace stacktrace {
  /**
  * A struct that computes and represents process informations in WinCE.
  */
  struct ProcessInformation {
  public:
    /**
    * Return information for every process.
    *
    * @return ProcessInformation The process informations.
    */
    static ProcessInformation GetProcessInformation();

    const std::string& GetName() const { return name; }
    int GetId() const { return id; }
    //const Version& GetVersion() const { return version; }
    int GetBaseAddress() const { return baseAddress; }
    const StackFrames& GetStackFrames() const { return stackFrames; }
    static std::string GetFileName(std::string file);

  private:
    ProcessInformation(const std::string& name, int id, /*const Version& version, */int baseAddress, const StackFrames& stackFrames) : name(name), id(id), /*version(version),*/ baseAddress(baseAddress), stackFrames(stackFrames) {}
    static std::string GetProcessName();
    static int GetProcessId();

    //static Version GetProcessVersion() {
    //  int32 version = ::GetProcessVersion(GetCurrentProcessId());
    //  return Version((version&0xFFFF0000)>>16, version&0x0000FFFF);
    //}

    static int GetProcessBaseAddress();
    static StackFrames GetProcessStackFrames();

    std::string name;
    int id;
    //Version version;
    int baseAddress;
    StackFrames stackFrames;
  };
}

#endif
