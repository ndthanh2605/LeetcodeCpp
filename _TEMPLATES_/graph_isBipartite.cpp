bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, -1);       // -1 : not visited, 0 : visited, even, 1 : visited, odd

    bool hasOddCircle = false;
    function<void(int, int)> dfs = [&](int node, int c) -> void
        {
            if (hasOddCircle)
                return;

            color[node] = c;
            for (auto& u : graph[node]) {
                if (color[u] >= 0 && color[u] == color[node]) {
                    hasOddCircle = true;
                    return;
                }
                else if (color[u] < 0) {        // not visited
                    dfs(u, 1 - c);
                }
            }
        };

    for (int i = 0; i < n; i++) {
        if (color[i] < 0)
            dfs(i, 0);
    }

    return !hasOddCircle;
}