#ifdef _WIN32_WCE

#include "ProcessInformation.h"
#pragma warning(push)
#pragma warning(disable:4201)

#include <Windows.h>
#include <Tlhelp32.h>
#include <Psapi.h>
#include <Pkfuncs.h>
#include <WINERROR.H>

#pragma warning(pop)

using namespace std;

namespace stacktrace {
  static std::string ToString(const wchar_t* str) {
    char* newStr = new char[2*wcslen(str)+1];
    WideCharToMultiByte(CP_ACP, 0, str, -1, newStr, 2*wcslen(str)+1, 0, NULL);
    std::string output(newStr);
    delete[] newStr;
    return output;
  }

  ProcessInformation ProcessInformation::GetProcessInformation() { 
    return ProcessInformation(GetProcessName(), GetProcessId(), /*GetProcessVersion(),*/ GetProcessBaseAddress(), GetProcessStackFrames()); 
  }

  std::string ProcessInformation::GetProcessName() {
    wchar_t fileName[2048];
    GetModuleFileNameW(0, fileName, 2048);
    return stacktrace::ToString(fileName);
  }

  std::string ProcessInformation::GetFileName(std::string file) {
    int ind = file.find_last_of('\\');
    if (ind == 0)
      return file;
    return file.substr(ind+1,file.size()-ind);
  }

  int ProcessInformation::GetProcessBaseAddress() {
    ModuleInformations moduleInformations = ModuleInformation::GetModuleInformations();
    ModuleInformations::iterator it;
    for (it = moduleInformations.begin(); it != moduleInformations.end(); ++it)
      if (it->GetName() == GetFileName(GetProcessName()))
        return it->GetBaseAddress();

    return 0;
  }

  StackFrames ProcessInformation::GetProcessStackFrames() {
    std::list< StackFrame > stackFrames;
    const int callSnapshotExsLength = 256;
    CallSnapshotEx callSnapshots[256];
    int count = 0;
    int skipFrame = 0;

    do {
      count = GetThreadCallStack((HANDLE)GetCurrentThreadId(), callSnapshotExsLength, callSnapshots, STACKSNAP_EXTENDED_INFO, skipFrame);
      for (int i = 0; i < count; i++){
        vector<int> params(4);
        for (int j = 0; j < 4; j++)
          params[j] = (int)callSnapshots[i].dwParams[j];
        stackFrames.push_back(StackFrame(callSnapshots[i].dwReturnAddr, callSnapshots[i].dwFramePtr,params,GetProcessBaseAddress()));
      }
      skipFrame += count;
    } while (count == callSnapshotExsLength);

    return stackFrames;
  }

  int ProcessInformation::GetProcessId() {
     return GetCurrentProcessId();
  }
}

#endif
