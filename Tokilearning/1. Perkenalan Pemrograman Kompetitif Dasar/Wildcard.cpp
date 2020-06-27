#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
 
using namespace std;
 
string ast,hur[105],s,s1,s2,ss,sss;
int len,len1,len2,stat,pos,n,i,j;
 
void pecah() {
	if (stat==1) {
		s2=ast.substr(1,len-1);
		pos=0;
	}
	else if (stat==2) {
		int x=1,y=len-2;
		while (ast[x]!='*' && ast[y]!='*') {
			x++;
			y--;
		}
		if (ast[x]=='*')
			pos=x;
		else if (ast[y]=='*')
			pos=y;
		s1=ast.substr(0,pos);
		s2=ast.substr(pos+1,len-pos-1);
	}
	else {
		s1=ast.substr(0,len-1);
		pos=len-1;
	}
}
 
int cariposisi() {
	len=ast.length();
	if (ast[0]=='*')
		return 1;
	else if (ast[len-1]=='*')
		return 3;
	else
		return 2;
}
 
bool ada(int w) {
	int x,y;
	s=hur[w];
	len=s.length();
	bool kena=false;
	if (stat==1) {
		len2=s2.length();
		if (len>=len2) {
		x=len-len2;
		ss=s.substr(x,len2);
		if (s2==ss)
			kena=true;
		}
		}
	else if (stat==2) {
		len1=s1.length();
		len2=s2.length();
		if ((len>=len1) && (len>=len2)) {
		ss=s.substr(0,len1);
		sss=s.substr(len-len2,len2);
		if (((ss==s1) && (sss==s2)) && (len1-1<len-len2))
			kena=true;
		}
	}
 
	else if (stat==3) {
		len2=s1.length();
		if (len>=len2) {
		ss=s.substr(0,len2);
		if (s1==ss)
			kena=true;
	}
	}
	return kena;
}
 
int main() {
	cin >> ast;
	cin >> n;
	for (i=0;i<n;i++)
		cin >> hur[i];
	if (ast=="*") {
		for (i=0;i<n;i++)
			cout << hur[i] << endl;
	}
	else {
		stat=cariposisi();
		pecah();
		for (i=0;i<n;i++) {
			if (ada(i))
				cout << hur[i] << endl;
		}
	}
}