/**
 * @param {number} n
 * @param {number[][]} roads
 * @return {number}
 */
var minScore = function (n, roads) {

    // Adjacency List
    // Key   -> City
    // Value -> Array of [Neighbour, Distance]
    //
    // Example:
    // 1 -> [[2, 9], [3, 5]]
    // 2 -> [[1, 9], [3, 6]]
    const adj = new Map();

    // ---------------- Build Graph ----------------
    for (const [u, v, c] of roads) {

        // If city 'u' is not already present,
        // create an empty neighbour list.
        //
        // Why?
        // adj.get(u) would return undefined otherwise,
        // and undefined.push(...) would cause an error.
        if (!adj.has(u)) {
            adj.set(u, []);
        }

        // Same for city 'v'
        if (!adj.has(v)) {
            adj.set(v, []);
        }

        // Since roads are bidirectional,
        // add both directions.
        adj.get(u).push([v, c]);
        adj.get(v).push([u, c]);
    }

    // visited[i] tells whether city i has been visited
    const visited = new Array(n + 1).fill(false);

    // Stores the minimum edge weight found so far
    let result = Infinity;

    function dfs(u) {

        // Mark current city as visited
        visited[u] = true;

        // Traverse all neighbours of current city
        for (const [v, c] of adj.get(u) || []) {

            // Keep updating the minimum road weight
            result = Math.min(result, c);

            // Visit neighbour if not already visited
            if (!visited[v]) {
                dfs(v);
            }
        }
    }

    // Start DFS from city 1
    dfs(1);

    return result;
};
