#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll q,n,a,b,ans;
int main(){
    cin>>q;
    for(int i=1;i<=q;i++){
        cin>>n>>a>>b;
        ans=0;
        if(n%2==1){n--;ans+=a;}
        if(2*a>b){
            ans += (n/2)*b;
        }
        else{
            ans += n*a;
        }
        cout<<ans<<endl;
    }
}
