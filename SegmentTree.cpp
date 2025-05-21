#include "SegmentTree.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

SegmentTree::SegmentTree(vector<int> nums) {
    array = nums;
    tree = fillTree();
    minTree = fillMinTree();
    maxTree = fillMaxTree();
    size = tree.size();
}

void SegmentTree::update(int index, int value) {
    int pos = size / 2 + index;
    tree[pos] = value;
    minTree[pos] = value;
    maxTree[pos] = value;
    for (int i = pos / 2; i > 0; i /= 2) {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
        minTree[i] = min(minTree[i * 2], minTree[i * 2 + 1]);
        maxTree[i] = max(maxTree[i * 2], maxTree[i * 2 + 1]);
    }
}

void SegmentTree::add(int index, int value) {
    vector<int> newArray(array.size() + 1);
    for (int i = 0; i < index; i++)
    {
        newArray[i] = array[i];
    }
    newArray[index] = value;
    for (int i = index; i < array.size(); i++)
    {
        newArray[i + 1] = array[i];
    }
    array = newArray;
    tree = fillTree();
    minTree = fillMinTree();
    maxTree = fillMaxTree();
    size = tree.size();
}

void SegmentTree::add(int value) {
    add(array.size(), value);
}

void SegmentTree::remove(int index) {
    vector<int> newArray(array.size() - 1);
    for (int i = 0; i < index; ++i) newArray[i] = array[i];
    for (int i = index; i < array.size() - 1; ++i) newArray[i] = array[i + 1];
    array = newArray;
    tree = fillTree();
    minTree = fillMinTree();
    maxTree = fillMaxTree();
    size = tree.size();
}

int SegmentTree::getSum(int l, int r) {
    int res = 0;
    l = size / 2 + l;
    r = size / 2 + r;
    while (l <= r) {
        if (l % 2 == 1) res += tree[l++];
        if (r % 2 == 0) res += tree[r--];
        l /= 2;
        r /= 2;
    }
    return res;
}

int SegmentTree::getMin(int l, int r) {
    int m = INT32_MAX;
    l = size / 2 + l;
    r = size / 2 + r;
    while (l <= r) {
        if (l % 2 == 1) m = min(minTree[l++], m);
        if (r % 2 == 0) m = min(minTree[r--], m);
        l /= 2;
        r /= 2;
    }
    return m;
}

int SegmentTree::getMax(int l, int r) {
    int m = INT32_MIN;
    l = size / 2 + l;
    r = size / 2 + r;
    while (l <= r) {
        if (l % 2 == 1) m = max(maxTree[l++], m);
        if (r % 2 == 0) m = max(maxTree[r--], m);
        l /= 2;
        r /= 2;
    }
    return m;
}

vector<int> SegmentTree::fillTree() {
    tree = vector<int>(2 * array.size());
    int k = 0;
    for (int i = tree.size() / 2; i < tree.size(); ++i) {
        tree[i] = array[k++];
    }
    for (int i = tree.size() / 2 - 1; i > 0; --i) {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
    return tree;
}

vector<int> SegmentTree::fillMinTree() {
    minTree = vector<int>(2 * array.size());
    int k = 0;
    for (int i = minTree.size() / 2; i < minTree.size(); ++i) {
        minTree[i] = array[k++];
    }
    for (int i = minTree.size() / 2 - 1; i > 0; --i) {
        minTree[i] = min(minTree[i * 2], minTree[i * 2 + 1]);
    }
    return minTree;
}

vector<int> SegmentTree::fillMaxTree() {
    maxTree = vector<int>(2 * array.size());
    int k = 0;
    for (int i = maxTree.size() / 2; i < maxTree.size(); ++i) {
        maxTree[i] = array[k++];
    }
    for (int i = maxTree.size() / 2 - 1; i > 0; --i) {
        maxTree[i] = max(maxTree[i * 2], maxTree[i * 2 + 1]);
    }
    return maxTree;
}
