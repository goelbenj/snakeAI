#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_COURSE_LENGTH 6
#define MAX_LOC_LENGTH 6
#define MAX_DAY_LENGTH 9
#define NUM_DAYS 15
#define MAX_NAME 256

typedef struct{
    char course_code[MAX_COURSE_LENGTH + 1];
    char location[MAX_LOC_LENGTH + 1];
    char instructor[MAX_NAME];
    int start_time;
    float duration;
    int priority;
    char student_class;
}Exam;

typedef struct{
    Exam *list_exams;
    char day_string[MAX_DAY_LENGTH + 1];
    int day_num;
}Day;

typedef struct{
    Day list_days[NUM_DAYS];
    int num_exams;
}Schedule;