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
    int nbFloors; // number of floors
    int width; // width of the area
    int nbRounds; // maximum number of rounds
    int exitFloor; // floor on which the exit is found
    int exitPos; // position of the exit on its floor
    int nbTotalClones; // number of generated clones
    int nbAdditionalElevators; // ignore (always zero)
    int nbElevators; // number of elevators
    cin >> nbFloors >> width >> nbRounds >> exitFloor >> exitPos >> nbTotalClones >> nbAdditionalElevators >> nbElevators; cin.ignore();
    int elevators[nbElevators];
    for (int i = 0; i < nbElevators; i++) {
        int elevatorFloor; // floor on which this elevator is found
        int elevatorPos; // position of the elevator on its floor
        cin >> elevatorFloor >> elevatorPos; cin.ignore();    
        elevators[elevatorFloor] = elevatorPos;
    }
    
    string action;
    int i = 0;
    // game loop
    while (1) {
        i++;
        action = "WAIT"; 
        int cloneFloor; // floor of the leading clone
        int clonePos; // position of the leading clone on its floor
        string direction; // direction of the leading clone: LEFT or RIGHT
        cin >> cloneFloor >> clonePos >> direction; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        
        if(cloneFloor != exitFloor)
        {
            if(clonePos > elevators[cloneFloor] && direction == "RIGHT")action = "BLOCK"; 
            if(clonePos < elevators[cloneFloor] && direction == "LEFT")action = "BLOCK"; 
        }
        else
        {   
            if(clonePos > exitPos && direction == "RIGHT")action = "BLOCK";
            if(clonePos < exitPos && direction == "LEFT")action = "BLOCK";
            cerr << "test" << endl;
        }
               
        cout << action << endl; // action: WAIT or BLOCK
    }
}
