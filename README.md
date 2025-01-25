# DamidoumML

**DamidoumML** is a lightweight machine learning library that I am developing to deepen my understanding of data structures and C++. Inspired by popular libraries such as PyTorch, TensorFlow, and JAX, I aim to create a Python wrapper for this C++ library. This project will also help me learn more about project organization and library building, utilizing tools like CMake and setuptools.

Currently, I am developing on macOS, and the library is not yet accessible on other operating systems.

## How to Install the Python Wrapper

1. Clone the repository
2. Create a virtual environment using Python 3.10 or higher:
   ```bash
   python3.10 -m venv .venv
   ```
3. Activate the virtual environment:
   ```bash
   source .venv/bin/activate
   ```
4. Build the library:
   ```bash
   pip install .
   ```

## Using the C++ Library

1. Create a build directory:
   ```bash
   mkdir build
   ```
2. Change to the build directory:
   ```bash
   cd build
   ```
3. Initialize CMake:
   ```bash
   cmake ..
   ```
4. Build the library:
   ```bash
   cmake --build .
   ```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
