
# xtd concepts

## legends

🟢 Available
🔴 coming soon

## Types 

⚫️ concepts
🟢   |- xtd::logical
🟢   |- xtd::character
🟢   |- xtd::enumeration
🟢   |- xtd::number = xtd::numeric
🟢   |- xtd::numeric (||)
🟢   |    |- xtd::integer (||)
🟢   |    |    |- xtd::integer_8
🟢   |    |    |- xtd::integer_16
🟢   |    |    |- xtd::integer_32
🟢   |    |    |- xtd::integer_64
🟢   |    |    |- xtd::signed_integer (||)
🟢   |    |    |   |- xtd::signed_integer_8
🟢   |    |    |   |- xtd::signed_integer_16
🟢   |    |    |   |- xtd::signed_integer_32
🟢   |    |    |   |- xtd::signed_integer_64
🟢   |    |    |- xtd::unsigned_integer (||)
🟢   |    |         |- xtd::unsigned_integer_8
🟢   |    |         |- xtd::unsigned_integer_16
🟢   |    |         |- xtd::unsigned_integer_32
🟢   |    |         |- xtd::unsigned_integer_64
🟢   |    |- xtd::real (||)
🟢   |         |- xtd::real_single
🟢   |         |- xtd::real_double
🟢   |         |- xtd::real_decimal
🟢   |- xtd::textual
🟢        |- xtd::textual_literal

### Definitions

