#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
int main()
{
    int N; // the total number of nodes in the level, including the gateways
    int L; // the number of links
    int E; // the number of exit gateways
    cin >> N >> L >> E; cin.ignore();
    
    //info output
    cerr << "Nodes: " << N << endl;
    cerr << "Links: " << L << endl;
    
    int graph[N][N] = {}; //the matrix, which represents graph
   
    for (int i = 0; i < L; i++) {
        int N1; // N1 and N2 defines a link between these nodes
        int N2;
        cin >> N1 >> N2; cin.ignore();
        graph[N1][N2] = 1;
        graph[N2][N1] = 1;
    }
    
    vector<int> exitNode; //vector of all exit nodes
    for (int i = 0; i < E; i++) {
        int EI; // the index of a gateway node
        cin >> EI; cin.ignore();
        exitNode.push_back( EI );
        cerr << "ExitNode: " << EI << endl;
    }
    
    //our graph in matrix view
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            cerr << graph[i][j] << "";
        cerr << endl;
    } 

    // game loop
    int a, b;
    while (1) {
        int SI; // The index of the node on which the Skynet agent is positioned this turn
        cin >> SI; cin.ignore();
        cerr << "SkyNetNode: " << SI << endl;
        
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        
        for(int j = 0; j < N; ++j)
            if(graph[SI][j] == 1)
            {
                a = SI;
                b = j;
                if (find(exitNode.begin(), exitNode.end(), j) != exitNode.end())break;
            }
            
        cout << a << " " << b << endl;
    }
}
