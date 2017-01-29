
#ifndef _ABSHEAP_H_
#define _ABSHEAP_H_

#include <iostream>

using namespace std;

#define HEAPSIZE 500000

class Node {
    public:
        int key;
        char element;
};


class AbsHeap {

    public:
        AbsHeap() {
            ary = new Node [HEAPSIZE];
            size = 0;
        }

        ~AbsHeap() {
            delete[] ary;
        }

        // Remember to ++size
        virtual void push(int _key, char _element) = 0;

        // return the element with the minimum key, remember to --size
        virtual char pop() = 0;

        void printArray() const {
            cout << "(Index, Key, Element)" << endl;
            for (int i=0; i<size; i++)
                cout << "(" << i << "," << ary[i].key << "," << ary[i].element << ")" << endl;
        }

        void printByPopping() {
            while (!isEmpty())
                cout << pop();
            cout << endl;
        }

        bool isEmpty() const {
            return (size == 0);
        }

        void swap(int i, int j) {
            /*if (i>=size || j>=size)
                cout << "swap: " << i << "," << j << "," << size << endl;
                */
            Node temp = ary[i];
            ary[i] = ary[j];
            ary[j] = temp;
        }

        Node *ary;
        int size;

};

#endif
