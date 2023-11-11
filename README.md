# 42_student
git respo of all my 42 projects



# LEARNING LESSONS

-> Cast and working with bytes:

In C, void pointers are generic pointers that can point to any data type. 
However, you can't directly dereference a void pointer since the compiler 
doesn't know its actual type and size. To work around this, you should cast 
your void pointers to unsigned char pointers. This is because unsigned char is 
guaranteed to be 1 byte in size, which is perfect for byte-by-byte comparison.
