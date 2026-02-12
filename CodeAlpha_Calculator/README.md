# Basic Calculator Program

A simple command-line calculator written in C that performs basic arithmetic operations.

## Features

- **Addition** (+)
- **Subtraction** (-)
- **Multiplication** (*)
- **Division** (/) with zero-division error handling


Follow the on-screen prompts:
1. Select an operation (1-4)
2. Enter the first number
3. Enter the second number
4. View the calculated result

## Example

```
Basic Calculator Program
-------------------------
Select an operation:
1. Addition (+)
2. Subtraction (-)
3. Multiplication (*)
4. Division (/)
Enter your choice (1-4): 1
Enter first number: 43
Enter second number: 1.9
Result: 44.90
```

## Error Handling

- Division by zero is caught and displays an error message
- Invalid operation choices (outside 1-4 range) display an error message

## Notes

- Supports floating-point numbers
- Results are displayed with 2 decimal places
