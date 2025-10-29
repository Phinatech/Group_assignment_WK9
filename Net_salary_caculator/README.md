# 🧮 Net Salary Calculator (C Program Using Pointers)

## Project Description
This C program calculates an employee’s **net salary** from a given **gross salary** after applying all required deductions.  
The program demonstrates the use of **pointers**, **modular programming**, and **functions**.

Each deduction is implemented in its own function, and all deductions are called inside a main `net_salary()` function.  
Only the `main()` function does not use pointers.

---

## Deductions and Rules

1. **Tax on Salary**
   - If salary ≤ $100 → 0%
   - If salary > $100 and ≤ $300 → 20%
   - If salary > $300 → 28%

2. **Medication Insurance** → 5% of gross salary  
3. **Maternity Leave** → 0.3% of gross salary  
4. **Social Security Fund** → 3% of gross salary  

Each deduction is calculated by a separate function that uses pointers.

---

## Program Flow
1. User enters **gross salary**.  
2. The program calls the four deduction functions (each using pointers).  
3. The deductions are added together.  
4. The **net salary** is calculated and printed to the user.

---

## Folder Structure
net-salary-calculator/
├── include/
│ └── salary.h
├── src/
│ ├── deductions.c
│ ├── net_salary.c
│ └── main.c
├── Makefile
└── README.md

## Advantages of Using Pointers

1. Pass by reference: Functions can directly modify variables without returning multiple values.

2. Return multiple results: The net_salary() function can calculate and update several deductions at once.

3. Efficient memory use: No unnecessary copying of data between functions.

4. Foundation for advanced memory handling: Prepares students for arrays, strings, and dynamic memory.

5. Cleaner modular code: Each function handles one task and communicates using pointers.


## How to Compile and Run

```bash
# Compile the program
make

# Run the program
./net_salary

