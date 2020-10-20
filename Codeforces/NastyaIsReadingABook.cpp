#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,l[200],r[200],k,ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&l[i],&r[i]);
    }
    scanf("%d",&k);
    for(int i=1;i<=n;i++){
        if(k>r[i])ans++;
        else break;
    }
    printf("%d\n",n-ans);
}
