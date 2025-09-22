#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


int main()
{
	//temperatures 개수 n
    int n;

    scanf("%d", &n);
    int* tem = (int*)malloc(sizeof(int) * (n + 2));

	//temperatures 입력받기
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        tem[i] = t;
    }
 
    //값이 0일 경우 0
    if (n == 0)
    {
        printf("0");
        return 0;
    }


	//가장 0에 가까운 온도 찾기
    int li = 0;
    for (;n > 0;n--)
    {
        for (int i = 0;i < n;i++)
        {
			if (tem[li] * tem[li] > tem[i] * tem[i])  //절댓값 비교
            {
                li = i;
            }
			if (tem[li] * tem[li] == tem[i] * tem[i])   //절댓값이 같을 때 양수 우선
            {
                if (tem[li] < tem[i])
                    li = i;
            }

        }
    }

    printf("%d\n", tem[li]);

    return 0;
}

//n값이 0인 경우 조건 반영안함.