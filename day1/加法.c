#include <stdio.h>
#include <string.h>
int main()
{
    char a[100];
    char b[100];
    char c[101];
    int j = 0;
    memset(a, 0, 100);
    memset(b, 0, 100);
    memset(c, 0, 101);
    scanf("%s", c);
    for (int i = strlen(c) - 1; i >= 0; i--)
    {
        a[j++] = c[i] - '0';
    }
    j = 0;
    scanf("%s", c);
    for (int i = strlen(c) - 1; i >= 0; i--)
    {
        b[j++] = c[i] - '0';
    }
    int s = 0;
    int MAXLEN;
    if (strlen(a) >= strlen(b))
    {
        MAXLEN = strlen(a);
    }
    else
        MAXLEN = strlen(b);
    for (int k = 0, i = 0; i < MAXLEN; i++)
    {
        s = a[i] + b[i] + k;
        a[i] = s % 10;
        k = s / 10;
    }
    for (int i = MAXLEN; i >= 0; i--)
    {
        if (a[i] != 0)
        {
            for (int m = i; m >= 0; m--)
            {
                printf("%d", a[m]);
            }
            break;
        }
    }
}