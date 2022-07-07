#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
        char data;
        int childCount;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch)
        {
            data = ch;
            for (int i=0;i<26;i++)
            {
                children[i] = NULL;
            }
            childCount = 0;
            isTerminal = false;
        }

};

class Trie{
    public:
        TrieNode*  root;

        Trie(char ch)
        {
            root = new TrieNode(ch);
        }

        void insertUtil(TrieNode* root, string word)
        {
            // base case
            if (word.length() == 0)
            {
                root->isTerminal = true;
                return;
            }

            // Assuming, word will be in upper case
            int index = word[0] - 'a';
            TrieNode* child;

            // Present
            if (root->children[index] != NULL)
            {
                child = root->children[index];
            }
            else
            {
                // Absent
                child = new TrieNode(word[0]);
                root->childCount++;
                root->children[index] = child;
            }

            // Recursion
            insertUtil(child, word.substr(1));

        }

        void insertWord(string word)                                // INSERTION
        {
            insertUtil(root, word);
        }

        void lcp(string str, string &ans)
        {
            for (int i=0;i<str.length();i++)
            {
                char ch = str[i];

                if (root->childCount == 1)
                {
                    ans.push_back(ch);
                    int index = ch - 'a';
                    root = root->children[index];
                }
                else
                {
                    break;
                }

                if (root->isTerminal)
                {
                    break;
                }
            }
        }


};

string longestCommonPrefix2(vector<string> &arr, int n)                    // APPROACH #1
{                                                                          // using Loops
    string ans = "";
    for (int i=0;i<arr[0].length();i++)
    {
        char ch = arr[0][i];

        bool match = true;

        for (int j=1;j<n;j++)
        {
            if (arr[j].size() < i || ch != arr[j][i])
            {
                match = false;
                break;
            }
        }
        if (match == false)
        {
            break;
        }
        else
        {
            ans.push_back(ch);
        }
    }
    return ans;
}



string longestCommonPrefix(vector<string> &arr, int n)          // APPROACH #2 
{                                                               // using TRIE
    Trie *t = new Trie('\0');

    // insert all strings in Trie

    for (int i=0;i<n;i++)
    {
        t->insertWord(arr[i]);
    }
    string first = arr[0];
    string ans = "";
    t->lcp(first, ans);
    return ans;
}

int main()
{
    vector<string> str = {"ninjas", "niju", "nideo"};
    int n = str.size();

    cout<<longestCommonPrefix(str, n)<<endl;
    cout<<longestCommonPrefix2(str, n);
}