# Student Email Memory Management
## Question 3 - Dynamic Memory Allocation & Shrinking

---

## Description
A C program demonstrating dynamic memory management for storing student email addresses. The program allocates memory for 10 students, then shrinks the allocation to 6 students while preserving existing data, showcasing proper use of `malloc()`, `realloc()`, and `free()`.

---

## Features
- Dynamic memory allocation using `malloc()`
- Two-level memory management (array + individual strings)
- Memory shrinking from 10 to 6 students using `realloc()`
- Data preservation during memory operations
- Comprehensive memory cleanup with `free()`
- Error handling for allocation failures
- Memory address tracking for educational purposes

---

## Requirements
- GCC compiler (or any standard C compiler)
- Standard C libraries: `stdio.h`, `stdlib.h`, `string.h`

---

## Compilation

```bash
gcc -o student_memory memory_management.c
```

Or with warnings enabled:
```bash
gcc -Wall -o student_memory memory_management.c
```

---

## Usage

1. **Run the program:**
   ```bash
   ./student_memory
   ```

2. **Enter 10 email addresses** when prompted

3. **View operations:** The program automatically:
   - Displays all 10 emails
   - Shrinks memory to 6 students
   - Shows remaining 6 emails
   - Frees all allocated memory

---

## Example Run

```
=== STUDENT EMAIL MANAGEMENT SYSTEM ===
2023 May Cohort

Allocating memory for 10 students...
Memory allocated successfully at address: 0x7f8b2c004000

Enter email addresses for 10 students:
Student 1 email: john.smith@example.com
Student 2 email: alice.johnson@example.com
...
Student 10 email: bob.williams@example.com

=== INITIAL DATA ===
--- Student Email Addresses ---
Student 1: john.smith@example.com
...
Student 10: bob.williams@example.com

=== SHRINKING MEMORY ===
Reducing cohort size from 10 to 6 students...
Freeing memory for students 7 to 10...
Reallocating array to smaller size...
Memory successfully shrunk!

=== AFTER SHRINKING ===
--- Student Email Addresses ---
Student 1: john.smith@example.com
...
Student 6: emily.davis@example.com

=== CLEANUP ===
Freeing all remaining allocated memory...
All memory freed successfully!
```

---

## Technical Implementation

### Memory Allocation Strategy
```c
// Level 1: Array of pointers
char **emails = malloc(10 * sizeof(char *));

// Level 2: Individual email strings
emails[i] = malloc((strlen(buffer) + 1) * sizeof(char));
```

### Shrinking Process
1. Free individual strings for students 7-10
2. Use `realloc()` to shrink pointer array from 10 to 6
3. First 6 students' data remains intact

### Memory Safety
- NULL checks after every allocation
- Systematic deallocation to prevent leaks
- Graceful handling of allocation failures 

---

## Key Functions

- **`malloc()`**: Initial allocation for array and strings
- **`realloc()`**: Shrinks array from 10 to 6 pointers
- **`free()`**: Deallocates all memory before exit
- **`displayEmails()`**: Shows current student list
- **`freeMemory()`**: Systematic cleanup helper

---

## File Structure
```
memory_management.c    # Main program file
README.md              # This file
```
---

## Author
**Tamunotonye Briggs**  

---

## Notes
- Maximum email length: 100 characters
- Memory addresses displayed for educational demonstration
- Shrinking preserves first 6 students' data
- All allocated memory is properly freed before program exit
