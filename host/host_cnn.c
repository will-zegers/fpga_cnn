#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdint.h>

int host(char inputFileName[]);

int main() {
    char inputFileName[] = "input0.dat";
    int i;
    getchar();
    for (i = 0; i < 10; i++) {
        inputFileName[5] = (char)(i+48);
        host(inputFileName);
        getchar();
    }
    return 0;
}


int host(char inputFileName[]) {
    int fdr, fdw;

    float tologic[1024];
    float fromlogic[10];
    FILE *fin;

    int i;

    for (i = 0; i < 1024; i++) {
        tologic[i] = 0;
    }

    fin = fopen(inputFileName, "r");
    for (i = 0; i < 1024; i++) {
        fscanf(fin, "%f\n", &tologic[i]);
    }
    fclose(fin);


    fdr = open("/dev/xillybus_read_32", O_RDONLY);
    fdw = open("/dev/xillybus_write_32", O_WRONLY);

    if ((fdr < 0) || (fdw < 0)) {
        perror("Failed to open Xillybus device file(s)");
        exit(1);
    }

    write(fdw, (void *) &tologic, sizeof(tologic));
    read(fdr, (void *) &fromlogic, sizeof(fromlogic));

    printf("    The probabilities of the digit being 0~9 are:\n");
    for (i = 0; i < 10; i++) {
        printf("        %d: %f\n", i, fromlogic[i]);
    }

    close(fdr);
    close(fdw);

    return 0;
}
