#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

long long fpb(long long x,long long y) {
        if (y==0)
                return x;
        else
                return fpb(y,x%y);
}

long long kpk(long long x,long long y) {
        long long temp1,temp2;
        temp1=x;
        temp2=y/fpb(x,y);
        return temp1*temp2;
}


int main() {
        long long a,b,c,d,atas,bawah,pembagi;
        scanf("%lld %lld",&a,&b);
        scanf("%lld %lld",&c,&d);
                if (b!=d) {        
                        bawah=kpk(b,d);
                        a=(bawah/b)*a;
                        c=(bawah/d)*c;
                        atas=a+c;
                }
                else {
                        atas=a+c;
                        bawah=b;
                }  
                //atas=a+c;
                pembagi=fpb(atas,bawah);
                while (pembagi>1) {
                        atas/=pembagi;
                        bawah/=pembagi;
                        pembagi=fpb(atas,bawah);
                }
        printf("%lld %lld\n",atas,bawah);
        
        return 0;
}