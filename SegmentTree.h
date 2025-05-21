#pragma once
#ifndef SEGMENTTREE_H
#define SEGMENTTREE_H

#include <vector>
using namespace std;

class SegmentTree {
private:
    int size;
    vector<int> array;
    vector<int> tree;
    vector<int> minTree;
    vector<int> maxTree;

    vector<int> fillTree();
    vector<int> fillMinTree();
    vector<int> fillMaxTree();

public:
    SegmentTree(vector<int> nums);

    void update(int index, int value);
    void add(int index, int value);
    void add(int value);
    void remove(int index);

    int getSum(int l, int r);
    int getMin(int l, int r);
    int getMax(int l, int r);

};
#endif // SEGMENTTREE_H