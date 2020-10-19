#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct Node{
    Node *next, *prev;
    string name;

    Node(string name_ = "") :
    prev(NULL), next(NULL), name(name_) { }
};

Node* nil;

void init(){
    nil = new Node();
    nil->next = nil;
    nil->prev = nil;
}

void printList(){
    Node* cur = nil->next;
    for(; cur != nil; cur = cur->next){
        cout << cur->name << " -> ";
    }
    cout << endl;
}

void insert(Node* v, Node* p = nil){
    v->next = p->next;
    p->next->prev = v;
    p->next = v;
    v->prev = p;
}

void erase(Node *v){
    if (v == nil) return;
    v->prev->next = v->next;
    v->next->prev = v->prev;
    delete v;
}

int main(){
    init();

    vector<string> names = {"yamamoto", "watanabe", "ito", "takahashi", "suzuki", "sato"};

    Node *watanabe;
    for (int i = 0; i < (int) names.size(); ++i){
        Node* node = new Node(names[i]);

        insert(node);

        cout << "step " << i << ": ";
        if (names[i] == "watanabe") watanabe = node;
        printList();
    }

    cout << "before: ";
    printList();
    erase(watanabe);
    cout << "after: ";
    printList();

}