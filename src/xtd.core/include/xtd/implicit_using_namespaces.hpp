/// @file
/// @brief Contains implicit using namespaces.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "target_id_definitions.hpp"

/// @cond
/// These implicit using directives are enabled by default to simplify code.
/// To disable them, set -DXTD_ENABLE_IMPLICIT_NAMESPACES=OFF when configuring xtd.

#if defined(__XTD_ENABLE_IMPLICIT_USING_NAMESPACES__)
#define __using_namespace__(name_space) \
  namespace name_space {} \
  using namespace name_space

#if __XTD_CURRENT_TARGET_ID__ == __XTD_TARGET_ID_TEST_APPLICATION__ || __XTD_CURRENT_TARGET_ID__ == __XTD_TARGET_ID_CONSOLE_APPLICATION__ || __XTD_CURRENT_TARGET_ID__ == __XTD_TARGET_ID_GUI_APPLICATION__ || __XTD_CURRENT_TARGET_ID__ == __XTD_TARGET_ID_UNKNOWN__
__using_namespace__(xtd);
__using_namespace__(xtd::collections::generic);
__using_namespace__(xtd::io);
__using_namespace__(xtd::linq);
__using_namespace__(xtd::net::http);
__using_namespace__(xtd::ranges::views);
__using_namespace__(xtd::threading);
__using_namespace__(xtd::threading::tasks);
#endif

#if __XTD_CURRENT_TARGET_ID__ == __XTD_TARGET_ID_TEST_APPLICATION__ || __XTD_CURRENT_TARGET_ID__ == __XTD_TARGET_ID_GUI_APPLICATION__ || __XTD_CURRENT_TARGET_ID__ == __XTD_TARGET_ID_UNKNOWN__
__using_namespace__(xtd::drawing);
__using_namespace__(xtd::forms);
#endif

#if __XTD_CURRENT_TARGET_ID__ == __XTD_TARGET_ID_TEST_APPLICATION__
__using_namespace__(xtd::tunit);
__using_namespace__(xtd::tunit::constraints);
#endif

#undef __using_namespace__
#endif
/// @endcond
