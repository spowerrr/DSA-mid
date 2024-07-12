#include <iostream>

struct node {
    int data;
    struct node * next;
}*head=NULL;


struct node* createNode(int x){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=x;
    newNode->next=NULL;
    return newNode;
}

void insertEnding(int val){
    struct node * newNode = createNode(val);
    if(head==NULL){
        head= newNode;
    }else{
    struct node * tempNode= head;
    while (tempNode->next != NULL)
    {
        tempNode= tempNode->next;
    }
    
    tempNode->next=newNode;
    }

}
void printAllLinkedList(){
    struct node *temp = head;
    while (temp != NULL) {
        std::cout << temp->data << " --> ";
        temp = temp->next;
    }
    std::cout << std::endl;
}



double calculateAverageOfEvenPosition(){
    int index=0,evenCount=0;
    double evenSum=0;
    struct node * tempNode = head;
    while(tempNode!= NULL){
        if(index%2==0){
            evenSum += tempNode->data;
            evenCount++;
        }
        tempNode=tempNode->next;
        index++;
    }
    return evenSum/evenCount;
}

int calculateSumOfOddPosition(){
    int index=0;
    int oddSum=0;
    struct node * tempNode = head;
    while(tempNode!= NULL){
        if(index%2 != 0){
            oddSum += tempNode->data;
        }
        tempNode=tempNode->next;
        index++;
    }
    return oddSum;
}
void printEvenNumbers() {
    struct node * tempNode= head;
    std::cout <<"Even-numbered elements: ";
    while (tempNode != NULL) {
        if (tempNode->data % 2 == 0) {
            std::cout << tempNode->data << ", ";
        }
        tempNode = tempNode->next;
    }
}

int main(){
    //now we are inserting 1,2,3,4,5,6
    insertEnding(1);
    insertEnding(2);
    insertEnding(3);
    insertEnding(4);
    insertEnding(5);
    insertEnding(6);

    printAllLinkedList();

    double x= calculateAverageOfEvenPosition();
    std::cout<<"Average of even index elements: "<<x<<std::endl;

    int y= calculateSumOfOddPosition();
    std::cout<<"Sum of odd index elements: "<<y<<std::endl;
    printEvenNumbers();

}