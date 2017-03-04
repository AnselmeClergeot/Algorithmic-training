#include "node.h"
#include <limits>

const int INFINITY { 100 };
const int UNDEFINED { -1 };

Node::Node(const int index) : m_index { index }, m_shortest_from_start { INFINITY }, m_previous_index { UNDEFINED }, m_leaving_edges {}, m_visited {false}
{

}

bool Node::is_visited() const
{
    return m_visited;
}

void Node::set_visited(const bool visited)
{
    m_visited = visited;
}

void Node::connect(const int index, const int edge_weight)
{
    m_leaving_edges.push_back(Edge(index, edge_weight));
}

int Node::get_index() const
{
    return m_index;
}

int Node::get_previous_index() const
{
    return m_previous_index;
}

int Node::get_shortest_from_start() const
{
    return m_shortest_from_start;
}

void Node::try_update_shortest(const int new_shortest)
{
    if(m_shortest_from_start > new_shortest)
        m_shortest_from_start = new_shortest;
}

const std::vector<Edge> &Node::get_edges()
{
    return m_leaving_edges;
}

bool operator==(const Node &lhs, const Node &rhs)
{
    return lhs.get_index() == rhs.get_index();
}
