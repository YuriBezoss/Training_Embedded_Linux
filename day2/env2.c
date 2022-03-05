#include <stdio.h>

extern char **environ;

int main(int argc, char *argv[]){
    int i = 0;

    for(i=0; environ[i] != 0; i++){
        printf("%s\n\r", environ[i]);
    }
    
    return 0;
}

