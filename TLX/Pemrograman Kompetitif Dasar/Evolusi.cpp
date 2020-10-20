#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int m,n,z;
str a,b;
stack <str> ans;
vector < pair<str,str> > pc;
int lower(string s){
    int l=0;
    int r=pc.size()-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(pc.at(mid).first > s){
            r=mid-1;
        }
        else if(pc.at(mid).first < s){
            l=mid+1;
        }
        else{
            if(mid-1 >= 0){
                if(pc.at(mid-1).first == s){
                    r=mid-1;
                }
                else{
                    return mid;
                }
            }
            else{
                return mid;
            }
        }
    }
    return -1;
}
int upper(string s){
    int l=0;
    int r=pc.size()-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(pc.at(mid).first > s){
            r=mid-1;
        }
        else if(pc.at(mid).first < s){
            l=mid+1;
        }
        else{
            if(mid+1 < pc.size()){
                if(pc.at(mid+1).first == s){
                    l=mid+1;
                }
                else{
                    return mid;
                }
            }
            else{
                return mid;
            }
        }
    }
    return -1;
}
void dfs(str s){
    if(s!=b){
        int low = lower (s);
        int up = upper (s);
        if((low==-1)||(up==-1)){}
        else{
            for(int i=low;i<=up;i++){
                dfs(pc.at(i).second);
                if(z==1){ans.push(s);break;}
            }
        }
    }
    else{
        z=1;ans.push(s);
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        str p,c;cin>>p>>c;
        pc.push_back(make_pair(p,c));
    }
    cin>>a>>b;
    sort(pc.begin(),pc.end());
    dfs(a);
    if(z==0){
        swap(a,b);
        dfs(a);
        if(z==0){cout<<"TIDAK MUNGKIN"<<endl;}
        else{
            while(!ans.empty()){
                cout<<ans.top()<<endl;
                ans.pop();
            }
        }
    }
    else{
        while(!ans.empty()){
            cout<<ans.top()<<endl;
            ans.pop();
        }
    }

//    cout<<endl;
//    for(int i=0;i<pc.size();i++){
//        cout<<pc.at(i).first<<" "<<pc.at(i).second<<endl;
//    }
    //str x = "dinohippus";cout<<lower(x)<<" "<<upper(x)<<endl;


}
