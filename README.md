*This project has been created as part of the 42 curriculum by keblanch.*

# ft_printf

## Description

The goal of this project is to create a library (`libftprintf.a`) containing `ft_printf`, a recreation of the `printf` C function, using variadic parameters.

The specifiers taken into account are the following: **cspdiuxX%**

### Description - Bonus part

Along with the specifiers taken into account in the mandatory part, the function can now interpret these flags:

- `-` Left-justify within the given field `[width]`
- `0` Left-pads the number with zeroes within the given field `[width]`
- `(space)` Inserts a blank space where a sign would be
- `+` Inserts a plus sign if the number is positive
- `#` Inserts 0x or 0X at the start of an **x** or **X** specifier respectively if value is different than 0.
- `(number)` A number of characters defining `[width]` (see examples below)
- `.[precision]` Minimum number of digits written when used along **diuxX**, `[precision]` is asumed to be 0 if not specified; Maximum number of characters written if used with **s**

The expected syntax for the format specifier is `%[flags][width][.precision]specifier` with any number of flags in any order and one single specifier.

Although stdio's printf would throw a warning if using repeated flags and/or no specifier, we cannot throw warnings in this exercise.

Some specific cases that would throw warnings but still work using stdio's printf are not expected to be implemented, for exemple:

```c
// MOULINETTE OK
printf("%----") // >>-
ft_printf("%----") // >>%----
```

If the `specifier` part is omitted, the format specifier will not be interpreted.

#### Bonus examples

```c
// multiple flags in any order
ft_printf("%0 5d\n", 42); // >> 0042
ft_printf("%+05d\n", 42); // >>+0042
ft_printf("%05d\n", 42);  // >>00042
ft_printf("%#08X\n", 42); // >>0X00002A
ft_printf("%#8.4X\n", 42); // >>  0X002A
ft_printf("(% -+08.d)\n", 0); // >>(+       )
// here some flags are superfluous (0, (space), .4)
ft_printf("(%- 08.4c)\n", 'a'); // >>(a       )
ft_printf("(%- 08.4%)\n", 'a'); // >>(%)
// additional tests
ft_printf("(%08.3d)\n", 42);  // >>(     042)
ft_printf("(%4.0d)\n", 0);  // >>(    )
ft_printf("%+05d\n", -21);  // >>(-0021)
ft_printf("%+05d\n", INT_MIN);  // >>(-2147483648)
```

## Instructions

### Basic usage

- To create the library, use `make`
- To cleanup object files use `make clean`
- Use the resulting `libftprintf.a` library to access the `ft_printf` function.
  - The function prototype is the following: `int ft_printf(const char *, ...);`

### Compile with bonuses

- Use `make bonus`
- Use the resulting `libftprintf.a` library as in the basic usage.

### Testing

If this project was downloaded from github, you should also be able to create a testing program.

- To run tests, use the `make test` command
  - the resulting a.out program should display a variety of tests and use cases.

## Resources

[man 3 printf](https://man7.org/linux/man-pages/man3/printf.3.html)

[cppreference - printf](https://cplusplus.com/reference/cstdio/printf/)

[cppreference - variadic functions](https://en.cppreference.com/w/c/variadic.html)

[My own code](https://github.com/42-kblanche/printf) (reused for the mandatory part and as a base for the bonus part)

### AI usage

No AI was used to make the mandatory part.

I used AI to help me avoid pitfalls and common mistakes during the implementation of the bonuses. No code generated.

## Technical choices

To achieve the project goals, I created a basic string structure that allowed me to reallocate easily the memory necessary when appending or inserting strings.

I used a basic *if-else* parsing function to replace the different flags with their variadic equivalents - using various *type-to-ascii* functions I created.

### Technical choices - Bonus part

I used a structure to isolate flags, width, precision and specifier (length of the datatype is not taken into account)

## Example code

### hello_world.c

```c
    #include "printfft.h"

    int main(void)
    {
        ft_printf("Hello world!\n");
        return (0);
    }
```

### test.c

```c
    #include "printfft.h"

    int main(void)
    {
        ft_printf("%%%c%s%p%d%i%u%x%X%%\n", 'A', "fortytwo", 0, -42, -42, -42, -42, -42);
    }
```