| xtd type           | std type                           | xtd::logical | xtd::numeric | xtd::integer | xtd::signed_integer | xtd::unsigned_integer | xtd::real | xtd::character | xtd::textual | xtd::enumeration |
| ------------------ |----------------------------------- | ------------ | ------------ | ------------ | ------------------- | --------------------- | --------- | -------------- | ------------ | ---------------- |
| xtd::boolean       | bool                               | ✅            | ❌            | ❌            | ❌                   | ❌                     | ❌         | ❌              | ❌            | ❌                |
| xtd::byte          | unsigned char / std::uint8_t       | ❌            | ✅            | ✅            | ❌                   | ✅                     | ❌         | ❌              | ❌            | ❌                |
| char               | char                               | ❌            | ❌            | ❌            | ❌                   | ❌                     | ❌         | ✅              | ❌            | ❌                |
| xtd::char8         | char8_t                            | ❌            | ❌            | ❌            | ❌                   | ❌                     | ❌         | ✅              | ❌            | ❌                |
| xtd::char16        | char16_t                           | ❌            | ❌            | ❌            | ❌                   | ❌                     | ❌         | ✅              | ❌            | ❌                |
| xtd::char32        | char32_t                           | ❌            | ❌            | ❌            | ❌                   | ❌                     | ❌         | ✅              | ❌            | ❌                |
| xtd::decimal       | long double                        | ❌            | ✅            | ❌            | ❌                   | ❌                     | ✅         | ❌              | ❌            | ❌                |
| double             | double                             | ❌            | ✅            | ❌            | ❌                   | ❌                     | ✅         | ❌              | ❌            | ❌                |
| xtd::int16         | short / std::int16_t               | ❌            | ✅            | ✅            | ✅                   | ❌                     | ❌         | ❌              | ❌            | ❌                |
| xtd::int32         | int / std::int32_t                 | ❌            | ✅            | ✅            | ✅                   | ❌                     | ❌         | ❌              | ❌            | ❌                |
| xtd::int64         | long long / std::int64_t           | ❌            | ✅            | ✅            | ✅                   | ❌                     | ❌         | ❌              | ❌            | ❌                |
| xtd::sbyte         | signed char / std::int8_t          | ❌            | ✅            | ✅            | ✅                   | ❌                     | ❌         | ❌              | ❌            | ❌                |
| xtd::single        | float                              | ❌            | ✅            | ❌            | ❌                   | ❌                     | ✅         | ❌              | ❌            | ❌                |
| xtd::size          | size_t                             | ❌            | ✅            | ✅            | ❌                   | ✅                     | ❌         | ❌              | ❌            | ❌                |
| xtd::uint16        | unsigned short / std::uint16_t     | ❌            | ✅            | ✅            | ❌                   | ✅                     | ❌         | ❌              | ❌            | ❌                |
| xtd::uint32        | unsigned int / std::uint32_t       | ❌            | ✅            | ✅            | ❌                   | ✅                     | ❌         | ❌              | ❌            | ❌                |
| xtd::uint64        | unsigned long long / std::uint64_t | ❌            | ✅            | ✅            | ❌                   | ✅                     | ❌         | ❌              | ❌            | ❌                |
| xtd::wchar         | wchar_t                            | ❌            | ❌            | ❌            | ❌                   | ❌                     | ❌         | ✅              | ❌            | ❌                |
| xtd::string        | std::string                        | ❌            | ❌            | ❌            | ❌                   | ❌                     | ❌         | ❌              | ✅            | ❌                |
| xtd::u8string      | std::u8string                      | ❌            | ❌            | ❌            | ❌                   | ❌                     | ❌         | ❌              | ✅            | ❌                |
| xtd::u16string     | std::u16string                     | ❌            | ❌            | ❌            | ❌                   | ❌                     | ❌         | ❌              | ✅            | ❌                |
| xtd::u32string     | std::u32string                     | ❌            | ❌            | ❌            | ❌                   | ❌                     | ❌         | ❌              | ✅            | ❌                |
| xtd::wstring       | std::wstring                       | ❌            | ❌            | ❌            | ❌                   | ❌                     | ❌         | ❌              | ✅            | ❌                |
| const char*        | const char*                        | ❌            | ❌            | ❌            | ❌                   | ❌                     | ❌         | ❌              | ✅            | ❌                |
| const xtd::char8*  | const char8_t*                     | ❌            | ❌            | ❌            | ❌                   | ❌                     | ❌         | ❌              | ✅            | ❌                |
| const xtd::char16* | const char16_t*                    | ❌            | ❌            | ❌            | ❌                   | ❌                     | ❌         | ❌              | ✅            | ❌                |
| const xtd::char32* | const char32_t*                    | ❌            | ❌            | ❌            | ❌                   | ❌                     | ❌         | ❌              | ✅            | ❌                |
| const xtd::wchar*  | const wchar_t*                     | ❌            | ❌            | ❌            | ❌                   | ❌                     | ❌         | ❌              | ✅            | ❌                |
| enum               | enum                               | ❌            | ❌            | ❌            | ❌                   | ❌                     | ❌         | ❌              | ❌            | ✅                |
| enum class         | enum class                         | ❌            | ❌            | ❌            | ❌                   | ❌                     | ❌         | ❌              | ❌            | ✅                |
| enum struct        | enum struct                        | ❌            | ❌            | ❌            | ❌                   | ❌                     | ❌         | ❌              | ❌            | ✅                |
| xtd::object        | /                                  | ❌            | ❌            | ❌            | ❌                   | ❌                     | ❌         | ❌              | ❌            | ❌                |
| user type          | /                                  | ❌            | ❌            | ❌            | ❌                   | ❌                     | ❌         | ❌              | ❌            | ❌                |

## Able

