#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "function.h"

// 0부터 99까지의 난수 10개로 배열을 채웁니다.
void MakerArr(int list[])
{
    int i;

    srand((unsigned int)time(NULL));

    for (i = 0; i < SIZE; i++)
    {
        list[i] = rand() % 100;
    }
}

// 현재 배열 내용을 출력합니다.
void PrnArr(int list[])
{
    int i;

    for (i = 0; i < SIZE; i++)
    {
        printf("%d  ", list[i]);
    }
    printf("\n");
}

// 정렬하지 않은 배열에서도 사용할 수 있는 순차 탐색입니다.
int LinearSearch(int list[], int key)
{
    int i;

    for (i = 0; i < SIZE; i++)
    {
        if (list[i] == key)
        {
            return i;
        }
    }

    return -1;
}

// 가장 작은 원소를 앞쪽으로 옮기는 선택 정렬입니다.
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

// 정렬된 배열에서 가운데 값을 비교하며 범위를 좁힙니다.
int BinarySearch(int list[], int key)
{
    int low = 0;
    int high = SIZE - 1;
    int mid;
    int count = 1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        printf("%d회: low=%d, mid=%d, high=%d, list[mid]=%d\n",
               count, low, mid, high, list[mid]);

        if (list[mid] == key)
        {
            return mid;
        }
        else if (list[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }

        count++;
    }

    return -1;
}
