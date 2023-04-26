#include <iostream>
#include <unordered_set>
#include <unordered_map>

template <typename T, typename W>
class Edge {
    public:
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
            edges[src].insert(std::make_pair(dest, newEdge));

            if (!directed) {
                Edge<T, W> newBackEdge(dest, src, weight);
                edges[dest].insert(std::make_pair(src, newBackEdge));
            }
        }

        void displayEdges() {
            for (auto& [src, edges_map] : edges) {
                for (auto& [dest, edge] : edges_map) {
                    std::cout << src << " --> " << dest << " W: " << edge.getWeight() << std::endl;
                }
            }
        }
        // bool hasCycle() const;

        // std::vector<int> nodeColoring() const;
        // std::vector<int> edgeColoring() const;
        // void completeEdges();
        // std::vector<std::vector<T>> connectedComponents() const;
        // std::vector<double> katzCentrality(double alpha, double beta) const;
        // std::vector<Edge<T, W>> primMST() const;
        // std::vector<Edge<T, W>> kruskalMST() const;
        // std::vector<T> iterativeDFS(const T& start) const;
        // std::vector<T> uniformCostSearch(const T& start, const T& goal) const;
        // std::vector<T> aStarSearch(const T& start, const T& goal, std::function(T, T)> heuristic) const;
    
    private:
        bool directed;
        std::unordered_set<T> nodes;
        std::unordered_map<T, std::unordered_map<T, Edge<T, W>>> edges;
};

int main() {
    Graph<int, int> g = Graph<int, int>(false);
    g.addNode(1);
    g.addNode(2);

    std::cout << "The nodes in the graph are: " << std::endl;
    g.displayNodes();

    std::cout << "Graph:" << std::endl;
    g.addEdge(1, 2);
    g.displayEdges();
}
