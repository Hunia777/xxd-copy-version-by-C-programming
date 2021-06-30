#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int file_len = sizeof(argv[1]);
    int CH = 0;
    int blank = 0;
    char file_name[1000];
    char buffer[17];
    char empty[17] = "";
    memcpy(file_name, argv[1], file_len);

    FILE *bin_file;
    bin_file = fopen(file_name, "rb");
    if(bin_file == NULL)
    {
        perror(" \"FOPEN\" ERROR, CAN NOT FIND YOUR INPUT FILE\n");
        return -1;
    }

    while(( CH = fgetc(bin_file) ) != EOF)
    {

        printf("%02X", CH);
        if((int)CH == 0)
            buffer[blank%16] = '.';
        else
            buffer[blank%16] = (char)CH;
        blank++;
        if(blank % 2 == 0)
            printf(" ");
        if(blank % 16 == 0)
        {
            printf(" %s", buffer);
            memcpy(buffer, empty, sizeof(empty));
            printf("\n");
        }
            
    }
    fclose(bin_file);
    printf("\n");
    printf("Total Read Character: %d\n\n", blank);
    return 0;

}