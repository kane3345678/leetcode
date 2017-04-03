https://leetcode.com/problems/implement-queue-using-stacks/#/description
Implement Queue using Stacks
class MyQueue {
public:
    /** Initialize your data structure here. */
    vector<int> ans;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        ans.push_back(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int i =ans.front(); 
        ans.erase(ans.begin());
        return i;
    }
    
    /** Get the front element. */
    int peek() {
        return ans.front(); 
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return (ans.size()==0) ? true:false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */

