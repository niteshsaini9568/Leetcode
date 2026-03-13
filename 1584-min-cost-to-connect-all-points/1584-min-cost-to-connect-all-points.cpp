class Solution {
public:
    typedef pair<int, int> P;
    int minCostConnectPoints(vector<vector<int>>& points) {
       int V = points.size();

       vector<vector<P>> adj(V);

        for(int i = 0; i < points.size(); i++){
            for(int j = i+1; j < points.size(); j++){
                int dis = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, dis});
                adj[j].push_back({i, dis});
            }
        }

        int sum = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<bool> visited(V, false);

        pq.push({0,0});  

        while(!pq.empty()){
            auto el = pq.top();
            pq.pop();

            int wt = el.first;
            int u = el.second;

            if(visited[u]) continue;

            visited[u] = true;
            sum += wt;

            for(auto &edge : adj[u]){
                int v = edge.first;
                int wt_ = edge.second;

                if(!visited[v]){
                    pq.push({wt_, v});
                }
            }
        }

        return sum;
    }
};