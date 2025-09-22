#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    int height[8]; //산 높이저장하는 배열
    // game loop
    while (1) {


        int gi = 0; //가장 큰 산 높이의 인덱스


        for (int j = 0;j < 8;j++)
        {
            //산 높이 배열에 저장
            for (int i = 0; i < 8; i++) {
                int mountain_h;
                scanf("%d", &mountain_h);
                height[i] = mountain_h;
            }
            //가장 높은 산의 인덱스 찾기
            for (int i = 0;i < 8;i++)
            {
                if (height[gi] < height[i])
                {
                    gi = i;
                }
            }
            //가장 높은 산 인덱스 출력
            printf("%d\n", gi);


        }
    }

    return 0;
}