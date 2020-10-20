#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,mx[60],h,m,ans;
int main(){
    scanf("%d %d %d",&n,&h,&m);
    for(int i=1;i<=n;i++)mx[i]=h;
    for(int i=1;i<=m;i++){
        int l,r,x;
        scanf("%d %d %d",&l,&r,&x);
        for(int j=l;j<=r;j++){
            mx[j] = min(mx[j],x);
        }
    }
    for(int i=1;i<=n;i++){
        ans += mx[i]*mx[i];
    }
    printf("%d\n",ans);
}
