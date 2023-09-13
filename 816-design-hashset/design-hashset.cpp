class MyHashSet {
public:
    /*
        Approach :
        using linked list data structure (DLL) list - stl , we can store keys from the imput
        and we can manage the collisions too
    */
    vector<list<int>> v ;
    int size;
    MyHashSet() {
        size = 1000;
        v.resize(size);
    }
    // gives us the index with in the range we taken (size)
    int hash(int key)
    {
        return key%size;
    }
    // this will return iterator if element alredy present else it return end pointer
    list<int> :: iterator search(int key)
    {
        int i = hash(key);
        return  find(v[i].begin() , v[i].end() ,key);
    }
    // this function will check first key is present or not , if not, push it to it's corresponding index.
    void add(int key) 
    {
        if(contains(key)) return ;
        int i = hash(key);
        v[i].push_back(key);
    }
    // this function will check first key is there or not, if yes, then get it's iterator from search and erase it
    void remove(int key) 
    {
         if(!contains(key)) return ;
        int i = hash(key);
        v[i].erase(search(key));
    }
    // this function will check whether key is present in the list vector or not
    bool contains(int key) {
      int i = hash(key);
      if(search(key) != v[i].end()) return true;
      else
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */