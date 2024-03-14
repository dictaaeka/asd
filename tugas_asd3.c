#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 2024
#define MIN_LENGTH 1945

void lessThanRequired(int *lengthOfText)
{
    printf("the length of your text is less then specified, please update your text\n");
    *lengthOfText = MIN_LENGTH;
}

void equalThanRequired()
{
    printf("thank you, your length is correct\n");
}

void moreThanRequired(int *lengthOfText)
{
    printf("your length is too long, please reduce the text\n");
    *lengthOfText = MIN_LENGTH;
}

int checkLenghtRequirement(char *text)
{
    int length = strlen(text);
    if (length < MIN_LENGTH)
        return 0;
    else if (length == MIN_LENGTH )
        return 1;
    else
        return 2;
}

int main()
{
    int length, lengthOfText, selectOption;
    FILE *fptr = NULL;
    char text[4000];

    fptr = fopen("text_file.txt", "r");

    if (fptr == NULL)
    {
        printf("Error");
        exit(1);
    }

    fgets(text, MAX_LENGTH, fptr);

    fclose(fptr);

    selectOption = checkLenghtRequirement(text);

    void (*options[3])(int *) = {lessThanRequired, equalThanRequired, moreThanRequired};
    options[selectOption](&lengthOfText);

    printf("\nThe Lenght is updated to %d", lengthOfText);

    return 0;
}