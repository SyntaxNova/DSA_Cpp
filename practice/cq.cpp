#include<iostream>
using namespace std;


int const SIZE = 5 ;
class Queue{
    public:
    int items[SIZE];
    int front;
    int rear;

    Queue(){
        front = -1;
        rear = -1;
    }
    
    bool isfull(){
        if(front == 0 && rear == SIZE - 1){
            return true;    }
        else if (front == rear + 1){
            return true;}
        else
        return false;
    }

    bool isempty(){
        if(front == -1){
            return true;}
        else{
            return false;}
    }
    
    void enqueue(int element){
        if(isfull()){
            cout<<"Queue is full !"<<endl;
        }
        else{
            if(front == -1)
                front = 0 ;
                rear = (rear + 1) % SIZE ;
                items[rear] = element ;
                cout<<"Inserted : "<< element << endl ;
            
        }
    }
    
    int dequeue(){
        int element;
        if(isempty()){
            cout<<"Queue is empty "<<endl;
        }
        else 
            element = items[front];
            
            if(front == rear){
                front = -1;
                rear = -1;
            }
            else{
                front = (front + 1) % SIZE;
            }
            return element;
    }

    void display(){
        
        if(isempty()){
            cout<<"Queue is empty "<<endl;
        }
        else{
            int i ;
            cout<<"Front -> "<<front<<endl;
            cout<<"Items -> ";
            for( i = front ; i != rear ; i = (i + 1 )% SIZE ){
                cout<<items[i]<<" ";
            }
            cout<<items[i]<<endl;
            cout<<"Rear -> "<<rear;
        }
    }
};

int main(){
        Queue obj ;
        int element ;
        int choice;    

    do{
        
        cout<<"\n 1] Enqueue (Insertion) \n 2] Dequeue (Deletion)\n 3] Display \n 4] Escape \n ";
        cout<<"Enter Choice : ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter Number to be Inserted : ";
                cin>>element;
                obj.enqueue(element);
                break;
            case 2:
                obj.dequeue();
                break;
            case 3:
                obj.display();
                break;
            case 4:
                cout<<"Escaping..."<<endl;
                cout<<"Exited Succesfully";
                break;
        }
        
        
    }while(choice != 4);

    return (0);
}










