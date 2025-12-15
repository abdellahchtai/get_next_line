# get_next_line

This project was developed as part of the **42 curriculum**.

Author: **abchtaib**

---

## 📌 Overview

`get_next_line` is a C function that reads a file descriptor and returns **one line at a time**, including the terminating newline character (`\n`) when present. Each subsequent call returns the next line until the **end of file (EOF)** is reached, at which point the function returns `NULL`.

The size of the read buffer is configurable at **compile time** using the `BUFFER_SIZE` macro.

---

## 🎯 Objectives

* Read from a file descriptor using a configurable buffer size
* Return exactly one line per function call
* Preserve unread data between calls
* Correctly handle:

  * Files with or without a trailing newline
  * Very large buffer sizes
  * Read errors
* Avoid memory leaks and invalid memory access

---

## ⚙️ Function Prototype

```c
char *get_next_line(int fd);
```

---

## 🧠 Core Concept: Static Variable

To preserve leftover data after a newline is returned, the implementation relies on a **static variable**.

Key properties of a static variable in C:

* Initialized only **once** during program execution
* Retains its value between function calls
* Stored in the **static/global memory segment**, not on the stack

This allows `get_next_line` to remember the remainder of the buffer that was read but not yet returned.

---

## 🛠️ Algorithm Description

The implementation follows these steps:

1. **Read from the file descriptor**

   * Allocate a buffer of size `BUFFER_SIZE + 1`
   * Use `read()` to fill the buffer
   * Append a null terminator (`\0`)

2. **Accumulate data**

   * Concatenate the newly read buffer with a static string using a custom `strjoin`

3. **Search for a newline**

   * Detect the presence of `\n`
   * If no newline is found, continue reading and appending

4. **Extract the line**

   * Separate and return the first line
   * Store the remaining data for the next call

5. **Error and EOF handling**

   * On read error, free allocated memory and return `NULL`
   * On EOF, return remaining data if any, otherwise `NULL`

---

## 📦 Compilation Instructions

To compile the project, define the buffer size at compile time using the `BUFFER_SIZE` macro.

Example:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
    get_next_line.c get_next_line_utils.c main.c -o gnl
```

You can adjust the buffer size as needed:

```bash
gcc -D BUFFER_SIZE=1024 get_next_line.c get_next_line_utils.c main.c -o gnl
```

Run the program:

```bash
./gnl
```

---

## 🚫 Common Pitfalls Addressed

* Memory leaks caused by forgotten `free()` calls
* Writing past allocated buffers
* Losing leftover data between function calls
* Incorrect handling of files without a trailing newline

---

## 📚 References & Learning Resources

* Wikipedia — *Static Variables in C*
* Linux Manual Pages — `read(2)`, `open(2)`, `close(2)`
* GNU C Library Documentation
* 42 Network official subject: **get_next_line**
* YouTube tutorials on file descriptors and memory management

These resources were used to understand low-level I/O, memory behavior, and static storage duration in C.

---

## ✅ Conclusion

This project reinforces fundamental concepts of:

* Low-level file I/O
* Memory allocation and deallocation
* Static storage duration
* Defensive programming and debugging

`get_next_line` is a foundational exercise for writing safe, efficient, and reusable C code.
