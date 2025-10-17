#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Try the command like..-> %s <fileName1> <filename2>\n", argv[0]);
        return 1;
    }

    int i;
    for (i = 1; i < argc; i++) {
        if (remove(argv[i]) == 0) {
            printf("Removed file '%s'\n", argv[i]);
        } else {
            printf("Failed to remove the file %s....\n", argv[i]);
        }
    }

    return 0;
}

