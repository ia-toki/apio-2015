#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cassert>

using namespace std;

vector<int> edge[50005];
int N,M,b,p,start,finish,jarak[50005],node,banding;
bool sudah[50005];

int main() {
    scanf("%d %d",&N,&M);
    for (int i=0;i<M;++i) {
        scanf("%d %d",&b,&p);
        if (i==0) start = b;
        else if (i==1) finish = b;
        assert(0<=b&&b<N);
        edge[b].push_back(p);
    }

    memset(jarak,127,sizeof(jarak));
    memset(&banding,127,sizeof(banding));
    jarak[start] = 0;
    node = start;

    while (!sudah[finish] && node != -1) {
        sudah[node] = true;
        for (int i=0;i<edge[node].size();++i) {
            for (int j=1;node+j*edge[node][i]<N;++j) {
                jarak[node+j*edge[node][i]] = min(jarak[node+j*edge[node][i]],jarak[node]+j);
            }

            for (int j=1;node-j*edge[node][i]>=0;++j) {
                jarak[node-j*edge[node][i]] = min(jarak[node-j*edge[node][i]],jarak[node]+j);
            }
        }

        node = -1;
        for (int i=0;i<N;++i) {
            if (sudah[i]) continue;
            if (jarak[i] == banding) continue;
            if (node == -1 || jarak[node] > jarak[i]) node = i;
        }
    }

    if (sudah[finish]) printf("%d\n",jarak[finish]);
    else printf("-1\n");
    return 0;
}
