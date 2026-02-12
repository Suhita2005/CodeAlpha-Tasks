# Matrix Operations Program

A program that performs basic matrix operations including addition, multiplication, and transposition.

**Available in:**
- C (`matrix.c`) - Original implementation
- Python (`matrix.py`) - Windows-friendly version

## Features

- **Matrix Addition**: Add two matrices of the same dimensions
- **Matrix Multiplication**: Multiply two matrices (with compatible dimensions)
- **Matrix Transpose**: Transpose a matrix (swap rows and columns)

## Requirements

- C compiler (GCC, Clang, or MSVC)
- Standard C library

## Compilation and Running

### Option 1: Run the Python Version (Recommended for Windows)
```bash
python matrix.py
```

This is the easiest way to run the program on Windows without compiler setup issues.

### Option 2: Compile and Run the C Version (Linux/Mac/Unix)
```bash
gcc matrix.c -o matrix
./matrix
```

### Complete Example Session
```bash
$ python matrix.py
Matrix Operations:
1. Addition
2. Multiplication
3. Transpose
Enter your choice: 1
Enter rows and columns of matrices: 2 2
Matrix A:
Enter elements of the matrix (2 x 2):
Element [0][0]: 1
Element [0][1]: 2
Element [1][0]: 3
Element [1][1]: 4
Matrix B:
Enter elements of the matrix (2 x 2):
Element [0][0]: 5
Element [0][1]: 6
Element [1][0]: 7
Element [1][1]: 8
Result of Addition:
Matrix (2 x 2):
6       8
10      12
```

The program will present a menu with three options:
```
Matrix Operations:
1. Addition
2. Multiplication
3. Transpose
Enter your choice: 
```

### Operation Details

#### 1. Addition
- Prompts for matrix dimensions (rows and columns)
- Accepts two matrices of the same size
- Outputs the sum of the two matrices

#### 2. Multiplication
- Prompts for dimensions of both matrices
- Multiplies Matrix A (r1 × c1) with Matrix B (r2 × c2)
- Validates that columns of A equal rows of B
- Outputs the product matrix

#### 3. Transpose
- Prompts for matrix dimensions
- Accepts a matrix
- Outputs the transposed matrix (rows become columns and vice versa)

## Constraints

- Maximum matrix size: 10 × 10 (defined by `SIZE` constant)
- All matrix elements must be integers
- For multiplication, the number of columns in Matrix A must equal the number of rows in Matrix B

## Example

```
Matrix Operations:
1. Addition
2. Multiplication
3. Transpose
Enter your choice: 1
Enter rows and columns of matrices: 2 2
Matrix A:
1 2
3 4
Matrix B:
5 6
7 8
Result of Addition:
6	8	
10	12	
```

## Functions

- `inputMatrix()`: Takes user input for matrix elements
- `displayMatrix()`: Prints a matrix in formatted output
- `addMatrices()`: Adds two matrices
- `multiplyMatrices()`: Multiplies two matrices
- `transposeMatrix()`: Transposes a matrix

## Notes

- All matrix operations use integer arithmetic
- Tab characters are used to separate matrix elements in output for better readability
- Error handling for incompatible matrix dimensions during multiplication