⚫️ concepts
🟢   |- xtd::integer_arithmeticable (&&)
🟢   |    |- xtd::arithmeticable (&&)
🟢   |    |    |- xtd::addable
🟢   |    |    |- xtd::divisible
🟢   |    |    |- xtd::multipliable
🟢   |    |    |- xtd::subtractable
🟢   |    |- xtd::modable
🔴   |- xtd::callable = invokable
🔴   |- xtd::clonable
🟢   |- xtd::decrementable (&&)
🟢   |    |- xtd::post_decrementable
🟢   |    |- xtd::pre_decrementable
🟢   |- xtd::formattable
🔴   |- xtd::full_comparable (&&)
🟢   |    |- xtd::comparable (&&)
🟢   |    |    |- xtd::greater_than_comparable
🟢   |    |    |- xtd::less_than_comparable
🔴   |    |- xtd::equatable
🔴   |- xtd::hashable
🟢   |- xtd::incrementable (&&)
🟢   |    |- xtd::post_incrementable
🟢   |    |- xtd::pre_incrementable
🔴   |- xtd::invokable
🔴   |- xtd::nullable
🔴   |- xtd::observable
🔴   |- xtd::random_access_iterable (&&)
🔴   |   |- xtd::bidirectional_iterable (&&)
🔴   |   |    |- xtd::backward_iterable
🟢   |   |    |- xtd::forward_iterable
🔴   |- xtd::streamable (&&)
🟢   |   |- xtd::stream_insertable
🔴   |   |- xtd::stream_extractable
🟢   |- xtd::stringable
🟢   |- xtd::collections::generic::enumerable
🔴   |- xtd::ranges::range = std::ranges::range

### Definitions

| Status | Concept                               | Corresponding interface                | Main role                                               | Interaction / Usage                                                                 |
| ------ | ------------------------------------- | -------------------------------------- | ------------------------------------------------------- | ----------------------------------------------------------------------------------- |
| 🟢      | xtd::comparable                       | xtd::icomparable                       | Allows `<` and `>` between types                        | Useful for sorting, ordering, specialized algos                                     |
| 🟢      | xtd::greater_than_comparable          | /                                      | Allows `>` between types                                | Used by xtd::comparable; useful for max, partial sorting, specialized algos         |
| 🟢      | xtd::less_than_comparable             | /                                      | Allows `<` between types                                | Used by xtd::comparable; useful for min, partial sorting, specialized algos         |
| 🔴      | xtd::clonable                         | xtd::iclonable                         | Object can be cloned                                    | Collections, polymorphic objects, abstract copy                                     |
| 🔴      | xtd::equatable                        | xtd::iequatable                        | Allows `==` and `!=` between types                      | Sets, dictionaries, collections, tests                                              |
| 🟢      | xtd::formattable                      | xtd::iformattable                      | Object can be formatted for xtd::string::format         | Console, println, logging, light serialization                                      |
| 🔴      | xtd::hashable                         | xtd::ihashable                         | Object can be hashed                                    | xtd::collections::generic::dictionary, xtd::collections::generic::hash_set, caches  |
| 🔴      | xtd::observable                       | xtd::iobservable                       | Observable / reactive object                            | UI, tasks, responsive pipelines, event notifications                                |
| 🔴      | xtd::random_access_iterable           | /                                      | Random access iterable                                  | Not used in xtd                                                                     |
| 🔴      | xtd::bidirectional_iterable           | /                                      | Bidirectional iterable                                  | Not used in xtd                                                                     |
| 🔴      | xtd::backward_iterable                | /                                      | Iterable backward only                                  | Not used in xtd                                                                     |
| 🟢      | xtd::forward_iterable                 | /                                      | Iterable forward only                                   | Collections, coroutines, pipelines LINQ                                             |
| 🔴      | xtd::streamable                       | /                                      | Allows `<<`with std::ostream and `>>` with std::istream | input ans output stream operations, light serialization                             |
| 🟢      | xtd::stream_insertable                | /                                      | Allows `<<`with std::ostream                            | Console, println, logging, light serialization                                      |
| 🔴      | xtd::stream_extractable               | /                                      | Allows `>>`with std::istream                            | input stream operations, light serialization                                        |
| 🟢      | xtd::stringable                       | xtd::istringable                       | Conversion to string                                    | Serialization, logs, display, debugging                                             |
| 🟢      | xtd::collections::generic::enumerable | xtd::collections::generic::ienumerable | Base for all collections / LINQ                         | Used by xtd::forward_iterable, by all LINQ pipelines, tasks that return collections |
