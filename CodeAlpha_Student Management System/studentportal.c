#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#define MAX_STUDENTS 100
#define FILENAME "students.dat"

typedef struct {
    int rollno;
    char name[50];
    char course[30];
    int semester;
    float cgpa;
} Student;

void addStudent();
void deleteStudent();
void updateStudent();
void searchStudent();
void displayAllStudents();
void saveToFile(Student s[], int n);
int loadFromFile(Student s[]);

int main() {
    int choice;
    
    do {
        system("cls");
        printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("\n----- MAIN MENU -----\n");
        printf("1. Add New Student Record\n");
        printf("2. Remove Student Record\n");
        printf("3. Modify Student Details\n");
        printf("4. Lookup Student\n");
        printf("5. Show All Students\n");
        printf("0. Quit Program\n");
        printf("\nEnter your choice: ");
        scanf(" %d", &choice);
        fflush(stdin);
        
        switch(choice) {
            case 1:
                addStudent();
                break;
            case 2:
                deleteStudent();
                break;
            case 3:
                updateStudent();
                break;
            case 4:
                searchStudent();
                break;
            case 5:
                displayAllStudents();
                break;
            case 0:
                printf("\nThank you for using Student Management System!\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
        
        if (choice != 0) {
            printf("\nPress any key to continue...");
            getch();
        }
        
    } while (choice != 0);
    
    return 0;
}

void addStudent() {
    system("cls");
    printf("\n===== ADD NEW STUDENT =====\n");
    
    Student students[MAX_STUDENTS];
    int count = loadFromFile(students);
    
    if (count >= MAX_STUDENTS) {
        printf("\n[ERROR] Maximum number of students reached!\n");
        return;
    }
    
    Student s;
    
    printf("\nEnter Roll No: ");
    scanf(" %d", &s.rollno);
    fflush(stdin);
    
    for (int i = 0; i < count; i++) {
        if (students[i].rollno == s.rollno) {
            printf("\n[ERROR] Student with this roll number already exists!\n");
            return;
        }
    }
    
    printf(" Enter Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = 0;
    
    printf(" Enter Course: ");
    fgets(s.course, sizeof(s.course), stdin);
    s.course[strcspn(s.course, "\n")] = 0;
    
    printf(" Enter Semester: ");
    char temp[20];
    fgets(temp, sizeof(temp), stdin);
    s.semester = atoi(temp);
    
    printf(" Enter CGPA: ");
    fgets(temp, sizeof(temp), stdin);
    s.cgpa = atof(temp);
    
    students[count] = s;
    saveToFile(students, count + 1);
    
    printf("\n[SUCCESS] Student added successfully!\n");
}

void deleteStudent() {
    system("cls");
    printf("\n===== DELETE STUDENT =====");
    
    Student students[MAX_STUDENTS];
    int count = loadFromFile(students);
    
    if (count == 0) {
        printf("\n❌ No students found!\n");
        return;
    }
    
    int rollno, found = 0;
    printf("\n Enter Roll No to delete: ");
    scanf(" %d", &rollno);
    fflush(stdin);
    
    for (int i = 0; i < count; i++) {
        if (students[i].rollno == rollno) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            found = 1;
            count--;
            saveToFile(students, count);
            printf("\n✅ Student deleted successfully!\n");
            break;
        }
    }
    
    if (!found) {
        printf("\n❌ Student with Roll No %d not found!\n", rollno);
    }
}

void updateStudent() {
    system("cls");
    printf("\n===== UPDATE STUDENT =====");
    
    Student students[MAX_STUDENTS];
    int count = loadFromFile(students);
    
    if (count == 0) {
        printf("\n[ERROR] No students found!\n");
        return;
    }
    
    int rollno, found = 0, choice;
    printf("\nEnter Roll No to update: ");
    scanf(" %d", &rollno);
    fflush(stdin);    
    for (int i = 0; i < count; i++) {
        if (students[i].rollno == rollno) {
            do {
                system("cls");
                printf("\n===== UPDATE MENU =====");
                printf("\n1. Update Name\n");
                printf("2. Update Course\n");
                printf("3. Update Semester\n");
                printf("4. Update CGPA\n");
                printf("0. Back to Main Menu\n");
                printf("\nEnter your choice: ");
                scanf(" %d", &choice);
                getchar();
                
                switch(choice) {
                    case 1:
                        printf("\nEnter new Name: ");
                        fgets(students[i].name, sizeof(students[i].name), stdin);
                        students[i].name[strcspn(students[i].name, "\n")] = 0;
                        printf("\n[SUCCESS] Name updated successfully!\n");
                        break;
                    case 2:
                        printf("\nEnter new Course: ");
                        fgets(students[i].course, sizeof(students[i].course), stdin);
                        students[i].course[strcspn(students[i].course, "\n")] = 0;
                        printf("\n[SUCCESS] Course updated successfully!\n");
                        break;
                    case 3:
                        printf("\nEnter new Semester: ");
                        char temp_sem[20];
                        fgets(temp_sem, sizeof(temp_sem), stdin);
                        students[i].semester = atoi(temp_sem);
                        printf("\n[SUCCESS] Semester updated successfully!\n");
                        break;
                    case 4:
                        printf("\nEnter new CGPA: ");
                        char temp_cgpa[20];
                        fgets(temp_cgpa, sizeof(temp_cgpa), stdin);
                        students[i].cgpa = atof(temp_cgpa);
                        printf("\n[SUCCESS] CGPA updated successfully!\n");
                        break;
                    case 0:
                        break;
                    default:
                        printf("\n[ERROR] Invalid choice!\n");
                }
                
                if (choice != 0) {
                    printf("\nPress any key to continue...");
                    getch();
                }
                
            } while (choice != 0);
            
            saveToFile(students, count);
            found = 1;
            printf("\n[SUCCESS] Student details updated successfully!\n");
            break;
        }
    }
    
    if (!found) {
        printf("\n❌ Student with Roll No %d not found!\n", rollno);
    }
}

void searchStudent() {
    system("cls");
    printf("\n===== SEARCH STUDENT =====\n");
    
    Student students[MAX_STUDENTS];
    int count = loadFromFile(students);
    
    if (count == 0) {
        printf("\n[ERROR] No students found!\n");
        return;
    }
    
    int rollno, found = 0;
    printf("\nEnter Roll No to search: ");
    scanf("%d", &rollno);    fflush(stdin);    
    for (int i = 0; i < count; i++) {
        if (students[i].rollno == rollno) {
            printf("\n===== STUDENT DETAILS =====\n");
            printf("\nRoll No  : %d\n", students[i].rollno);
            printf("Name     : %s\n", students[i].name);
            printf("Course   : %s\n", students[i].course);
            printf("Semester : %d\n", students[i].semester);
            printf("CGPA     : %.2f\n\n", students[i].cgpa);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("\n[ERROR] Student with Roll No %d not found!\n", rollno);
    }
}

// Function to display all students in a nice tabular format
void displayAllStudents() {
    system("cls");
    printf("\n===== ALL STUDENT RECORDS =====\n\n");
    
    Student students[MAX_STUDENTS];
    int count = loadFromFile(students);
    
    if (count == 0) {
        printf("The student database is currently empty.\n");
        printf("Use 'Add New Student Record' to add students.\n");
        return;
    }
    
    printf("%-10s %-30s %-20s %-10s %-6s\n", "Roll No", "Name", "Course", "Semester", "CGPA");
    printf("================================================================================\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-10d %-30s %-20s %-10d %-6.2f\n", 
               students[i].rollno, 
               students[i].name, 
               students[i].course, 
               students[i].semester, 
               students[i].cgpa);
    }
    
    printf("================================================================================\n");
    printf("\nTotal students: %d\n", count);
}

void saveToFile(Student students[], int count) {
    FILE *file = fopen(FILENAME, "wb");
    
    if (file == NULL) {
        printf("\n[ERROR] Couldn't save the data!\n");
        printf("Please check if you have write permissions in this directory.\n");
        return;
    }
    
    if (fwrite(&count, sizeof(int), 1, file) != 1) {
        printf("\n[WARNING] Error writing record count to file!\n");
    }
    
    if (fwrite(students, sizeof(Student), count, file) != count) {
        printf("\n[WARNING] Not all student records were saved correctly!\n");
    }
    
    fclose(file);
}

int loadFromFile(Student students[]) {
    FILE *file = fopen(FILENAME, "rb");
    
    if (file == NULL) {
        return 0;
    }
    
    int count = 0;
    
    if (fread(&count, sizeof(int), 1, file) != 1) {
        printf("\n[WARNING] Corrupted data file. Starting with empty database.\n");
        fclose(file);
        return 0;
    }
    
    if (count < 0 || count > MAX_STUDENTS) {
        printf("\n[WARNING] Invalid record count in file. Starting fresh.\n");
        fclose(file);
        return 0;
    }
    
    size_t read = fread(students, sizeof(Student), count, file);
    if (read != count) {
        printf("\n[WARNING] Some student records may be corrupted.\n");
        count = read;
    }
    
    fclose(file);
    return count;
}