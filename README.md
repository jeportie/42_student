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

	- It checks if total_size is 0 or if dst is already full 
	(dst_len == total_size),in which case it returns the total length dst would 
	have after concatenation.

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

	- The maximum number of characters to append is total_size - strlen(dst) - 1 
	= 10 - 5 - 1 = 4.

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
	
# PASSING A POINTER BY REFERENCE 

Example : ft_split
In your ft_extract_word function, the use of "**s" instead of *s is related to how
you want to modify the pointer s in the calling function (ft_split) from within 
ft_extract_word. This is a common technique in C for modifying a pointer through
a function call, often referred to as "passing a pointer by reference".

Let's break it down:

Pointer to a Pointer ("**s"): When you pass &s to ft_extract_word from ft_split, 
you are passing a pointer to the pointer s. Inside ft_extract_word, s is then a 
pointer to a pointer to char, or char "**". This allows you to modify where the 
original pointer s (in ft_split) is pointing.

Dereferencing Once (*s): When you use *s inside ft_extract_word, you are 
accessing the value that s points to, which is the original char * pointer in 
ft_split. This is useful for reading or writing the data at the location pointed
to by the original s.

Dereferencing Twice ("**s"): When you use "**s", you are accessing the value pointed
to by the pointer that s points to. In this case, it's the actual characters in 
the string that s is iterating over.

Example:

ft_split has a pointer s that points to the current character in the string.
You want ft_extract_word to move this pointer s as it processes the string.
To achieve this, you pass the address of s (&s, which is char "**") to 
ft_extract_word.
Inside ft_extract_word, you use *s to access and work with the original string 
and "**s" to access individual characters.
When you modify *s (like *s += strlen), you're changing where the original s in 
ft_split is pointing.
This technique is essential when you need a function to modify the address that 
a pointer is pointing to, rather than just modifying the data at the address the
pointer is currently pointing to.

# HANDLE NEW_LST FUNCTIONS MEMORY ALLOCATION OR NOT

hether to duplicate strings or directly assign pointers in a list node depends 
on the context and design of your function. Let's break down these two scenarios:

Defined Type (e.g., String):

When your list node specifically expects a string (or any other defined data type),
duplicating the string is often safer and more robust. This duplication ensures
that the list node owns its data and is not affected by changes or deallocations
outside the list.
This approach isolates each node's data, making your code more predictable and 
less prone to bugs related to shared memory or dangling pointers.
Undefined Type (e.g., void *):

When your list node is designed to hold a generic pointer (void *), it typically
doesn't duplicate the data it's pointing to. This is because it's designed for 
general use, and it doesn't know the specifics of what it's storing.
In this case, the responsibility for managing the memory of the data 
(like allocation and deallocation) lies outside the list. The list merely holds
a reference to the data.
This approach is flexible but requires careful memory management. 
The code using the list must ensure that the memory pointed to by these generic
pointers is correctly managed.

Here's a quick summary:

Duplicate in Defined Type: When the list node type is defined (like a string), 
duplicating the data within the list node is a good practice. 
This ensures that each node fully controls and manages its own data.

Direct Assignment in Undefined Type: When the list node holds a void * for 
generic data, it typically just stores the pointer passed to it. 
The caller is responsible for managing the actual data's memory.

This decision is about balancing memory efficiency, flexibility, and safety. 
Duplicating data can prevent many issues but at the cost of additional memory 
usage and processing. Directly assigning pointers is more efficient but requires
careful memory management to avoid issues like memory leaks or dangling pointers.

