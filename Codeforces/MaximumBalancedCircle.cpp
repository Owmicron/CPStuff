#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
int n,f[300000],beg,fin,sum[300000];
vector<int> v,ans;
vector < pair < int, pair<int,int> > > p;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int temp;
        scanf("%d",&temp);
        if(f[temp]==0){v.push_back(temp);}
        f[temp]++;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        sum[i+1]=sum[i]+f[v[i]];
    }

//    for(int i=0;i<v.size();i++)cout<<v[i]<<" ";cout<<endl;
//    for(int i=0;i<v.size();i++)cout<<f[v[i]]<<" ";cout<<endl;
//    for(int i=1;i<=v.size();i++)cout<<sum[i]<<" ";cout<<endl;cout<<endl;

    beg = 0;
    for(int i=1;i<v.size();i++){
        if (abs (v[i]-v[i-1]) <= 1 ){
            if(f[v[i]]==1){
                fin=i;
                p.push_back (make_pair (sum[fin+1]-sum[beg], make_pair(beg,fin)) );
                beg=i;
            }
        }
        else{
            fin=i-1;
            p.push_back (make_pair (sum[fin+1]-sum[beg], make_pair(beg,fin)) );
            beg=i;
        }
    }
    fin = v.size()-1;
    p.push_back (make_pair (sum[fin+1]-sum[beg], make_pair(beg,fin)) );

    sort(p.begin(),p.end());
//    for(int i=0;i<p.size();i++){
//        cout<<p[i].first<<" "<<p[i].second.first<<" "<<p[i].second.second<<endl;
//    }

    int idx = p.size()-1;
    beg = p [idx].second.first; fin = p[idx].second.second;

    for(int i=beg;i<fin;i++){
        ans.push_back (v[i]) ;
    }
    for(int i=fin;i>=beg;i--){
        int ff = f[v[i]];
        if(i<fin)ff--;
        for(int j=1;j<=ff;j++){
            ans.push_back(v[i]);
        }
    }

    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)printf("%d ",ans[i]);

}
