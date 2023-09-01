/*
  Approach :
  we have used maps to store key values and key iterators and list to store keys
  for every put operation , we are removing key from list and maps and inserting it into list front , map
  for every get operation we are taking key from list and append it to front
  if capacity excees then simply removes from back
  same key will be removeed from maps too
  TC => O(n)
  SC => O(1)
*/
class LRUCache {
public:
    unordered_map<int,int> m;
    list<int> l;
    unordered_map<int , list<int> :: iterator> addr;
    int cap;
    int size;
    LRUCache(int capacity) {
        cap = capacity;
        size =0;
    }
    
    int get(int key) {
        if(m.find(key) == m.end())return -1;
        auto itr = addr[key];
        l.erase(itr);
        addr.erase(key);
        l.push_front(key);
        addr[key] = l.begin();
        return m[key];
    }
    
    void put(int key, int value) 
    {
        if(m.find(key) != m.end())
        {
            auto itr = addr[key];
            l.erase(itr);
            addr.erase(key);
            m.erase(key);
            size--;
        }
        if(size == cap)
        {
            auto k = l.back();
            l.pop_back();
            m.erase(k);
            addr.erase(k);
            size--;
        }
        size++;
        l.push_front(key);
        addr[key] = l.begin();
        m[key] = value;

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */