#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE *fp1;
	FILE *fp2;

	fp1 = fopen("123456.txt", "rt");
	fp2 = fopen("output.txt", "w");
	char buf[1024];
		//= ">♠ </span> <span style=color:black>아이티윌</spa	>서울강남, 부산서면위치, 빅데이터분석, 오라클, 자바웹개발, 네트워크 보안, 국가기간, 내일배움카드제도, 정부지원국비무료강좌< / span>(서울 강남구 테헤란로)< / span>< / s >♠ 아이티윌</spa>서울강남, 부산서면위치, 빅데이터분석, 오라클, 자바웹개발, 네트워크 보안, 국가기간, 내일배움카드제도, 정부지원국비무료강좌< / span>(서울 강남구 테헤란로)< / span>< / s";
	char buf2[1024] = ">♠ 아이티윌</spa>서울강남, 부산서면위치, 빅데이터분석, 오라클, 자바웹개발, 네트워크 보안, 국가기간, 내일배움카드제도, 정부지원국비무료강좌< / span>(서울 강남구 테헤란로)< / span>< / s>♠ 아이티윌</spa>서울강남, 부산서면위치, 빅데이터분석, 오라클, 자바웹개발, 네트워크 보안, 국가기간, 내일배움카드제도, 정부지원국비무료강좌< / span>(서울 강남구 테헤란로)< / span>< / ";

	char *tok=" ";

	/*while (!feof(fp1)) {
		fgets(buf, 1024, fp1);
		fputs(buf, fp2);
	}*/
	

	while (!feof(fp1)) {
		printf("ASDFASDFASDF\n");
		fgets(buf, 1024, fp1);
		tok = strtok(buf, "♠");	

		tok = strtok(NULL, "<");
		if (tok == NULL) {
		continue;
		}

		printf("first %s\n", tok);
	
		if (tok[0]=='?') {
			printf("들어옴\n");
			strtok(NULL, "=");
			strtok(NULL, ">");
			tok = strtok(NULL, "<");
		}
		printf("상호 : %s\n", tok);
		fputs(tok, fp2);
		strtok(NULL, "(");
		tok = strtok(NULL, ")");
		printf("위치 : %s\n", tok);
		fputs(tok, fp2);

		tok = strtok(NULL, "♠");


	}
	
		/*tok = strtok(buf2, "♠");
		tok=strtok(NULL, "<");
		printf("first %s\n", tok);


		if (tok[0] == '<') {
			printf("span 들어옴\n");
			strtok(buf2, "span style");
			strtok(buf2, ">");
		}
		printf("상호 : %s\n", tok);
		strtok(NULL, "(");
		tok = strtok(NULL, ")");

		printf("위치 : %s\n", tok);*/

	
	

	return 0;
}