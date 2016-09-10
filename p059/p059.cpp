/*
* Project Euler Problem 59 => https://projecteuler.net/problem=59
* Kevin Kuehler
* https://github.com/kevinkuehler/Project-Euler
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cctype>
using namespace std;

char most_likely(unordered_map<int,int> & );
void find_frequency(vector<int> &, unordered_map<int,int>, int);
void table_top_three(unordered_map<int,int> &, int[3]);
int main() {

    /* Reads file into vector */
    ifstream file;
    file.open("p059_cipher.txt");
    string c;
    vector<int> cipher;
    while(getline(file,c,','))
        cipher.push_back(stoi(c));

    int size = cipher.size();

    /*
    * Create 3 frequency tables since key length is 3 (given).
    * All numbers are put into the frequency table that
    * corresponds to its key position.
    */
    unordered_map<int,int> freq[3];

    for(int i = 0; i < 3; i++)
        for(int j = i; j < size; j+=3)
            freq[i][cipher[j]]++;

    /*
    * Finds the most likely key part from each frequency table
    * and puts these values together in an array.
    * Then key is used to decrypt the text and sum ascii values.
    */
    int key[3];
    for(int i = 0; i < 3; i++)
        key[i] = most_likely(freq[i]);

    int sum = 0;
    for(int i = 0; i < size; i++)
        sum +=  cipher[i] ^ key[i % 3];

    cout << sum << endl;
    return 0;
}

// Finds the three numbers that occur most in the frequency table.
// These are all individually xor-ed with common English letters
// and punctuation. If the result of the xor is both lowercase
// and alphanumeric we add it as a potential key.
// The potential key with the highest frequency is returned.
char most_likely(unordered_map<int,int> & freq) {
    static char common[] = {'e', 't', 'a', 'o', 'i', 'n', ' ', 's', 'h', 'r', 'd', 'l', 'u'};

    int mf[3];
    table_top_three(freq,mf);

    int pot_keys[26] = { 0 };
    for(int i = 0; i < 3; i++) {
        for(int j = i; j < 13; j++) {
            char t = mf[i] ^ common[j];
            if(t > 96 && t < 123)
                pot_keys[t-'a']+=freq[mf[i]];
        }
     }

    char best_key;
    int max = -1;
    for(int i = 0; i < 26; i++) {
        if(pot_keys[i] > max)  {
            best_key = i + 'a';
            max = pot_keys[i];
        }
    }
    return best_key;
}

// Populates the array top with the keys that have the maximum value
// in the table. Index 0 holds the max key and index 2 holds the smallest.
// NOTE: adds the index -1 to the table.
void table_top_three(unordered_map<int,int> & table, int top[3]) {
    top[0] = top[1] = top[2] = -1;
    for(auto it = table.begin(); it != table.end(); it++) {
        if(it->second > table[top[0]]) {
            top[2] = top[1];
            top[1] = top[0];
            top[0] = it->first;
        }
        else if(it->second > table[top[1]]) {
            top[2] = top[1];
            top[1] = it->first;
        }
        else if(it->second > table[top[2]])
            top[2] = it->first;
    }
}
