class SmallestInfiniteSet {
public:
    set<int> st; //set have elements in sorted order-------
    SmallestInfiniteSet() {
        st.clear();
        for(int i=1; i<=1000; i++)  //constraints is given num<=1000, so we will not take more than that
            st.insert(i);   
    }
    
    int popSmallest() {
        int t = *st.begin();
        st.erase(st.begin());
        return t;   
    }
    
    void addBack(int num) {
        st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
