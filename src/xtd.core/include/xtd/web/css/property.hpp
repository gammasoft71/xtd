/// @file
/// @brief Contains xtd::web::css::property class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../../object.hpp"
#include "../../string.hpp"
#include "../../single.hpp"
#include <ostream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  namespace web {
    namespace css {
      class property : public object {
      public:
        /// @name Public Constructors
        
        /// @{
        property() = default;
        explicit property(const xtd::string& value) : value_(value) {}
        property(const property&) = default;
        property& operator =(const property&) = default;
        property(property&&) = default;
        property& operator =(property&&) = default;
        /// @}
        
        /// @name Operators
        
        /// @{
        operator xtd::string() noexcept {return value_;}
        /// @}
        
        /// @name Public Properties
        
        /// @{
        [[nodiscard]] auto value() const noexcept -> const xtd::string& {return value_;}
        template<typename value_t>
        [[nodiscard]] auto value() const noexcept -> value_t {return xtd::parse<value_t>(value_);}
        /// @}
        
        /// @name Public Methods
        
        /// @{
        [[nodiscard]] auto to_boolean() const -> bool {return xtd::parse<bool>(value_);}
        [[nodiscard]] auto to_double() const -> double {return xtd::parse<double>(value_);}
        [[nodiscard]] auto to_int8() const -> xtd::sbyte  {return xtd::parse<xtd::sbyte>(value_);}
        [[nodiscard]] auto to_int16() const -> xtd::int16 {return xtd::parse<xtd::int16>(value_);}
        [[nodiscard]] auto to_int32() const -> xtd::int32 {return xtd::parse<xtd::int32>(value_);}
        [[nodiscard]] auto to_int64() const -> xtd::int64 {return xtd::parse<xtd::int64>(value_);}
        [[nodiscard]] auto to_intptr() const -> xtd::intptr {return xtd::parse<xtd::intptr>(value_);}
        [[nodiscard]] auto to_single() const -> xtd::single {return xtd::parse<float>(value_);}
        [[nodiscard]] auto to_string() const noexcept -> xtd::string override {return value_;}
        [[nodiscard]] auto to_uint8() const -> xtd::byte {return xtd::parse<xtd::byte>(value_);}
        [[nodiscard]] auto to_uint16() const -> xtd::uint16 {return xtd::parse<xtd::uint16>(value_);}
        [[nodiscard]] auto to_uint32() const -> xtd::uint32 {return xtd::parse<xtd::uint32>(value_);}
        [[nodiscard]] auto to_uint64() const -> xtd::uint64 {return xtd::parse<xtd::uint64>(value_);}
        [[nodiscard]] auto to_uintptr() const -> xtd::uintptr {return xtd::parse<xtd::uintptr>(value_);}
        template<typename value_t>
        [[nodiscard]] auto to() const -> value_t {return xtd::parse<value_t>(value_);}
        /// @}
        
        /// @name Public Static Methods
        
        /// @{
        static auto from(bool value) -> property {return property(string::format("{}", value));}
        static auto from(double value) -> property {return property(string::format("{}", value));}
        static auto from(xtd::single value) -> property {return property(string::format("{}", value));}
        static auto from(xtd::sbyte value) -> property {return property(string::format("{}", value));}
        static auto from(xtd::int16 value) -> property {return property(string::format("{}", value));}
        static auto from(xtd::int32 value) -> property {return property(string::format("{}", value));}
        static auto from(xtd::int64 value) -> property {return property(string::format("{}", value));}
        static auto from(const xtd::string& value) -> property {return property(string::format("{}", value));}
        static auto from(xtd::byte value) -> property {return property(string::format("{}", value));}
        static auto from(xtd::uint16 value) -> property {return property(string::format("{}", value));}
        static auto from(xtd::uint32 value) -> property {return property(string::format("{}", value));}
        static auto from(xtd::uint64 value) -> property {return property(string::format("{}", value));}
        static auto from(const auto& value) -> property {return property(string::format("{}", value));}
        /// @}
        
      private:
        xtd::string value_;
      };
    }
  }
}
