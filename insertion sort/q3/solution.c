#include <stdio.h>

struct student
{
    int id;
    float cgpa;
};

typedef struct student Student; // create an alias for struct student

void swap(Student *a, Student *b)
{
    Student temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(Student students[], int n)
{
    int i, j, max_idx;

    for (i = 0; i < n - 1; i++)
    {
        max_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (students[j].cgpa > students[max_idx].cgpa)
            {
                max_idx = j;
            }
        }
        swap(&students[max_idx], &students[i]);
    }
}

int main()
{
    Student students[100];
    int n, i;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter ID for student %d: ", i + 1);
        scanf("%d", &students[i].id);
        printf("Enter CGPA for student %d: ", i + 1);
        scanf("%f", &students[i].cgpa);

        while (students[i].cgpa < 0.0 || students[i].cgpa > 4.0)
        {
            printf("Invalid CGPA! Enter a value between 0.00 and 4.00: ");
            scanf("%f", &students[i].cgpa);
        }
    }

    selectionSort(students, n);

    printf("\nSorted student data (by CGPA in descending order):\n");
    printf("ID\tCGPA\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%.2f\n", students[i].id, students[i].cgpa);
    }

    return 0;
}
