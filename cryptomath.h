#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#define MAXLEN 1000

int   checkbs(char *s1,char *s2);  //1为前者大，2为后者大，0为相等 
char* retback(char *s1);        //字符串顺序颠倒 
char* BigAdd(char *s1,char *s2);
char* BigSub(char *s1,char *s2);
char* BigMulti(char *sv1,char *sv2);
char* BigDiv(char *sv1,char *sv2,char *modre);//除数，被除数，余数

char * Bigmodexp(char *sv1,char *sv2,char *s3);//Expres = sv1 ^sv2 mod s3

char * checksu(char *s1);//”1“为是素数，"0"为不是

char * priroot(char *s1,char *s2);//”1“为是原根，"0"为不是 s1 为s2原根

char * gcdch(char * s1,char *s2);//最大公约数 
char * chgcoe(char *s1,char *s2);//欧几里得除法单步 
char * Euccoe(char *s1,char *s2);//广义欧几里得除法 s2a * s1 + s2b * s2 = 1 
char * inver(char *s1,char *s2);//返回0为没有逆元 ，否则返回s1 mod s2的逆元

char* retback(char *s1) {   
	//此函数用于将字符串顺序颠倒 
	char sret[MAXLEN];
	int i = 0;
	for (; i < strlen(s1); i++)
		sret[i] = s1[strlen(s1) - i - 1];  
	sret[i] = '\0';
	return sret;
}

char* BigAdd(char *sv1, char *sv2) {
	//大数加法 
	char sadd[MAXLEN];//结果字符串 
	char s1[MAXLEN], s2[MAXLEN];
	strcpy(s1, sv1);
	strcpy(s2, sv2);
	int Flag = 0, su = 0;//位标志符,正负控制符，1为负 
	int len1 = 0, len2 = 0, len3 = 0, i = 0;
	len1 = strlen(s1);
	len2 = strlen(s2);
	len3 = len1;
	if (len2 > len3)
		len3 = len2;
	//sadd = (char *)malloc(len3+1);
	len3 = 0;
	if (s1[0] == '-' && s2[0] != '-') {
		for (i = 0; i<len1; i++) s1[i] = s1[i + 1];
		return BigSub(s2, s1);
	}
	else if (s1[0] != '-' && s2[0] == '-') {
		for (i = 0; i<len2; i++) s2[i] = s2[i + 1];
		return BigSub(s1, s2);
	}
	else if (s1[0] == '-' && s2[0] == '-') {
		for (i = 0; i<len1; i++) s1[i] = s1[i + 1];
		for (i = 0; i<len2; i++) s2[i] = s2[i + 1];
		len1--;
		len2--;
		su = 1;
	}
	while (1)
	{
		len1 -= 1;
		len2 -= 1;
		if (len1 < 0)
		{
			while (len2 >= 0) {
				sadd[len3] = s2[len2] + Flag;
				Flag = 0;
				if (sadd[len3] > '9')
				{
					sadd[len3] -= 10;
					Flag = 1;
				}
				len3++;
				len2 -= 1;
			}
			break;
		}
		else if (len2 < 0)
		{
			while (len1 >= 0) {
				sadd[len3] = s1[len1] + Flag;
				Flag = 0;
				if (sadd[len3] > '9')
				{
					sadd[len3] -= 10;
					Flag = 1;
				}
				len3++;
				len1 -= 1;
			}
			break;
		}
		else
		{
			sadd[len3] = s1[len1] - '0' + s2[len2] + Flag;
			Flag = 0;
			if (sadd[len3] > '9')
			{
				sadd[len3] -= 10;
				Flag = 1;
			}
			len3++;
		}
	}
	if (Flag == 1)
	{
		sadd[len3] = '1';
		len3++;
	}
	sadd[len3] = '\0';
	if (su == 1) {
		sadd[len3] = '-';
		sadd[len3 + 1] = '\0';
	}
	return retback(sadd);
}

int checkbs(char *s1, char *s2)
{
	//1为前者大，2为后者大，0为相等 
	int len = 0;
	if (strlen(s1) > strlen(s2))
		return 1;
	else if (strlen(s1)<strlen(s2))
		return 2;
	else
	{
		while (len<strlen(s1))
		{
			if (s1[len] > s2[len])
				return 1;
			else if (s1[len]<s2[len])
				return 2;
			len++;
		}
		return 0;
	}
}

