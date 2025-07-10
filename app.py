from flask import Flask, request, jsonify, render_template
import subprocess
import sys
import os # <--- Ensure os is imported

app = Flask(__name__, template_folder='templates')

@app.route('/')
def home():
    return render_template('index.html')

@app.route('/calculate', methods=['POST'])
def calculate():
    data = request.json
    num1 = data.get('num1', '').strip()
    operator = data.get('operator', '').strip()
    num2 = data.get('num2', '').strip()

    # Normalize operator: IMPORTANT CHANGE HERE
    # Convert HTML's '*' to 'x' which C++ CLI understands and is not a wildcard
    operator = operator.replace('×', 'x').replace('*', 'x').replace('÷', '/') # <--- MODIFIED
    # Note: The original 'x' replace is now redundant, but harmless.

    if not num1 or not operator or not num2:
        print(f"DEBUG: Missing input data. num1='{num1}', operator='{operator}', num2='{num2}'")
        return jsonify({'error': 'Missing input data'}), 400

    try:
        cli_path = os.path.join(os.getcwd(), 'new_fraction_cli.exe') # Use the new executable name

        # IMPORTANT CHANGE HERE: NO QUOTES AROUND OPERATOR ANYMORE
        # Because 'x' does not need special handling by the shell
        command = [cli_path, num1, operator, num2] # <--- MODIFIED

        print(f"DEBUG: Attempting to execute command (absolute path): {command}")
        print(f"DEBUG: Type of num1: {type(num1)}, value: '{num1}'")
        print(f"DEBUG: Type of operator: {type(operator)}, value: '{operator}'") # Should be 'x' now
        print(f"DEBUG: Type of num2: {type(num2)}, value: '{num2}'")

        result = subprocess.check_output(
            command,
            text=True,
            encoding='utf-8',
            shell=False,
            stderr=subprocess.STDOUT
        )
        print(f"DEBUG: CLI successful output: {result.strip()}")
        return jsonify({'result': result.strip()})
    except subprocess.CalledProcessError as e:
        print(f"ERROR: subprocess.CalledProcessError occurred:")
        print(f"  Command: {e.cmd}")
        print(f"  Return Code: {e.returncode}")
        print(f"  CLI Error Output (e.output): {e.output.strip()}")
        return jsonify({'error': f'CLI Error: {e.output.strip()}'}), 400
    except Exception as e:
        print(f"ERROR: An unexpected Python error occurred: {e}")
        import traceback
        traceback.print_exc()
        return jsonify({'error': f'Server Error: {str(e)}'}), 500

if __name__ == '__main__':
    app.run(debug=True)