//definition TREE_AVL
#ifndef AVL_TREE_AVL_H
#define AVL_TREE_AVL_H
//initial libs
#include "Tree.h"
#include <iostream>
#include "AVL_Node.h"
#include <cmath>
#include <iostream>
#include <memory>
#include <vector>
#include <functional>
#include <utility>
#include <algorithm>
using namespace std;
//Tree body
template <typename T>
class AVL: public Tree<T> {
//tree items
private:
    Node<T> *head;
    unsigned int size;
//
//destruction_func
static void destroy_node(Node<T>* node){
    if(node){
        destroy_node(node->left);
        destroy_node(node->right);
        delete node;
    }
}
//
public:
//constructors
AVL(const int first){head=new Node<T>(first); size=1;}; //init with first key
AVL():head(nullptr),size(0){};                          //empty init
AVL(AVL<T> const& other):head(nullptr){
    vector<Node<T> const*> remaining;
    Node<T> const* cur=other.head;
    while(cur){
        insert(cur->key);
        if(cur->right){
            remaining.push_back(cur->right);
        }
        if(cur->left){
            cur=cur->left;
        }
        else if(remaining.empty()){
            break;
        }
        else{
            cur=remaining.back();
            remaining.pop_back();
        }
    }
};
//destructor
~AVL(){destroy_node(head);}
//methods
//info funcs
Node<T>* const show_data();                         //outputting data
bool const search(const int a);                     //looking for element
unsigned int amount();                              //showing amount of elements
//moderating funcs
void insert(T a);                                   //inserting 1 element
void insert(const vector<T> a);                     //inserting mass of elements
void remove_element(const T a);                     //removing 1 element
void remove_element(const vector<T> a);             //removing mass of elements
void remove_minimal(){
    head=remove_min(head);
};                         //removing minimal
//interface methods;
T FIND_MIN_ELEMENT();                                       //minimal element
T FIND_MAX_ELEMENT();                                       //maximal element
Node<T>* FIND_NODE(T data);                                 //search with key
static Node<T>* INSERT(Node<T>* p, T data);                 //insertion
static Node<T>* DELETE(Node<T>* nd, int data);              //deleting
//interface tests
void TESTING_INSERT(int n);
void TESTING_DELETING(int n);
void TESTING_MAX_ELEMENT(int n);
void TESTING_MIN_ELEMENT(int n);
void TESTING_FINDING_ELEMENT(int n);
};
//methods realising
//moderating funcs
template<typename T> void AVL<T>::insert(const T a){
head=AVL_TREE_NODE_H::insert(head,a);
size++;
};                  //inserting 1 element
template<typename T> void AVL<T>::insert(const vector<T> a){
    for(unsigned int i=0;i<a.size();++i) {
        this->insert(a[i]);
    }
};          //inserting mass of elements
template<typename T> void AVL<T>::remove_element(const T a){
    if(::search(head, a)){
        size--;
    }
    head = AVL_TREE_NODE_H::remove(head,a);
};          //removing 1 element
template<typename T> void AVL<T>::remove_element(const vector<T> a){
    for(unsigned int i=0;i<a.size();++i) {
        this->remove_element(a[i]);
    }
};  //removing mass of elements
//info funcs
template<typename T> Node<T>* const AVL<T>::show_data(){
    return head;
};              //outputting data
template<typename T> bool const AVL<T>::search(const int a){
    return AVL_TREE_NODE_H::search(head,a); //is element here?
};          //looking for element
template<typename T> unsigned int AVL<T>::amount(){
    return size;
};                   //showing amount of elements
//operator realisation
//help-func

//operators
template<typename T> ostream& operator <<(ostream& os,AVL<T>& a){
    AVL<T>* a_=new AVL(a);
    Node<T>* b=a_->show_data();
    Node<T>* i;
    if(b==nullptr){
        cout<< "empty";
        delete i;
        return os;
    }
    while(b->left!=nullptr){
        i=find_min(b->left);
        cout<< "| "<< i->key <<" | ";
        b->left=remove_min(b->left);
    }
    cout<<"( "<<b->key<<" )";
    while(b->right!=nullptr){
        i=find_min(b->right);
        cout<< " | "<< i->key <<" |";
        b->right=remove_min(b->right);
    }
    delete a_;
    delete i;
    return os;
}; //output
};
//interface methods
template<typename T> T AVL<T>::FIND_MIN_ELEMENT(){};                                       //minimal element
template<typename T> T AVL<T>::FIND_MAX_ELEMENT(){};                                       //maximal element
template<typename T> Node<T>* AVL<T>::FIND_NODE(T data){};                                 //search with key
template<typename T> static Node<T>* AVL<T>::INSERT(Node<T>* p, T data){};                 //insertion
template<typename T> static Node<T>* AVL<T>::DELETE(Node<T>* nd, int data){};              //deleting
//interface tests
template<typename T> void AVL<T>::TESTING_INSERT(int n){};
template<typename T> void AVL<T>::TESTING_DELETING(int n){};
template<typename T> void AVL<T>::TESTING_MAX_ELEMENT(int n){};
template<typename T> void AVL<T>::TESTING_MIN_ELEMENT(int n){};
template<typename T> void AVL<T>::TESTING_FINDING_ELEMENT(int n){};
/**
template <typename T>
class AVL{
private:
    Node *head;
    unsigned int size;
public:
    AVL(const int first){head=new Node(first); size=1;}; //init with first key
    AVL(){head=nullptr;size=0;}; //empty init
    ~AVL(){del(head);}; //destructor
    //info funcs
    Node* const show_data(){return head;}; //data
    bool const search(const int a){ //is element here?
        return AVL_TREE_NODE_H::search(head,a);
    };
    unsigned int amount(){ //writing an amount of nodes
        return size;
    };
    //controlling tree keys
    void insert(const int a){//inserting num
        head=AVL_TREE_NODE_H::insert(head,a);
        size++;
    }
    void insert(const vector<int> a){//inserting mass
        for(unsigned int i=0;i<a.size();++i) {
            head = AVL_TREE_NODE_H::insert(head, a[i]);
        }
        size+=a.size();
    }
    void remove_element(const int a){//removing num
        if(::search(head, a)){
            size--;
        }
        head = AVL_TREE_NODE_H::remove(head,a);
    }
    void remove_element(const vector<int> a){//removing mass
        for(unsigned int i=0;i<a.size();++i) {
            if(::search(head, a[i])){
                size--;
            }
            head = AVL_TREE_NODE_H::remove(head, a[i]);
        }
    }

    AVL &operator =(const AVL& a){
        this->head=a.head;
        this->size=a.size;
        return *this;
    }
    AVL operator -(const int b){ //subtracting num
        AVL a;
        head = AVL_TREE_NODE_H::remove(head,b);
        a=*this;
        return a;
    };
    AVL operator +(const int b){ //subtracting num
        AVL a;
        head = AVL_TREE_NODE_H::insert(head,b);
        a=*this;
        return a;
    };
};

ostream& operator <<(ostream& os,AVL& a){
    if(a.show_data()==nullptr)
    {
        os<< "empty";
        return os;
    }
    os<<*a.show_data();
    return os;
};
**/
#endif //AVL_TREE_AVL_H
