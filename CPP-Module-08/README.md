# CPP Module 08 — STL algorithmic exercises and container utilities

This module includes several small projects that exercise the use of STL algorithms, custom container utilities and iterator-compatible types.

Exercises (detailed):

- `ex00/` — easyfind
  - Files: `easyfind.hpp`, `easyfind.tpp`, `main.cpp`.
  - Purpose: Implement a template function `easyfind` that searches for an integer value inside any standard container (vector, list, etc.) using `std::find` and returns the found value or throws an exception when not found. The `main` demonstrates using `easyfind` with `std::list` and `std::vector`.

- `ex01/` — Span
  - Files: `Span.hpp`, `Span.cpp`, `Span.tpp`, `main.cpp`.
  - Purpose: Implement a `Span` class that stores a set of integers and can compute the shortest and longest span (minimum difference between any two numbers and maximum difference). It supports adding single numbers and adding ranges via iterators. The `main` demonstrates small and large cases and exception handling when spans can't be computed.

- `ex02/` — MutantStack
  - Files: `MutantStack.hpp`, `MutantStack.tpp`, `main.cpp`.
  - Purpose: Implement `MutantStack`, a stack-like container that exposes iterators (begin/end) so it can be iterated like other containers. The `main` compares behavior with a `std::list` and shows iterator traversal.

How to build:

Each exercise has a `Makefile`; run `make` inside the exercise folder.
