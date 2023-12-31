/// @file
/// @brief Contains xtd::web::css::property class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../../object.h"
#include "../../ustring.h"
#include <ostream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  namespace web {
    namespace css {
      class property : public object {
      public:
        /// @name Constructors
        
        /// @{
        property() = default;
        explicit property(const xtd::ustring& value) : value_(value) {}
        /// @}
        
        /// @name Operators
        
        /// @{
        operator xtd::ustring() noexcept {return value_;}
        /// @}
        
        /// @name Properties
        
        /// @{
        const xtd::ustring& value() const noexcept {return value_;}
        template<typename value_t>
        uintptr value() const noexcept {return xtd::parse<value_t>(value_);}
        /// @}
        
        /// @name Methods
        
        /// @{
        static property from(bool value) {return property(ustring::format("{}", value));}
        static property from(double value) {return property(ustring::format("{}", value));}
        static property from(float value) {return property(ustring::format("{}", value));}
        static property from(sbyte value) {return property(ustring::format("{}", value));}
        static property from(int16 value) {return property(ustring::format("{}", value));}
        static property from(int32 value) {return property(ustring::format("{}", value));}
        static property from(int64 value) {return property(ustring::format("{}", value));}
        static property from(const xtd::ustring& value) {return property(ustring::format("{}", value));}
        static property from(xtd::byte value) {return property(ustring::format("{}", value));}
        static property from(uint16 value) {return property(ustring::format("{}", value));}
        static property from(uint32 value) {return property(ustring::format("{}", value));}
        static property from(uint64 value) {return property(ustring::format("{}", value));}
        template<typename value_t>
        static property from(value_t value) {return property(ustring::format("{}", value));}
        
        bool to_boolean() const {return xtd::parse<bool>(value_);}
        double to_double() const {return xtd::parse<double>(value_);}
        sbyte to_int8() const {return xtd::parse<sbyte>(value_);}
        int16 to_int16() const {return xtd::parse<int16>(value_);}
        int32 to_int32() const {return xtd::parse<int32>(value_);}
        int64 to_int64() const {return xtd::parse<int64>(value_);}
        intptr to_intptr() const {return xtd::parse<intptr>(value_);}
        float to_single() const {return xtd::parse<float>(value_);}
        xtd::ustring to_string() const noexcept override {return value_;}
        xtd::byte to_uint8() const {return xtd::parse<xtd::byte>(value_);}
        uint16 to_uint16() const {return xtd::parse<uint16>(value_);}
        uint32 to_uint32() const {return xtd::parse<uint32>(value_);}
        uint64 to_uint64() const {return xtd::parse<uint64>(value_);}
        uintptr to_uintptr() const {return xtd::parse<uintptr>(value_);}
        template<typename value_t>
        uintptr to() const {return xtd::parse<value_t>(value_);}
        /// @}
        
      private:
        xtd::ustring value_;
      };
    }
  }
}
