#include "graph.h"
#include <iostream>
#include <algorithm>
#include <cassert>

const int UNDEFINED { -1 };

Graph::Graph(const unsigned int size) : m_nodes_number {size}, m_edges {}
{

}

void Graph::connect(const int lhs_index, const int rhs_index, const int edge_weight)
{
    m_edges.push_back(Edge(lhs_index, rhs_index, edge_weight));
    m_edges.push_back(Edge(rhs_index, lhs_index, edge_weight));
}

void Graph::prim_algorithm()
{
    std::vector<int> visited_nodes {};
    std::vector<Edge> mst {};

    visited_nodes.push_back(0);

    while(visited_nodes.size() != m_nodes_number)
    {
        Edge to_add(get_minimum_connection(visited_nodes));
        visited_nodes.push_back(to_add.get_next_index());
        mst.push_back(to_add);
    }

    int total_cost {0};

    std::cout << "Minimum spanning tree contains :" << std::endl;

    for(Edge e : mst)
    {
        std::cout << e;
        total_cost+=e.get_weight();
    }

    std::cout << "Total cost of MST is " << total_cost;
}

Edge Graph::get_minimum_connection(const std::vector<int> &visited) const
{
    Edge min_edge(UNDEFINED, UNDEFINED, INFINITY) ;

    for(const Edge &e : m_edges)
    {
        for(const int& n : visited)
        {
            if(e.get_previous_index() == n && e.get_weight() <= min_edge.get_weight() && std::find(visited.begin(), visited.end(), e.get_next_index()) == visited.end())
            {
                min_edge = e;
            }
        }
    }

    return min_edge;
}
