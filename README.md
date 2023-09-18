# printf() - Custom printf Function

## Introduction

The **printf()** project is a collaborative effort by **Youssef Ahmed** and **Mariam Ahmed**, students of the ALX Software Engineering Programme at Holberton School. This project aims to create a custom function named "**_printf**" that emulates the functionality of the standard "printf" command found in the **stdio.h** library. This custom implementation provides a subset of the basic features and functions available in the manual 3 of "printf".

## Function Prototype

The **_printf()** function is designed to perform formatted output conversion and print data. Its prototype is as follows:

```c
int _printf(const char *format, ...);
```

Here, the **format** parameter is a string containing the text to be printed. Since **_printf()** is a variadic function, it can accept a variable number of arguments that correspond to placeholders within the format string.

## Format Tags

The format string follows a specific pattern for placeholders, which has the following prototype:

```
%[flags][length]specifier
```

- **Specifier** represents the data type to be printed.
- **Flags** modify the output format.
- **Length** specifies the length of the data type.

## Supported Specifiers

- **c**: Character
- **d** or **i**: Signed decimal integer
- **s**: String of characters
- **b**: Signed binary
- **o**: Signed octal
- **u**: Unsigned integer
- **x**: Unsigned hexadecimal
- **X**: Unsigned hexadecimal (uppercase)
- **p**: Pointer address
- **r**: Reverse string of characters
- **R**: ROT13 translation of a string
- **S**: String with special characters replaced by their ASCII value
- **%**: Character

## Supported Flags

- **+**: Prints a plus sign (+) when the argument is a positive number (for **i** and **d** specifiers).
- **(space)**: Prints a blank space if the argument is a positive number (for **i** and **d** specifiers).
- **#**: Prints "0," "0x," and "0X" for **o**, **x**, and **X** specifiers, respectively, but does not print anything if the argument is zero.

## Supported Lengths

- **l**: Prints a long int or unsigned long int (for **i**, **d**, **o**, **u**, **x**, and **X** specifiers).
- **h**: Prints a short int or unsigned short int (for **i**, **d**, **o**, **u**, **x**, and **X** specifiers).

## Return Value

If the **_printf()** function runs successfully, it returns the number of characters printed.

## Examples

1. Printing the string "Hello, Holberton":
   - Code: `_printf("Hello Hol%s.", "berton");`
   - Output: `Hello Holberton.`

2. Printing an integer number:
   - Code: `_printf("10 + 10 is equal to %d.", 20);`
   - Output: `10 + 10 is equal to 20.`

3. Printing binary, octal, and hexadecimal numbers:
   - Code: `_printf("10 in binary is [%b], in octal is [%o], and in hexadecimal is [%x]", 5, 5, 5);`
   - Output: `10 in binary is [1010], in octal is [12], and in hexadecimal is [A]`

4. Printing a string encoded in ROT13:
   - Code: `_printf("Hello in ROT13 is %R", "Hello");`
   - Output: `Hello in ROT13 is Urybb`

## Using Flags and Length Tags

5. Printing the string "Hello, Holberton" with plus and minus signs:
   - Code: `_printf("2 * 2 = %+d and 5 * -5 = %+i", 4, -25);`
   - Output: `2 * 2 = +4 and 5 * -5 = -25`

6. Printing a long integer number and a short integer number:
   - Code: `_printf("1 million as a long int is %ld, but as a short int is %hd", 1000000, 1000000);`
   - Output: `1 million as a long int is 1000000, but as a short int is 16960`

## Project Files

- **_printf.c**: This file contains the custom printf function implementation.
- **main.h**: The header file where all function prototypes are defined.

## Authors

- Youssef Ahmed (Email:cstfre@gmail.com)
- Mariam Ahmed (Email:mariamahmd607@gmail.com)

## Conclusion

The **printf()** project provides a custom implementation of the printf function, allowing you to format and print text in various ways. It offers support for a range of specifiers, flags, and length modifiers, making it a versatile tool for text formatting in C programming.
