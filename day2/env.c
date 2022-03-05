#include <stdio.h>

int main(int argc, char *argv[]){
    FILE *fp = NULL;
    const char *path = "./data";
    fp = fopen(path, "a");
    if(NULL == fp){
        printf("cannot open file");
        return -2;
    } else {
        printf("open file successfully \n");
        return 0;
    }
    
    return 0;
}

