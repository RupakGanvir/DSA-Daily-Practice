#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LFUCache
{
private:
    int capacity;
    int minFreq;
    unordered_map<int, pair<int, int>> keyToValFreq;
    unordered_map<int, list<int>> freqToList;
    unordered_map<int, list<int>::iterator> keyToIter;

    void updateFrequency(int key)
    {
        int freq = keyToValFreq[key].second;
        keyToValFreq[key].second++;

        freqToList[freq].erase(keyToIter[key]);
        freqToList[freq + 1].push_front(key);
        keyToIter[key] = freqToList[freq + 1].begin();

        if (freqToList[minFreq].empty())
        {
            freqToList.erase(minFreq);
            if (minFreq == freq)
            {
                minFreq++;
            }
        }
    }

public:
    LFUCache(int capacity)
    {
        this->capacity = capacity;
        this->minFreq = 0;
    }

    int get(int key)
    {
        if (keyToValFreq.find(key) == keyToValFreq.end())
        {
            return -1;
        }
        updateFrequency(key);
        return keyToValFreq[key].first;
    }

    void put(int key, int value)
    {
        if (capacity <= 0)
        {
            return;
        }

        if (keyToValFreq.find(key) != keyToValFreq.end())
        {
            keyToValFreq[key].first = value;
            updateFrequency(key);
            return;
        }

        if (keyToValFreq.size() >= capacity)
        {
            int evictKey = freqToList[minFreq].back();
            freqToList[minFreq].pop_back();
            keyToIter.erase(evictKey);
            keyToValFreq.erase(evictKey);
        }

        keyToValFreq[key] = {value, 1};
        freqToList[1].push_front(key);
        keyToIter[key] = freqToList[1].begin();
        minFreq = 1;
    }
};

int main()
{
    LFUCache *cache = new LFUCache(2);

    cache->put(1, 1);
    cache->put(2, 2);
    cout << "Get 1: " << cache->get(1) << endl;

    cache->put(3, 3);
    cout << "Get 2: " << cache->get(2) << endl;
    cout << "Get 3: " << cache->get(3) << endl;

    cache->put(4, 4);
    cout << "Get 1: " << cache->get(1) << endl;
    cout << "Get 3: " << cache->get(3) << endl;
    cout << "Get 4: " << cache->get(4) << endl;

    delete cache;
    return 0;
}