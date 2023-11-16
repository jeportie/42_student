# 42_student
git respo of all my 42 projects



# LEARNING LESSONS

-> Cast and working with bytes:

In C, void pointers are generic pointers that can point to any data type. 
However, you can't directly dereference a void pointer since the compiler 
doesn't know its actual type and size. To work around this, you should cast 
your void pointers to unsigned char pointers. This is because unsigned char is 
guaranteed to be 1 byte in size, which is perfect for byte-by-byte comparison.

-> ft_strlcat explained :

Let's break down the behavior of ft_strlcat with a visual example for clarity.

	- The function calculates the length of dst and src.

	- It checks if total_size is 0 or if dst is already full (dst_len == total_size),
	in which case it returns the total length dst would have after 
	concatenation.

	- It then appends characters from src to dst, being careful not to write 
	more characters than total_size - 1.

	 -It always null-terminates dst, provided total_size is not 0.

	 - Finally, it returns the total length of the string it tried to create, 
	 which is the sum of the lengths of dst and src.

The strlcat function concatenates strings with the same input parameters as 
strncat, but unlike strncat, it takes the full total_size of the buffer 
(not just the length) and guarantees to NUL-terminate the result 
(as long as there is at least one byte free in dst). 
Importantly, ft_strlcat do not overflow the destination buffer.

Here's the key point:

	- ft_strlcat will append at most total_size - strlen(dst) - 1 characters from 
	src to dst.

This means that it will append characters from src to the end of dst, but it
will stop appending either when it has added total_size - strlen(dst) - 1 
characters, or when it reaches the end of src, whichever comes first. 
The -1 is to leave space for the null terminator.

Example:

Let's say we have a destination string dst and a source string src:

	- dst = "Hello"

	- src = "World"

	- total_size = 10 (the total total_size of the dst buffer)

Initial state of dst buffer: ["H", "e", "l", "l", "o", "\0", "?", "?", "?", "?"]
(where "?" represents uninitialized space).

Now, let's apply ft_strlcat:

	- The length of dst (strlen(dst)) is 5.

	- The maximum number of characters to append is total_size - strlen(dst) - 1 =
	10 - 5 - 1 = 4.

	- So, ft_strlcat will append at most 4 characters from src to dst.

After ft_strlcat:

	- dst = "HelloWorl"

	- Final state of dst buffer: 
	  ["H", "e", "l", "l", "o", "W", "o", "r", "l", "\0"].

Notice that only 4 characters from src were appended to dst, and the result was 
null-terminated.

Conclusion:

	- The function ensures that dst is null-terminated after appending 
	characters from src.

	- It appends characters based on the available space in dst, accounting for
	its current length and the total buffer size (total_size).

	- It returns the total length of the string it tried to create, not the 
	length of the string actually created. In the example, it would return 9 
	(length of "Hello" + length of "World"), even though it only appended part 
	of "World" due to size constraints.
