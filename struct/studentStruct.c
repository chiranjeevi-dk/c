#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NAME_LEN 20
#define MAX_DEPT_LEN 4
#define MAX_EMAIL_LEN 30
#define MAX_PHONE_LEN 15


typedef union studentContactInfo
{
    char email[MAX_EMAIL_LEN];
    char phone[MAX_PHONE_LEN];
} studentContactInfo;

typedef struct studentContact
{
    studentContactInfo info;
    bool hasEmail;
    bool hasPhone;
} studentContact;

void setEmail(studentContact *contact, const char *email)
{
    if (email != NULL)
    {
        snprintf(contact->info.email, sizeof(contact->info.email), "%s", email);
        contact->hasEmail = true;
        contact->hasPhone = false;
    }
}

char *getEmail(studentContact *contact)
{
    return contact->hasEmail ? contact->info.email : NULL;
}

void setPhone(studentContact *contact, const char *phone)
{
    if (phone != NULL)
    {
        snprintf(contact->info.phone, sizeof(contact->info.phone), "%s", phone);
        contact->hasPhone = true;
        contact->hasEmail = false;
    }
}

char *getPhone(studentContact *contact)
{
    return contact->hasPhone ? contact->info.phone : NULL;
}

typedef struct Student
{
    int rollno;
    char name[MAX_NAME_LEN];
    char dept[MAX_DEPT_LEN];
    char gender;
    float cgpa;
    studentContact contact;
} Student;

typedef struct Classroom
{
    int totalStudents;
    int maleStudents;
    int femaleStudents;
    Student *students;
    int capacity;
} Classroom;

void initClassroom(Classroom *classroom, int initialCapacity)
{
    classroom->totalStudents = 0;
    classroom->maleStudents = 0;
    classroom->femaleStudents = 0;
    classroom->capacity = initialCapacity;
    (*classroom).students = (Student *)malloc(initialCapacity * sizeof(Student));
    if (classroom->students == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
}

void freeClassroom(Classroom *classroom);

void addStudent(Classroom *classroom, const Student *student)
{
    if (classroom->totalStudents >= classroom->capacity)
    {
        int newCapacity = classroom->capacity * 2;
        Student *newStudents = (Student *)realloc(classroom->students, newCapacity * sizeof(Student));
        if (newStudents == NULL)
        {
            fprintf(stderr, "Memory reallocation failed\n");
            freeClassroom(classroom);  // Now the compiler knows about freeClassroom
            exit(EXIT_FAILURE);
        }
        classroom->students = newStudents;
        classroom->capacity = newCapacity;
    }
    classroom->students[classroom->totalStudents++] = *student;
}

void freeClassroom(Classroom *classroom)
{
    if (classroom->students != NULL)
    {
        free(classroom->students);
        classroom->students = NULL;
    }
}

void printStudent(const Student *student)
{
    printf("Roll no: %d\n", student->rollno);
    printf("Name: %s\n", student->name);
    printf("Department: %s\n", student->dept);
    printf("Gender: %c\n", student->gender);
    printf("CGPA: %.2f\n", student->cgpa);
    printf("Contact information:\n");
    if (student->contact.hasEmail)
    {
        printf("Email: %s\n", getEmail((studentContact *)&student->contact));
    }
    if (student->contact.hasPhone)
    {
        printf("Phone: %s\n", getPhone((studentContact *)&student->contact));
    }
    printf("\n");
}

void printClassroom(const Classroom *classroom)
{
    printf("Total students: %d\n", classroom->totalStudents);
    printf("Male students: %d\n", classroom->maleStudents);
    printf("Female students: %d\n", classroom->femaleStudents);
    printf("Student list:\n");
    for (int i = 0; i < classroom->totalStudents; i++)
    {
        printStudent(&classroom->students[i]);
    }
}

void safeStringInput(char *buffer, int maxSize, const char *prompt)
{
    printf("%s", prompt);
    if (fgets(buffer, maxSize, stdin) != NULL)
    {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n')
        {
            buffer[len - 1] = '\0';
        }
        else
        {
            // Clear remaining characters in the input buffer
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF)
                ;
        }
    }
    else
    {
        fprintf(stderr, "Input error\n");
        exit(EXIT_FAILURE);
    }
}

int safeIntInput(const char *prompt)
{
    int value;
    printf("%s", prompt);
    while (scanf("%d", &value) != 1)
    {
        fprintf(stderr, "Invalid input. Please enter an integer.\n");
        // Clear the invalid input
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;
        printf("%s", prompt);
    }
    // Clear the newline left by scanf
    getchar();
    return value;
}

float safeFloatInput(const char *prompt)
{
    float value;
    printf("%s", prompt);
    while (scanf("%f", &value) != 1)
    {
        fprintf(stderr, "Invalid input. Please enter a float.\n");
        // Clear the invalid input
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;
        printf("%s", prompt);
    }
    // Clear the newline left by scanf
    getchar();
    return value;
}

int main()
{
    Classroom classroom;
    initClassroom(&classroom, 10);

    int numStudents = safeIntInput("Enter the Number of students: ");
    if (numStudents <= 0)
    {
        fprintf(stderr, "Number of students must be positive.\n");
        freeClassroom(&classroom);
        return EXIT_FAILURE;
    }

    for (int count = 0; count < numStudents; count++)
    {
        Student student;

        student.rollno = safeIntInput("Enter student's roll no: ");
        safeStringInput(student.name, MAX_NAME_LEN, "Enter student's name: ");
        safeStringInput(student.dept, MAX_DEPT_LEN + 1, "Enter student's department (3 characters): ");

        printf("Enter student's gender (M/F): ");
        while (scanf(" %c", &student.gender) != 1 || (student.gender != 'M' && student.gender != 'F'))
        {
            fprintf(stderr, "Invalid input. Please enter 'M' or 'F'.\n");
            while (getchar() != '\n')
                ; // Clear the buffer
            printf("Enter student's gender (M/F): ");
        }
        getchar(); // Clear the newline left by scanf

        student.cgpa = safeFloatInput("Enter student's CGPA: ");

        int contactChoice = safeIntInput("Enter student's contact (for Email '1' or for Phone '2'): ");
        if (contactChoice == 1)
        {
            char email[MAX_EMAIL_LEN];
            safeStringInput(email, MAX_EMAIL_LEN, "Enter student's email: ");
            setEmail(&student.contact, email);
        }
        else if (contactChoice == 2)
        {
            char phone[MAX_PHONE_LEN];
            safeStringInput(phone, MAX_PHONE_LEN, "Enter student's phone: ");
            setPhone(&student.contact, phone);
        }
        else
        {
            fprintf(stderr, "Invalid contact choice. Skipping contact information.\n");
        }

        if (student.gender == 'M')
        {
            classroom.maleStudents++;
        }
        else if (student.gender == 'F')
        {
            classroom.femaleStudents++;
        }

        addStudent(&classroom, &student);
    }

    printClassroom(&classroom);
    freeClassroom(&classroom);

    return EXIT_SUCCESS;
}
