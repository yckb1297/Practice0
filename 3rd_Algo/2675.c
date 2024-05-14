#include <stdio.h>
#include <string.h>

int main()
{
    int T, R, i, j, k;
    char S[20];

    scanf("%d", &T);

    for (i=0; i<T; i++) //테스트 개수만큼 반복
    {
        scanf("%d %s", &R, S);

        for (j=0; j<strlen(S); j++) //S의 길이만큼 반복
        {
            for (k=0; k<R; k++)
            {
                printf("%c", S[j]);
            }
        }printf("\n");
    }return 0;
}