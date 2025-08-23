#include "../../../include/xtd/threading/lock.hpp"
#include "../../../include/xtd/threading/mutex.hpp"
#include "../../../include/xtd/collections/generic/dictionary.hpp"

using namespace xtd;
using namespace xtd::threading;

struct lock::data {
  string str;
  intptr ptr = 0;
  int32 used_count = 0;
  threading::mutex mutex;
  inline static auto mutexes_access = threading::mutex {};
  inline static auto mutexes = xtd::collections::generic::dictionary<intptr, xtd::ptr<lock::data>> {};
  inline static auto named_mutexes = xtd::collections::generic::dictionary<string, xtd::ptr<lock::data>> {};
};

lock::lock(const xtd::string& str) : data_ {new_ptr<lock::data>()} {
  data_->str = str;
  enter();
}

lock::lock(xtd::intptr ptr) : data_ {new_ptr<lock::data>()} {
  data_->ptr = ptr;
  enter();
}

lock::lock(const std::string& str) : lock {xtd::string {str}} {
}

lock::lock(const char* str) : lock {xtd::string {str}} {
}

lock::lock(const xtd::char16* str) : lock {xtd::string {str}} {
}

lock::lock(const xtd::char32* str) : lock {xtd::string {str}} {
}

lock::lock(const xtd::char8* str) : lock {xtd::string {str}} {
}

lock::lock(const xtd::wchar* str) : lock {xtd::string {str}} {
}

lock::~lock() {
  exit();
}

void lock::enter() {
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
  
  data_->mutex.wait_one();
}

void lock::exit() {
  data::mutexes_access.wait_one();
  if (data_->used_count) --data_->used_count;
  if (data_->ptr && !data_->used_count && data::mutexes.contains(data_->ptr)) data::mutexes.remove(data_->ptr);
  else if (!data_->used_count && data::named_mutexes.contains(data_->str)) data::named_mutexes.remove(data_->str);
  data::mutexes_access.release_mutex();
  
  data_->mutex.release_mutex();
}
