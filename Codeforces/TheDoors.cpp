#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n;
int z,o,a[300000];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=n;i>=1;i--){
        if(a[i]==1){o=i;break;}
    }
    for(int i=n;i>=1;i--){
        if(a[i]==0){z=i;break;}
    }
    printf("%d\n",min(o,z));
}
