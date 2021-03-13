#include<iostream>

using namespace std;

struct Node {
	int info;
	Node* next;
};

typedef Node* PNode;
typedef Node* LinkedList;

void ListInit(LinkedList& H) {
	H = NULL;
}
bool IsEmpty(LinkedList  H) {
	return (H == NULL); 
}
//bo sung dau danh sach
void InsertBegin(LinkedList& H, int K) {
	PNode Q = new Node;
	Q->info = K;
	if (H == NULL) {
		Q->next = NULL;
		H = Q;
	}
	else {
		Q->next = H;
		H = Q;
	}
}
//bo sung sau phan tu hien tai
PNode InsertAfter(LinkedList& H, PNode P, int K) {
	PNode Q = new Node;
	Q->info = K;
	if (H == NULL) {
		Q->next = NULL;
		H = Q;
	}
	else {
		if (P == NULL) return NULL;
		Q->next = P->next;
		P->next = Q;
	}
	return Q;
}
//bo sung truoc phan tu hien tai
PNode InsertBefore(LinkedList& H, PNode P, int K) {
	PNode Q = new Node;
	Q->info = K;
	if (H == NULL) {
		H = Q;
		Q->next = NULL;
		return Q;
	}
	else {
		if (P == NULL) return NULL;
		Q->info = P->info;
		P->info = K;
		Q->next = P->next;
		P->next = Q;
	}
	return P;
}
//xoa dau danh sach
void DeleteHeadNode(LinkedList& H, PNode P) {
	if (H == NULL)
		cout << "danh sach rong " << endl;
	else {
		PNode P = H;
		H = H->next;
		delete P;
	}
}
//xoa node hien tai
void DeleteNode(LinkedList& H, PNode P) {
	if (H == NULL)
		cout << "danh sach rong " << endl;
	if (H == P && P->next == NULL) {
		H = NULL;
		delete P;
	}
	else {
		if (H == P) {
			H = P->next;
			delete P;
		}
		else {
			PNode R = H;
			while (R->next != P) R = R->next;
			R->next = P->next;
			delete P;
		}
	}
}
PNode SearchNode(LinkedList& H, int K) {
	PNode P = H;
	while (P != 0) {
		if (P->info == K)
			return P;
		else P = P->next;
	}
	return 0;
}
void Traverse(LinkedList H) { 
	PNode P;P = H;
	while (P != NULL) { 
		//Visit(P);
		P = P->next; 
	} 
}
int ListLength(LinkedList H) { 
	PNode P;
	P = H;
	int count = 0;
	while (P != NULL) { 
		count++;P = P->next; 
	}
	return count; 
}
int main()
{
	return 0;
}