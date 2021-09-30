
#include <stdio.h>

char compare(char a[], char b[]) {
    int t = 1;
    int i = 0;

    while(a[i]) {
        if(a[i] != b[i])
            t = 0;
        i++;
    }

    if(t == 1)
        return 'T';
    else
        return 'F';
}


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

    if(compare(argv[1], "-c") == 'T' || compare(argv[1], "--bytes") == 'T')
        printf("%d\n", count_byte);

    if(compare(argv[1], "-w") == 'T' || compare(argv[1], "--words") == 'T')
        printf("%d\n", count_word);

    if(compare(argv[1], "-l") == 'T' || compare(argv[1], "--lines") == 'T')
        printf("%d\n", count_line);

    fclose(file);
    return 0;
}
