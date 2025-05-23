#include <stdio.h>
#include <ctype.h>

#define STUDENTS 5  //constant
#define TESTS 13


// User input names and scores for 5 students.
//Calculate each student's average score
void input_data(char names[STUDENTS][11], int results[STUDENTS][TESTS], float averages[STUDENTS]) {
    for (int i = 0; i < STUDENTS; i++) {  
        scanf("%s", names[i]);
        
        int sum = 0;
        for (int j = 0; j < TESTS; j++) {
            scanf("%d", &results[i][j]);
            sum += results[i][j];
        }

        averages[i] = (float)sum / TESTS;  // casting
    }
}


// Calculate class average 
float find_class_average(float averages[STUDENTS]) {
    
    float total = 0;
    for (int i = 0; i < STUDENTS; i++) {
        total += averages[i];
    }
    return total / STUDENTS;
}


// Find the student with the highest average 
int find_top_student(float averages[STUDENTS]) {
    int index = 0;
    for (int i = 1; i < STUDENTS; i++) {
        if (averages[i] > averages[index]) {
            index = i;
        }
    }
    return index;
}


// Print names of students below the group average 
void underperform_students(char names[STUDENTS][11], float averages[STUDENTS], float groupAverage) {
    for (int i = 0; i < STUDENTS; i++) {
        if (averages[i] < groupAverage) {
            capitalize_letter(names[i]);
            printf("%s\n", names[i]);
        }
    }
}


// Capitalize the first letter of a name 
void capitalize_letter(char name[]) {
    name[0] = toupper(name[0]);
}


// Main function
int main() {
    char names[STUDENTS][11];    // 10+1
    int results[STUDENTS][TESTS];
    float averages[STUDENTS];

    input_data(names, results, averages);

    float groupAverage = find_class_average(averages);
    int topIndex = find_top_student(averages);

    capitalize_letter(names[topIndex]);
    printf("%s\n", names[topIndex]);

    underperform_students(names, averages, groupAverage);

    return 0;
}
