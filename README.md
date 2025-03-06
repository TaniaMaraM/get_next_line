# Get Next Line

![Get Next Line Badge](https://github.com/ayogun/42-project-badges/blob/main/badges/get_next_linem.png?raw=true)

## Description

The **Get Next Line** project is a challenge that aims to create a function that reads a line from a file descriptor, one line at a time. The goal is to efficiently handle memory allocation, manage buffers, and process large files in a way that ensures no memory leaks or unnecessary resource consumption.

The project is implemented in C and adheres strictly to the norms and guidelines of the 42 School.

### Core Functionality

- **`get_next_line()`** reads one line at a time from a given file descriptor.
- The function uses a static buffer to store unprocessed data between successive calls.
- The function is robust and handles different cases, such as files with or without newlines, empty files, and large files.
- The memory is managed efficiently, ensuring no memory leaks and proper cleanup of unused data.
- The program handles both files and standard input (`stdin`).

## Files

This project consists of the following files:

- **[get_next_line.c](get_next_line.c)**: Contains the main logic for reading lines from a file descriptor.
- **[get_next_line.h](get_next_line.h)**: The header file containing the function prototypes and necessary includes.
- **[get_next_line_utils.c](get_next_line_utils.c)**: A utility file with helper functions for string manipulation and memory management.
- **[get_next_line_bonus.c](get_next_line_bonus.c)**: Contains the bonus part of the project that manages multiple file descriptors.
- **[get_next_line_bonus.h](get_next_line_bonus.h)**: Header file for the bonus part.
- **[get_next_line_utils_bonus.c](get_next_line_utils_bonus.c)**: Contains the utility functions used in the bonus part.

---

## Mandatory Part

The mandatory part of this project consists of the following functions:

### **`get_next_line()`**

Reads one line from a file descriptor.

- **Parameters**: `fd` - The file descriptor to read from.
- **Returns**: A string containing the next line from the file, including the newline character (`\n`) if present. Returns `NULL` when the end of the file is reached.

---

### **`ft_find_newline()`**

Finds the index of the first occurrence of the newline character (`\n`) in a string.

- **Parameters**: `str` - The string to search in.
- **Returns**: The index of the first newline, or `-1` if not found.

This function iterates over a string and looks for the first occurrence of the newline character (`\n`). If found, it returns the index of that position. If no newline is present, it returns `-1`.

---

### **`ft_extract_line()`**

Extracts a line from the buffer up to the first newline character (`\n`).

- **Parameters**: `keep` - The string to extract the line from.
- **Returns**: A newly allocated string containing the extracted line, or `NULL` if memory allocation fails.

This function takes the current buffer and extracts a line starting from the beginning of the buffer up to (and including) the first newline character. If no newline is found, the function returns the entire buffer. The extracted line is returned as a new string, and memory is dynamically allocated for it.

---

### **`ft_update_keep()`**

Updates the buffer by retaining the content after the newline (`\n`).

- **Parameters**: `keep` - The current buffer.
- **Returns**: A new string with the content after the newline, or `NULL` if no content remains.

This function is responsible for updating the buffer after extracting a line. It removes the portion that was extracted (including the newline) and keeps the remaining content. The updated buffer is returned, and memory is managed accordingly.

---

### **`ft_read_file()`**

Reads data from a file descriptor and updates the buffer with the new content.

- **Parameters**: `fd` - The file descriptor. `keep` - The buffer to update.
- **Returns**: A string with the updated buffer, or `NULL` if no data is available or an error occurs.

This function handles reading from a file descriptor. It uses a temporary buffer to read data from the file and appends it to the existing `keep` buffer. It ensures that the buffer is updated properly and keeps track of any unprocessed data for subsequent reads.

---
## Utility Functions (get_next_line_utils.c)

The utility functions are essential for supporting the core functionality of `get_next_line()`. They handle basic string operations and memory management.

### **`ft_strlen()`**

Calculates and returns the length of a string by traversing it until it finds the null character (`\0`).

- **Parameters**: `str` - The string whose length needs to be calculated.
- **Returns**: The length of the string (excluding the null terminator).

---

### **`ft_strchr()`**

Searches for the first occurrence of a character in a string and returns a pointer to that position. If the character is not found, it returns `NULL`. If the character is `\0`, it returns a pointer to the null terminator.

- **Parameters**: `str` - The string to search in. `c` - The character to search for.
- **Returns**: A pointer to the first occurrence of the character, or `NULL` if not found.

---

### **`ft_substr()`**

Creates a new string that is a substring of the original string. It is perfect for extracting a line up to the newline character (`\n`) or any other specific part of the string. This is particularly useful for managing large buffers, as it allows working with specific portions of the string without overloading memory with unnecessary data.

- **Parameters**: `s` - The original string. `start` - The starting index of the substring. `len` - The length of the substring.
- **Returns**: A new string containing the specified substring, or `NULL` if memory allocation fails.

---

### **`ft_strjoin()`**

Concatenates two strings. It allocates memory for the new string, copies the content of both strings into the new allocation, and returns the concatenated string.

- **Parameters**: `s1` - The first string. `s2` - The second string.
- **Returns**: A newly allocated string that is the result of concatenating `s1` and `s2`, or `NULL` if memory allocation fails.

---

### **`ft_calloc()`**

Allocates memory for a specified number of elements, each of a given size, and initializes the memory to zeros. It returns a pointer to the allocated memory or `NULL` if there is an allocation failure (e.g., out of memory).

- **Parameters**: `nmemb` - The number of elements. `size` - The size of each element.
- **Returns**: A pointer to the allocated memory, or `NULL` if allocation fails.

---

## Bonus Part

In the bonus part, additional functionality is added to `get_next_line` to handle multiple file descriptors while using only one static variable. Below are the key changes made to achieve this functionality:

### 1. **Using an Array of Static Pointers**
   - Initially, the function used a single static variable (`static char *keep`) to store the data read from the file descriptor. However, the bonus requires the handling of multiple file descriptors.
   - To handle this, an array of static pointers (`static char *keep[1042]`) was introduced, where each index corresponds to a different file descriptor (`fd`). This allows the function to maintain separate buffers for each file descriptor, enabling independent reading from multiple files.

### 2. **Reading Data for Each File Descriptor**
   - Each file descriptor now has its own buffer. The line `keep[fd] = ft_read_file(fd, keep[fd]);` updates the buffer for the specific file descriptor each time `get_next_line` is called. This ensures that the data is read independently for each file descriptor and that no data is mixed up between them.

### 3. **Line Extraction and Buffer Update per File Descriptor**
   - After reading the data, the function extracts the line from the buffer corresponding to the current file descriptor using `line = ft_extract_line(keep[fd]);`.
   - Then, the buffer for that file descriptor is updated with the remaining data (if any) using `keep[fd] = ft_update_keep(keep[fd]);`. This ensures that each file descriptor maintains its own state, and the reading process continues smoothly without interfering with other file descriptors.

### 4. **Why This is Important**
   - These changes enable the function to handle multiple file descriptors at the same time without losing track of the reading state of each file descriptor.
   - By using an array of static pointers, the function can now read from different file descriptors in sequence without mixing the lines read from different files.
   - This is especially useful in real-world applications where multiple files are often opened and read at the same time, ensuring that data from different files is managed properly and independently.

## Tester
This repository includes a tester, allowing you to easily test your code and check if it handles the various edge cases and formatting correctly. Enjoy testing!

![Build Status](https://img.shields.io/badge/build-passing-brightgreen)

---



