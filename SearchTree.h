#pragma once
#include<iostream>
#include<string>
#include "complex.h"
#include "Person.h"
#include "Excepsion.h"
#include "Tree.h"

template<typename T>
class SearchTree : public Tree<T> {
    public:
    SearchTree();
    SearchTree(const SearchTree& tree);
    SearchTree(const T* array, const T& invalid);
    SearchTree(const T *array, const T &invalid, std::string variants);
    ~SearchTree() {};
    bool operator ==(SearchTree<T> &); 
    bool operator !=(SearchTree<T> &); 
    SearchTree<T>* ExtractSubtree(T item);
    void BalanceTree();
    Node<T>* FindItem(T item);
    bool FindItemBool(T item);
    bool FindTreeBool(SearchTree& tree);
    Node<T>* FindItem(T item, Node<T>* rootActual);
    void AddNode(T item);
    Node<T>* AddNode(T item, Node<T>* rootActual);
    Node<T>* MinItem(Node<T>* rootActual); /// для удаления узла
    void DeleteNode(T item);
    Node<T>* DeleteNode(T item, Node<T>* rootActual);
    void SetHeight();
    Node<T>* SetHeightInvers(int height, Node<T>* rootActual);
    int MaxHeight(Node<T>* rootActual);
    Node<T>* SetHeight(int heightMax, Node<T>* rootActual);
    int Height(Node<T>* rootActual);
    int BalanceFactor(Node<T>* rootActual);
    void FixHeight(Node<T>* rootActual);
    Node<T>* RotationRight(Node<T>* p);
    Node<T>* RotationLeft(Node<T>* q);
    Node<T>* Balance(Node<T>* p);
    bool TestingBalance();
    bool TestingBalance(Node<T>* rootActual);
    void Where(bool (*operasion) (T));
    void Merger(SearchTree& tree);
};

template<class T> SearchTree<T>::SearchTree() {
    this->root = nullptr;
}

template<class T> SearchTree<T>::SearchTree(const SearchTree<T> &tree) {
    this->root = Tree<T>::CopyTree(tree.root);
    this->SetHeight();
}

template<class T> SearchTree<T>::SearchTree(const T *array, const T &invalid) {
    int index = 0;
    this->root = Tree<T>::CreateTree(array, invalid, index);
    this->SetHeight();
}

template<class T> SearchTree<T>::SearchTree(const T *array, const T &invalid, std::string variants) {
    int index = 0;
    this->root = Tree<T>::CreateTree(array, invalid, index);
    this->SetHeight();
}


template<class T> void SearchTree<T>::AddNode(T item) {
    this->root = AddNode(item, this->root);  
}

template<class T> Node<T> *SearchTree<T>::AddNode(T item, Node<T> *rootActual) {
    if (!rootActual) {
        rootActual = new Node<T>(item);
    } else  if (item == rootActual->data) {
        throw ExceptionError(2);
    } else  if (item < rootActual->data) {
        rootActual->left = AddNode(item, rootActual->left);
    } else {
        rootActual->right = AddNode(item, rootActual->right);
    }
    return Balance(rootActual);
}

template<class T> bool SearchTree<T>::operator==(SearchTree<T> & tree2) {
    return this->Comparison(this->root, tree2.root);
}


template<class T> bool SearchTree<T>::operator!=(SearchTree<T> & tree2) {
    return (!Comparison(this->root, tree2.root));
}

template<class T> Node<T> *SearchTree<T>::FindItem(T item) {
    return FindItem(item, this->root);
}

template<class T> bool SearchTree<T>::FindItemBool(T item) {
    if (FindItem(item)) {
        return true;
    } else {
        return false;
    }
    
}

template<class T> Node<T> *SearchTree<T>::FindItem(T item, Node<T> *rootActual) {
    if (!rootActual) {
        return nullptr;
    } else if (rootActual->data == item) {
        return rootActual;
    } else  if (item < rootActual->data) {
        return FindItem(item, rootActual->left);
    } else {
        return FindItem(item, rootActual->right);
    }   
}

