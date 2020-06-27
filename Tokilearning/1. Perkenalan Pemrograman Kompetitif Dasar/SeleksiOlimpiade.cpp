#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct dataa {
	string nama[85];
	int p1[85];
	int p2[85];
	int p3[85];
};

dataa peserta;

void tukar(int a,int b) {
	swap(peserta.nama[a],peserta.nama[b]);
	swap(peserta.p1[a],peserta.p1[b]);
	swap(peserta.p2[a],peserta.p2[b]);
	swap(peserta.p3[a],peserta.p3[b]);
}

void urut(int x) {
	for (int i=1;i<=x;i++) {
		for (int j=0;j<i;j++) {
			if (peserta.p3[j]<peserta.p3[i]) {
				//cout << "tukar3" << j << ' ' << i << endl;
				tukar(j,i);
			}
			else if (peserta.p3[j]==peserta.p3[i]) {
				if (peserta.p2[j]<peserta.p2[i]) {
					//cout << "tukar2" << j << ' ' << i << endl;
					tukar(j,i);
				}
				else if (peserta.p2[j]==peserta.p2[i]) {
					if (peserta.p1[j]<peserta.p1[i]) {
						//cout << "tukar1" << j << ' ' << i << endl;
						tukar(j,i);
					}
				}
			}
		}
	}
}

int cari(int x,string s) {
	int y=0;
	while (y<=x && peserta.nama[y]!=s) {
			y++;
			//cout << y << endl;
		}
	return y;
}

int main() {
	int t,n,m,ind;
	string ss;
	cin >> t;
	for (int i=0;i<t;i++) {
		cin >> n >> m;
		cin >> ss;
		for (int j=0;j<n;j++) {
			cin >> peserta.nama[j] >> peserta.p1[j] >> peserta.p2[j] >> peserta.p3[j];
		}
		urut(n-1);
		//for (int j=0;j<n;j++) {
			//cout << peserta.nama[j] << ' ' << peserta.p1[j] <<' '<< peserta.p2[j] <<' '<< peserta.p3[j] << endl;
		//}
		//cout << "sudah\n" << endl;
		ind=cari(m-1,ss);
		if (ind>m-1)
			cout << "TIDAK\n";
		else
			cout << "YA\n";
	}
}