#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
bool eliminated[1000005];
long long primelist[77778];

void sieve() {
        long long j,x;
        x=1;
        for (long long i=2;i<=1000000;i++)
                eliminated[i]=false;
        //for (int i=0;i<=77778;i++)
        //        primelist[i]=0;
        eliminated[1]=false;
        //eliminated[0]=false;
        for (long long i=2;i<=989999;i++) {
                if (!eliminated[i]) {
                        primelist[x]=i;
                       // printf("prima ke %lld: %lld\n",x,i);
                        x++;
                        j=i;
                        while (i*j<=989999) {
                                eliminated[i*j]=true;
                                j++;
                        }
                        //x++;
                }
        }
}
bool isprime(long long n) {
        bool prima=true;
        int i=2;
        while (i*i<=n) {
                if (n%i==0)
                        prima=false;
                i++;
        }
        if (n<1)
                prima=false;
        return prima;
}

int main() {
        long long t,n,a,b;
        bool jalan;
        sieve();
        scanf("%lld",&t);
        for (int i=0;i<t;i++) {
                scanf("%lld",&n);
                printf("%lld\n",primelist[n]);
        //        jalan=true;
        //        a=1;
        //        b=2;
        //        while (a<n) {
        //                b++;
        //                if (isprime(b))
        //                        a++;
        //        }
        //        printf("%lld\n",b);
        }
        return 0;
}