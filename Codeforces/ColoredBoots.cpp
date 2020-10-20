#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
str a,b;
int n;
vector < int > junkx;
vector <int> junky;
vector < pair<int,int> > ans;
pair<char,int> x[200000],y[200000];
int main(){
    cin>>n;
    cin>> a;
    for(int i=0;i<a.size();i++){
        if(a[i]!='?')x[i]=make_pair(char(int(a[i])-32),i);
        else x[i]=make_pair('a',i);
    }
    sort(x,x+a.size());
    cin>> b;
    for(int i=0;i<b.size();i++){
        if(b[i]!='?')y[i]=make_pair(char(int(b[i])-32),i);
        else y[i]=make_pair('a',i);
    }
    sort(y,y+b.size());
//    for(int i=0;i<a.size();i++){
//        cout<<x[i].first;
//    }cout<<endl;
//    for(int i=0;i<a.size();i++){
//        cout<<x[i].second<<" " ;
//    }cout<<endl;
//
//    for(int i=0;i<b.size();i++){
//        cout<<y[i].first;
//    }cout<<endl;
//    for(int i=0;i<b.size();i++){
//        cout<<y[i].second<<" " ;
//    }cout<<endl;
//    cout<<endl;
    int l1=0;int l2=0;
    while(l1<n && l2<n){
//        cout<<l1<<x[l1].first<<" "<<l2<<y[l2].first<<endl;
        if(x[l1].first != 'a' && y[l2].first != 'a'){
            if(x[l1].first == y[l2].first){
                ans.push_back (make_pair(x[l1].second,y[l2].second));
                l1++;l2++;
            }
            else if(x[l1].first < y[l2].first){
                junkx.push_back(x[l1].second);
                l1++;
            }
            else{
                junky.push_back(y[l2].second);
                l2++;
            }
        }
        else{

            if(x[l1].first=='a' && y[l2].first=='a'){
                ans.push_back(make_pair(x[l1].second,y[l2].second));
                l1++;l2++;
            }
            else if(x[l1].first=='a'){
                if(!junky.empty()){
                    ans.push_back(make_pair(x[l1].second,junky.back()));
                    junky.pop_back();l1++;
                }
                else{
                    ans.push_back(make_pair(x[l1].second,y[l2].second));
                    l1++;l2++;
                }
            }
            else if(y[l2].first=='a'){
                if(!junkx.empty()){
                    ans.push_back(make_pair(junkx.back(),y[l2].second));
                    junkx.pop_back();l2++;
                }
                else{
                    ans.push_back(make_pair(x[l1].second,y[l2].second));
                    l1++;l2++;
                }
            }
        }
    }
    if(l1<n){
        for(int i=l1;i<n;i++){
            if(x[i].first=='a'){
            if(!junky.empty()){
                ans.push_back(make_pair(x[i].second,junky.back()));
                junky.pop_back();
            }
            }
        }
    }
    else if(l2<n){
        for(int i=l2;i<n;i++){
            if(y[i].first=='a'){
            if(!junkx.empty()){
                ans.push_back(make_pair(junkx.back(),y[i].second));
                junkx.pop_back();
            }
            }
        }
    }
    cout<<ans.size()<<endl;
    while(!ans.empty()){
        cout<<ans.back().first+1<<" "<<ans.back().second+1<<endl;
        ans.pop_back();
    }
}
