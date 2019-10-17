#ifndef SINGLYLINKEDLIST_H_INCLUDED
#define SINGLYLINKEDLIST_H_INCLUDED


#include <iostream>
#include <cstdio>
#include <cstring>

#define Ele int
#define inf 0x3f3f3f3f

using namespace std;

typedef struct lnode{
    Ele data;
    struct lnode *next;
} node;

node ZZ=node{inf,nullptr};


class LinkedList{
private:
    node head;
    int Size;
public:
    bool CreatList();
    void DestoryList(node now=ZZ);
    void ClearList(node one=ZZ);
    bool InsertBList(Ele dt,int ad=0);
    bool InsertAList(Ele dt,int ad);
    void DeleteElem(int ad,Ele &q);//ɾ������iλ�õ�Ԫ�ز����浽q��//
    bool ListEmpty();//�����Ƿ�Ϊ��
    void Append(node *s);//��ָ��s��ָ��һ���������ӵ�ԭ�������//
    int  ListSize();//����������ǰ��С//
    void ListElemChange(int ad,Ele e);//�ı�ad��Ԫ�ص�ֵ//
    bool ListHead(node &e);//���������ĵ�һ���ڵ�浽e��//
    void ListQuery(int ad,Ele &e);//����adλ�õ�����//
    void ListEnd(node &e);//���������һ���ڵ�浽e��//
    bool ListNext(int ad,node &e);//����adλ�õĺ��Ԫ�ش浽e��,�޺�̷���false//
    bool ListPrior(int ad,node &e);//����adλ�õ�ǰ��Ԫ�ش浽e��,��ǰ������false//
    int  ListLocateElem(Ele e,bool (*cmp)(Ele x,Ele y)=nullptr);
    //���ص�һ��������e����cmp��ϵ��Ԫ��λ��//
    void PrintList();
};

bool LinkedList::CreatList(){
    node *p=new node;
    p->next=nullptr;
    p->data=0;
    if(p){
       head=*p;
       Size=0;
       return true;
    }
    Size=-1;
    return false;
}

void LinkedList::DestoryList(node now){
    node *p;
    if(now.data==inf)
        p=&head;
    else
        p=&now;
    if(p->next)
        DestoryList(*p);
    delete p;
    Size--;
    return;
}

void LinkedList::ClearList(node one){
    node *p;
    if(one.data==inf)
        p=head.next;
    else
        p=&one;
    if(p->next){
        ClearList(*(p->next));
    }
    delete p;
    Size--;
    return;
}

bool LinkedList::InsertBList(Ele dt,int ad){
    if(ad<0||ad>Size)
        return false;
    node *p=&head;
    int i=1;
    while(p->next&&i<ad){
        p=p->next;
        i++;
    }
    node *a=new node;
    if(!a)
        return false;
    a->data=dt;
    a->next=p->next;
    p->next=a;
    Size++;
    return true;

}//���뺯���ڵ�ad���ڵ�ǰ����

bool LinkedList::InsertAList(int dt, int ad){
    if(ad<1||ad>Size)
        return false;
    node *p=head.next;
    int i=1;
    while(p->next&&i<=ad){
        p=p->next;
    }
    node *a=new node;
    if(!a)
        return false;
    a->data=dt;
    a->next=p->next;
    p->next=a;
    Size++;
    return true;
}

void LinkedList::DeleteElem(int ad,Ele &q){
    if(ad<1||ad>Size)
        return;
    int i=0;
    node now=head;
    while(now.next&&i<ad-1){
        now=*now.next;
        i++;
    }
    node *temp=now.next;
    node *temp2=temp->next;
    now.next=temp2;
    q=temp->data;
    delete temp;
    return;
}

bool LinkedList::ListEmpty(){
    return Size==0;
}

void LinkedList::Append(node* s){
    node mv=head;
    while(mv.next){
        mv=*mv.next;
    }
    mv.next=s;
    return;
}

