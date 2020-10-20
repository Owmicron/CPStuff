#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,ans;
int main(){
    scanf("%d",&n);
    for(int i=3;i<=n;i++){
        ans+=i*(i-1);
    }
    printf("%d\n",ans);
}
