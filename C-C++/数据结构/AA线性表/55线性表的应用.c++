#include <iostream>
using namespace std;
#include <iomanip>

#define MaxCol 10

typedef int ElemType;

struct DList{
    ElemType data[MaxCol];
    DList *next;
};

struct HList{
    int Row, Col;
    DList *next;
};


void CreateTable(HList *&h){
    DList *las;
    h = new HList;
    h -> next = nullptr;
    
    cout << "the ROW and COL of table: ";
    cin >> h -> Row >> h -> Col;
    
    for (int i = 0; i < h -> Row; i++){
        cout << "the[" << i << "]row: ";
        DList *s = new DList;
        for (int j = 0; j < h -> Col; j++)
            cin >> s -> data[j];
        
        if (h -> next == nullptr)
            h -> next = s;
        else
            las -> next = s;

        las = s;
    }
    las -> next = nullptr;
}

void DestroyTable(HList *&h){
    DList *pre = h -> next;
    DList *p = pre -> next;
    while (p != nullptr){
        delete pre;
        pre = p;
        p = p -> next;
    }
    delete pre; pre = nullptr;
    delete p;   p = nullptr;
}

void DispTable(HList *h){
    DList *p = h -> next;
    while (p != nullptr){
        for (int j = 0; j < h -> Col; j++){
            cout << setw(4) << p -> data[j];
        }
        cout << endl;
        p = p -> next;
    }
}

// 等值连接
void LinkTable(HList *h1, HList *h2, HList *&h){
    DList *las;
    DList *p = h1 -> next;
    
    cout << "what's the index of unlink_table1 and unlink_table2: ";
    int i, j;
    cin >> i >> j;

    h = new HList;
    h -> Row = 0;
    h -> Col = h1 -> Col + h2 -> Col;
    h -> next = nullptr;

    while (p != nullptr){
        DList *q = h2 -> next;
        
        while (q != nullptr){
            if (p -> data[i - 1] == q -> data[j - 1]){
                DList *s = new DList;

                for (int k = 0; k < h1 -> Col; k++)
                    s -> data[k] = p -> data[k];
                for (int k = 0; k < h2 -> Col; k++)
                    s -> data[h1 -> Col + k] = q -> data[k];

                if (h -> next == nullptr)
                    h -> next = s;
                else 
                    las -> next = s;

                las = s;

                h -> Row++;
            }
            q = q -> next;
        }
        p = p -> next;
    }
    las -> next = nullptr;
}

int main (){
    HList *h1, *h2, *h;
    cout << "tabel_1: " << endl;
    CreateTable(h1);
    cout << "table_2: " << endl;
    CreateTable(h2);
    LinkTable(h1, h2, h);
    cout << "linked_res:" << endl;
    DispTable(h);
    DestroyTable(h1);
    DestroyTable(h2);
    DestroyTable(h);
    return 1;
}