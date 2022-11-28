#include <stdio.h>
#include <math.h>
float scannum(char ch)
{
    int value;
    value = ch;
    return (float)(value - '0');
}
int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return 1;
    return -1;
}
int isOperand(char ch)
{
    if (ch >= '0' && ch <= '9')
        return 1;
    return -1;
}
float operation(int a, int b, char op)
{
    if (op == '+')
        return b + a;
    else if (op == '-')
        return b - a;
    else if (op == '*')
        return b * a;
    else if (op == '/')
        return b / a;
    else if (op == '^')
        return pow(b, a);
    else
        return 0;
}
float postfix(char *postfix)
{
    int a, b;
    int stk[100];
    int top = -1;
    char *it;
    for (it = postfix; *it != '\0'; it++)
    {
        if (isOperator(*it) != -1)
        {
            a = stk[top];
            top--;
            b = stk[top];
            top--;
            top++;
            stk[top] = operation(a, b, *it);
        }
        else if (isOperand(*it) > 0)
        {
            top++;
            stk[top] = scannum(*it);
        }
    }
    return stk[top];
}
int main()
{
    
    char post[] = "45+78/35*2";
    printf("%s = ", post);
    printf("%f", postfix(post));
}