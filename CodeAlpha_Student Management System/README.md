# Student Management System

A simple yet effective console-based Student Management System built in C for managing student records with file persistence.

## Features

 **Core Features:**
-  **Add New Student** - Register new students with their details
-  **Delete Student** - Remove student records by roll number
-  **Update Student** - Modify existing student information (name, course, semester, CGPA)
-  **Search Student** - Find and view specific student details
-  **View All Students** - Display all students in a formatted table

## Project Structure

```
task 3/
├── studentportal.c      # Main program source code
└── README.md           # This file
```

## Data Structure

Each student record contains:
- **Roll No** - Unique identifier (integer)
- **Name** - Student's full name (max 50 characters)
- **Course** - Program/Course name (max 30 characters)
- **Semester** - Current semester (1-8 typically)
- **CGPA** - Cumulative Grade Point Average (floating point)

## Compilation & Execution

### On Windows (using MinGW or MSVC):

```bash
gcc studentportal.c -o studentportal.exe
studentportal.exe
```

### On Linux/Mac:

```bash
gcc studentportal.c -o studentportal
./studentportal
```

## Usage Guide

### Main Menu
The program starts with an interactive menu:
```
╔═══════════════════════════════════════════════════╗
║   STUDENT MANAGEMENT SYSTEM                      ║
╚═══════════════════════════════════════════════════╝

┌─── MAIN MENU ───────────────────────────────────┐
│ 1.  Add New Student Record                      │
│ 2.  Remove Student Record                      │
│ 3.   Modify Student Details                    │
│ 4.  Lookup Student                             │
│ 5.  Show All Students                          │
│ 0.  Quit Program                               │
└────────────────────────────────────────────────────┘
```

### Adding a Student
1. Select option 1 from the main menu
2. Enter the student's roll number
3. Enter the student's full name
4. Enter the course name
5. Enter the current semester
6. Enter the CGPA

### Searching for a Student
1. Select option 4 from the main menu
2. Enter the roll number to search
3. The system displays the complete student details

### Viewing All Students
1. Select option 5 from the main menu
2. All registered students are displayed in a formatted table with:
   - Roll Number
   - Name
   - Course
   - Semester
   - CGPA
   - Total count of students

### Updating Student Information
1. Select option 3 from the main menu
2. Enter the roll number of the student to update
3. Choose which field to update:
   - Name
   - Course
   - Semester
   - CGPA

### Deleting a Student
1. Select option 2 from the main menu
2. Enter the roll number of the student to delete
3. Confirm the deletion (system removes the record)

## Technical Details

### File Storage
- Student records are stored in a binary file: `students.dat`
- The file is created automatically in the same directory as the program
- Binary format ensures data integrity and efficient storage

### Maximum Capacity
- The system can handle up to **100 students** (configurable via `MAX_STUDENTS`)

### Data Validation
- Duplicate roll numbers are prevented
- File corruption detection with automatic recovery
- Input buffer overflow protection

## Features & Highlights

🎨 **User-Friendly Interface**
- Unicode box characters for a modern look
- Clear error messages with emoji indicators
- Interactive menu system with input validation

💾 **Data Persistence**
- Binary file format for reliable data storage
- Automatic file creation on first run
- Data validation during file read/write operations

⚙️ **Robust Error Handling**
- Graceful handling of missing files
- Detection and recovery from corrupted data
- User-friendly error messages

## Requirements

- **C Compiler** (GCC, Clang, MSVC, etc.)
- **Standard C Libraries** (stdio.h, string.h, stdlib.h, conio.h)
- **Operating System** - Windows, Linux, or Mac

## Notes

⚠️ **Important:**
- `gets()` is used for string input. In production, consider using `fgets()` for better security
- The program uses `conio.h` (Windows-specific). For cross-platform support, use alternative input methods
- File permissions are required to create/modify the `students.dat` file

## Example Workflow

1. **Start Program** → Main menu appears
2. **Add Student** → Enter 3 students
3. **View All** → See formatted table
4. **Search** → Look up specific student
5. **Update** → Modify CGPA
6. **Delete** → Remove a record
7. **Quit** → Exit program (data saved)

## License

This project is educational and free to use.

---


