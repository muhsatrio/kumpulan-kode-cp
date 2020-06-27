#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

int fpb(int a,int b) {
        if (b==0)
                return a;
        else
                return fpb(b,a%b);
}

int kpk(int a,int b) {
        return (a*b)/fpb(a,b);
}

int main() {
        int arr[25],n,hasil;
        scanf("%d",&n);
        for (int i=0;i<n;i++)
                scanf("%d",&arr[i]);
        hasil=kpk(arr[0],arr[1]);
        int i=2;
        while (i<n) {
                hasil=kpk(hasil,arr[i]);
                i++;
        }
        printf("%d\n",hasil);
        return 0;
}