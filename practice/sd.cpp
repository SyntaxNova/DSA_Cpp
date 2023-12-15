#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<stdlib.h>
using namespace std;

int n ;
class student{
    int rollno;
    char name1;
    float sgpa;

    public:
    void getdata();
    void showdata();
    void rolllist();
    void findsgpa();
    void findname();
    void namelist();
    void topten();

    int partition(student arr[],int lb,int ub);
    void Quicksort(student arr[] , int lb , int ub);
}s[25];

void ask(int mid){
    char ch;
    cout<<endl<<"Student Found ";
    cout<<endl<<"do you want to see data (y/n) ";
        cin>>ch;
    if(ch == 'y'){
        s[mid].showdata();    
    }
}

int main(){
    int m;
    int count = 1;
    while(1){
        cout<<endl<<" Main Menu ";
        cout<<endl<<"1. Enter Data ";
        cout<<endl<<"2. show Data ";
        cout<<endl<<"3. Search stud by sgpa ";
        cout<<endl<<"4. roll call list ";
        cout<<endl<<"5. search by name ";
        cout<<endl<<"6. name list ";
        cout<<endl<<"7. Top 10 ";
        cout<<endl<<"8. Exit ";
        cout<<endl;
            cin>>m;
        cout<<endl;
        switch(m){
            case 1 :
                cout<<endl<<" Enter no of stud ";
                    cin>>n;
                for(int i=0 ; i<=n ; i++){
                    cout<<endl<<"Enter Data for students "<<count++<<endl;
                    s[i].getdata();
                }
                break;
            case 2:
                for(int i=0 ; i<n ; i++)
                    s[i].showdata();
                break;
            case 3: 
                s[0].findsgpa();
                break;
            case 4: 
                s[0].rolllist();
                break;
            case 5:
                s[0].findname();
                break;
            case 6 :
                s[0].namelist();
                break;
            case 7  :
                s[0].topten();
                break;
            case 8 :
                exit(0);
                break;       
       }
    }
}

void student :: getdata(){
    cout<<"Enter Name of student : ";
    cin>>name1;
    cout<<"Enter roll no of student : ";
    cin>>rollno;
    cout<<"Enter sgpa of student : ";
    cin>>sgpa;
    cout<<endl;
    cout<<endl;
}

void student :: showdata(){
    cout<<endl;
    cout<<"Name : "<<name1<<"\t Roll no : "<<rollno;
    cout<<fixed<<setprecision(2)<<"\tSGPA : "<<sgpa;
}

void student :: findsgpa(){
    int count = 0;
    float fsgpa;
        count  = 0;
    cout<<"Enter sgpa : ";
    cin>>fsgpa;
    for(int i = 0 ; i < n ; i++){
        if(s[i].sgpa = fsgpa){
            ask(i);
            count++;
        }
    }
    if(count == 0 ){
       cout<<"Not found "; 
    }
}

void student :: rolllist(){
    for(int i = 0 ; i< (n-1) ; i++ ){
        for(int j = 0 ; j< (n-i-1) ; j++){
            if(s[j].rollno > s[j+1].rollno){
                swap(s[j].rollno , s[j+1].rollno);
                swap(s[j].name1 , s[j+1].name1);
                swap(s[j].sgpa , s[j+1].sgpa);
            }
        }
    }
    cout<<"\n Sorted Roll call list :\n";
    for(int i  = 0 ; i < n ; i++){
        s[i].showdata();
    }
    cout<<endl;
}

void student :: namelist(){
    for(int i = 0 ; i < (n-1) ; i++){
        for(int j = i+1 ; j>0 ; j--){
            if(s[j].name1 > s[j-1].name1){
                swap(s[j].name1 ,s[j-1].name1);
                swap(s[j].rollno ,s[j-1].rollno);
                swap(s[j].sgpa ,s[j-1].sgpa);
            }
        }
    }
    cout<<"\n Alphabetically Named list : \n";
    for(int i = 0 ; i < n ; i++){
        s[i].showdata();
    }
}

void student :: findname(){
    char studname;
    cout<<"Enter stud name : ";
        cin>>studname;
    for(int i = 0 ; i < n-1 ; i++){
        for(int j = 0 ; j < n-i-1 ; j++){
            if(s[j].name1 > s[j+1].name1){
                swap(s[j].name1 , s[j+1].name1);
                swap(s[j].rollno , s[j+1].rollno);
                swap(s[j].sgpa , s[j+1].sgpa);
            }
        }
    } 
    int f = 0 ;
    int end = n-1;
    int mid;

    while(f <= end){
        mid = (f+end)/2;

        if(s[mid].name1 == studname){
            ask(mid);
            break;
        }else if(s[mid].name1<studname)
            f=mid+1;
        else
            end = mid - 1;
    }

    if(f > n )
        cout << "\nNot Found \n";
}

int student :: partition(student arr[],int lb,int ub){
    int pivot = arr[lb].sgpa ;
    int start = lb ; 
    int end = ub ;
    while(start<end){
        while(arr[start].sgpa <= pivot)
            start++;
        while(arr[end].sgpa > pivot)    
            end--;
        if(start<end){
            swap(s[start].name1 , s[end].name1);
            swap(s[start].rollno , s[end].rollno);
            swap(s[start].sgpa , s[end].sgpa);
        }
    }
    swap(arr[lb].sgpa , arr[end].sgpa);
    return end;
}

void student :: Quicksort(student arr[] , int lb ,int ub){
    if(lb<ub){
        int pos = partition(arr,lb,pos-1);
        Quicksort(arr,lb,pos-1);
        Quicksort(arr,pos+1,lb);
    }
}

void student::topten(){
    Quicksort(s,0,(n-1));
    for(int i = n ; i > 0 ; i--){
        s[i].showdata();
    }
}















