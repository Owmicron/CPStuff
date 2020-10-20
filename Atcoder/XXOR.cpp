#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,bit[500],bitk[500],mx,ans[500];
ll k,two[50],res;
void bin (ll x, bool ink){
    queue <ll> s;
    while(x>0){
        s.push(x);
        x/=2;
    }
    int idx = -1;
    while(!s.empty()){
        idx ++;
        mx = max(mx,idx);
        if(s.front() % 2 == 1){
            if(!ink)bit[idx]++;
            else bitk[idx]++;
        }
        s.pop();
    }
}
int main(){
    two[0]=1;
    for(int i=1;i<=45;i++){
        two[i] = 2 * two[i-1];
    }

    cin>>n>>k;
    bin(k,true);
    for(int i=1;i<=n;i++){
        ll temp;
        cin>>temp;
        bin(temp,false);
    }
    for(int i=0;i<=mx;i++){
        if(bit[i] < n - bit[i]){ans[i]=1;}
    }
    for(int i=mx;i>=0;i--){
        if(bitk[i]>ans[i]){break;}
        if(bitk[i]<ans[i]){ans[i]=0;}
    }
    for(int i=0;i<=mx;i++){
        if(ans[i]==1){
            res += (ll) two[i] * (n-bit[i]);
        }
        else if(ans[i]==0){
            res += (ll) two[i] * (bit[i]);
        }
    }
    cout<<res<<endl;

}
