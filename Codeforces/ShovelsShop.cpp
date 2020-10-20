#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,m,k,a[300000];
pair<int,int> offer[300000];
int sum[300000];
int sr (int left, int right){
    if(right<left)return 0;
    return sum[right]-sum[left-1];
}
int buy (int idx, int buy, int free){
    return sr (idx+free,idx+buy-1);
}
int memo[3000];
bool calc[3000];
int dp (int x){
    if(x>=k){return 0;}
    else if(calc[x])return memo[x];
    else{
        int mn = INT_MAX;
        for(int i=1;i<=m;i++){
            if(x+offer[i].first>k)break;
            mn = min (mn, buy(x+1,offer[i].first,offer[i].second) + dp(x+offer[i].first));
        }
        calc[x]=true;
        memo[x]=mn;
        return mn;
    }
}
int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=m;i++){
        int x,y;scanf("%d %d",&x,&y);
        offer[i]=make_pair(x,y);
    }
    m++;offer[m]=make_pair(1,0);
    sort(offer+1,offer+1+m);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    printf("%d\n",dp(0));
}
