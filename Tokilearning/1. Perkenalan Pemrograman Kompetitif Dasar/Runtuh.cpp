#include <iostream>
#include <cstring>
#include <string>

using namespace std;

string ktk[25];

bool all1(int x,int y) {
	int j=0;
	while (j<y && ktk[x][j]=='1')
		j++;
	if (j>=y) {
		return true;
	}
	else
		return false;
}

void runtuh(int x,int y) {
	int j,k;
	j=x;
	while (j>0) {
		ktk[j]=ktk[j-1];
		j--;
	}
	for (k=0;k<y;k++)
		ktk[0][k]='0';
}
void turun(int x,int y,int z) {
	int j;
	j=x+1;
	while (ktk[j][y]=='0')
		j++;
	swap(ktk[x][y],ktk[j-1][y]);
}

int main() {
	int i,r,c,koor,count;
	bool awal,aman;
	cin >> r >> c;
	for (i=0;i<r;i++)
		cin >> ktk[i];
	aman=false;
	if (r==1) {
		if (all1(r-1,c))
			for (i=0;i<c;i++)
				ktk[0][i]='0';
	}
	else {
	while (!aman) {
	i=r-1;
	awal=false;
	while (i>=0) {
		if (all1(i,c)) {
			runtuh(i,c);
			if (!awal) {
				koor=i;
				awal=true;
			}
		}
		else
			i--;
	}
	if (!awal)
		koor=0;
	while (koor>=0) {
		for (i=0;i<c;i++) {
			if (ktk[koor][i]=='1')
				turun(koor,i,r);
		}
		koor--;
	}
	count=0;
	for (i=r-1;i>=0;i--) {
		if (all1(i,c))
			count++;
	}
	if (count==0)
		aman=true;
	}
	}
	for (i=0;i<r;i++)
		cout << ktk[i] << endl;
}