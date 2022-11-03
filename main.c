// Problem statement :
// Implement a linked list to store the marks of students
// Sort the linked list in descending order
// Remove the entries with marks less than 40

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include <windows.h>

struct node{
    struct node *next;
    int data;

};

struct node *head = NULL;
struct node *current = NULL;


bool isEmpty(){
    if(head==NULL){
        return true;
    }else{
        return false;
    }
}

int listLength(){
    int count = 0;
    if(isEmpty()){
        return 0;
    }else{

        current = head;
        while(current!=NULL){
            count++;
            current=current->next;
        }
        return count;
    }
    return count;
}
void displayList(){
    if(head==NULL){
        printf(" Linked List is empty \n");
        return;
    }
    current = head;
    do{
        printf(" %d",current->data);
        current = current->next;
    }while(current!=NULL);

    printf("\n List Length : %d",listLength());
}
void insertBeg(int data){
    struct node *link = (struct node *)malloc(sizeof(struct node));
    link->data=data;

    link->next=head;
    head = link;


}
void insertEnd(int data){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *temp;

    ptr->data=data;
    ptr->next = NULL;
    if(head==NULL){

        head=ptr;
    }else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=ptr;
    }
}
void insertPos(int data, int pos){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    ptr->data=data;
    if(pos==0){
        insertBeg(data);
    }
    temp=head;
    for(int i=0;i<pos;i++){
        temp=temp->next;
    }
    ptr->next=temp->next;
    temp->next=ptr;
}
void deleteBeg(){
    struct node *temp;
    temp=head;
    head = head->next;
    free(temp);
}
void deleteEnd(){
    struct node *temp;
    temp = head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    current = temp->next;
    temp->next=NULL;
    free(current);
}
void deletePos(int pos){
    struct node *temp;
    struct node *temp2;
    if(pos==0){
        deleteBeg();
    }else if(pos == listLength()-1){
        deleteEnd();
    }else if(pos>=listLength()){
        printf("Invalid Input");
    }else{
        temp2=head;
        for(int i=0;i<pos;i++){
            temp=temp2;
            temp2=temp2->next;
        }
        temp->next=temp2->next;
        temp2->next = NULL;
        free(temp2);
    }

}
void swapEle(int pos){ // this function swaps the elements at the nth and (n+1)th positions
    struct node *temp;
    struct node *temp2;
    temp2=head;
    if(pos==0){
        temp=head;
        temp2 = head->next;

        temp->next = temp2->next;
        head=temp2;
        temp2->next=temp;
    }else if(pos > listLength()-2){
        printf("\nInvalid Input\n");
    }
    else{
        temp=head;
        for(int i=0;i<pos;i++){
            current = temp;
            temp=temp->next;
            temp2=temp->next;
        }
        temp->next = temp2->next;
        temp2->next = temp;
        current->next = temp2 = NULL;

    }
}
void swap(struct node *a, struct node *b)
{
    int temp;
    temp = a->data;
    a->data = b->data;
    b->data = temp;
}
void sortListDescending(){
    struct node *temp;
    struct node *temp2;
    int swapped;
    if(head==NULL){
            return;
    }
    do{
        swapped=0;
        temp=head;

        while(temp->next!= temp2){
            if(temp->data < temp->next->data){
                swap(temp,temp->next);
                swapped=1;
            }
            temp=temp->next;
        }
        temp2 = temp;
    }while(swapped);
}

void RemoveFails(int cutoff){
    struct node *temp;
    struct node *temp2;
    temp = head;
    while(temp->next->data >= cutoff){
        temp=temp->next;
    }
    temp2=temp->next;
    temp->next = NULL;
    temp=temp2->next;
    while(temp->next!=NULL){
        temp2->next=NULL;
        free(temp2);
        temp2=temp;
        temp = temp->next;

    }
}
int main()
{
    int ch=0,pos,ele;
    while(ch!=12){
        printf("\n ---MENU---\n");
        printf(" 1. Display\n 2. Insert Beginning\n 3. Insert End\n");
        printf(" 4. Insert Position \n 5. Delete Beginning \n 6. Delete End\n");
        printf(" 7. Delete Position \n 8. Swap two adjacent elements \n 9. Sort list in descending order \n" );
        printf(" 10. Sort list in ascending order \n 11. Remove Values less than amount \n");
        scanf("%d", &ch);

        system("cls");
        switch(ch){
            case 1 :displayList();
                    break;
            case 2 :printf(" \n Enter element to enter : ");
                    scanf("%d", &ele);
                    insertBeg(ele);
                    printf(" \n The new list is : ");
                    displayList();
                    break;
            case 3 :printf(" \n Enter element to enter : ");
                    scanf("%d", &ele);
                    insertEnd(ele);
                    printf(" \n The new list is : ");
                    displayList();
                    break;
            case 4 :printf(" \n Enter element to enter : ");
                    scanf("%d", &ele);
                    printf(" \n Enter position to insert into : ");
                    scanf("%d", &pos);
                    insertPos(ele,pos);
                    printf(" \n The new list is : ");
                    displayList();
                    break;
            case 5 :deleteBeg();
                    printf(" \n The new list is : ");
                    displayList();
                    break;
            case 6 :deleteEnd();
                    printf(" \n The new list is : ");
                    displayList();
                    break;
            case 7 :printf(" \n Enter the position to delete : ");
                    scanf("%d", &pos);
                    deletePos(pos);
                    printf(" \n The new list is : ");
                    displayList();
                    break;
            case 8 :printf(" \n Enter the position to swap : ");
                    scanf("%d",&pos);
                    swapEle(pos);
                    printf(" \n The new list is : ");
                    displayList();
                    break;
            case 9 :sortListDescending();
                    printf(" \n The new list is : ");
                    displayList();
                    break;
            case 10:

                    break;
            case 11:printf(" \n Enter the passing Mark : ");
                    scanf("%d", &ele);
                    RemoveFails(ele);
                    printf(" \n The new list is : ");
                    displayList();
                    break;



            default:break;

        }



    }
    return 0;
}
