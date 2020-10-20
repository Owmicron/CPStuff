#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,k,a[300000];
bool used[300000];
int l[300000],r[300000];
int val[300000];
vector<int> one,two;
bool fst;
priority_queue < pair<int,int> > q;
void take_left (int x){
    int cur = x;
    for(int i=1;i<=k;i++){
        cur = l[cur];
        if(cur==0){break;}
        //cout<<"left "<<a[cur]<<endl;
        if(fst){one.push_back(a[cur]);}
        else {two.push_back(a[cur]);}
        used[cur]=true;
        r[l[cur]] = r[cur];
        l[r[cur]] = l[cur];
    }
}
void take_right (int x){
    int cur = x;
    for(int i=1;i<=k;i++){
        cur = r[cur];
        if(cur==0){break;}
        //cout<<"right "<<a[cur]<<endl;
        if(fst){one.push_back(a[cur]);}
        else {two.push_back(a[cur]);}
        used[cur]=true;
        r[l[cur]] = r[cur];
        l[r[cur]] = l[cur];
    }
}
int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        l[i]=i-1;
        r[i]=i+1;
        if(i==n){r[i]=0;}
        q.push(make_pair(a[i],i));
    }

    while(!q.empty()){
        int idx = q.top().second;
        q.pop();
        //cout<<a[idx]<<" "<<idx<<endl;
        if(!used[idx]){
            fst = not fst;
            if(fst){one.push_back(a[idx]);}
            if(!fst){two.push_back(a[idx]);}
            r [l[idx]] = r[idx];
            l [r[idx]] = l[idx];
            used[idx]=true;
            take_left(idx);
            take_right(idx);
        }
    }
    for(int i=0;i<one.size();i++)val[one[i]]=1;
    for(int i=0;i<two.size();i++)val[two[i]]=2;
    for(int i=1;i<=n;i++){
        printf("%d",val[a[i]]);
    }
}
