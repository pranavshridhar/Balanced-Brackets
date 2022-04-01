#include "stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isOpening(char e)
{
    if (e == '(')
    {
        return true;
    }
    else if (e == '<')
    {
        return true;
    }
    else if (e == '[')
    {
        return true;
    }
    else if (e == '{')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isClosing(char e)
{
    if (e == ')')
    {
        return true;
    }
    else if (e == '>')
    {
        return true;
    }
    else if (e == ']')
    {
        return true;
    }
    else if (e == '}')
    {
        return true;
    }
    else
    {
        return false;
    }
}

char correspondingto(char e)
{
    if (e == '(')
    {
        return ')';
    }
    else if (e == ')')
    {
        return '(';
    }
    else if (e == '<')
    {
        return '>';
    }
    else if (e == '>')
    {
        return '<';
    }
    else if (e == '[')
    {
        return ']';
    }
    else if (e == ']')
    {
        return '[';
    }
    else if (e == '{')
    {
        return '}';
    }
    else if (e == '}')
    {
        return '{';
    }
    return '\0';
}

bool isImportant(char e)
{
    if (e == '(')
    {
        return true;
    }
    else if (e == ')')
    {
        return true;
    }
    else if (e == '{')
    {
        return true;
    }
    else if (e == '}')
    {
        return true;
    }
    else if (e == '[')
    {
        return true;
    }
    else if (e == ']')
    {
        return true;
    }
    else if (e == '<')
    {
        return true;
    }
    else if (e == '>')
    {
        return true;
    }
    return false;
}



int main() {
    printf("\nWelcome to Balanced Brackets!\n");
    while (true) {
        char input[301];
        STACK* s = stack_init();
        
        // Opens an input
        printf("Enter an input (up to 300 characters) to check if your expression is balanced, or enter q to quit.\n");
        fgets(input, 300, stdin);

        int i = 0;
        while (input[i] != '\n' && input[i] != '\0') {
            i++;
        }
        
        input[i] = '\0';

        if ((strcmp (input, "q") == 0) || (strcmp (input, "Q") == 0))
            break;
        
        printf ("%s\n", input);

        STACK* str = stack_init();

        i = 0;

        bool errFound = false;
        while(input[i] != 0) {
            char c = input[i];

            if(isImportant(c)) {

                if(isClosing(c)) {

                    if(stack_size(str) == 0) {
                        for(int k = 0; k < i; k++){
                            printf(" ");
                        }
                        printf("^ missing ");
                        printf("%c", correspondingto(c));
                        printf("\n");
                        errFound = true;
                        break;
                    } 
                    if(stack_top(str) != correspondingto(c)) {
                        for(int j = 0; j < i; j++) {
                            printf(" ");
                        }
                        printf("^ expecting %c \n", correspondingto(c));
                        errFound = true;
                        break;
                    } else {
                        stack_pop(str);
                    }

                } else if(isOpening(c)) {
                    stack_push(str, c);
                }

            } else if(isOpening(c)) {
                stack_push(str, c);
            }

            i++;
        }

        if(!errFound) {
            if(stack_size(str) != 0) {
                 for(int j = 0; j < i; j++) {
                    printf(" ");
                }
                char f = correspondingto(input[i]);
                printf("%c", f);
                printf("^ missing %c \n", correspondingto(input[i-1]));
                errFound = true;
            } else {
                printf("Expression is balanced\n");
            }
        }

        stack_dealloc(str);



        stack_dealloc(s);
    }

    printf ("\nGoodbye\n");

}