#ifndef NODE_H
#define NODE_H
#include "edge.h"
#include <vector>

class Node
{
public:
    Node(const int index);

    void connect(const int index, const int edge_weight);

    int get_index() const;
    int get_previous_index() const;
    int get_shortest_from_start() const;

    void try_update_shortest(const int new_shortest);

    const std::vector<Edge> &get_edges();

    bool is_visited() const;

    void set_visited(const bool visited);

private :
    int m_index;
    int m_shortest_from_start;
    int m_previous_index;

    bool m_visited;

    std::vector<Edge> m_leaving_edges;
};

bool operator==(const Node &lhs, const Node &rhs);

#endif // NODE_H
