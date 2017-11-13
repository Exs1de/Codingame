#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream> 
#include <cmath>    
#include <cassert>

using namespace std;

double getDistance(double x1, double y1, double x2, double y2); //returns distance between user and defibrillator
string getSegment(string str, int segment_num); //parse string on 6 segments (numeration [0 .. 5])
double convert(string str); //convert "," -> "." and apply  "/ 180 * M_PI"

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

//global variables to save some memory in the loops
vector<string> segments; //single DEFIB string
string segment; //segment of DEFIB string
double x = 0, y = 0; //varibles for getDistance() method

int main()
{
    string LON;
    cin >> LON; cin.ignore();
    string LAT;
    cin >> LAT; cin.ignore();
    int N;
    cin >> N; cin.ignore();
    
    double userLON, userLAT, defLON, defLAT;
    double D, minD = 99999; //D - distance between user and defibrillator
    string destination = "no defibrillator, time to die";
    
    userLON = convert(LON);
    userLAT = convert(LAT);
    
    for (int i = 0; i < N; i++) {
        string DEFIB;
        getline(cin, DEFIB);
        
        defLON = convert(getSegment(DEFIB, 4));
        defLAT = convert(getSegment(DEFIB, 5));
        
        D = getDistance(userLON, userLAT, defLON, defLAT);
        
        if(minD > D)
        {
            minD = D;
            destination = getSegment(DEFIB, 1);
        }
        //clear vector for next iteration
        segments.clear();
    }
    
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << destination << endl;
}

string getSegment(string str, int segment_num){  
    stringstream ss(str);
    while(getline(ss, segment, ';'))
    {
        segments.push_back(segment);
        cerr << segment << endl;
    }  
    return  segments[segment_num];
}

double convert(string str){
    replace(str.begin(), str.end(), ',', '.');
    return stod(str) / 180 * M_PI;
}

double getDistance(double userLON, double userLAT, double defLON, double defLAT){
    x = (defLON - userLON)*cos((defLAT + userLAT) / 2);
    y = (defLAT - userLAT);
    return sqrt(pow(x, 2) + pow(y, 2))*6371;
}
