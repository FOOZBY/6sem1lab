#include "Header.h"
using namespace std;

class RBT : public Tree
{
    Node* TNULL;

    void insertFix(Node* k) 
    {
        Node* u;
        while (k->parent->color == 1) 
        {
            if (k->parent == k->parent->parent->right) 
            {
                u = k->parent->parent->left;
                if (u->color == 1) 
                {
                    u->color = 0;
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    k = k->parent->parent;
                }
                else 
                {
                    if (k == k->parent->left) 
                    {
                        k = k->parent;
                        rightRotate(k);
                    }
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    leftRotate(k->parent->parent);
                }
            }
            else 
            {
                u = k->parent->parent->right;

                if (u->color == 1) 
                {
                    u->color = 0;
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    k = k->parent->parent;
                }
                else 
                {
                    if (k == k->parent->right) 
                    {
                        k = k->parent;
                        leftRotate(k);
                    }
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    rightRotate(k->parent->parent);
                }
            }
            if (k == root) 
            {
                break;
            }
        }
        root->color = 0;
    }

    void leftRotate(Node* x)
    {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != TNULL)
        {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr)
        {
            this->root = y;
        }
        else if (x == x->parent->left)
        {
            x->parent->left = y;
        }
        else
        {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    void rightRotate(Node* x)
    {
        Node* y = x->left;
        x->left = y->right;
        if (y->right != TNULL)
        {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr)
        {
            this->root = y;
        }
        else if (x == x->parent->right)
        {
            x->parent->right = y;
        }
        else
        {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }

    Node* minimum(Node* NodeRBT) 
    {
        while (NodeRBT->left != TNULL) 
        {
            NodeRBT = NodeRBT->left;
        }
        return NodeRBT;
    }

    void deleteFix(Node* x) 
    {
        Node* s;
        while (x != root && x->color == 0) 
        {
            if (x == x->parent->left) 
            {
                s = x->parent->right;
                if (s->color == 1) 
                {
                    s->color = 0;
                    x->parent->color = 1;
                    leftRotate(x->parent);
                    s = x->parent->right;
                }

                if (s->left->color == 0 && s->right->color == 0) 
                {
                    s->color = 1;
                    x = x->parent;
                }
                else {
                    if (s->right->color == 0) 
                    {
                        s->left->color = 0;
                        s->color = 1;
                        rightRotate(s);
                        s = x->parent->right;
                    }

                    s->color = x->parent->color;
                    x->parent->color = 0;
                    s->right->color = 0;
                    leftRotate(x->parent);
                    x = root;
                }
            }
            else 
            {
                s = x->parent->left;
                if (s->color == 1) 
                {
                    s->color = 0;
                    x->parent->color = 1;
                    rightRotate(x->parent);
                    s = x->parent->left;
                }

                if (s->right->color == 0 && s->left->color == 0) 
                {
                    s->color = 1;
                    x = x->parent;
                }
                else 
                {
                    if (s->left->color == 0) 
                    {
                        s->right->color = 0;
                        s->color = 1;
                        leftRotate(s);
                        s = x->parent->left;
                    }

                    s->color = x->parent->color;
                    x->parent->color = 0;
                    s->left->color = 0;
                    rightRotate(x->parent);
                    x = root;
                }
            }
        }
        x->color = 0;
    }

    void rbTransplant(Node* u, Node* v) 
    {
        if (u->parent == nullptr) 
        {
            root = v;
        }
        else if (u == u->parent->left) 
        {
            u->parent->left = v;
        }
        else 
        {
            u->parent->right = v;
        }
        v->parent = u->parent;
    }

    void deleteNodeRBTHelper(Node* NodeRBT, int data) 
    {
        Node* z = TNULL;
        Node* x,* y;
        while (NodeRBT != TNULL) 
        {
            if (NodeRBT->data == data) 
            {
                z = NodeRBT;
            }

            if (NodeRBT->data <= data) 
            {
                NodeRBT = NodeRBT->right;
            }
            else 
            {
                NodeRBT = NodeRBT->left;
            }
        }

        if (z == TNULL) 
        {
            cout << "data not found in the tree" << endl;
            return;
        }

        y = z;
        int y_original_color = y->color;
        if (z->left == TNULL) 
        {
            x = z->right;
            rbTransplant(z, z->right);
        }
        else if (z->right == TNULL) 
        {
            x = z->left;
            rbTransplant(z, z->left);
        }
        else 
        {
            y = minimum(z->right);
            y_original_color = y->color;
            x = y->right;
            if (y->parent == z) 
            {
                x->parent = y;
            }
            else
            {
                rbTransplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }

            rbTransplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        delete z;
        if (y_original_color == 0) 
        {
            deleteFix(x);
        }
    }

    void del(Node* curr)
    {

        if (curr && curr != TNULL)
        {
            del(curr->left);
            del(curr->right);
            delete curr;
        }
    }

public:
    RBT() 
    {
        TNULL = new Node(-1);
        TNULL->color = 0;
        TNULL->left = nullptr;
        TNULL->right = nullptr;
        root = TNULL;
    }
   
    void insert(int data) 
    {
        Node* node = new Node(data);
        node->parent = nullptr;
        node->data = data;
        node->left = TNULL;
        node->right = TNULL;
        node->color = 1;

        Node* y = nullptr;
        Node* x = this->root;

        while (x != TNULL) 
        {
            y = x;
            if (node->data < x->data) 
            {
                x = x->left;
            }
            else 
            {
                x = x->right;
            }
        }

        node->parent = y;
        if (y == nullptr) 
        {
            root = node;
        }
        else if (node->data < y->data) 
        {
            y->left = node;
        }
        else 
        {
            y->right = node;
        }

        if (node->parent == nullptr) 
        {
            node->color = 0;
            return;
        }

        if (node->parent->parent == nullptr) 
        {
            return;
        }

        insertFix(node);
    }

    void remove(int data) 
    {
        deleteNodeRBTHelper(this->root, data);
    }

    void clear()
    {
        del(this->root);
        root = TNULL;
    }
};