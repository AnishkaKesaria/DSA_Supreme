#include <bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char d){
        this->data = d;
        for(int i=0; i<26; i++)
            children[i] = NULL;
        this->isTerminal = false;
    }
};

void insertWord(TrieNode* root, string word)
{
    cout<<"Inserting "<< word<<endl;

    if(word.length()==0)
    {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;
    //present
    if(root->children[index]!= NULL)
        child = root->children[index];
    else
    {
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    insertWord(child, word.substr(1)); 
}

bool searchWord(TrieNode* root, string word)
{
    //base case
    if(word.length()==0)
        return root->isTerminal;

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    if(root->children[index] != NULL)
    {
        child = root->children[index];
        
    }
    else
        return false;

    return searchWord(child, word.substr(1));
}

void deleteWord(TrieNode* root, string word)
{
    if(word.length()==0)
    {
        root->isTerminal = false;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;
    if(root->children[index]!=NULL)
        child = root->children[index];
    else
        return;
    
    deleteWord(child, word.substr(1));
}

int main()
{
    TrieNode* root = new TrieNode('-');
    insertWord(root, "coding");
    cout<<searchWord(root, "coding")<<endl;
    deleteWord(root, "coding");
    cout<<searchWord(root, "coding")<<endl;
    return 0;
}