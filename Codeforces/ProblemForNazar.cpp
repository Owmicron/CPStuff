#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll range[70],ans,idx,p=1;
ll md=1000000007;
ll start[70],fin[70],l,r,t;
ll sum(ll x){
    ll cur=0;
    for(int i=1;i<=idx;i++){
        if(x<=range[i] && x>range[i-1]){cur=i;break;}
    }
    ll special = x-range[cur-1];
    special = start[cur] + 2 * (special-1);
    ll s=0;
    for(int i=1;i<=cur;i++){
        ll left,right;
        left = start[i];
        right = fin[i];
        if(i==cur){right=special;}

        ll n,a,b;
        n = (right-left)/2 + 1;
        a = left+right;
        if(n%2==0){n/=2;}
        else{a/=2;}
        b = ((a%md)*(n%md))%md;
        s = ((s%md) + (b%md))%md;
    }
    return s;
}
int main(){
    start[1]=1;fin[1]=1;
    range[1]=1;
    while(ans<=1000000000000000000){
        ans+=p;
        p*=2;
        idx = floor(log(p)/log(2))+1;
        start[idx]=fin[idx-2]+2;
        fin[idx]=fin[idx-2]+2*p;
        range[idx]=range[idx-1]+p;
//        cout<<range[idx]<<endl;
//        cout<<start[idx]<<" "<<fin[idx]<<endl;
//        cout<<"start\n"<<start[idx]<<"\nfin\n"<<fin[idx]<<endl;
    }
//    for(int i=1;i<=idx;i++){
//        cout<<"idx "<<i<<endl<<"range "<<range[i]<<endl;
//        cout<<start[i]<<" "<<fin[i]<<endl;
//    }
//    cout<<endl;
    scanf("%lld %lld",&l,&r);
    t = sum(r) - sum(l-1);
    if(t<0){t+=md;}
    printf("%lld\n",t);
}
