#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,m,r,share,mn,mx,beg;
int main(){
    scanf("%d %d %d",&n,&m,&r);
    beg = r;
    mn = 2000;
    for(int i=1;i<=n;i++){
        int temp;
        scanf("%d",&temp);
        mn = min(mn,temp);
    }
    share = r/mn;
    r%=mn;
    mx = 0;
    for(int i=1;i<=m;i++){
        int temp;
        scanf("%d",&temp);
        mx = max(mx,temp);
    }
    r+=mx*share;
    r=max(beg,r);
    printf("%d\n",r);
}
