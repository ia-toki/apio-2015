#include <bits/stdc++.h>
using namespace std;

int n, m;
int pw[100005];
int pos[100005];
vector <int> doges[100005];

int dist[50005][300];

priority_queue<pair<int,pair<int,int> > > pq;

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &pos[i], &pw[i]);
    doges[pos[i]].push_back(i);
  }

  for (int i = 0; i <= 50000; i++) {
    for (int j = 0; j < 300; j++) {
      dist[i][j] = 1000000000;
    }
  }
  pq.push(make_pair(0, make_pair(pos[0], 0)));
  dist[pos[0]][0] = 0;
  int limit = (int) sqrt(n);
  int res = 1000000000;

  while (!pq.empty()) {
    pair<int,pair<int,int> > now = pq.top();
    pq.pop();
    int posnow = now.second.first;
    int distnow = -now.first;
    if (posnow == pos[1]) {
      res = min(res, distnow);
    }
    int pownow = now.second.second;
    if (pownow == 0) {
      for (int i = 0; i < (int)doges[posnow].size(); i++) {
        if (pw[doges[posnow][i]] <= limit) {
          pair <int,pair<int,int> > nxt;
          if (dist[posnow][pw[doges[posnow][i]]] > distnow) {
            dist[posnow][pw[doges[posnow][i]]] = distnow;
            int distnext = distnow;
            pq.push(make_pair(-distnext, make_pair(posnow, pw[doges[posnow][i]])));
          }
        } else {
          int powernow = pw[doges[posnow][i]];
          for (int j = 1; posnow - j*powernow >= 0; ++j) {
            int posnext = posnow - j*powernow;
            int distnext = distnow + j;
            if (dist[posnext][0] > distnext) {
              dist[posnext][0] = distnext;
              pq.push(make_pair(-distnext, make_pair(posnext, 0)));
            }
          }
          for (int j = 1; posnow + j*powernow < n; ++j) {
            int posnext = posnow + j*powernow;
            int distnext = distnow + j;
            if (dist[posnext][0] > distnext) {
              dist[posnext][0] = distnext;
              pq.push(make_pair(-distnext, make_pair(posnext, 0)));
            }
          }
        }
      }
    } else {
      if (dist[posnow][0] > distnow) {
        dist[posnow][0] = distnow;
        pq.push(make_pair(-dist[posnow][0], make_pair(posnow, 0)));
      }
      if (posnow + pownow < n && dist[posnow + pownow][pownow] > dist[posnow][pownow] + 1) {
        int distnext = dist[posnow][pownow] + 1;
        int posnext = posnow + pownow;
        dist[posnext][pownow] = dist[posnow][pownow] + 1;
        pq.push(make_pair(-distnext, make_pair(posnext, pownow)));
      }
      if (posnow - pownow >= 0 && dist[posnow - pownow][pownow] > dist[posnow][pownow] + 1) {
        int distnext = dist[posnow][pownow] + 1;
        int posnext = posnow - pownow;
        dist[posnext][pownow] = dist[posnow][pownow] + 1;
        pq.push(make_pair(-distnext, make_pair(posnext, pownow)));
      }
    }
  }
  if (res == 1000000000) res = -1;
  printf("%d\n",res);
}
