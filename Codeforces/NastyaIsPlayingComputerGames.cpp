#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,k,ans;
int main(){
    scanf("%d %d",&n,&k);
    ans = n + (n-1) + min (k-1,n-k) + n+1;
    printf("%d\n",ans);
}
