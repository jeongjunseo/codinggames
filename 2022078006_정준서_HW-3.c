#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//퀵소트 기준함수
int compare(const void* a, const void* b) {

    const char** c = (const char**)a;
    const char** d = (const char**)b;

    return strcmp(*c, *d);
}

int main()
{
    int b;
    scanf("%d", &b); fgetc(stdin); //새책 개수

    //새책 입력 받기:new[b][1025]
    char** new = (char**)malloc(sizeof(char*) * (b));
    for (int i = 0; i < b; i++) {
        new[i] = (char*)malloc(sizeof(char) * 1025);
    }
    for (int i = 0; i < b; i++) {
        char title[1025] = "";
        scanf("%[^\n]", new[i]); fgetc(stdin);
    }

    int n; //책장 책
    scanf("%d", &n); fgetc(stdin);
    책장 책 입력받기
    char** book = (char**)malloc(sizeof(char*) * n);
    for (int i = 0;i < n;i++)
    {
        book[i] = (char*)malloc(sizeof(char) * 1025);
    }

    for (int i = 0; i < n; i++) {
        char name[1025] = "";
        scanf("%[^\n]", book[i]); fgetc(stdin);
    }

    
    //새 책의 서랍장 자리 확인 후 부족하면 가장 선호 낮은거 없애
   
    //책 제목 겹치는지 확인
    int same = 0;
    for (int i = b-1;i >=0;i--)
    {
        for (int j = 0;j < n;j++)
        {
            if (strncmp(new[i], book[j], strlen(new[i])) == 0) //새책과 책장책과 기존 책 비교
            {
                same++;
            }
        }
    }




    //가장 높은 선호도를 가진 책을 제외한 나머지 빈자리가 몇개인지
    //가장 높은 선호도 찾기
	int gi = 0; //가장 큰  인덱스
    for (int j = 1;j < n;j++)
    {
        if (book[gi][strlen(book[j])-1] < book[j][strlen(book[j])-1])
        {
            gi = j;
        }
    }
    //가장 높은 선호도가 가장 끝이 e이면 모두 None인 것이므로 공간없음표시
    if (book[gi] == 'e')
    {
        printf("1Your TBR is out of control Clara!");
        return 0;
    }

    //그 가장 높은 선호도 보다 낮은 뺄 수 있는 책 개수
    int cnt = 0;
    for (int i = 0;i < n;i++)
    {
        if (book[gi][strlen(book[gi]) - 1] > book[i][strlen(book[i]) - 1])
        {
            cnt++;
        }
    }
	//필요한 책 개수(b) - 겹치는 책 개수(same) > 뺄 수 있는 책 개수(cnt) 이면 공간 부족
    if (cnt < b-same)
    {
        printf("Your TBR is out of control Clara!");
        return 0;
    }



	//선호도 배열
    int* num = (int*)malloc(sizeof(int) * n);

	//선호도 배열 초기화
    for (int i = 0;i < n;i++)
	{   //선호도가 None인 경우 11로 처리
        if (book[i][strlen(book[i]) - 1] == 'e' && book[i][strlen(book[i]) - 2] == 'n' && book[i][strlen(book[i]) - 3] == 'o' && book[i][strlen(book[i]) - 4] == 'N')
        {
            num[i] = 11;
            continue;
        }
        선호도가 10인 경우 10저장
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
	//선호도 가장 낮은 것 빼고 새책 넣기
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
        strcpy(book[li], new[j - 1]); //새책 넣기
        temp = num[li];
        num[li] = 11; //선호도를 바꿔서 새책임을 표시
    }

    //제거한 책의 선호도와 같은 선호도를 가진 다른 책도 제거
    for (int i = 0;i < n;i++)
    {
        if (li == i) //li인덱스에는 새책이 들어갔으므로 이 경우는 건너뜀.
            continue;
        if (temp == num[i])
            book[li][0] = '\0';
    }


    //책 정렬
    qsort(book, n, sizeof(char*), (int(*)(const void*, const void*))compare);
	//책 출력
    for (int i = 0;i < n;i++)
    {
        if (book[i][0] == '\0') continue;
		//책 제목 뒤에 선호도 숫자 제거
        if (book[i][strlen(book[i]) - 1] >= '0' && book[i][strlen(book[i]) - 1] <= '9' && book[i][strlen(book[i]) - 2] <= ' ')
        {
            book[i][strlen(book[i]) - 2] = '\0';
        }
		//책 제목 뒤에 선호도 None 제거
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