template<class T> SearchTree<T> *SearchTree<T>::ExtractSubtree(T item) {
    Node<T>* nodeItem = FindItem(item);
    if (nodeItem) {
        SearchTree<T>* subtree = new SearchTree();
        subtree->root = Tree<T>::CopyTree(nodeItem);
        return subtree;
    } else {
        return nullptr;
    }
}

template<class T> bool SearchTree<T>::FindTreeBool(SearchTree& tree) {
    Node<T>* nodeItem = FindItem((tree.root)->data);
    Node<T>* nodeItem2 = tree.FindItem((tree.root)->data);
    if (nodeItem) {
        return Tree<T>::Comparison(nodeItem, nodeItem2);
    } else {
        return false;
    }
    
}

template<class T> Node<T> *SearchTree<T>::MinItem(Node<T> *rootActual) {
    Node<T>* nodeItem = rootActual;
    while (nodeItem && nodeItem->left)
        nodeItem = nodeItem->left;
    return nodeItem;
}


template<class T> void SearchTree<T>::DeleteNode(T item) {
    this->root = DeleteNode(item, this->root);
}

template<class T> Node<T> *SearchTree<T>::DeleteNode(T item, Node<T> *rootActual) {
    if (!rootActual) {
        return nullptr;
    } else  if (item < rootActual->data) {
        rootActual->left = DeleteNode(item, rootActual->left);
    } else if (item > rootActual->data){
        rootActual->right = DeleteNode(item, rootActual->right);
    }  else {
        if (!rootActual->left && !rootActual->right) {
            delete rootActual;
            return nullptr;
        } else if (!rootActual->left) {
            Node<T>* nodeItem = rootActual->right;
            delete rootActual;
            return nodeItem;
        } else if (!rootActual->right) {
            Node<T>* nodeItem = rootActual->left;
            delete rootActual;
            return nodeItem;
        }
        Node<T>* nodeItemMin = MinItem(rootActual->right);
        rootActual->data = nodeItemMin->data;
        rootActual->right = DeleteNode(nodeItemMin->data, rootActual->right);
    }
    return rootActual;
}

template<class T> void SearchTree<T>::SetHeight() {
    this->root = SetHeightInvers(1, this->root);
    int maxHeight = MaxHeight(this->root);;
    this->root = SetHeight(maxHeight, this->root);
}

template<class T> Node<T> *SearchTree<T>::SetHeightInvers(int height, Node<T> *rootActual) {
    if (rootActual) {
        rootActual->height = height;
    }
    if (rootActual->left) {
        rootActual->left = SetHeightInvers(height + 1, rootActual->left);
    }
    if (rootActual->right) {
        rootActual->right = SetHeightInvers(height + 1, rootActual->right);
    }
    return rootActual;
}

template<class T> int SearchTree<T>::MaxHeight(Node<T> *rootActual) {
    if (rootActual) {
        if (!rootActual->left && !rootActual->right) {
            return rootActual->height;
        } else if (!rootActual->left) {
            return MaxHeight(rootActual->right);
        } else if (!rootActual->right) {
            return MaxHeight(rootActual->left);
        } else {
            int maxLeft = MaxHeight(rootActual->left);
            int maxRight = MaxHeight(rootActual->right);
            return (maxLeft > maxRight) ? maxLeft : maxRight;
        }
    } else {
        return 0;
    }
}

template<class T> Node<T> *SearchTree<T>::SetHeight(int heightMax, Node<T> *rootActual) {
    if (rootActual) {
        rootActual->height = heightMax - rootActual->height + 1;
        ///std::cout << rootActual->height << " height " << rootActual->data << " data\n";
    }
    if (rootActual->left) {
        rootActual->left = SetHeight(heightMax, rootActual->left);
    }
    if (rootActual->right) {
        rootActual->right = SetHeight(heightMax, rootActual->right);
    }
    return rootActual;
}

