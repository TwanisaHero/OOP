## P01 - Fraction Class  
### Author: Antwan Taylor  
### Date: December 2024  

### Description:  
The **Fraction Class** project implements a robust C++ class for performing arithmetic operations and equality checks with fractions. This program demonstrates operator overloading and effective fraction management using mathematical techniques like Least Common Denominator (LCD) and Least Common Multiple (LCM).  

Key features include:  
- Overloaded operators for arithmetic (`+`, `-`, `*`, `/`) and equality checks (`==`).  
- Custom input/output handling using the `<<` operator.  
- Helper methods for simplifying and managing fractions.  
- Separation of class definition and implementation for clarity and maintainability.  

### Files  

|   #   | File             | Description                                                                 |
| :---: | ---------------- | --------------------------------------------------------------------------- |
|   1   | `program1.cpp`   | Contains the implementation of the `Fraction` class and sample operations.  |
|   2   | `fractions.txt`  | Input file with test cases for fraction operations.                         |

### Prerequisites:  
- A working C++ compiler (e.g., GCC or Clang).  
- Ensure the files `program1.cpp` and `fractions.txt` are in the same directory before running the program.  

### Instructions  

| Step | Action | Command/Format |
| ---- | ------ | -------------- |
| 1 | **Compilation** | Compile the program using a C++ compiler: |
|   | | ```bash g++ program1.cpp -o program1 ``` |
| 2 | **Running the Program** | Once compiled, run the program by executing: |
|   | | ```bash ./program1 ``` |
| 3 | **Input File Format** | The input file (`fractions.txt`) should contain operations in the format: |
|   | | ```<fraction1> <operator> <fraction2>``` |
|   | | Example: |
|   | | ```
1/2 + 3/4  
5/6 - 1/3  
7/8 * 2/3  
4/5 / 1/5  
``` |
| 4 | **Expected Output** | The program will process the operations and display the results in the format: |
|   | | ```
1/2 + 3/4 = 5/4  
5/6 - 1/3 = 1/2  
7/8 * 2/3 = 7/12  
4/5 / 1/5 = 4  
``` |
| 5 | **Notes** | - The program automatically simplifies results to their lowest terms. |
|   | | - Invalid input formats will trigger an error message and prompt re-entry. |

### Notes:  
- The program simplifies results to their lowest terms automatically.  
- Invalid input formats will produce error messages and prompt re-entry.  
