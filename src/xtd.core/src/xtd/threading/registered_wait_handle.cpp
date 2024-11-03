#include "../../../include/xtd/threading/registered_wait_handle.h"
#include "../../../include/xtd/threading/thread_pool.h"

using namespace xtd;
using namespace xtd::threading;

bool registered_wait_handle::unregister() {
  if (item_ == 0) return false;
  
  auto item = reinterpret_cast<thread_pool::thread_pool_asynchronous_io_item*>(item_);
  item->data->unregistered = true;
  return item->data->wait_object->signal();
}

bool registered_wait_handle::unregister(wait_handle& wait_object) {
  if (item_ == 0) return false;
  
  auto item = reinterpret_cast<thread_pool::thread_pool_asynchronous_io_item*>(item_);
  item->data->unregistered = true;
  return wait_object.signal();
}
