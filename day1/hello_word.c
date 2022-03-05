#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    char c = 0;
    char is_data = 0;
    const char path[] = "/proc/meminfo";
    int fd = -1;
    fd = open(path, O_RDONLY);
    if (fd < 0 )
    {
        printf("cannot open file");
        return -1;
    }
    
    while (read(fd, &c, 1) == 1 && c != '\n')
    {
        if(is_data == 0 && c != ' '){
            is_data = 0;
        } else {
            is_data = 1;
        }

        if (is_data == 1)
        {
            if(c != ' '){
                printf("%c", c);
            }
        }
    }
    printf("\n");



    close(fd);
    return 0;
}