#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll q,l,r,d,ans;
int main(){
    cin>>q;
    for(ll i=1;i<=q;i++){
        cin>>l>>r>>d;
        if(d<l){ans=d;}
        else{
            if(r%d==0){ans=r+d;}
            else{ans= ((r/d)+1)*d;}
        }
        cout<<ans<<endl;
    }
}
