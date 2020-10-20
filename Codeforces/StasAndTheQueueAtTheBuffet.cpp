#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
pair <ll,ll> p[200000];
pair <ll,ll> s[200000];
int n;
ll ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        p[i]=make_pair(a,b);
        s[i]=make_pair(a-b,i);
    }
    sort(s+1,s+1+n,greater< pair<ll,ll> > ());
    for(int i=1;i<=n;i++){
        int idx = s[i].second;
        ans += p[idx].first * (i-1) + p[idx].second * (n-i);
    }
    printf("%lld\n",ans);
}
