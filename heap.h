//
// Created by Manju Muralidharan on 10/19/25.
// Modified by Chris Palomares on 10/24/25
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // insert index at end of heap, restore order using upheap()
        data[size] = idx;
        size++;

        // Restore heap property by bubbling up
        upheap(size - 1, weightArr);
    }

    int pop(int weightArr[]) {
        // Replace root with last element, then call downheap()
        if (size == 0)
            return -1;

        int rootElement = data[0];      // store root element
        data[0] = data[size - 1];       // Move last element to the root
        size--;                         // Reduce heap size
        downheap(0, weightArr);     // Restore heap order
        return rootElement;             // Return smallest index
    }

    void upheap(int pos, int weightArr[]) {
        // Swap child upward while smaller than parent
        while (pos > 0) {
            int parent = (pos - 1) / 2;
            if (weightArr[data[pos]] > weightArr[data[parent]]) {

                //swap
                int temp = data[pos];
                data[pos] = data[parent];
                data[parent] = temp;
                pos = parent;
            } else {
                break;
            }
        }
    }

    void downheap(int pos, int weightArr[]) {
        // swap parent downward while larger than any child
        while (true) {
            int left = 2 * pos + 1;
            int right = 2 * pos + 2;
            int smallest = pos;

            // compare parent with left child
            if (left < size && weightArr[data[left]] < weightArr[data[smallest]]) {
                smallest = left;
            }

            // compare parent with right child
            if (right < size && weightArr[data[right]] < weightArr[data[smallest]]) {
                smallest = right;
            }

            // stop if parent is already smallest
            if (smallest == pos) {
                break;
            }

            // Swap parent and smaller child
            int temp = data[pos];
            data[pos] = data[smallest];
            data[smallest] = temp;

            // Continue down the tree
            pos = smallest;
        }
    }
};

#endif