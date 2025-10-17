#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN	10000

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Try the command like..-> %s <pattern> <filename>\n", argv[0]);
        return 1;
    }

    char *pattern = argv[1];
    char *fileName = argv[2];
    FILE *fp = fopen(fileName, "r");

    if (fp == NULL) {
        printf("Error opening file.....\n");
        return 1;
    }

    char line[MAX_LEN];
    int line_num = 0;
    int found = 0;

    while (fgets(line, sizeof(line), fp)) {
        line_num++;
        if (strstr(line, pattern)) {
            printf("%d: %s", line_num, line);
            found = 1;
        }
    }

    if (!found) {
        printf("No matches found...\n");
    }

    fclose(fp);
    return 0;
}

