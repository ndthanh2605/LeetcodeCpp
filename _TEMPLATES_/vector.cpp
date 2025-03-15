// append vector to vector

rs.insert(rs.end(), arr.begin(), arr.end());


// -------------------------------------------------
// using array to implement queue (for topology sort)

vector<int> q(n);
int first = 0, last = -1;

// indegree
for (int i = 0; i < n; i++) {
	if (degree[i] == 0)
		q[++last] = i;		// q.push(i)
}

while (first <= last) {
	int i = q[first++];		// q.top() + q.pop()
	for (auto& j : adj[i]) {
		degree[j]--;
		if (degree[j] == 0) {
			q[++last] = j;	// q.push(j)
		}
	}
}

return first == n? q : vector<int>(n);