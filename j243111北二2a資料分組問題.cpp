#include<iostream>
#include<vector>
#include<math.h>
#include<unordered_set>
#include<limits>
using namespace std;
const int LIM=numeric_limits<int>::max();
int d,N;
int hammingDistance(const vector<int>& a,const vector<int>& b) {
    int dist=0;
    for(size_t i=0;i<d;++i){
        dist+=abs(a[i]-b[i]);
    }
    return dist;
}
int main() {
    while(cin>>d>>N){
        vector<vector<int>>data(N,vector<int>(d,0));
        vector<int>node(N,0);
        for(int i=0;i<N;++i){
            node[i]=i;
            for(int j=0;j<d;++j){
                cin>>data[i][j];
            }
        }
        int c=1,dist_min=LIM;
        while(true){
            int dist_min_cur=LIM;
            for(int i=0;i<N;++i){
                for (int j=i+1;j<N;++j){
                    int dist=hammingDistance(data[i],data[j]);
                    if(dist<=c){
                        node[j]=node[i];
                        dist_min_cur=min(dist_min_cur,dist);
                    }
                }
            }
            if(dist_min_cur==dist_min)break;
            dist_min=min(dist_min,dist_min_cur);
            c++;
        }    
        unordered_set<int>st;
        for(auto it:node){
            st.insert(it);
        }
        cout<<st.size()<<endl;
    }
    return 0;
}
