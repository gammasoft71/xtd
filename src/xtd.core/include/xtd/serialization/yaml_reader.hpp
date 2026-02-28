/// @file
/// @brief Contains xtd::serialization::yaml_reader class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "yaml.hpp"
#include "../io/stream_reader.hpp"
#include "../argument_exception.hpp"
#include "../format_exception.hpp"
#include "../object.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Contains classes that can be used for serializing and deserializing objects. Serialization is the process of converting an object or a graph of objects into a linear sequence of bytes for either storage or transmission to another location. Deserialization is the process of taking in stored information and recreating objects from it.
  namespace serialization {
    /// @brief 
    class yaml_reader : public object {
    public:
      /// @name Public Constructors
      
      /// @{
      explicit yaml_reader(std::istream& stream);
      explicit yaml_reader(xtd::io::text_reader& text_reader);
      explicit yaml_reader(const xtd::string& text);
      /// @}
      
      /// @name Public Properties
      
      /// @{
      auto yaml() const noexcept -> const xtd::serialization::yaml&;
      /// @}
      
    private:
      auto parse_text(const xtd::string& text) -> void;
      
      xtd::serialization::yaml yaml_;
    };
  }
}
