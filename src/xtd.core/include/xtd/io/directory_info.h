/// @file
/// @brief Contains xtd::io::directory_info class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include "file_system_info.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @brief Exposes instance methods for creating, moving, and enumerating through directories and subdirectories. This class cannot be inherited.
    /// @par Namespace
    /// xtd::io
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core io
    class core_export_ directory_info : public xtd::io::file_system_info {
    public:
      directory_info(const xtd::ustring& path);
      
      xtd::ustring name() const override;
      
      bool exists() const override;
      
      void remove() override;
    };
  }
}
