Q1. "Can you explain the difference between a pointer and a reference in C++? When would you prefer one over the other?

Ans) Pointer stores the memory address of a variable. It can be null, reassigned, and needs dereferencing (*ptr) to access the value.
Reference is an alias for an existing variable. It cannot be null, cannot be reassigned after initialization, and no dereferencing needed.
int x = 10;
int* ptr = &x;    // pointer — stores address of x
int& ref = x;     // reference — alias for x

*ptr = 20;        // modify via pointer
ref = 20;         // modify via reference — same effect
Pass by pointer vs pass by reference — both pass the address, so both reflect changes outside the function. Your explanation mixed this up — passing by pointer does reflect changes if you modify the pointed-to value.
void byPointer(int* p) { *p = 99; }  // change REFLECTS outside
void byReference(int& r) { r = 99; } // change REFLECTS outside
void byValue(int v) { v = 99; }      // change does NOT reflect
When to prefer which:
Use reference when parameter should never be null and won't be reassigned
Use pointer when null is a valid state or you need to reassign
Use const reference for passing large objects without copying
