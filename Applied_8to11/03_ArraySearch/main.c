#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "function.h"

int main(void)
{
    int list[SIZE];
    int key, linearIndex, binaryIndex;

    MakerArr(list);

    printf("정렬 전 배열: ");
    PrnArr(list);

    printf("찾을 정수: ");
    if (scanf("%d", &key) != 1)
    {
        printf("정수를 입력해야 합니다.\n");
        return 1;
    }

    // 처음 배열에서도 가능한 순차 탐색입니다.
    linearIndex = LinearSearch(list, key);

    SortArr(list);
    printf("정렬 후 배열: ");
    PrnArr(list);

    // 이진 탐색은 반드시 정렬한 다음에 사용합니다.
    binaryIndex = BinarySearch(list, key);

    if (linearIndex == -1)
    {
        printf("순차 탐색: 찾지 못했습니다.\n");
    }
    else
    {
        printf("순차 탐색: 정렬 전 list[%d]에서 찾았습니다.\n", linearIndex);
    }

    if (binaryIndex == -1)
    {
        printf("이진 탐색: 찾지 못했습니다.\n");
    }
    else
    {
        printf("이진 탐색: 정렬 후 list[%d]에서 찾았습니다.\n", binaryIndex);
    }

    return 0;
}
