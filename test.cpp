#include "cryptomath.h"
#include <iostream>

using namespace std; 

int main()
{
//	//大数定律头文件有错，因为局部的数组不能当作参数传回主函数，可能会丢失 
//	char* s1 = "111111111111111111111111111111";
//	char* s2 = "999999999999999999999999999999";
//	char *modre;
//	modre = (char *)malloc(strlen(s2) + 1);
//	int i;
//	FILE *F1;
//	F1 = fopen("1.txt", "w");
//	fprintf(F1, "+: %s\n", BigAdd(s1, s2));
//	fprintf(F1, "-: %s\n", BigSub(s1, s2));
//	fprintf(F1, "*: %s\n", BigMulti(s1, s2));
//	fprintf(F1, "/: %s %s\n", BigDiv(s1, s2, modre), modre);

//	char *s1="16549831564932154894613";
// 	char *s2="14296162465928358278";
//	char *s3="85245795982789489271";
// 	char *s4=(char*)malloc(5);
// 	char *s5=(char*)malloc(500);
// 	Bigmodexp(s1,s2,s3);
// 	FILE *F1;
// 	F1=fopen("1.txt","w"); 
// 	fprintf(F1,"%s",Expres);

//	if (strcmp("1", checksu("46856248255981")) == 1)
//		printf("TRUE");
//	else
//	{
//		printf("FALSE");
//	}

//	char v[5] = "2";
//	while (strcmp("7", v) != 0) {
//		if (strcmp("1", priroot(v, "7")) == 0) printf("%s ", v);
//		strcpy(v, BigAdd(v, "1"));
//	}

    printf("%s",inver("2244","7121"));

	return 0;
}
