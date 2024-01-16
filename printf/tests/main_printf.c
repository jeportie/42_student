/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:42:12 by jeportie          #+#    #+#             */
/*   Updated: 2024/01/16 19:27:47 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    char *sample = "Sample String";
    void *ptr = (void *)0x7fff25a57b38;
    void *ptr2= (void *)0x12345015ff23;
    void *ptr3 = (void *)0x12345678;
    unsigned int hexValue = 0xABCD;
    void *p = (void *)0x12345678;
    void *p2 = (void *)0x98765432;
    int i = -42;
    unsigned int u = 42;

    char *escape_string = "Hello\tWorld\tTabbed!";
    unsigned int x = 0xABC;
    unsigned int X = 0xABC;
    long long large_num = LLONG_MAX;
    char long_string[128];
    int d = 42;

    int i2 = -12345;
    int d2 = 1000;
    unsigned int u2 = UINT_MAX;
    char *s3 = "Complex";
    char *sample2 = "Sample Hello";

	ft_memset(long_string, 'A', 128);
    printf("Test 01 - Simple character: %c\n", 'A');
    printf("Test 02 - Non-printable char (bell): %c\n", 7); // ASCII Bell
    printf("Test 03 - Newtab character (tab): %c\t\n", '\t');
    printf("Test 04 - Simple string: %s\n", "Hello World");
    printf("Test 05 - Null string: %s\n", (char *)NULL);
    printf("Test 06 - String with escapes: %s\n", escape_string);
    printf("Test 07 - Long string: %s\n", long_string);
    printf("Test 08 - Simple pointer: %p\n", p);
    printf("Test 09 - Null pointer: %p\n", NULL);
    printf("Test 10 - Function pointer: %p\n", p);
    printf("Test 11 - Simple integer (d): %d\n", d);
    printf("Test 12 - Maximum int (d): %d\n", INT_MAX);
    printf("Test 13 - Minimum int (d): %d\n", INT_MIN);
    printf("Test 14 - Negative zero (d): %d\n", -0);
    printf("Test 15 - Simple integer (i): %i\n", i);
    printf("Test 16 - Positive int: %i\n", 123);
    printf("Test 17 - Negative int: %i\n", -123);
    printf("Test 18 - Simple unsigned integer (u): %u\n", u);
    printf("Test 19 - Maximum unsigned int: %u\n", UINT_MAX);
    printf("Test 20 - Negative value as unsigned (u): %u\n", -42);
    printf("Test 21 - Simple hexadecimal (x): %x\n", x);
    printf("Test 22 - Zero as hex (x): %x\n", 0);
    printf("Test 23 - Max unsigned int as hex (x): %x\n", UINT_MAX);
    printf("Test 24 - Simple hexadecimal (X): %X\n", X);
    printf("Test 25 - Zero as hex (X): %X\n", 0);
    printf("Test 26 - Max unsigned int as hex (X): %X\n", UINT_MAX);
    printf("Test 27 - Single percent sign (%%): %%\n");
    printf("Test 28 - Char, String, and Int: %c, %s, %d\n", 'H', "world", 42);
    printf("Test 29 - Hex, Unsigned, and String: %x, %u, %s\n", 0xABCD, 12345, "Test");
    printf("Test 30 - Pointer, Int, and Char: %p, %i, %c\n", p, -123, 'A');
    printf("Test 31 - Int, Hex Uppercase, String, and Char: %d, %X, %s, %c\n", 1000, 0xBEEF, "Hex", 'B');
    printf("Test 32 - Unsigned, Pointer, String, and Hex: %u, %p, %s, %x\n", UINT_MAX, p, "Unsigned", 0x1234);
    printf("Test 33 - Mixed specifiers: %d, %x, %s, %c, %p, %u, %%\n", 42, 42, "Quarante deux", '4', p, (unsigned int)420);
    printf("Test 34 - Complex format: %X, %u, %s\n", 0xABCD, 9999, "String");
    printf("Test 35 - Complex format: %p, %i, %c, %s\n", p, i2, 'F', "Pointer");
    printf("Test 36 - Complex format: %d, %X, %s, %c\n", d2, 0xBEEF, "Hex", 'G');
    printf("Test 37 - Complex format: %u, %p, %s, %x\n", u2, p, "Unsigned", 0x1234);
    printf("Test 38 - Multiple strings: %s, %s, %s\n", "One", "Two", "Three");
    printf("Test 39 - Multiple integers: %d, %d, %d\n", -1, 0, 1);
    printf("Test 40 - Multiple hex: %x, %x, %x\n", 0xABC, 0xDEF, 0x123);
    printf("Test 41 - Multiple pointers: %p, %p\n", p, p2);
    printf("Test 42 - Mixed specifiers: %d, %x, %s, %c, %p, %u\n", INT_MIN, 0xFFFF, "Mixed", 'H', p2, 500);
    printf("Test 43 - Complex format: %c %u %p %x %s\n", 'Z', UINT_MAX, ptr, 0xBEEF, s3);
    printf("Test 44 - Nested specifiers: %%d\n", 42);
    printf("Test 45 - Random symbols as flags: %k%d\n", 42);
    printf("Test 46 - Width for char: %5c\n", 'A');
    printf("Test 47 - Width for string: %20s\n", "Hello, World!");
    printf("Test 48 - Width for pointer: %20p\n", p);
    printf("Test 49 - Width for int (d): %10d\n", 12345);
    printf("Test 50 - Width for int (i): %10i\n", -12345);
    printf("Test 51 - Width for unsigned: %10u\n", 12345);
    printf("Test 52 - Width for hex (x): %10x\n", 0xABC);
    printf("Test 53 - Width for hex (X): %10X\n", 0xABC);
    printf("Test 54 - Width and zero flag for int (d): %010d\n", 12345);
    printf("Test 55 - Width and zero flag for int (i): %010i\n", -12345);
    printf("Test 56 - Width and zero flag for unsigned: %010u\n", 12345);
    printf("Test 57 - Width and zero flag for hex (x): %010x\n", 0xABC);
    printf("Test 58 - Width and zero flag for hex (X): %010X\n", 0xABC);
    printf("Test 59 - Width and minus flag for int (d): %-10d\n", 12345);
    printf("Test 60 - Width and minus flag for int (i): %-10i\n", -12345);
    printf("Test 61 - Precision for string: %.5s\n", "HelloWorld");
    printf("Test 62 - Precision for int (d): %.5d\n", 123);
    printf("Test 63 - Precision for int (i): %.5i\n", -123);
    printf("Test 64 - Precision for unsigned: %.5u\n", 12345);
    printf("Test 65 - Precision for hex (x): %.5x\n", 0xABC);
    printf("Test 66 - Precision for hex (X): %.5X\n", 0xABC);
    printf("Test 67 - # flag with hex (x): %#x\n", 0xABC);
    printf("Test 68 - # flag with hex (X): %#X\n", 0xABC);
    printf("Test 69 - ' ' flag with int (d): % d\n", 12345);
    printf("Test 70 - ' ' flag with int (i): % i\n", -12345);
    printf("Test 71 - ' ' flag with unsigned: % u\n", 12345);
    printf("Test 72 - + flag with int (d): %+d\n", 12345);
    printf("Test 73 - + flag with int (i): %+i\n", -12345);
    printf("Test 74 - + flag with unsigned: %+u\n", 12345);
    printf("Test 75 - Width and Precision for int 10.5 (d): %10.5d\n", 123);
    printf("Test 76 - Width and Precision for int (i): %10.5i\n", -123);
    printf("Test 77 - Width and Precision for hex (x): %10.5x\n", 0xABC);
    printf("Test 78 - Width and Precision for hex (X): %10.5X\n", 0xABC);
    printf("Test 79 - ' ' and + flags with int (d): % +d\n", 12345);
    printf("Test 80 - ' ' and + flags with int (i): % +i\n", -12345);
    printf("Test 81 - # and 0 flags with hex (x): %#010x\n", 0xABC);
    printf("Test 82 - # and 0 flags with hex (X): %#010X\n", 0xABC);
    printf("Test 83 - - and 0 flags with int (d): %-010d\n", 12345);
    printf("Test 84 - - and width with string: %-20s\n", "Left aligned");
    printf("Test 85 - Mixed specifiers and flags: %-10.5d %#x %+i % 10u\n", 123, 0xABC, -12345, 12345);
    printf("Test 86 - Complex mix: %10.5d %-10s %#X %10p %+i %-10u\n", 123, "String", 0xABC, ptr, -12345, 12345);
    printf("Test 87 - Very complex mix: %#-10.5X % 10.5d %+10.5i %-.10s %p %010u\n", 0xABC, 12345, -12345, "String", p2, 12345);
    printf("Test 88 - Complex mix: %-5c %20.10s %+05d\n", 'X', "Formatted", 12345);
    printf("Test 89 - Complex mix: %+10i %-15u %#08x\n", -12345, 12345, 0xABC);
    printf("Test 90 - Complex mix: %#10X %-20p %%\n", 0xABCDEF, p);
    printf("Test 91 - Complex mix: % 10d %+10d %-10d\n", 123, -456, 789);
    printf("Test 92 - Complex mix: %-20.10s %010u\n", "Truncated", 12345);
    printf("Test 93 - Complex mix: %#c %#x %#X\n", 'Y', 0x123, 0xABC);
    printf("Test 94 - Complex mix: %+10i % 10d %-10u\n", -12345, 12345, 12345);
    printf("Test 95 - Very complex mix: %-c %#x % 10d %+i %-10s %#X %p %u %%\n", 'Z', 0x123, 12345, -12345, "Test", 0xABCDEF, ptr, 12345);
    printf("Test 96 - Reversed specifiers: d%\n");
    printf("Test 97 - Random characters: %d###%x\n", 42, 0xABC);
    printf("Test 98 - All non-permitted flags for %d: %0#+ d\n", 42);
    printf("Test 99 - All non-permitted flags for %x: %+ #0x\n", 0xABC);
    printf("Test 100 - All non-permitted flags for %X: %+ #0X\n", 0xABC);
    printf("Test 101 - All non-permitted flags for %u: % #0+u\n", 12345);
    printf("Test 102 - All non-permitted flags for %c: %#0+c\n", 'A');
    printf("Test 103 - String with precision: %.5s\n", "Hello, World!");
    printf("Test 104 - Padded and width string: %10s\n", "Pad me");
    printf("Test 105 - Over-precision string: %.20s\n", "Short");
    printf("Test 106 - Excessive width: %150s\n", "Wide");
    printf("Test 107 - Excessive width for char: %100c\n", 'A');
    printf("Test 108 - Excessive precision: %.100s\n", "abcdefghijklmnopqrstuvwxyz0123456789 0 1 2 3 4 5 6 7 8 9 ");
    printf("Test 109 - Left-justified with width: %-5c\n", 'B');
    printf("Test 110 - Right-justified with width: %5c\n", 'C');
    printf("Test 111 - Left-justified with width: %-20s\n", "Left aligned");
    printf("Test 112 - Right-justified with width: %20s\n", "Right aligned");
    printf("Test 113 - Invalid flag combo: %+ 0d\n", 42);
    printf("Test 114 - Conflicting flags: %+ -0d\n", 42);
    printf("Test 115 - NULL for integer: %d\n", NULL);
    printf("Test 116 - Random characters: %x %d%%%s####\n", 42, 42, "test");
    printf("Test 117 - Mixed valid and invalid specifiers: %d %r %d\n", 42, 42);
    printf("Test 118 - Invalid specifier: %y\n");
    printf("Test 119 - Incorrect specifier combination: %.5c\n", 'A');
    printf("Test 120 - Precision with pointer: %.5p\n", ptr2);
    printf("Test 121 - Non-existent specifier: %v\n");
    printf("Test 122 - Incomplete specifier: %\n");
    printf("Test 123 - Multiple percent signs: %%d%%\n", 42);
    printf("Test 124 - Reversed specifiers: d%\n");
    printf("Test 125 - Plus flag (not permitted): %+c\n", 'E');
    printf("Test 126 - Space flag (not permitted): % c\n", 'F');
    printf("Test 127 - Hash flag (not permitted): %#c\n", 'G');
    printf("Test 128 - Precision (not permitted): %.2c\n", 'H');
    printf("Test 129 - Invalid flag combo: %-+ c\n", 'J');
    printf("Test 130 - Zero flag (not permitted): %0s\n", sample);
    printf("Test 131 - Plus flag (not permitted): %+s\n", sample);
    printf("Test 132 - Space flag (not permitted): % s\n", sample);
    printf("Test 133 - Hash flag (not permitted): %#s\n", sample);
    printf("Test 134 - Length modifier (not permitted): %s\n", sample);
    printf("Test 135 - Invalid flag combo: %-+ s\n", sample2);
    printf("Test 136 - Hash flag (not permitted): %#p\n", ptr3);
    printf("Test 137 - Precision (not permitted): %.5p\n", ptr3);
    printf("Test 138 - Length modifier (not permitted): %.5p\n", ptr3);
    printf("Test 139 - Integer with hash flag (not permitted): %#d\n", 42);
    printf("Test 140 - Non-existent specifier: %w\n", 42);
    printf("Test 141 - Reversed specifiers: d%\n");
    printf("Test 142 - All non-permitted flags: %0#+ d\n", 42);
    printf("Test 143 - Hexadecimal with plus (not permitted) (x): %+x\n", hexValue);
    printf("Test 144 - Hexadecimal with space (not permitted) (X): % X\n", hexValue);
    printf("Test 145 - Percent sign: %%\n");
    printf("Test 146 - Percent sign with width: %5%\n");
    printf("Test 147 - Percent sign left-justified: %-5%\n");
    printf("Test 148 - Invalid flag with percent: %+#%\n");
    printf("Test 149 - Zero padding with percent: %05%\n");
    printf("Test 150 - Multiple percent signs: %% %% %%\n");
    printf("Test 151 - Percent sign: %%\n");
    printf("Test 152 - Large number (i): %i\n", 21474836470);
    printf("Test 153 - Above max int (i): %i\n", INT_MAX + 1);
    printf("Test 154 - Below min int (i): %i\n", INT_MIN - 1);
    printf("Test 155 - Very large number (d): %d\n", large_num);
    printf("Test 156 - Int overflow: %d\n", INT_MAX + 1);
    printf("Test 157 - Int underflow: %d\n", INT_MIN - 1);

    return 0;
}
