#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 10

int main(void)
{
    char Answer1;
    int Answer2, i, j, people, reserved;
    int seat[SIZE] = { 0 };

    reserved = 0;

    while (1)
    {
        if (reserved == SIZE)
        {
            printf("모든 좌석이 예약되었습니다.\n");
            break;
        }

        printf("좌석을 예약하시겠습니까? (y/n): ");
        if (scanf(" %c", &Answer1) != 1)
        {
            printf("입력을 읽을 수 없습니다.\n");
            return 1;
        }

        if (Answer1 == 'N' || Answer1 == 'n')
        {
            break;
        }
        if (Answer1 != 'Y' && Answer1 != 'y')
        {
            printf("y 또는 n을 입력하세요.\n");
            continue;
        }

        printf("==============================\n");
        printf(" 1  2  3  4  5  6  7  8  9 10\n");
        printf("==============================\n");
        for (i = 0; i < SIZE; i++)
        {
            printf(" %d ", seat[i]);   // 0은 빈 좌석, 1은 예약된 좌석
        }
        printf("\n\n");

        printf("몇 명 예약하시겠습니까? ");
        if (scanf("%d", &people) != 1)
        {
            printf("인원은 숫자로 입력해야 합니다.\n");
            return 1;
        }
        if (people < 1 || people > SIZE - reserved)
        {
            printf("1명 이상, 남은 %d명 이하로 입력하세요.\n", SIZE - reserved);
            continue;
        }

        // 예약이 성공했을 때만 j를 증가시킵니다.
        for (j = 0; j < people; )
        {
            printf("%d번째 사람의 좌석 번호(1~10): ", j + 1);
            if (scanf("%d", &Answer2) != 1)
            {
                printf("좌석 번호는 숫자로 입력해야 합니다.\n");
                return 1;
            }

            if (Answer2 < 1 || Answer2 > SIZE)
            {
                printf("좌석 번호는 1부터 %d까지입니다.\n", SIZE);
                continue;
            }

            // 사용자 좌석 번호는 1부터, 배열의 위치는 0부터 시작합니다.
            if (seat[Answer2 - 1] == 0)
            {
                seat[Answer2 - 1] = 1;
                reserved++;
                j++;
                printf("%d번 좌석 예약 완료.\n", Answer2);
            }
            else
            {
                printf("이미 예약된 자리입니다. 다른 좌석을 선택하세요.\n");
            }
        }
    }

    printf("예약 프로그램을 종료합니다.\n");
    return 0;
}
