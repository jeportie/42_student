/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 03:32:38 by jeportie          #+#    #+#             */
/*   Updated: 2024/01/02 04:38:49 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    // Character 'c'
    ft_printf("Test 1 [ft_printf] - Character: %c\n", 'A');
    printf("Test 1 [printf   ] - Character: %c\n", 'A');

    // String 's' with precision
    ft_printf("Test 2 [ft_printf] - String: %.5s\n", "Hello, World!");
    printf("Test 2 [printf   ] - String: %.5s\n", "Hello, World!");

    // Null strings
    ft_printf("Test 2b [ft_printf] - Null string: %s\n", NULL);
    printf("Test 2b [printf   ] - Null string: %s\n", NULL);

    // Pointer 'p'
    void *ptr = (void *)0x12345678;
    ft_printf("Test 3 [ft_printf] - Pointer: %p\n", ptr);
    printf("Test 3 [printf   ] - Pointer: %p\n", ptr);

    // Null pointer
    ft_printf("Test 3b [ft_printf] - Null pointer: %p\n", NULL);
    printf("Test 3b [printf   ] - Null pointer: %p\n", NULL);

    // Decimal integer 'd' max and min
    ft_printf("Test 4 [ft_printf] - Max int: %d\n", INT_MAX);
    printf("Test 4 [printf   ] - Max int: %d\n", INT_MAX);

    ft_printf("Test 4b [ft_printf] - Min int: %d\n", INT_MIN);
    printf("Test 4b [printf   ] - Min int: %d\n", INT_MIN);

    // Integer 'i' positive and negative
    ft_printf("Test 5 [ft_printf] - Positive int: %i\n", 123);
    printf("Test 5 [printf   ] - Positive int: %i\n", 123);

    ft_printf("Test 5b [ft_printf] - Negative int: %i\n", -123);
    printf("Test 5b [printf   ] - Negative int: %i\n", -123);

    // Unsigned int 'u' max
    ft_printf("Test 6 [ft_printf] - Max unsigned int: %u\n", UINT_MAX);
    printf("Test 6 [printf   ] - Max unsigned int: %u\n", UINT_MAX);

    // Hexadecimal 'x' and 'X'
    ft_printf("Test 7 [ft_printf] - Hexadecimal (lowercase): %x\n", 0xABC);
    printf("Test 7 [printf   ] - Hexadecimal (lowercase): %x\n", 0xABC);

    ft_printf("Test 8 [ft_printf] - Hexadecimal (uppercase): %X\n", 0xABC);
    printf("Test 8 [printf   ] - Hexadecimal (uppercase): %X\n", 0xABC);

    // New Test 9: Simple string with padding and width
    ft_printf("Test 9 [ft_printf] - Padded and width string: %10s\n", "Pad me");
    printf("Test 9 [printf   ] - Padded and width string: %10s\n", "Pad me");

    // New Test 10: Complex formatting with multiple specifiers
    ft_printf("Test 10 [ft_printf] - Complex format: %c %u %p %x %s\n", 'Z', UINT_MAX, ptr, 0xBEEF, "Complex");
    printf("Test 10 [printf   ] - Complex format: %c %u %p %x %s\n", 'Z', UINT_MAX, ptr, 0xBEEF, "Complex");

    // Test 11: Printing a string with a precision longer than the string
    ft_printf("Test 11 [ft_printf] - Over-precision string: %.20s\n", "Short");
    printf("Test 11 [printf   ] - Over-precision string: %.20s\n", "Short");

    // Test 12: Passing a non-null terminated string (Undefined behavior)
    char non_null_terminated[5] = {'H', 'e', 'l', 'l', 'o'};
    ft_printf("Test 12 [ft_printf] - Non-null terminated: %s\n", non_null_terminated);
    printf("Test 12 [printf   ] - Non-null terminated: %s\n", non_null_terminated);

    // Test 13: Passing an invalid format specifier (Undefined behavior)
    ft_printf("Test 13 [ft_printf] - Invalid specifier: %y\n");
    printf("Test 13 [printf   ] - Invalid specifier: %y\n");

    // Test 14: Integer overflow (Undefined behavior)
    ft_printf("Test 14 [ft_printf] - Int overflow: %d\n", INT_MAX + 1);
    printf("Test 14 [printf   ] - Int overflow: %d\n", INT_MAX + 1);

    // Test 15: Integer underflow (Undefined behavior)
    ft_printf("Test 15 [ft_printf] - Int underflow: %d\n", INT_MIN - 1);
    printf("Test 15 [printf   ] - Int underflow: %d\n", INT_MIN - 1);

    // Test 16: Passing wrong type (Undefined behavior)
    ft_printf("Test 16 [ft_printf] - Wrong type for d: %d\n", "123");
    printf("Test 16 [printf   ] - Wrong type for d: %d\n", "123");

    // Test 17: Null pointer for %s (may be handled as (null) or segfault)
    ft_printf("Test 17 [ft_printf] - Null pointer for s: %s\n", (char *)NULL);
    printf("Test 17 [printf   ] - Null pointer for s: %s\n", (char *)NULL);

    // Test 18: Excessive width (may cause buffer overflow if not handled)
    //ft_printf("Test 18 [ft_printf] - Excessive width: %10000s\n", "Wide");
    //printf("Test 18 [printf   ] - Excessive width: %10000s\n", "Wide");

        // Test 19: Passing NULL for a %d specifier (may produce an error or unexpected behavior)
    ft_printf("Test 19 [ft_printf] - NULL for integer: %d\n", NULL);
    printf("Test 19 [printf   ] - NULL for integer: %d\n", NULL);

    // Test 20: Passing a floating-point number to %d (may produce an error or unexpected behavior)
    ft_printf("Test 20 [ft_printf] - Float to int: %d\n", 123.456);
    printf("Test 20 [printf   ] - Float to int: %d\n", 123.456);

    // Test 21: Excessively large width for %c (may cause buffer overflow if not handled)
    //ft_printf("Test 21 [ft_printf] - Excessive width for char: %10000c\n", 'A');
    //printf("Test 21 [printf   ] - Excessive width for char: %10000c\n", 'A');

    // Test 22: Incorrect specifier combination (e.g., using a precision specifier with %c which is typically not used)
    ft_printf("Test 22 [ft_printf] - Incorrect specifier combination: %.5c\n", 'A');
    printf("Test 22 [printf   ] - Incorrect specifier combination: %.5c\n", 'A');

    // Test 23: Using a length modifier with %c which typically doesn't require it
    ft_printf("Test 23 [ft_printf] - Length modifier with char: %lc\n", 'A');
    printf("Test 23 [printf   ] - Length modifier with char: %lc\n", 'A');

    // Test 24: Passing a string to %d (may produce an error or unexpected behavior)
    ft_printf("Test 24 [ft_printf] - String to int: %d\n", "123");
    printf("Test 24 [printf   ] - String to int: %d\n", "123");

        // Test 25: Missing argument for a specifier
    ft_printf("Test 25 [ft_printf] - Missing argument: %d\n");
    printf("Test 25 [printf   ] - Missing argument: %d\n");

    // Test 26: Invalid combination of flags
    ft_printf("Test 26 [ft_printf] - Invalid flag combo: %+ 0d\n", 42);
    printf("Test 26 [printf   ] - Invalid flag combo: %+ 0d\n", 42);

    // Test 27: Precision specifier for %p (undefined in some implementations)
    void *ptr2 = (void *)0x12345678;
    ft_printf("Test 27 [ft_printf] - Precision with pointer: %.5p\n", ptr2);
    printf("Test 27 [printf   ] - Precision with pointer: %.5p\n", ptr2);

    // Test 28: Excessively large precision (may cause buffer overflow if not handled)
    ft_printf("Test 28 [ft_printf] - Excessive precision: %.100d\n", 42);
    printf("Test 28 [printf   ] - Excessive precision: %.100d\n", 42);

    // Test 29: Unsupported length modifier
    ft_printf("Test 29 [ft_printf] - Unsupported length modifier: %jx\n", 42);
    printf("Test 29 [printf   ] - Unsupported length modifier: %jx\n", 42);

    // Test 30: Using non-existent specifiers
    ft_printf("Test 30 [ft_printf] - Non-existent specifier: %z\n");
    printf("Test 30 [printf   ] - Non-existent specifier: %z\n");

        // Test 31: Nested specifiers (undefined behavior)
    ft_printf("Test 31 [ft_printf] - Nested specifiers: %%d\n", 42);
    printf("Test 31 [printf   ] - Nested specifiers: %%d\n", 42);

    // Test 32: Incomplete specifier at the end
    ft_printf("Test 32 [ft_printf] - Incomplete specifier: %\n");
    printf("Test 32 [printf   ] - Incomplete specifier: %\n");

    // Test 33: Random symbols as flags (undefined behavior)
    ft_printf("Test 33 [ft_printf] - Random symbols as flags: %k%d\n", 42);
    printf("Test 33 [printf   ] - Random symbols as flags: %k%d\n", 42);

    // Test 34: Excessive length modifiers
    ft_printf("Test 34 [ft_printf] - Excessive length modifiers: %hhhhhhhd\n", 42);
    printf("Test 34 [printf   ] - Excessive length modifiers: %hhhhhhhd\n", 42);

    // Test 35: Conflicting flags
    ft_printf("Test 35 [ft_printf] - Conflicting flags: %+ -0d\n", 42);
    printf("Test 35 [printf   ] - Conflicting flags: %+ -0d\n", 42);

    // Test 36: Width and precision as negative numbers
    ft_printf("Test 36 [ft_printf] - Negative width and precision: %*.*d\n", -10, -5, 42);
    printf("Test 36 [printf   ] - Negative width and precision: %*.*d\n", -10, -5, 42);

    // Test 37: Mixed random characters in the format string
    ft_printf("Test 37 [ft_printf] - Random characters: %jx %d%%%s####\n", 42, 42, "test");
    printf("Test 37 [printf   ] - Random characters: %jx %d%%%s####\n", 42, 42, "test");

    // Test 38: Multiple percent signs
    ft_printf("Test 38 [ft_printf] - Multiple percent signs: %%d%%\n", 42);
    printf("Test 38 [printf   ] - Multiple percent signs: %%d%%\n", 42);

    // Test 39: Invalid specifier with valid ones
    ft_printf("Test 39 [ft_printf] - Mixed valid and invalid specifiers: %d %r %d\n", 42, 42);
    printf("Test 39 [printf   ] - Mixed valid and invalid specifiers: %d %r %d\n", 42, 42);

    // Test 40: Reversed specifiers (should be ignored or treated as literals)
    ft_printf("Test 40 [ft_printf] - Reversed specifiers: d%\n");
    printf("Test 40 [printf   ] - Reversed specifiers: d%\n");

    return 0;
}

