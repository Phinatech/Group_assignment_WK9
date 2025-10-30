# Sorting Names Program
## Question 2 - Bubble Sort with Function Pointers

---

## Description
A C program that sorts 20 full names in either ascending or descending order using the bubble sort algorithm. The program utilizes function pointers to provide flexible ordering based on user input.

---

## Features
- User input for 20 full names
- Bubble sort implementation
- Function pointers for dynamic comparison logic
- Support for ascending and descending order
- Case-insensitive sort order selection
- Input validation with default fallback

---

## Requirements
- GCC compiler (or any standard C compiler)
- Standard C libraries: `stdio.h`, `string.h`, `ctype.h`

---

## Compilation

```bash
gcc -o name_sorter sort.c
```

Or with warnings enabled:
```bash
gcc -Wall -o name_sorter sort.c
```

---

## Usage

1. **Run the program:**
   ```bash
   ./name_sorter
   ```

2. **Enter 20 full names** when prompted (one per line)

3. **Choose sort order:**
   - Type `asc` for ascending order (A-Z)
   - Type `desc` for descending order (Z-A)

4. **View results:** The program displays all names in the selected order

---

## Example Run

```
=== NAME SORTING PROGRAM ===
Please enter 20 full names:
----------------------------
Enter name 1: John Smith
Enter name 2: Alice Johnson
...
Enter name 20: Bob Williams

----------------------------
Enter 'asc' for ascending order or 'desc' for descending order: asc

Sorting in ASCENDING order...

Sorted names:
----------------------------
 1. Alice Johnson
 2. Bob Williams
 3. John Smith
...
```

---

## Technical Implementation

### Function Pointers
```c
typedef int (*CompareFunc)(const char*, const char*);
```
- `compareAscending()`: Uses `strcmp()` directly
- `compareDescending()`: Reverses `strcmp()` parameters

### Bubble Sort
- Time Complexity: O(n²)
- Space Complexity: O(1)
- Stable sorting algorithm
- Accepts comparison function as parameter

---

## File Structure
```
sort.c          # Main program file
README.md       # This file
```

---

## Author
**Tamunotonye Briggs**  

---

## Notes
- Maximum name length: 50 characters
- Input is case-insensitive for sort order selection
- Invalid sort order defaults to ascending
