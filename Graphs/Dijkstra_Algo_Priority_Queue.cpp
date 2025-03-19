class Solution {
public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], weight = edge[2];
            adj[u].push_back({ weight,v});
            
        }

        vector<int> distances(V, INT_MAX);
      set<pair<int, int>> s;
        distances[0] = 0;
        s.insert({0,0});
        //its weight,node not node,weight to reduce redundancy of calculation where long distance might be updated and again short one is found

        while (!s.empty()) {
            auto it = s.begin();
            int curr = it->second;
            int dist = it->first;
            s.erase(it);
            for (auto& nbor : adj[curr]) {
                int nextNode = nbor.second;
                int edgeWeight = nbor.first;
                if (distances[curr] + edgeWeight < distances[nextNode]) {
                    if(distances[nextNode]!=INT_MAX){
                        s.erase({distances[nextNode],nextNode});
                    }
                    distances[nextNode] = distances[curr] + edgeWeight;
                    s.insert({distances[nextNode],nextNode});
                }
            }
        }

       
        for (int i = 0; i < V; i++) {
            if (distances[i] == INT_MAX) {
                distances[i] = -1;
            }
        }

        return distances;
    }
};
