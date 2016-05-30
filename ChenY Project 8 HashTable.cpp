//Yan Chen
//Project 7 hashFunction
//313

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//node class
class node{
	public:
		string data;
		node* next;
		
		node();
		node (string d);
};
//node constructor
node::node(){
	data = "dummy";
	next = NULL;
}
//node constructor with parameter int
node::node(string d){
	data = d;
	next = NULL;
}

//hashTable class
class hashTable{
	public:
		node** hashT;
		int bSize;
		
		hashTable(int B);
};
//hashTable constructor: creates an pointer array of size B
hashTable::hashTable(int B){
	bSize = B;
	hashT = new node*[B];
	
	for(int i = 0; i <B; i++){
		hashT[i] = new node("dummy");
	}
}



/*findSpot function: returns a node* spot to insert or Null if already in list
note *1: I converted the strings into integer when comparing, so the integer 
would be in ascending order instead of instead of lexicographic order
*/
node* findSpot(hashTable arr, string data, int index){
	node* walker;
	walker = arr.hashT[index];
	
	//*1
	while(walker->next != NULL && stoi(walker->next->data) < stoi(data) ){
		walker = walker->next;
	}

	if(walker->next != NULL && walker->next->data == data){
		return NULL;
	}		
	else{
		return walker;
	}
}



//hashOne function: mod ( (int)data, Bsize)
int hashFunctionOne(string data, int B) {
	int index = stoi(data) % B;
	return index;
	
};
//HashOne: hashTable <- data from textfile using hashFunction1
void hashOne (ifstream& in, hashTable hash, int B){
	string data = "";
	int index = 0;
	
	while(in>>data){
		index = hashFunctionOne(data, B);
		node* spot = findSpot(hash, data, index);
		
		if(spot == NULL){
			cout<<data<<" not inserted: already in the database!! \n";
		}
		else{
			cout<<"data: "<<data<<" \t index: "<<index<<endl;
			node* temp = new node(data);
			temp->next = spot->next;
			spot->next = temp;
		}
	}
	in.close();
};



//hashTwo function: sum of all digits
int hashFunctionTwo(string data, int B) {
	int number = stoi(data);
	int sum =  0;
	int index = 0;
	
	while(number > 0) {
		sum += number % 10;
		number /= 10;
	}
	index = sum % B;
	
	return index;
};
//HashTwo: hashTable <- data from textfile using hashFunction2
void hashTwo (ifstream& in, hashTable hash, int B){
	string data = "";
	int index = 0;
	
	while(in>>data){
		index = hashFunctionTwo(data, B);
		node* spot = findSpot(hash, data, index);
		
		if(spot ==NULL){
			cout<<data<<" not inserted: already in the database!! \n";
		}
		else{
			cout<<"data: "<<data<<" \t index: "<<index<<endl;
			node* temp = new node(data);
			temp->next = spot->next;
			spot->next = temp;
		}
	}
	in.close();
};



//hashThree function: sum of (all char's ascii value * 32)
int hashFunctionThree(string data, int B) {
	int val = 0;
	int index = 0;
	
	for(int i = 0; i < data.size(); i++ ) {
		val = val*32 + (int)data[i];
	}	
	index = val % B ;
	
	return index;
};
//HashThree: hashTable <- data from textfile using hashFunction3
void hashThree (ifstream& in, hashTable hash, int B){
	string data = "";
	int index = 0;
	
	while(in>>data){
		index = hashFunctionThree(data, B);
		node* spot = findSpot(hash, data, index);
		
		if(spot ==NULL){
			cout<<data<<" IS NOT INSERTED: already in the database!! \n";
		}
		else{
			cout<<"data: "<<data<<" \t index: "<<index<<endl;
			node* temp = new node(data);
			temp->next = spot->next;
			spot->next = temp;
		}
	}
	in.close();
};



//print function: prints the entire hashTable
void print(hashTable h1, int Bsize){
	
	for(int i; i < Bsize; i++){
		if(h1.hashT[i]->next == NULL){
			cout<<"hash table "<<i<<": "<<"empty \n";
		}
		else{
			cout<<"hash table "<<i<<": ";
			while(h1.hashT[i]->next != NULL){
				cout<<h1.hashT[i]->next->data<<"--> ";
				h1.hashT[i] = h1.hashT[i]->next;
			}
			cout<<"\n";
		}
	}
}


string askfilename();
int main() {

	//step 1: Bsize <- ask for size of bucket
	int Bsize = 0;	
	cout<<"Enter the number of buckets you want for the hash table. \n";
	cin>>Bsize;
	
	//step 2: create a hash table with Bsize buckets
	hashTable hash(Bsize);

	
	//step 3: infile<- open file
	string filename = askfilename();
	ifstream inFile(filename.c_str());
	if(!inFile.is_open()){
		cout<<"Error: Could not open "<<filename<<"!!!"<<endl;
		return 1;	
	}
	
	
	//step 4 & 5: whichHash <- ask for which hash function
	int whichHash;
	bool repeatIfTrue = true;

	while ( repeatIfTrue == true) {
		
		cout<<"which function do you want to use:  ";
		cin>>whichHash;
		
		if      (whichHash == 1){
			hashOne(inFile, hash, Bsize);
			repeatIfTrue = false;
		}
		
		else if (whichHash == 2){
			hashTwo(inFile, hash, Bsize);
			repeatIfTrue = false;
		}
		
		else if (whichHash == 3){
			hashThree(inFile, hash, Bsize);
			repeatIfTrue = false;
		}
		
		else{
			cout<<"Error: Please enter a choice of 1, 2, or 3!! \n";
			repeatIfTrue = true;
		}
	}
	
	
	//step 6: print entire hashTable
	print(hash, hash.bSize);
		
}

//ask user for textFile name
string askfilename(){	
	string filename = "";
	
	cout<<"Enter the name of text file. \n";
	cin>>filename;
	
	return filename + ".txt";
}
