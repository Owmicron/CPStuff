#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll dua[40],n,k,r,l;
queue <ll> q;
void arr (ll x){
    str temp = "";
    while(x>0){
        if(x%2==0){temp+="0";}
        else{temp+="1";}
        x/=2;
    }
    for(int i=0;i<temp.size();i++){
        if(temp[i]=='1'){q.push(dua[i]);}
    }
}
int main(){
    dua[0]=1;
    for(int i=1;i<=35;i++)dua[i]=2*dua[i-1];
    cin>>n>>k;
    arr (n);
    r = n;
    l = q.size();
    if(k>=l && k<=r){
        ll change = k-q.size();
        while(change>0){
            ll temp=q.front();
            q.pop();
            if(temp==1){q.push(1);}
            else{
                temp/=2;
                q.push(temp);
                q.push(temp);
                change--;
            }
        }
        cout<<"YES\n";
        while(!q.empty()){
            cout<<q.front()<<" ";
            q.pop();
        }
    }
    else{
        cout<<"NO\n";
    }

}
