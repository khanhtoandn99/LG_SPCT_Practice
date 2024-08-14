

void BFS(v)
{
    queue.push(v)
    visited[v] = true
    while (!queue.empty()) {
        u = queue.front()
        queue.pop()
        for (w : G[u]) {
            if (visited[w] == false) {
                visited[w] = true
                queue.push(w)
            }
        }
    }
}