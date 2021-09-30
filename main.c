
#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[]) {

    FILE *file = fopen(argv[2],"r");

    unsigned int count_line = 1;
    unsigned int count_word = 0;
    unsigned int count_byte = 0;
    int state = 0;
    char c;

    while((c = fgetc(file)) != EOF){
        if(c == '\n')
            count_line++ ;
        if(c == ' ' || c == '\n' || c == '\t')
            state = 0;
        else if(state == 0){
            state = 1;
            count_word++ ;
        }
        count_byte++;
    }

    if(strcmp(argv[1], "-c") == 0 || strcmp(argv[1], "--bytes") == 0)
        printf("%d\n", count_byte);

    else if(strcmp(argv[1], "-w") == 0 || strcmp(argv[1], "--words") == 0)
        printf("%d\n", count_word);

    else if(strcmp(argv[1], "-l") == 0 || strcmp(argv[1], "--lines") == 0)
        printf("%d\n", count_line);

    fclose(file);
    return 0;
}
