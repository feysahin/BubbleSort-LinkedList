#include<stdio.h>
#include<stdlib.h>

typedef struct bubble{
	int data;
	struct bubble *next;
}BUBBLE;

BUBBLE *create_node();

void enter_data(BUBBLE **, int);
void traverse();
void bubbleSort(BUBBLE **, int);

int main(){
	BUBBLE *head = NULL;

	int n;
	printf("How many numbers do you want to bubble? ");
	scanf("%d", &n);
	
	head = create_node();
	
	enter_data(&head,n);
	printf("\n");
	traverse(&head);
	
	bubbleSort(&head,n);
	printf("\n");
	traverse(&head);
	
	return 0;
}

void enter_data(BUBBLE **phead, int n){
	int i;
	
	BUBBLE *node = create_node(), *tmp;
	*phead=node;
	 
	for(i=0; i<n; i++){
		printf("\n%d. num: ", i+1);
		scanf("%d", &node->data);
		node->next = create_node();
		tmp=node;		
		node=node->next; 
	}
	tmp->next = NULL;
	free(node);
}

void bubbleSort(BUBBLE **phead, int n){
	int i, j, k=n-2;
	BUBBLE *tmp = *phead, *prev, *post; //*phead=head
		
	for(i=0; i<n-1; i++){
		
		//her kontrol turunun baþýnda ilk eleman deðiþikliði yapýlabilir.
		if(tmp->data > tmp->next->data){
				printf("\ntmp->data: %d ve tmp->next->data: %d\t", tmp->data, tmp->next->data);
				post = tmp->next->next;
				prev = tmp->next;
				prev->next = tmp;
				tmp->next = post;
				*phead = prev;
				traverse(phead);
				//ilk 2 eleman kontrol edildiði için tmp 2. elemaný göstermekte dolayýsýyla sýradaki while'da 1 az eksik kontrol edilmesini istiyoruzç
				j=1;
		}
		//üstteki if'e girmediði için tmp en baþta kaldý dolayýsýyla sýradaki while'da 1 tur fazla kontrol edilmesini istiyoruz.
		else j = 0;
		
		while(j<n-i-1){
			if(i!=0 || j!=k){
				if(tmp->data > tmp->next->data){
					printf("\ntmp->data: %d ve tmp->next->data: %d\t", tmp->data, tmp->next->data);					
					post = tmp->next;
					tmp->next = tmp->next->next;
					prev->next = post;
					post->next = tmp;
					prev = post;
					traverse(phead);
				}
				else{
					prev = tmp;
					tmp = tmp->next;
				}
			}	
			j++;		
		}
		//sadece ilk kontrol turunda next'i NULL olan elemana da bakýldýðý için sadece bu turda son 2 eleman swapi yapýlmalýdýr.
		if(i==0 && tmp->data > tmp->next->data){
			printf("\ntmp->data: %d ve tmp->next->data: %d\t", tmp->data, tmp->next->data);
			post = tmp->next;
			post->next = tmp;
			prev->next = post;
		 	tmp->next = NULL;
			traverse(phead);	
		}		
		tmp = *phead;
	}
}

void traverse(BUBBLE **phead){
	BUBBLE *node = *phead;
	while(node != NULL){
		printf("%d  ", node->data);
		node = node->next;
	}
	printf("\n");
}

BUBBLE *create_node(){
	return (BUBBLE*)malloc(sizeof(BUBBLE));
}
