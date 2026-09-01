#include <stdio.h>
#include <ctype.h>

int main() {
    char ch;

    printf("Enter an uppercase character: ");
    scanf("%c", &ch);

    ch = tolower(ch);

    printf("Lowercase character: %c\n", ch);

    return 0;
}


