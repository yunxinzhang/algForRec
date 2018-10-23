/**
 *  * // This is the interface that allows for creating nested lists.
 *   * // You should not implement it, or speculate about its implementation
 *    * class NestedInteger {
 *     *   public:
 *      *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *       *     bool isInteger() const;
 *        *
 *         *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *          *     // The result is undefined if this NestedInteger holds a nested list
 *           *     int getInteger() const;
 *            *
 *             *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *              *     // The result is undefined if this NestedInteger holds a single integer
 *               *     const vector<NestedInteger> &getList() const;
 *                * };
 *                 */
class NestedIterator {
public:
	stack<vector<NestedInteger>::iterator> iter_end;
	stack<vector<NestedInteger>::iterator> iter_cur;
	NestedIterator(vector<NestedInteger> &nestedList) {
		iter_end.push(nestedList.end());
		iter_cur.push(nestedList.begin());
	}

	int next() {
		return (iter_cur.top()++)->getInteger();
	}

	bool hasNext() {
	while(iter_cur.empty()){
		if(iter_cur.top() != iter_end.top()){
			if(iter_cur.top()->isInteger()){
				return true;
			}else{
				iter_end.push(iter_cur.top()->getList().end());
				iter_cur.push(iter_cur.top()->getList().begin());
			}
		}else{
			iter_end.pop();
			iter_cur.pop();
			if (!iter_cur.empty())
				++iter_cur.top();
		}	        				    
	}
	return false;
	}
};

/**
 *  * Your NestedIterator object will be instantiated and called as such:
 *   * NestedIterator i(nestedList);
 *    * while (i.hasNext()) cout << i.next();
 *     */
