//Cây nhị phân and Danh sách liên kết 

//Cây nhị phân
// tiền tố là NLR, hậu tố là LRN
#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* pLeft;
    struct node* pRight;
};
typedef struct node NODE;
typedef NODE* TREE;

void khoitaocay(TREE& t)
{
    t = NULL;
}

void themnodevaocay(TREE& t, int x)
{
    if (t == NULL)
    {
        NODE* p = new NODE;
        p->data = x;
        p->pLeft = NULL;
        p->pRight = NULL;
        t = p;
    }
    else
    {
        if (t->data > x)
        {
            themnodevaocay(t->pLeft, x);
        }
        else if (t->data < x)
        {
            themnodevaocay(t->pRight, x);
        }
    }
}

void NLR(TREE t)
{
    if (t != NULL)
    {
        cout << t->data << " ";
        NLR(t->pLeft);
        NLR(t->pRight);
    }
}

void NRL(TREE t)
{
    if (t != NULL)
    {
        cout << t->data << " ";
        NRL(t->pRight);
        NRL(t->pLeft);
    }
}

void LNR(TREE t)
{
    if (t != NULL)
    {
        NRL(t->pLeft);
        cout << t->data << " ";
        NRL(t->pRight);
    }
}

void RNL(TREE t)
{
    if (t != NULL)
    {
        NRL(t->pRight);
        cout << t->data << " ";
        NRL(t->pLeft);
    }
}

void RLN(TREE t)
{
    if (t != NULL)
    {
        NRL(t->pRight);
        NRL(t->pLeft);
        cout << t->data << " ";
    }
}

void LRN(TREE t)
{
    if (t != NULL)
    {
        NRL(t->pLeft);
        NRL(t->pRight);
        cout << t->data << " ";
    }
}

