import graphlib

g = graphlib.Graph(False)

# g.addNode("A")
# g.addNode("B")
# g.addNode("C")

# g.displayNodes()

# g.addEdge("A", "B", 1)
# g.addEdge("B", "C", 2)

# g.displayEdges()

g.addNode(1)
g.addNode(2)
g.addNode(3)
g.addNode(4)
g.addNode(5)
g.addNode(6)
g.addNode(7)
g.addNode(8)
g.addNode(9)

g.addEdge(1, 2, 2)
g.addEdge(1, 7, 2)
g.addEdge(2, 3, 2)
g.addEdge(2, 4, 2)
g.addEdge(4, 5, 2)
g.addEdge(5, 6, 2)
g.addEdge(7, 8, 2)
g.addEdge(7, 9, 2)

g.displayEdges()

res = g.iterativeDFS(3)
print(res)
