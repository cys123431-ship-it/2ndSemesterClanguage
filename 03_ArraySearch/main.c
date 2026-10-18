#include <stdio.h>
#include "function.h"

int main(void)
{
    int list[SIZE];

    MakerArr(list);             // 난수 배열 생성

    printf("정렬 전: ");
    PrnArr(list);               // 원래 배열 출력

    SortArr(list);              // 선택 정렬

    printf("정렬 후: ");
    PrnArr(list);               // 정렬한 배열 출력

    BinarySearch(list);         // 정렬한 배열에서 이진 탐색

    return 0;
}
