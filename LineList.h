
#ifndef HEADER_ONCE_INCLUDE

#define HEADER_ONCE_INCLUDE



#include <iostream>
#include <cstdio>
#define max_line 1111111
using namespace std;


class linelist{
private:
    int *a,Size;
public:
    void InitList(){//初始化线性表
        a=new int[max_line];
        Size=0;
    }
    void DestroyList(){//销毁线性表，释放内存
        delete [] a;
        Size=0;
        return;

    }
    void ClearList(){//清空线性表，线性表依然存在
        Size=0;
        return;
    }
    bool ListEmpty(){//判断线性表是否为空
        return Size==0;
    }
    int ListLength(){//返回线性表的当前长度
        return Size;
    }
    bool GetElem(int i,int &e){//取出线性表第i个元素保存到e中
        if(i>=0&&i<Size){
            e=a[i];
            return true;
        }
        else
            return false;
    }
    int LocateElem(int e,bool (*cmp)(int x,int y)){//找到线性表中第一个与e满足cmp函数关系的元素，并返回位置
        if(cmp==NULL){
            for(int i=0;i<Size;i++){
                if(e==a[i])
                    return i+1;
            }
            return 0;
        }
        else{
            for(int i=0;i<Size;i++){
                if(cmp(e,a[i])){
                    return i+1;
                }
            }
            return 0;
        }
    }
    void PriorElem(int cur_e,int &pre_e){//返回cur_e元素的直接前驱元素
        for(int i=0;i<Size;i++){
            if(cur_e==a[i]&&i>=1){
                pre_e=a[i-1];
                return;
            }
        }
        return;
    }
    void NextElem(int cur_e,int &next_e){//返回cur_e元素的直接后继元素
        for(int i=0;i<Size;i++){
            if(cur_e==a[i]&&i<Size-1){
                next_e=a[i+1];
                return;
            }
        }
        return;
    }
    bool ListInsert(int i,int e){//在线性表i位置插入e
        if(i<1||i>Size+1)
            return false;
        i-=1;
        for(int j=Size-1;j>=i;j--){
            a[j+1]=a[j];
        }
        a[i]=e;
        Size+=1;
        return true;
    }
    bool ListDelete(int i,int &e){//删除线性表i位置的元素，并将它存到e中
        if(i<1||i>Size)
            return false;
        i-=1;
        e=a[i];
        for(int j=Size-1;j>i;j--){
            a[j-1]=a[j];
        }
        Size--;
        return true;
    }
    void ListTraverse(){//输出线性表
        for(int i=0;i<Size;i++)
            printf("%d ",a[i]);
        printf("\n");
        return;
    }
    void MergeList(linelist lb,linelist &lc);//将两个线性表在保证大小顺序的情况下合并（默认原线性表已排序
    void Listunion(linelist lb);//将两个线性表以集合形式合并
};

void linelist::MergeList(linelist lb,linelist &lc){
    int len=lb.Size;
    lc.InitList();
    int i=0,j=0,k=0;
    while(i<Size&&j<len){
        if(a[i]>=lb.a[j]){
            int x;
            lb.GetElem(j++,x);
            lc.ListInsert(k+1,x);
        }
        else{
            lc.ListInsert(k+1,a[i]);
            i++;
        }
        k++;
    }
    while(i<Size){
        lc.ListInsert(k+1,a[i++]);
        k++;
    }
    while(j<len){
        int x;
        lb.GetElem(j++,x);
        lc.ListInsert(k+1,x);
        k++;
    }
    return;
}

void linelist::Listunion(linelist lb){
    int len=lb.ListLength();
    for(int i=0;i<len;i++){
        int x;
        lb.GetElem(i,x);
        if(!LocateElem(x,nullptr)){
            ListInsert(Size+1,x);
        }
    }
    return;
}


#endif // HEADER_ONCE_INCLUDE
