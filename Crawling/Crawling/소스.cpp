#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE *fp1;
	FILE *fp2;

	fp1 = fopen("123456.txt", "rt");
	fp2 = fopen("output.txt", "w");
	char buf[1024];
		//= ">�� </span> <span style=color:black>����Ƽ��</spa	>���ﰭ��, �λ꼭����ġ, �����ͺм�, ����Ŭ, �ڹ�������, ��Ʈ��ũ ����, �����Ⱓ, ���Ϲ��ī������, �����������񹫷ᰭ��< / span>(���� ������ �������)< / span>< / s >�� ����Ƽ��</spa>���ﰭ��, �λ꼭����ġ, �����ͺм�, ����Ŭ, �ڹ�������, ��Ʈ��ũ ����, �����Ⱓ, ���Ϲ��ī������, �����������񹫷ᰭ��< / span>(���� ������ �������)< / span>< / s";
	char buf2[1024] = ">�� ����Ƽ��</spa>���ﰭ��, �λ꼭����ġ, �����ͺм�, ����Ŭ, �ڹ�������, ��Ʈ��ũ ����, �����Ⱓ, ���Ϲ��ī������, �����������񹫷ᰭ��< / span>(���� ������ �������)< / span>< / s>�� ����Ƽ��</spa>���ﰭ��, �λ꼭����ġ, �����ͺм�, ����Ŭ, �ڹ�������, ��Ʈ��ũ ����, �����Ⱓ, ���Ϲ��ī������, �����������񹫷ᰭ��< / span>(���� ������ �������)< / span>< / ";

	char *tok=" ";

	/*while (!feof(fp1)) {
		fgets(buf, 1024, fp1);
		fputs(buf, fp2);
	}*/
	

	while (!feof(fp1)) {
		printf("ASDFASDFASDF\n");
		fgets(buf, 1024, fp1);
		tok = strtok(buf, "��");	

		tok = strtok(NULL, "<");
		if (tok == NULL) {
		continue;
		}

		printf("first %s\n", tok);
	
		if (tok[0]=='?') {
			printf("����\n");
			strtok(NULL, "=");
			strtok(NULL, ">");
			tok = strtok(NULL, "<");
		}
		printf("��ȣ : %s\n", tok);
		fputs(tok, fp2);
		strtok(NULL, "(");
		tok = strtok(NULL, ")");
		printf("��ġ : %s\n", tok);
		fputs(tok, fp2);

		tok = strtok(NULL, "��");


	}
	
		/*tok = strtok(buf2, "��");
		tok=strtok(NULL, "<");
		printf("first %s\n", tok);


		if (tok[0] == '<') {
			printf("span ����\n");
			strtok(buf2, "span style");
			strtok(buf2, ">");
		}
		printf("��ȣ : %s\n", tok);
		strtok(NULL, "(");
		tok = strtok(NULL, ")");

		printf("��ġ : %s\n", tok);*/

	
	

	return 0;
}