#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,mx,day;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int a;
        scanf("%d",&a);
        mx = max(mx,a);
        if(i>=mx){day++;}
    }
    printf("%d\n",day);
}
