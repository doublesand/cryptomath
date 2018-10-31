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
