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
	char buf3[1024] = "rksk ���˴޾� ��������ä���(asd)���Ӥ�";
	char buf4[1024] = ">�� ����Ƽ��</spa>���ﰭ��";
	char *ntok=" ";
	char *atok = " ";
	char *tok=" ";

	/*while (!feof(fp1)) {
		fgets(buf, 1024, fp1);
		fputs(buf, fp2);
	}*/

	//fgets(buf3, 1024, fp1);

	//tok = strtok(buf4, "��");
	//tok = strtok(NULL, "<");
	//tok = strtok(buf4, "(");
	//tok = strtok(NULL, ")");


	/*if (tok == NULL) {
		printf("Aasdafa");
	}
	else
		printf(tok);*/

	
	
	

	while (!feof(fp1)) {
		fgets(buf, 1024, fp1);
		fgets(buf2, 1024, fp1);

		ntok = strtok(buf, "��");
		ntok = strtok(NULL, "<");
		
		if(ntok==NULL){
			atok = strtok(buf, "(");
			atok = strtok(NULL, ")");

			if(atok!=NULL)
				printf("���뿭 : %s\n",atok);
		}
		else {
			printf("��ȣ : %s\n", ntok);
		}
	}
	
		/*if (tok[0]=='?') {
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
		

		tok = strtok(NULL, "��");*/


	
	
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