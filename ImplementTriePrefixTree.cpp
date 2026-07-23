#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TrieNode
{
public:
    TrieNode *children[26];
    bool isEndOfWord;

    TrieNode()
    {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *currentNode = root;
        for (char character : word)
        {
            int index = character - 'a';
            if (currentNode->children[index] == nullptr)
            {
                currentNode->children[index] = new TrieNode();
            }
            currentNode = currentNode->children[index];
        }
        currentNode->isEndOfWord = true;
    }

    bool search(string word)
    {
        TrieNode *currentNode = root;
        for (char character : word)
        {
            int index = character - 'a';
            if (currentNode->children[index] == nullptr)
            {
                return false;
            }
            currentNode = currentNode->children[index];
        }
        return currentNode->isEndOfWord;
    }

    bool startsWith(string prefix)
    {
        TrieNode *currentNode = root;
        for (char character : prefix)
        {
            int index = character - 'a';
            if (currentNode->children[index] == nullptr)
            {
                return false;
            }
            currentNode = currentNode->children[index];
        }
        return true;
    }
};

int main()
{
    Trie prefixTree;

    prefixTree.insert("apple");
    cout << (prefixTree.search("apple") ? "true" : "false") << "\n";
    cout << (prefixTree.search("app") ? "true" : "false") << "\n";
    cout << (prefixTree.startsWith("app") ? "true" : "false") << "\n";

    prefixTree.insert("app");
    cout << (prefixTree.search("app") ? "true" : "false") << "\n";

    Trie anotherTree;
    anotherTree.insert("hello");
    anotherTree.insert("helloworld");

    cout << (anotherTree.search("hello") ? "true" : "false") << "\n";
    cout << (anotherTree.search("h") ? "true" : "false") << "\n";
    cout << (anotherTree.startsWith("hell") ? "true" : "false") << "\n";
    cout << (anotherTree.startsWith("world") ? "true" : "false") << "\n";

    return 0;
}