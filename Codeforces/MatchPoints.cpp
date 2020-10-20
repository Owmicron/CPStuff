#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n;
bool used[300000];
ll mini,a[300000],z,f;
bool can(int x){
    bool bs=true;
    for(int i=1;i<=x;i++){
        int l=i;
        int r=n-x+i;
        if((abs(a[l]-a[r]))<z){bs=false;break;}
    }
    return bs;
}
ll ans (int l,int r){
    int rmost=r;
    int z = 0;
    while(l<=r){
        bool a,b;
        int mid = (l+r)/2;
        a = can(mid);
        b = can(mid+1);

        if(a && b){
            if(mid<rmost)l=mid+1;
            else {z=mid;break;}
        }
        else if(a && !b){
            z=mid;break;
        }
        else{
            r=mid-1;
        }
    }
    return z;
}
int main(){
    cin>>n>>z;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);

    cout<<ans(0,n/2);

}

