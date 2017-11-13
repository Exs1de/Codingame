#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <map>

using namespace std;

string remove_char(string str, string c); //remove used letters from list
int getScore(string c, map<int, string>score_table); //count score of given letter

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
    
int main()
{    
    //setup score_table
    map<int, string>score_table;
    score_table.insert(pair<int, string>(1, "e, a, i, o, n, r, t, l, s, u"));
    score_table.insert(pair<int, string>(2, "d, g"));
    score_table.insert(pair<int, string>(3, "b, c, m, p"));
    score_table.insert(pair<int, string>(4, "f, h, v, w, y"));
    score_table.insert(pair<int, string>(5, "k"));
    score_table.insert(pair<int, string>(8, "j, x"));
    score_table.insert(pair<int, string>(10, "q, z"));
    
    int N;  //number of words given
    cin >> N; cin.ignore();
    
    string word[N];
    for (int i = 0; i < N; i++) {
        string W;
        getline(cin, W);
        word[i] = W;
    }
    
    string LETTERS;
    getline(cin, LETTERS);
    
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    string temp, winner;
    string c;
    int score = 0, curr_score = 0;
    
    for(int i = 0; i < N; i++) //for each word given
    {   
        temp = LETTERS;
        curr_score = 0;
        for(int j = 0; j < word[i].length(); j++) //for each letter in the word
        {
            c = word[i].at(j); //c = letter on [j] index from the word
            if(temp.find(c) != string::npos) //if LETTERS contains this letter and it has not been already used
            {
                temp = remove_char(temp, c); //temp represents LETTERS for each iteration | if letter has been used, we delete it from temp
                curr_score += getScore(c, score_table); //count score for letter            
            }
            else break; //if LETTERS doesnt contain letter, take next word
            
            if(j == word[i].length() - 1) //if all letter has been checked
            {
                if(score < curr_score)
                {
                    score = curr_score; //update score
                    winner = word[i]; //update word with the biggest score
                }    
            }
        }
    }
    
    cout << winner << endl;
}

string remove_char(string str, string c){
    for(int i = 0; i < str.length(); i++){
        if(c.at(0) == str.at(i)){
            str.erase(i, 1); //delete 1 letter from str on positin [i]
            return str;
        }
    }
}

int getScore(string c, map<int, string>score_table){
    string temp;
    for (auto it = score_table.begin(); it != score_table.end(); ++it)
    {
        temp = it->second;
        if (temp.find(c) != string::npos) //if score_table map contain value of letter, return its KEY
        {
            return  it->first;
        }
    }
}
