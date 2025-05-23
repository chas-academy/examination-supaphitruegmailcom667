#include <stdio.h>
#include <ctype.h>

#define STUDENTS 5  //constant
#define TESTS 13

void input_data(char names[STUDENTS][11], int results[STUDENTS][TESTS], float averages[STUDENTS]) {
    int sum = 0;

    for (int i = 0; i < STUDENTS; i++) {
        scanf("%s", names[i]);

        for (int j = 0; j < TESTS; j++) {
            scanf("%d", &results[i][j]);
            sum += results[i][j];
        }

        averages[i] = (float)sum / TESTS;  // Type casting
        sum = 0;
    }
}


float cal_average(float averages[STUDENTS]) {
    float total = 0;
    for (int i = 0; i < STUDENTS; i++) {
        total += averages[i];
    }
    return total / STUDENTS;
}


int find_top_student(float averages[STUDENTS]) {
    int index = 0;
    float highest = averages[0];

    for (int i = 1; i < STUDENTS; i++) {
        if (averages[i] > highest) {
            highest = averages[i];
            index = i;
        }
    }
    return index;
}

void underperform_student(char names[STUDENTS][11], float averages[STUDENTS], float totalAverage) {
    for (int i = 0; i < STUDENTS; i++) {
        if (averages[i] < totalAverage) {
            names[i][0] = toupper(names[i][0]);
            printf("%s\n", names[i]);
        }
    }
}

int main() {
    char names[STUDENTS][11];  // 10+1
    int results[STUDENTS][TESTS];
    float averages[STUDENTS];

    input_data(names, results, averages);

    float totalAverage = cal_average(averages);
    int toppStudent = find_top_student(averages);

    names[toppStudent][0] = toupper(names[toppStudent][0]);
    printf("%s\n", names[toppStudent]);

    underperform_student(names, averages, totalAverage);

    return 0;
}

