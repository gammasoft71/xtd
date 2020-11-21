#ifdef _WIN32_WCE

#pragma once;

#include <string>
#include <stddef.h>
#include <vector>
#include <list>

namespace stacktrace {
  /**
  * A struct representing a stack frame defined by a return address, a frame pointer, a base address and a list of parameters.
  */
  struct StackFrame {
  public:
    StackFrame() :returnAddress(0), framePointer(0), baseAddress(0) {}
    StackFrame(int returnAddress, int framePointer, const std::vector<int>& params, int baseAddress) : returnAddress(returnAddress), framePointer(framePointer), params(params), baseAddress(baseAddress) {}

    int GetAbsoluteReturnAddress() const;
    int GetReturnAddress() const { return returnAddress; }
    int GetFramePointer() const { return framePointer; }
    const std::vector< int >& GetParams() const { return params; }
    virtual bool Equals(const StackFrame& sf) const { return &sf != NULL && returnAddress == sf.returnAddress && framePointer == sf.framePointer && params  == sf.params && baseAddress == sf.baseAddress; }
    virtual std::string ToString() const;

  private:
    int returnAddress;
    int framePointer;
    std::vector<int> params;
    int baseAddress;
  };

  typedef std::list<StackFrame> StackFrames;
}

#endif
