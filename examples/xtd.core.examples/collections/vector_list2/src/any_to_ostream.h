#pragma once
#include <any>
#include <functional>
#include <ostream>
#include <typeindex>
#include <map>

using any_type_ostreamer = std::function<std::ostream&(std::ostream&, const std::any&)>;

template<typename type_t, typename function_t>
inline std::pair<const std::type_index, any_type_ostreamer> to_any_type_ostreamer(const function_t& function) {
  return {std::type_index(typeid(type_t)), [g = function](std::ostream& os, std::any const &any)->std::ostream& {
      return g(os, std::any_cast<const type_t&>(any));
    }
  };
}

std::map<std::type_index, any_type_ostreamer>& get_registered_types() {
  static std::map<std::type_index, any_type_ostreamer> registered_types;
  if (registered_types.empty()) {
    registered_types.insert(to_any_type_ostreamer<bool>([](std::ostream& os, bool value)->std::ostream& {return os << value;}));
    registered_types.insert(to_any_type_ostreamer<int8_t>([](std::ostream& os, int8_t value)->std::ostream& {return os << value;}));
    registered_types.insert(to_any_type_ostreamer<int16_t>([](std::ostream& os, int16_t value)->std::ostream& {return os << value;}));
    registered_types.insert(to_any_type_ostreamer<int32_t>([](std::ostream& os, int32_t value)->std::ostream& {return os << value;}));
    registered_types.insert(to_any_type_ostreamer<int64_t>([](std::ostream& os, int64_t value)->std::ostream& {return os << value;}));
    registered_types.insert(to_any_type_ostreamer<uint8_t>([](std::ostream& os, uint8_t value)->std::ostream& {return os << value;}));
    registered_types.insert(to_any_type_ostreamer<uint16_t>([](std::ostream& os, uint16_t value)->std::ostream& {return os << value;}));
    registered_types.insert(to_any_type_ostreamer<uint32_t>([](std::ostream& os, uint32_t value)->std::ostream& {return os << value;}));
    registered_types.insert(to_any_type_ostreamer<uint64_t>([](std::ostream& os, uint64_t value)->std::ostream& {return os << value;}));
    registered_types.insert(to_any_type_ostreamer<float>([](std::ostream& os, float value)->std::ostream& {return os << value;}));
    registered_types.insert(to_any_type_ostreamer<double>([](std::ostream& os, double value)->std::ostream& {return os << value;}));
    registered_types.insert(to_any_type_ostreamer<long double>([](std::ostream& os, long double value)->std::ostream& {return os << value;}));
  }
  return registered_types;
}

template<typename type_t, typename function_t>
void register_any_to_ostream(const function_t& function) {
  auto& registered_types = get_registered_types();
  registered_types.insert(to_any_type_ostreamer<type_t>(function));
}

std::ostream& operator<<(std::ostream& os, const std::any& value) noexcept {
  auto it = get_registered_types().find(std::type_index(value.type()));
  if (it != get_registered_types().end()) return it->second(os, value);
  return os << "(unknown)";
}
