#ifdef _WIN32_WCE

#include "StackFrame.h"
#include <sstream>

using namespace std;

namespace stacktrace {
  int StackFrame::GetAbsoluteReturnAddress() const {
    if (returnAddress >= baseAddress && returnAddress <= baseAddress+0x08000000)
      return returnAddress - baseAddress;
    return returnAddress;
  }

  string StackFrame::ToString() const { 
    stringstream ss;
    ss << "ReturnAddress=0x" << hex << GetReturnAddress() << ", FramePointer=0x" << GetFramePointer();
    ss << ", Params = 0x" << params[0] << ",0x" << params[1] << ",0x" << params[2] << ",0x" << params[3];
    return ss.str();
  }
}

#endif
