#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>

/*
 * Event types
 */

#define EV_SYN 0x00
#define EV_KEY 0x01
#define EV_REL 0x02
#define EV_ABS 0x03
#define EV_MSC 0x04

#define KEY_1 2
#define KEY_2 3
#define KEY_3 4
#define KEY_4 5
#define KEY_5 6
#define KEY_6 7
#define KEY_7 8
#define KEY_8 9
#define KEY_9 10
#define KEY_0 11
#define KEY_MINUS 12
#define KEY_EQUAL 13
#define KEY_BACKSPACE 14
#define KEY_TAB 15
#define KEY_Q 16
#define KEY_W 17
#define KEY_E 18
#define KEY_R 19
#define KEY_T 20
#define KEY_Y 21
#define KEY_U 22
#define KEY_I 23
#define KEY_O 24
#define KEY_P 25
#define KEY_LEFTBRACE 26
#define KEY_RIGHTBRACE 27
#define KEY_ENTER 28
#define KEY_LEFTCTRL 29
#define KEY_A 30
#define KEY_S 31
#define KEY_D 32
#define KEY_F 33
#define KEY_G 34
#define KEY_H 35
#define KEY_J 36
#define KEY_K 37
#define KEY_L 38

char pretty_print(int key)
{
    switch (key)
    {
    case KEY_1:
        return '1';
    case KEY_2:
        return '2';
    case KEY_3:
        return '3';
    case KEY_4:
        return '4';
    default:
        break;
    }
}

int main(int argc, char **argv)
{
    int fd, bytes;
    struct input_event data;

    const char *pDevice = "/dev/input/event4";

    // Open Keyboard
    fd = open(pDevice, O_RDONLY | O_NONBLOCK);
    if (fd == -1)
    {
        printf("ERROR Opening %s\n", pDevice);
        return -1;
    }

    while (1)
    {
        // Read Keyboard Data
        bytes = read(fd, &data, sizeof(data));
        if (bytes > 0)
        {
            /*printf("Keypress value=%d, type=%d, code=%d\n",
                data.value, data.type, data.code);*/
            if (data.type == 1)
            {
                printf("Keypress = %c : %d\n",
                       pretty_print(data.code),
                       data.code);
            }
        }
        else
        {
            // Nothing read
            sleep(1);
        }
    }

    return 0;
}