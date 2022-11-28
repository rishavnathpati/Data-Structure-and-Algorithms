#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

double evaluateprefix(char *prefixExp)
{

    char operendStack[100];
    int top = -1;

    for (int i = strlen(prefixExp) - 1; i >= 0; i--)
    {

        if (isdigit(prefixExp[i]))
            operendStack[++top] = prefixExp[i] - '0';
        else
        {
            double o1 = operendStack[top--];
            double o2 = operendStack[top--];
            if (prefixExp[i] == '+')
                operendStack[++top] = o1 + o2;
            else if (prefixExp[i] == '-')
                operendStack[++top] = o1 - o2;
            else if (prefixExp[i] == '*')
                operendStack[++top] = o1 * o2;
            else if (prefixExp[i] == '/')
                operendStack[++top] = o1 / o2;
            else
            {
                printf("Invalid Expression");
                return -1;
            }
        }
    }
    return operendStack[top];
}

int main()

{
    char prefix[] = "*+54-23";
    printf("%s= %f", prefix, evaluateprefix(prefix));
}
