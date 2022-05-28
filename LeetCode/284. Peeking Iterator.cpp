// 唯一需要注意的就是-1和size的比较，size()函数返回的是unsigned int

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
    int index = -1;
    vector<int> myNums;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    myNums = nums;
        index = -1;
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        cout << index << endl;
        if (index + 1 < myNums.size()) {
            return myNums[index + 1];
        }
        return 0;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    return myNums[++index];
	}
	
	bool hasNext() const {
	    return index + 1 < myNums.size();
	}
};