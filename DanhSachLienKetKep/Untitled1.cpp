
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct    {
    char hoten[30];
    int masv;
    float d1, d2, d3;
}Data;
typedef struct tagNode   {
    Data infor;
    struct tagNode *prev;
    struct tagNode *next;    
}Node;
typedef struct    {
    Node *pHead;  
    Node *pTail;
    int spt;
}DList;
/////////////Tao danh  sach rong
void initList(DList *L){
    L->pHead = NULL;
    L->pTail = NULL;
    L->spt = 0;
}
/////////////////////////////////////
int emptyList(DList L){
    return (L.spt == 0); 
}
/////////////////////////////////////
void nhap(Data *x){
    printf("Nhap ma sv: ");
    scanf("%d", &(x->masv));
    if(x->masv > 0){
        printf("Nhap ho ten: ");
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
void processList(DList L){
    Node *pp = L.pHead;
    while( pp != NULL ){
         in(pp->infor); //in d? li?u trong node 
         pp = pp->next;
     }
}
/////////////////////////////////////////

void insert_Head(DList *L, Data x)
    {
    Node *pp;
    pp = (Node*) malloc(sizeof(Node));
    pp->infor = x;
    pp->next = NULL;
    pp->prev = NULL;
    if(emptyList(*L)){
    	L->pHead = pp;
    	L->pTail = pp;
    }   
    else {
    	L->pHead->prev = pp;
    	pp->next = L->pHead;
    	L->pHead = pp;
    }
     L->spt++;
    }
///////////////////////////////////////
void insert_Tail(DList *L, Data x)
    {
    Node *pp;
    pp = (Node*) malloc(sizeof(Node));
    pp->infor = x;
    pp->next = NULL;
    pp->prev = NULL;
    if(emptyList(*L)){
    	L->pHead = pp;
    	L->pTail = pp;
    }   
    else {
    	L->pTail->next = pp;
    	pp->prev = L->pTail;
    	L->pTail = pp;
    }
    L->spt++;
}
///////////////////////////////////////////
void del_Head(DList*L){
	Node *pp;
	if(emptyList(*L)) return;
	else {
		pp = L->pHead;
		L->pHead = pp->next;
		if(L->pHead!=NULL) L->pHead->prev=NULL;
		free(pp);
		L->spt--;
		if(L->pHead==NULL) L->pTail=NULL;
		}
	}
//////////////////////////////////////////////////////
void del_After(DList *L, Node *q) {
    Node *pp;
    if(NULL==q) return ;
    else{
    	pp = q->next;
    	q->next = pp->next;
    	if(pp->next !=NULL) pp->next->prev=q;
    	free(pp);
    	L->spt--;
    	if(NULL == L->pTail || pp==L->pTail)
    		L->pTail=q;
	}   
}
///////////////////////////////////////////////////
Node* search_Name(DList L, char Name[30]) {
    Node *pp = L.pHead;

    while(pp != NULL && !strstr(pp->infor.hoten, Name)) {
        pp = pp->next;
    }

    return pp;
}	
//////////////////////////////////////////////////
void del_Name(DList *L, char Name[30]) {
    Node *pp = search_Name(*L, Name);
    if(NULL==pp) return;
    if(pp == L->pHead) del_Head(L);
    else del_After(L, pp->prev);
}

////////////////////////////////////////////////
void insert_After(DList *L, Node *q, Data x) {
    Node *pp;
    if(NULL == q) return;
    pp = (Node*) malloc(sizeof(Node));
    pp->infor = x;
    pp->prev = q;
    pp->next = q->next;
	if(q->next != NULL)
		q->next->prev = pp;
	else
		L->pTail = pp;
	
	q->next = pp;
	L->spt++;
}
///////////////////////////////////////////////

int main(){
    DList L;
	int kt = 0;
	Data x;
	char Name[30];
	initList(&L); //tao ra 1 ds rong
do{
    printf("\nChuong trinh lam viec voi DSLK kep SV\n");
    printf("\n1: Them nut vao dau danh sach");
    printf("\n2: Them nut vao cuoi danh sach");
    printf("\n3: Them nut vao sau mot nut khac trong danh sach");
    printf("\n4: Xoa nut theo ten danh sach");
    printf("\n9: Duyet danh sach");
     printf("\n0: Thoat");
     printf("\nMoi ban chon: ");
     int chon;
     scanf("%d", &chon);
     switch(chon){
        case 1: 
            printf("Nhap so thong tin sv can them\n");
            nhap(&x);
            if(x.masv > 0) 
                insert_Head(&L, x);
            break;
        case 2: 
            printf("Nhap so thong tin sv can them\n");
            nhap(&x);
            if(x.masv > 0) 
                insert_Tail(&L, x);
            break;
            
        case 3:
        	{
        	printf("Them sau sinh vien ten: ");
            scanf(" %[^\n]", Name);
            Node *q = search_Name(L, Name);
            if(q != NULL) {
                printf("Nhap thong tin sv can them\n");
                nhap(&x);
                if(x.masv > 0)
                    insert_After(&L, q, x);
                } 
			else {
                printf("Khong tim  thay sinh vien!\n");
            }
            break;
        }
        case 4: 
        	printf("Nhap ten nguoi can xoa: ");
            scanf(" %[^\n]", Name);
            del_Name(&L, Name);
            break;
        case 9: 
        	printf("\nDanh sach tu dau den cuoi:\n");
            processList(L);
            break;    
        case 0: 
            printf("Bye bye\n");
            kt = 1;	
            break;
        }
 }while(kt==0); 
}

