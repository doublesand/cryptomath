#include "encryptmath.h"


int main() { 
	string s1 = "111111111111111111111111111111";
	string s2 = "999999999999999999999999999999";
	s1 = "dengwenfeng";
	reverse(s1.begin(),s1.end());
	int len = max(s1.length(),s2.length());
	cout<<len<<endl; 
	return 0;
}
