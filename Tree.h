#pragma once
#include<iostream>
#include<string>
#include "complex.h"
#include "Person.h"
#include "Excepsion.h"

template <class T>
class Tree {
    protected:
        struct Node {
            T data; 
            Node* left = nullptr;
            Node* right = nullptr; 
            Node() {};
            Node(const T& data) {
                this->data = data; 
                this->left = nullptr;
                this->right = nullptr;
            }
            void setData(const T& data) {
                this->data = data; 
            }
        };
        Node* root;
    public:
        Tree();
        Tree(const Tree& tree);
        Tree(const T* array, const T& invalid);
        Tree(const T *array, const T &invalid, std::string variants);
        ~Tree();
        void Destroy(Node* rootActual);
        Node* CopyTree(Node* rootActual);
        Node* CreateTree(const T* array, const T& invalid, int& index);
        Node* CreateTree(const T* array, const T& invalid, int& index, std::string variants);
        void Traversal(std::string varians, Node* rootActual, void (*operasion) (T&));
        void Traversal(std::string varians, void (*operasion) (T&));
        void Traversal(void (*operasion) (T&));
        void Traversal(std::string varians);
        void Traversal();
        int Size();
        int Size(Node* rootActual);
        void Map(T (*operasion) (T));
        void Map(T (*operasion) (T), Node* rootActual);
        bool operator ==(Tree<T> &); 
        bool Comparison(Node*, Node*);
	    bool operator !=(Tree<T>); 

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


template<class T> typename Tree<T>::Node *Tree<T>::CopyTree(Tree<T>::Node *rootActual) {
    if(rootActual) {
        Node* node  = new Node(rootActual->data);
        node->left = CopyTree(rootActual->left);
        node->right = CopyTree(rootActual->right);
        return node;
    } else {
        return nullptr;
    }
}

template<class T> typename Tree<T>::Node *Tree<T>::CreateTree(const T *array, const T &invalid, int &index) {
    Node* rootActual = nullptr;
    if(array[index] != invalid) {
        rootActual = new Node(array[index]);
        index++;
        rootActual->left = CreateTree(array, invalid, index);
        index++;
        rootActual->right = CreateTree(array, invalid, index);
    }
    return rootActual;
} 

template<class T> typename Tree<T>::Node *Tree<T>::CreateTree(const T *array, const T &invalid, int &index, std::string variants) {
    Tree(array, invalid);
    Node* rootActual = nullptr;
    if(array[index] != invalid) {
        for(int i = 0; i < variants.size(); i++) {
            switch (variants[i]) {
            case 'S':
                rootActual = new Node(array[index]);
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

template<class T> void Tree<T>::Destroy(Tree<T>::Node *rootActual) {
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

template<class T> void Tree<T>::Traversal(void (*operasion)(T&)) {
    Traversal("LSR", this->root, operasion);
    std::cout << "\n";
}

template<class T> void Tree<T>::Traversal(std::string varians, void (*operasion) (T&)) {
    Traversal(varians, this->root, operasion);
    std::cout << "\n";
}


template<class T> void Tree<T>::Traversal(std::string varians, Node* rootActual, void (*operasion) (T&)) {
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

template<class T> void Tree<T>::Map(T (*operasion)(T), Node* rootActual) {
    if (rootActual) {
        Map(operasion, rootActual->left);
        rootActual->data = operasion(rootActual->data);
        Map(operasion, rootActual->right);
    }
}

template<class T> int Tree<T>::Size() {
    return Size(this->root);
}
template<class T> int Tree<T>::Size(Node* rootActual) {
    if(!rootActual)
        return 0;
    return Size(rootActual->left) + Size(rootActual->right) + 1;
}

template<class T> bool Tree<T>::operator==(Tree<T> & tree2) {
    return Comparison(this->root, tree2.root);
}

template<class T> bool Tree<T>::operator!=(Tree<T> tree2) {
    return (!Comparison(this->root, tree2.root));
}

template<class T> bool Tree<T>::Comparison(Node* rootActualTh, Node* rootActual) {
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
