#include<iostream>
#include<string>
#include<fstream>
using namespace std;

void countNumInFile(string filename, int& size);
void bubbleUp(int ary[]);
void bubbleDown(int ary[]);
void print(int ary[], int size);

int last = 0; //step 1: last <-- 0

int main(){
	int size = 0;
    int data = 0;
	
    string filename = "";
    cout<<"Enter your filename: ";
    cin>>filename;
    filename= filename+".txt";
    
    ifstream inFile (filename.c_str());
	countNumInFile(filename, size); //initialized size
	int heapAry[size];
	
	while(inFile>>data){ //step 2: data <-- get an item from tfi
        last++;			 //step 3: last++
        heapAry[last] = data; //step 4: ary[last] <-- data
		bubbleUp(heapAry); //step 5: BubbleUp(last) **I made variable last static 
	}// step 6
	
	inFile.close(); // step 7: close input file
		
	cout<<"Insert Order:"<<endl; //print insert order
	print(heapAry, size+1);
		
	cout<<"Sorted Order:"<<endl;
	while(last>0){	
		cout<<heapAry[1]<<endl; //step 8: print ary[first]
	    heapAry[1] = heapAry[last];	//step 9: ary <-- ary[last] then last --
		last --;
		bubbleDown(heapAry); //step 10: BubbleDown(first)
	}// step 11: repeat step 8 to step 10 until Queue is empty (last == 0)
	    
	system("pause");
	return 0;
}

void print(int ary[], int size){
    for(int i = 1; i < size; i++){
        cout<<ary[i]<<endl;               
    }      
    cout<<endl;
}
     
void countNumInFile(string filename, int& size){
    cout<<filename<<endl;
	ifstream inFile (filename.c_str());
	int temp;
	while(inFile>>temp){
		size++;
	}	
	cout<<"The number of integers in this file is "<<size<<".\n";
	inFile.close();
}//countNumInFile

void bubbleUp(int ary[]){
	int kidIndex = last;	//step 1: kidIndex <-- last
	int fatherIndex = kidIndex/2;	//Step 2: fatherIndex <-- kidIndex /2
	while(kidIndex!=1){		//step 3: if(ary[kidIndex] < ary[fatherIndex]) swap
		fatherIndex = kidIndex/2;	
		if(ary[kidIndex] < ary[fatherIndex]){
			int temp = ary[kidIndex];
			ary[kidIndex] = ary[fatherIndex];
			ary[fatherIndex] = temp;
			kidIndex = fatherIndex;	
		}else{
			return;	//step 4: repeat step 2 to step 3 until ary[fatherIndex]<= ary[kidIndex] or kidIndex == 1 // at the root
			}
		}
	}//end bubbleUp

void bubbleDown(int ary[]){
	int fatherIndex, leftKid, rightKid, smallKid = 0;
	fatherIndex = 1;
	while(true){
		leftKid = fatherIndex*2;
		rightKid = fatherIndex*2+1;
		if (rightKid <= last){ 					 	   //case 1; two kid
			if(ary[leftKid] <ary[rightKid]){
				smallKid = leftKid;
			}else{
				smallKid = rightKid;
			}
				
		}else if(leftKid <= last && rightKid > last){  //case 2; one left kid
				smallKid = leftKid;
				
		}else{										   //case 3; the root
			smallKid=last;
		}
		
		if(smallKid<=last && ary[smallKid] < ary[fatherIndex]){	//swap if conditions met
			int temp = ary[smallKid];
			ary[smallKid] = ary[fatherIndex];	
			ary[fatherIndex] = temp;		
		}	
		fatherIndex = smallKid;
			
		if(ary[fatherIndex]<= ary[smallKid]){ 	//repeat until these conditions are met
			if (leftKid > last && rightKid > last)
				return;
			}
		}//while
}//bubbleDown
