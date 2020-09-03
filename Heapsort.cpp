#include<iostream>

using namespace std;

void Heapify(int Tree[], int MaxSize, int CurrentNode){

    int Parent=CurrentNode;
    int LeftChild=2*CurrentNode+1;
    int RightChild=2*CurrentNode+2;

    if(LeftChild<MaxSize && Tree[LeftChild]>Tree[Parent]){

        Parent=LeftChild;
    }
    if(RightChild<MaxSize && Tree[RightChild]>Tree[Parent]){

        Parent=RightChild;
    }
    if(Parent!=CurrentNode){

        swap(Tree[CurrentNode],Tree[Parent]);
        Heapify(Tree,MaxSize,Parent);
    }



}

void HeapSort(int Tree[], int MaxSize){

    int Start=0;
    int MidPoint=(MaxSize/2)-1;
    int End=MaxSize-1;

    for(int i=MidPoint; i>=0; i--){
        Heapify(Tree,MaxSize,i);
    }

    for(int i=End; i>=0; i--){
        swap(Tree[Start],Tree[i]);
        Heapify(Tree,i,Start);
    }


}

int main(){

    int MaxSize;

    cout<<"Enter MaxSize: ";
    cin>>MaxSize;

    int Tree[MaxSize];

    for(int i=0; i<MaxSize; i++){
        cin>>Tree[i];
    }

    for(int i=0; i<MaxSize; i++){
        cout<<"["<<Tree[i]<<"]";
    }
    cout<<endl;

    HeapSort(Tree,MaxSize);

    for(int i=0; i<MaxSize; i++){
        cout<<"["<<Tree[i]<<"]";
    }


return 0;
}
