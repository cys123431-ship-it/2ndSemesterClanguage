#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 10

void PrintSeats(int seat[]);
int CountAvailable(int seat[]);
int ReserveSeat(int seat[], int number);

int main(void)
{
    int seat[SIZE] = { 0 };
    char answer;
    int people, number, i, result, available;

    while (1)
    {
        available = CountAvailable(seat);

        if (available == 0)
        {
            printf("모든 좌석이 예약되었습니다.\n");
            break;
        }

        printf("\n좌석을 예약하시겠습니까? (y/n): ");
        if (scanf(" %c", &answer) != 1)
        {
            printf("입력 오류입니다.\n");
            return 1;
        }

        if (answer == 'n' || answer == 'N')
        {
            break;
        }
        if (answer != 'y' && answer != 'Y')
        {
            printf("y 또는 n을 입력하세요.\n");
            continue;
        }

        PrintSeats(seat);
        printf("남은 좌석: %d개\n", available);

        printf("예약할 인원 수: ");
        if (scanf("%d", &people) != 1)
        {
            printf("인원은 숫자로 입력하세요.\n");
            return 1;
        }

        if (people < 1 || people > available)
        {
            printf("1명 이상 %d명 이하로 입력하세요.\n", available);
            continue;
        }

        // 성공적으로 예약했을 때만 i를 증가시킵니다.
        for (i = 0; i < people;)
        {
            printf("%d번째 사람의 좌석 번호(1~10): ", i + 1);
            if (scanf("%d", &number) != 1)
            {
                printf("좌석 번호는 숫자로 입력하세요.\n");
                return 1;
            }

            result = ReserveSeat(seat, number);

            if (result == 1)
            {
                printf("%d번 좌석 예약 완료.\n", number);
                i++;
            }
            else if (result == 0)
            {
                printf("이미 예약된 자리입니다. 다시 선택하세요.\n");
            }
            else
            {
                printf("좌석 번호는 1부터 10까지입니다.\n");
            }
        }
    }

    printf("\n최종 좌석 현황\n");
    PrintSeats(seat);
    printf("예약 프로그램을 종료합니다.\n");

    return 0;
}

// 0은 빈 좌석, 1은 이미 예약한 좌석입니다.
void PrintSeats(int seat[])
{
    int i;

    printf("==============================\n");
    printf(" 1  2  3  4  5  6  7  8  9 10\n");
    printf("==============================\n");

    for (i = 0; i < SIZE; i++)
    {
        printf(" %d ", seat[i]);
    }

    printf("\n");
}

// 예약되지 않은 좌석의 수를 계산해 돌려줍니다.
int CountAvailable(int seat[])
{
    int i;
    int count = 0;

    for (i = 0; i < SIZE; i++)
    {
        if (seat[i] == 0)
        {
            count++;
        }
    }

    return count;
}

// 1: 성공, 0: 이미 예약됨, -1: 범위를 벗어남
int ReserveSeat(int seat[], int number)
{
    if (number < 1 || number > SIZE)
    {
        return -1;
    }

    if (seat[number - 1] == 1)
    {
        return 0;
    }

    seat[number - 1] = 1;
    return 1;
}
