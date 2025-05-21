#include <iostream>
#include <algorithm>
#include <vector>
#include "SegmentTree.h"

using namespace std;

int main()
{
	vector<int> nums = {1, 2, 3, 4, 5, 6, 9, 3};
	SegmentTree st(nums);

	cout << "Test 1" << endl;
	/*
	getSum(0, 4) = 1 + 2 + 3 + 4 + 5 = 15
	getMin(0, 4) = 1
	getMin(2, 5) = 3
	getMax(5, 7) = 9
	*/
	cout << st.getSum(0, 4) << endl;
	cout << st.getMin(0, 4) << endl;
	cout << st.getMin(2, 5) << endl;
	cout << st.getMax(5, 7) << endl;



	cout << "\nTest 2" << endl;
	/*
	update(2, 228) => nums = {1, 2, 228, 4, 5, 6, 9, 3}
	update(4, 0) => nums = {1, 2, 228, 4, 0, 6, 9, 3}
	update(5, -2) => nums = {1, 2, 228, 4, 0, -2, 9, 3}
	update(7, 1000) => nums = {1, 2, 228, 4, 0, -2, 9, 1000}

	getSum(0, 4) = 1 + 2 + 228 + 4 + 0 = 235
	getMin(0, 4) = 0
	getMin(2, 5) = -2
	getMax(5, 7) = 1000
	*/
	st.update(2, 228);
	st.update(4, 0);
	st.update(5, -2);
	st.update(7, 1000);

	cout << st.getSum(0, 4) << endl;
	cout << st.getMin(0, 4) << endl;
	cout << st.getMin(2, 5) << endl;
	cout << st.getMax(5, 7) << endl;



	cout << "\nTest 3" << endl;
	vector<int> nums2 = { 1, 2, 3, 4 };
	SegmentTree st2(nums2);
	/*
	add(1, 17) => nums = {1, 17, 2, 3, 4}
	add(18) => nums = {1, 17, 2, 3, 4, 18}
	remove(2) => nums = {1, 17, 3, 4, 18}

	getSum(1, 3) = 24
	getMin(2, 4) = 3
	getMax(0, 4) = 18
	*/
	st2.add(1, 17);
	st2.add(18);
	st2.remove(2);

	cout << st2.getSum(1, 3) << endl;
	cout << st2.getMin(2, 3) << endl;
	cout << st2.getMax(0, 4) << endl;
}