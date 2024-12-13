# P02A - Ncurses Test  

## Author: Antwan Taylor  
## Date: December 2024  

### Description  
This program tests the installation of the `ncurses` library on Windows 11 using Windows Subsystem for Linux (WSL). It involves writing a simple C++ program that uses the `ncurses` library to display a "Hello, World!" message on the screen. The program demonstrates the basic functionality of `ncurses` in initializing the screen, displaying a message, and waiting for user input before closing the program.

### Files  

|   #   | File               | Description                                               |
| :---: | ------------------ | --------------------------------------------------------- |
|   1   | `hello_ncurses.cpp` | The C++ source code for the "Hello, World!" program using the `ncurses` library. |

### Prerequisites:  
- **WSL (Windows Subsystem for Linux)** must be installed on Windows 11.  
- **Ncurses library** must be installed in the WSL environment.

### Instructions  

| Step | Action                            | Command/Format                           |
| ---- | --------------------------------- | ---------------------------------------- |
| 1    | **Install WSL**                   | Follow the official Microsoft guide to install WSL on Windows 11. |
| 2    | **Install Ncurses Library**       | In WSL, run `sudo apt-get install libncurses5-dev` to install ncurses. |
| 3    | **Write the Program**             | Write a simple "Hello, World!" program using `ncurses` to test the installation. |
| 4    | **Compile and Run the Program**   | Compile using: `g++ hello_ncurses.cpp -o hello_ncurses -lncurses` and run with: `./hello_ncurses` |

### Program Flow  

- The program initializes the ncurses environment.  
- It displays "Hello, World!" on the screen.  
- It waits for user input before ending the program and restoring normal terminal behavior.

### Screenshots Below:  
![Ncurses Screenshot](img.png)
