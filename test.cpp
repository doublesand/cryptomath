#include "cryptomath.h"
#include <iostream>

using namespace std; 

int main()
{
	//��������ͷ�ļ��д���Ϊ�ֲ������鲻�ܵ����������������������ܻᶪʧ 
	char* s1 = "111111111111111111111111111111";
	char* s2 = "999999999999999999999999999999";
	char *modre;
	modre = (char *)malloc(strlen(s2) + 1);
	int i;
	FILE *F1;
	F1 = fopen("1.txt", "w");
	fprintf(F1, "+: %s\n", BigAdd(s1, s2));
	fprintf(F1, "-: %s\n", BigSub(s1, s2));
	fprintf(F1, "*: %s\n", BigMulti(s1, s2));
	fprintf(F1, "/: %s %s\n", BigDiv(s1, s2, modre), modre);
	return 0;
}