char* BigSub(char *sv1, char *sv2)
{
	char ssub[MAXLEN];//结果字符串 
	char s1[MAXLEN], s2[MAXLEN];
	strcpy(s1, sv1);
	strcpy(s2, sv2);
	int Flag = 0, su = 0;//借位标志符，正负标志符 
	int len1 = 0, len2 = 0, len3 = 0, i = 0;
	len1 = strlen(s1);
	len2 = strlen(s2);
	len3 = len1;
	//ssub = (char *)malloc(len3+1);
	if (s1[0] == '-' && s2[0] == '-') {
		for (i = 0; i<len1; i++) s1[i] = s1[i + 1];
		for (i = 0; i<len2; i++) s2[i] = s2[i + 1];
		return BigSub(s2, s1);
	}
	else if (s1[0] != '-' && s2[0] == '-') {
		for (i = 0; i<len2; i++) s2[i] = s2[i + 1];
		return BigAdd(s1, s2);
	}
	else if (s1[0] == '-' && s2[0] != '-') {
		for (i = 0; i<len1; i++) s1[i] = s1[i + 1];
		strcpy(ssub, retback(BigAdd(s1, s2)));
		len3 = strlen(ssub);
		ssub[len3] = '-';
		ssub[len3 + 1] = '\0';
		return retback(ssub);
	}
	if (checkbs(s1, s2) == 0)
		return "0";
	else if (checkbs(s1, s2) == 2)
	{
		strcpy(ssub, retback(BigSub(s2, s1)));
		strcat(ssub, "-");
		return retback(ssub);
	}
	len3 = 0;
	while (1)
	{
		len1 -= 1;
		len2 -= 1;
		if (len2 < 0)
		{
			while (len1 >= 0)
			{
				ssub[len3] = s1[len1] - Flag;
				Flag = 0;
				if (ssub[len3]<'0')
				{
					ssub[len3] += 10;
					Flag = 1;
				}
				len3++;
				len1 -= 1;
			}
			break;
		}
		else
		{
			ssub[len3] = s1[len1] - s2[len2] - Flag + '0';
			Flag = 0;
			if (ssub[len3]<'0')
			{
				ssub[len3] += 10;
				Flag = 1;
			}
			len3++;
		}
	}
	while (ssub[len3 - 1] == '0')
		len3--;
	if (su == 1)
	{
		ssub[len3] = '-';
		len3++;
	}
	ssub[len3] = '\0';
	return retback(ssub);
}

char* BigMulti(char *sv1, char *sv2)
{
	char smulti[MAXLEN];          //结果字符串 
	char s1[MAXLEN], s2[MAXLEN];
	strcpy(s1, sv1);
	strcpy(s2, sv2);
	int Flag = 0, su = 0; //进位标志符
	int len1 = 0, len2 = 0, len3 = 0;
	int i = 0;
	len1 = strlen(s1);
	len2 = strlen(s2);
	//smulti = (char *)malloc(len1+len2+1);
	len3 = 0;
	if (strcmp(s1, "0") == 0 || strcmp(s2, "0") == 0) return "0"; //其中一个乘数为0 

	if (s1[0] == '-' && s2[0] == '-') {
		for (i = 0; i<len1; i++) s1[i] = s1[i + 1];
		for (i = 0; i<len2; i++) s2[i] = s2[i + 1];
		len1--;
		len2--;
		return BigMulti(s1, s2);  //一个简单的递归，太精妙了 
	}
	else if (s1[0] != '-' && s2[0] == '-') {
		for (i = 0; i<len2; i++) s2[i] = s2[i + 1];
		su = 1;                     //符号位吧 
		len2--;
	}
	else if (s1[0] == '-' && s2[0] != '-') {
		for (i = 0; i<len1; i++) s1[i] = s1[i + 1];
		len1--;
		su = 1;
	}
	i = 0;
	//开始处理 
	while (1)
	{
		len1 = strlen(s1) - len3 - 1; 
		len2 = strlen(s2) - 1;
		if (len1<0)
		{
			len2 -= (0 - len1);
			len1 = 0;
			if (len2<0)
				break;
		}
		while (1)
		{
			if (len1 >= strlen(s1) || len2<0) break;
			i += (s1[len1] - '0')*(s2[len2] - '0');
			len1++;
			len2--;
		}
		i += Flag;
		Flag = i / 10;
		i = i % 10;
		smulti[len3] = '0' + i;
		len3++;
		i = 0;
	}
	if (Flag > 0)
	{
		//注意最高位是否有进位 
		smulti[len3] = '0' + Flag;
		len3++;
	}
	smulti[len3] = '\0';
	if (su == 1) {
		smulti[len3] = '-';
		smulti[len3 + 1] = '\0';
	}
	return retback(smulti);
}