int  LinkedList::ListSize(){
    return Size;
}

void LinkedList::ListElemChange(int ad, int e){
    if(ad<1||ad>Size)
        return;
    int i=0;
    node now=head;
    while(now.next&&i<ad){
        now=*now.next;
        i++;
    }
    now.data=e;
    return;
}

bool LinkedList::ListHead(node &e){
    node now=head;
    if(now.next==nullptr)
        return false;
    else{
        e=*now.next;
        return true;
    }
}

void LinkedList::ListQuery(int ad, int& e){
    if(ad<1||ad>Size)
        return;
    int i=0;
    node now=head;
    while(now.next&&i<ad){
        now=*now.next;
        i++;
    }
    e=now.data;
    return;
}

void LinkedList::ListEnd(node& e){
    node now=head;
    while(now.next){
        now=*now.next;
    }
    e=now;
    return;
}

bool LinkedList::ListNext(int ad, node& e){
    if(ad<1||ad>=Size)
        return false;
    int i=0;
    node now=head;
    while(now.next&&i<ad){
        now=*now.next;
        i++;
    }
    if(now.next){
        e=*now.next;
        return true;
    }
    return false;
}

bool LinkedList::ListPrior(int ad, node& e){
    if(ad<2||ad>Size)
        return false;
    int i=0;
    node now=head;
    while(now.next&&i<ad-1){
        now=*now.next;
        i++;
    }
    if(i==ad-1&&now.next){
        e=now;
        return true;
    }
    return false;
}

int  LinkedList::ListLocateElem(Ele e, bool(* cmp)(Ele x,Ele y)){
    int i=0;
    node now=head;
    while(now.next){
        now=*now.next;
        i++;
        if(cmp(now.data,e))
            return i;
    }
    return -1;
}

void LinkedList::PrintList(){
    node *p=&head;
    while(p->next){
        p=p->next;
        printf("%d ",p->data);
    }
    printf("\n");
    return;
}

typedef struct dllnode{
    int data;
    struct dllnode *nt,*lt;
}DLn;

class doublist{
private:
    DLn *head;
    int Size;
public:
    bool CreatList();//create a double linked list
    void DestoryList();//free the space of this list
    void ClearList();//clear this list
    void AInsertList(int ad,int x);//insert an element into this list
    void BInsertList(int ad,int x);//__
    int  DeleteElem(int ad);//delete the elem the tips of which is ad
    bool ListEmpty();
    int  ListSize();
    void ListChange(int ad,int x);//change the value of the ad-th element
    int  ListQuery(int ad);//return the value of the ad-th element
    void APrintList();//
    void BPrintList();//
};

bool doublist::CreatList(){
    DLn *p;
    p=new DLn;
    if(p){
        p->data=inf;
        p->lt=nullptr;
        p->nt=nullptr;
        head=p;
        return true;
    }
    return false;
}

void doublist::DestoryList(){
    DLn *p=head;
    while(p){
        DLn *d=p;
        p=p->nt;
        delete d;
    }
    return;
}

void doublist::ClearList(){
    DLn *p=head->nt;
    while(p){
        DLn *d=p;
        p=p->nt;
        delete d;
    }
    return;
}

void doublist::AInsertList(int ad, int x){
    if(ad>Size||ad<1)
        return;
    if(ad==Size){
        DLn *p=new DLn;
        p->data=x;
        p->nt=nullptr;
        DLn *fa=head->nt;
        while(fa)
            fa=fa->nt;
        fa->nt=p;
        p->lt=fa;
    }
    int i=0;
    DLn *now=head;
    while(now&&i<ad){
        now=now->nt;
        i++;
    }
    DLn *in=new DLn;
    in->data=x;
    in->nt=now->nt;
    now->nt->lt=in;
    now->nt=in;
    in->lt=now;
    return;
}

