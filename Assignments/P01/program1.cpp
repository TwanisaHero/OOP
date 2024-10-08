/*****************************************************************************
 *
 *  Author:        Antwan Taylor
 *  Label:         P01
 *  Title:         Program 1 - Fraction Class
 *  Course:        2143-Object-Oriented-Programming
 *  Semester:      Fall Semester 2024
 *
 *  Description:
 *      This program defines a Fraction class that represents a mathematical
 *      fraction and provides methods for performing arithmetic operations
 *      with fractions. The class ensures fractions are stored in their
 *      simplest form.
 *
 *  Usage:
 *      To create a fraction, use the constructor:
 *      To perform arithmetic operations:
 *      cout << result; // Outputs the result
 *
 *  Files: fractions.txt (input file containing fractions and operations)
 *****************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>  // for stringstream
using namespace std;

// Helper function to calculate the Greatest Common Divisor (GCD)
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Helper function to calculate the Least Common Multiple (LCM)
int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

/**
 * Fraction Class
 *
 * Description:
 *      Represents a mathematical fraction and provides methods for
 *      performing arithmetic operations.
 *
 * Public Methods:
 *     
 *       - Fraction(int num = 0, int den = 1): Constructor to create
 *        a fraction with a specified numerator and denominator.
 *    
 *       - Fraction operator+(const Fraction& other) const: Adds two
 *        fractions and returns the result as a new Fraction.
 *     
 *      - Fraction operator-(const Fraction& other) const: Subtracts
 *        another fraction from this fraction and returns the result.
 *     
 *      - Fraction operator*(const Fraction& other) const: Multiplies
 *        this fraction by another fraction and returns the result.
 *     
 *       - Fraction operator/(const Fraction& other) const: Divides
 *        this fraction by another fraction and returns the result.
 *      
 *       - friend ostream& operator<<(ostream& os, const Fraction& frac):
 *        Overloaded output operator to print the fraction.
 *
 * Private Methods:
 *      - void reduce(): Reduces the fraction to its simplest form
 *        by dividing the numerator and denominator by their GCD.
 *
 * Usage:
 *       To create a fraction, use the constructor:
 *      
 *       To perform arithmetic operations:
 *     
 *       Fraction result = f1 + f2; // Adds fractions
 *        
 *        cout << result; // Outputs the result
 */
class Fraction
{
private:
    int numerator;   // Numerator of the fraction
    int denominator; // Denominator of the fraction

    // Helper function to reduce the fraction
    void reduce()
    {
        int commonDivisor = gcd(numerator, denominator);
        numerator /= commonDivisor;
        denominator /= commonDivisor;
    }

public:
    // Constructor
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den)
    {
        if (den == 0)
        {
            cout << "ERROR! Denominator cannot be zero." << endl;
            numerator = 0;
            denominator = 1;
        }
        else
        {
            reduce();
        }
    }

    // Overloaded addition operator
    Fraction operator+(const Fraction& other) const
    {
        int commonDenominator = lcm(denominator, other.denominator);
        int adjustedNumerator1 = numerator * (commonDenominator / denominator);
        int adjustedNumerator2 = other.numerator * (commonDenominator / other.denominator);
        int resultNumerator = adjustedNumerator1 + adjustedNumerator2;

        return Fraction(resultNumerator, commonDenominator);
    }

    // Overloaded subtraction operator
    Fraction operator-(const Fraction& other) const
    {
        int commonDenominator = lcm(denominator, other.denominator);
        int adjustedNumerator1 = numerator * (commonDenominator / denominator);
        int adjustedNumerator2 = other.numerator * (commonDenominator / other.denominator);
        int resultNumerator = adjustedNumerator1 - adjustedNumerator2;

        return Fraction(resultNumerator, commonDenominator);
    }

    // Overloaded multiplication operator
    Fraction operator*(const Fraction& other) const
    {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    // Overloaded division operator
    Fraction operator/(const Fraction& other) const
    {
        if (other.numerator == 0)
        {
            cout << "ERROR! Cannot divide by zero." << endl;
            return Fraction(0, 1);
        }
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    // Overloaded output operator (<<) for printing fractions
    friend ostream& operator<<(ostream& os, const Fraction& frac)
    {
        if (frac.denominator == 1)
        {
            os << frac.numerator; // Print as whole number if denominator is 1
        }
        else
        {
            os << frac.numerator << "/" << frac.denominator;
        }
        return os;
    }
};

// Function to parse fraction from string
Fraction parseFraction(const string& str)
{
    size_t slashPos = str.find('/');                  // Find the position of the slash
    string numeratorStr = str.substr(0, slashPos);    // Extract the numerator
    string denominatorStr = str.substr(slashPos + 1); // Extract the denominator

    int num, den;
    stringstream(numeratorStr) >> num;
    stringstream(denominatorStr) >> den;

    return Fraction(num, den);
}

int main()
{
    ifstream inputFile("fractions.txt");  // Input file containing fractions and operations
    if (!inputFile)
    {
        cout << "Error opening file!" << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line))
    {
        if (line.empty()) continue;  // Skip empty lines

        size_t pos = line.find(' ');
        Fraction frac1 = parseFraction(line.substr(0, pos));  // First fraction

        char operation = line[pos + 1];
        Fraction frac2 = parseFraction(line.substr(pos + 3));  // Second fraction

        Fraction result;

        // Determine the operation and perform it
        if (operation == '+')
        {
            result = frac1 + frac2;
        }
        else if (operation == '-')
        {
            result = frac1 - frac2;
        }
        else if (operation == '*')
        {
            result = frac1 * frac2;
        }
        else if (operation == '/')
        {
            result = frac1 / frac2;
        }
        else
        {
            cout << "ERROR: " << operation << endl;
            continue;
        }

        cout << frac1 << " " << operation << " " << frac2 << " = " << result << endl;
    }

    inputFile.close();
    return 0;
}
