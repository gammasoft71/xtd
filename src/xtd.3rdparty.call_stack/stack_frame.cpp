#ifdef _WIN32_WCE

#include "StackFrame.h"
#include <sstream>

using namespace std;

namespace stacktrace {
  int StackFrame::GetAbsoluteReturnAddress() const {
    if (this->returnAddress >= this->baseAddress && this->returnAddress <= this->baseAddress+0x08000000)
      return this->returnAddress - this->baseAddress;
    return this->returnAddress;
  }

  string StackFrame::ToString() const { 
    stringstream ss;
    ss << "ReturnAddress=0x" << hex << this->GetReturnAddress() << ", FramePointer=0x" << this->GetFramePointer();
    ss << ", Params = 0x" << this->params[0] << ",0x" << this->params[1] << ",0x" << this->params[2] << ",0x" << this->params[3];
    return ss.str();
  }
}

#endif