*This activity has been created as part of the 42 curriculum by ppodobri.*

# Description

The goal of this activity was to replicate the `printf` function from `<stdio.h>`. `ft_printf` writes formatted output to standard output and returns the number of characters printed, just like the original.

The following conversions are implemented:

- `%c` Prints a single character.
- `%s` Prints a string (as defined by the common C convention). A `NULL` string prints `(null)`.
- `%p` Prints a `void *` pointer in hexadecimal format, prefixed with `0x`. A `NULL` pointer prints `(nil)`.
- `%d` Prints a decimal (base 10) number.
- `%i` Prints an integer in base 10.
- `%u` Prints an unsigned decimal (base 10) number.
- `%x` Prints a number in hexadecimal (base 16) lowercase format.
- `%X` Prints a number in hexadecimal (base 16) uppercase format.
- `%%` Prints a percent sign.

# Instructions

Build the library:

```sh
make        # builds libftprintf.a
make clean  # removes object files
make fclean # removes object files and libftprintf.a
make re     # rebuilds everything
```

Use it in your own program by including the header and linking the library:

```c
#include "ft_printf.h"

int main(void)
{
	ft_printf("Hello %s, the answer is %d\n", "world", 42);
	return (0);
}
```

```sh
cc -Wall -Wextra -Werror main.c libftprintf.a -I.
```

# Algorithms and data structures

## Parsing

`ft_printf` makes a single linear pass over the format string (O(n) in its length). Regular characters are written directly with `write`. When a `%` is followed by another character, that character is passed to a dispatcher, which calls the handler for the matching conversion and then skips both characters. A `%` at the very end of the string is printed as a regular character, so the parser never reads past the terminating `'\0'`.

## Variadic arguments

The arguments are accessed through a `va_list`. It is passed **by pointer** to the dispatcher and the handlers, so every handler advances the same argument list. Each handler reads its argument with the type the caller actually passed (`int` for `%c`/`%d`/`%i`, `unsigned int` for `%u`/`%x`/`%X`, `char *` for `%s`, `void *` for `%p`). Reading with the wrong type would produce garbage, because a `va_list` carries no type or count information.

## Number conversion

Numbers are printed with a **recursive base conversion**: if the number has more than one digit, the function first calls itself with `n / base`, then writes the digit for `n % base`. Because the recursion returns from the most significant digit down, the digits come out in the correct order without needing a buffer, so there is no length limit. Digits are looked up in a table (`"0123456789abcdef"` or `"0123456789ABCDEF"`), so the same approach works for base 10 and base 16.

The hexadecimal function takes an `unsigned long`, because it is also used for `%p`: on 64-bit Linux a memory address needs up to 64 bits, while an `unsigned int` only holds 32. With a 32-bit parameter, the upper hex digits of an address were lost. For `%x`/`%X`, the `unsigned int` argument is read first and then widened to `unsigned long`, which keeps its value.

## Return value

Every handler keeps track of how many characters it wrote, and the total is accumulated in `ft_printf`, so the final return value matches the number of characters printed by the original `printf`.

## Edge cases

- `INT_MIN` (`-2147483648`) is handled separately, because negating it does not fit in an `int`.
- `NULL` for `%s` prints `(null)` and `NULL` for `%p` prints `(nil)`, matching glibc.

## Why this design

- **Recursion instead of a buffer:** no maximum length to get wrong and less code.
- **`write` per character:** simple and predictable. Output buffering was not required.
- **No heap allocation:** nothing to free, so no leaks are possible.

# Resources

- [C variadic functions](https://learn.programmingline.com/learn/c/c-variadic-functions)
- [Video: variadic functions / printf](https://www.youtube.com/watch?v=S-ak715zIIE)
- [Video: printf implementation](https://www.youtube.com/watch?v=7Sph8JlRo0g)
- Discussions with peers

## AI usage

AI was used to understand why `printf` behaves the way it does and how `va_arg` works. No code was written by an LLM. This README was drafted with AI assistance based on my implementation and notes, then reviewed by me.