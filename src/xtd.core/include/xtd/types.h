/// @file
/// @brief Contains xtd fundamental types.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "core_namespace_aliases.h"
#include "self.h"
#include "bool.h"
#include "byte.h"
#include "char.h"
#include "char16.h"
#include "char32.h"
#include "char8.h"
#include "decimal.h"
#include "double.h"
#include "int16.h"
#include "int32.h"
#include "int64.h"
#include "intptr.h"
#include "null.h"
#include "ptrdiff.h"
#include "sbyte.h"
#include "single.h"
#include "size.h"
#include "slong.h"
#include "type.h"
#include "uint16.h"
#include "uint32.h"
#include "uint64.h"
#include "uintptr.h"
#include "ulong.h"
#include "wchar.h"

#include <memory>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {  
  /// @brief The xtd::sptr object is a shared pointer.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @par Examples
  /// This example shows to use xtd::sptr with xtd::version class
  /// @code
  /// sptr<xtd::version> version = new_sptr<xtd::version>(1, 2, 3);
  ///
  /// console::write_line("version = {}", version->to_string());
  /// delete_ptr(version); // Not mandatory.
  /// @endcode
  template<typename type_t>
  using sptr = std::shared_ptr<type_t>;
  
  /// @brief The xtd::uptr object is a unique pointer.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @par Examples
  /// This example shows to use xtd::uptr with xtd::version class
  /// @code
  /// uptr<xtd::version> version = newu_uptr<xtd::version>(1, 2, 3);
  ///
  /// console::write_line("version = {}", version->to_string());
  /// delete_ptr(version); // Not mandatory.
  /// @endcode
  template<typename type_t>
  using uptr = std::unique_ptr<type_t>;
  
  /// @brief The xtd::ptr object is a shared pointer.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @par Examples
  /// this is example shows to use xtd::new_ with xtd::version class
  /// @code
  /// ptr<xtd::version> version = new_ptr<xtd::version>(1, 2, 3);
  ///
  /// console::write_line("version = {}", version->to_string());
  /// delete_ptr(version); // Not mandatory.
  /// @endcode
  template<typename type_t>
  using ptr = sptr<type_t>;
  
  /// @brief The xtd::new_ptr operator creates a xtd::ptr object.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// this is example shows to use xtd::new_ptr with xtd::version class
  /// @code
  /// ptr<xtd::version> version = new_ptr<xtd::version>(1, 2, 3);
  ///
  /// console::write_line("version = {}", version->to_string());
  /// delete_ptr(version); // Not mandatory.
  /// @endcode
  /// @remarks The xtd::new_ptr is equivalent to [std::make_shared](https://en.cppreference.com/w/cpp/memory/shared_ptr/make_shared).
  template<typename type_t, typename ...args_t>
  ptr<type_t> new_ptr(args_t&& ... args) {return ptr<type_t> {new type_t(args...)};}
  
  /// @cond
  template<typename type_t>
  ptr<type_t> new_ptr(const type_t& arg) {return ptr<type_t> {new type_t(arg)};}
  
  template<typename type_t>
  ptr<type_t> new_ptr() {return ptr<type_t>(new type_t {});}
  /// @endcond
  
  /// @brief xtd::news_sptr operator creates a xtd::sptr object.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// this is example shows to use xtd::new_sptr with xtd::version class
  /// @code
  /// sptr<xtd::version> version = new_sptr<xtd::version>(1, 2, 3);
  ///
  /// console::write_line("version = {}", version->to_string());
  /// delete_ptr(version); // Not mandatory.
  /// @endcode
  /// @remarks The xtd::new_sptr is equivalent to [std::make_shared](https://en.cppreference.com/w/cpp/memory/shared_ptr/make_shared).
  template<typename type_t, typename ...args_t>
  sptr<type_t> new_sptr(args_t&& ... args) {return sptr<type_t> {new type_t(args...)};}
  
  /// @cond
  template<typename type_t>
  sptr<type_t> new_sptr(const type_t& arg) {return sptr<type_t> {new type_t(arg)};}
  
  template<typename type_t>
  sptr<type_t> new_sptr() {return sptr<type_t>(new type_t {});}
  /// @endcond
  
  /// @brief xtd::new_uptr operator. This operator creates a xtd::uptr object.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// this is example shows to use xtd::new_uptr with xtd::version class
  /// @code
  /// uptr<xtd::version> version = new_uptr<xtd::version>(1, 2, 3);
  ///
  /// console::write_line("version = {}", version->to_string());
  /// delete_(version); // Not mandatory.
  /// @endcode
  /// @remarks The xtd::new_uptr is equivalent to [std::make_unique](https://en.cppreference.com/w/cpp/memory/unique_ptr/make_unique).
  template<typename type_t, typename ...args_t>
  uptr<type_t> new_uptr(args_t&& ... args) {return uptr<type_t> {new type_t(args...)};}
  
  /// @cond
  template<typename type_t>
  uptr<type_t> new_uptr(const type_t& arg) {return uptr<type_t> {new type_t(arg)};}
  
  template<typename type_t>
  uptr<type_t> new_uptr() {return uptr<type_t>(new type_t {});}
  /// @endcond
  
  /// @brief xtd::delete_ptr operator delete a xtd::sptr or xtd::ptr object.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// this is example shows to use xtd::delete_ptr with xtd::version class
  /// @code
  /// ptr<xtd::version> version = new_ptr<xtd::version>(1, 2, 3);
  ///
  /// console::write_line("version = {}", version->to_string());
  /// delete_ptr(version); // Not mandatory.
  /// @endcode
  /// @remarks This operator does not have to be called because when an xtd::sptr object leaves the scope, its value is automatically reset.
  /// @remarks Use it when you want to reset the xtd::sptr object at a specific time.
  template<typename type_t>
  void delete_ptr(sptr<type_t>& ptr) {ptr = null;}
  
  /// @brief xtd::delete_ptr operator delete a xtd::uptr object.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// this is example shows to use xtd::delete_ptr with xtd::version class
  /// @code
  /// uptr<xtd::version> version = new_uptr<xtd::version>(1, 2, 3);
  ///
  /// console::write_line("version = {}", version->to_string());
  /// delete_ptr(version); // Not mandatory.
  /// @endcode
  /// @remarks This operator does not have to be called because when an xtd::uptr object leaves the scope, its value is automatically reset.
  /// @remarks Use it when you want to reset the xtd::ptr object at a specific time.
  template<typename type_t>
  void delete_ptr(uptr<type_t>& ptr) {ptr = null;}
}
