# POC YAML + CSS

## web <-> xtd stack

┌─────────────────────────────────────────────────────────┐
│                    WEB STACK                            │
├─────────────────────────────────────────────────────────┤
│  HTML        →  Structure du document                   │
│  CSS         →  Apparence et mise en page               │
│  JavaScript  →  Logique et interactivité                │
└─────────────────────────────────────────────────────────┘
                         ↓ ↓ ↓
┌─────────────────────────────────────────────────────────┐
│                  DESKTOP NATIF (xtd)                    │
├─────────────────────────────────────────────────────────┤
│  YAML        →  Structure de l'interface                │
│  CSS         →  Apparence et mise en page               │
│  C++         →  Logique et interactivité                │
└─────────────────────────────────────────────────────────┘

## Examples

### C++

```cpp
#include <xtd/xtd>

auto main() -> int {
  auto form1 = form::create("Hello world (label)");
  auto label1 = label::create(form1, "Hello, World!");
  label1.shadow(true)
    .text_align(content_alignment::middle_center)
    .dock(dock_style::fill)
    .font({label1.font(), 32, font_style::bold | font_style::italic})
    .fore_color(color::green);
  application::run(form1);
}
```

### C++ + RAII

```cpp
#include <xtd/xtd>

namespace hello_world_label_example {
  class main_form : public form {
  public:
    main_form() {
      text("Hello world (label)");
      controls().add(label1);
      
      label1.dock(dock_style::fill);
      label1.font({label1.font(), 32, font_style::bold | font_style::italic});
      label1.fore_color(color::green);
      label1.shadow(true);
      label1.text("Hello, World!");
      label1.text_align(content_alignment::middle_center);
    }
    
  private:
    label label1;
  };
}

auto main() -> int {
  application::run(hello_world_label_example::main_form {});
}
```

### C++ + CSS

```cpp
#include <xtd/xtd>

auto main() -> int {
  auto form1 = form::create("Hello world (label)");
  auto label1 = label::create(form1, "Hello, World!");
  label1.style_sheet(R"(
    label {
      color: green;
      font: bold italic 32px;
      text-align: middle center;
      text-shadow: 2px 2px #000000;
    }
  )");
  application::run(form1);
}
```

### Markup YAML + CSS

```cpp
#include <xtd/xtd>

auto main() -> int {
  application::markup(R"(
    controls:
    - name: form1
      control: form
      text: Hello world (label)
      controls:
        - name: label1
          control: label
          dock: fill
          text: Hello, World!
          shadow: true
          style_sheet: |
            label {
              color: green;
              font: bold italic 32px;
              text-align: middle center;
              text-shadow: 2px 2px #000000;
            }
  )");
  application::run(application::markup.find<form>("form1"));
}
```
