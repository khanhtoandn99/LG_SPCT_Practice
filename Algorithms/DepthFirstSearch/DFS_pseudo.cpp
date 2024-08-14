
// Using stack
void DFS(v)
{
    stack.push(v)
    while (!stack.empty()) {
        u = stack.pop()
        if (visited[u] == true) continue
        visited[u] = true
        for (w : G[u]) {
            stack.push(w)
        }
    }
}

// Using recursive
void DFS(v)
{
    visited[v] = true
    for (w : G[v]) {
        if (visited[w]) continue
        DFS(w)
    }
}

// Advance - How to list all paths from Source to Target

vector<vector<int>> vAllPaths

void DFS(int v, vector<int> curPath, vector<bool> curVisited)
{
    curPath.push_back(v)
    if (v == G.size() - 1) {
        vAllPaths.push_back(curPath)
        return
    }

    curVisited[v] = true
    for (i : G.size()) {
        w = G[v][i]
        if (w > v && curVisited[w] == false) {
            DFS(w, curPath, curVisited)
        }
    }
}