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
    int n;
    cin >> n; cin.ignore();
    
    int lowest = 0;
    int biggest = 0;
    int loss = 0;
    
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v; cin.ignore();
        
        if(v >= biggest)biggest = v;
        else{
            lowest = v;
            if(lowest - biggest < loss)loss = lowest - biggest;
        }
    }
     
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;  
    
    cout << loss << endl;
}
