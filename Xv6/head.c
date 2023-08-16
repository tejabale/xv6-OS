#include "types.h"
#include "stat.h"
#include "user.h"

char buf[512];

void cat(int fd, int num){

    int n;
    int no_lines = 0;

    while ((n = read(fd, buf, sizeof(buf))) > 0){
        if(no_lines >= num){
            break;
        }
        for(int i=0; i<n; i++){
            if(buf[i] == '\n'){
                no_lines++;
                if(no_lines<=num){
                    if (write(1, buf+i, 1) != 1){
                        printf(1, "cat: write error\n");
                        exit();
                    }
                }
            }
            else if(no_lines < num){
                if (write(1, buf+i, 1) != 1){
                    printf(1, "cat: write error\n");
                    exit();
                }
            }
        }
        
    }

    if (n < 0){
        printf(1, "cat: read error\n");
        exit();
    }
}

int main(int argc, char *argv[]){
    int fd, i;
    int n = atoi(argv[1]);
    if (argc <= 2){
        cat(0, 0);
        exit();
    }

    for (i = 2; i < argc; i++)
    {
        if ((fd = open(argv[i], 0)) < 0)
        {
            printf(1, "cat: cannot open %s\n", argv[i]);
            exit();
        }
        printf(1, "-----%s-----\n" , argv[i]);
        cat(fd, n);
        close(fd);
    }
    exit();
}
