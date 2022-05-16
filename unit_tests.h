#include <cassert>
#include <iostream>
#include <math.h>
#include "complex.h"
#include "Tree.h"

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

void test_creating_tree() {
    int array[] = {1,2,3,'#','#',4,'#','#',5,6,'#','#','#'}; 
    Tree<int> tree(array, '#');
    tree.Traversal();
}

