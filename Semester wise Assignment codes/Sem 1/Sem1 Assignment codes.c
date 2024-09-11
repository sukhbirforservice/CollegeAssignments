// Semester 1 Programs

// 1. Program to find ASCII value of a character entered by the user:

#include <stdio.h>

int main() {
    char c;
    printf("Enter a character: ");
    scanf("%c", &c);
    printf("ASCII value of %c is %d\n", c, c);
    return 0;
}


// 2. Program to find whether the given year is leap year or not:

#include <stdio.h>

int main() {
    int year;
    printf("Enter a year: ");
    scanf("%d", &year);
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        printf("%d is a leap year\n", year);
    else
        printf("%d is not a leap year\n", year);
    return 0;
}


// 3. Program to perform simple Calculator operations:

#include <stdio.h>

int main() {
    int choice;
    float num1, num2, result;
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);
    switch (choice) {
        case 1:
            result = num1 + num2;
            break;
        case 2:
            result = num1 - num2;
            break;
        case 3:
            result = num1 * num2;
            break;
        case 4:
            if (num2 != 0)
                result = num1 / num2;
            else
                printf("Error: Division by zero\n");
            break;
        default:
            printf("Invalid choice\n");
    }
    printf("Result: %f\n", result);
    return 0;
}


// 4. Program to check whether a given number is Armstrong number or not:

#include <stdio.h>

int main() {
    int num, sum = 0, temp, digit;
    printf("Enter a number: ");
    scanf("%d", &num);
    temp = num;
    while (temp != 0) {
        digit = temp % 10;
        sum += digit * digit * digit;
        temp /= 10;
    }
    if (sum == num)
        printf("%d is an Armstrong number\n", num);
    else
        printf("%d is not an Armstrong number\n", num);
    return 0;
}


// 5. Program to check whether a given number is odd or even:


#include <stdio.h>

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (num % 2 == 0)
        printf("%d is even\n", num);
    else
        printf("%d is odd\n", num);
    return 0;
}


// 6. Program to print pattern:


#include <stdio.h>

int main() {
    int i, j;
    for (i = 1; i <= 5; i++) {
        for (j = 1; j <= i; j++) {
            if (i == 1 || i == 3 || j == 1 || j == i)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}


// 7. Program to find out the average of 4 integers:

#include <stdio.h>

int main() {
    int num1, num2, num3, num4;
    printf("Enter four numbers: ");
    scanf("%d %d %d %d", &num1, &num2, &num3, &num4);
    printf("Average: %f\n", (num1 + num2 + num3 + num4) / 4.0);
    return 0;
}


// 8. Program to display array elements using two-dimensional arrays:

#include <stdio.h>

int main() {
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int i, j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}



// 9. Program to perform swapping using function:

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    printf("Before swapping: num1 = %d, num2 = %d\n", num1, num2);
    swap(&num1, &num2);
    printf("After swapping: num1 = %d, num2 = %d\n", num1, num2);
    return 0;
}


// 10. Program to display all prime numbers between two intervals using functions:

#include <stdio.h>

int is_prime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void display_primes(int lower, int upper) {
    for (int i = lower; i <= upper; i++) {
        if (is_prime(i)) printf("%d ", i);
    }
}

int main() {
    int lower, upper;
    printf("Enter lower and upper bounds: ");
    scanf("%d %d", &lower, &upper);
    printf("Prime numbers between %d and %d: ", lower, upper);
    display_primes(lower, upper);
    return 0;
}


// 11. Program to reverse a sentence using recursion:

#include <stdio.h>

void reverse_sentence(char *str) {
    if (*str == '\0') return;
    reverse_sentence(str + 1);
    printf("%c", *str);
}

int main() {
    char str[100];
    printf("Enter a sentence: ");
    scanf("%[^\n]", str);
    printf("Reversed sentence: ");
    reverse_sentence(str);
    return 0;
}


// 12. Program to find the factorial of a given number using Recursion:

#include <stdio.h>

int factorial(int num) {
    if (num == 0 || num == 1) return 1;
    return num * factorial(num - 1);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Factorial of %d: %d\n", num, factorial(num));
    return 0;
}


// 13. Program to find the GCD of two numbers using Recursion:

#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    printf("GCD of %d and %d: %d\n", num1, num2, gcd(num1, num2));
    return 0;
}


// 14. Program to get the largest element of an array using the function:

#include <stdio.h>

int largest_element(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    printf("Largest element: %d\n", largest_element(arr, 5));
    return 0;
}


// 15. Program to concatenate two strings:

#include <stdio.h>