void doublist::BInsertList(int ad, int x){
    if(ad<1||ad>Size)
        return;
    DLn *now=head;
    int i=0;
    while(i<ad&&now){
        now=now->nt;
        i++;
    }
    DLn *p=new DLn;
    p->data=x;
    p->lt=now->lt;
    p->nt=now;
    now->lt->nt=p;
    return;
}

int  doublist::DeleteElem(int ad){
    if(ad<1||ad>Size){
        return -1;
    }
    DLn *p=head;
    int i=0;
    while(p&&i<ad){
        p=p->nt;
        i++;
    }
    p->lt->nt=p->nt;
    p->nt->lt=p->lt;
    int ans=p->data;
    delete p;
    Size--;
    return ans;
}

bool doublist::ListEmpty(){
    return head->nt==nullptr;
}

int  doublist::ListSize(){
    return Size;
}

int  doublist::ListQuery(int ad){
    if(ad<1||ad>Size)
        return -1;
    DLn *p=head;
    int i=0;
    while(p){
        p=p->nt;
        i++;
        if(i==ad)
            return p->data;
    }
    return -1;
}

void doublist::APrintList(){
    DLn *p=head->nt;
    while(p){
        printf("%d ",p->data);
        p=p->nt;
    }
    printf("\n");
    return;
}

void doublist::BPrintList(){
    DLn *p=head->nt;
    while(p){
        p=p->nt;
    }
    while(p!=head){
        printf("%d ",p->data);
        p=p->lt;
    }
    printf("\n");
    return;
}


class CircleList{
private:
    node *head;
    int Size;
public:
    bool CreatList();//
    void DestoryList();//
    void Increase(int x);//insert at the end of this list
    void InsertIn(int ad,int x);//insert an element in this list
    void DeleteEle(int ad);//delete an element
    bool ListEmpty();//either the list is empty or not
    int  ListLength();//return the length of this list
    void ListTrverse();//visit every element of this list
};

bool CircleList::CreatList(){
    head=new node;
    Size=0;
    if(head){
        head->next=nullptr;
        return true;
    }
    else
        return false;
}

void CircleList::DestoryList(){//where is the last pointer
    node *p=head->next;
    while(p){
        node *d=p;
        p=p->next;
        delete d;
    }
    delete head;
    return;
}

void CircleList::Increase(int x){
    if(head->next==nullptr){
        node *p=new node;
        p->data=x;
        p->next=p;
        head->next=p;
        Size++;
        return;
    }
    else{
        node *p=head->next;
        node *ed=p;
        while(p->next!=ed){
            p=p->next;
        }
        node *a=new node;
        a->data=x;
        a->next=ed;
        p->next=a;
        Size++;
        return;
    }
}

void CircleList::InsertIn(int ad, int x){
    node *p=head->next;
    int i=1;
    while(i<Size&&p&&i<ad-1){
        p=p->next;
        i++;
    }
    node *a=new node;
    a->data=x;
    a->next=p->next;
    p->next=a;
    return;

}

void CircleList::DeleteEle(int ad){
    if(ad<1||ad>Size)
        return;
    if(ad==1){
        node *ls;
        int i=1;
        while(i<Size){
            ls=ls->next;
            i++;
        }
        node *be=head->next;
        node *rb=be->next;
        ls->next=rb;
        head->next=rb;
        delete be;
        Size--;
        return;
    }
    node *p=head->next;
    int i=1;
    while(i<ad-1&&p&&i<=Size){
        p=p->next;
        i++;
    }
    node *d=p->next;
    node *q=d->next;
    p->next=q;
    delete d;
    Size--;
    return;
}

bool CircleList::ListEmpty(){
    return Size==0;
}

int  CircleList::ListLength(){
    return Size;
}

void CircleList::ListTrverse(){
    node *p=head->next;
    int i=1;
    while(i<=Size&&p){
        printf("%d ",p->data);
        p=p->next;
        i++;
    }
    printf("\n");
    return;
}


#endif // SINGLYLINKEDLIST_H_INCLUDED
