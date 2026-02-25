#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int yes_flag = 0;
    int no_flag = 0;
    int d_flag = 0;
    int number = 0;
    char buf[9999];
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-y") == 0) 
        {
            yes_flag = 1;
        }
        if (strcmp(argv[i], "-h") == 0)
        {
            printf("soooo... if -y flag set them u... dont need to enter smthn...\nannd -h for this message\n-no for entering number and then printing that many dashes\n");
            return 0;
        }
        if (strcmp(argv[i], "-no") == 0)          
        {
            char buf[100];
            fgets(buf, sizeof(buf), stdin);
            number = atoi(buf);
            no_flag = 1;
        }
        
    }

    if (geteuid() == 0) {
        printf("hello root\n");
        printf("cli tool\n");
        if (yes_flag == 1) {
            printf("entered -y flag, so no need to enter smth\n");
        } else {
            printf("enter smth: \n");
            fgets(buf, sizeof(buf), stdin);
            if (strstr(buf, "epstein") != NULL) {
                printf("you entered epstein, funny.\n");
                return -1488;
            }

            printf("you entered: %s \n", buf);
        }
    } else {
        if (no_flag == 1)
        {
            for (int i = 0; i < number; i++) {
                printf("-");
            }
        }
        else {
            printf("use sudo. \n");
        }
    }
    return 0;
}