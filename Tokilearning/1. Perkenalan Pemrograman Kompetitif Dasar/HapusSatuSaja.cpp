#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

string kurang(string s,int x) {
        int y=x,len=s.size();
        while (y<len) {
                s[y]=s[y+1];
                y++;
        }
        return s;
}
int main() {
	int len1,len2,i,j,hur1[26],hur2[26],temp,count;
	bool iya;
	for (int i=0;i<26;i++) {
		hur1[i]=0;
		hur2[i]=0;
	}
	string a,b,aa;
	cin >> a;
	cin >> b;
	len1=a.size();
	len2=b.size();
	if ((len1-len2>1) || (len1-len2<1)) {
		cout << "Wah, tidak bisa :(\n";
	}
	else  {
	        bool sama1=false,sama2;
	        int i=0;
                while (!sama1 && i<len1) {
                        aa=kurang(a,i);
                        //cout << aa << endl;
                        //cout << aa.length() << endl;
                        for (int j=0;j<len2;j++) {
                                sama2=true;
                                //cout << aa[j] << endl;
                                //cout << b[j] << endl; 
                                if (aa[j]!=b[j])
                                        sama2=false;
                        }
                        if (sama2)
                                sama1=true;
                        i++;
                        //cout << kurang(a,i) << endl;
                        //cout << b << endl;
                        //cout << "===\n";
                }
		if (sama1) 
		        cout << "Tentu saja bisa!\n";
		else
		        cout << "Wah, tidak bisa :(\n";
	}
	return 0;
}