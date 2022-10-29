class MyHashSet {
private:
    static int const hashSize = 37;
    set<int> hashSet[hashSize];
    
public:
    MyHashSet() {
        cout << "Initializing HashSet..." << endl;
    }
    
    int hashFunc(int key){
        return key % hashSize;
    }
    
    void add(int key) {
        int hashValue = hashFunc(key);
        bool keyExists = false;
        auto hashIter = hashSet[hashValue].begin();
        hashIter = hashSet[hashValue].find(key);
        
        if(hashIter != hashSet[hashValue].end()){
            return;
        }
        hashSet[hashValue].insert(key);
    }
    
    void remove(int key) {
        int hashValue = hashFunc(key);
        bool keyExists = false;
        auto hashIter = hashSet[hashValue].begin();
        hashIter = hashSet[hashValue].find(key);
        
        if(hashIter != hashSet[hashValue].end()){
            hashSet[hashValue].erase(key);
            return;
        }
    }
    
    bool contains(int key) {
        int hashValue = hashFunc(key);
        auto hashIter = hashSet[hashValue].begin();
        hashIter = hashSet[hashValue].find(key);
        
        if(hashIter != hashSet[hashValue].end()){
            return true;
        }
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