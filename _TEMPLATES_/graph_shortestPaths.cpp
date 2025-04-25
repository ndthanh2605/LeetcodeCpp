// Dijkstra -> non negative edges
vector<int> dijkstra(int src, int n, vector<vector<pair<int, int>>>& adj) {
	vector<int> rs(n, INT_MAX);
	rs[src] = 0;
	
	// use heap {distance, node}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0, src });
	whiie (!pq.empty()) {
		auto [d, u] = pq.top(); pq.pop();
		if (d > rs[u])
			continue;
		
		for (const auto& [v, w] : adj[u]) {
			if (rs[u] + w < rs[v]) {
				rs[v] = rs[u] + w;
				pq.push({ rs[v], v });
			}
		}
	}
	
	return rs;
}


// Bellman-Ford -> from 1 single nodes to all others (include negative edges)
// adj : list of {u, v, w} edges
vector<int> bellmanFort(int src, int n, vector<vector<tuple<int>>>& adj) {
	vector<int> rs(n, INT_MAX);
	rs[src] = 0;
	
	// relax all edges: (n - 1) times
	for (int i = 1; i < n; i++) {
		for (auto& [u, v, w] : adj) {
			if (rs[u] != INT_MAX && rs[u] + w < rs[v]) {
				rs[v] = rs[u] + w;
			}
		}
	}
	
	// check for negative cycle
	for (auto& [u, v, w] : adj) {
		if (rs[u] != INT_MAX && rs[u] + w < rs[v])
			return {};
	}
	
	return rs;
}


// Floyd-Warshall -> all pairs of nodes in weighted graph (include negative edges)
// graph : adj matrix (INT_MAX for no edge)
void floydWarshall(int n, vector<vector<int>>& graph) {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX) {
					graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
				}
			}
		}
	}
}

