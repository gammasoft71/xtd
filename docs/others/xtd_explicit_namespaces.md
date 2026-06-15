# Using xtd without `XTD_ENABLE_IMPLICIT_NAMESPACES`

By default, xtd enables the `XTD_ENABLE_IMPLICIT_NAMESPACES` CMake option.  
This allows developers to write shorter and cleaner code by avoiding repetitive namespace prefixes in typical scenarios.

---

## ✅ Simplified usage (default)

When the option is **enabled** (which is the default), you can simply use:

```cpp
#include <xtd/xtd>

class main_form : public form {
public:
  main_form() {
    text("Hello, World!");
    controls().push_back(label1);
    label1.text("Hello!");
  }

private:
  label label1;
};

auto main() -> int {
  application::run(main_form {});
}
```

This syntax is ideal for learning, writing quick prototypes, and focusing on the logic rather than verbose declarations.

---

## ⚙️ Explicit usage (without implicit namespaces)

When `XTD_ENABLE_IMPLICIT_NAMESPACES` is **disabled**, you need to:

- Include individual headers instead of the unified `<xtd/xtd>`;
- Use fully qualified names like `xtd::forms::label`;
- Or manually declare `using namespace` directives.

### Equivalent code with the option disabled:

```cpp
#include <xtd/forms/application>
#include <xtd/forms/form>
#include <xtd/forms/label>

using namespace xtd::forms;

class main_form : public form {
public:
  main_form() {
    text("Hello, World!");
    controls().push_back(label1);
    label1.text("Hello!");
  }

private:
  label label1;
};

auto main() -> int {
  application::run(main_form {});
}
```

You could also avoid `using namespace` and use fully qualified types explicitly:

```cpp
xtd::forms::label label1;
```

---

## 🔧 How to disable the option

To disable the implicit namespace support during configuration, pass the following to CMake:

```bash
cmake -DXTD_ENABLE_IMPLICIT_NAMESPACES=OFF ..
```

---

## 💡 Recommendation

We recommend keeping `XTD_ENABLE_IMPLICIT_NAMESPACES` **enabled** (default) when:

- Writing examples and tutorials;
- Creating small tools, UI prototypes or educational code;
- Focusing on readability and ease of use.

Disabling it may be preferable in:

- Large-scale projects where namespace clarity is important;
- Frameworks or libraries integrating with xtd and requiring strict symbol management.

---

## 📌 Summary table

| Feature                      | Enabled (`ON`)            | Disabled (`OFF`)                        |
|-----------------------------|---------------------------|-----------------------------------------|
| Namespace prefixes required | ❌ No                     | ✅ Yes                                  |
| Short includes              | ✅ `<xtd/xtd>`            | ❌ Must include individual components   |
| Suitable for beginners      | ✅ Yes                    | 🔶 Possibly, with more boilerplate      |
| Default value               | ✅ ON                     | ❌ Must be explicitly turned off        |

---

## ❓ FAQ

### Can I still use full namespaces when the option is enabled?
Yes! You can always use `xtd::forms::form` even if implicit namespaces are active.

### Will disabling this option break existing examples?
If you disable the option, examples using the simplified syntax may not compile unless you adapt them with proper includes and namespaces.

---

📘 See the [examples page](../examples/README.md) for more context on how this option affects code samples.