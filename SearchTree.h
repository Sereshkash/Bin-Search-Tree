#pragma once
#include<iostream>
#include<string>
#include "complex.h"
#include "Person.h"
#include "Excepsion.h"
#include "Tree.h"

template<typename T>
class SearchTree : public Tree<T> {
    private:
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
    void a(void);
        void AddNode(T item);
        void AddNode(T item, Node* rootActual);
};

template<class T> void SearchTree<T>::AddNode(T item) {
    AddNode(item, root);  
}

template<class T> void SearchTree<T>::AddNode(T item, SearchTree<T>::Node *rootActual) {
    if (!rootActual) {
        rootActual = new Node(item);
    } else  if (item < rootActual->field) {
        AddNode(item, rootActual->left);
    } else {
        AddNode(item, rootActual->right);
    }
}

/*
struct tnode * addnode(int item, tnode *tree) {
  if (tree == NULL) { // Если дерева нет, то формируем корень
    tree =new tnode; // память под узел
    tree->field = item;   // поле данных
    tree->left =  NULL;
    tree->right = NULL; // ветви инициализируем пустотой
  }else  if (item < tree->field)   // условие добавление левого потомка
    tree->left = addnode(item, tree->left);
  else    // условие добавление правого потомка
    tree->right = addnode(item, tree->right);
  return(tree);
}
*/