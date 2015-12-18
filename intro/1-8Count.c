#include <stdio.h>

int main()
{
    int nw,tb,sp; 
    nw = tb = sp = 0;
    int c;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
            sp++;
        if (c == '\t')
            tb++;
        if (c == '\n')
            nw++;
    }
    printf("%d",sp);
    printf("%d",tb);
    printf("%d",nw);
}
