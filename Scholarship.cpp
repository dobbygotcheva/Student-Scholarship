#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

#define MAXARRAY 10
void quicksort(int arr[], int low, int high);
//template for displaying an array
template<class T> void show(T*m, int n){
	for(int i=0; i<n; i++){
		cout<<m[i]<<" ";
	}
	cout<<endl;
}
//template for sorting an array
template<class X> void sort(X*m, int n){
	//local variable
	X s;
	//operators for a loop
	for(int i=1; i<=n-1;i++){
		for(int j=0;j<n-i; j++){
			if(m[j]>m[j+1]){
				//switching the values of the neighbors
				s=m[j+1];
				m[j+1]=m[j];
				m[j]=s;
			}
		}
	}
	//displaying the sorted array
	show(m,n);
}


// sorting every grade between low and high
void quicksort(int arr[], int low, int high){
	int i=low;
	int j=high;
	int y=0;
//supporting element
	int z=arr[(low+high)/2];
//dividing
	do{
		//finding the left element
		while(arr[i]<z) i++;
		//finding the right element
		while(arr[j]>z) j--;
		
		if(i<=j){
			//switching the positions of the two elements
			y=arr[i];
			arr[j]=y;
			i++;
			j--;
		}
	}while(i<=j);
	//recursion
	if(low<j)
	quicksort(arr,low, j);
	
	if(i<high)
	quicksort(arr, i, high);
}




class Students{
	public:
	char first_name[20];
	char second_name[20];
	char last_name[20];
	double sr_uspeh;
	char egn[11];
};






//three level hierarchy
class Student{
	//base class
public:
  Student() { 
     cout << "Scholarship is given to some students.\n"; }
     
    virtual void scholarship(){
    	cout<<"Students receive scholarship, safe for lazy students."<<endl;
	} 
};

class LazyStudent : public Student {
	//derived class
public:
  LazyStudent() { 
     cout << "No scholarship if you are a lazy student\n"; 
}
void scholarship(){
	cout<<"You are a lazy student, so you get no scholarship."<<endl;
}
};

class HardWorkingStudent: public LazyStudent {
	//derived class
	//it ingerits all the abovewritten messages 
public:
  HardWorkingStudent() { 
     cout << "But a big scholarship if you are hard-working student\n"; 
  }
  void scholarship(){
  	cout<<"You are a hard-working student, so you get a scholarship.";
  }
};






int main()

{
	int array[MAXARRAY]={0};
	int i=0;
	//putting numbers- the grades into the array
	for(i=0;i<MAXARRAY; i++){
	
	cout<<"Input number:"<<endl;
	cin>>array[i];
}
	quicksort(array, 0, (MAXARRAY-1));
	cout<<"After quicksort:"<<endl;
	//putting out the sorted array
	for(i=0; i<MAXARRAY;i++){
		cout<<array[i]<<" ";
	}
	cout<<endl;
	
	//putting in the grades of the student
	int D[5]={3,5,3,2,6};
	//sorting 
	sort(D,5);
	//you can also put them in GPA
	char S[5]={'D','A','B','B','F'};
	//sorting
	sort(S,5);
	
	
	
	
	Students students;
	fstream file;
	file.open("c:/students.txt", ios::in);
	int n;
	cout<<"Bring back the number of students:";
	cin>>n;
	for(i=0;i<n;i++){//introducing data about n students
		cout<<"Name:";
		cin>>students.first_name;
		cout<<"Second name:";
		cin>>students.second_name;
		cout<<"Family name:";
		cin>>students.last_name;
		cout<<"Average grade:";
		cin>>students.sr_uspeh;
		cout<<"EGN:";
		cin>>students.egn;
		
		//entering the data into the file
		
		file<<students.first_name<<" ";
		file<<students.second_name<<" ";
		file<<students.last_name<<" ";
		file<<students.sr_uspeh<<" ";
		//end of the recording
		file<<students.egn<<'\n';
		
		
	}
	
	//it places the get pointer at the beginning of the file(position 0)
	file.seekg(0);
	//taking out the data of the students from the file
	for(i=0; i<n;i++){
		file>>students.first_name;
		file>>students.second_name;
		file>>students.last_name;
		file>>students.sr_uspeh;
		file>>students.egn;
	    //outputs data about those students with average grade between 4 and 5
	    if(students.sr_uspeh>=4 && students.sr_uspeh<=5){
	    	cout<<students.first_name<<" ";
	    	cout<<students.second_name<<" ";
	    	cout<<students.last_name<<endl;
		}
	}
	file.close();

	
	
	
	//we have chosen a hard-working student who will read all the messages
	//the hard-working student will receive a message that they are hard- working and they will receive a scholarship
  HardWorkingStudent student;
  student.scholarship();
  return 0;
}
