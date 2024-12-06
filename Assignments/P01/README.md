 ## P01 - Fraction Class  
 
 ### Name: Antwan Taylor 

 ### Description  

 This program implements a robust `Fraction` class in C++ that supports arithmetic operations and equality checks through operator overloading. The class is designed to handle fractions efficiently by leveraging methods like Least Common Denominator (LCD) and Least Common Multiple (LCM) for accurate arithmetic. The implementation follows best practices, separating the class definition from its implementation using the scope resolution operator (`::`).  

 Key features include:  
 - Overloaded operators: `+`, `-`, `*`, `/`, and `==`.  
 - Support for input/output via custom methods and the `<<` operator.  
 - Helper methods to simplify and manage fractions.  

 ### Files  

 |   #   | File              | Description                                                                 |
 | :---: | ----------------- | --------------------------------------------------------------------------- |
 |   1   | program1.cpp      | Main program implementing the `Fraction` class and performing arithmetic operations. |
 |   2   | fractions.txt     | Input file containing fractions and operations for testing.                 |

 ### Instructions  

 1. **Setup**:  
   - Place `program1.cpp` and `fractions.txt` in the same directory.  

 2. **Compilation**:  
   - Use a C++ compiler to build the program:  
     ```bash  
     g++ program1.cpp -o program1  
     ```  

 3. **Running the Program**:  
   - Run the program with the input file:  
     ```bash  
     ./program1  
     ```  

 4. **Input File Format**:  
   The input file (`fractions.txt`) should contain operations in the following format:  
   1/2 + 3/4
   5/6 - 1/3
   7/8 * 2/3
   4/5 / 1/5 
   
 5. **Example Output**:   
   1/2 + 3/4 = 5/4
   5/6 - 1/3 = 1/2



