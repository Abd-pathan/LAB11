#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MXCMDL 400
#define MXOPL 4000

void myFunc(const char *cmd) {
    FILE *fp;
    char op[MXOPL];

    fp = popen(cmd, "r");
    if (fp == NULL) {
        perror("Error opening pipe");
        exit(EXIT_FAILURE);
    }
    while (fgets(op, MXOPL, fp) != NULL) {
        printf("%s", op);
    }
    pclose(fp);
}

int main() {
    char cmd[MXCMDL];

    while (1) {
        printf("Enter command: ");
        fgets(cmd, MXCMDL, stdin);

        cmd[strcspn(cmd, "\n")] = '\0';

        if (strcmp(cmd, "quit") == 0) {
            printf("Exiting program...bye!\n");
            break;
        }
        myFunc(cmd);
    }

    return 0;
}
