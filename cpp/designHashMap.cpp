class MyHashMap {
private:
    static const int hashSize = 100000;
    map<int, int> hashMap;
public:
    
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        int index = key % hashSize;
        auto hashIter = hashMap.begin();
        bool exists = false;
        hashIter = hashMap.find(key);
        if(hashIter != hashMap.end()){
            cout << "[WARNING] key found. UPDATING value" << endl;
            hashIter->second = value;
            return;
        }
        cout << "[INFO] key not found. INSERTING value" << endl;
        hashMap.insert(pair<int,int> (key, value));
    }
    
    int get(int key) {
        int index = key % hashSize;
        auto hashIter = hashMap.begin();
        bool exists = false;
        hashIter = hashMap.find(key);
        if(hashIter != hashMap.end()){
            cout << "[INFO] key found. Input: "<< key <<", Key [" 
                 << hashIter->first << "] Value: [" << hashIter->second  << "]" << endl;
            return hashIter->second;
        }
        else{
            cout << "[WARNING] key not found" << endl;
            return -1;
        }
    }
    
    void remove(int key) {
        int index = key % hashSize;
        auto hashIter = hashMap.begin();
        bool exists = false;
        hashIter = hashMap.find(key);
        if(hashIter != hashMap.end()){
            cout << "[INFO] key found. REMOVING value" << endl;
            hashMap.erase(key);
            return;
        }
        cout << "[WARNING] key not found" << endl;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
