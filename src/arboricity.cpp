#include <stdio.h>
#include <stdlib.h>
#include "arboricity.h"
#include "dynamic_edge_orientation.h"

int arboricity(std::string filename)
{
        EdgeSequence sequence;
        NodeID n = graph_io::readSequence(sequence, filename);
        NodeID m = sequence.size();
        
        UndirectedGraph* g = new UndirectedGraph(n, m);
        for (size_t i = 0; i < m; ++i) {
                g->AddEdge(sequence[i].source, sequence[i].target, 1);
        }
        
        int forest_num = g->Solve();
        
        delete g;
        
        return forest_num;
}


int main(int argc, char ** argv) {
        std::string filename;
        
        if (argc >= 2) {
                filename = argv[1];
        } else {
                std::cerr << "no input passed." << std::endl;
                return 1;
        }
        
        std::cout << arboricity(filename) << std::endl;
}
