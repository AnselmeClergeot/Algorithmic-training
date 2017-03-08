#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <set>
#include "edge.h"

class Graph
{
public:
    Graph(const unsigned int size);

    void connect(const int lhs_index, const int rhs_index, const int edge_weight);

    void prim_algorithm();



private:
    std::vector<Edge> m_edges;
    unsigned int m_nodes_number;

    Edge get_minimum_connection(const std::set<int> &visited) const;
};

#endif // GRAPH_H
