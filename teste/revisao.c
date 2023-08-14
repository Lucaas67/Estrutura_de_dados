#include <stdio.h> 
#include <string.h> 

int main(int argc, char* argv[]){
    int i = 11;
    float f = 1.5;
    double d = 1.55555555;
    char c = 'J';
    char* string = "nao existe string em C.";

    if(i){
        printf("\n%d e verdadeiro", i);
    }

    printf("\n%c - %s (%d)", c, string, strlen(string));
    printf("\n");
    for(n = 0; n < strlen(string); n++){
        printf("%c", string[n])/
        n++;
    }

    return 0;
}