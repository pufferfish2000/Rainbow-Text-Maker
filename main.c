#include <stdio.h>
#include <time.h>

int rand(void);
void srand(int);

const unsigned int COLORS[] = {248,140,132, 255,171,112, 248,251,149, 143,251,91, 97,251,234, 65,174,234, 174,94,234};

void rainbow_print(char* text) {
    for (int i = 0; i < 7; i++) {
        printf("\x1b[38;2;%d;%d;%dm", COLORS[i*3], COLORS[i*3+1], COLORS[i*3+2]);
        printf("%s", text);
        printf("\n");
    }
    for (int i = 5; i >= 0; i--) {
        printf("\x1b[38;2;%d;%d;%dm", COLORS[i*3], COLORS[i*3+1], COLORS[i*3+2]);
        printf("%s", text);
        printf("\n");
    }
}
void set_color(int i) {
    printf("\x1b[38;2;%d;%d;%dm", COLORS[i*3], COLORS[i*3+1], COLORS[i*3+2]);
}
void rainbow_chars(char* text) {
    srand(time(NULL));
    int i = rand() %7;
    int size = 0;
    while (text[size]!= 0){
        size++;
    }
    for (int counter = 0; counter < size; counter++){
        set_color(i);
        printf("%c", text[counter]);
        i++;
        i %= 7;
    }

    printf("\n");
    //printf("the size was..... %d!\n", size);
}

int main(void) {
    printf("Enter your text here: ");
    char input[1000];
    fgets(input, 1000, stdin);
    rainbow_chars(input);

    return 0;
}


