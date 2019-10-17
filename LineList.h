
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
    void InitList(){//��ʼ�����Ա�
        a=new int[max_line];
        Size=0;
    }
    void DestroyList(){//�������Ա��ͷ��ڴ�
        delete [] a;
        Size=0;
        return;

    }
    void ClearList(){//������Ա����Ա���Ȼ����
        Size=0;
        return;
    }
    bool ListEmpty(){//�ж����Ա��Ƿ�Ϊ��
        return Size==0;
    }
    int ListLength(){//�������Ա�ĵ�ǰ����
        return Size;
    }
    bool GetElem(int i,int &e){//ȡ�����Ա��i��Ԫ�ر��浽e��
        if(i>=0&&i<Size){
            e=a[i];
            return true;
        }
        else
            return false;
    }
    int LocateElem(int e,bool (*cmp)(int x,int y)){//�ҵ����Ա��е�һ����e����cmp������ϵ��Ԫ�أ�������λ��
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
    void PriorElem(int cur_e,int &pre_e){//����cur_eԪ�ص�ֱ��ǰ��Ԫ��
        for(int i=0;i<Size;i++){
            if(cur_e==a[i]&&i>=1){
                pre_e=a[i-1];
                return;
            }
        }
        return;
    }
    void NextElem(int cur_e,int &next_e){//����cur_eԪ�ص�ֱ�Ӻ��Ԫ��
        for(int i=0;i<Size;i++){
            if(cur_e==a[i]&&i<Size-1){
                next_e=a[i+1];
                return;
            }
        }
        return;
    }
    bool ListInsert(int i,int e){//�����Ա�iλ�ò���e
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
    bool ListDelete(int i,int &e){//ɾ�����Ա�iλ�õ�Ԫ�أ��������浽e��
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
    void ListTraverse(){//������Ա�
        for(int i=0;i<Size;i++)
            printf("%d ",a[i]);
        printf("\n");
        return;
    }
    void MergeList(linelist lb,linelist &lc);//���������Ա��ڱ�֤��С˳�������ºϲ���Ĭ��ԭ���Ա�������
    void Listunion(linelist lb);//���������Ա��Լ�����ʽ�ϲ�
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
