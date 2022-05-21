#pragma once
#include<iostream>
#include<string>
#include "complex.h"
#include "Person.h"
#include "Excepsion.h"

template <class T>
 struct Node {
    T data; 
    Node* left = nullptr;
    Node* right = nullptr;
    int height = -1;
    Node() {};
    Node(const T& data) {
        this->data = data; 
        this->left = nullptr;
        this->right = nullptr;
    }
    void setData(const T& data) {
        this->data = data; 
    }
    void setHeight(const int& height) {
        this->height = height; 
    }
};

template <class T>
class Tree {
    protected:
        Node<T>* root;
    public:
        Tree();
        Tree(const Tree& tree);
        Tree(const T* array, const T& invalid);
        Tree(const T *array, const T &invalid, std::string variants);
        ~Tree();
        void Destroy(Node<T>* rootActual);
        Node<T>* CopyTree(Node<T>* rootActual);
        Node<T>* CreateTree(const T* array, const T& invalid, int& index);
        Node<T>* CreateTree(const T* array, const T& invalid, int& index, std::string variants);
        void Traversal(std::string varians, Node<T>* rootActual, void (*operasion) (T&));
        void Traversal(std::string varians, void (*operasion) (T&));
        void Traversal(void (*operasion) (T&));
        void Traversal(std::string varians);
        void Traversal();
        int Size();
        int Size(Node<T>* rootActual);
        void Map(T (*operasion) (T));
        void Map(T (*operasion) (T), Node<T>* rootActual);
        bool operator ==(Tree<T> &); 
        bool Comparison(Node<T>*, Node<T>*);
	    bool operator !=(Tree<T> &); 

};

template<class T> Tree<T>::Tree() {
    root = nullptr;
}

template<class T> Tree<T>::Tree(const Tree<T> &tree) {
    this->root = CopyTree(tree.root);
}

template<class T> Tree<T>::Tree(const T *array, const T &invalid) {
    int index = 0;
    root = CreateTree(array, invalid, index);
}

template<class T> Tree<T>::Tree(const T *array, const T &invalid, std::string variants) {
    int index = 0;
    root = CreateTree(array, invalid, index);
}


template<class T> Node<T> *Tree<T>::CopyTree(Node<T> *rootActual) {
    if(rootActual) {
        Node<T>* node  = new Node<T>(rootActual->data);
        node->left = CopyTree(rootActual->left);
        node->right = CopyTree(rootActual->right);
        return node;
    } else {
        return nullptr;
    }
}

template<class T> Node<T> *Tree<T>::CreateTree(const T *array, const T &invalid, int &index) {
    Node<T>* rootActual = nullptr;
    if(array[index] != invalid) {
        rootActual = new Node<T>(array[index]);
        index++;
        rootActual->left = CreateTree(array, invalid, index);
        index++;
        rootActual->right = CreateTree(array, invalid, index);
    }
    return rootActual;
} 

template<class T> Node<T> *Tree<T>::CreateTree(const T *array, const T &invalid, int &index, std::string variants) {
    Tree(array, invalid);
    Node<T>* rootActual = nullptr;
    if(array[index] != invalid) {
        for(int i = 0; i < variants.size(); i++) {
            switch (variants[i]) {
            case 'S':
                rootActual = new Node<T>(array[index]);
                break;
            case 'L':
                index++;
                rootActual->left = CreateTree(array, invalid, index, variants);
                break;
            case 'R':
                index++;
                rootActual->right = CreateTree(array, invalid, index, variants);
                break;
            default:
                break;
            }
        }
    }
}

template<class T> Tree<T>::~Tree() {
    Destroy(this->root);
}

template<class T> void Tree<T>::Destroy(Node<T> *rootActual) {
    if (rootActual) {
        Destroy(rootActual->left);
        Destroy(rootActual->right);
        delete rootActual;
    }
}

template <class T>
void PrintElem(T & item) {
    std::cout << item << " ";
}

template<class T> void Tree<T>::Traversal() {
    Traversal("SLR", this->root, PrintElem);
    std::cout << "\n";
}

template<class T> void Tree<T>::Traversal(std::string varians) {
    Traversal(varians, this->root, PrintElem);
    std::cout << "\n";
}

template<class T> void Tree<T>::Traversal(void (*operasion)(T &)){
    Traversal("LSR", this->root, operasion);
    std::cout << "\n";
}

template<class T> void Tree<T>::Traversal(std::string varians, void (*operasion)(T &)) {
    Traversal(varians, this->root, operasion);
    std::cout << "\n";
}


template<class T> void Tree<T>::Traversal(std::string varians, Node<T> *rootActual, void (*operasion)(T &)) {
    if (rootActual) {
        for(int i = 0; i < varians.size(); i++) {
            switch (varians[i]) {
            case 'S':
                operasion(rootActual->data);
                break;
            case 'L':
                Traversal(varians, rootActual->left, operasion);
                break;
            case 'R':
                Traversal(varians, rootActual->right, operasion);
                break;
            default:
                break;
            }
        }
    }
}

template<class T> void Tree<T>::Map(T (*operasion)(T)) {
    this->Map(operasion, root);
}

template<class T> void Tree<T>::Map(T (*operasion)(T), Node<T> *rootActual) {
    if (rootActual) {
        Map(operasion, rootActual->left);
        rootActual->data = operasion(rootActual->data);
        Map(operasion, rootActual->right);
    }
}

template<class T> int Tree<T>::Size() {
    return Size(this->root);
}
template<class T> int Tree<T>::Size(Node<T> *rootActual) {
    if(!rootActual)
        return 0;
    return Size(rootActual->left) + Size(rootActual->right) + 1;
}

template<class T> bool Tree<T>::operator==(Tree<T> & tree2) {
    return Comparison(this->root, tree2.root);
}

template<class T> bool Tree<T>::operator!=(Tree<T> & tree2) {
    return (!Comparison(this->root, tree2.root));
}

template<class T> bool Tree<T>::Comparison(Node<T>* rootActualTh, Node<T>* rootActual) {
    if ((rootActualTh == nullptr) && (rootActual == nullptr)) {
        return true;
    } else if ((!rootActualTh) && (rootActual)) {
        return false;
    } else if ((rootActualTh) && (!rootActual)) {
        return false;
    } else if (rootActualTh->data != rootActual->data) {
        return false;
    }
    return (Comparison(rootActualTh->left, rootActual->left)) && (Comparison(rootActualTh->right, rootActual->right));
}

