/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 03:32:38 by jeportie          #+#    #+#             */
/*   Updated: 2024/01/03 18:07:56 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    char *sample = "Sample String";
    void *ptr = (void *)0x12345000;
    void *ptr2 = (void *)0x12345015;
    void *ptr3 = (void *)0x12345678;
    unsigned int hexValue = 0xABCD;
    char c = 'A';
    char *s = "Test string";
    void *p = (void *)0x12345678;
    int i = -42;
    unsigned int u = 42;

    unsigned int x = 0xABC;
    unsigned int X = 0xABC;
    char non_null_terminated[5] = {'H', 'e', 'l', 'l', 'o'};
    long long large_num = LLONG_MAX;
    char long_string[128];
    int d = 42;
    ft_printf("SIMPLE SPECIFIER TEST:\n\n");

    // %c Tests
    ft_printf("Test 01 [ft_printf] - Simple character: %c\n", 'A');
    printf("Test 01 [printf   ] - Simple character: %c\n", 'A');
    ft_printf("Test 02 [ft_printf] - Non-printable char (bell): %c\n", 7); // ASCII Bell
    printf("Test 02 [printf   ] - Non-printable char (bell): %c\n", 7); // ASCII Bell
    ft_printf("Test 03 [ft_printf] - Newtab character (tab): %c\t\n", '\t');
    printf("Test 03 [printf   ] - Newtab character (tab): %c\t\n", '\t');

    // %s Tests
    ft_printf("Test 04 [ft_printf] - Simple string: %s\n", "Hello World");
    printf("Test 04 [printf   ] - Simple string: %s\n", "Hello World");
    ft_printf("Test 05 [ft_printf] - Null string: %s\n", (char *)NULL);
    printf("Test 05 [printf   ] - Null string: %s\n", (char *)NULL);
    char *escape_string = "Hello\tWorld\tTabbed!";
    ft_printf("Test 06 [ft_printf] - String with escapes: %s\n", escape_string);
    printf("Test 06 [printf   ] - String with escapes: %s\n", escape_string);
    ft_memset(long_string, 'A', 128);
    ft_printf("Test 07 [ft_printf] - Long string: %s\n", long_string);
    printf("Test 07 [printf   ] - Long string: %s\n", long_string);

    // %p Tests
    void *p2 = &d; // assuming d is defined earlier as an int
    ft_printf("Test 08 [ft_printf] - Simple pointer: %p\n", p2);
    printf("Test 08 [printf   ] - Simple pointer: %p\n", p2);
    ft_printf("Test 09 [ft_printf] - Null pointer: %p\n", NULL);
    printf("Test 09 [printf   ] - Null pointer: %p\n", NULL);
    int (*func_ptr)(int) = &ft_isalnum; // Using 'main' just as an example function
    ft_printf("Test 10 [ft_printf] - Function pointer: %p\n", func_ptr);
    printf("Test 10 [printf   ] - Function pointer: %p\n", func_ptr);

    // %d Tests
    ft_printf("Test 11 [ft_printf] - Simple integer (d): %d\n", d);
    printf("Test 11 [printf   ] - Simple integer (d): %d\n", d);
    ft_printf("Test 12 [ft_printf] - Maximum int (d): %d\n", INT_MAX);
    printf("Test 12 [printf   ] - Maximum int (d): %d\n", INT_MAX);
    ft_printf("Test 13 [ft_printf] - Minimum int (d): %d\n", INT_MIN);
    printf("Test 13 [printf   ] - Minimum int (d): %d\n", INT_MIN);
    ft_printf("Test 14 [ft_printf] - Negative zero (d): %d\n", -0);
    printf("Test 14 [printf   ] - Negative zero (d): %d\n", -0);

    // %i Tests
    ft_printf("Test 15 [ft_printf] - Simple integer (i): %i\n", i);
    printf("Test 15 [printf   ] - Simple integer (i): %i\n", i);
    ft_printf("Test 16 [ft_printf] - Positive int: %i\n", 123);
    printf("Test 16 [printf   ] - Positive int: %i\n", 123);
    ft_printf("Test 17 [ft_printf] - Negative int: %i\n", -123);
    printf("Test 17 [printf   ] - Negative int: %i\n", -123);

    // %u Tests
    ft_printf("Test 18 [ft_printf] - Simple unsigned integer (u): %u\n", u);
    printf("Test 18 [printf   ] - Simple unsigned integer (u): %u\n", u);
    ft_printf("Test 19 [ft_printf] - Maximum unsigned int: %u\n", UINT_MAX);
    printf("Test 19 [printf   ] - Maximum unsigned int: %u\n", UINT_MAX);
    ft_printf("Test 20 [ft_printf] - Negative value as unsigned (u): %u\n", -42);
    printf("Test 20 [printf   ] - Negative value as unsigned (u): %u\n", -42);

    // %x Tests
    ft_printf("Test 21 [ft_printf] - Simple hexadecimal (x): %x\n", x);
    printf("Test 21 [printf   ] - Simple hexadecimal (x): %x\n", x);
    ft_printf("Test 22 [ft_printf] - Zero as hex (x): %x\n", 0);
    printf("Test 22 [printf   ] - Zero as hex (x): %x\n", 0);
    ft_printf("Test 23 [ft_printf] - Max unsigned int as hex (x): %x\n", UINT_MAX);
    printf("Test 23 [printf   ] - Max unsigned int as hex (x): %x\n", UINT_MAX);

    // %X Tests
    ft_printf("Test 24 [ft_printf] - Simple hexadecimal (X): %X\n", X);
    printf("Test 24 [printf   ] - Simple hexadecimal (X): %X\n", X);
    ft_printf("Test 25 [ft_printf] - Zero as hex (X): %X\n", 0);
    printf("Test 25 [printf   ] - Zero as hex (X): %X\n", 0);
    ft_printf("Test 26 [ft_printf] - Max unsigned int as hex (X): %X\n", UINT_MAX);
    printf("Test 26 [printf   ] - Max unsigned int as hex (X): %X\n", UINT_MAX);

    // %% Test
    ft_printf("Test 27 [ft_printf] - Single percent sign (%%): %%\n");
    printf("Test 27 [printf   ] - Single percent sign (%%): %%\n");

    ft_printf("\nMULTIPLE SPECIFIER TEST:\n\n");

    int ftlen, clen;
    // Test 33: Multiple specifiers - %d and %s
    ftlen = ft_printf("Test 33 [ft_printf] - Integer and String: %d, %s\n", 42, "Hello");
    clen = printf("Test 33 [printf   ] - Integer and String: %d, %s\n", 42, "Hello");
    // Test 34: Multiple specifiers - %c and %x
    ftlen = ft_printf("Test 34 [ft_printf] - Char and Hex: %c, %x\n", 'A', 255);
    clen = printf("Test 34 [printf   ] - Char and Hex: %c, %x\n", 'A', 255);
    // Test 35: Multiple specifiers - %p and %u
    ftlen = ft_printf("Test 35 [ft_printf] - Pointer and Unsigned Int: %p, %u\n", &large_num, 1000);
    clen = printf("Test 35 [printf   ] - Pointer and Unsigned Int: %p, %u\n", &large_num, 1000);
    // Test 36: Multiple specifiers - %i and %X
    ftlen = ft_printf("Test 36 [ft_printf] - Int and Hex Uppercase: %i, %X\n", -42, 255);
    clen = printf("Test 36 [printf   ] - Int and Hex Uppercase: %i, %X\n", -42, 255);
    // Test 37: Multiple specifiers - %s, %c, and %d
    ftlen = ft_printf("Test 37 [ft_printf] - String, Char, and Int: %s, %c, %d\n", "Test", 'B', 123);
    clen = printf("Test 37 [printf   ] - String, Char, and Int: %s, %c, %d\n", "Test", 'B', 123);
    // Test 38: Multiple specifiers - %u and %s
    ftlen = ft_printf("Test 38 [ft_printf] - Unsigned and String: %u, %s\n", UINT_MAX, "Max Unsigned");
    clen = printf("Test 38 [printf   ] - Unsigned and String: %u, %s\n", UINT_MAX, "Max Unsigned");
    // Test 39: Multiple specifiers - %c and %p
    ftlen = ft_printf("Test 39 [ft_printf] - Char and Pointer: %c, %p\n", 'C', &s);
    clen = printf("Test 39 [printf   ] - Char and Pointer: %c, %p\n", 'C', &s);
    // Test 40: Multiple specifiers - %d and %x
    ftlen = ft_printf("Test 40 [ft_printf] - Int and Hex: %d, %x\n", INT_MIN, 0xABCDEF);
    clen = printf("Test 40 [printf   ] - Int and Hex: %d, %x\n", INT_MIN, 0xABCDEF);
    // Test 41: Multiple specifiers - %s and %X
    ftlen = ft_printf("Test 41 [ft_printf] - String and Hex Uppercase: %s, %X\n", "Hex", 0xBEEF);
    clen = printf("Test 41 [printf   ] - String and Hex Uppercase: %s, %X\n", "Hex", 0xBEEF);
    // Test 42: Multiple specifiers - %p, %d, and %c
    ftlen = ft_printf("Test 42 [ft_printf] - Pointer, Int, and Char: %p, %d, %c\n", p, -100, 'D');
    clen = printf("Test 42 [printf   ] - Pointer, Int, and Char: %p, %d, %c\n", p, -100, 'D');
    // Test 43: Complex format - %s, %d, %c, and %x
    ftlen = ft_printf("Test 43 [ft_printf] - Complex format: %s, %d, %c, %x\n", "Complex", 42, 'E', 0xFADE);
    clen = printf("Test 43 [printf   ] - Complex format: %s, %d, %c, %x\n", "Complex", 42, 'E', 0xFADE);
    // Test 44: Complex format - %X, %u, and %s
    ftlen = ft_printf("Test 44 [ft_printf] - Complex format: %X, %u, %s\n", 0xABCD, 9999, "String");
    clen = printf("Test 44 [printf   ] - Complex format: %X, %u, %s\n", 0xABCD, 9999, "String");
    // Test 45: Complex format - %p, %i, %c, and %s
    ftlen = ft_printf("Test 45 [ft_printf] - Complex format: %p, %i, %c, %s\n", &i, -12345, 'F', "Pointer");
    clen = printf("Test 45 [printf   ] - Complex format: %p, %i, %c, %s\n", &i, -12345, 'F', "Pointer");
    // Test 46: Complex format - %d, %X, %s, and %c
    ftlen = ft_printf("Test 46 [ft_printf] - Complex format: %d, %X, %s, %c\n", 1000, 0xBEEF, "Hex", 'G');
    clen = printf("Test 46 [printf   ] - Complex format: %d, %X, %s, %c\n", 1000, 0xBEEF, "Hex", 'G');
    // Test 47: Complex format - %u, %p, %s, and %x
    ftlen = ft_printf("Test 47 [ft_printf] - Complex format: %u, %p, %s, %x\n", UINT_MAX, p, "Unsigned", 0x1234);
    clen = printf("Test 47 [printf   ] - Complex format: %u, %p, %s, %x\n", UINT_MAX, p, "Unsigned", 0x1234);
    // Test 48: Complex format - Multiple %s specifiers
    ftlen = ft_printf("Test 48 [ft_printf] - Multiple strings: %s, %s, %s\n", "One", "Two", "Three");
    clen = printf("Test 48 [printf   ] - Multiple strings: %s, %s, %s\n", "One", "Two", "Three");
    // Test 49: Complex format - Multiple %d specifiers
    ftlen = ft_printf("Test 49 [ft_printf] - Multiple integers: %d, %d, %d\n", -1, 0, 1);
    clen = printf("Test 49 [printf   ] - Multiple integers: %d, %d, %d\n", -1, 0, 1);
    // Test 50: Complex format - Multiple %x specifiers
    ftlen = ft_printf("Test 50 [ft_printf] - Multiple hex: %x, %x, %x\n", 0xABC, 0xDEF, 0x123);
    clen = printf("Test 50 [printf   ] - Multiple hex: %x, %x, %x\n", 0xABC, 0xDEF, 0x123);
    // Test 51: Complex format - Multiple %p specifiers
    void *ptrA = &i, *ptrB = &u, *ptrC = &x;
    ftlen = ft_printf("Test 51 [ft_printf] - Multiple pointers: %p, %p, %p\n", ptrA, ptrB, ptrC);
    clen = printf("Test 51 [printf   ] - Multiple pointers: %p, %p, %p\n", ptrA, ptrB, ptrC);
    // Test 52: Complex format - Mixed specifiers
    ftlen = ft_printf("Test 52 [ft_printf] - Mixed specifiers: %d, %x, %s, %c, %p, %u\n", INT_MIN, 0xFFFF, "Mixed", 'H', &ftlen, 500);
    clen = printf("Test 52 [printf   ] - Mixed specifiers: %d, %x, %s, %c, %p, %u\n", INT_MIN, 0xFFFF, "Mixed", 'H', &ftlen, 500);
    // New Test 53: Complex formatting with multiple specifiers
    ft_printf("Test 53 [ft_printf] - Complex format: %c %u %p %x %s\n", 'Z', UINT_MAX, ptr, 0xBEEF, "Complex");
    printf("Test 53 [printf   ] - Complex format: %c %u %p %x %s\n", 'Z', UINT_MAX, ptr, 0xBEEF, "Complex");
        // Test 54: Nested specifiers (undefined behavior)
    ft_printf("Test 54 [ft_printf] - Nested specifiers: %%d\n", 42);
    printf("Test 54 [printf   ] - Nested specifiers: %%d\n", 42);
    // Test 55: Random symbols as flags (undefined behavior)
    ft_printf("Test 55 [ft_printf] - Random symbols as flags: %k%d\n", 42);
    printf("Test 55 [printf   ] - Random symbols as flags: %k%d\n", 42);





    ft_printf("\n FLAG TEST:\n\n");

    // String 's' with precision
    ft_printf("Test 02 [ft_printf] - String: %.5s\n", "Hello, World!");
    printf("Test 02 [printf   ] - String: %.5s\n", "Hello, World!");
    // New Test 9: Simple string with padding and width
    ft_printf("Test 09 [ft_printf] - Padded and width string: %10s\n", "Pad me");
    printf("Test 09 [printf   ] - Padded and width string: %10s\n", "Pad me");
    // Test 11: Printing a string with a precision longer than the string
    ft_printf("Test 11 [ft_printf] - Over-precision string: %.20s\n", "Short");
    printf("Test 11 [printf   ] - Over-precision string: %.20s\n", "Short");
    //Test 18: Excessive width (may cause buffer overflow if not handled)
    ft_printf("Test 18 [ft_printf] - Excessive width: %150s\n", "Wide");
    printf("Test 18 [printf   ] - Excessive width: %150s\n", "Wide");
    // Test 21: Excessively large width for %c (may cause buffer overflow if not handled)
    ft_printf("Test 21 [ft_printf] - Excessive width for char: %100c\n", 'A');
    printf("Test 21 [printf   ] - Excessive width for char: %100c\n", 'A');
    // Test 26: Invalid combination of flags
    ft_printf("Test 26 [ft_printf] - Invalid flag combo: %+ 0d\n", 42);
    printf("Test 26 [printf   ] - Invalid flag combo: %+ 0d\n", 42);
    // Test 28: Excessively large precision (may cause buffer overflow if not handled)
    ft_printf("Test 28 [ft_printf] - Excessive precision: %.100s\n", "abcdefghijklmnopqrstuvwxyz0123456789 0 1 2 3 4 5 6 7 8 9 ");
    printf("Test 28 [printf   ] - Excessive precision: %.100s\n", "abcdefghijklmnopqrstuvwxyz0123456789 0 1 2 3 4 5 6 7 8 9 ");
    // Test 35: Conflicting flags
    ft_printf("Test 35 [ft_printf] - Conflicting flags: %+ -0d\n", 42);
    printf("Test 35 [printf   ] - Conflicting flags: %+ -0d\n", 42);
    // Test 36: Width and precision as negative numbers
    ft_printf("Test 36 [ft_printf] - Negative width and precision: %*.*d\n", -10, -5, 42);
    printf("Test 36 [printf   ] - Negative width and precision: %*.*d\n", -10, -5, 42);
    // Test 37: Mixed random characters in the format string
    ft_printf("Test 37 [ft_printf] - Random characters: %jx %d%%%s####\n", 42, 42, "test");
    printf("Test 37 [printf   ] - Random characters: %jx %d%%%s####\n", 42, 42, "test");
    // Test 39: Invalid specifier with valid ones
    ft_printf("Test 39 [ft_printf] - Mixed valid and invalid specifiers: %d %r %d\n", 42, 42);
    printf("Test 39 [printf   ] - Mixed valid and invalid specifiers: %d %r %d\n", 42, 42);
    // Test 42: Left-justified character with width
    ft_printf("Test 42 [ft_printf] - Left-justified with width: %-5c\n", 'B');
    printf("Test 42 [printf   ] - Left-justified with width: %-5c\n", 'B');
    // Test 43: Right-justified character with width
    ft_printf("Test 43 [ft_printf] - Right-justified with width: %5c\n", 'C');
    printf("Test 43 [printf   ] - Right-justified with width: %5c\n", 'C');
    // Test 44: Character with zero flag (not typically permitted)
    ft_printf("Test 44 [ft_printf] - Zero flag (not permitted): %0c\n", 'D');
    printf("Test 44 [printf   ] - Zero flag (not permitted): %0c\n", 'D');
    // Test 52: Left-justified string with width
    ft_printf("Test 52 [ft_printf] - Left-justified with width: %-20s\n", sample);
    printf("Test 52 [printf   ] - Left-justified with width: %-20s\n", sample);
    // Test 53: Right-justified string with width
    ft_printf("Test 53 [ft_printf] - Right-justified with width: %20s\n", sample);
    printf("Test 53 [printf   ] - Right-justified with width: %20s\n", sample);
    // Test 54: String with precision
    ft_printf("Test 54 [ft_printf] - Precision: %.5s\n", sample);
    printf("Test 54 [printf   ] - Precision: %.5s\n", sample);
    // Test 62: Left-justified pointer with width
    ft_printf("Test 62 [ft_printf] - Left-justified with width: %-20p\n", ptr3);
    printf("Test 62 [printf   ] - Left-justified with width: %-20p\n", ptr3);
    // Test 63: Right-justified pointer with width
    ft_printf("Test 63 [ft_printf] - Right-justified with width: %20p\n", ptr3);
    printf("Test 63 [printf   ] - Right-justified with width: %20p\n", ptr3);
    // Test 64: Pointer with zero flag (not typically permitted)
    ft_printf("Test 64 [ft_printf] - Zero flag (not permitted): %0p\n", ptr3);
    printf("Test 64 [printf   ] - Zero flag (not permitted): %0p\n", ptr3);
    // Test 74: Integer with left padding %d
    ft_printf("Test 74 [ft_printf] - Integer with left padding: %-10d\n", 42);
    printf("Test 74 [printf   ] - Integer with left padding: %-10d\n", 42);
    // Test 75: Integer with zero padding %d
    ft_printf("Test 75 [ft_printf] - Integer with zero padding: %010d\n", -42);
    printf("Test 75 [printf   ] - Integer with zero padding: %010d\n", -42);
    // Test 76: Integer with space flag %d
    ft_printf("Test 76 [ft_printf] - Integer with space flag: % d\n", 42);
    printf("Test 76 [printf   ] - Integer with space flag: % d\n", 42);
    // Test 77: Integer with plus flag %d
    ft_printf("Test 77 [ft_printf] - Integer with plus flag: %+d\n", -42);
    printf("Test 77 [printf   ] - Integer with plus flag: %+d\n", -42);
    // Test 78: Unsigned integer with precision %u
    ft_printf("Test 78 [ft_printf] - Unsigned integer with precision: %.5u\n", 42);
    printf("Test 78 [printf   ] - Unsigned integer with precision: %.5u\n", 42);
    // Test 83: Integer with invalid flag combination %d
    ft_printf("Test 83 [ft_printf] - Invalid flag combo: %-+0 d\n", 42);
    printf("Test 83 [printf   ] - Invalid flag combo: %-+0 d\n", 42);
    // Test 89: Integer with random characters in format string
    ft_printf("Test 89 [ft_printf] - Random characters: %d###\n", 42);
    printf("Test 89 [printf   ] - Random characters: %d###\n", 42);
    // Test 93: Hexadecimal %x with hash flag
    ft_printf("Test 93 [ft_printf] - Hexadecimal with hash (x): %#x\n", hexValue);
    printf("Test 93 [printf   ] - Hexadecimal with hash (x): %#x\n", hexValue);
    // Test 94: Hexadecimal %X with hash flag
    ft_printf("Test 94 [ft_printf] - Hexadecimal with hash (X): %#X\n", hexValue);
    printf("Test 94 [printf   ] - Hexadecimal with hash (X): %#X\n", hexValue);
    // Test 95: Hexadecimal %x with zero padding
    ft_printf("Test 95 [ft_printf] - Hexadecimal with zero padding (x): %010x\n", hexValue);
    printf("Test 95 [printf   ] - Hexadecimal with zero padding (x): %010x\n", hexValue);
    // Test 96: Hexadecimal %X with zero padding
    ft_printf("Test 96 [ft_printf] - Hexadecimal with zero padding (X): %010X\n", hexValue);
    printf("Test 96 [printf   ] - Hexadecimal with zero padding (X): %010X\n", hexValue);
    // Test 97: Hexadecimal %x with width
    ft_printf("Test 97 [ft_printf] - Hexadecimal with width (x): %15x\n", hexValue);
    printf("Test 97 [printf   ] - Hexadecimal with width (x): %15x\n", hexValue);
    // Test 98: Hexadecimal %X with width
    ft_printf("Test 98 [ft_printf] - Hexadecimal with width (X): %15X\n", hexValue);
    printf("Test 98 [printf   ] - Hexadecimal with width (X): %15X\n", hexValue);
    // Test 99: Hexadecimal %x with left-justified
    ft_printf("Test 99 [ft_printf] - Left-justified hexadecimal (x): %-15x\n", hexValue);
    printf("Test 99 [printf   ] - Left-justified hexadecimal (x): %-15x\n", hexValue);
    // Test 100: Hexadecimal %X with left-justified
    ft_printf("Test 100 [ft_printf] - Left-justified hexadecimal (X): %-15X\n", hexValue);
    printf("Test 100 [printf   ] - Left-justified hexadecimal (X): %-15X\n", hexValue);
    // Test 103: Hexadecimal %x with precision
    ft_printf("Test 103 [ft_printf] - Hexadecimal with precision (x): %.5x\n", hexValue);
    printf("Test 103 [printf   ] - Hexadecimal with precision (x): %.5x\n", hexValue);
    // Test 104: Hexadecimal %X with precision
    ft_printf("Test 104 [ft_printf] - Hexadecimal with precision (X): %.5X\n", hexValue);
    printf("Test 104 [printf   ] - Hexadecimal with precision (X): %.5X\n", hexValue);





    ft_printf("\n INVALID FORMAT AND ERROR MESSAGES TEST:\n\n");


    // Test 13: Passing an invalid format specifier (Undefined behavior)
    ft_printf("Test 13 [ft_printf] - Invalid specifier: %y\n");
    printf("Test 13 [printf   ] - Invalid specifier: %y\n");
    // Test 22: Incorrect specifier combination (e.g., using a precision specifier with %c which is typically not used)
    ft_printf("Test 22 [ft_printf] - Incorrect specifier combination: %.5c\n", 'A');
    printf("Test 22 [printf   ] - Incorrect specifier combination: %.5c\n", 'A');
    // Test 27: Precision specifier for %p (undefined in some implementations)
    ft_printf("Test 27 [ft_printf] - Precision with pointer: %.5p\n", ptr2);
    printf("Test 27 [printf   ] - Precision with pointer: %.5p\n", ptr2);
    // Test 30: Using non-existent specifiers
    ft_printf("Test 30 [ft_printf] - Non-existent specifier: %z\n");
    printf("Test 30 [printf   ] - Non-existent specifier: %z\n");
    // Test 32: Incomplete specifier at the end
    ft_printf("Test 32 [ft_printf] - Incomplete specifier: %\n");
    printf("Test 32 [printf   ] - Incomplete specifier: %\n");
    // Test 38: Multiple percent signs
    ft_printf("Test 38 [ft_printf] - Multiple percent signs: %%d%%\n", 42);
    printf("Test 38 [printf   ] - Multiple percent signs: %%d%%\n", 42);
    // Test 40: Reversed specifiers (should be ignored or treated as literals)
    ft_printf("Test 40 [ft_printf] - Reversed specifiers: d%\n");
    printf("Test 40 [printf   ] - Reversed specifiers: d%\n");
    // Test 45: Character with plus flag (not typically permitted)
    ft_printf("Test 45 [ft_printf] - Plus flag (not permitted): %+c\n", 'E');
    printf("Test 45 [printf   ] - Plus flag (not permitted): %+c\n", 'E');
    // Test 46: Character with space flag (not typically permitted)
    ft_printf("Test 46 [ft_printf] - Space flag (not permitted): % c\n", 'F');
    printf("Test 46 [printf   ] - Space flag (not permitted): % c\n", 'F');
    // Test 47: Character with hash flag (not typically permitted)
    ft_printf("Test 47 [ft_printf] - Hash flag (not permitted): %#c\n", 'G');
    printf("Test 47 [printf   ] - Hash flag (not permitted): %#c\n", 'G');
    // Test 48: Character with precision (not typically permitted)
    ft_printf("Test 48 [ft_printf] - Precision (not permitted): %.2c\n", 'H');
    printf("Test 48 [printf   ] - Precision (not permitted): %.2c\n", 'H');
    // Test 50: Character with invalid flag combination
    ft_printf("Test 50 [ft_printf] - Invalid flag combo: %-+ c\n", 'J');
    printf("Test 50 [printf   ] - Invalid flag combo: %-+ c\n", 'J');
    // Test 55: String with zero flag (not typically permitted)
    ft_printf("Test 55 [ft_printf] - Zero flag (not permitted): %0s\n", sample);
    printf("Test 55 [printf   ] - Zero flag (not permitted): %0s\n", sample);
    // Test 56: String with plus flag (not typically permitted)
    ft_printf("Test 56 [ft_printf] - Plus flag (not permitted): %+s\n", sample);
    printf("Test 56 [printf   ] - Plus flag (not permitted): %+s\n", sample);
    // Test 57: String with space flag (not typically permitted)
    ft_printf("Test 57 [ft_printf] - Space flag (not permitted): % s\n", sample);
    printf("Test 57 [printf   ] - Space flag (not permitted): % s\n", sample);
    // Test 58: String with hash flag (not typically permitted)
    ft_printf("Test 58 [ft_printf] - Hash flag (not permitted): %#s\n", sample);
    printf("Test 58 [printf   ] - Hash flag (not permitted): %#s\n", sample);
    // Test 59: String with length modifier (not typically permitted)
    ft_printf("Test 59 [ft_printf] - Length modifier (not permitted): %ls\n", sample);
    printf("Test 59 [printf   ] - Length modifier (not permitted): %ls\n", sample);
    // Test 60: String with invalid flag combination
    ft_printf("Test 60 [ft_printf] - Invalid flag combo: %-+ s\n", sample);
    printf("Test 60 [printf   ] - Invalid flag combo: %-+ s\n", sample);
    // Test 65: Pointer with plus flag (not typically permitted)
    ft_printf("Test 65 [ft_printf] - Plus flag (not permitted): %+p\n", ptr3);
    printf("Test 65 [printf   ] - Plus flag (not permitted): %+p\n", ptr3);
    // Test 66: Pointer with space flag (not typically permitted)
    ft_printf("Test 66 [ft_printf] - Space flag (not permitted): % p\n", ptr3);
    printf("Test 66 [printf   ] - Space flag (not permitted): % p\n", ptr3);
    // Test 67: Pointer with hash flag (not typically permitted)
    ft_printf("Test 67 [ft_printf] - Hash flag (not permitted): %#p\n", ptr3);
    printf("Test 67 [printf   ] - Hash flag (not permitted): %#p\n", ptr3);
    // Test 68: Pointer with precision (not typically permitted)
    ft_printf("Test 68 [ft_printf] - Precision (not permitted): %.5p\n", ptr3);
    printf("Test 68 [printf   ] - Precision (not permitted): %.5p\n", ptr3);
    // Test 69: Pointer with length modifier (not typically permitted)
    ft_printf("Test 69 [ft_printf] - Length modifier (not permitted): %lp\n", ptr3);
    printf("Test 69 [printf   ] - Length modifier (not permitted): %lp\n", ptr3);
    // Test 70: Pointer with invalid flag combination
    ft_printf("Test 70 [ft_printf] - Invalid flag combo: %-+ p\n", ptr3);
    printf("Test 70 [printf   ] - Invalid flag combo: %-+ p\n", ptr3);
    // Test 79: Integer with hash flag %d (not typically permitted)
    ft_printf("Test 79 [ft_printf] - Integer with hash flag (not permitted): %#d\n", 42);
    printf("Test 79 [printf   ] - Integer with hash flag (not permitted): %#d\n", 42);
    // Test 85: Integer with non-existent specifier %w (should fail or be ignored)
    ft_printf("Test 85 [ft_printf] - Non-existent specifier: %w\n", 42);
    printf("Test 85 [printf   ] - Non-existent specifier: %w\n", 42);
    // Test 86: Integer with excessive length modifiers %hhhhhd
    ft_printf("Test 86 [ft_printf] - Excessive length modifiers: %hhhhhhhd\n", 42);
    printf("Test 86 [printf   ] - Excessive length modifiers: %hhhhhhhd\n", 42);
    // Test 87: Integer with mixed valid and invalid flags %d
    ft_printf("Test 87 [ft_printf] - Mixed valid and invalid flags: %0+- 5d\n", 42);
    printf("Test 87 [printf   ] - Mixed valid and invalid flags: %0+- 5d\n", 42);
    // Test 88: Integer with reversed specifiers %d%
    ft_printf("Test 88 [ft_printf] - Reversed specifiers: d%\n");
    printf("Test 88 [printf   ] - Reversed specifiers: d%\n");
    // Test 90: Integer %d with all non-permitted flags
    ft_printf("Test 90 [ft_printf] - All non-permitted flags: %0#+ d\n", 42);
    printf("Test 90 [printf   ] - All non-permitted flags: %0#+ d\n", 42);
   // Test 101: Hexadecimal %x with plus flag (not typically permitted)
    ft_printf("Test 101 [ft_printf] - Hexadecimal with plus (not permitted) (x): %+x\n", hexValue);
    printf("Test 101 [printf   ] - Hexadecimal with plus (not permitted) (x): %+x\n", hexValue);
    // Test 102: Hexadecimal %X with space flag (not typically permitted)
    ft_printf("Test 102 [ft_printf] - Hexadecimal with space (not permitted) (X): % X\n", hexValue);
    printf("Test 102 [printf   ] - Hexadecimal with space (not permitted) (X): % X\n", hexValue);
    // Test 105: Percent sign %%
    ft_printf("Test 105 [ft_printf] - Percent sign: %%\n");
    printf("Test 105 [printf   ] - Percent sign: %%\n");
    // Test 106: Percent sign with width %%
    ft_printf("Test 106 [ft_printf] - Percent sign with width: %5%\n");
    printf("Test 106 [printf   ] - Percent sign with width: %5%\n");
    // Test 107: Percent sign with left-justified %%
    ft_printf("Test 107 [ft_printf] - Percent sign left-justified: %-5%\n");
    printf("Test 107 [printf   ] - Percent sign left-justified: %-5%\n");
    // Test 108: Percent sign with invalid flag %%
    ft_printf("Test 108 [ft_printf] - Invalid flag with percent: %+#%\n");
    printf("Test 108 [printf   ] - Invalid flag with percent: %+#%\n");
    // Test 109: Percent sign with zero padding %%
    ft_printf("Test 109 [ft_printf] - Zero padding with percent: %05%\n");
    printf("Test 109 [printf   ] - Zero padding with percent: %05%\n");
    // Test 110: Multiple percent signs %%
    ft_printf("Test 110 [ft_printf] - Multiple percent signs: %% %% %%\n");
    printf("Test 110 [printf   ] - Multiple percent signs: %% %% %%\n");
    // Test 119: Percent sign %%
    ft_printf("Test 119 [ft_printf] - Percent sign: %%\n");
    printf("Test 119 [printf   ] - Percent sign: %%\n");
    // Test 22: %i with a large number (beyond int range) to check behavior
    ftlen = ft_printf("Test 22 [ft_printf] - Large number (i): %i\n", 21474836470);
    clen = printf("Test 22 [printf   ] - Large number (i): %i\n", 21474836470);
    // Test 23: %i with a number just above INT_MAX (to see if it wraps around correctly)
    ftlen = ft_printf("Test 23 [ft_printf] - Above max int (i): %i\n", INT_MAX + 1);
    clen = printf("Test 23 [printf   ] - Above max int (i): %i\n", INT_MAX + 1);
    // Test 24: %i with a number just below INT_MIN (to see if it wraps around correctly)
    ftlen = ft_printf("Test 24 [ft_printf] - Below min int (i): %i\n", INT_MIN - 1);
    clen = printf("Test 24 [printf   ] - Below min int (i): %i\n", INT_MIN - 1);
    // Test 32: %d with a very large number (long long max for instance)
    ftlen = ft_printf("Test 32 [ft_printf] - Very large number (d): %d\n", large_num);
    clen = printf("Test 32 [printf   ] - Very large number (d): %d\n", large_num);
  // Test 14: Integer overflow (Undefined behavior)
    ft_printf("Test 14 [ft_printf] - Int overflow: %d\n", INT_MAX + 1);
    printf("Test 14 [printf   ] - Int overflow: %d\n", INT_MAX + 1);
    // Test 15: Integer underflow (Undefined behavior)
    ft_printf("Test 15 [ft_printf] - Int underflow: %d\n", INT_MIN - 1);
    printf("Test 15 [printf   ] - Int underflow: %d\n", INT_MIN - 1);
    // Test 16: Passing wrong type (Undefined behavior)
    ft_printf("Test 16 [ft_printf] - Wrong type for d: %d\n", "123");
    printf("Test 16 [printf   ] - Wrong type for d: %d\n", "123");
    // Test 19: Passing NULL for a %d specifier (may produce an error or unexpected behavior)
    ft_printf("Test 19 [ft_printf] - NULL for integer: %d\n", NULL);
    printf("Test 19 [printf   ] - NULL for integer: %d\n", NULL);
    // Test 20: Passing a floating-point number to %d (may produce an error or unexpected behavior)
    ft_printf("Test 20 [ft_printf] - Float to int: %d\n", 123.456);
    printf("Test 20 [printf   ] - Float to int: %d\n", 123.456);
    // Test 24: Passing a string to %d (may produce an error or unexpected behavior)
    ft_printf("Test 24 [ft_printf] - String to int: %d\n", "123");
    printf("Test 24 [printf   ] - String to int: %d\n", "123");
        // Test 25: Missing argument for a specifier
    ft_printf("Test 25 [ft_printf] - Missing argument: %d\n");
    printf("Test 25 [printf   ] - Missing argument: %d\n");
    // Test 84: Negative unsigned integer %u (undefined behavior)
    ft_printf("Test 84 [ft_printf] - Negative unsigned integer (undefined): %u\n", -42);
    printf("Test 84 [printf   ] - Negative unsigned integer (undefined): %u\n", -42);

    return 0;
}

