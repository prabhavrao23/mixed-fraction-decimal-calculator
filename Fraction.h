#include <cmath>
#include <string>
#include <sstream>

#ifndef FRACTION_H
#define FRACTION_H

/**
 * @class Fraction
 * Represents a fraction with a numerator and a denominator.
 */
class Fraction {
private:
    long numerator;
    long denominator;

    void reduce();
    long gcd(long a, long b) const;
public:
    /** Constructor
    * @param numerator The numerator of the fraction
    * @param denominator The denominator of the fraction
    */
    Fraction(long numerator, long denominator);

    /** Get the numerator of the fraction
     * @return The numerator
     */
    long getNumerator() const;

    /** Get the denominator of the fraction
     * @return The denominator
     */
    long getDenominator() const;

    /** Set the numerator of the fraction
     * @param numerator The new numerator value
     */
    void setNumerator(long numerator);

    /** Set the denominator of the fraction
     * @param denominator The new denominator value
     */
    void setDenominator(long denominator);

    /** Convert the fraction to a string representation
     * @return A string representing the fraction
     */
    std::string toString();

    /** Overloaded addition operator for adding two fractions
     * @param rhs The right-hand side fraction to add
     * @return The sum of the two fractions
     */
    Fraction operator+(const Fraction &rhs) const;

    /** Overloaded addition operator for adding an integer to a fraction
     * @param rhs The integer to add
     * @return The sum of the fraction and the integer
     */
    Fraction operator+(const int rhs) const;

    /** Overloaded subtraction operator for subtracting two fractions
     * @param rhs The right-hand side fraction to subtract
     * @return The difference between the two fractions
     */
    Fraction operator-(const Fraction &rhs) const;

    /** Overloaded subtraction operator for subtracting an integer from a fraction
     * @param rhs The integer to subtract
     * @return The difference between the fraction and the integer
     */
    Fraction operator-(const int rhs) const;

    /** Overloaded division operator for dividing two fractions
     * @param rhs The right-hand side fraction to divide by
     * @return The result of dividing the left-hand side fraction by the right-hand side fraction
     */
    Fraction operator/(const Fraction &rhs) const;

    /** Overloaded division operator for dividing a fraction by an integer
     * @param rhs The integer to divide by
     * @return The result of dividing the fraction by the integer
     */
    Fraction operator/(const int rhs) const;

    /** Overloaded multiplication operator for multiplying two fractions
     * @param rhs The right-hand side fraction to multiply by
     * @return The result of multiplying the two fractions
     */
    Fraction operator*(const Fraction &rhs) const;

    /** Overloaded multiplication operator for multiplying a fraction by an integer
     * @param rhs The integer to multiply by
     * @return The result of multiplying the fraction by the integer
     */
    Fraction operator*(const int rhs) const;

    /**
    * @brief Equality comparison operator.
    * @param rhs The Fraction object to compare with.
    */
    bool operator == (const Fraction rhs) const;

    /**
     * @brief Inequality comparison operator.
     * @param rhs The Fraction object to compare with.
     *
     */
    bool operator != (const Fraction rhs) const;

    /**
     * @brief Less than comparison operator.
     * @param rhs The Fraction object to compare with.
     *
     */
    bool operator<(const Fraction rhs) const;

    /**
     * @brief Greater than comparison operator.
     * @param rhs The Fraction object to compare with.
     * @return this instance that is not = or less than rhs
     */
    bool operator>(const Fraction rhs) const;

    /**
     * @brief Less than or equal to comparison operator.
     * @param rhs The Fraction object to compare with.
     * return this less than that is not greater than or equal to rhs
     */

    bool operator<=(const Fraction rhs) const;

    /**
     * @brief Greater than or equal to comparison operator.
     * @param rhs The Fraction object to compare with.
     * @return this is it is less than rhs or = rhs
     */
    bool operator>=(const Fraction rhs) const;

    /**
     * @brief Postfix increment operator.
     * @return this after incrementing
     */
    Fraction& operator ++();
    /**
       * @param dummy to differentiate from prefix
       * @brief Postfix decrement operator.
       * @return returns this before incrementing
       */
    Fraction operator++(int dummy);
    /**
     * @brief Prefix decrement operator.
     * @return this after decrementing
     */
    Fraction& operator--();

    /**
     * @brief Postfix decrement
     * @param dummy to differentiate from prefix
     * @return this before decrementing
     */
    Fraction operator--(int dummy);

};

#endif //FRACTION_H
std::ostream& operator << (std::ostream &out,  Fraction rhs);
std::ostream& operator << (std::ostream &out,  Fraction *rhs);