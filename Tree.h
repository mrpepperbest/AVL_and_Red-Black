
#ifndef TREE_H
#define TREE_H
#include "Timer.h"
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
public:
//interface methods;
    virtual T FIND_MIN_ELEMENT(){};                          //minimal element
    virtual T FIND_MAX_ELEMENT(){};                          //maximal element
    virtual Node<T>* FIND_NODE(T data){};                    //search with key
    virtual void INSERT(T data){};                           //insertion
    virtual void DELETE(T data){};                           //deleting
//interface tests
    virtual void TESTING_INSERT(int n) final;
    virtual void TESTING_DELETING(int n) final;
    virtual void TESTING_MAX_ELEMENT(int n) final;
    virtual void TESTING_MIN_ELEMENT(int n) final;
    virtual void TESTING_FINDING_ELEMENT(int n) final;
};
//test funcs declaration
template <typename T> void Tree<T>::TESTING_INSERT(int n)
{
    Timer t;
    for(int i=0; i<n; i++) {
        INSERT(i);
    }
    cout << "Time of inserting of " << n << " elements is " <<  t.elapsed() << " s "<< endl;
    Timer a;
    INSERT(n);
    cout << "Time of inserting of 1 element into the tree of " << n << " elements is " << a.elapsed() << " ms " << endl<<endl;
}         //insertion test

template <typename T>void Tree<T>::TESTING_DELETING(int n)
{
    for(int i=0; i<n; i++) {
        INSERT(i);
    }
    Timer a;
    INSERT(n);
    DELETE(n-1);
    cout << "Time of deleting of an element is " << a.elapsed()  << "ms" << endl<<endl;
}        //deleting test

template <typename T>void Tree<T>::TESTING_MAX_ELEMENT(int n)
{
    unsigned int start_time =  clock();
    for(int i=0; i<n; i++) {
        INSERT(i);
    }
    Timer a;
    FIND_MAX_ELEMENT();
    cout << "Time of finding of a needed element in a tree of " << n << " elements is " <<  a.elapsed() << "s"<< endl;
}     //max test

template <typename T>void Tree<T>::TESTING_MIN_ELEMENT(int n)
{
    unsigned int start_time =  clock();
    for(int i=0; i<n; i++) {
        INSERT(i);
    }
    Timer a;
    FIND_MIN_ELEMENT();
    cout << "Time of finding of a needed element in a tree of " << n << " elements is " <<  a.elapsed() << "s"<< endl;
}     //min test

template <typename T>void Tree<T>::TESTING_FINDING_ELEMENT(int n)
{
    unsigned int start_time =  clock();
    for(int i=0; i<n; i++) {
        INSERT(i);
    }
    Timer a;
    FIND_NODE(n-1);
    cout << "Time of finding of a needed element in a tree of " << n << " elements is " <<  a.elapsed() << "s"<< endl;
} //search test
#endif //TREE_H
