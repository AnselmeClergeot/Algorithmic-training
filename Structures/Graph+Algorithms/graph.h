#ifndef GRAPH_H
#define GRAPH_H
#include <list>
#include "node.h"

class Graph
{
public:
    Graph(const int size);

    void connect_undirected(const int lhs_index, const int rhs_index, const int edge_value);
    void connect_directed(const int lhs_index, const int rhs_index, const int edge_value);

    void depth_first_search(const int start_index);
    void breadth_first_search(const int start_index);

    void shortest_path_to_all_other(const int start_index);
    void shortest_path_to_node(const int start_index, const int end_index);

    void set_all_unvisited();

private :
    std::vector<Node> m_nodes_bag;

    int get_node_by_shortest(const std::list<int>& outside_nodes);




};

#endif // GRAPH_H
