/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 03:32:38 by jeportie          #+#    #+#             */
/*   Updated: 2024/01/12 22:46:25 by jeportie         ###   ########.fr       */
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
    void *p = (void *)0x12345678;
    int i = -42;
    unsigned int u = 42;

    unsigned int x = 0xABC;
    unsigned int X = 0xABC;
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


    // Test 28: Multiple specifiers - %c, %s, and %d
    ft_printf("Test 28 [ft_printf] - Char, String, and Int: %c, %s, %d\n", 'H', "world", 42);
    printf("Test 28 [printf   ] - Char, String, and Int: %c, %s, %d\n", 'H', "world", 42);
    // Test 29: Multiple specifiers - %x, %u, and %s
    ft_printf("Test 29 [ft_printf] - Hex, Unsigned, and String: %x, %u, %s\n", 0xABCD, 12345, "Test");
    printf("Test 29 [printf   ] - Hex, Unsigned, and String: %x, %u, %s\n", 0xABCD, 12345, "Test");
    // Test 30: Multiple specifiers - %p, %i, and %c
    void *ptr4 = &d;
    ft_printf("Test 30 [ft_printf] - Pointer, Int, and Char: %p, %i, %c\n", ptr4, -123, 'A');
    printf("Test 30 [printf   ] - Pointer, Int, and Char: %p, %i, %c\n", ptr4, -123, 'A');



    // Test 31: Multiple specifiers - %d, %X, %s, and %c
    ft_printf("Test 31 [ft_printf] - Int, Hex Uppercase, String, and Char: %d, %s, %c\n", 1000, "Hex", 'B');
    printf("Test 31 [printf   ] - Int, Hex Uppercase, String, and Char: %d, %X, %s, %c\n", 1000, 0xBEEF, "Hex", 'B');

    // Test 31: Multiple specifiers - %d, %X, %s, and %c
    ft_printf("Test 31 [ft_printf] - Int, Hex Uppercase, String, and Char: %d, %X, %s, %c\n", 1000, 0xBEEF, "Hex", 'B');
    printf("Test 31 [printf   ] - Int, Hex Uppercase, String, and Char: %d, %X, %s, %c\n", 1000, 0xBEEF, "Hex", 'B');


    // Test 32: Multiple specifiers - %u, %p, %s, and %x
    ft_printf("Test 32 [ft_printf] - Unsigned, Pointer, String, and Hex: %u, %p, %s, %x\n", UINT_MAX, p, "Unsigned", 0x1234);
    printf("Test 32 [printf   ] - Unsigned, Pointer, String, and Hex: %u, %p, %s, %x\n", UINT_MAX, p, "Unsigned", 0x1234);
    // Test 33: Multiple specifiers - Mixed with all specifiers
    ft_printf("Test 33 [ft_printf] - Mixed specifiers: %d, %x, %s, %c, %p, %u, %%\n", 42, 42, "Quarante deux", '4', p, (unsigned int)420);
    printf("Test 33 [printf   ] - Mixed specifiers: %d, %x, %s, %c, %p, %u, %%\n", 42, 42, "Quarante deux", '4', p, (unsigned int)420);
    // Test 34: Complex format - %X, %u, and %s
    ft_printf("Test 34 [ft_printf] - Complex format: %X, %u, %s\n", 0xABCD, 9999, "String");
    printf("Test 34 [printf   ] - Complex format: %X, %u, %s\n", 0xABCD, 9999, "String");
    // Test 35: Complex format - %p, %i, %c, and %s
    int i2 = -12345;
    void *ptr5 = &i2;
    ft_printf("Test 35 [ft_printf] - Complex format: %p, %i, %c, %s\n", ptr5, i2, 'F', "Pointer");
    printf("Test 35 [printf   ] - Complex format: %p, %i, %c, %s\n", ptr5, i2, 'F', "Pointer");
    // Test 36: Complex format - %d, %X, %s, and %c
    int d2 = 1000;
    ft_printf("Test 36 [ft_printf] - Complex format: %d, %X, %s, %c\n", d2, 0xBEEF, "Hex", 'G');
    printf("Test 36 [printf   ] - Complex format: %d, %X, %s, %c\n", d2, 0xBEEF, "Hex", 'G');
    // Test 37: Complex format - %u, %p, %s, and %x
    unsigned int u2 = UINT_MAX;
    ft_printf("Test 37 [ft_printf] - Complex format: %u, %p, %s, %x\n", u2, ptr, "Unsigned", 0x1234);
    printf("Test 37 [printf   ] - Complex format: %u, %p, %s, %x\n", u2, ptr, "Unsigned", 0x1234);
    // Test 38: Complex format - Multiple %s specifiers
    ft_printf("Test 38 [ft_printf] - Multiple strings: %s, %s, %s\n", "One", "Two", "Three");
    printf("Test 38 [printf   ] - Multiple strings: %s, %s, %s\n", "One", "Two", "Three");
    // Test 39: Complex format - Multiple %d specifiers
    ft_printf("Test 39 [ft_printf] - Multiple integers: %d, %d, %d\n", -1, 0, 1);
    printf("Test 39 [printf   ] - Multiple integers: %d, %d, %d\n", -1, 0, 1);
    // Test 40: Complex format - Multiple %x specifiers
    ft_printf("Test 40 [ft_printf] - Multiple hex: %x, %x, %x\n", 0xABC, 0xDEF, 0x123);
    printf("Test 40 [printf   ] - Multiple hex: %x, %x, %x\n", 0xABC, 0xDEF, 0x123);
    // Test 41: Complex format - Multiple %p specifiers
    void *ptrA = &d, *ptrB = &u2;
    ft_printf("Test 41 [ft_printf] - Multiple pointers: %p, %p\n", ptrA, ptrB);
    printf("Test 41 [printf   ] - Multiple pointers: %p, %p\n", ptrA, ptrB);
    // Test 42: Complex format - Mixed specifiers
    ft_printf("Test 42 [ft_printf] - Mixed specifiers: %d, %x, %s, %c, %p, %u\n", INT_MIN, 0xFFFF, "Mixed", 'H', &i, 500);
    printf("Test 42 [printf   ] - Mixed specifiers: %d, %x, %s, %c, %p, %u\n", INT_MIN, 0xFFFF, "Mixed", 'H', &i, 500);
    // Test 43: Complex formatting with multiple specifiers
    char *s3 = "Complex";
    ft_printf("Test 43 [ft_printf] - Complex format: %c %u %p %x %s\n", 'Z', UINT_MAX, ptr, 0xBEEF, s3);
    printf("Test 43 [printf   ] - Complex format: %c %u %p %x %s\n", 'Z', UINT_MAX, ptr, 0xBEEF, s3);
    ft_printf("Test 44 [ft_printf] - Nested specifiers: %%d\n", 42);
    printf("Test 44 [printf   ] - Nested specifiers: %%d\n", 42);
    // Test 45: Random symbols as flags (undefined behavior)
    ft_printf("Test 45 [ft_printf] - Random symbols as flags: %k%d\n", 42);
    printf("Test 45 [printf   ] - Random symbols as flags: %k%d\n", 42);


    ft_printf("\n FLAG TEST:\n\n");
    

    // Test 46: Width for %c
    ft_printf("Test 46 [ft_printf] - Width for char: %5c\n", 'A');
    printf("Test 46 [printf   ] - Width for char: %5c\n", 'A');
    // Test 47: Width for %s
    ft_printf("Test 47 [ft_printf] - Width for string: %20s\n", "Hello, World!");
    printf("Test 47 [printf   ] - Width for string: %20s\n", "Hello, World!");
    // Test 48: Width for %p
    void *ptr6 = &ft_printf;
    ft_printf("Test 48 [ft_printf] - Width for pointer: %20p\n", ptr6);
    printf("Test 48 [printf   ] - Width for pointer: %20p\n", ptr6);
    // Test 49: Width for %d
    ft_printf("Test 49 [ft_printf] - Width for int (d): %10d\n", 12345);
    printf("Test 49 [printf   ] - Width for int (d): %10d\n", 12345);
    // Test 50: Width for %i
    ft_printf("Test 50 [ft_printf] - Width for int (i): %10i\n", -12345);
    printf("Test 50 [printf   ] - Width for int (i): %10i\n", -12345);
    // Test 51: Width for %u
    ft_printf("Test 51 [ft_printf] - Width for unsigned: %10u\n", 12345);
    printf("Test 51 [printf   ] - Width for unsigned: %10u\n", 12345);
    // Test 52: Width for %x
    ft_printf("Test 52 [ft_printf] - Width for hex (x): %10x\n", 0xABC);
    printf("Test 52 [printf   ] - Width for hex (x): %10x\n", 0xABC);
    // Test 53: Width for %X
    ft_printf("Test 53 [ft_printf] - Width for hex (X): %10X\n", 0xABC);
    printf("Test 53 [printf   ] - Width for hex (X): %10X\n", 0xABC);
    // Test 54: Width with zero flag for %d
    ft_printf("Test 54 [ft_printf] - Width and zero flag for int (d): %010d\n", 12345);
    printf("Test 54 [printf   ] - Width and zero flag for int (d): %010d\n", 12345);
    // Test 55: Width with zero flag for %i
    ft_printf("Test 55 [ft_printf] - Width and zero flag for int (i): %010i\n", -12345);
    printf("Test 55 [printf   ] - Width and zero flag for int (i): %010i\n", -12345);
    // Test 56: Width with zero flag for %u
    ft_printf("Test 56 [ft_printf] - Width and zero flag for unsigned: %010u\n", 12345);
    printf("Test 56 [printf   ] - Width and zero flag for unsigned: %010u\n", 12345);
    // Test 57: Width with zero flag for %x
    ft_printf("Test 57 [ft_printf] - Width and zero flag for hex (x): %010x\n", 0xABC);
    printf("Test 57 [printf   ] - Width and zero flag for hex (x): %010x\n", 0xABC);
    // Test 58: Width with zero flag for %X
    ft_printf("Test 58 [ft_printf] - Width and zero flag for hex (X): %010X\n", 0xABC);
    printf("Test 58 [printf   ] - Width and zero flag for hex (X): %010X\n", 0xABC);
    // Test 59: Width with minus flag for %d
    ft_printf("Test 59 [ft_printf] - Width and minus flag for int (d): %-10d\n", 12345);
    printf("Test 59 [printf   ] - Width and minus flag for int (d): %-10d\n", 12345);
    // Test 60: Width with minus flag for %i
    ft_printf("Test 60 [ft_printf] - Width and minus flag for int (i): %-10i\n", -12345);
    printf("Test 60 [printf   ] - Width and minus flag for int (i): %-10i\n", -12345);
    // Test 61: Precision for %s
    ft_printf("Test 61 [ft_printf] - Precision for string: %.5s\n", "HelloWorld");
    printf("Test 61 [printf   ] - Precision for string: %.5s\n", "HelloWorld");
    // Test 62: Precision for %d
    ft_printf("Test 62 [ft_printf] - Precision for int (d): %.5d\n", 123);
    printf("Test 62 [printf   ] - Precision for int (d): %.5d\n", 123);
    // Test 63: Precision for %i
    ft_printf("Test 63 [ft_printf] - Precision for int (i): %.5i\n", -123);
    printf("Test 63 [printf   ] - Precision for int (i): %.5i\n", -123);
    // Test 64: Precision for %u
    ft_printf("Test 64 [ft_printf] - Precision for unsigned: %.5u\n", 12345);
    printf("Test 64 [printf   ] - Precision for unsigned: %.5u\n", 12345);
    // Test 65: Precision for %x
    ft_printf("Test 65 [ft_printf] - Precision for hex (x): %.5x\n", 0xABC);
    printf("Test 65 [printf   ] - Precision for hex (x): %.5x\n", 0xABC);
    // Test 66: Precision for %X
    ft_printf("Test 66 [ft_printf] - Precision for hex (X): %.5X\n", 0xABC);
    printf("Test 66 [printf   ] - Precision for hex (X): %.5X\n", 0xABC);
    // Test 67: # flag with %x
    ft_printf("Test 67 [ft_printf] - # flag with hex (x): %#x\n", 0xABC);
    printf("Test 67 [printf   ] - # flag with hex (x): %#x\n", 0xABC);
    // Test 68: # flag with %X
    ft_printf("Test 68 [ft_printf] - # flag with hex (X): %#X\n", 0xABC);
    printf("Test 68 [printf   ] - # flag with hex (X): %#X\n", 0xABC);
    // Test 69: ' ' flag with %d
    ft_printf("Test 69 [ft_printf] - ' ' flag with int (d): % d\n", 12345);
    printf("Test 69 [printf   ] - ' ' flag with int (d): % d\n", 12345);
    // Test 70: ' ' flag with %i
    ft_printf("Test 70 [ft_printf] - ' ' flag with int (i): % i\n", -12345);
    printf("Test 70 [printf   ] - ' ' flag with int (i): % i\n", -12345);
    // Test 71: ' ' flag with %u
    ft_printf("Test 71 [ft_printf] - ' ' flag with unsigned: % u\n", 12345);
    printf("Test 71 [printf   ] - ' ' flag with unsigned: % u\n", 12345);
    // Test 72: + flag with %d
    ft_printf("Test 72 [ft_printf] - + flag with int (d): %+d\n", 12345);
    printf("Test 72 [printf   ] - + flag with int (d): %+d\n", 12345);
    // Test 73: + flag with %i
    ft_printf("Test 73 [ft_printf] - + flag with int (i): %+i\n", -12345);
    printf("Test 73 [printf   ] - + flag with int (i): %+i\n", -12345);
    // Test 74: + flag with %u (Note: '+' flag has no effect on %u)
    ft_printf("Test 74 [ft_printf] - + flag with unsigned: %+u\n", 12345);
    printf("Test 74 [printf   ] - + flag with unsigned: %+u\n", 12345);
    // Test 75: Width and Precision for %d
    ft_printf("Test 75 [ft_printf] - Width and Precision for int 10.5 (d): %10.5d\n", 123);
    printf("Test 75 [printf   ] - Width and Precision for int 10.5 (d): %10.5d\n", 123);
    // Test 76: Width and Precision for %i
    ft_printf("Test 76 [ft_printf] - Width and Precision for int (i): %10.5i\n", -123);
    printf("Test 76 [printf   ] - Width and Precision for int (i): %10.5i\n", -123);
    // Test 77: Width and Precision for %x
    ft_printf("Test 77 [ft_printf] - Width and Precision for hex (x): %10.5x\n", 0xABC);
    printf("Test 77 [printf   ] - Width and Precision for hex (x): %10.5x\n", 0xABC);
    // Test 78: Width and Precision for %X
    ft_printf("Test 78 [ft_printf] - Width and Precision for hex (X): %10.5X\n", 0xABC);
    printf("Test 78 [printf   ] - Width and Precision for hex (X): %10.5X\n", 0xABC);
    // Test 79: ' ' and + flags with %d (Note: '+' takes precedence over ' ')
    ft_printf("Test 79 [ft_printf] - ' ' and + flags with int (d): % +d\n", 12345);
    printf("Test 79 [printf   ] - ' ' and + flags with int (d): % +d\n", 12345);
    // Test 80: ' ' and + flags with %i (Note: '+' takes precedence over ' ')
    ft_printf("Test 80 [ft_printf] - ' ' and + flags with int (i): % +i\n", -12345);
    printf("Test 80 [printf   ] - ' ' and + flags with int (i): % +i\n", -12345);
    // Test 81: # and 0 flags with %x
    ft_printf("Test 81 [ft_printf] - # and 0 flags with hex (x): %#010x\n", 0xABC);
    printf("Test 81 [printf   ] - # and 0 flags with hex (x): %#010x\n", 0xABC);
    // Test 82: # and 0 flags with %X
    ft_printf("Test 82 [ft_printf] - # and 0 flags with hex (X): %#010X\n", 0xABC);
    printf("Test 82 [printf   ] - # and 0 flags with hex (X): %#010X\n", 0xABC);
    // Test 83: - and 0 flags with %d (Note: '-' takes precedence over '0')
    ft_printf("Test 83 [ft_printf] - - and 0 flags with int (d): %-010d\n", 12345);
    printf("Test 83 [printf   ] - - and 0 flags with int (d): %-010d\n", 12345);
    // Test 84: - and width with %s
    ft_printf("Test 84 [ft_printf] - - and width with string: %-20s\n", "Left aligned");
    printf("Test 84 [printf   ] - - and width with string: %-20s\n", "Left aligned");
    // Test 85: Mixed specifiers and flags
    ft_printf("Test 85 [ft_printf] - Mixed specifiers and flags: %-10.5d %#x %+i % 10u\n", 123, 0xABC, -12345, 12345);
    printf("Test 85 [printf   ] - Mixed specifiers and flags: %-10.5d %#x %+i % 10u\n", 123, 0xABC, -12345, 12345);
    // Test 86: Complex mix with all specifiers
    ft_printf("Test 86 [ft_printf] - Complex mix: %10.5d %-10s %#X %10p %+i %-10u\n", 123, "String", 0xABC, ptr, -12345, 12345);
    printf("Test 86 [printf   ] - Complex mix: %10.5d %-10s %#X %10p %+i %-10u\n", 123, "String", 0xABC, ptr, -12345, 12345);
    // Test 87: Very complex mix with all specifiers and flags
    ft_printf("Test 87 [ft_printf] - Very complex mix: %#-10.5X % 10.5d %+10.5i %-.10s %p %010u\n", 0xABC, 12345, -12345, "String", &i, 12345);
    printf("Test 87 [printf   ] - Very complex mix: %#-10.5X % 10.5d %+10.5i %-.10s %p %010u\n", 0xABC, 12345, -12345, "String", &i, 12345);
    // Test 88: Complex mix with c, s, and d specifiers
    ft_printf("Test 88 [ft_printf] - Complex mix: %-5c %20.10s %+05d\n", 'X', "Formatted", 12345);
    printf("Test 88 [printf   ] - Complex mix: %-5c %20.10s %+05d\n", 'X', "Formatted", 12345);
    // Test 89: Complex mix with i, u, and x specifiers
    ft_printf("Test 89 [ft_printf] - Complex mix: %+10i %-15u %#08x\n", -12345, 12345, 0xABC);
    printf("Test 89 [printf   ] - Complex mix: %+10i %-15u %#08x\n", -12345, 12345, 0xABC);
    // Test 90: Complex mix with X, p, and % specifiers
    void *ptr8 = &ft_printf;
    ft_printf("Test 90 [ft_printf] - Complex mix: %#10X %-20p %%\n", 0xABCDEF, ptr8);
    printf("Test 90 [printf   ] - Complex mix: %#10X %-20p %%\n", 0xABCDEF, ptr8);
    // Test 91: Complex mix with multiple %d and flags
    ft_printf("Test 91 [ft_printf] - Complex mix: % 10d %+10d %-10d\n", 123, -456, 789);
    printf("Test 91 [printf   ] - Complex mix: % 10d %+10d %-10d\n", 123, -456, 789);
    // Test 92: Complex mix with s and u specifiers with precision and width
    ft_printf("Test 92 [ft_printf] - Complex mix: %-20.10s %010u\n", "Truncated", 12345);
    printf("Test 92 [printf   ] - Complex mix: %-20.10s %010u\n", "Truncated", 12345);
    // Test 93: Complex mix with c, x, and X specifiers with flags
    ft_printf("Test 93 [ft_printf] - Complex mix: %#c %#x %#X\n", 'Y', 0x123, 0xABC);
    printf("Test 93 [printf   ] - Complex mix: %#c %#x %#X\n", 'Y', 0x123, 0xABC);
    // Test 94: Complex mix with i, d, and u specifiers with flags and width
    ft_printf("Test 94 [ft_printf] - Complex mix: %+10i % 10d %-10u\n", -12345, 12345, 12345);
    printf("Test 94 [printf   ] - Complex mix: %+10i % 10d %-10u\n", -12345, 12345, 12345);
    // Test 95: Complex mix with all specifiers and various flags
    ft_printf("Test 95 [ft_printf] - Very complex mix: %-c %#x % 10d %+i %-10s %#X %p %u %%\n", 'Z', 0x123, 12345, -12345, "Test", 0xABCDEF, ptr, 12345);
    printf("Test 95 [printf   ] - Very complex mix: %-c %#x % 10d %+i %-10s %#X %p %u %%\n", 'Z', 0x123, 12345, -12345, "Test", 0xABCDEF, ptr, 12345);
    // Test 96: Complex mix with reversed specifiers and flags (should be ignored or treated as literals)
    ft_printf("Test 96 [ft_printf] - Reversed specifiers: d%\n");
    printf("Test 96 [printf   ] - Reversed specifiers: d%\n");
    // Test 97: Complex mix with random characters and specifiers
    ft_printf("Test 97 [ft_printf] - Random characters: %d###%x\n", 42, 0xABC);
    printf("Test 97 [printf   ] - Random characters: %d###%x\n", 42, 0xABC);
    // Test 98: Complex mix with all non-permitted flags for %d
    ft_printf("Test 98 [ft_printf] - All non-permitted flags for %d: %0#+ d\n", 42);
    printf("Test 98 [printf   ] - All non-permitted flags for %d: %0#+ d\n", 42);
    // Test 99: Complex mix with all non-permitted flags for %x
    ft_printf("Test 99 [ft_printf] - All non-permitted flags for %x: %+ #0x\n", 0xABC);
    printf("Test 99 [printf   ] - All non-permitted flags for %x: %+ #0x\n", 0xABC);
    // Test 100: Complex mix with all non-permitted flags for %X
    ft_printf("Test 100 [ft_printf] - All non-permitted flags for %X: %+ #0X\n", 0xABC);
    printf("Test 100 [printf   ] - All non-permitted flags for %X: %+ #0X\n", 0xABC);
    // Test 101: Complex mix with all non-permitted flags for %u
    ft_printf("Test 101 [ft_printf] - All non-permitted flags for %u: % #0+u\n", 12345);
    printf("Test 101 [printf   ] - All non-permitted flags for %u: % #0+u\n", 12345);
    // Test 102: Complex mix with all non-permitted flags for %c
    ft_printf("Test 102 [ft_printf] - All non-permitted flags for %c: %#0+c\n", 'A');
    printf("Test 102 [printf   ] - All non-permitted flags for %c: %#0+c\n", 'A');
    // Test 103: String with precision
    ft_printf("Test 103 [ft_printf] - String with precision: %.5s\n", "Hello, World!");
    printf("Test 103 [printf   ] - String with precision: %.5s\n", "Hello, World!");
    // Test 104: String with padding and width
    ft_printf("Test 104 [ft_printf] - Padded and width string: %10s\n", "Pad me");
    printf("Test 104 [printf   ] - Padded and width string: %10s\n", "Pad me");
    // Test 105: Printing a string with a precision longer than the string
    ft_printf("Test 105 [ft_printf] - Over-precision string: %.20s\n", "Short");
    printf("Test 105 [printf   ] - Over-precision string: %.20s\n", "Short");
    // Test 106: Excessive width for string
    ft_printf("Test 106 [ft_printf] - Excessive width: %150s\n", "Wide");
    printf("Test 106 [printf   ] - Excessive width: %150s\n", "Wide");
    // Test 107: Excessive width for %c
    ft_printf("Test 107 [ft_printf] - Excessive width for char: %100c\n", 'A');
    printf("Test 107 [printf   ] - Excessive width for char: %100c\n", 'A');
    // Test 108: Excessively large precision for string
    ft_printf("Test 108 [ft_printf] - Excessive precision: %.100s\n", "abcdefghijklmnopqrstuvwxyz0123456789 0 1 2 3 4 5 6 7 8 9 ");
    printf("Test 108 [printf   ] - Excessive precision: %.100s\n", "abcdefghijklmnopqrstuvwxyz0123456789 0 1 2 3 4 5 6 7 8 9 ");
    // Test 109: Left-justified character with width
    ft_printf("Test 109 [ft_printf] - Left-justified with width: %-5c\n", 'B');
    printf("Test 109 [printf   ] - Left-justified with width: %-5c\n", 'B');
    // Test 110: Right-justified character with width
    ft_printf("Test 110 [ft_printf] - Right-justified with width: %5c\n", 'C');
    printf("Test 110 [printf   ] - Right-justified with width: %5c\n", 'C');
    // Test 111: Left-justified string with width
    ft_printf("Test 111 [ft_printf] - Left-justified with width: %-20s\n", "Left aligned");
    printf("Test 111 [printf   ] - Left-justified with width: %-20s\n", "Left aligned");
    // Test 112: Right-justified string with width
    ft_printf("Test 112 [ft_printf] - Right-justified with width: %20s\n", "Right aligned");
    printf("Test 112 [printf   ] - Right-justified with width: %20s\n", "Right aligned");
    // Test 113: Invalid flag combination
    ft_printf("Test 113 [ft_printf] - Invalid flag combo: %+ 0d\n", 42);
    printf("Test 113 [printf   ] - Invalid flag combo: %+ 0d\n", 42);
    // Test 114: Conflicting flags
    ft_printf("Test 114 [ft_printf] - Conflicting flags: %+ -0d\n", 42);
    printf("Test 114 [printf   ] - Conflicting flags: %+ -0d\n", 42);
    // Test 115: Negative width and precision
    ft_printf("Test 115 [ft_printf] - Negative width and precision: %*.*d\n", -10, -5, 42);
    printf("Test 115 [printf   ] - Negative width and precision: %*.*d\n", -10, -5, 42);
    // Test 116: Mixed random characters in the format string
    ft_printf("Test 116 [ft_printf] - Random characters: %x %d%%%s####\n", 42, 42, "test");
    printf("Test 116 [printf   ] - Random characters: %x %d%%%s####\n", 42, 42, "test");
    // Test 117: Mixed valid and invalid specifiers
    ft_printf("Test 117 [ft_printf] - Mixed valid and invalid specifiers: %d %r %d\n", 42, 42);
    printf("Test 117 [printf   ] - Mixed valid and invalid specifiers: %d %r %d\n", 42, 42);





    ft_printf("\n INVALID FORMAT AND ERROR MESSAGES TEST:\n\n");

    // Test 118: Passing an invalid format specifier (Undefined behavior)
    ft_printf("Test 118 [ft_printf] - Invalid specifier: %y\n");
    printf("Test 118 [printf   ] - Invalid specifier: %y\n");
    // Test 119: Incorrect specifier combination (e.g., using a precision specifier with %c which is typically not used)
    ft_printf("Test 119 [ft_printf] - Incorrect specifier combination: %.5c\n", 'A');
    printf("Test 119 [printf   ] - Incorrect specifier combination: %.5c\n", 'A');
    // Test 120: Precision specifier for %p (undefined in some implementations)
    ft_printf("Test 120 [ft_printf] - Precision with pointer: %.5p\n", ptr2);
    printf("Test 120 [printf   ] - Precision with pointer: %.5p\n", ptr2);
    // Test 121: Using non-existent specifiers
    ft_printf("Test 121 [ft_printf] - Non-existent specifier: %v\n");
    printf("Test 121 [printf   ] - Non-existent specifier: %v\n");
    // Test 122: Incomplete specifier at the end
    ft_printf("Test 122 [ft_printf] - Incomplete specifier: %\n");
    printf("Test 122 [printf   ] - Incomplete specifier: %\n");
    // Test 123: Multiple percent signs
    ft_printf("Test 123 [ft_printf] - Multiple percent signs: %%d%%\n", 42);
    printf("Test 123 [printf   ] - Multiple percent signs: %%d%%\n", 42);
    // Test 124: Reversed specifiers (should be ignored or treated as literals)
    ft_printf("Test 124 [ft_printf] - Reversed specifiers: d%\n");
    printf("Test 124 [printf   ] - Reversed specifiers: d%\n");
    // Test 125: Character with plus flag (not typically permitted)
    ft_printf("Test 125 [ft_printf] - Plus flag (not permitted): %+c\n", 'E');
    printf("Test 125 [printf   ] - Plus flag (not permitted): %+c\n", 'E');
    // Test 126: Character with space flag (not typically permitted)
    ft_printf("Test 126 [ft_printf] - Space flag (not permitted): % c\n", 'F');
    printf("Test 126 [printf   ] - Space flag (not permitted): % c\n", 'F');
    // Test 127: Character with hash flag (not typically permitted)
    ft_printf("Test 127 [ft_printf] - Hash flag (not permitted): %#c\n", 'G');
    printf("Test 127 [printf   ] - Hash flag (not permitted): %#c\n", 'G');
    // Test 128: Character with precision (not typically permitted)
    ft_printf("Test 128 [ft_printf] - Precision (not permitted): %.2c\n", 'H');
    printf("Test 128 [printf   ] - Precision (not permitted): %.2c\n", 'H');
    // Test 129: Character with invalid flag combination
    ft_printf("Test 129 [ft_printf] - Invalid flag combo: %-+ c\n", 'J');
    printf("Test 129 [printf   ] - Invalid flag combo: %-+ c\n", 'J');
    // Test 130: String with zero flag (not typically permitted)
    ft_printf("Test 130 [ft_printf] - Zero flag (not permitted): %0s\n", sample);
    printf("Test 130 [printf   ] - Zero flag (not permitted): %0s\n", sample);
    // Test 131: String with plus flag (not typically permitted)
    ft_printf("Test 131 [ft_printf] - Plus flag (not permitted): %+s\n", sample);
    printf("Test 131 [printf   ] - Plus flag (not permitted): %+s\n", sample);
    // Test 132: String with space flag (not typically permitted)
    ft_printf("Test 132 [ft_printf] - Space flag (not permitted): % s\n", sample);
    printf("Test 132 [printf   ] - Space flag (not permitted): % s\n", sample);
    // Test 133: String with hash flag (not typically permitted)
    ft_printf("Test 133 [ft_printf] - Hash flag (not permitted): %#s\n", sample);
    printf("Test 133 [printf   ] - Hash flag (not permitted): %#s\n", sample);
    // Test 134: String with length modifier (not typically permitted)
    ft_printf("Test 134 [ft_printf] - Length modifier (not permitted): %s\n", sample);
    printf("Test 134 [printf   ] - Length modifier (not permitted): %s\n", sample);
    char *sample2 = "Sample Hello";
    // Test 135: String with invalid flag combination
    ft_printf("Test 135 [ft_printf] - Invalid flag combo: %-+ s\n", sample2);
    printf("Test 135 [printf   ] - Invalid flag combo: %-+ s\n", sample2);
    // Test 136: Pointer with plus flag (not typically permitted)
    ft_printf("Test 136 [ft_printf] - Plus flag (not permitted): %+p\n", ptr3);
    printf("Test 136 [printf   ] - Plus flag (not permitted): %+p\n", ptr3);
    // Test 137: Pointer with space flag (not typically permitted)
    ft_printf("Test 137 [ft_printf] - Space flag (not permitted): % p\n", ptr3);
    printf("Test 137 [printf   ] - Space flag (not permitted): % p\n", ptr3);
    // Test 138: Pointer with hash flag (not typically permitted)
    ft_printf("Test 138 [ft_printf] - Hash flag (not permitted): %#p\n", ptr3);
    printf("Test 138 [printf   ] - Hash flag (not permitted): %#p\n", ptr3);
    // Test 139: Pointer with precision (not typically permitted)
    ft_printf("Test 139 [ft_printf] - Precision (not permitted): %.5p\n", ptr3);
    printf("Test 139 [printf   ] - Precision (not permitted): %.5p\n", ptr3);
    // Test 140: Pointer with length modifier (not typically permitted)
    ft_printf("Test 140 [ft_printf] - Length modifier (not permitted): %.5p\n", ptr3);
    printf("Test 140 [printf   ] - Length modifier (not permitted): %.5p\n", ptr3);
    // Test 141: Pointer with invalid flag combination
    ft_printf("Test 141 [ft_printf] - Invalid flag combo: %-+ p\n", ptr3);
    printf("Test 141 [printf   ] - Invalid flag combo: %-+ p\n", ptr3);
    // Test 142: Integer with hash flag %d (not typically permitted)
    ft_printf("Test 142 [ft_printf] - Integer with hash flag (not permitted): %#d\n", 42);
    printf("Test 142 [printf   ] - Integer with hash flag (not permitted): %#d\n", 42);
    // Test 143: Integer with non-existent specifier %w (should fail or be ignored)
    ft_printf("Test 143 [ft_printf] - Non-existent specifier: %w\n", 42);
    printf("Test 143 [printf   ] - Non-existent specifier: %w\n", 42);
    // Test 144: Integer with excessive length modifiers %hhhhhd
    ft_printf("Test 144 [ft_printf] - Excessive length modifiers: %hhhhhd\n", 42);
    printf("Test 144 [printf   ] - Excessive length modifiers: %hhhhhhhd\n", 42);
    // Test 145: Integer with mixed valid and invalid flags %d
    ft_printf("Test 145 [ft_printf] - Mixed valid and invalid flags: %0+- 5d\n", 42);
    printf("Test 145 [printf   ] - Mixed valid and invalid flags: %0+- 5d\n", 42);
    // Test 146: Integer with reversed specifiers %d%
    ft_printf("Test 146 [ft_printf] - Reversed specifiers: d%\n");
    printf("Test 146 [printf   ] - Reversed specifiers: d%\n");
    // Test 147: Integer %d with all non-permitted flags
    ft_printf("Test 147 [ft_printf] - All non-permitted flags: %0#+ d\n", 42);
    printf("Test 147 [printf   ] - All non-permitted flags: %0#+ d\n", 42);
    // Test 148: Hexadecimal %x with plus flag (not typically permitted)
    ft_printf("Test 148 [ft_printf] - Hexadecimal with plus (not permitted) (x): %+x\n", hexValue);
    printf("Test 148 [printf   ] - Hexadecimal with plus (not permitted) (x): %+x\n", hexValue);
    // Test 149: Hexadecimal %X with space flag (not typically permitted)
    ft_printf("Test 149 [ft_printf] - Hexadecimal with space (not permitted) (X): % X\n", hexValue);
    printf("Test 149 [printf   ] - Hexadecimal with space (not permitted) (X): % X\n", hexValue);
    // Test 150: Percent sign %%
    ft_printf("Test 150 [ft_printf] - Percent sign: %%\n");
    printf("Test 150 [printf   ] - Percent sign: %%\n");
    // Test 151: Percent sign with width %%
    ft_printf("Test 151 [ft_printf] - Percent sign with width: %5%\n");
    printf("Test 151 [printf   ] - Percent sign with width: %5%\n");
    // Test 152: Percent sign with left-justified %%
    ft_printf("Test 152 [ft_printf] - Percent sign left-justified: %-5%\n");
    printf("Test 152 [printf   ] - Percent sign left-justified: %-5%\n");
    // Test 153: Percent sign with invalid flag %%
    ft_printf("Test 153 [ft_printf] - Invalid flag with percent: %+#%\n");
    printf("Test 153 [printf   ] - Invalid flag with percent: %+#%\n");
    // Test 154: Percent sign with zero padding %%
    ft_printf("Test 154 [ft_printf] - Zero padding with percent: %05%\n");
    printf("Test 154 [printf   ] - Zero padding with percent: %05%\n");
    // Test 155: Multiple percent signs %%
    ft_printf("Test 155 [ft_printf] - Multiple percent signs: %% %% %%\n");
    printf("Test 155 [printf   ] - Multiple percent signs: %% %% %%\n");
    // Test 156: Percent sign %%
    ft_printf("Test 156 [ft_printf] - Percent sign: %%\n");
    printf("Test 156 [printf   ] - Percent sign: %%\n");
    // Test 157: %i with a large number (beyond int range) to check behavior
    ft_printf("Test 157 [ft_printf] - Large number (i): %i\n", 21474836470);
    printf("Test 157 [printf   ] - Large number (i): %i\n", 21474836470);
    // Test 158: %i with a number just above INT_MAX (to see if it wraps around correctly)
    ft_printf("Test 158 [ft_printf] - Above max int (i): %i\n", INT_MAX + 1);
    printf("Test 158 [printf   ] - Above max int (i): %i\n", INT_MAX + 1);
    // Test 159: %i with a number just below INT_MIN (to see if it wraps around correctly)
    ft_printf("Test 159 [ft_printf] - Below min int (i): %i\n", INT_MIN - 1);
    printf("Test 159 [printf   ] - Below min int (i): %i\n", INT_MIN - 1);
    // Test 160: %d with a very large number (long long max for instance)
    ft_printf("Test 160 [ft_printf] - Very large number (d): %d\n", large_num);
    printf("Test 160 [printf   ] - Very large number (d): %d\n", large_num);
    // Test 161: Integer overflow (Undefined behavior)
    ft_printf("Test 161 [ft_printf] - Int overflow: %d\n", INT_MAX + 1);
    printf("Test 161 [printf   ] - Int overflow: %d\n", INT_MAX + 1);
    // Test 162: Integer underflow (Undefined behavior)
    ft_printf("Test 162 [ft_printf] - Int underflow: %d\n", INT_MIN - 1);
    printf("Test 162 [printf   ] - Int underflow: %d\n", INT_MIN - 1);
    // Test 163: Passing wrong type (Undefined behavior)
    ft_printf("Test 163 [ft_printf] - Wrong type for d: %d\n", "123");
    printf("Test 163 [printf   ] - Wrong type for d: %d\n", "123");
    // Test 164: Passing NULL for a %d specifier (may produce an error or unexpected behavior)
    ft_printf("Test 164 [ft_printf] - NULL for integer: %d\n", NULL);
    printf("Test 164 [printf   ] - NULL for integer: %d\n", NULL);
    // Test 165: Passing a floating-point number to %d (may produce an error or unexpected behavior)
    ft_printf("Test 165 [ft_printf] - Float to int: %d\n", 123.456);
    printf("Test 165 [printf   ] - Float to int: %d\n", 123.456);
    // Test 166: Passing a string to %d (may produce an error or unexpected behavior)
    ft_printf("Test 166 [ft_printf] - String to int: %d\n", "123");
    printf("Test 166 [printf   ] - String to int: %d\n", "123");
    // Test 167: Missing argument for a specifier
    ft_printf("Test 167 [ft_printf] - Missing argument: %d\n");
    printf("Test 167 [printf   ] - Missing argument: %d\n");

    printf("%50d trop cool j'ai mon propre printf qui marche avec tout\n%50p\n",123,  ptr3);
    ft_printf("%50d trop cool j'ai mon propre printf qui marche avec tout\n%50p\n", 123,  ptr3);
    return 0;
}