//hàm kiểm tra số nguyên tố
bool checksnt(int x)
{
    if (x < 2)
    {
        return false;
    }
    else
    {
        if (x == 2)
        {
            return true;
        }
        else
        {
            if (x % 2 == 0)
            {
                return false;
            }
            else
            {
                for (int i = 2;i < x;i++)
                {
                    if (x % i == 0)
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

void soluongsnt(TREE t, int& dem)
{
    if (t != NULL)
    {
        if (checksnt(t->data) == true)
        {
            dem++;
        }
        soluongsnt(t->pLeft, dem);
        soluongsnt(t->pRight, dem);
    }
}

//neu node tồn tại trong cây thì trả về node đó , còn ko trả về NULL
NODE* find(TREE t, int n)
{
    if (t == NULL)
    {
        return NULL;
    }
    else
    {
        if (n < t->data)
        {
            find(t->pLeft, n);
        }
        else if (n > t->data)
        {
            find(t->pRight, n);
        }
        else //t->data==x
        {
            return t;
        }
    }
}

//xuất node có 2 con
void NODE_2con(TREE t)
{
    if (t != NULL)
    {
        if (t->pLeft != NULL && t->pRight != NULL)
        {
            cout << t->data << " ";
        }
        NODE_2con(t->pLeft);
        NODE_2con(t->pRight);
    }
}
//xuất node có 1 con
void NODE_1con(TREE t)
{
    if (t != NULL)
    {
        if ((t->pLeft != NULL && t->pRight == NULL) || (t->pLeft == NULL && t->pRight != NULL))
        {
            cout << t->data << " ";
        }
        NODE_1con(t->pLeft);
        NODE_1con(t->pRight);
    }
}

//xuat node không có nhánh nào 
void NODE_la(TREE t)
{
    if (t != NULL)
    {
        if (t->pLeft == NULL && t->pRight == NULL)
        {
            cout << t->data << " ";
        }
        NODE_la(t->pLeft);
        NODE_la(t->pRight);
    }
}

//tìm số lớn nhất trong cây
int findmax(TREE t)
{
    if (t->pRight == NULL)
    {
        return t->data;
    }
    return findmax(t->pRight);
}

int findmin(TREE t)

{
    if (t->pLeft == NULL)
    {
        return t->data;
    }
    return findmin(t->pLeft);
}

void findnodethemang(TREE& X, TREE& Y)
{
    //cách 1 tìm node trái nhất cảu cánh phải
    if (Y->pLeft != NULL)
    {
        findnodethemang(X, Y->pLeft);
    }
    else
    {
        X->data = Y->data;
        X = Y;
        Y = Y->pRight;
    }
    // //cách 2 tìm node phải nhất cảu cánh trái
    // if(Y->pRight!=NULL)
    // {
    //     findnodethemang(X,Y->pRight);
    // }
    // else
    // {
    //     X->data=Y->data;
    //     X=Y;
    //     Y=Y->pLeft; 
    // }
}

void xoanode(TREE& t, int data)
{
    if (t == NULL)
    {
        return;
    }
    else
    {
        if (data < t->data)
        {
            xoanode(t->pLeft, data);
        }
        else if (data > t->data)
        {
            xoanode(t->pRight, data);
        }
        else //data==t->data
        {
            NODE* X = t;
            if (t->pLeft == NULL)
            {
                t = t->pRight;
            }
            else if (t->pRight == NULL)
            {
                t = t->pLeft;
            }
            else //node cần xóa là node có 2 con
            {
                //cách 1 tìm node trái nhất của nhánh phải 
                findnodethemang(X, t->pRight);
            }
            // else //node cần xóa là node có 2 con
            // {
            //     //cách 2 tìm node phải nhất của nhánh trái 
            //     findnodethemang(X,t->pLeft);
            // }
            delete X;
        }
    }
}
//tính chiều cao của cây
int height(TREE t)
{
    if (t == NULL || (t->pLeft == NULL && t->pRight == NULL))
    {
        return 0;
    }
    else
    {
        int leftheight = height(t->pLeft);
        int rightheight = height(t->pRight);
        return 1 + max(leftheight, rightheight);
    }
}

void menu(TREE& t)
{
    int xoa;
    cout << "\nnhap gia tri can xoa ";
    cin >> xoa;
    xoanode(t, xoa);
    NLR(t);
}

//đếm số lượng những số đã nhập
int demla(TREE t)
{
	if (t == NULL)
	{
		return 0;
	}
	if (t->pLeft == NULL && t->pRight == NULL)
	{
		return 1;
	}
	else {
		return (demla(t->pLeft) + demla(t->pRight));
	}
}
//Tính tổng tất cả các số đã nhập
int sum(TREE t)
{
	if (t == NULL || t->data != ((sum(t->pLeft) + sum(t->pRight) + t->data) / demla(t)))
	{
		return 0;
	}
	else if (t->data == ((sum(t->pLeft) + sum(t->pRight) + t->data) / demla(t)))
	{
		return 1;
	}
}



int main()
{
    TREE t;
    khoitaocay(t);
    int x;
    int dem = 0;
    while (true)
    {
        cin >> x;
        if (x == 0)
        {
            break;
        }
        else
        {
            themnodevaocay(t, x);
        }
        NLR(t);
    }
    soluongsnt(t, dem);
    cout << "\nso luong so nguyen to la " << dem << endl;
    int n;
    cout << "\n\tnhap phan tu can tim kiem ";
    cin >> n;
    NODE* p = find(t, n);
    if (p == NULL)
    {
        cout << "phan tu " << n << " khong ton tai trong cay ! ";
    }
    else
    {
        cout << "phan tu " << n << " ton tai trong cay ! ";
    }
    cout << "\nnode co 2 con la ";
    NODE_2con(t);
    cout << "\nnode co 1 con la ";
    NODE_1con(t);
    cout << "\nnode khong co nhanh la  ";
    NODE_la(t);
    //findmax(t);
    // cout<<"\ngia tri lon nhat la "<<MAX<<endl;
    // findmin(t);
    // cout<<"\ngia tri lon nhat la "<<MIN<<endl;
    // findmin(t);
    cout << "\nnode lon nhat la " << findmax(t);
    cout << "\nnode nho nhat la " << findmin(t);
    menu(t);
    cout << "\nChiều cao của cây: " << height(t) + 1 << endl;
    system("pause");
}



Danh sách liên kết 
#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* pNext;
};
typedef struct node NODE;

struct list
{
    NODE* pHead;
    NODE* pTail;
};
typedef struct list LIST;

void khoitao(LIST& l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

NODE* khoitaoNODE(int x)
{
    NODE* p = new NODE;
    if (p == NULL)
    {
        cout << "khong du bo nho cap phat ! ";
        return NULL;
    }
    p->data = x;
    p->pNext = NULL;
    return p;
}

void themvaodau(LIST& l, NODE* p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void themvaocuoi(LIST& l, NODE* p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void xuatds(LIST l)
{
    if (l.pHead == 0)
    {
        cout << "danh sach rong ! ";
    }
    else
    {
        cout << "danh sach da nhap la : ";
        for (NODE* k = l.pHead;k != 0;k = k->pNext)
        {
            cout << k->data << " ";
        }
    }
}

int findmax(LIST l)
{
    int max = l.pHead->data;
    for (NODE* k = l.pHead;k != NULL;k = k->pNext)
    {
        if (max < k->data)
        {
            max = k->data;
        }
    }
    return max;
}

int findmin(LIST l)
{
    int min = l.pHead->data;
    for (NODE* k = l.pHead;k != NULL;k = k->pNext)
    {
        if (min > k->data)
        {
            min = k->data;
        }
    }
    return min;
}
// them node p vao sau node q(q la node co san trong ds lk)
void them1sovaosauvitribanmuon(LIST& l, NODE* p)
{
    int x;
    cout << "nhap vi tri phia truoc so ban can them ! ";
    cin >> x;
    NODE* q = khoitaoNODE(x);
    if (q->data == l.pHead->data && l.pHead->pNext == NULL)
    {
        themvaocuoi(l, p);
    }
    else
    {
        for (NODE* k = l.pHead;k != NULL;k = k->pNext)
        {
            if (q->data == k->data)
            {
                NODE* h = khoitaoNODE(p->data);
                NODE* g = k->pNext;
                h->pNext = g;
                k->pNext = h;
            }
        }
    }

}

void them1sovaotruocvitribanmuon(LIST& l, NODE* p)
{
    int x;
    cout << "nhap vi tri phia truoc so ban muon them ! ";
    cin >> x;
    NODE* q = khoitaoNODE(x);
    if (q->data == l.pHead->data && l.pHead->pNext == NULL)
    {
        themvaodau(l, p);
    }
    else
    {
        NODE* g = new NODE;
        for (NODE* k = l.pHead;k != NULL;k = k->pNext)
        {
            if (q->data == k->data)
            {
                NODE* h = khoitaoNODE(p->data);
                h->pNext = k;
                g->pNext = h;
            }
            g = k;//giữ liên kết với node nằm trước node q trong danh sách 
        }
    }
}

void themvaovitri(LIST& l, NODE* p, int vt, int n)
{
    if (l.pHead == NULL || vt == 1)
    {
        themvaodau(l, p);
    }
    else if (vt == n + 1)
    {
        themvaocuoi(l, p);
    }
    else
    {
        int dem = 0;//xac dinh vi tri can them 
        NODE* g = new NODE;
        for (NODE* k = l.pHead;k != 0;k = k->pNext)
        {
            dem++;
            if (dem == vt)
            {
                NODE* h = khoitaoNODE(p->data);
                h->pNext = k;
                g->pNext = h;
                break;
            }
            g = k;
        }
    }
}

void xoadau(LIST& l)
{
    if (l.pHead == NULL)
    {
        return;
    }
    NODE* p = l.pHead;
    l.pHead = l.pHead->pNext;
    delete p;
}

void xoacuoi(LIST& l)
{
    if (l.pHead == NULL)
    {
        return;
    }
    else if (l.pHead->pNext == NULL)
    {
        xoadau(l);
        return;
    }
    for (NODE* k = l.pHead;k != NULL;k = k->pNext)
    {
        if (k->pNext == l.pTail)
        {
            delete l.pTail;
            k->pNext = NULL;
            l.pTail = k;
            return;
        }
    }
}
//ham xoa 1 node nam sau node q trong danh sach
void xoasau(LIST& l, NODE* q)
{
    for (NODE* k = l.pHead;k != NULL;k = k->pNext)
    {
        if (k->data == q->data)
        {
            NODE* g = k->pNext;
            k->pNext = g->pNext;
            delete g;
        }
    }
}
void xoaso(LIST& l, int x)
{
    if (l.pHead == NULL)
    {
        return;
    }
    else if (l.pHead->data == x)
    {
        xoadau(l);
        return;
    }
    else if (l.pTail->data == x)
    {
        xoacuoi(l);
        return;
    }
    NODE* g = new NODE;
    for (NODE* k = l.pHead;k != NULL;k = k->pNext)
    {
        if (k->data == x)
        {
            g->pNext = k->pNext;
            delete k;
            return;
        }
        g = k;//cho node g tro den node k
    }
}

//xóa các phẩn tử trùng nhau
void removeDuplicates(List &l)
{
    struct Node *p, *q, *dup;
    p = l.pHead;

    while (p != NULL && p->pNext != NULL)
    {
        q = p;
        while (q->pNext != NULL)
        {
            if (p->data == q->pNext->data)
            {
                dup = q->pNext;
                q->pNext = q->pNext->pNext;
                delete (dup);
            }
            else
                q = q->pNext;
        }
        p = p->pNext;
    }
}
//chỉ xóa 2 số trùng nhau bằng nhau
NODE* deletebangnhau(LIST l)
{
    NODE* p, * q;
    if (l.pHead == NULL)
    {
        return l.pHead;
    }
    p = l.pHead;
    while (p->pNext != NULL)
    {
        if (p->data == p->pNext->data)
        {
            NODE* q = p->pNext;
            p->pNext = q->pNext;
            free(q);
        }
        else p = p->pNext;
    }
    return l.pHead;
}

void SortList(LIST& l)
{
    // for loop thứ nhất
    for (NODE* pTmp = l.pHead;pTmp != NULL;pTmp = pTmp->pNext)
    {
        //for loop thứ hai
        for (NODE* pTmp2 = pTmp->pNext;pTmp2 != NULL;pTmp2 = pTmp2->pNext)
        {
            if (pTmp->data > pTmp2->data) // nếu giá trị trước > giá trị sau thì hoán đổi hai vị trí
            {
                int tmp = pTmp->data;
                pTmp->data = pTmp2->data;
                pTmp2->data = tmp;
            }
        }
    }
}

int search(LIST l, int n)

{
    for (NODE* k = l.pHead;k != NULL;k = k->pNext)
    {
        if (k->data == n)
        {
            return 1;
        }
    }
    return 0;
}

void menu(LIST l)
{
    while (true)
    {
        int luachon;
        cout << "\n\n\t\t==========MENU==========";
        cout << "\n\t.1 tim so lon nhat ! ";
        cout << "\n\t.2 tim so nho nhat ! ";
        cout << "\n\t.3 them 1 so vao sau vi tri ban muon (them node p sau node q )";
        cout << "\n\t.4 them 1 so vao truoc vi tri ban muon (them node p truoc node q )";
        cout << "\n\t.5 them vi tri bat ki trong danh sach ";
        cout << "\n\t.6 xoa dau  ";
        cout << "\n\t.7 xoa cuoi  ";
        cout << "\n\t.8 xoa sau  ";
        cout << "\n\t.9 xoa so bat ki  ";
        cout << "\n\t.10 xoa nhung phan tu lien tiep trung nhau ";//vd 1 1 2 2 3 3 thanh 1 2 3 nhung 1 2 1 2 3 3 thi ra 1 2 1 2 3 
        cout << "\n\t.11 sap xep tang dan";
        cout << "\n\t.12 tim so ";
        cout << "\n\t.20 ket thuc chuong trinh ! ";
        cout << "\n\tlua chon cua ban la : ";
        cin >> luachon;
        cout << "\n\t\n\t==========END==========";
        if (luachon == 1)
        {
            cout << "\nso lon nhat la : " << findmax(l) << endl;
        }
        else if (luachon == 2)
        {
            cout << "\nso nho nhat la : " << findmin(l) << endl;
        }
        else if (luachon == 3)
        {
            int x;
            cout << "\nnhap so ban muon them ";
            cin >> x;
            NODE* p = khoitaoNODE(x);
            them1sovaosauvitribanmuon(l, p);
            xuatds(l);
        }
        else if (luachon == 4)
        {
            int x;
            cout << "\nnhap so ban muon them ";
            cin >> x;
            NODE* p = khoitaoNODE(x);
            them1sovaotruocvitribanmuon(l, p);
            xuatds(l);
        }
        else if (luachon == 5)
        {
            int n = 0;
            for (NODE* k = l.pHead;k != NULL;k = k->pNext)
            {
                n++;
            }
            int x;
            cout << "\nnhap so ban muon them ";
            cin >> x;
            NODE* p = khoitaoNODE(x);
            int vt;
            do
            {
                cout << "\nnhap vi tri can them : ";
                cin >> vt;
                if (vt<1 || vt>n + 1)
                {
                    cout << "\nvi tri can them phai nam trong khoang [1, " << n + 1 << "]";
                    system("pause");
                }
            } while (vt<1 || vt>n + 1);
            themvaovitri(l, p, vt, n);
            xuatds(l);
        }
        else if (luachon == 6)
        {
            xoadau(l);
            xuatds(l);
        }
        else if (luachon == 7)
        {
            xoacuoi(l);
            xuatds(l);
        }
        else if (luachon == 8)
        {
            int x;
            cout << "\nnhap so phia truoc so can xoa :  ";
            cin >> x;
            NODE* q = khoitaoNODE(x);
            xoasau(l, q);
            xuatds(l);
        }
        else if (luachon == 9)
        {
            int x;
            cout << "\nnhap so can xoa :  ";
            cin >> x;
            xoaso(l, x);
            xuatds(l);
        }
        else if (luachon == 10)
        {
            deletebangnhau(l);
            xuatds(l);
        }
        else if (luachon == 11)
        {
            SortList(l);
        }
        else if (luachon == 12)
        {
            int n;
            cin >> n;
            if (search(l, n) == 0)
            {
                cout << "khong tim thay " << n << endl;
            }
            else if (search(l, n) == 1)
            {
                cout << "co ton tai phan tu " << n << endl;
            }
        }
        else
        {
            break;
        }
    }
}
int main()
{
    LIST l;
    khoitao(l);
    int x;
    cout << "\nnhap lien tuc va nhap so 0 de dung lai !" << endl;
    while (true)
    {
        cin >> x;
        if (x == 0)
        {
            break;
        }
        else
        {
            NODE* p = khoitaoNODE(x);
            themvaocuoi(l, p);
        }
    }
    int ok;
    xuatds(l);
    cout << "\nneu ban muon tiep tuc tinh nang tren nhung du lieu ban cung cap hay nhan 1 de tiep tuc !";
    cin >> ok;
    if (ok == 1)
    {
        cout << "\nban da chon tiep tuc ! ";
        menu(l);
    }
    else
    {
        return 0;
    }
    xuatds(l);
    cout << "ban da ket thuc chuong trinh ! ";
    system("pause");
}