template<class T> int SearchTree<T>::Height(Node<T> *rootActual) {
    return rootActual ? rootActual->height : 0;
}

template<class T> int SearchTree<T>::BalanceFactor(Node<T> *rootActual) {
	return Height(rootActual->right)- Height(rootActual->left);
}

template<class T> void SearchTree<T>::FixHeight(Node<T> *rootActual) {
	int hl = Height(rootActual->left);
	int hr = Height(rootActual->right);
	rootActual->height = ((hl > hr) ? hl : hr) + 1;
}

template<class T> Node<T> *SearchTree<T>::RotationRight(Node<T> *p) {
	Node<T>* q = p->left;
	p->left = q->right;
	q->right = p;
	FixHeight(p);
	FixHeight(q);
	return q;
}

template<class T> Node<T> *SearchTree<T>::RotationLeft(Node<T> *q) {
	Node<T>* p = q->right;
	q->right = p->left;
	p->left = q;
	FixHeight(q);
	FixHeight(p);
	return p;
}

template<class T> Node<T> *SearchTree<T>::Balance(Node<T> *p) {
	FixHeight(p);
	if (BalanceFactor(p) == 2) {
		if(BalanceFactor(p->right) < 0)
			p->right = RotationRight(p->right);
		return RotationLeft(p);
	}
	if (BalanceFactor(p) == -2) {
		if(BalanceFactor(p->left) > 0 )
			p->left = RotationLeft(p->left);
		return RotationRight(p);
	}
	return p;
}

template<class T> void SearchTree<T>::BalanceTree() {
    T invalid = -999999;
    T* array = Tree<T>::GetStr("LSR", invalid);
    int j = 0;
    Tree<T>::Destroy(this->root);
    this->root = nullptr;
    while (array[j]) {
        if (array[j] != invalid) {
           this->AddNode(array[j]);
        }
        j++;
    }
    delete [] array;
}

template<class T> bool SearchTree<T>::TestingBalance() {
    return TestingBalance(this->root);
}

template<class T> bool SearchTree<T>::TestingBalance(Node<T> *rootActual) {
    if (rootActual) {
        if ((BalanceFactor(rootActual) > 1) || (BalanceFactor(rootActual) < -1)) {
        return false;
        }
        bool testLeft = true;
        bool testRight = true;
        if (rootActual->left) {
            testLeft = TestingBalance(rootActual->left);
        }
        if (rootActual->right) {
            testRight = TestingBalance(rootActual->right);
        }
        return testLeft && testRight;
    } else {
        return true;
    }
}

template<class T> void SearchTree<T>::Where(bool (*operasion)(T)) {
    T invalid = -999999;
    T* array = Tree<T>::GetStr("LSR", invalid); 
    int j = 0;
    Tree<T>::Destroy(this->root);
    this->root = nullptr;
    while (array[j]) {
        if ((array[j] != invalid) && operasion(array[j]) == true) {
           this->AddNode(array[j]);
        }
        j++;
    }
    delete [] array;
}

template<class T> void SearchTree<T>::Merger(SearchTree<T> &tree) {
    T invalid = -999999;
    T* array = tree.GetStr("LSR", invalid);
    int j = 0;
    while (array[j]) {
        if ((array[j] != invalid) && (this->FindItemBool(array[j]) == false)) {
           this->AddNode(array[j]);
        }
        j++;
    }
    delete [] array;
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
/*
template<typename T>
bool operator==(SearchTree<T> tree1, SearchTree<T> &tree2) {
    return (((Tree<T>) tree1) == ((Tree<T>) tree2));
}

template<typename T>
bool operator==(SearchTree<T> &tree1, Tree<T> &tree2) {
    return (Tree<T>) tree1 == tree2;
}
template<typename T>
bool operator==(Tree<T> &tree1, SearchTree<T> &tree2) {
    return tree1 == (Tree<T>) tree2;
}
*/