/* consider two classes one representing 1st name and anoatheer representing Last name 
how to use bridge functuon(friend)function to dynamically concatenates the string of two classes 
*/


#include <iostream>
#include<string.h>

using namespace std; 

class Last;

class First
{
    private:
    char* first;

    public:
    First()
    {
        first = nullptr;
    }
    First(const char* f)
    {
        int len = strlen( f );
        first = new char[ len +1 ];
        strcpy(first , f);
    }

    ~First(){}

    friend char* fullName( First& f , Last& l);
};

class Last
{
    private:
    char* last;

    public:
    Last()
    {
        last = nullptr;
    }

    Last(const char* l)
    {
        int len = strlen(l);
        last = new char[ len +1];
        strcpy(last , l);
    }

    friend  char* fullName(First& f , Last& l);
    
};

char* fullName( First& f , Last& l)
{
    /* Take away form AI search to eleminate magic number problem:
    
    In modern C++, the best way to do this is using constexpr (or const). 
    This gives the number a readable name without adding any runtime overhead
     or taking up extra memory, because the compiler can optimize it away.
    
Why this is the best approach:
Readability: Anyone reading your code will instantly know why you are adding 2.

Type Safety: Unlike old C-style macros (#define EXTRA_SPACE 2), constexpr respects scope and has an explicit data type.

Performance: The compiler treats EXTRA_SPACE exactly like the literal number 2, meaning your code remains highly efficient.
 */
    constexpr int Space_CHAR = 1;
   

    int len = strlen(f.first) + strlen(l.last)+Space_CHAR;
    char* name = new char[ len + 1 ];

    strcpy(name, f.first); //strcpy and strcat are diffrent
    strcat(name, " "); 
    strcat(name, l.last);

    return name;
    
}

int main()
{
    First F("Rohit");
    Last L("Bhatt");
    cout<<fullName(F,L)<<endl;
}












//Personal Notes:

/* # C++ Constants: When to Use `const` vs `constexpr`

Both `const` and `constexpr` are used to make variables unmodifiable, but they tell the compiler to do very different things under the hood. 

The core difference comes down to **when** the value is determined: `const` is for values fixed at **runtime**, while `constexpr` is for values fixed at **compile-time**.

---

## The Golden Rule of Thumb
> **Use `constexpr` whenever you can, and use `const` when you have to.**

---

## 1. When to use `constexpr` (Compile-Time)

Use `constexpr` when the value is absolutely known at compile-time and will never change. This allows the compiler to optimize your code by calculating the value ahead of time, saving CPU cycles when the program runs.

### Common Use Cases:
* **Hardcoded configurations and math constants:** (e.g., Max array sizes, Pi, conversion factors).
* **Array bounds:** Setting the size of a standard array.
* **Template arguments:** Values passed into template parameters.

### Code Example:
```cpp
constexpr double PI = 3.14159265; // Computed at compile-time
constexpr int MAX_USERS = 100;    // Processed by the compiler

int open_slots[MAX_USERS];        // Works! Compiler needs a compile-time constant here
const int USER_INPUT = x; // Works! It's fixed for the rest of this execution.
// constexpr int BAD_INPUT = x; // ERROR! Compiler doesn't know what 'x' is yet.
Quick Comparison SummaryFeatureconstexprconstWhen is it evaluated?During CompilationDuring 
Runtime (usually)What can initialize it?Only other compile-time constantsAnything (literals,
 variables, functions)Can it specify array sizes?YesNo (except for const int initialized with 
 a literal)Primary PurposePerformance & OptimizationCode safety (read-only enforcement)A 
 final way to think about it:All constexpr variables are implicitly const (you can't change 
 them), but not all const variables can be constexpr (because they might not be known at 
 compile-time).Does this distinction make sense for the constants you are planning to add 
 to your length calculation?
 */