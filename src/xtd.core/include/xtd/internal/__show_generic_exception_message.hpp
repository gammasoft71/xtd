/// @file
/// @brief Contains __show_generic_exception_message__ methods.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "../exception.hpp"
#include "../target_id_definitions.hpp"
#include "../string.hpp"
#if __XTD_CURRENT_TARGET_ID__ == __XTD_TARGET_ID_GUI_APPLICATION__ || __XTD_CURRENT_TARGET_ID__ == __XTD_TARGET_ID_UNKNOWN__
#include "xtd/forms/application.hpp"
#include "xtd/forms/exception_box.hpp"
#endif
#include <iostream>

/// @cond
#if __XTD_CURRENT_TARGET_ID__ == __XTD_TARGET_ID_GUI_APPLICATION__ || __XTD_CURRENT_TARGET_ID__ == __XTD_TARGET_ID_UNKNOWN__
inline void __show_generic_exception_message__(const std::exception& e) {xtd::forms::application::main_form().has_value() ? xtd::forms::exception_box::show(xtd::forms::application::main_form().value().get(), e, xtd::forms::application::product_name()) : xtd::forms::exception_box::show(e, xtd::forms::application::product_name());}
inline void __show_generic_exception_message__() {xtd::forms::application::main_form().has_value() ? xtd::forms::exception_box::show(xtd::forms::application::main_form().value().get(), xtd::forms::application::product_name()) : xtd::forms::exception_box::show(xtd::forms::application::product_name());}
#else
inline void __show_generic_exception_message__(const std::exception& e) {std::cerr << std::endl << xtd::string::format("Unhandled exception: {}", dynamic_cast<const xtd::exception*>(&e) ? static_cast<const xtd::exception&>(e).to_string() : e.what()) << std::endl;}
inline void __show_generic_exception_message__() { std::cerr << std::endl << xtd::string::format("Unhandled exception: Unknown exception occurred") << std::endl;}
#endif
/// @endcond
