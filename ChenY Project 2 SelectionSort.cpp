#include<iostream>
#include<fstream>
using namespace std;

void printArray(int* ary, int size);
string askTF();
int countFileSize(string filename);

int main(){	
	
	string filename = "";
	filename = askTF();	//filename <-ask user for textFile name
	
	int size = 0;
	size = countFileSize(filename); //size <- count the number of integers in file
	
	int *ary = new int[size]; 
	
	ifstream inFile(filename.c_str());	
	for(int i = 0; i<size; i++){ //transfer the integers from the file into array ary
		inFile>>ary[i];
	}
	inFile.close();
	
	int position = 0; 
	int walker = 0;	
	int min = 0;
	
	while(position < size){
		
		//iterating the array list to find min
		while(walker < size){
			if(ary[walker] < ary[min]){
				min = walker;	//index of min = index of walker
			}
			walker++;
		}
		
		cout<<"iteration = " << position <<"  position = " << position <<"  min = "<< min<<endl;
		printArray(ary, size);
		
		//swap
		int temp = ary[position];
		ary[position] = ary[min];
		ary[min] = temp;
		
		//setting indexs for next iteration
		position++;
		walker = position;
		min = walker;
	}	
}

//print array in index order
void printArray(int* ary, int size){ //print array in index order
	for(int i = 0; i<size; i++){
		cout<<ary[i]<<"  ";
	}
	cout<<"\n";
}

//ask user for textFile name
string askTF(){	
	string filename = "";
	cout<<"name of file?\n";
	cin>>filename;
	return filename + ".txt";
}

//count the number of integers in file
int countFileSize(string filename){
	int size = 0;
	
	ifstream inFile(filename.c_str());
	int input = 0;
	
	while(inFile>>input){
		size++;
	}
	
	inFile.close();
	
	return size;
}



