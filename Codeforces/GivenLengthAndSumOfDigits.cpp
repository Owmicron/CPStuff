#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll m,s;
int a[101],b[101];
int main(){
    cin>>m>>s;
    if(9*m < s){cout<<"-1 -1";}
    else if(s == 0){
        if(m==1){cout<<"0 0";}
        else{cout<<"-1 -1";}
    }
    else{
        ll t=s;
        for(ll i=0;i<m;i++){
            if(t>9){
                a[i]=9;
                t-=9;
            }
            else{
                a[i]=t;
                break;
            }
        }
        t=s-1;
        b[0]=1;
        for(ll i=m-1;i>=0;i--){
            if(t>9){
                b[i]+=9;
                t-=9;
            }
            else{
                b[i]+=t;
                break;
            }
        }
        for(ll i=0;i<m;i++)cout<<b[i];
        cout<<" ";
        for(ll i=0;i<m;i++)cout<<a[i];
    }
}
