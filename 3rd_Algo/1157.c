#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    char word[1000001];
    int alphabet_count[26] = {0};  //각 알파벳의 빈도를 저장하는 배열. 알파벳 개수 26개
    int max_count = 0;
    char most_frequent_char = '?';
    int num_max_chars = 0;

    scanf("%s", word);

    // 입력된 단어의 각 문자의 빈도 계산 (대소문자 구분하지 않음)
    for (int i = 0; word[i] != '\0'; i++) {
        if (isalpha(word[i])) //isalpha: 알파벳인지 확인
        {
            int index = tolower(word[i]) - 'a'; //tolower: 소문자로 변환
            alphabet_count[index]++; 
        }
    }

    // 가장 많이 사용된 알파벳 찾기
    for (int i = 0; i < 26; i++) {
        if (alphabet_count[i] > max_count) { //max_count에 현재까지의 빈도 최댓값 저장
            max_count = alphabet_count[i];//max_count를 현재 알파벳의 빈도로 갱신
            most_frequent_char = 'A' + i; //아스키코드를 이용한 변환
            num_max_chars = 1;
        } else if (alphabet_count[i] == max_count) { //현재 인덱스와 max_count가 동일
            num_max_chars++;
        }
    }

    
    if (num_max_chars > 1) {
        printf("?\n"); // 가장 많이 사용된 알파벳이 여러 개인 경우 '?' 출력
    } else {
        printf("%c\n", most_frequent_char); //아니면 가장 많이 사용된 알파벳 출력
    }

    return 0;
}