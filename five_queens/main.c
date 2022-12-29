/* 
2305 박준선 5Queens 알고리즘 (C언어)
1: Queen, 2: 체스판 공간
*/

#include <stdio.h>

int five_queens(int x, int y, int _arr[][5]) 
{
    int arr[5][5];

    for(int i = 0; i < 5; i ++) // 인자로 받은 배열 복사
    {
        for(int j = 0; j < 5; j ++)
        {
            arr[i][j] = _arr[i][j];
        }
    }

    arr[y][x] = 1;

    /* 퀸의 이동 가능 경로 기록 */
    for (int i = 0; i < 5; i ++) // 세로
    {
        if(arr[y][i] != 1) arr[y][i] = 2;
    }
    for (int i = 0; i < 5; i ++) //가로
    {
        if(arr[i][x] != 1) arr[i][x] = 2;
    }
    for (int i = 1; (y + i) <  5 && (x + i) <  5; i ++)  // 우측 - 아래
    {
        if(arr[y + i][x + i] != 1) arr[y + i][x + i] = 2;
    }
    for (int i = 1; (y - i) > -1 && (x - i) > -1; i ++) // 좌측 - 위
    {
        if(arr[y - i][x - i] != 1) arr[y - i][x - i] = 2;
    }
    for (int i = 1; (y + i) <  5 && (x - i) > -1; i ++) // 좌측 - 아래
    {
        if(arr[y + i][x - i] != 1) arr[y + i][x - i] = 2;
    }
    for (int i = 1; (y - i) > -1 && (x + i) <  5; i ++) // 우측 - 위
    {
        if(arr[y - i][x + i] != 1) arr[y - i][x + i] = 2;
    }

    if (y == 4) // 맨 아래까지 퀸이 배치 가능한 경우일 때
    {
        for (int i = 0; i < 5; i ++) // 체스판 출력
        {
            for (int j = 0; j < 5; j ++)
            {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
        printf("= = = = = \n");
    }

    for (int i = 0; i < 5; i ++) // 퀸이 배치 가능한 경우 계산
    {
        if (y + 1 > 4) break;
        if (arr[y + 1][i] == 0) five_queens(i, y + 1, arr);
    }

    return 0;
}

int main()
{
    int arr[5][5] = {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
    for (int i = 0; i < 5; i ++)
    {
        five_queens(i, 0, arr);
    }

    return 0;
}
