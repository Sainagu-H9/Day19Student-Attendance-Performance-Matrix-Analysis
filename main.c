#include <stdio.h>

int main() {
    int attendance[5][5], marks[5][5];
    char names[5][20];
    int i, j, ch;

    int present[5], absent[5], total[5];
    float avg[5];
    char grade[5];

    printf("Enter names of 5 students:\n");
    for (i = 0; i < 5; i++) scanf("%s", names[i]);

    printf("\nEnter attendance (1 or 0) for 5 students in 5 subjects:\n");
    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            scanf("%d", &attendance[i][j]);

    printf("\nEnter marks out of 100 for 5 students in 5 subjects:\n");
    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            scanf("%d", &marks[i][j]);

    int max_att = 0, min_att = 0, max_mark = 0, min_mark = 0;

    for (i = 0; i < 5; i++) {
        present[i] = 0;
        total[i] = 0;
        for (j = 0; j < 5; j++) {
            present[i] += attendance[i][j];
            total[i] += marks[i][j];
        }
        absent[i] = 5 - present[i];
        avg[i] = total[i] / 5.0;

        if (avg[i] >= 90) grade[i] = 'A';
        else if (avg[i] >= 80) grade[i] = 'A';
        else if (avg[i] >= 70) grade[i] = 'B';
        else if (avg[i] >= 60) grade[i] = 'C';
        else if (avg[i] >= 50) grade[i] = 'D';
        else grade[i] = 'F';
    }

    for (i = 1; i < 5; i++) {
        if (present[i] > present[max_att]) max_att = i;
        if (present[i] < present[min_att]) min_att = i;
        if (total[i] > total[max_mark]) max_mark = i;
        if (total[i] < total[min_mark]) min_mark = i;
    }

    while (1) {
        printf("\n========= MENU =========\n");
        printf("1. Attendance Matrix\n2. Marks Matrix\n3. Attendance Report\n");
        printf("4. Marks Report\n5. Grades\n6. Exit\nEnter choice: ");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("\nAttendance Matrix:\n");
            for (i = 0; i < 5; i++) {
                printf("%s: ", names[i]);
                for (j = 0; j < 5; j++) printf("%d ", attendance[i][j]);
                printf("\n");
            }
        } 
        else if (ch == 2) {
            printf("\nMarks Matrix:\n");
            for (i = 0; i < 5; i++) {
                printf("%s: ", names[i]);
                for (j = 0; j < 5; j++) printf("%d ", marks[i][j]);
                printf("\n");
            }
        } 
        else if (ch == 3) {
            printf("\nAttendance Report:\n");
            for (i = 0; i < 5; i++)
                printf("%s -> Present: %d, Absent: %d\n", names[i], present[i], absent[i]);
            printf("\nMost Present: %s\nLeast Present: %s\n", names[max_att], names[min_att]);
        } 
        else if (ch == 4) {
            printf("\nMarks Report:\n");
            for (i = 0; i < 5; i++)
                printf("%s -> Total: %d, Average: %.2f\n", names[i], total[i], avg[i]);
            printf("\nTopper: %s\nLowest Marks: %s\n", names[max_mark], names[min_mark]);
        } 
        else if (ch == 5) {
            printf("\nGrades:\n");
            for (i = 0; i < 5; i++)
                printf("%s -> Grade: %c\n", names[i], grade[i]);
        } 
        else if (ch == 6) {
            break;
        }
        else printf("\nInvalid choice.\n");
    }

    return 0;
}
