#include "header.h"

void showLog(char* userName){
    FILE* fp;
    t_User currentUser = {0};
    char fileName[20] = {0};
    strcpy(fileName,userName);
    strcat(fileName,".txt");
    if((fp = fopen(fileName,"rb"))== NULL){
        printf("Error");
    }
    fread(&currentUser,sizeof(t_User),1,fp);
    char machineId[5] = {0};
    char timeOnTheMachine[10] = {0};
    printf("User: %s\n",currentUser.name);
    while (fread(machineId,sizeof(char)*5,1,fp) != 0){
        fread(timeOnTheMachine,sizeof(char)*10,1,fp);
        printf("MachineId: %s\nTime spent on the machine: %s\n",machineId,timeOnTheMachine);
    }

    fclose(fp);
}
