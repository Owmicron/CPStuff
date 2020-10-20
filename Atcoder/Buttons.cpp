#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int a,b,ans;
int main(){
    cin>>a>>b;
    for(int i=0;i<2;i++){
        if(a>=b){ans+=a;a--;}
        else{ans+=b;b--;}
    }
    cout<<ans<<endl;
}
