#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n;
bool valid;
int f[300000];
vector<int> a,b;
int main(){
    cin>>n;
    valid=true;
    for(int i=1;i<=n;i++){
        int temp;
        cin>>temp;
        f[temp]++;
        if(f[temp]>=3){valid=false;}
        if(f[temp]==1){a.push_back(temp);}
        else if(f[temp]==2){b.push_back(temp);}
    }
    if(!valid){cout<<"NO\n";}
    else{
        cout<<"YES\n";
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        cout<<a.size()<<endl;
        for(int i=0;i<a.size();i++){
            cout<<a[i];
            if(i<a.size()-1)cout<<" ";
        }
        cout<<endl;
        cout<<b.size()<<endl;
        for(int i=b.size()-1;i>=0;i--){
            cout<<b[i];
            if(i>0)cout<<" ";
        }
        cout<<endl;
    }
}

