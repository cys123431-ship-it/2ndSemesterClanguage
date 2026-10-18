#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "function.h"

// 난수로 배열을 채우는 함수
void MakerArr(int list[])
{
    int i;
    srand((unsigned int)time(NULL));

    for (i = 0; i < SIZE; i++)
    {
        list[i] = rand() % 100;  // 0부터 99까지의 정수
    }
}

// 배열 원소를 차례대로 출력하는 함수
void PrnArr(int list[])
{
    int i;

    for (i = 0; i < SIZE; i++)
    {
        printf("%d  ", list[i]);
    }
    printf("\n");
}

// 선택 정렬: 가장 작은 값을 찾아 앞쪽부터 채웁니다.
void SortArr(int list[])
{
    int i, j, min, temp;

    for (i = 0; i < SIZE - 1; i++)
    {
        min = i;
        for (j = i + 1; j < SIZE; j++)
        {
            if (list[j] < list[min])
            {
                min = j;
            }
        }

        temp = list[i];
        list[i] = list[min];
        list[min] = temp;
    }
}

// 정렬된 배열에서 가운데 값을 비교하며 찾는 이진 탐색
void BinarySearch(int list[])
{
    int low, mid, high, count, key;

    low = 0;
    high = SIZE - 1;
    count = 1;

    printf("찾을 값을 입력하세요: ");
    if (scanf("%d", &key) != 1)
    {
        printf("찾을 값은 숫자로 입력해야 합니다.\n");
        return;
    }

    printf("\n이진 탐색 과정\n");
    while (low <= high)
    {
        mid = (low + high) / 2;
        printf("\n%d회 탐색: low=%d, high=%d, mid=%d\n", count, low, high, mid);
        printf("list[%d]=%d와 찾을 값 %d 비교\n", mid, list[mid], key);

        if (list[mid] == key)
        {
            printf("%d를 찾았습니다. 위치: list[%d]\n", key, mid);
            return;
        }
        else if (list[mid] > key)
        {
            printf("%d > %d이므로 왼쪽 탐색\n", list[mid], key);
            high = mid - 1;
        }
        else
        {
            printf("%d < %d이므로 오른쪽 탐색\n", list[mid], key);
            low = mid + 1;
        }
        count++;
    }

    printf("%d는 배열에 없습니다.\n", key);
}
