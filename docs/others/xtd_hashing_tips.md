# 7 Ways to Hash Custom Types in xtd

This document provides a clear and practical overview of the seven main strategies available in **xtd** to make custom user-defined types hashable. It compares each method, shows when to use it, and highlights how xtd improves upon the STL and .NET models by combining the strengths of both worlds.

---

## 1. `foo1` – Native C++ (Default Hashing)
**Concept:**  
A type with no hash customization is hashed by **its address** (pointer identity).

**Pros:**  
- Zero effort  
- Works automatically  

**Cons:**  
- Not suitable for value-based equality  
- Each instance has a different hash

**Use only for:**  
Identity containers or internal objects where address identity is intended.

---

## 2. `foo2` – Specializing `std::hash<T>`
**Concept:**  
Provide a specialization of `std::hash<your_type>`.

**Pros:**  
- Standard STL technique  
- Non-intrusive  
- Works with both STL and xtd containers

**Cons:**  
- Boilerplate code  
- Specialization must be in namespace `std`  
- Cannot be overloaded per-container (global only)

**Use for:**  
Lightweight types where you want STL and xtd compatibility.

---

## 3. `foo3` – Implementing `ihashable` (xtd style)
**Concept:**  
Your type implements the `ihashable` interface and exposes `get_hash_code()`.

**Pros:**  
- .NET-like  
- Clean, explicit, self-contained  
- Works for value types and class types  
- Plays perfectly with xtd containers

**Cons:**  
- Requires modifying the type  

**Use for:**  
Core types in your project where value identity is meaningful.

---

## 4. `foo4` – Inheriting from `object` With Default Hash
**Concept:**  
Derive your class from the xtd root type `object`.

If you don’t override `equals` or `get_hash_code`, xtd falls back to safe defaults:

- Hash = stable runtime identity  
- Equality = reference identity

**Pros:**  
- Behaves like .NET’s `object`  
- Good for base polymorphic types

**Cons:**  
- Still not value-based unless you override methods

**Use for:**  
Reference-type models or polymorphism where identity matters.

---

## 5. `foo5` – Inheriting from `object` With Custom `equals` + `get_hash_code`
**Concept:**  
Override both methods to get full value-based semantics.

**Pros:**  
- Perfect value semantics  
- Full .NET-like behavior  
- Works for any xtd container  

**Cons:**  
- Requires two methods to be implemented properly

**Use for:**  
Types that act as keys or value objects in your domain.

---

## 6. `foo6` – Providing an External `iequality_comparer<T>`
**Concept:**  
Define a custom comparer object that implements hashing and equality externally.

**Pros:**  
- Non-intrusive  
- Multiple comparers can exist for the same type  
- Perfect when you need alternative hash strategies

**Cons:**  
- Must be passed explicitly to the container

**Use for:**  
Cases like case-insensitive strings, or hashing by a subset of fields.

---

## 7. `foo7` – Template-Injected Hasher (STL-like)
**Concept:**  
The container is instantiated with a custom hasher passed as a template parameter:

```cpp
unordered_set<foo, my_hasher> set;
```

**Pros:**  
- Perfect STL compatibility  
- Non-intrusive  
- User can decide per-container strategy  

**Cons:**  
- Boilerplate equals + hasher pair  
- Less expressive than xtd-specific interfaces

**Use for:**  
Users familiar with STL conventions or cases requiring multiple independent hashers.

---

# Comparison Table

| Method | Intrusive? | Per-Type | Per-Container | Value-Based? | Notes |
|-------|------------|----------|---------------|---------------|-------|
| foo1 | No | No | No | ❌ | Address identity |
| foo2 | No | Yes (global) | No | ✔️ | STL-compatible |
| foo3 | Yes (`ihashable`) | Yes | Yes | ✔️ | Clean xtd pattern |
| foo4 | Yes (`object`) | Yes | No | ❌ | Identity unless overridden |
| foo5 | Yes (`object`) | Yes | No | ✔️ | Full .NET-like |
| foo6 | External | No | Yes | ✔️ | Multiple strategies possible |
| foo7 | External | No | Yes | ✔️ | STL-style container customizer |

---

# Recommendations

### ✔️ Best for most xtd code  
**Use `foo3` (ihashable)** or **foo5 (object + overrides)**.

These two give the cleanest, safest, most consistent semantics.

### ✔️ When you need multiple hashing strategies  
Use **foo6** or **foo7**.

### ✔️ When you need STL compatibility  
Use **foo2** or **foo7**.

### ❌ Avoid  
`foo1` except for pointer-identity semantics.

---

# Summary

xtd gives you **every hashing strategy** the STL or .NET ever offered — and lets you mix them freely:

- **STL-style**  
- **.NET-style**  
- **Hybrid**  
- **Per-object**  
- **Per-type**  
- **Per-container**

Few frameworks do this.  
xtd does it cleanly, elegantly, and consistently.

---

If you want, I can generate a **second document** with code samples for all seven cases.