char* BigDiv(char *sv1, char *sv2, char *modre)//被除数，除数，余数 
{
	char sdiv[MAXLEN], s1[MAXLEN], s2[MAXLEN];
	int Flag = 0;//进位标志符
	int len1 = 0, len2 = 0, len3 = 0;
	len1 = strlen(sv1);
	len2 = strlen(sv2);
	strcpy(s1, sv1);
	strcpy(s2, sv2);
	len3 = 0;
	sdiv[len3] = '0';
	if (checkbs(s1, s2) == 2)
	{
		strcpy(modre, s1);
		return "0";
	}
	while (1)
	{
		if (checkbs(s1, s2) == 2)
			break;
		else
		{
			len2 = strlen(s2);
			strcat(s2, "0");
		}
	}
	len2 = strlen(s2);
	if (s2[len2 - 1] == '0'&&len2 >= strlen(sv2))
		s2[len2 - 1] = '\0';
	while (1)
	{
		if (checkbs(s1, s2) == 2) {
			len2 = strlen(s2);
			if (s2[len2 - 1] == '0'&&len2 > strlen(sv2))
				s2[len2 - 1] = '\0';
			else break;
			len3++;
			sdiv[len3] = '0';
			sdiv[len3 + 1] = '\0';
		}
		else {
			strcpy(s1, BigSub(s1, s2));
			sdiv[len3] += 1;
		}
	}
	while (1) {
		len2 = strlen(s2);
		if (s2[len2 - 1] == '0'&&len2 >= strlen(sv2))
		{
			s2[len2 - 1] = '\0';
			sdiv[len3] = '0';
			sdiv[len3 + 1] = '\0';
		}
		else break;
	}
	sdiv[len3 + 1] = '\0';
	strcpy(modre, s1);
	return sdiv;
}

char Expres[MAXLEN];
char * Bigmodexp(char *sv1, char *sv2, char *s3)
{
	//s1底数，s2指数，s3模数
	char sexp1[MAXLEN], sexp2[MAXLEN], smod[MAXLEN];
	char s1[MAXLEN], s2[MAXLEN];
	strcpy(s2, sv2);
	BigDiv(sv1, s3, s1);
	if (strcmp(s2, "1") == 0)
		strcpy(Expres, s1);
	else if ((s2[strlen(s2) - 1] - '0') % 2 == 1)
	{
		s2[strlen(s2) - 1] -= 1;
		strcpy(sexp2, BigDiv(s2, "2", smod));
		Bigmodexp(s1, sexp2, s3);
		strcpy(sexp1, Expres);
		BigDiv(BigMulti(sexp1, sexp1), s3, sexp2);
		BigDiv(BigMulti(sexp2, s1), s3, sexp1);
		strcpy(Expres, sexp1);
	}
	else
	{
		strcpy(sexp2, BigDiv(s2, "2", smod));
		Bigmodexp(s1, sexp2, s3);
		strcpy(sexp1, Expres);
		BigDiv(BigMulti(sexp1, sexp1), s3, sexp2);
		strcpy(Expres, sexp2);
	}
	return "0";
}

char * checksu(char *s1)
{
	//”1“为是素数，"0"为不是 
	char modre[MAXLEN];
	char factor[10][2] = { "2","3","5","7" };
	char MRfac[10][10] = { "2","3","7","61","24251" };
	char MR_sec[10];//MR测试的强测试 
	int i = 0;
	for (; i<4; i++) {
		BigDiv(s1, factor[i], modre);
		if (strcmp(modre, "0") == 0)
		{
			return "0";
		}
	}
	for (i = 0; i<5; i++) {
		strcpy(MR_sec, BigSub(s1, "1"));
		Bigmodexp(MRfac[i], MR_sec, s1);
		if (strcmp(Expres, "1") != 0)
		{
			return "0";
		}
		else {
			while ((MR_sec[strlen(MR_sec) - 1] - '0') % 2 == 0 && checkbs(MR_sec, "2") == 1) {
				strcpy(MR_sec, BigDiv(MR_sec, "2", modre));
				Bigmodexp(MRfac[i], MR_sec, s1);
				if (strcmp(Expres, "1") != 0 && strcmp(Expres, BigSub(s1, "1")) != 0)
				{
					return "0";
				}
				else if (strcmp(Expres, BigSub(s1, "1")) == 0) break;
			}
		}
	}
	return "1";
}

