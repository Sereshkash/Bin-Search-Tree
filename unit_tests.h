#include <cassert>
#include <iostream>
#include <math.h>
#include "complex.h"
#include "Tree.h"
#include "SearchTree.h"
#define INVALID -9999999
/// testing Complex

void test_creating_complex() {
    Complex a(1, 0);
    Complex b = 1;
    Complex c;
    c.SetRe(1);
    c.SetIm(0);
    assert(a == b);
    assert(c == b);
}

void test_operations() {
    Complex a(1, 1);
    Complex b(-2, 4);
    Complex d(-1, 5);
    assert((a + b) == d);
    Complex e(3, -3);
    assert((a - b) == e);
    Complex f(-6, 2);
    assert((a * b) == f);
}

/// testing Tree

template <class T>
T multElem(T item) {
    return item * 2;
}

template <class T>
bool divisionElem(T item) {
    return (item % 2) == 0;
}

void test_creating_tree() {
    int array[] = {1,2,3,INVALID,INVALID,4,INVALID,INVALID,5,6,INVALID,INVALID,INVALID}; 
    int array2[] = {2,4,6,INVALID,INVALID,8,INVALID,INVALID,10,12,INVALID,INVALID,INVALID}; 
    Tree<int> tree(array, INVALID);
    Tree<int> tree2(array2, INVALID);
    Tree<int> tree4(array, INVALID);
    tree.Traversal();
    Tree<int> tree3(tree);
    assert(tree == tree3);
    assert(tree3.Size() == 6);
    /// testing map
    tree.Map(multElem);
    assert(tree == tree2);
    /// testing travel
    tree.Traversal("LSR");
    tree.Traversal("SLR");
    /// testing size
    assert(tree.Size() == 6);
    assert(tree2.Size() == 6);
    /// testing getting str (for any option)
    int* array5 = tree4.GetStr("SLR", INVALID);
    Tree<int> tree5(array5, INVALID);
    assert(tree4 == tree5);
    delete [] array5;
}

void test_creating_search_tree() {
    int array[] = {8,3,1,INVALID,INVALID,6,4,INVALID,INVALID, 7,INVALID,INVALID,10,INVALID,14,INVALID,INVALID}; 
    int array2[] = {8,3,1,INVALID,INVALID,6,4,INVALID,INVALID, 7,INVALID,INVALID,10,INVALID,14,INVALID,INVALID}; 
    int array3[] = {3,1,INVALID,INVALID,6,4,INVALID,INVALID, 7,INVALID,INVALID}; 
    int array4[] = {3,2,INVALID,INVALID,6,4,INVALID,INVALID, 7,INVALID,INVALID}; 
    int array5[] = {9,1,INVALID,INVALID,INVALID}; 
    int array6[] = {8,4,1,INVALID,INVALID,6,INVALID,7,INVALID,INVALID,10,INVALID,14,INVALID,INVALID}; 
    SearchTree<int> searchtree(array, INVALID);
    SearchTree<int> searchtree2(searchtree);
    SearchTree<int> searchtree3(array3, INVALID);
    SearchTree<int> searchtree4(array4, INVALID);
    SearchTree<int> searchtree5(array5, INVALID);
    SearchTree<int> searchtree6(array6, INVALID);
    SearchTree<int> searchtree9(array, INVALID);
    assert(searchtree == searchtree2);
    /// testing size and add
    assert(searchtree.Size() == 8);
    searchtree.AddNode(15);
    searchtree.Traversal();
    assert(searchtree.Size() == 9);
    /// testing extracting subtree
    SearchTree<int>* searchtreePtr = searchtree.ExtractSubtree(3);
    assert(*(searchtreePtr) == searchtree3);
    /// testing find item (bool)
    assert(searchtree.FindItemBool(6) == true);
    assert(searchtree.FindItemBool(15) == true);
    assert(searchtree.FindItemBool(9) == false);
    /// testing find subtree (bool)
    assert(searchtree.FindTreeBool(*searchtreePtr) == true);
    assert(searchtree.FindTreeBool(searchtree4) == false);
    assert(searchtree.FindTreeBool(searchtree5) == false);
    delete searchtreePtr;
     /// testing delete subtree (bool)
    searchtree2.DeleteNode(3);
    assert(searchtree2 == searchtree6);
    /// testing balance
    searchtree2.SetHeight();
    searchtree.BalanceTree();
     assert(searchtree.TestingBalance() == true);
    int array7[] = {1,INVALID,2,INVALID,3,INVALID,4,INVALID,5,INVALID,6,INVALID,INVALID}; 
    SearchTree<int> searchtree7(array7, INVALID);
    SearchTree<int> searchtree10(array7, INVALID);
    assert(searchtree7.TestingBalance() == false);
    searchtree7.BalanceTree();
    assert(searchtree7.TestingBalance() == true);
    /// testing where
    searchtree7.Where(divisionElem);
    int array8[] = {4,2,INVALID,INVALID,6,INVALID,INVALID}; 
    SearchTree<int> searchtree8(array8, INVALID);
    assert(searchtree7 == searchtree8);
    /// testing merger (слияние)
    searchtree9.Merger(searchtree10);
    int array9[] = {8,3,1,INVALID,2,INVALID,INVALID,6,4,INVALID,5,INVALID,INVALID,7,INVALID,INVALID,10,INVALID,14,INVALID,INVALID};
    SearchTree<int> searchtree11(array9, INVALID); 
    assert(searchtree9 == searchtree11);
    searchtree9.Traversal("LSR");
}