#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * ---
 * Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
 **/
int main()
{
    int lightX; // the X position of the light of power
    int lightY; // the Y position of the light of power
    int initialTX; // Thor's starting X position
    int initialTY; // Thor's starting Y position
    cin >> lightX >> lightY >> initialTX >> initialTY; cin.ignore();

    int TX = initialTX;
    int TY = initialTY;
    int X = lightX;
    int Y = lightY;
    
    string dir;
    bool set_dir = false;
    
    // game loop
    while (1) {
        int remainingTurns; // The remaining amount of turns Thor can move. Do not remove this line.
        cin >> remainingTurns; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        dir = "";
        if(TY < Y){dir = "S"; TY++; set_dir = true;}
        if(TY > Y){dir = "N"; TY--; set_dir = true;}
        if(TX < X){dir += "E"; TX++; set_dir = true;}
        if(TX > X){dir += "W"; TX--; set_dir = true;}

        if(!set_dir){
            if(TY == Y){
                if(TX < X){dir = "E"; TX++;}
                if(TX > X){dir = "W"; TX--;}
            } 
            
            if(TX == X){
                if(TY < Y){dir = "S"; TY++;}
                if(TY > Y){dir = "N"; TY--;}  
            }
        }
        set_dir = false;
            
        cerr << TY << endl; 
        cout << dir << endl;
        
        
        
    }
}
