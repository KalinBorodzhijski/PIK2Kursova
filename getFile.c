#include "header.h"

FILE* getFile(){
    t_User currentUser = {0};
    int structRead;

    FILE* userFile;
    char name[25];

    printf("Enter name:");
    scanf("%s",name);
    strcat(name,".txt");
    if((userFile = fopen(name,"ab+"))==NULL){
        printf("User not found");

    }

    structRead = fread(&currentUser,sizeof(t_User),1,userFile);

    if(structRead == 0){
        fclose(userFile);
        remove(name);
        printf("Invalid user");
        exit(0);
    }

    return userFile;
}

