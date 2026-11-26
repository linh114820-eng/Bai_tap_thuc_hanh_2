#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct    {
     char hoten[30];
     int masv;
     float d1, d2, d3;
}Data;
typedef struct tagNode    {
     Data infor;
     struct tagNode *link;
}Node;
typedef struct    {
     Node *pHead;  
     Node *pTail;
     int spt;
}LList;
/////////////////////////////////////
void initList(LList *L)
    {
     L->pHead = NULL;
     L->pTail = NULL;
     L->spt = 0;
    }
/////////////////////////////////////
int emptyList(LList L)
 {
     return (L.spt == 0); 
}
/////////////////////////////////////
void insert_Head(LList *L, Data x)
    {
     Node *pp;
     pp = (Node*) malloc(sizeof(Node));
     pp->infor = x;
     pp->link = NULL;
     if(emptyList(*L)){
       L->pHead = pp;
       L->pTail = pp;
      }   
        else {
      pp->link = L->pHead;
      L->pHead = pp;
      }
     L->spt++;
    }
///////////////////////////////////////
void nhap(Data *x){
    printf("Nhap ma sv: ");
    scanf("%d", &(x->masv));
    if(x->masv > 0){
        printf("Nhap ma sv: ");
        scanf("%s", (x->hoten));
        printf("Nhap diem mon 1: ");
        scanf("%f", &(x->d1));
        printf("Nhap diem mon 2: ");
        scanf("%f", &(x->d2));
        printf("Nhap diem mon 3: ");
        scanf("%f", &(x->d3));
    }
}
void in(Data x){
    printf("Ten: %s, Ma: %d, Diem 1: %.2f, Diem 2: %.2f, Diem 2: %.2f\n", 
            x.hoten, x.masv, x.d1, x.d2, x.d3);
}
void processList(LList L){
    Node *pp = L.pHead;
    while( pp != NULL ){
         in(pp->infor); //in d? li?u trong node 
         pp = pp->link;
     }
}
/////////////////////////////////////////
void insert_Tail(LList *L, Data x)
    {
     Node *pp;
     pp = (Node*) malloc(sizeof(Node));
     pp->infor = x;
     pp->link = NULL;
     if(emptyList(*L)){
       L->pHead = pp;
       L->pTail = pp;
      }   
        else {
      L->pTail->link = pp;
      L->pTail = pp;
      }
     L->spt++;
    }
///////////////////////////////////////////
void del_Head(LList*L){
	Node *pp;
	if(emptyList(*L)) return;
	else {
		pp = L->pHead;
		L->pHead = pp->link;
		free(pp);
		L->spt--;
		if(L->pHead==NULL) L->pTail=NULL;
		}
	}
//////////////////////////////////////////////////////
void del_After(LList *L, Node *q) {
    Node *pp;
    if(q == NULL || q->link == NULL) return;
    pp = q->link;
    q->link = pp->link;
    if(pp == L->pTail) L->pTail = q;
    free(pp);
    L->spt--;
}
//////////////////////////////////////////////////
void del_Name(LList *L, char Name[30]) {
    Node *pp = L->pHead, *q = NULL;
    while(pp != NULL && !strstr(pp->infor.hoten, Name)) {
        q = pp;
        pp = pp->link;
    }
    if(NULL == pp) return;
    else {
        if(pp == L->pHead) del_Head(L);
        else del_After(L, q); 
    }
}		
////////////////////////////////////////////////

Node* search_Name(LList L, char Name[30]) {
    Node *pp = L.pHead;
    while(pp != NULL && !strstr(pp->infor.hoten, Name)) {
        pp = pp->link;
    }
    return pp;
}
////////////////////////////////////////////////
void insert_After(LList *L, Node *q, Data x) {
    Node *pp;
    if(NULL == q) return;
    else {
        pp = (Node*) malloc(sizeof(Node));
        pp->infor = x;
        pp->link = q->link;
        q->link = pp;
        if(q == L->pTail) L->pTail = pp;
        L->spt++;
    }
}
///////////////////////////////////////////////
	
int main(){
    LList L;
 	int kt = 0;
 	Data x;
 	char Name[30];
 	initList(&L); //tao ra 1 ds rong
 do{
     printf("\nChuong trinh lam viec voi DSLK don SV\n");
     printf("\n1: Them nut vao dau danh sach");
     printf("\n2: Them nut vao cuoi danh sach");
     printf("\n3: Them nut vao sau mot nut khac trong danh sach");
     printf("\n4: Xoa nut theo ten danh sach");
     printf("\n9: Duyet ds");
     printf("\n0: Thoat");
     printf("\nMoi ban chon: ");
     int chon;
     scanf("%d", &chon);
     switch(chon){
        case 1: 
            printf("Nhap so thông tin sv can them\n");
            nhap(&x);
            if(x.masv > 0) 
                insert_Head(&L, x);
            break;
        case 2: 
            printf("Nhap so thông tin sv can them\n");
            nhap(&x);
            if(x.masv > 0) 
                insert_Tail(&L, x);
            break;
            
        case 3:
        	{
        	printf("Ban muon them vao sau nguoi ten gi? ");
                scanf(" %[^\n]", Name);
                Node *q = search_Name(L, Name);
                if(q != NULL) {
                    printf("Nhap thong tin sv can them\n");
                    nhap(&x);
                    if(x.masv > 0)
                        insert_After(&L, q, x);
                } else {
                    printf("Khong tim thay sinh vien!\n");
                }
                break;
        }
        case 4: 
        	printf("Ban muon xoa nguoi co ten la gi? ");
            scanf(" %[^\n]", Name);
            del_Name(&L, Name);
            break;
        case 9: 
                processList(L);
                break;    
        case 0: 
                printf("Bye bye\n");
             kt = 1;	
        }
 }while(kt==0); 
}
