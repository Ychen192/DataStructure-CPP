#include<iostream>
#include<fstream>
#include<string>
using namespace std;

string askTF(int fileNum);
bool fileInOrder (string filename);
void fileMerge(string inFile1, string inFile2, string outFile);

int main() {
	
	//Asking user for filename for file (parameter are used to mark the filename)
	string file1 = askTF(1);
	string file2 = askTF(2);	
	string file3 = "output.txt";
	
	//string file1 = "ExternalSortDataA.txt";
	//string file2 = "ExternalSortDataB.txt";
	cout<<"Your result will be in (output.txt). \n";
	
	
    //if the two files are the same, exit
	if( file1 == file2) {
		cout<<"The two files you entered are the same!!!"<<endl;
		exit(1);
	}
	//else check if the files are in ascending order
	else { 
		//if the two files are in order merge the files
		if( fileInOrder(file1) && fileInOrder(file2) ){
			fileMerge(file1, file2, file3);
			cout<<"File merge success!! ";
		}
		//else let user know that one or both file are not in ascending order
		else{
			cout<<"One or both of the input file are not in ascending order!!"<<endl;
		}
	}
}

void fileMerge(string file1, string file2, string file3){
	
	int data1 = 0;
	int data2 = 0;
	
	ifstream inFile1(file1);
	ifstream inFile2(file2);
	ofstream outFile(file3);
	
	//step 1: get data from text files
	inFile1>>data1;
	inFile2>>data2;
	
	//step 2: compare data1 and data2 and output the lower integer
	while( !inFile1.eof() && !inFile2.eof() ){	

		if(data1 < data2){
          	outFile<<data1<<" ";
          	inFile1>>data1;
    	}	
    	else if(data1 > data2){
    		outFile<<data2<<" ";
        	inFile2>>data2;
    	}	
    	else {
    		outFile<<data1<<" ";
        	inFile1>>data1;
        	inFile2>>data2;	
		}	
	}//step3: repeat till either file1 or file2 is empty
	
	//when one of the file is empty check the other file and output the rest if tehre is any
	if ( inFile1.eof() ){
		outFile<<data2<<" ";
		while( inFile2>>data2 ){
			outFile<<data2<<" ";
		}
	}
	else if ( inFile2.eof() ){
		outFile<<data1<<" ";
		while( inFile1>>data1){
			outFile<<data1<<" ";
		}
	}
	
	inFile1.close();
	inFile2.close();
	outFile.close();	
}

//ask user for textFile name
string askTF(int fileNum){	
	string filename = "";
	cout<<"Enter the name of text file #"<<fileNum<<". \n";
	cin>>filename;
	return filename + ".txt";
}

//check if the integers in file is in ascending order
bool fileInOrder (string filename){

	ifstream inFile(filename.c_str());

	int input1 = -99999;
	int input2 = 0;
	
	while(inFile>>input2){
		if(input1 <= input2){
			input1 = input2;		
		}
		else{
			return false;
		}
	}
	inFile.close();		
	return true;
}




