#include<iostream>
#include<fstream>
using namespace std;

class student{
	public:
	char division[5];
	char name[30];
	char address[50];
	
	public:
	void accept();
	void display();
	void rollno(){
		return roll_no;
	}
	
};

void student :: accept(){
	cout<<"\nEnter roll num of stud : ";
	cin>>roll_no;
	
	cout<<"\nEnter name of stud : ";
	cin.ignore();
	cin.getline(name,30);
	
	cout<<"\nEnter division of stud : ";
	cin>>division;
	
	cout<<"\nEnter address of stud : ";
	cin>>address;
}

void student :: display(){
	cout<<"\t  "<<roll_no << "\t  "<<name <<"\t  "<<division "\t  "<<address<<endl;
}

void create(){
	student s; //object
	int n;
	int i;
	
	ofstream out("student.txt");
	cout<<"\n How many records to enter? : ";
	cin>>n;
	
	for (i = 0 ; i<n ; i++){
		s.accept();
		out.write((char *)&s , sizeof(s));
	}
	out.close();
}

void search(){
	int n;
	int flag = 0 ;
	
	cout<<"\n Enter rollnum to be searched : ";
	cin>>n;
	ifstream infile("student.txt");
	
	student s;
	while(infile.read((char*)&s , sizeof(s))){
		if(s.rollno()==n){
			cout<<"\n Record Found \n ";
			cout<<"\nrollno		name		division		Address";
			s.display();
			flag=1;
			break;
		}
	}
	if(flag==0){
		cout<<"\n Record not found ";
	}
	infile.close();
}

void display(){
	student s;
	ifstream infile("student.txt");
	while(infile.read((char*)& , sizeof(s))){
		s.display();
	}
	infile.close();
}

void addrecord(){
	student s;
	ofstream outfile("student.txt" , ios::app);
	s.accept();
	outfile.write((char*)&s, sizeof(s));
	outfile.close();
	cout<<"Record successfully Added ";
}

void deleterecord(){
	int n;
	int flag = 0 ;
	cout<<"\n Enter rollno whoserecord to be deleted : ";
	cin>>n;
	ifstream infile("student.txt");
	ofstream temp("temp.txt");
	
	student s;
	while(infile.read((char*)&s, sizeof(s))){
		if(s.rollno()!=n){
			temp.write((char*)&s. sizeof(s));
		}
		else{
			flag=1;
			cout<<"\n Record successfully deleted ";
		}
	}
	if(flag==0){
		cout<<"\n Record not found ";
	}
	infile.close();
	temp.close();
	remove("student.txt");
	rename("temp.txt" , "student.txt");
}

int main(){
	int choice;
	int roll_no;
	int marks;
	char name[30];
	ofstream out("student.txt");
	out.close();
	
	do{
		cout<<"\n";
		cout<<"\n menu: \n1] create Database \n 2] Display \n 3] Add record \n 4] search record \n 5] delete record 6] exit ";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"\n";
				create();
				break;
			case 2:
				cout<<"\n";
				cout<<"\nRoll num 		Name		Division		Address";
				create();
				break;
			case 3:
				cout<<"\n";
				addrecord();
				break;
			case 4:
				cout<<"\n";
				search();
				break;
			case 5:
				cout<<"\n";
				delete_record();
				break;
			case 6:
				cout<<"\n";
				cout<<"You Have Successfully Exitted...";
				break;
		
		}
	}while(choice!=5);
	return 0;
}
