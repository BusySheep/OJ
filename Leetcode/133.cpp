/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
private:
public:
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
        if (node == NULL) return NULL;
        static map<UndirectedGraphNode*, UndirectedGraphNode*> visited;
        UndirectedGraphNode* result;
        if (visited.count(node) != 0) {
            return visited[node];
        } else {
            result = new UndirectedGraphNode(node->label);
            visited[node] = result;
        }
        for (int i = 0; i < node->neighbors.size(); i++) {
        	result->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        return result;
    }
};