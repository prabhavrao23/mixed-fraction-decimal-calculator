# Fraction Calculator Web Interface

**Project Overview**

I made this project to be able to perform arithmetic operations on mixed fractions and decimals. I did this through operator overloading with a C++ backend and Python Flask frontend. 

**Demo Video**

The calculator supports various input formats for numbers, including simple fractions, mixed numbers, decimals, and whole numbers.

Features
Arithmetic Operations: Perform addition (+), subtraction (-), multiplication (×), and division (÷) of any number. 

Flexible Input Formats: Supports 1/2, 2_1/3, 1.25, and 3.

Command-Line Interface (C++): The core calculation engine can also be run directly from your IDE or terminal.

Web-Based User Interface (Python Flask):

Simple and intuitive interface for calculations.

**Project Structure**
Techstack: C++ backend and Python Flask frontend.

your-fraction-calculator-repo/
├── app.py                  # Main Flask application logic
├── templates/
│   └── index.html          # HTML template for the web interface
├── fraction_cli.cpp        # C++ source code for the command-line interface (CLI)
├── Fraction.h              # Header for the Fraction C++ class
├── Fraction.cpp            # Implementation for the Fraction C++ class
└── README.md               # This documentation

**Prerequisites/How to run on your computer**
A C++ Compiler (GCC/G++ recommended): For compiling the C++ backend.

Python 3: For running the Flask frontend.

Flask: The Python web framework.

1. Clone the Repository 

2. Compile the C++ Backend

3. Run the Python Flask Frontend
Install Flask: If you haven't already, install Flask using pip:

Access the Web Interface: Open your web browser and go to the address provided by Flask (e.g., http://127.0.0.1:5000/).
