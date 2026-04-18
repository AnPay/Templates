Q1. What is Python? List its key features that distinguish it from other languages.
Python is a high-level, interpreted, general-purpose programming language known for its simplicity and readability.
Key features:

Dynamically typed
Interpreted
Supports OOP, procedural, and functional programming
Large standard library
Cross-platform
Automatic memory management

Q2. How do you write a comment in Python? What is the difference between single-line and multi-line comments?
Single-line comment: starts with #
Multi-line comment: written using triple quotes (''' or """), though technically they are strings.

Q3. What is PEP 8 and why is it important for Python development?
PEP 8 is the official style guide for Python code. It improves readability, enforces consistency, and helps teams collaborate effectively.

Q4. How do you print output in Python? Demonstrate with different print() options.
Use print() function.
Examples:

print("Hello")
print("Value:", 10)
print("A", "B", sep="-")
print("Hello", end=" ")
print(f"Hello {name}")

Q5. What is the difference between a script and an interactive Python session?
A script is a .py file executed as a whole.
An interactive session executes code line-by-line and gives immediate output.

Q6. How do you take user input in Python? What type does input() always return?
Use input() function.
Example: x = input("Enter value: ")
It always returns a string.

Q7. Explain the concept of indentation in Python. What happens if you mix tabs and spaces?
Python uses indentation to define code blocks. Standard is 4 spaces.
Mixing tabs and spaces results in an IndentationError.

Q8. What are Python keywords? List at least 10 examples.
Keywords are reserved words in Python.
Examples: if, else, elif, for, while, def, return, class, try, except, True, False, None

Q9. How do you declare a variable in Python? Are there any naming conventions?
Variables are declared without specifying type.
Example: x = 10
Naming conventions:

Use lowercase with underscores (snake_case)
Cannot start with a number
Cannot use keywords

Q10. What is dynamic typing in Python? Give an example.
Variable type is determined at runtime.
Example:
x = 10
x = "hello"

Q11. How do you check the type of a variable in Python?
Use type() function.
Example: type(x)

Q12. What is the difference between = (assignment) and == (comparison) in Python?
= assigns a value to a variable.
== compares two values and returns True or False.

Q13. How do you swap two variables in Python without a temporary variable?
Use tuple unpacking:
a, b = b, a

Q14. What are constants in Python and how are they conventionally defined?
Python does not have true constants.
Convention: use uppercase variable names (e.g., PI = 3.14).

Q15. Explain multiple assignment in Python with an example
Assign same value:
a = b = c = 0
Assign different values:
x, y, z = 1, 2, 3

Q16. What are the built-in data types in Python?

Numeric: int, float, complex
Sequence: list, tuple, range, str
Mapping: dict
Set: set, frozenset
Boolean: bool
NoneType

Q17. What is the difference between int and float in Python?
int represents whole numbers.
float represents decimal numbers.
Python does not use fixed memory sizes like 4 or 8 bytes.

Q18. What is a boolean in Python? What values evaluate to False?
Boolean values are True and False.
Falsy values: False, None, 0, 0.0, '', [], {}, set()

Q19. How does Python handle very large integers? Is there an integer overflow?
Python supports arbitrary precision integers.
There is no integer overflow.

Q20. What is the NoneType and when do you use None?
None represents absence of a value.
Used as default return value or placeholder.

Q21. What is type casting? How do you convert an integer to a string?
Type casting means converting one data type to another.
Example: str(10)

Q22. What is the difference between implicit and explicit type conversion?
Implicit: automatic conversion by Python
Example: 5 + 2.0 → float
Explicit: manual conversion
Example: int("10")

Q23. How do you check if a variable is of a specific type using isinstance()?
Example: isinstance(x, int)

Q24. What is the difference between mutable and immutable data types? Give examples
Mutable: can be modified (list, dict, set)
Immutable: cannot be modified (int, float, str, tuple)

If you revise this once or twice, you’ll be solid for basic Python interviews.
