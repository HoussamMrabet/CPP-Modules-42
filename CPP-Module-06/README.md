# CPP Module 06 — Type conversions, serialization and RTTI

This module contains small utilities that exercise low-level C++ features: literal parsing and conversion, pointer serialization, and runtime type identification using RTTI.

Exercises (detailed):

- `ex00/` — ScalarConverter
  - Files: `ScalarConverter.hpp/cpp`, `main.cpp`.
  - Purpose: Implement `ScalarConverter::convert(const std::string&)` which parses a literal (like `"42"`, `"42.0f"`, `"nan"`, `"'a'"`) and prints its representation as `char`, `int`, `float`, and `double` when possible. The program must handle special values (`nan`, `+inf`, `-inf`), display non-displayable characters, and print `impossible` where conversion can't be performed.

- `ex01/` — Serializer
  - Files: `Serializer.hpp/cpp`, `Data.hpp`, `main.cpp`.
  - Purpose: Demonstrate converting a pointer to an integer type and back safely. `Serializer::serialize(Data*)` returns a `uintptr_t` and `Serializer::deserialize(uintptr_t)` returns the original `Data*`. The `main` shows the addresses and verifies the deserialized pointer points to the original object.

- `ex02/` — RTTI identification (dynamic_cast exercise)
  - Files: `Base.hpp`, `A.hpp`, `B.hpp`, `C.hpp`, `main.cpp`.
  - Purpose: Implement three classes inheriting `Base`. Provide two `identify` overloads that detect the actual derived type from a `Base*` (using `dynamic_cast<T*>`) and from a `Base&` (using `dynamic_cast<T&>` with exception handling). The `main` generates a random derived instance and demonstrates both pointer- and reference-based identification.

How to build:

Each exercise has a `Makefile`; run `make` inside the exercise folder.

