#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    // Creation
    unordered_map<string, int> m;

    // Insertion
    pair<string, int> p = make_pair("babbar", 3);
    m.insert(p);

    pair<string, int> p2("love", 1);
    m.insert(p2);

    m["mera"] = 1;

    m["mera"] = 2;   // This will update the value of "mera" from 1 to 2

    //Searching
    cout<<m["mera"]<<endl;
    cout<<m.at("babbar")<<endl;

    //cout<<m.at("heinJi")<<endl;   // Gives error
    cout<<m["heinJi"]<<endl;      // will return 0 and create a new entry with key "heinjI"

    // Size
    cout<<"SIZE: "<<m.size()<<endl;

    // To check Presence
    cout<<m.count("love")<<endl;

    // Erase 
    //m.erase("love");
    cout<<"SIZE: "<<m.size()<<endl;


    // Iterator
    unordered_map <string, int> :: iterator it = m.begin();
    while (it != m.end())
    {
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }
}