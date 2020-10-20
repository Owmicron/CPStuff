#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
stack<ll> s;
ll n,a,t,c,ans;
pair<ll,ll> p[100002];
int main(){
    cin>>n;
    s.push(100001);
    c++;
    for(ll i=1;i<=n;i++){
        cin>>a;
        if(a<s.top()){
//            for(ll i=t;i>=1;i--){
//                if(s.top()>=p[i].first){
//                    ans+=p[i].second;
//                }
//                else{
//                    break;
//                }
//            }
            t++;
            p[t].first = s.top();
            p[t].second = c;
            c=0;

            s.push(a);c++;
            ans+=c;
        }
        else{
            s.push(a);c++;
            ans+=c;
            for(ll i=t;i>=1;i--){
                if(s.top()>=p[i].first){
                    ans+=p[i].second;
                }
                else{
                    break;
                }
            }
        }
    }
//    for(ll i=t;i>=1;i--){
//        if(s.top()>=p[i].first){
//            ans+=p[i].second;
//        }
//        else{
//            break;
//        }
//    }
    cout<<ans<<endl;
}
