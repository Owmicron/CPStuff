#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int m,n;
int mat[600][600];
vector< pair<int,int> > v[600];
stack <int>ans;
stack <int>ans2;
void daftar (int x){
    vector< pair<int,int> > z;
    for(int i=1;i<=m;i++){
        z.push_back(make_pair(mat[x][i],i));
    }
    sort(z.begin(),z.end());
    v[x].push_back(z[0]);
    for(int i=1;i<z.size();i++){
        if(z[i].first != z[i-1].first){v[x].push_back(z[i]);}
    }
    sort(v[x].begin(),v[x].end());
}
bool valid;
void c(int deep,int res){
    if(deep<n){
        for(int i=0;i<v[deep].size();i++){
            int rest=res xor v[deep][i].first;
            ans.push(v[deep][i].second);
//            cout<<deep<<" "<<rest<<endl;
            c(deep+1,rest);
            if(valid){break;}
            ans.pop();
        }
    }
    else{
        for(int i=0;i<v[deep].size();i++){
            int rest=res xor v[deep][i].first;
            ans.push(v[deep][i].second);
//            cout<<deep<<" "<<rest<<endl;
            if(rest>0){valid=true;break;}
            ans.pop();
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mat[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        daftar(i);
    }
//    for(int i=1;i<=n;i++){
//        for(int j=0;j<v[i].size();j++){
//            cout<<v[i][j].first<<" ";
//        }cout<<endl;
//    }
    c(1,0);
    if(!valid){cout<<"NIE\n";}
    else{
        cout<<"TAK\n";
        while(!ans.empty()){
            ans2.push(ans.top());
            ans.pop();
        }
        cout<<ans2.top();
        ans2.pop();
        while(!ans2.empty()){
            cout<<" "<<ans2.top();
            ans2.pop();
        }
    }

}
