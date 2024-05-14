#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int NWords(char *str){ //문자열에서 단어의 개수를 계산하는 함수
    int count=0;
    bool inWord=false; //inWord 선언 및 false로 초기화
    /*bool은 C 언어의 표준 라이브러리인 <stdbool.h>에 정의된 불리언 자료형
    true 또는 false 값만을 가짐*/

    for (int i=0; str[i]!='\0'; i++) //문자열을 한 글자씩 이동
    {
        if (str[i]!=' ' && !inWord)//i번째 문자가 공백이 아니고, 단어가 시작하지 않은 상태일 때
        {
            count++; //카운트업
            inWord=true; //단어가 시작됨을 알림
        }

        else if (str[i] == ' ') //i번째 문자가 공백일 때
        {
            inWord=false;
        }
    }return count;
}

int main(){
    char str[1000001]; //문자열 받을 변수 및 크기 정의
    fgets(str, sizeof(str), stdin); 

    /*fgets: 문자열 입력 받을 때 쓰는 함수
    기본 형식: char *fgets(char *str, int num, FILE *stream);
    엔터를 만날 때까지 문자 입력 받음
    stream은 입력 소스를 나타내는 파일 포인터. 주로 stdin을 사용함.*/

    if (str[strlen(str)-1]=='\n') 
        str[strlen(str)-1]= '\0';
        /*문자를 입력할 때 마지막에 엔터를 눌러서 입력했다면,
        그 자리에 \0(null)을 넣어서 공백을 하나 더 세지 않도록 함. */
        printf("%d\n", NWords(str));
        return 0;
}