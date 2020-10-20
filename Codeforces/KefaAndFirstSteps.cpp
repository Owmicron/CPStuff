#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,m,p,mx,temp;
int main(){
    cin>>n;
    mx=-1;m=-1;
    for(ll i=1;i<=n;i++){
        cin>>temp;
        if (temp>=m){p++;
            if(p>mx){mx=p;}
        }
        else{
            p=1;
        }
        m=temp;
    }
    cout<<mx;
}
