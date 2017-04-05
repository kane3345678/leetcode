Insert Delete GetRandom O(1)
https://leetcode.com/problems/insert-delete-getrandom-o1/#/description
class RandomizedSet {
public:
    vector<int> buf;
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (find(buf.begin(), buf.end(), val) == buf.end()){
            buf.push_back(val);
            return true;
        }
        else
            return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto i = find(buf.begin(), buf.end(), val);
        if (i == buf.end())
            return false;
        else if(buf.size() > 0)
            buf.erase(i);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if(buf.size() == 0)
            return -1;
        else if(buf.size() == 1)
            return buf[0];
        int r = rand() % (buf.size() - 1);
        
        //cout<<buf.begin()->second;
        
        return buf[r];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

