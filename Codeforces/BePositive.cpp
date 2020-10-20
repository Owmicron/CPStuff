#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,d,po,ne;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int temp;
        scanf("%d",&temp);
        if(temp>0){po++;}
        else if(temp<0){ne++;}
    }
    int need;
    if(n%2==0)need=n/2;
    else{need=(n/2)+1;}

    if(po>=need){d=1;}
    else{
        if(ne>=need){d=-1;}
        else{
            d=0;
        }
    }
    printf("%d\n",d);
}
