#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 5

int main(void)
{
    int i;
    int score[SIZE];

    printf("5명의 점수를 입력하시오.\n");

    for (i = 0; i < SIZE; i++)
    {
        printf("%d번째 점수: ", i + 1);
        if (scanf("%d", &score[i]) != 1)
        {
            printf("점수를 숫자로 입력해야 합니다.\n");
            return 1;
        }
    }

    printf("\n입력한 점수\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("scores[%d] = %d\n", i, score[i]);
    }

    return 0;
}
