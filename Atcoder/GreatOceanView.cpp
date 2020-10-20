#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,h,mx,ans;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>h;
        if(i==1){mx = h;ans++;}
        else{
            if(h>=mx){mx = h;ans++;}
        }
    }
    cout<<ans<<endl;
}
