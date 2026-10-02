J'avais bien pensé a truc comme ça mais plutot :

* iformatter :

```cpp
  class iformater interface {
  public:
    virtual bool try_to_string(const xtd::string& format, xtd::any_object obj, xtd::string& result) const noexcept = 0;
```

* iformat_provider : 

```cpp
namespace xtd {
  class iformat_provider interface_ {
  public:
    virtual xtd::any_object get_format(const xtd::type_object& type) = 0;
  };
}
```

* iformatable : 

```cpp
namespace xtd {
  class iformatable interface_ {
  public:
    virtual xtd::string to_string(const xtd::string& format, const iformat_provider& provider) const = 0;
  };
}
```

* culture_info : 

```cpp
namespace xtd {
  namespace globalization {
    class culture_info : public iformat_provider {
      xtd::any_object get_format(const xtd::type_object& type) const override {
        if (type == typeof_<xtd::globalization::calendar>()) return xtd::globalization::calendar {/*...*/};
        return {};
      }
    };
  }
}
```

* date_time :

```cpp
namespace xtd {
  class date_time : public xtd::iformatbale, public xtd::object {
  public:
    xtd::string to_string(const xtd::string& format) const override {
      return to_string(format, xtd::globalization::culture_info::current::culture());
    }

    xtd::string to_string(const xtd::string& format, const iformat_provider& provider) const override {
      /*
      auto calendar = as<xtd::globalization::calendar>(provider.get_format(typeof_<xtd::globalization::calendar>()));
      ...
      auto prov = as<user_format_provider>(provider.get_format(typeof_<user_format_provider>()));
      */
    }
  };
}
```

* main :

```cpp
class user_format_provider : public iformat_provider {
  class date_time_formater : public iformater {
  public:
    xtd::string try_to_string(const xtd::string& format, xtd::any_object obj) const noexcept override {
      if (!is<date_time>(obj)) return false;
      switch(format[0]) {
        case 'D' : result = as<date_time>(obj) + " with `D` format"; return true;
        case 'd' : result = return as<date_time>(obj) + " with `d` format"; return true
        case 't' : result = return as<date_time>(obj) + " with `t` format"; return true
      }
      return false;
    }
  };
  
public:
  xtd::any_object get_format(const xtd::type_object& type) const override {
   if (type == typeof_<xtd::date_time>()) return date_time_formater {};
   return {};
  }
};
 
auto main() -> int {
  auto now = date_time::now();
  println("now = {}", now.to_string(":D", culture_info {"en-US"}));
  println("now = {}", now.to_string(":D", user_format_provider {/*...*/}));
}
```


Mon vrai problème c'est lors de l'appel de `xtd::date_time:: to_string(const xtd::string& format, const iformat_provider& provider)`.
Si je ne connais pas le type à l'avance comme `user_format_provider`. 
Comment pouvoir vérifier dynmamiquement en C++ une instancier et utiliser un type que l'on ne connais pas ?

