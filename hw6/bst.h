#ifndef _BST_H_
#define _BST_H_

#include <iostream>
using namespace std;

class Node {
    public:
        Node() { left = right = NULL;}
        Node(int val) { 
            left = right = NULL;
            data = val;
        }
        Node *left;
        Node *right;
        int data;
};

class BST {
    public:
        BST() { root = NULL; }

        ~BST() {
            if (root != NULL)
                release(root);
        }

        void postorder() const {
            if (root == NULL) 
                return;
            postorder(root);
            cout << endl;
        }


        void inorder() const {
            if (root == NULL) 
                return;
            inorder(root);
            cout << endl;
        }
    
        void insert(int val) {
            if (root == NULL) 
                root = new Node(val);
            else
                insert(root, val);
        }

	protected:

        // p cannot be NULL
        void release(Node* p) {
            if (p->left != NULL)
                release(p->left);
            if (p->right != NULL)
                release(p->right);
            delete p;
        }

		void postorder(Node* p) const {
            if (p->left != NULL)
                postorder(p->left);
            if (p->right != NULL)
                postorder(p->right);
            cout << p->data << " ";
        }
	
	    // p cannot be NULL
        void inorder(Node* p) const {
            if (p->left != NULL)
                inorder(p->left);
            cout << p->data << " ";
            if (p->right != NULL)
                inorder(p->right);
        }

        // p cannot be NULL
        void insert(Node* p, int val) {

            if (p->data > val) {
                // left
                if (p->left == NULL) 
                    p->left = new Node(val);
                else 
                    insert(p->left, val);
            }
            else {
                //right
                if (p->right == NULL) 
                    p->right = new Node(val);
                else 
                    insert(p->right, val);
            }
        }

        Node *root;
};

#endif