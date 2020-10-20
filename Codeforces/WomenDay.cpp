#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,k,m[200];
int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        int temp;
        scanf("%d",&temp);
        m[temp%k]++;
    }
    int ans = 0;

    for(int i=0;i<k;i++){
        int sisa;
        if(i==0){sisa=0;}
        else{sisa=k-i;}
        if(sisa==i){ans+=m[i]/2;m[i]/=2;}
        else{
            int p = min(m[i],m[sisa]);
            ans += p;
            m[i]-=p;
            m[sisa]-=p;
        }
    }
    cout<<ans*2<<endl;
}

