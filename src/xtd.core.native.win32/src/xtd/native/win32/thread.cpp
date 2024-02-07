#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/thread>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <Windows.h>
#undef max
#undef min

using namespace xtd::native;

#if !defined(_MSC_VER)
#define __try
#define __except if
#endif

namespace {
  // https://msdn.microsoft.com/en-us/library/xcb2z8hs.aspx
  void SetThreadName(DWORD dwThreadID, const char* threadName) {
#pragma pack(push, 8)
    struct THREADNAME_INFO {
      DWORD dwType;
      LPCSTR szName;
      DWORD dwThreadID;
      DWORD dwFlags;
    };
#pragma pack(pop)
    
#pragma warning(push)
#pragma warning(disable: 6320 6322)
    __try {
      THREADNAME_INFO info {0x1000, threadName, dwThreadID, 0};
      RaiseException(0x406D1388, 0, sizeof(info) / sizeof(ULONG_PTR), (ULONG_PTR*)&info);
    } __except (EXCEPTION_EXECUTE_HANDLER) {
    }
#pragma warning(pop)
  }
}

bool thread::cancel(intmax_t handle) {
  if (reinterpret_cast<HANDLE>(handle) == INVALID_HANDLE_VALUE) return false;
  return TerminateThread(reinterpret_cast<HANDLE>(handle), static_cast<DWORD>(- 1)) != FALSE;
}

intmax_t thread::create(std::function<void(intmax_t)> start, intmax_t obj, int_least32_t max_stack_size, bool suspended, intmax_t& id) {
  auto sa = SECURITY_ATTRIBUTES {};
  sa.bInheritHandle = TRUE;
  sa.lpSecurityDescriptor = nullptr;
  sa.nLength = sizeof(SECURITY_ATTRIBUTES);
  auto flags = DWORD {};
  if (suspended) flags |= CREATE_SUSPENDED;
  auto thread_id = DWORD {};
  auto thread = CreateThread(nullptr, max_stack_size, [](void* thread_arg)->DWORD {
    auto start_obj = reinterpret_cast<std::pair<std::function<int_least32_t(intmax_t)>, intmax_t>*>(thread_arg);
    start_obj->first(start_obj->second);
    delete start_obj;
    return 0;
  }, reinterpret_cast<void*>(new std::pair<std::function<void(intmax_t)>, intmax_t>{ start, obj }), flags/* | STACK_SIZE_PARAM_IS_A_RESERVATION*/, &thread_id);
  id = static_cast<intmax_t>(thread_id);
  return reinterpret_cast<intmax_t>(thread);
}

bool thread::detach(intmax_t handle) {
  if (reinterpret_cast<HANDLE>(handle) == INVALID_HANDLE_VALUE) return false;
  return CloseHandle(reinterpret_cast<HANDLE>(handle)) == TRUE;
}

intmax_t thread::get_current_thread_handle() {
  return reinterpret_cast<intmax_t>(GetCurrentThread());
}

intmax_t thread::get_thread_id(intmax_t handle) {
  if (reinterpret_cast<HANDLE>(handle) == INVALID_HANDLE_VALUE) return reinterpret_cast<intmax_t>(INVALID_HANDLE_VALUE);
  return static_cast<intmax_t>(GetThreadId(reinterpret_cast<HANDLE>(handle)));
}

bool thread::join(intmax_t handle) {
  if (reinterpret_cast<HANDLE>(handle) == INVALID_HANDLE_VALUE) return false;
  return WaitForSingleObject(reinterpret_cast<HANDLE>(handle), INFINITE) == 0;
}

bool thread::resume(intmax_t handle) {
  if (reinterpret_cast<HANDLE>(handle) == INVALID_HANDLE_VALUE) return false;
  return ResumeThread(reinterpret_cast<HANDLE>(handle)) != static_cast<DWORD>(-1);
}

bool thread::set_current_thread_name(const std::string& name) {
  SetThreadName(GetCurrentThreadId(), name.c_str());
  return true;
}

bool thread::set_priority(intmax_t handle, int_least32_t priority) {
  if (reinterpret_cast<HANDLE>(handle) == INVALID_HANDLE_VALUE) return false;
  return SetThreadPriority((HANDLE)handle, priority - 2) != FALSE;
}

void thread::sleep(int_least32_t milliseconds_timeout) {
  Sleep(milliseconds_timeout);
}

bool thread::suspend(intmax_t handle) {
  if (reinterpret_cast<HANDLE>(handle) == INVALID_HANDLE_VALUE) return false;
  return SuspendThread(reinterpret_cast<HANDLE>(handle)) != static_cast<DWORD>(-1);
}

bool thread::yield() {
  Sleep(0);
  return true;
}
