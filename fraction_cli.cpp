#include <iostream>
#include <regex>
#include <cmath>
#include <string>
#include <algorithm>
#include "Fraction.h"

// Helper: parse input string to Fraction
Fraction parseFraction(const std::string& input) {
    std::regex mixed_re(R"(^(-?\d+)_(-?\d+)/(\d+)$)"); // matches a_b/c
    std::regex frac_re(R"(^(-?\d+)/(\d+)$)");          // matches b/c
    std::regex decimal_re(R"(^-?\d*\.\d+$)");           // matches decimal like 1.25
    std::smatch match;

    // Mixed fraction
    if (std::regex_match(input, match, mixed_re)) {
        long whole = std::stol(match[1].str());
        long num = std::stol(match[2].str());
        long den = std::stol(match[3].str());
        if (den == 0) throw std::domain_error("Denominator cannot be zero");
        long numerator = std::abs(whole) * den + num;
        if (whole < 0) numerator = -numerator;
        return Fraction(numerator, den);
    }

    // Fraction b/c
    if (std::regex_match(input, match, frac_re)) {
        long num = std::stol(match[1].str());
        long den = std::stol(match[2].str());
        if (den == 0) throw std::domain_error("Denominator cannot be zero");
        return Fraction(num, den);
    }

    // Decimal number
    if (std::regex_match(input, decimal_re)) {
        double val = std::stod(input);
        const int precision = 1000000; // 1 million precision for fraction approx
        long numerator = static_cast<long>(round(val * precision));
        long denominator = precision;
        return Fraction(numerator, denominator);
    }

    // Whole number fallback
    try {
        long val = std::stol(input);
        return Fraction(val, 1);
    } catch (...) {
        throw std::invalid_argument("Invalid fraction input: " + input);
    }
}

// Helper function to strip leading/trailing double quotes
std::string stripQuotes(const std::string& s) {
    if (s.length() >= 2 && s.front() == '"' && s.back() == '"') {
        return s.substr(1, s.length() - 2); // Extract substring excluding first and last char
    }
    return s; // Return original string if no quotes or not properly quoted
}

int main(int argc, char* argv[]) {
    // Removed debug prints for argc and argv here

    if (argc != 4) {
        std::cout << "Usage: ./fraction_cli num1 operator num2\n";
        return 1;
    }

    try {
        Fraction f1 = parseFraction(argv[1]);
        std::string op = argv[2];

        // Removed debug prints for operator before stripping

        // Note: stripQuotes is no longer strictly necessary if Flask always sends 'x'
        // and you never run it directly with "quotes", but it's harmless to keep.
        op = stripQuotes(op);

        // Removed debug prints for operator after stripping

        Fraction f2 = parseFraction(argv[3]);

        Fraction result(0, 1);
        if (op == "+") result = f1 + f2;
        else if (op == "-") result = f1 - f2;
        else if (op == "*" || op == "x") result = f1 * f2; // Will now correctly process 'x'
        else if (op == "/") result = f1 / f2;
        else {
            std::cout << "Invalid operation\n";
            return 1;
        }

        std::cout << result.toString() << "\n";
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}