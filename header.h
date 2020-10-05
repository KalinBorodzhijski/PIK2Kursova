#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Ured {
    char name[40];
    char uredId[5];
}t_Ured;
typedef struct User {
    char name[10];
    int initialWeight;
    int currentWeight;
}t_User;

FILE* getFile();
void addExercise(char* userName);
void showLog(char* userName);
void logOut(char* userName);
