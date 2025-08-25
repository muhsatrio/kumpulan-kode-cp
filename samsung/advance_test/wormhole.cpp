#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Point {
  int x;
  int y;
};

struct Wormhole {
  Point a, b;
  int cost;
};

int countManhattan(Point a, Point b) {
  return abs(a.x - b.x) + abs(a.y - b.y);
}

int main() {
  int t, n;
  
  cin >> t;
  
  while (t--) {
    Point s, d;
    
    cin >> n;
    
    vector<Wormhole> wormholes(n);
    vector<Point> nodes;

    cin >> s.x >> s.y >> d.x >> d.y;
    
    nodes.push_back(s);
    nodes.push_back(d);
    
    for (int i=0; i<n; i++) {
      cin >> wormholes[i].a.x >> wormholes[i].a.y >> wormholes[i].b.x >> wormholes[i].b.y >> wormholes[i].cost;
      nodes.push_back(wormholes[i].a);
      nodes.push_back(wormholes[i].b);
    }
    
    int nodesSize = nodes.size();
    
    vector<vector<pair<int, int> > > graph(nodesSize);
    
    for (int i=0; i<nodesSize; i++) {
      for (int j=i+1; j<nodesSize; j++) {
        graph[i].push_back(make_pair(j, countManhattan(nodes[i], nodes[j])));
        graph[j].push_back(make_pair(i, countManhattan(nodes[i], nodes[j])));
      }
    }
    
    for (int i=0; i<wormholes.size(); i++) {
      int idxA = 2 + 2*i;
      int idxB = 2 + 2*i + 1;
      
      graph[idxA].push_back(make_pair(idxB, wormholes[i].cost));
      graph[idxB].push_back(make_pair(idxA, wormholes[i].cost));
    }
    
    vector<int> dist(nodes.size(), INT_MAX);
    
    dist[0] = 0;
    
    using P = pair<int, int>;
    
    priority_queue<P, vector<P>, greater<P> > pq;
    
    pq.push(make_pair(0, 0));
    
    while (!pq.empty()) {
      auto [currDist, currNode] = pq.top();
      pq.pop();
      
      if (currDist > dist[currNode]) continue;
      if (currNode == 1) break;
      
      for (auto [nextNode, nextDist] : graph[currNode]) {
        if (dist[currNode] + nextDist < dist[nextNode]) {
          dist[nextNode] = dist[currNode] + nextDist;
          pq.push(make_pair(dist[nextNode], nextNode));
        }
      }
    }
    
    cout << dist[1] << endl;
  }
  
  return 0;
}