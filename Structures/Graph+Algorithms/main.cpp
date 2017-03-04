#include <iostream>
#include "graph.h"

using namespace std;

int main()
{
    Graph G(7);

    G.connect_directed(0, 1, 0);
    G.connect_directed(0, 2, 0);
    G.connect_directed(0, 4, 0);
    G.connect_directed(0, 1, 0);
    G.connect_directed(1, 3, 0);
    G.connect_directed(1, 5, 0);
    G.connect_directed(2, 6, 0);
    G.connect_directed(4, 5, 0);

    G.depth_first_search(0);
    std::cout << std::endl;

    G.set_all_unvisited();

    G.breadth_first_search(0);


    return 0;
}
