#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,k;
int a[300000];
int f[300000];
int fmx,mx,idx;
vector <pair < int , pair<int,int> > > ans;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[a[i]]++;
        if(f[a[i]]>fmx){fmx=f[a[i]];mx=a[i];idx=i;}
    }
    k = n-fmx;
    for(int i=idx-1;i>=1;i--){
        if(a[i]!=mx){
            int t;
            if(a[i]<mx){t=1;}
            else{t=2;}
            ans.push_back ( make_pair (t , make_pair (i,i+1) ) );
            a[i]=mx;
        }
    }
    for(int i=idx+1;i<=n;i++){
        if(a[i]!=mx){
            int t;
            if(a[i]<mx){t=1;}
            else{t=2;}
            ans.push_back ( make_pair (t , make_pair (i,i-1) ) );
            a[i]=mx;
        }
    }
    cout<<k<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second.first<<" "<<ans[i].second.second<<endl;
    }

}

