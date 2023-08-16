#include "types.h"
#include "stat.h"
#include "user.h"


int main(int argc, char *argv[]){

    char** args = argv+ 1;
    int pid = fork();
    if(pid == 0){
        exec(args[0] ,args);
        exit();
    }
    else{
        wait();
        exit();
    }

}