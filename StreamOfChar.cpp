#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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

class StreamChecker
{
private:
    TrieNode *root;
    string streamHistory;
    int maxLength;

public:
    StreamChecker(vector<string> &words)
    {
        root = new TrieNode();
        maxLength = 0;

        for (const string &word : words)
        {
            maxLength = max(maxLength, (int)word.length());
            TrieNode *currentNode = root;

            for (int i = word.length() - 1; i >= 0; i--)
            {
                int index = word[i] - 'a';
                if (currentNode->children[index] == nullptr)
                {
                    currentNode->children[index] = new TrieNode();
                }
                currentNode = currentNode->children[index];
            }
            currentNode->isEndOfWord = true;
        }
    }

    bool query(char letter)
    {
        streamHistory += letter;
        if (streamHistory.length() > maxLength)
        {
            streamHistory.erase(streamHistory.begin());
        }

        TrieNode *currentNode = root;
        for (int i = streamHistory.length() - 1; i >= 0; i--)
        {
            int index = streamHistory[i] - 'a';
            if (currentNode->children[index] == nullptr)
            {
                return false;
            }
            currentNode = currentNode->children[index];
            if (currentNode->isEndOfWord)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    vector<string> words1 = {"cd", "f", "kl"};
    StreamChecker checker1(words1);

    cout << (checker1.query('a') ? "true" : "false") << " ";
    cout << (checker1.query('b') ? "true" : "false") << " ";
    cout << (checker1.query('c') ? "true" : "false") << " ";
    cout << (checker1.query('d') ? "true" : "false") << " ";
    cout << (checker1.query('e') ? "true" : "false") << " ";
    cout << (checker1.query('f') ? "true" : "false") << " ";
    cout << (checker1.query('g') ? "true" : "false") << " ";
    cout << (checker1.query('h') ? "true" : "false") << " ";
    cout << (checker1.query('i') ? "true" : "false") << " ";
    cout << (checker1.query('j') ? "true" : "false") << " ";
    cout << (checker1.query('k') ? "true" : "false") << " ";
    cout << (checker1.query('l') ? "true" : "false") << "\n";

    vector<string> words2 = {"ab", "ba", "aaab", "abab", "baa"};
    StreamChecker checker2(words2);

    cout << (checker2.query('a') ? "true" : "false") << " ";
    cout << (checker2.query('a') ? "true" : "false") << " ";
    cout << (checker2.query('a') ? "true" : "false") << " ";
    cout << (checker2.query('b') ? "true" : "false") << " ";
    cout << (checker2.query('a') ? "true" : "false") << " ";
    cout << (checker2.query('b') ? "true" : "false") << " ";
    cout << (checker2.query('a') ? "true" : "false") << " ";
    cout << (checker2.query('b') ? "true" : "false") << " ";
    cout << (checker2.query('a') ? "true" : "false") << " ";
    cout << (checker2.query('a') ? "true" : "false") << "\n";

    vector<string> words3 = {"hello", "world"};
    StreamChecker checker3(words3);

    cout << (checker3.query('h') ? "true" : "false") << " ";
    cout << (checker3.query('e') ? "true" : "false") << " ";
    cout << (checker3.query('l') ? "true" : "false") << " ";
    cout << (checker3.query('l') ? "true" : "false") << " ";
    cout << (checker3.query('o') ? "true" : "false") << " ";
    cout << (checker3.query('w') ? "true" : "false") << " ";
    cout << (checker3.query('o') ? "true" : "false") << " ";
    cout << (checker3.query('r') ? "true" : "false") << " ";
    cout << (checker3.query('l') ? "true" : "false") << " ";
    cout << (checker3.query('d') ? "true" : "false") << "\n";

    return 0;
}