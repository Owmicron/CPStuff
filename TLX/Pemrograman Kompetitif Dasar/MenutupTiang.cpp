#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef double dbl;
int s,f,n,d;
dbl mx,ans;
vector<int> v;
dbl cross (pair <dbl,dbl> o, pair<dbl,dbl> a, pair<dbl,dbl> b){
    return ( ((a.first - o.first)*(b.second - o.second)) - ((a.second - o.second)*(b.first - o.first)) );
}
dbl gradient(dbl x1, dbl y1, dbl x2, dbl y2){
    dbl m = (y2-y1) / (x2-x1);return m;
}
dbl draw_line(dbl x1, dbl y1, dbl x2, dbl y2){
    dbl l = sqrt((y2-y1)*(y2-y1) + (x2-x1)*(x2-x1));return l;
}
pair<dbl,dbl>pole[300000];
int main(){
    scanf("%d %d %d %d",&s,&f,&n,&d);
    for(int i=1;i<=n;i++){
        int x,h;scanf("%d %d",&x,&h);
        pole[i]=make_pair(x-(d/2),h);
        pole[n+i]=make_pair(x+(d/2),h);
    }
    sort(pole+1,pole+1+2*n);

    int point = 0;
    int p = point;
    pole[0].first = s;
    pole[2*n+1].first = f;

    for(int i=0;i<=2*n+1;i++){
        while ((v.size()>=2)&&( cross (pole[v.at(v.size()-2)] , pole[v.at(v.size()-1)] , pole[i])>=0 )){
            v.pop_back();
        }
        v.push_back(i);
    }
    for (int i=0;i<v.size()-1;i++){
        ans+=draw_line (pole[v.at(i)].first,pole[v.at(i)].second,pole[v.at(i+1)].first,pole[v.at(i+1)].second);
    }
    printf("%.3lf\n",ans);
}
