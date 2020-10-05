#include "header.h"


int main() {
    FILE* userFile = getFile();
    t_User currentUser = {0};
    fseek(userFile,0,SEEK_SET);
    fclose(userFile);
    int userInput = 0;


    while (1) {
        printf("1 - Add exercise\n2 - Show log\n3 - LogOut\n");
        scanf("%d",&userInput);
        if (userInput == 1) {
            addExercise(currentUser.name);
        } else if (userInput == 2){
            showLog(currentUser.name);
        }
        else if(userInput == 3){
            logOut(currentUser.name);
            return 0;
        }else{
            printf("Invalid input");
            return 0;
        }

    }

}
