/*
1. BFS: Simple BFS search in a graph starting fromt the start node looking for the end node. Keep pushing the nbrs
	    TC: O(n) Each node is traversed at most once.
	    SC: O(n) for queue


	2. DFS: Recursively keep visiting the nodes and checking if this is the end
	    TC: O(n) Each node is traversed at most once.
	    SC: O(n) for recursion stack


	3. Disjoint Set Union: Create a DSU and then check if start and end have the same leaders?
		TC: O(n*α(n)) ≈ O(n), the time complexity of each find call after union-by-rank and path 
			compression comes out to be O(α(n)), where α(n) is the inverse Ackermann function. It doesn't exceed 4 
			for any n < 10600 and hence is practically constant. We make O(n) calls in total.
		SC: O(n) for UF Data structure
*/

// S Akash

class Solution {
public:
    
    bool dfs(vector<vector<int>>& graph, vector<int>& visited, int current, int end) {
        if(current == end)
            return true;
        if(visited[current])
            return false;
        
        visited[current] = 1;
        
        for(int i=0; i<graph[current].size(); i++){
            if(dfs(graph, visited, graph[current][i], end))
                return true;
        }
        
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<vector<int>> graph(n);
        for(int i=0; i<edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> visited(n, 0);
        return dfs(graph, visited, start, end);
    }
};