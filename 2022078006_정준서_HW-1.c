#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    int height[8]; //�� ���������ϴ� �迭
    // game loop
    while (1) {


        int gi = 0; //���� ū �� ������ �ε���


        for (int j = 0;j < 8;j++)
        {
            //�� ���� �迭�� ����
            for (int i = 0; i < 8; i++) {
                int mountain_h;
                scanf("%d", &mountain_h);
                height[i] = mountain_h;
            }
            //���� ���� ���� �ε��� ã��
            for (int i = 0;i < 8;i++)
            {
                if (height[gi] < height[i])
                {
                    gi = i;
                }
            }
            //���� ���� �� �ε��� ���
            printf("%d\n", gi);


        }
    }

    return 0;
}