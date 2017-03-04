#include "graph.h"
#include <cassert>
#include <list>
#include <iostream>
#include <limits>
#include <queue>

const int INFINITY { 99999 };

Graph::Graph(const int size) : m_nodes_bag()
{
    for(int i {0}; i < size; i++)
    {
        m_nodes_bag.push_back(Node(i));
    }
}

void Graph::connect_undirected(const int lhs_index, const int rhs_index, const int edge_value)
{
    assert(lhs_index < m_nodes_bag.size() && rhs_index < m_nodes_bag.size());

    m_nodes_bag[lhs_index].connect(rhs_index, edge_value);
    m_nodes_bag[rhs_index].connect(lhs_index, edge_value);
}

void Graph::connect_directed(const int lhs_index, const int rhs_index, const int edge_value)
{
    assert(lhs_index < m_nodes_bag.size() && rhs_index < m_nodes_bag.size());

    m_nodes_bag[lhs_index].connect(rhs_index, edge_value);
}

void Graph::shortest_path_to_all_other(const int start_index)
{
    m_nodes_bag[start_index].try_update_shortest(0);

    std::list<int> outside_nodes;

    for(int i {0}; i < m_nodes_bag.size(); i++)
    {
        outside_nodes.push_back(i);
    }

    while(!outside_nodes.empty())
    {
        Node current = m_nodes_bag[get_node_by_shortest(outside_nodes)];
        outside_nodes.remove(get_node_by_shortest(outside_nodes));

        for(Edge e : current.get_edges())
        {
            m_nodes_bag[e.get_next_index()].try_update_shortest(current.get_shortest_from_start() + e.get_weight());
        }
    }

    for(const Node n : m_nodes_bag)
    {
        std::cout << "Shortest path from " << start_index << " to " << n.get_index() << " is " << n.get_shortest_from_start() << std::endl;
    }

}

void Graph::shortest_path_to_node(const int start_index, const int end_index)
{
    m_nodes_bag[start_index].try_update_shortest(0);

    std::list<int> outside_nodes;

    for(int i {0}; i < m_nodes_bag.size(); i++)
    {
        outside_nodes.push_back(i);
    }

    while(!outside_nodes.empty())
    {
        Node current = m_nodes_bag[get_node_by_shortest(outside_nodes)];
        outside_nodes.remove(get_node_by_shortest(outside_nodes));

        for(Edge e : current.get_edges())
        {
            m_nodes_bag[e.get_next_index()].try_update_shortest(current.get_shortest_from_start() + e.get_weight());
        }

        if(current.get_index() == end_index)
            break;
    }
        std::cout << "Shortest path from " << start_index << " to " << end_index << " is " << m_nodes_bag[end_index].get_shortest_from_start() << std::endl;

}

int Graph::get_node_by_shortest(const std::list<int>& outside_nodes)
{
    int cur_min { INFINITY };
    int cur_min_index {0};

    for(int index : outside_nodes)
    {
        if(m_nodes_bag[index].get_shortest_from_start() < cur_min)
        {
            cur_min = m_nodes_bag[index].get_shortest_from_start();
            cur_min_index = index;
        }
    }



    return cur_min_index;
}

void Graph::depth_first_search(const int start_index)
{
    m_nodes_bag[start_index].set_visited(true);

    std::cout << start_index << ' ';

    for(const Edge e : m_nodes_bag[start_index].get_edges())
    {
        if(!m_nodes_bag[e.get_next_index()].is_visited())
            depth_first_search(e.get_next_index());
    }
}

void Graph::breadth_first_search(const int start_index)
{
    std::queue<Node *> to_visit;
    m_nodes_bag[start_index].set_visited(true);
    to_visit.push(&m_nodes_bag[start_index]);

    while(!to_visit.empty())
    {
        Node *current = to_visit.front();
        std::cout << current->get_index() << ' ';
        to_visit.pop();


        for(Edge e : current->get_edges())
        {
            if(!m_nodes_bag[e.get_next_index()].is_visited())
            {
                m_nodes_bag[e.get_next_index()].set_visited(true);
                to_visit.push(&m_nodes_bag[e.get_next_index()]);
            }

        }

    }
}

void Graph::set_all_unvisited()
{
    for(Node &n : m_nodes_bag)
    {
        n.set_visited(false);
    }
}
