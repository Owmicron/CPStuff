#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n;
double eps=0.00001;
double a[300000],b[300000];
bool isequal (double x, double y){
    if(abs(x-y)<eps){return true;}
    return false;
}
vector<double>v;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        if(a[i]!=0){v.push_back(-b[i]/a[i]);}
    }
    int ans=0;
    if(v.empty()){ans=0;}
    else{
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            int temp;
            if(i==0){ans=1;temp=1;}
            else{
                if(isequal(v[i],v[i-1])){temp++;}
                else{temp=1;}
                ans = max(ans,temp);
            }
        }
    }
    cout<<ans<<endl;
}
