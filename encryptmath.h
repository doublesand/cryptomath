/*
	C++ ʵ�ִ��������ͷ�ļ� 
*/
#include <iostream>
#include <string> 
#include <algorithm>  //�����������һЩС�����õĶ��� 

using namespace std;

string BidAdd(string s1, string s2);
string BidSub(string s1, string s2);

string BidAdd(string s1, string s2){   //�����ӷ�
	string s;
	bool sign = 0;  //����λ�ж� 
	int flag = 0;  //��λ�ж� 
	if(s1[0] == '-' && s2[0] != '-'){
		s1 = s1.substr(1);
		return BidSub(s2,s1);
	} 
	else if(s1[0] != '-' && s2[0] == '-'){
		s2 = s2.substr(1);
		return BidSub(s1, s2);
	}
	else if(s1[0] == '-' && s2[0] == '-' ){
		s1 = s1.substr(1);
		s2 = s2.substr(1);
		flag = 1;
	}
	
	reverse(s1.begin(), s1.end());    //�ַ�����ת 
	reverse(s2.begin(), s2.end());    //�ַ�����ת 
	
	  
	
	for(int i = 0; i < len; i++){
		s[i] = s1[i] - '0' + s2[i] + flag;
		if(s[i] > '9') {
			s[i] = s[i] - 10;
			flag = 1;
		}else{
			flag = 0;
		}
	}
	
	return s;
} 

string BidSub(string s1, string s2){
	string s;
	
	return s;
}
 
