/// @file
/// @brief Contains __show_generic_exception_message__ methods.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#if __XTD_CURRENT_TARGET_ID__ == __XTD_TARGET_ID_GUI_APPLICATION__
#include "xtd/forms/application.h"
#include "xtd/forms/exception_box.h"
#endif
#include "../system_exception.h"
#include "../ustring.h"
#include <iostream>

/// @cond
#if __XTD_CURRENT_TARGET_ID__ == __XTD_TARGET_ID_GUI_APPLICATION__
inline void __show_generic_exception_message__(const std::exception& e) {xtd::forms::application::open_forms().size() > 0 ? xtd::forms::exception_box::show(xtd::forms::application::open_forms()[0].get(), e, xtd::forms::application::product_name()) : xtd::forms::exception_box::show(e, xtd::forms::application::product_name());}
inline void __show_generic_exception_message__() {xtd::forms::application::open_forms().size() > 0 ? xtd::forms::exception_box::show(xtd::forms::application::open_forms()[0].get(), xtd::forms::application::product_name()) : xtd::forms::exception_box::show(xtd::forms::application::product_name());}
#else
inline void __show_generic_exception_message__(const std::exception& e) {std::cerr << std::endl << xtd::ustring::format("Unhandled exception: {}", dynamic_cast<const xtd::system_exception*>(&e) ? static_cast<const xtd::system_exception&>(e).to_string() : e.what()) << std::endl;}
inline void __show_generic_exception_message__() { std::cerr << std::endl << xtd::ustring::format("Unhandled exception: Unknown exception occurred") << std::endl;}
#endif
/// @endcond
