#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;

string toLower(string str); //convert string to lowercase
string getEXT(string str);  //return extension if exists
vector<string> segments; //single strings with "filename" "..." ".extension"
string segment; //temp variable to push_back into segments

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
int main()
{
    int N; // Number of elements which make up the association table.
    cin >> N; cin.ignore();
    int Q; // Number Q of file names to be analyzed.
    cin >> Q; cin.ignore();
    
    cerr << "======MAP=====" << endl;
    map<string, string> MT_MAP;
    for (int i = 0; i < N; i++) {
        string EXT; // file extension
        string MT;  // MIME type.
        cin >> EXT >> MT; cin.ignore();
        MT_MAP.insert(pair<string, string>(toLower(EXT), MT));
        cerr << "EXT : " << EXT << "; MT : " << MT << endl;
    }

    cerr << "\n======FILENAMES=====" << endl;
    string files[Q];
    for (int i = 0; i < Q; i++) {
        string FNAME; // One file name per line.
        getline(cin, FNAME);
        files[i] = toLower(FNAME);
        cerr << FNAME << endl;
    }  
    
    cerr << "\n======OUTPUT======" << endl;  
    for(int i = 0; i < Q; i ++)
    {
        auto key_exists = MT_MAP.find(getEXT(files[i]));
        if(key_exists != MT_MAP.end()) //key exists
            cout << key_exists->second << endl;
        else //key doesn`t exist
            cout << "UNKNOWN" << endl;  
        segments.clear();
    }
    
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    // For each of the Q filenames, display on a line the corresponding MIME type. If there is no corresponding type, then display UNKNOWN.
    //cout << "UNKNOWN" << endl;
}

string getEXT(string str){  
    stringstream ss(str);
    if(str.back() == '.')return "UNKNOWN";
    while(getline(ss, segment, '.'))
    {
        segments.push_back(segment);
    }  
    if((segments.size() - 1) == 0)segments[segments.size() - 1] = "UNKNOWN";
    return  segments[segments.size() - 1];
}

string toLower(string str){
    transform(str.begin(), str.end(), str.begin(),::tolower);
    return str;
}
