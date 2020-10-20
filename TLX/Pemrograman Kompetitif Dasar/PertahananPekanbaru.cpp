#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll ans;
int n,sd,sm,p[300010],k[300010],l[300010],nlawan;
priority_queue < pair <int, int> > heap;
str subsoal;
bool possible,lawan[300010];
//int parent(int x){return (x-1)/2;}
//int left(int x){return 2*x+1;}
//int right(int x){return 2*(x+1);}
//int heap_push( pair <int,int> x){
//    heap.push_back(x);
//    int i = heap.size()-1;
//
//    while ((i>0) && (heap.at(i).first > heap.at(parent(i)).first )){
//        swap (heap.at(i) , heap.at(parent(i)));
//        i = parent(i);
//    }
//}
//
//int heapify (int x){
//    int i = x;
//    int mx = i;
//    bool swapped = true;
//
//    while(swapped){
//        if(( left(i) < heap.size() ) && (heap.at(left(i)).first > heap.at(mx).first)){mx = left(i);}
//        if(( right(i) < heap.size() ) && (heap.at(right(i)).second > heap.at(mx).first)){mx = right(i);}
//        swap (heap.at(i) , heap.at(mx));
//        if( i == mx ){swapped = false;}
//        i = mx;
//    }
//}
//
//void heap_pop(){
//    if(!heap.empty()){
//        nlawan++;lawan[heap.at(0).second]=true;
//        swap (heap.at(0),heap.at(heap.size()-1));
//        heap.pop_back();
//        if(!heap.empty()){heapify(0);}
//    }
//}
//void borong(){
//    while(!heap.empty()){
//        if(heap.at(0).first >= 0){
//            heap_pop();
//        }
//        else{
//            break;
//        }
//    }
//}
int main(){
    cin>>subsoal;possible=true;
    cin>>n>>sd>>sm;
    for(int i=1;i<=n;i++){
        if(i<n){cin>>p[i]>>k[i]>>l[i];}
        else{p[i]=sm;}
        if(sd + (i-1) < p[i]){possible =false;}
        if(possible){
            int lmin = p[i] - sd - nlawan;
            for(int i=1;i<=lmin;i++){
                nlawan++;
                lawan[heap.top().second]=true;
                heap.pop();
            }
            //borong();
            if(k[i]-l[i]>=0){nlawan++;lawan[i] =true;}
            else{heap.push(make_pair(k[i]-l[i],i));}
        }
    }

    if(!possible){ans=-1;}
    else{
        for(int i=1;i<n;i++){
            if(lawan[i]){ans+=l[i];}
            else{ans+=k[i];}
        }
    }
    cout<<ans<<endl;
}
