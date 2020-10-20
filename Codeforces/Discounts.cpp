#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll sum,a[400000];
int n,m;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    sort(a+1,a+1+n,greater<int>());
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        int q;
        scanf("%d",&q);
        printf("%lld\n",sum-a[q]);
    }
}
