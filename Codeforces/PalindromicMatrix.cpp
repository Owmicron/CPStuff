#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,m[22][22],a[500];
int num[1010];
bool use[1010],valid;
priority_queue <pair<int,int> >q;
void fill_edge (int x){
    if(!q.empty()){
        if(q.top().first>=4){
            int t = q.top().first;
            int node = q.top().second;
            q.pop();
            m[1][1] = node;
            m[1][x] = node;
            m[x][1] = node;
            m[x][x] = node;
            t-=4;
            if(t>0){
                q.push(make_pair(t,node));
            }
        }
        else{
            valid=false;
        }
    }
    else{
            valid=false;
    }
}
void fill_side (int x){
    for(int i=1;i<=x/2;i++){
        if(!q.empty()){
            if(q.top().first>=4){
                int t = q.top().first;
                int node = q.top().second;
                q.pop();
                m[1][i] = node;
                m[n][i] = node;
                m[1][n+1-i] = node;
                m[n][n+1-i] = node;
                t-=4;
                if(t>0){
                    q.push(make_pair(t,node));
                }
            }
            else{
                valid=false;
            }
        }
        else{
            valid=false;
        }
    }
}
void fill_ud (int x){
    for(int i=1;i<=x/2;i++){
        if(!q.empty()){
            if(q.top().first>=4){
                int t = q.top().first;
                int node = q.top().second;
                q.pop();
                m[i][1] = node;
                m[i][n] = node;
                m[n+1-i][1] = node;
                m[n+1-i][n] = node;
                t-=4;
                if(t>0){
                    q.push(make_pair(t,node));
                }
            }
            else{
                valid=false;
            }
        }
        else{
            valid=false;
        }
    }
}
void fill_center (int x){
    if(!q.empty()){
        if(q.top().first>=2){
            int t = q.top().first;
            int node = q.top().second;
            q.pop();
            m[1][x/2+1] = node;
            m[x][x/2+1] = node;
            t-=2;
            if(t>0){
                q.push(make_pair(t,node));
            }
        }
        else{
            valid=false;
        }
    }
    else{
            valid=false;
    }
    if(!q.empty()){
        if(q.top().first>=2){
            int t = q.top().first;
            int node = q.top().second;
            q.pop();
            m[x/2+1][1] = node;
            m[x/2+1][x] = node;
            t-=2;
            if(t>0){
                q.push(make_pair(t,node));
            }
        }
        else{
            valid=false;
        }
    }
    else{
            valid=false;
    }
}
void construct (int x){
    if(x%2==0){
        if(x>2){
            if(valid)fill_edge(x);
            if(valid)fill_side(x);
            if(valid)fill_ud(x);
            if(valid)construct(x-2);
        }
        else{
            if(valid)fill_edge(x);
        }
    }
    else{
            if(valid)fill_edge(x);
            if(valid)fill_side(x);
            if(valid)fill_ud(x);
            if(x>3){
                if(valid)construct(x-2);
            }
            if(valid)fill_center(x);
    }
}
int main(){
    valid = true;
    cin>>n;
    for(int i=1;i<=n*n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        num[ a[i] ] ++;
        use[a[i]]=true;
    }
    for(int i=1;i<=1000;i++){
        if(use[i]){
            q.push (make_pair(num[i],i));
        }
    }
    construct(n);
    if(valid){
        if(n%2==1){
            if(q.top().first>0){
                m[n/2+1][n/2+1]=q.top().second;
            }
            else{valid=false;}
        }
    }
    if(n==1){
        cout<<a[1]<<endl;
    }
    else{
        if(valid){
            cout<<"YES"<<endl;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    cout<<m[i][j];
                    if(j<n)cout<<" ";
                }cout<<endl;
            }
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}
