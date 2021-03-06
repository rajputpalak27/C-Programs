#include<bits/stdc++.h>
using namespace std;


struct Node{
    int data;
    struct Node *next;
}*first=NULL;

void insert(int n){
    int ele;
    cout<<"Enter the Element 1: ";
    cin>>ele;

    struct Node *new_node,*last;

    first=new Node;
    first->data=ele;
    first->next=NULL;
    last=first;

    for(int i=1;i<n;i++){
        cout<<"Enter the Element "<<i+1<<": ";
        cin>>ele;
        new_node=new Node;
        new_node->data=ele;
        new_node->next=NULL;
        last->next=new_node;
        last=new_node;
    }
}


void insertAtLocation(int pos,int e,int n){
    struct Node *t,*new_node;
    t=first;
    new_node=new Node;
    new_node->data=e;

    if(pos<0 || pos>n){
        cout<<endl<<"INDEX OUT OF SCOPE"<<endl;
        return;

    }else if(pos==0){
        new_node->next=first;
        first=new_node;

    }else{
        for(int i=0;i<pos-1;i++){
            t=t->next;
    }
        new_node->next=t->next;
        t->next=new_node;
    }
}

void display(struct Node *f){
    while(f!=NULL){
            cout<<f->data<<" ";
            f=f->next;
    }
}



int main(){

    int n,pos,e;
    cout<<"Enter the elements you want in linked list: ";
    cin>>n;

    insert(n);

    cout<<"Enter position and element to be inserted at that position :"<<endl;
    cin>>pos>>e;

    insertAtLocation(pos,e,n);

    display(first);

    return 0;
}
