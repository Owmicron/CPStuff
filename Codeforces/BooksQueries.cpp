#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
bool pos[200010];
ll q,l[200010],r[200010],lef,righ,tpt[200010];
char c;
ll src(ll x){
    if(!pos[x]){
        ll y,z;
        y = lef - tpt[x];
        z = lef - y + righ;
        return min(y,z);
    }
    else{
        ll kiri,kanan,mid;
        kiri=1;
        kanan=righ;
        bool found=false;
        ll y,z;
        y = righ - tpt[x];
        z = righ - y + lef;
        return min(y,z);
    }
}
int main(){
    cin>>q;
    for(ll i=1;i<=q;i++){
        ll temp;
        cin>>c>>temp;
        if(c=='L'){lef++;l[lef]=temp;tpt[temp]=lef;}
        else if(c=='R'){righ++;r[righ]=temp;pos[temp]=true;tpt[temp]=righ;}
        else{
            cout<<src(temp)<<endl;
        }

    }
}
