#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//����Ʈ �����Լ�
int compare(const void* a, const void* b) {

    const char** c = (const char**)a;
    const char** d = (const char**)b;

    return strcmp(*c, *d);
}

int main()
{
    int b;
    scanf("%d", &b); fgetc(stdin); //��å ����

    //��å �Է� �ޱ�:new[b][1025]
    char** new = (char**)malloc(sizeof(char*) * (b));
    for (int i = 0; i < b; i++) {
        new[i] = (char*)malloc(sizeof(char) * 1025);
    }
    for (int i = 0; i < b; i++) {
        char title[1025] = "";
        scanf("%[^\n]", new[i]); fgetc(stdin);
    }

    int n; //å�� å
    scanf("%d", &n); fgetc(stdin);
    å�� å �Է¹ޱ�
    char** book = (char**)malloc(sizeof(char*) * n);
    for (int i = 0;i < n;i++)
    {
        book[i] = (char*)malloc(sizeof(char) * 1025);
    }

    for (int i = 0; i < n; i++) {
        char name[1025] = "";
        scanf("%[^\n]", book[i]); fgetc(stdin);
    }

    
    //�� å�� ������ �ڸ� Ȯ�� �� �����ϸ� ���� ��ȣ ������ ����
   
    //å ���� ��ġ���� Ȯ��
    int same = 0;
    for (int i = b-1;i >=0;i--)
    {
        for (int j = 0;j < n;j++)
        {
            if (strncmp(new[i], book[j], strlen(new[i])) == 0) //��å�� å��å�� ���� å ��
            {
                same++;
            }
        }
    }




    //���� ���� ��ȣ���� ���� å�� ������ ������ ���ڸ��� �����
    //���� ���� ��ȣ�� ã��
	int gi = 0; //���� ū  �ε���
    for (int j = 1;j < n;j++)
    {
        if (book[gi][strlen(book[j])-1] < book[j][strlen(book[j])-1])
        {
            gi = j;
        }
    }
    //���� ���� ��ȣ���� ���� ���� e�̸� ��� None�� ���̹Ƿ� ��������ǥ��
    if (book[gi] == 'e')
    {
        printf("1Your TBR is out of control Clara!");
        return 0;
    }

    //�� ���� ���� ��ȣ�� ���� ���� �� �� �ִ� å ����
    int cnt = 0;
    for (int i = 0;i < n;i++)
    {
        if (book[gi][strlen(book[gi]) - 1] > book[i][strlen(book[i]) - 1])
        {
            cnt++;
        }
    }
	//�ʿ��� å ����(b) - ��ġ�� å ����(same) > �� �� �ִ� å ����(cnt) �̸� ���� ����
    if (cnt < b-same)
    {
        printf("Your TBR is out of control Clara!");
        return 0;
    }



	//��ȣ�� �迭
    int* num = (int*)malloc(sizeof(int) * n);

	//��ȣ�� �迭 �ʱ�ȭ
    for (int i = 0;i < n;i++)
	{   //��ȣ���� None�� ��� 11�� ó��
        if (book[i][strlen(book[i]) - 1] == 'e' && book[i][strlen(book[i]) - 2] == 'n' && book[i][strlen(book[i]) - 3] == 'o' && book[i][strlen(book[i]) - 4] == 'N')
        {
            num[i] = 11;
            continue;
        }
        ��ȣ���� 10�� ��� 10����
        if (book[i][strlen(book[i]) - 1] == '0')
        {
            if (book[i][strlen(book[i]) - 2] == '1')
            {
                num[i] = 10;
                continue;
            }
        }
		num[i] = book[i][strlen(book[i]) - 1] - '0'; //char to int
    }


    int temp;
	//��ȣ�� ���� ���� �� ���� ��å �ֱ�
    int li = 0;
    for (int j = b;j > 0;j--)
    {
        for (int i = 1;i < n;i++)
        {
            if (num[li] > num[i])
            {
                li = i;
            }
            
        }
        strcpy(book[li], new[j - 1]); //��å �ֱ�
        temp = num[li];
        num[li] = 11; //��ȣ���� �ٲ㼭 ��å���� ǥ��
    }

    //������ å�� ��ȣ���� ���� ��ȣ���� ���� �ٸ� å�� ����
    for (int i = 0;i < n;i++)
    {
        if (li == i) //li�ε������� ��å�� �����Ƿ� �� ���� �ǳʶ�.
            continue;
        if (temp == num[i])
            book[li][0] = '\0';
    }


    //å ����
    qsort(book, n, sizeof(char*), (int(*)(const void*, const void*))compare);
	//å ���
    for (int i = 0;i < n;i++)
    {
        if (book[i][0] == '\0') continue;
		//å ���� �ڿ� ��ȣ�� ���� ����
        if (book[i][strlen(book[i]) - 1] >= '0' && book[i][strlen(book[i]) - 1] <= '9' && book[i][strlen(book[i]) - 2] <= ' ')
        {
            book[i][strlen(book[i]) - 2] = '\0';
        }
		//å ���� �ڿ� ��ȣ�� None ����
        if (book[i][strlen(book[i]) - 1] == 'e' && book[i][strlen(book[i]) - 2] == 'n' && book[i][strlen(book[i]) - 3] == 'o' && book[i][strlen(book[i]) - 4] == 'N')
        {

            book[i][strlen(book[i]) - 5] = '\0';
            printf("%s\n", book[i]);
            continue;
        }
        
        printf("%s\n", book[i]);
    }

    return 0;
}