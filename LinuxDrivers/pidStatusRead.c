#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>

#define TARGET_PID_DIR    "/proc/8462"   //for firefox browser
#define READ_FILE         "status"
#define TARGET_OP_FILE    "8462_staus.txt"

int main(void){
    DIR *sDir;  // pointer to file directory - starting file directory stream
    sDir = opendir(TARGET_PID_DIR);
    FILE *opFile, *tmpFile;
    opFile = fopen(TARGET_OP_FILE, "w");

    if(opendir == NULL)     printf("Error opening %s\n", TARGET_OP_FILE);

    if (sDir == NULL)
    {
        printf("Error openning %s", TARGET_PID_DIR);
        exit(0);
    }
    
    struct dirent *entry;  //single directory entry returned by readdir()
    entry = readdir(sDir);

    char pid_Status_Path[250], buffer[500];

    while (entry != NULL)
    {
        if(strcmp(entry->d_name, READ_FILE) == 0){    //checks until "status" file is detected
            snprintf(pid_Status_Path, 250, "%s/%s", TARGET_PID_DIR, READ_FILE);    // it works like a printf but instead of printing the stream it stores into char *buffer
            
            tmpFile = fopen(pid_Status_Path,"r");
            if(tmpFile == NULL){
                printf("Error opening %s\n", pid_Status_Path);
                exit(0);
            }

            while (fgets(buffer, 500, tmpFile) != NULL)  // read first 500 chars from src file
            {
                fputs(buffer, opFile);     // write contents in buffer into op file
            }

            printf("Successfully written to %s\n", TARGET_OP_FILE);
            return 0;
            
        }
        entry = readdir(sDir);   //everytime it runs points to next file in current dir
    }

    printf("Element not found");
    
    return 0;
}
