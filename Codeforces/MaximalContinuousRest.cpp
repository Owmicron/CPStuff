#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,w;
int a[300000];
int main(){
    int mx=0;
    w=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]==1){
            if(a[i-1]==0){w=1;}
            else{w++;}
        }
        else{
            w=0;
        }
        mx=max(mx,w);
    }
    if(a[1]==1 && a[n]==1){
        w=0;
        ll l=1; ll r=n;
        while(l<r){
            if(a[l]==1){w++;l++;}
            if(a[r]==1){w++;r--;}
            if(a[l]==0 && a[r]==0)break;
        }
        mx = max(w,mx);
    }
    cout<<mx<<endl;
}
