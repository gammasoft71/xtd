#ifdef _WIN32_WCE

#pragma warning(push)
#pragma warning(disable:4201)

#include "ModuleInformation.h"
#include <Tlhelp32.h>
#include <Psapi.h>
//#include <Pkfuncs.h>
#include <WINERROR.H>
#include <sstream>
#include <Windows.h>
#include <pkfuncs.h>

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

  ModuleInformations ModuleInformation::GetModuleInformations() {
    intptr_t snapshot = (intptr_t)CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS | TH32CS_SNAPMODULE | TH32CS_GETALLMODS, 0);

    list<ModuleInformation> moduleInformations;

    if ((HANDLE)snapshot == INVALID_HANDLE_VALUE) return moduleInformations;

    MODULEENTRY32 moduleInfo;
    moduleInfo.dwSize = sizeof(moduleInfo);
    if (Module32First((HANDLE)snapshot, &moduleInfo)) do {
      moduleInformations.push_back(ModuleInformation((intptr_t)moduleInfo.hModule, stacktrace::ToString(moduleInfo.szModule), (int)moduleInfo.modBaseAddr, moduleInfo.modBaseSize));
    } while (Module32Next((HANDLE)snapshot, &moduleInfo));

    PROCESSENTRY32 processInfo;
    processInfo.dwSize = sizeof(processInfo);
    PROCVMINFO processMemoryInfo;
    if (Process32First((HANDLE)snapshot, &processInfo)) do {
      int mem = 0;
      HANDLE hProcess = OpenProcess( PROCESS_ALL_ACCESS, FALSE, processInfo.th32ProcessID );
      if (CeGetProcVMInfo(GetProcessIndexFromID(hProcess),sizeof(processMemoryInfo),&processMemoryInfo))
        mem = processMemoryInfo.cbRwMemUsed;

      moduleInformations.push_back(ModuleInformation(NULL, stacktrace::ToString(processInfo.szExeFile), (int)processInfo.th32MemoryBase, mem));
    } while (Process32Next((HANDLE)snapshot, &processInfo));

    CloseToolhelp32Snapshot((HANDLE)snapshot);
    return moduleInformations;
  }

  ModuleInformations ModuleInformation::GetProcessInformations() {
    intptr_t snapshot = (intptr_t)CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS | TH32CS_SNAPMODULE | TH32CS_GETALLMODS | TH32CS_SNAPHEAPLIST, 0);

    list<ModuleInformation> moduleInformations;

    if ((HANDLE)snapshot == INVALID_HANDLE_VALUE) return moduleInformations;

    PROCESSENTRY32 processInfo;
    processInfo.dwSize = sizeof(processInfo);
    PROCVMINFO processMemoryInfo;
    if (Process32First((HANDLE)snapshot, &processInfo)) do {
      int mem = 0;
      HANDLE hProcess = OpenProcess( PROCESS_ALL_ACCESS, FALSE, processInfo.th32ProcessID );
      if (CeGetProcVMInfo(GetProcessIndexFromID(hProcess),sizeof(processMemoryInfo),&processMemoryInfo))
        mem = processMemoryInfo.cbRwMemUsed;

      moduleInformations.push_back(ModuleInformation(NULL, stacktrace::ToString(processInfo.szExeFile), (int)processInfo.th32MemoryBase, mem));
    } while (Process32Next((HANDLE)snapshot, &processInfo));

    CloseToolhelp32Snapshot((HANDLE)snapshot);
    return moduleInformations;
  }

  string ModuleInformation::ToString() const {
    stringstream ss;
    ss << "Name= "+this->name+", BaseAdress=0x";
    ss << std::hex << this->baseAddress << "Size=0x" << this->size;
    return ss.str();
  }
}

#endif
