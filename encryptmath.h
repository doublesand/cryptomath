/*
	C++ 实现大数运算的头文件 
*/
#include <iostream>
#include <string> 
#include <algorithm>  //这个库里面有一些小但有用的东西 

using namespace std;

string BidAdd(string s1, string s2);
string BidSub(string s1, string s2);

string BidAdd(string s1, string s2){   //大数加法
	string s;
	bool sign = 0;  //符号位判断 
	int flag = 0;  //进位判断 
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
	
	reverse(s1.begin(), s1.end());    //字符串反转 
	reverse(s2.begin(), s2.end());    //字符串反转 
	
	  
	
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
 
