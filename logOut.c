#include "header.h"


void logOut(char* userName){
    int currentWeight = 0;
    char machineId[5] = {0};
    char timeOnTheMachine[10] = {0};
    printf("Your current weight:");
    scanf("%d",&currentWeight);
    FILE* fpFrom;
    FILE* fpTo;
    t_User currentUser = {0};
    char fileName[20] = {0};
    strcpy(fileName,userName);
    strcat(fileName,".txt");


    rename(fileName,"temp.txt");
    if((fpFrom = fopen("temp.txt","rb"))== NULL){
        printf("Error");
    }
    if((fpTo = fopen(fileName,"wb"))== NULL){
        printf("Error");
    }
    fread(&currentUser,sizeof(t_User),1,fpFrom);
    currentUser.currentWeight = currentWeight;

    fwrite(&currentUser,sizeof(t_User),1,fpTo);
    while(fread(&machineId,sizeof(char)*5,1,fpFrom) != 0){
        fread(&timeOnTheMachine,sizeof(char)*10,1,fpFrom);
        fwrite(&machineId,sizeof(char)*5,1,fpTo);
        fwrite(&timeOnTheMachine,sizeof(char)*10,1,fpTo);
    }

    printf("User: %s\nCurrent weight: %d\nInitial weight:%d\n",currentUser.name,currentUser.currentWeight,currentUser.initialWeight);

    fclose(fpTo);
    fclose(fpFrom);
    remove("temp.txt");
}
