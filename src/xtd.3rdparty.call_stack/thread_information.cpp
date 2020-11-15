#ifdef _WIN32_WCE

#pragma warning(push)
#pragma warning(disable:4201)

#include <Windows.h>
#include <Tlhelp32.h>
#include <Psapi.h>
//#include <Pkfuncs.h>
#include <WINERROR.H>

#pragma warning(pop)
#include "ThreadInformation.h"

namespace stacktrace {
  ThreadInformation ThreadInformation::GetThreadInformation() { 
    return ThreadInformation(GetCurrentThreadId()); 
  }
}

#endif