
# CPP Module 07 — Templates and small generic utilities

This module contains template-based utilities and small generic containers that practice creating type-safe, reusable code.

Exercises (detailed):

- `ex00/` — whatever (swap / min / max)
	- Files: `whatever.hpp`, `main.cpp`.
	- Purpose: Implement template functions `swap`, `min`, and `max` that work for built-in types and user-defined types. The `main` demonstrates swapping integers and strings and printing min/max values.

- `ex01/` — iter
	- Files: `iter.hpp`, `main.cpp`.
	- Purpose: Implement a template function `iter` that applies a function to each element of an array. The `main` shows `iter` used with a print function on an integer array.

- `ex02/` — Array (templated array class)
	- Files: `Array.hpp`, `Array.tpp`, `main.cpp`.
	- Purpose: Implement a template `Array<T>` class that behaves like a fixed-size array with bounds-checked `operator[]`, `getSize()` and proper copy semantics. The `main` demonstrates usage and exception on out-of-bounds access.

How to build:

Each exercise has a `Makefile`; run `make` inside the exercise folder.

