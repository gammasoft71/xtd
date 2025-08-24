#include "../../../include/xtd/threading/lock_guard.hpp"
#include "../../../include/xtd/threading/mutex.hpp"
#include "../../../include/xtd/collections/generic/dictionary.hpp"
#include "../../../include/xtd/helpers/throw_helper.hpp"

using namespace xtd;
using namespace xtd::helpers;
using namespace xtd::threading;

struct lock_guard::data {
  string str;
  intptr ptr = 0;
  int32 used_count = 0;
  threading::mutex mutex;
  inline static auto mutexes_access = threading::mutex {};
  inline static auto mutexes = xtd::collections::generic::dictionary<intptr, xtd::ptr<lock_guard::data>> {};
  inline static auto named_mutexes = xtd::collections::generic::dictionary<string, xtd::ptr<lock_guard::data>> {};
};

lock_guard::lock_guard(const xtd::string& str) : data_ {new_ptr<lock_guard::data>()} {
  if (str.empty()) throw_helper::throws(exception_case::argument);
  data_->str = str;
  data_->mutex = threading::mutex {str};
  enter();
}

lock_guard::lock_guard(xtd::intptr ptr) : data_ {new_ptr<lock_guard::data>()} {
  data_->ptr = ptr;
  enter();
}

lock_guard::lock_guard(const std::string& str) : lock_guard {xtd::string {str}} {
}

lock_guard::lock_guard(const char* str) : lock_guard {xtd::string {str}} {
}

lock_guard::lock_guard(const xtd::char16* str) : lock_guard {xtd::string {str}} {
}

lock_guard::lock_guard(const xtd::char32* str) : lock_guard {xtd::string {str}} {
}

lock_guard::lock_guard(const xtd::char8* str) : lock_guard {xtd::string {str}} {
}

lock_guard::lock_guard(const xtd::wchar* str) : lock_guard {xtd::string {str}} {
}

lock_guard::~lock_guard() {
  exit();
}

void lock_guard::enter() {
  data::mutexes_access.wait_one();
  if (data_->ptr) {
    if (data::mutexes.contains(data_->ptr)) data_ = data::mutexes[data_->ptr];
    else data::mutexes[data_->ptr] = data_;
  } else {
    if (data::named_mutexes.contains(data_->str)) data_ = data::named_mutexes[data_->str];
    else data::named_mutexes[data_->str] = data_;
  }
  ++data_->used_count;
  data::mutexes_access.release_mutex();
  
  try {
    data_->mutex.wait_one();
  } catch (...) {
    data::mutexes_access.wait_one();
    if (data_->used_count) --data_->used_count;
    if (data_->ptr && !data_->used_count && data::mutexes.contains(data_->ptr)) data::mutexes.remove(data_->ptr);
    else if (!data_->used_count && data::named_mutexes.contains(data_->str)) data::named_mutexes.remove(data_->str);
    data::mutexes_access.release_mutex();
    throw;
  }
}

void lock_guard::exit() {
  data_->mutex.release_mutex();
  
  data::mutexes_access.wait_one();
  if (data_->used_count) --data_->used_count;
  if (data_->ptr && !data_->used_count && data::mutexes.contains(data_->ptr)) data::mutexes.remove(data_->ptr);
  else if (!data_->used_count && data::named_mutexes.contains(data_->str)) data::named_mutexes.remove(data_->str);
  data::mutexes_access.release_mutex();
}
