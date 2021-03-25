//
// Created by Deepson Khadka on 3/23/21.
//

#ifndef CAPSTONE_PROJECT_DIJKSTRA_H
#define CAPSTONE_PROJECT_DIJKSTRA_H
#define V 9

class Dijkstra{
private:

public:
    int minDistance(int dist[], bool sptSet[]);
void dijkstra(int graph[V][V], int src);
    void printSolution(int dist[]);
};


#endif //CAPSTONE_PROJECT_DIJKSTRA_H
