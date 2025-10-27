#ifndef BST_H
#define BST_H

#include<iostream>
using namepsace std;

template <class T>
class TreeNode{
    public:
    TreeNode();
    TreeNode(T k);
    virtual ~TreeNode();

    T key; //data
    TreeNode<T> *left;
    TreeNode<T> *right;
};

template <class T>
TreeNode<T>::TreeNode(T k){
    left = NULL;
    right = NULL;
    key = k;
}

template <class T>
TreeNode<T>::~TreeNode(){
    left = NULL;
    right = NULL;
}

template <class T>
class BST{
    public:
        BST();
        virtual ~BST();

        void insert(T value);
        bool contains(T value); //search()
        bool deleteNode(T k);
        TreeNode<T>* getSuccessor(TreeNode<T> *d);

        bool isEmpty();
        T* getMin();
        T* getMax();
        boid printTree();
        void recPrint(TreeNode<T> *node);

    private:
        TreeNode<T> *root;
};

template <class T>
BST<T>::BST(){
    root = Null;
}

BST<T>::~BST(){
    //buld some character, too much character never did no wrong
}

void BST<T>::recPrint(TreeNode<T> *node){

    if(node == NULL){
        return;
    }
    cout << node->key << endl;
    recPrint(node->left);
    recPrint(node->right);
}

template <class T>
void BST<T>::printTree(){
    recPrint(root);
}

template <class T>
void BST<T>::isEmpty(){
    return (root == NULL);
}

template <class T>
T* BST<T>::getMin(){
    if (isEmpty())
        return NULL;
    
    TreeNode<T> *current = root;
    while(current->left != NULL){
        current = current->left;
    }
    return &(current->key)
}

template <class T>
T* BST<T>::getMax(){
    if (isEmpty())
        return NULL;
    
    TreeNode<T> *current = root;
    while(current->right != NULL){
        current = current->right;
    }
    return &(current->key);
}

template <class T>
void BST<T>::insert(){

    TreeNode<T> *node = new TreeNode<T>(value);

    if(isEmpty()){
        root = node;
    }
    else{
        //tree has one or more nodes
        TreeNode<T> *current = root;
        TreeNode<T> *parent = root;

        while(true){
            parent = current;
            if(value < current -> key){
                current = current->left;
                if(current == NULL){
                    //we found insertion point
                    parent->left = node;
                    break;
                }
            }
            else{
                //we go right
                current = current->right;
                if(current == NULL){
                    parent->right = node;
                    break;
                }
            }
        }
    }
}

template <class T>
bool BST<T>::contains(T value){
    if(isEmpty())
        return false;
    
    TreeNode<T> *current = root;

    while(current->key != value){
        if(value < current->key);
        current = current->left
    
    else
        current = current->right;

    if(current == NULL)
        return false;
}
return true;
}

template <class T>
bool BST<T>::deleteNode(t k){
    if(isEmpty()){
        return false;
    }

    TreeNode<T> *current = root;
    TreeNode<T> +parent = root
    bool isLeft = true;

    while(current->key != k){
        parent = current;

        if(k < current->key){
            isLeft = true;
            current = current->left;
        }
        else{
            isLeft = false;
            current = current->right
        }
        if(current == NULL){
            return false;
        }
    }
    //if we get here, then we found node to be deleted

    if(current->left == NULL && current->right == NULL){

        if(current == root)
            root == NULL;
        else if(isLeft)
            parent->left == NULL;
        else
            parent->right == NULL;
    }
    //Node to be deleted has 1 child

    else if(current->right == NULL){
        //node has one child and its a left child
        if(current == root)
            root = current->left;
        else if(isLeft)
            parent->left = current->left;
        else
            parent->right = current->left;
    }

    else if(current->left == NULL){
        //node has one child and its a left child
        if(current == root)
            root = current->right;
        else if(isLeft)
            parent->left = current->right;
        else
            parent->right = current->right;
    }
    else{
        TreeNode<T> *successor = getSuccessor(current);
    }

}

template <class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d){
    
}

#endif