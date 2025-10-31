# CPP Module 09 — Algorithmic challenges and small projects

This module contains several standalone projects that exercise algorithm design, parsing, and performance comparison between containers.

Exercises (detailed):

- `ex00/` — Bitcoin Exchange
  - Files: `BitcoinExchange.hpp/cpp`, `main.cpp`, `data.csv` (expected in working dir).
  - Purpose: Parse a CSV database of historical bitcoin exchange rates (`data.csv`) and process an input file of date/value pairs to compute exchange amounts. The program validates input and uses the loaded database to lookup the appropriate rate for each date.

- `ex01/` — RPN (Reverse Polish Notation evaluator)
  - Files: `RPN.hpp/cpp`, `main.cpp`.
  - Purpose: Evaluate a single RPN expression provided as a program argument. Supports basic operators and numeric tokens; prints the computed result or an error for invalid expressions.

- `ex02/` — PmergeMe
  - Files: `PmergeMe.hpp/cpp`, `main.cpp`.
  - Purpose: Implement a hybrid sorting algorithm (merge-insertion) and compare performance between `std::vector` and `std::deque` for the same input set. The `main` validates input, sorts the containers, prints the timings and the sorted result.

How to build:

Each exercise has a `Makefile`; run `make` inside the exercise folder.
