#pragma once
#include <ostream>
#include <string>
#include <xtd/strings.h>

namespace xtd {
  namespace html {
    namespace css {
      class property {
      public:
        property() = default;
        explicit property(const std::string& value) : value_(value) {}
        operator std::string() {return value_;}
        
        static property from(bool value) {
          property result;
          result.value(value);
          return result;
        }
        static property from(double value) {
          property result;
          result.value(value);
          return result;
        }
        static property from(float value) {
          property result;
          result.value(value);
          return result;
        }
        static property from(int8_t value) {
          property result;
          result.value(value);
          return result;
        }
        static property from(int16_t value) {
          property result;
          result.value(value);
          return result;
        }
        static property from(int32_t value) {
          property result;
          result.value(value);
          return result;
        }
        static property from(int64_t value) {
          property result;
          result.value(value);
          return result;
        }
        static property from(intptr_t value) {
          property result;
          result.value(value);
          return result;
        }
        static property from(const std::string& value) {
          property result;
          result.value(value);
          return result;
        }
        static property from(uint8_t value) {
          property result;
          result.value(value);
          return result;
        }
        static property from(uint16_t value) {
          property result;
          result.value(value);
          return result;
        }
        static property from(uint32_t value) {
          property result;
          result.value(value);
          return result;
        }
        static property from(uint64_t value) {
          property result;
          result.value(value);
          return result;
        }
        static property from(uintptr_t value) {
          property result;
          result.value(value);
          return result;
        }
        template<typename value_t>
        static property from(value_t value) {
          property result;
          result.value(value);
          return result;
        }
        
        const std::string& value() const {return value_;}
        void value(bool value) {value_ = format("{}", value);}
        void value(double value) {value_ = format("{}", value);}
        void value(float value) {value_ = format("{}", value);}
        void value(int8_t value) {value_ = format("{}", value);}
        void value(int16_t value) {value_ = format("{}", value);}
        void value(int32_t value) {value_ = format("{}", value);}
        void value(int64_t value) {value_ = format("{}", value);}
        void value(intptr_t value) {value_ = format("{}", value);}
        void value(const std::string& value) {value_ = value;}
        void value(uint8_t value) {value_ = format("{}", value);}
        void value(uint16_t value) {value_ = format("{}", value);}
        void value(uint32_t value) {value_ = format("{}", value);}
        void value(uint64_t value) {value_ = format("{}", value);}
        void value(uintptr_t value) {value_ = format("{}", value);}
        template<typename value_t>
        void value(value_t value) {value_ = format("{}", value);}

        bool to_boolean() const {return xtd::parse<bool>(value_);}
        double to_double() const {return xtd::parse<double>(value_);}
        int8_t to_int8() const {return xtd::parse<int8_t>(value_);}
        int16_t to_int16() const {return xtd::parse<int16_t>(value_);}
        int32_t to_int32() const {return xtd::parse<int32_t>(value_);}
        int64_t to_int64() const {return xtd::parse<int64_t>(value_);}
        intptr_t to_intptr() const {return xtd::parse<intptr_t>(value_);}
        float to_single() const {return xtd::parse<float>(value_);}
        std::string to_string() const {return value_;}
        uint8_t to_uint8() const {return xtd::parse<uint8_t>(value_);}
        uint16_t to_uint16() const {return xtd::parse<uint16_t>(value_);}
        uint32_t to_uint32() const {return xtd::parse<uint32_t>(value_);}
        uint64_t to_uint64() const {return xtd::parse<uint64_t>(value_);}
        uintptr_t to_uintptr() const {return xtd::parse<uintptr_t>(value_);}
        template<typename value_t>
        uintptr_t to() const {return xtd::parse<value_t>(value_);}

        friend std::ostream& operator <<(std::ostream& os, const property& property) noexcept {return os << property.to_string();}
        
      private:
        std::string value_;
      };
    }
  }
}
