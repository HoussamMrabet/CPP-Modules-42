
# CPP Module 05 — Exceptions, class invariants and forms

This module focuses on designing classes with strong invariants and using exceptions to enforce correct usage. The exercises build a small bureaucratic system of `Bureaucrat` and `Form` objects, then add an abstract `AForm` and concrete form implementations, and finally an `Intern` factory.

Exercises (detailed):

- `ex00/` — Bureaucrat
	- Files: `Bureaucrat.hpp`, `Bureaucrat.cpp`, `main.cpp`.
	- Purpose: Implement a `Bureaucrat` class that stores a name and a grade (1..150). The class throws `GradeTooHighException` or `GradeTooLowException` if constructed or modified with an out-of-range grade. Provides `incrementGrade()` and `decrementGrade()` and an `operator<<` for printing. The `main` demonstrates construction, copy/assignment, increment/decrement and exception handling for invalid grades.

- `ex01/` — Form
	- Files: `Form.hpp`, `Form.cpp`, `main.cpp` (plus `Bureaucrat` from ex00).
	- Purpose: Implement a `Form` class that has a name, sign state, and required grades to sign and execute. A `Bureaucrat` can call `signForm`/`beSigned` and exceptions are raised if grades are invalid or too low to sign. The `main` demonstrates creating forms, signing attempts, and handling invalid form parameters.

- `ex02/` — AForm and concrete forms
	- Files: `AForm.hpp/cpp`, `PresidentialPardonForm.*`, `RobotomyRequestForm.*`, `ShrubberyCreationForm.*`, `Bureaucrat.*`, `main.cpp`.
	- Purpose: Introduce an abstract `AForm` base class and three concrete form types that implement `execute()` behavior:
		- `PresidentialPardonForm` — simulates granting a pardon to a target (prints a message).
		- `RobotomyRequestForm` — simulates a 50% chance robotomy action (uses randomness to print success/failure messages).
		- `ShrubberyCreationForm` — writes ASCII-art trees to a file named after the target.
	- The `main` shows signing and executing these forms with bureaucrats of different grades, testing permission checks and exception handling.

- `ex03/` — Intern + form factory
	- Files: `Intern.hpp/cpp`, extended `main.cpp` and the forms from `ex02`.
	- Purpose: Add an `Intern` class that can create forms by name (factory). The `main` demonstrates the intern creating forms and interactions with `Bureaucrat` and `AForm`, including error handling when the intern is asked for an unknown form.

How to build:

Each exercise has a `Makefile`; run `make` inside the exercise folder.

