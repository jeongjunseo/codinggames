#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


int main()
{
	//temperatures ���� n
    int n;

    scanf("%d", &n);
    int* tem = (int*)malloc(sizeof(int) * (n + 2));

	//temperatures �Է¹ޱ�
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        tem[i] = t;
    }
 
    //���� 0�� ��� 0
    if (n == 0)
    {
        printf("0");
        return 0;
    }


	//���� 0�� ����� �µ� ã��
    int li = 0;
    for (;n > 0;n--)
    {
        for (int i = 0;i < n;i++)
        {
			if (tem[li] * tem[li] > tem[i] * tem[i])  //���� ��
            {
                li = i;
            }
			if (tem[li] * tem[li] == tem[i] * tem[i])   //������ ���� �� ��� �켱
            {
                if (tem[li] < tem[i])
                    li = i;
            }

        }
    }

    printf("%d\n", tem[li]);

    return 0;
}

//n���� 0�� ��� ���� �ݿ�����.