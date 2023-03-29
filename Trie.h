#include <bits/stdc++.h>
using namespace std;

class Trie
{
    struct TrieNode
    {
        map <char , TrieNode* > children;
        bool isEndOfWord;
        TrieNode()
        {
            isEndOfWord = false;
        }
        TrieNode(char c , bool end)
        {
            children[c] = new TrieNode();
            this->isEndOfWord = end;
        }
    };

    TrieNode *root = new TrieNode();
public:
    void insert(string word)
    {
        TrieNode *curr = root; 
        for(auto& c : word)
        {
            if(curr->children.find(c) == curr->children.end())
                curr->children[c] = new TrieNode();
            
            curr = curr->children[c];
        }
        curr->isEndOfWord = true;
    }

    void erase(string word)
    {
        eraseRecursive(word , root , 0);
    }

    void eraseRecursive(string word , TrieNode* curr , int idx)
    {
        if(idx == int(word.size()))
        {
            curr->isEndOfWord = false;
            return;
        }

        char c = word[idx];
        eraseRecursive(word , curr->children[c] , idx + 1);
        for(auto& [f , s] : curr->children) // f is the key and s is the trieNode pointer
        {
            if(s->isEndOfWord == false && s->children.empty())
            {
                delete s;
                curr->children.erase(f);
            }
        }
        if(curr->children.empty() && curr->isEndOfWord == false)
            delete curr;
    }

    bool search(string word)
    {
        TrieNode* curr = root;
        for(auto& c : word)
        {
            if(curr->children.find(c) == curr->children.end())
                return false;
            curr = curr->children[c];
        }
        return curr->isEndOfWord;
    }

    // Destructor

    void deleteRecursive(TrieNode* curr)
    {
        for(auto& [f , s] : curr->children)
            deleteRecursive(s);
        delete curr;
    }

    ~Trie()
    {
        // delete all the nodes
        deleteRecursive(root);
    }

};
