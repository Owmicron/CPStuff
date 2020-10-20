#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n;
ll sum;
int o,e;
vector<int> odd,even;
ll a,b,ans;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int temp;cin>>temp;
        sum+=temp;
        if(temp%2==0)even.push_back(temp);
        else odd.push_back(temp);
    }
    sort(odd.begin(),odd.end());
    sort(even.begin(),even.end());


    if(odd.empty()){ans=sum-even[even.size()-1];}
    else if(even.empty()){ans=sum-odd[odd.size()-1];}
    else{
        if(odd.size()==even.size()){ans=0;}
        else if(odd.size()>even.size()){
            //take odd first;
            int mn = even.size();
            for(int i=0;i<odd.size()-1-mn;i++){
                ans+=odd[i];
            }
            //take even;
        }
        else{
            int mn = odd.size();
            for(int i=0;i<even.size()-1-mn;i++){
                ans+=even[i];
            }
        }

    }
    cout<<ans<<endl;
}

