Fraction Calculator Web Interface
Project Overview
This project provides a convenient web-based application for performing arithmetic operations on fractions. It features a robust C++ backend that handles the core mathematical logic for fraction calculations, seamlessly integrated with a user-friendly frontend built using Python Flask.

The calculator supports various input formats for numbers, including simple fractions, mixed numbers, decimals, and whole numbers, making it versatile for different use cases.

✨ Features
Arithmetic Operations: Perform addition (+), subtraction (-), multiplication (×), and division (÷) of fractions.

Flexible Input Formats: Supports 1/2, 2_1/3, 1.25, and 3.

Command-Line Interface (C++): The core calculation engine can also be run directly from your IDE or terminal.

Web-Based User Interface (Python Flask):

Simple and intuitive interface for calculations.

Responsive design for easy use across devices.

📂 Project Structure
Techstack: C++ backend and Python Flask frontend.

your-fraction-calculator-repo/
├── app.py                  # Main Flask application logic
├── templates/
│   └── index.html          # HTML template for the web interface
├── fraction_cli.cpp        # C++ source code for the command-line interface (CLI)
├── Fraction.h              # Header for the Fraction C++ class
├── Fraction.cpp            # Implementation for the Fraction C++ class
└── README.md               # This documentation
⚙️ Prerequisites/How to run on your computer
A C++ Compiler (GCC/G++ recommended): For compiling the C++ backend.

Python 3: For running the Flask frontend.

Flask: The Python web framework.

1. Clone the Repository (or ensure all files are in one directory)
Make sure all project files (app.py, templates/, fraction_cli.cpp, Fraction.h, Fraction.cpp, README.md) are in a single directory on your computer.

2. Compile the C++ Backend
Open your terminal or command prompt, navigate to your project directory (e.g., C:\your-fraction-calculator-repo), and compile the C++ source code:

Bash

g++ fraction_cli.cpp Fraction.cpp -o fraction_cli.exe
This command will create the executable fraction_cli.exe (on Windows) or fraction_cli (on Linux/macOS) in your project directory.

3. Run the Python Flask Frontend
Install Flask: If you haven't already, install Flask using pip:

Bash

pip install Flask
Start the Flask application: From your project directory in the terminal, run:

Bash

python app.py
You will see output indicating that the Flask server is running, typically on http://127.0.0.1:5000.

Access the Web Interface: Open your web browser and go to the address provided by Flask (e.g., http://127.0.0.1:5000/).