char * priroot(char *s1, char *s2)
{
	//”1“为是原根，"0"为不是 
	char exp[1000], modre[1000];
	char sv2[1000], svfac1[1000], svfac2[1000];
	strcpy(sv2, BigSub(s2, "1"));
	if (checkbs(s1, s2) != 2)
		return "Error";
	strcpy(svfac1, "2");
	strcpy(svfac2, BigDiv(sv2, "2", modre));
	Bigmodexp(s1, svfac1, s2);
	if (strcmp(Expres, "1") == 0) return "0";
	Bigmodexp(s1, svfac2, s2);
	if (strcmp(Expres, "1") == 0) return "0";
	strcpy(svfac1, "3");
	while (strlen(svfac1) <= (strlen(s2) / 2 + 1))
	{
		strcmp(svfac2, BigDiv(sv2, svfac1, modre));
		if (strcmp(modre, "0") == 0)
		{
			Bigmodexp(s1, svfac1, s2);
			if (strcmp(Expres, "1") == 0) return "0";
			Bigmodexp(s1, svfac2, s2);
			if (strcmp(Expres, "1") == 0) return "0";
		}
		strcpy(svfac1, BigAdd(svfac1, "2"));
	}
	return "1";
}

char * gcdch(char * s1, char *s2) {
	int len;
	len = strlen(s1);
	if (len<strlen(s2))
		len = strlen(s2);
	char gcdchar1[MAXLEN];
	char gcdchar2[MAXLEN];
	char stmp[MAXLEN];
	strcpy(gcdchar1, s1);
	strcpy(gcdchar2, s2);
	while (1)
	{
		if (strcmp(gcdchar1, "1") == 0 || strcmp(gcdchar2, "1") == 0) return "1";
		else if (strcmp(gcdchar2, "0") == 0) return gcdchar1;
		else if (strcmp(gcdchar1, "0") == 0) return gcdchar2;
		else {
			if (checkbs(gcdchar1, gcdchar2) == 0) {
				return gcdchar1;
			}
			else if (checkbs(gcdchar1, gcdchar2) == 1)
			{
				BigDiv(gcdchar1, gcdchar2, stmp);
				strcpy(gcdchar1, stmp);
			}
			else
			{
				BigDiv(gcdchar2, gcdchar1, stmp);
				strcpy(gcdchar2, stmp);
			}
		}
	}
}

char s1a[1000] = "1", s1b[1000] = "0";
char s2a[1000] = "0", s2b[1000] = "1";//小的那个数由a，b表示的系数 
char * chgcoe(char *s1, char *s2) {
	char modre[1000];
	char num[1000];
	char stpa[1000], stpb[1000];
	strcpy(stpa, s2a);
	strcpy(stpb, s2b);
	strcpy(num, BigDiv(s1, s2, modre));
	strcpy(s2a, BigSub(s1a, BigMulti(stpa, num)));
	strcpy(s2b, BigSub(s1b, BigMulti(stpb, num)));
	strcpy(s1a, stpa);
	strcpy(s1b, stpb);
	return modre;
}
char * Euccoe(char *s1, char *s2)
{
	if (checkbs(s1, s2) == "2") {
		Euccoe(s2, s1);
		return "0";
	}
	char sv1[MAXLEN], sv2[MAXLEN], small[MAXLEN];
	strcpy(sv1, s1);
	strcpy(sv2, s2);
	while (1) {
		strcpy(small, chgcoe(sv1, sv2));
		printf("%s ab%s %s\n", small, s2a, s2b);
		if (strcmp("1", small) == 0) return "0";
		strcpy(sv1, sv2);
		strcpy(sv2, small);
	}
}

char * inver(char *s1, char *s2) {
	//返回0为没有逆元 
	char inver[MAXLEN], sv2[MAXLEN];
	char res[MAXLEN], isv2[MAXLEN], modre[MAXLEN];
	strcpy(sv2, BigSub(s2, "2"));
	strcpy(res, gcdch(s1, s2));
	if (strcmp(res, "1") != 0) return "0";
	Bigmodexp(s1, sv2, s2);
	//strcpy(sv2,BigAdd(s2,"3"));
	strcpy(inver, Expres);
	strcpy(isv2, "2");
	if (strcmp("1", checksu(s2)) == 0)
	{
		return inver;
	}
	Euccoe(s1, s2);
	if (s2a[0] == '-') return BigAdd(s2a, s2);
	else return s2a;
}
