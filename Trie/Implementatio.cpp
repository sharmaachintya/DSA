#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch)
        {
            data = ch;
            for (int i=0;i<26;i++)
            {
                children[i] = NULL;
            }
            isTerminal = false;
        }

};

class Trie{
    public:
        TrieNode*  root;

        Trie()
        {
            root = new TrieNode('\0');
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
            int index = word[0] - 'A';
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
                root->children[index] = child;
            }

            // Recursion
            insertUtil(child, word.substr(1));

        }

        void insertWord(string word)                                // INSERTION
        {
            insertUtil(root, word);
        }

        bool searchUtil(TrieNode* root, string word)
        {
            // Base Case
            if (word.length() == 0)
            {
                return root->isTerminal;
            }

            int index = word[0] - 'A';
            TrieNode* child;

            // Present
            if (root->children[index] != NULL)
            {
                child = root->children[index];
            }
            else
            {
                // Absent
                return false;
            }
            return searchUtil(child, word.substr(1));
        }

        bool searchWord(string word)                                    // SEARCHING
        {
            return searchUtil(root, word);
        }

        void removeUtil(TrieNode* root, string word)
        {
            // base case
            if (word.length() == 0)
            {
                root->isTerminal = false;
                return;
            }

            int index = word[0] - 'A';
            TrieNode* child;

            if (root->children[index] != NULL)
            {
                // Present
                child = root->children[index];
            }
            else
            {
                // Absent
                cout<<"Can't delete! "<<endl;
                return;
            }
            removeUtil(child, word.substr(1));

        }

        void removeWord(string word)                                     // DELETION    
        {
            return removeUtil(root, word);
        }


        bool prefixUtil(TrieNode* root, string prefix)
        {
            // base case
            if (prefix.length() == 0)
            {
                return true;
            }

            int index = prefix[0] - 'A';
            TrieNode* child;

            if (root->children[index] != NULL)
            {
                child = root->children[index];
            }
            else
            {
                return false;
            }
            return prefixUtil(child, prefix.substr(1));
        }

        bool startsWith(string prefix)                                 // PREFIX
        {
            return prefixUtil(root, prefix);
        }
};

int main()
{
    Trie *t = new Trie();
    t->insertWord("ARM");
    t->insertWord("DO");
    t->insertWord("ARMY");
    t->insertWord("TIME");

    cout<<"Present or Not: "<<t->searchWord("AR")<<endl;
    t->removeWord("ARM");
    cout<<"Present or Not: "<<t->searchWord("ARM")<<endl;

    cout<<"START WITH : "<<t->startsWith("A")<<endl;
    cout<<"STARTS WITH : "<<t->startsWith("ARS")<<endl;
}