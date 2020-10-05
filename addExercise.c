#include "header.h"

void addExercise(char* userName){
    char fileName[20] = {0};
    char machineName[40] = {0};
    char timeOnTheMachine[10] = {0};
    FILE* fp;
    FILE* equipmentFile;
    strcpy(fileName,userName);
    strcat(fileName,".txt");

    if((fp = fopen(fileName,"ab"))== NULL){
        printf("Error");
        exit(2);
    }
    printf("Enter machine name(Treadmill,  Leg extension machine, Standing calf machine, Bike)\n");
    scanf(" ");
    gets(machineName);
    printf("Time spent training\n");
    scanf("%s",timeOnTheMachine);


    if((equipmentFile = fopen("equipment.txt","rb")) == NULL){
        printf("Error");
        exit(3);
    }
    t_Ured machine = {0};
    int count = 0;
    while (fread(&machine,sizeof(t_Ured),1,equipmentFile) != 0){
        if (strcmp(machineName,machine.name) == 0){
            break;
        }
        count++;

    }

    if (count == 4){
        printf("Invalid input\n");
        fclose(equipmentFile);
        fclose(fp);
        return;
    }

    fwrite(&machine.uredId,sizeof(char)*5,1,fp);
    fwrite(&timeOnTheMachine,sizeof(char)*10,1,fp);

    fclose(equipmentFile);
    fclose(fp);

}
