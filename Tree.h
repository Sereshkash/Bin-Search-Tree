#pragma once
#include<iostream>
#include<string>

template <class T>
class Tree {
    private:
        struct Node {
            T data; 
            Node* left = nullptr;
            Node* right = nullptr; 
            Node() {};
            Node(const T& data = T()) {
                this->data = data; 
                this->left = nullptr;
                this->right = nullptr;
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
        Node* CopyTree(const Tree& tree, Node* rootActual);
        Node* CreateTree(const T* array, const T& invalid, int& index);
        Node* CreateTree(const T* array, const T& invalid, int& index, std::string variants);
        void Traversal(std::string varians, Node* rootActual, void (*operasion) (T&));
        void Traversal(std::string varians, void (*operasion) (T&));
        void Traversal(void (*operasion) (T&));
        void Traversal();
        void Map(T (*operasion) (T));
        void Map(T (*operasion) (T), Node* rootActual);
        bool operator ==(Tree); 
        bool Comparison(Tree, Node*);
	    bool operator !=(Tree); 

};

template<class T> Tree<T>::Tree() {
    root = nullptr;
}

template<class T> Tree<T>::Tree(const Tree<T> &tree) {
    CopyTree(tree, root);
}

template<class T> Tree<T>::Tree(const T *array, const T &invalid) {
    int index = 0;
    root = CreateTree(array, invalid, index);
}

template<class T> Tree<T>::Tree(const T *array, const T &invalid, std::string variants) {
    int index = 0;
    root = CreateTree(array, invalid, index);
}


template<class T> typename Tree<T>::Node *Tree<T>::CopyTree(const Tree<T> &tree, Tree<T>::Node *rootActual) {
    if(rootActual) {
        Node* node  = new Node(rootActual->data);
        node->left = CopyTree(rootActual->left);
        node->right = CopyTree(rootActual->right);
    }
    return rootActual;
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
    Destroy(root);
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
/*
template<class T> bool Tree<T>::operator==(Tree<T> tree2) {

}

template<class T> bool Tree<T>::Comparison(Tree<T> tree2, Node* rootActual) {
    if (rootActual) {
        Comparison(operasion, rootActual->left);
        rootActual->data = operasion(rootActual->data);
        Comparison(operasion, rootActual->right);
    }
    
}
*/