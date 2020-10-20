#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,k,a[200000],sisa;
bool valid;
int main(){
    scanf("%lld %lld",&n,&k);
    sisa = n - ((k)*(k+1))/2;

    if(sisa>=0){
        for(int i=1;i<=k;i++)a[i] = sisa/k ;
        for(int i=k;i>= k - (sisa%k) + 1 ;i--){
            a[i]++;
        }
        for(int i=1;i<=k;i++){
            a[i]+=i;
        }
        ll add=0;
        for(int i=2;i<k;i++){
            if(a[i]>2*a[i-1]){
                add += abs(2*a[i-1] - a[i]);
                a[i]=2*a[i-1];
            }
        }
        a[k]+=add;

        if(k==1){valid=true;}
        else{
            if(a[k]>2*a[k-1]){valid=false;}
            else{valid=true;}
        }
    }
    if(!valid){printf("NO\n");}
    else{
        printf("YES\n");
        for(int i=1;i<=k;i++)printf("%lld ",a[i]);
    }
}
