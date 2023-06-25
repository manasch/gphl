#include <iostream>
#include <map>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <bits/stdc++.h>

template <typename T, typename W>
class Edge {
    public:
        Edge() : src(T()), dest(T()), weight(W()) {}
        Edge(const T& src, const T& dest, const W& weight) : src(src), dest(dest), weight(weight) {}

        T getSource() const {
            return this->src;
        }

        T getDestination() const {
            return this->dest;
        }

        W getWeight() const {
            return this->weight;
        }

        bool operator!() {
            if (src == T() && dest == T() && weight == W()) {
                return false;
            }
            return true;
        }

        void operator=(Edge<T, W> otherEdge) {
            this->src = otherEdge.getSource();
            this->dest = otherEdge.getDestination();
            this->weight = otherEdge.getWeight();
        }

    private:
        T src, dest;
        W weight;
};

template <typename T, typename W>
class Graph {
    public:
        Graph(bool directed) : directed(directed) {}

        void addNode(const T& data) {
            nodes.insert(data);
        }

        void displayNodes() {
            for (auto x : nodes) {
                std::cout << x << std::endl;
            }
        }

        void addEdge(const T& src, const T& dest, const W& weight = W()) {
            if (nodes.find(src) == nodes.end() || nodes.find(dest) == nodes.end()) {
                std::cerr << "Either the source " << src << " or the destination " << dest << " does not exist." << std::endl;
                return;
            }

            Edge<T, W> newEdge(src, dest, weight);
            if (!minEdge) {
                minEdge = newEdge;
            }
            else {
                if (newEdge.getWeight() < minEdge.getWeight()) {
                    minEdge = newEdge;
                }
            }

            edges[src].insert(std::make_pair(dest, newEdge));

            if (!directed) {
                Edge<T, W> newBackEdge(dest, src, weight);
                edges[dest].insert(std::make_pair(src, newBackEdge));
            }
        }

        void displayMinEdge() {
            std::cout << "Source: " << minEdge.getSource() << std::endl;
            std::cout << "Destination: " << minEdge.getDestination() << std::endl;
            std::cout << "Weight: " << minEdge.getWeight() << std::endl;
        }

        void displayEdges() {
            for (const auto& [src, edges_map] : edges) {
                std::cout << src << " --> ";
                for (const auto& [dest, edge] : edges_map) {
                    std::cout << dest << "(" << edge.getWeight() << ") ";
                }
                std::cout << std::endl;
            }
        }
        // bool hasCycle() const;

        // std::vector<int> nodeColoring() const;
        // std::vector<int> edgeColoring() const;
        // void completeEdges();
        // std::vector<std::vector<T>> connectedComponents() const;
        // std::vector<double> katzCentrality(double alpha, double beta) const;

        std::vector<Edge<T, W>> primMST() const {
            if (nodes.size() == 0 || edges.size() == 0) {
                std::cerr << "Either there are no nodes or no edges in the graph" << std::endl;
                exit(1);
            }

            std::unordered_map<T, bool> selected(nodes.size(), false);
            std::vector<Edge<T, W>> result;

            // Choosing the first node given by the nodes set
            typename std::unordered_set<T>::iterator v = nodes.begin();
            return result;
        }

        // std::vector<Edge<T, W>> kruskalMST() const;

        std::vector<T> iterativeDFS(const T& start) const {
            if (nodes.find(start) == nodes.end()) {
                std::cerr << "The source node doesn't exist in the graph" << std::endl;
                exit(1);
            }

            T node;
            std::stack<T> stk;
            std::unordered_map<T, bool> visited;
            std::vector<T> result;

            stk.push(start);
            while (!stk.empty()) {
                node = stk.top();
                stk.pop();

                if (!visited[node]) {
                    result.push_back(node);
                    visited[node] = true;
                }

                for (auto it = edges.at(node).rbegin(); it != edges.at(node).rend(); ++it) {
                    const auto& [dest, _] = *it;
                    if (!visited[dest]) {
                        stk.push(dest);
                    }
                }
            }
            return result;
        }
        // std::vector<T> uniformCostSearch(const T& start, const T& goal) const;
        // std::vector<T> aStarSearch(const T& start, const T& goal, std::function(T, T)> heuristic) const;
    
    private:
        bool directed;
        Edge<T, W> minEdge;
        std::unordered_set<T> nodes;
        std::unordered_map<T, std::map<T, Edge<T, W>>> edges;
};

int main() {
    Graph<int, int> g = Graph<int, int>(false);
    g.addNode(1);
    g.addNode(2);
    g.addNode(3);
    g.addNode(4);
    g.addNode(5);
    g.addNode(6);
    g.addNode(7);
    g.addNode(8);
    g.addNode(9);

    // std::cout << "The nodes in the graph are: " << std::endl;
    // g.displayNodes();

    g.displayMinEdge();
    g.addEdge(1, 2, 5);
    g.displayMinEdge();
    g.addEdge(1, 7, 1);
    g.displayMinEdge();
    g.addEdge(2, 3, 8);
    g.addEdge(2, 4, 9);
    g.addEdge(4, 5, 4);
    g.addEdge(5, 6, 3);
    g.addEdge(7, 8, 3);
    g.addEdge(7, 9, 1);

    std::cout << "Graph:" << std::endl;
    g.displayEdges();

    std::cout << "DFS: " << std::endl;
    std::vector<int> res = g.iterativeDFS(4);

    for (auto x : res) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
