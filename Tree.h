
#ifndef TREE_H
#define TREE_H
#include "AVL_Node.h"
#include <iostream>
#include <memory>
#include <vector>
#include <functional>
#include <utility>
#include <algorithm>
using namespace std;
template <typename T>
class Tree {
    Node<T>* root;
public:
//interface methods;
    virtual T FIND_MIN_ELEMENT(){};                          //minimal element
    virtual T FIND_MAX_ELEMENT(){};                          //maximal element
    virtual Node<T>* FIND_NODE(T data){};                    //search with key
    virtual void INSERT(T data){};                           //insertion
    virtual void DELETE(T data){};                           //deleting
//interface tests
    virtual void TESTING_INSERT(int n){};
    virtual void TESTING_DELETING(int n){};
    virtual void TESTING_MAX_ELEMENT(int n){};
    virtual void TESTING_MIN_ELEMENT(int n){};
    virtual void TESTING_FINDING_ELEMENT(int n){};
};
#endif //TREE_H
