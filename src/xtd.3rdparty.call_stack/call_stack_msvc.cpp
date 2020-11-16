/* Copyright (c) 2009, Fredrik Orderud
 License: BSD licence (http://www.opensource.org/licenses/bsd-license.php) */

/* Windows (Microsoft visual studio) implementation of the call_stack class. */
#ifdef _WIN32 // also defined in 64bit

#if defined(_WIN32_WCE)

#include "call_stack.hpp"
#include "ProcessInformation.h"
#include "ThreadInformation.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

namespace stacktrace {
  call_stack::call_stack (const size_t /*num_discard*/) {
    ProcessInformation processInformation = ProcessInformation::GetProcessInformation();

    StackFrames::const_iterator it;
    for (it = processInformation.GetStackFrames().begin(); it != processInformation.GetStackFrames().end(); ++it) {
      stacktrace::entry e;
      e.file = "";
      e.line = 0;
      stringstream ss;
      ss << "0x";
      ss << std::hex;
      ss << std::setw(8);
      ss << std::setfill('0');
      ss << it->GetAbsoluteReturnAddress();
      e.function = ss.str();
      e.offset = it->GetFramePointer();
      e.column = 0;
      stack.push_back(e);
    }
  }
  
  call_stack::~call_stack () throw() {
    // automatic cleanup
  }
} // namespace stacktrace


#else

#include "call_stack.h"
#include "stack_walker.h"

/** Adapter class to interfaces with the StackWalker project.
 *  Source: http://stackwalker.codeplex.com/ */
class StackWalkerAdapter : public StackWalker {
public:
  explicit StackWalkerAdapter (const size_t num_discard) :
  StackWalker(StackWalker::RetrieveVerbose | StackWalker::SymBuildPath), // do not use public Microsoft-Symbol-Server
  discard_idx(static_cast<int>(num_discard)+2) {}
  virtual ~StackWalkerAdapter () {}
  
protected:
  virtual void OnCallstackEntry (CallstackEntryType /*eType*/, CallstackEntry &entry) {
    if (entry.lineFileName[0] == 0)
      discard_idx = -1; // skip all entries from now on
    
    // discard first N stack entries
    if (discard_idx > 0) {
      discard_idx--;
    } else if (discard_idx == 0) {
      stacktrace::entry e;
      e.file = entry.lineFileName;
      e.line = entry.lineNumber;
      e.function = entry.name;
      e.offset = static_cast<size_t>(entry.offsetFromSmybol);
      e.column = entry.offsetFromLine;
      stack.push_back(e);
    }
  }
  virtual void OnOutput (LPCSTR /*szText*/) {
    // discard (should never be called)
  }
  virtual void OnSymInit (LPCSTR /*szSearchPath*/, DWORD /*symOptions*/, LPCSTR /*szUserName*/) {
    // discard
  }
  virtual void OnLoadModule (LPCSTR /*img*/, LPCSTR /*mod*/, DWORD64 /*baseAddr*/, DWORD /*size*/, DWORD /*result*/, LPCSTR /*symType*/, LPCSTR /*pdbName*/, ULONGLONG /*fileVersion*/) {
    // discard
  }
  virtual void OnDbgHelpErr (LPCSTR /*szFuncName*/, DWORD /*gle*/, DWORD64 /*addr*/) {
    // discard
  }
  
public:
  std::vector<stacktrace::entry> stack;       ///< populated stack trace
private:
  int discard_idx; ///< the number of stack entries to discard
};


namespace stacktrace {
  // windows 32 & 64 bit impl.
  call_stack::call_stack (const size_t num_discard /*= 0*/) {
    StackWalkerAdapter sw(num_discard);
    sw.ShowCallstack();
    stack = sw.stack;
  }
  
  call_stack::~call_stack () throw() {
    // automatic cleanup
  }

  /*
  std::string to_string () const {
    std::ostringstream os;
    for (size_t i = 0; i < stack.size(); i++)
      os << stack[i].to_string() << std::endl;
    return os.str();
  }
  */
  
} // namespace stacktrace

#endif // _WIN32_WCE

#endif // _WIN32
