#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 5

// 사용할 함수를 main보다 먼저 알려 줍니다.
int InputScores(int score[]);
void PrintScores(int score[]);
int SumScores(int score[]);
int MaxScore(int score[]);

int main(void)
{
    int score[SIZE];
    int sum;
    int max;

    if (InputScores(score) == 0)
    {
        printf("입력 오류로 프로그램을 종료합니다.\n");
        return 1;
    }

    PrintScores(score);

    sum = SumScores(score);
    max = MaxScore(score);

    printf("점수 합계: %d\n", sum);
    printf("점수 평균: %.1f\n", (double)sum / SIZE);
    printf("최고 점수: %d\n", max);

    return 0;
}

// 배열에 다섯 명의 점수를 입력합니다. 성공하면 1을 돌려줍니다.
int InputScores(int score[])
{
    int i;

    for (i = 0; i < SIZE; i++)
    {
        while (1)
        {
            printf("%d번째 점수(0~100): ", i + 1);

            if (scanf("%d", &score[i]) != 1)
            {
                return 0;
            }

            if (score[i] >= 0 && score[i] <= 100)
            {
                break;
            }

            printf("점수는 0부터 100까지 입력하세요.\n");
        }
    }

    return 1;
}

// 배열에 저장된 점수를 차례대로 출력합니다.
void PrintScores(int score[])
{
    int i;

    printf("\n입력한 점수\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("score[%d] = %d\n", i, score[i]);
    }
}

// 합계를 계산해서 main에 돌려줍니다.
int SumScores(int score[])
{
    int i;
    int sum = 0;

    for (i = 0; i < SIZE; i++)
    {
        sum = sum + score[i];
    }

    return sum;
}

// 가장 큰 점수를 찾아 main에 돌려줍니다.
int MaxScore(int score[])
{
    int i;
    int max = score[0];

    for (i = 1; i < SIZE; i++)
    {
        if (score[i] > max)
        {
            max = score[i];
        }
    }

    return max;
}