void concatenate(char *str1, char *str2) {
    while (*str1 != '\0') str1++;
    while (*str2 != '\0') {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
}

int main() {
    char str1[100] = "Hello ";
    char str2[100] = "World!";
    concatenate(str1, str2);
    printf("Concatenated string: %s\n", str1);
    return 0;
}



// 16. Program to find the length of String:

#include <stdio.h>

int string_length(char *str) {
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%[^\n]", str);
    printf("Length of string: %d\n", string_length(str));
    return 0;
}



// 17. Program to find the frequency of a character in a string:

#include <stdio.h>

int frequency(char *str, char c) {
    int count = 0;
    while (*str != '\0') {
        if (*str == c) count++;
        str++;
    }
    return count;
}

int main() {
    char str[100];
    char c;
    printf("Enter a string: ");
    scanf("%[^\n]", str);
    printf("Enter a character: ");
    scanf(" %c", &c);
    printf("Frequency of %c: %d\n", c, frequency(str, c));
    return 0;
}



// 18. Program to store Student Information in Structure and Display it:

#include <stdio.h>

struct Student {
    int roll_no;
    char name[100];
    float marks;
};

int main() {
    struct Student student;
    printf("Enter student information:\n");
    printf("Roll No: ");
    scanf("%d", &student.roll_no);
    printf("Name: ");
    scanf("%[^\n]", student.name);
    printf("Marks: ");
    scanf("%f", &student.marks);
    printf("Student Information:\n");
    printf("Roll No: %d\n", student.roll_no);
    printf("Name: %s\n", student.name);
    printf("Marks: %.2f\n", student.marks);
    return 0;
}



// 19. Program to read the data and determine the following: (a) Total marks obtained by each student. (b) The highest marks in each subject and the marks of the student who secured it. (c) The student who obtained the highest total marks.

#include <stdio.h>

struct Student {
    int roll_no;
    float marks[5];
};

int main() {
    struct Student students[10];
    int i, j;
    for (i = 0; i < 10; i++) {
        printf("Enter student %d information:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &students[i].roll_no);
        printf("Marks in 5 subjects: ");
        for (j = 0; j < 5; j++) {
            scanf("%f", &students[i].marks[j]);
        }
    }
    // Calculate total marks for each student
    for (i = 0; i < 10; i++) {
        float total = 0;
        for (j = 0; j < 5; j++) {
            total += students[i].marks[j];
        }
        printf("Total marks of student %d: %.2f\n", students[i].roll_no, total);
    }
    // Find highest marks in each subject
    float highest_marks[5] = {0};
    int highest_marks_student[5] = {0};
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 5; j++) {
            if (students[i].marks[j] > highest_marks[j]) {
                highest_marks[j] = students[i].marks[j];
                highest_marks_student[j] = students[i].roll_no;
            }
        }
    }
    for (j = 0; j < 5; j++) {
        printf("Highest marks in subject %d: %.2f by student %d\n", j + 1, highest_marks[j], highest_marks_student[j]);
    }
    // Find student with highest total marks
    float highest_total = 0;
    int highest_total_student = 0;
    for (i = 0; i < 10; i++) {
        float total = 0;
        for (j = 0; j < 5; j++) {
            total += students[i].marks[j];
        }
        if (total > highest_total) {
            highest_total = total;
            highest_total_student = students[i].roll_no;
        }
    }
    printf("Student with highest total marks: %d with %.2f marks\n", highest_total_student, highest_total);
    return 0;
}

// 20. Program to insert, update, delete and append telephone details of an individual or a company into a telephone directory using random access file:

#include <stdio.h>

struct TelephoneDirectory {
    char name[100];
    char phone[20];
};

void insert_record(FILE *fp) {
    struct TelephoneDirectory record;
    printf("Enter name: ");
    scanf("%[^\n]", record.name);
    printf("Enter phone number: ");
    scanf("%s", record.phone);
    fseek(fp, 0, SEEK_END);
    fwrite(&record, sizeof(struct TelephoneDirectory), 1, fp);
}

void update_record(FILE *fp) {
    struct TelephoneDirectory record;
    char name[100];
    printf("Enter name to update: ");
    scanf("%[^\n]", name);
    fseek(fp, 0, SEEK_SET);
    while (fread(&record, sizeof(struct TelephoneDirectory), 1, fp) == 1) {
        if (strcmp(record.name, name) == 0) {
            printf("Enter new phone number: ");
            scanf("%s", record.phone);
            fseek(fp, -sizeof(struct TelephoneDirectory), SEEK_CUR);
            fwrite(&record, sizeof(struct TelephoneDirectory), 1, fp);
            return;
        }
    }
    printf("Record not found.\n");
}

void delete_record(FILE *fp) {
    struct TelephoneDirectory record;
    char name[100];
    printf("Enter name to delete: ");
    scanf("%[^\n]", name);
    FILE *temp_fp = fopen("temp.dat", "wb");
    fseek(fp, 0, SEEK_SET);
    while (fread(&record, sizeof(struct TelephoneDirectory), 1, fp) == 1) {
        if (strcmp(record.name, name) != 0) {
            fwrite(&record, sizeof(struct TelephoneDirectory), 1, temp_fp);
        }
    }
    fclose(fp);
    fclose(temp_fp);
    remove("telephone_directory.dat");
    rename("temp.dat", "telephone_directory.dat");
    fp = fopen("telephone_directory.dat", "rb+");
}

void display_records(FILE *fp) {
    struct TelephoneDirectory record;
    fseek(fp, 0, SEEK_SET);
    while (fread(&record, sizeof(struct TelephoneDirectory), 1, fp) == 1) {
        printf("Name: %s, Phone: %s\n", record.name, record.phone);
    }
}

int main() {
    FILE *fp = fopen("telephone_directory.dat", "rb+");
    if (fp == NULL) {
        fp = fopen("telephone_directory.dat", "wb+");
    }
    int choice;
    while (1) {
        printf("1. Insert record\n");
        printf("2. Update record\n");
        printf("3. Delete record\n");
        printf("4. Display records\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert_record(fp);
                break;
            case 2:
                update_record(fp);
                break;
            case 3:
                delete_record(fp);
                break;
            case 4:
                display_records(fp);
                break;
            case 5:
                fclose(fp);
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
