#include<iostream>
using namespace std ;

int const SIZE = 5;
class Queue{
    
    private:
    int items[SIZE] ;
    int front ;
    int rear ;

    public:
    Queue(){
        front = -1;
        rear = -1 ;
    }

    bool isfull(){
        if(front == 0 && rear == SIZE - 1 ){
            return true;
        }
        if(front == rear + 1){return true;}
        else return false;
    }

    bool isEmpty(){
        if(front == -1){
            return true;
        }else
            return false;
    }
    
    void enQueue(int element){
        if(isfull()){
            cout<<"Queue is full ";
        }
        else{
            if(front == -1)
                front = 0;
                rear = (rear + 1) % SIZE ;
                items[rear] = element;
                cout<< "Inserted "<<element<<endl;
            
        }
        cout<<"\n";
    }

    int deQueue(){
        int element;

        if(isEmpty()){
            cout<<"Queue is Empty \n";
            return (-1);
        }
        else{
            element = items[front];
            if(front == rear){
                front = -1;
                rear = -1;            
            }else{
                front = (front + 1) % SIZE;
            }return element ;
        }cout<<"\n";
    }

    void display(){
        int i ;
        if(isEmpty()){
            cout<<"Queue is Empty ";
        }
        else{
            
            cout<<"Front -> "<<front<<endl;
            cout<<"Items -> ";
            for( i = front ; i != rear ; i = (i+1)%SIZE ){
                cout<<items[i]<<" ";
            }
            cout<<items[i];
            cout<<"\n rear -> "<<rear;        
        }
        cout<<"\n";
    }
    
};

int main(){
    Queue q;
    int choice;
    int element;
    
    do{
        cout<<" 1. Enqueue  \n 2. dequeue \n 3. display \n 4. exit"<<endl;
        cout<<"Enter choice : ";
        cin>>choice;

        switch(choice){
            case 1:
                    cout<<"Enter element to insert : ";
                    cin>>element;
                    q.enQueue(element);
                    break; 
            case 2:
                q.deQueue(); 
                break;
            case 3:
                cout<<"\nDisplaying elements: \n";
                q.display();
                break ;
            case 4:
                cout<<"Exiting...";
                break;   
        }
    }

    while(choice != 4);
    return 0;
}
















