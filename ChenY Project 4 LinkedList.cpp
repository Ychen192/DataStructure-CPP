#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class node{
	public:
	int count = 0;
	string data;
	node* next;
	
	node (string d);
};

node::node(string d){
	data = d;
	count=1;
	next = NULL;
}

void insert(string in);
void print();

node* listHead;	
int main()
{
	listHead = new node("dummy");
	
	string filename = "";
	cout << "Enter the filename. " << endl;
	cin >> filename;
	filename = filename+".txt";
	ifstream inFile(filename.c_str());
	string input = "";
	
	while(inFile>>input){
		insert(input);
	}
	inFile.close();
	print();
	
}
void print(){
	node* walker = listHead;
	while(true){
		for(int i=0; i<80; i++){
			walker = walker->next;
			if(walker->next== NULL)
				return;
		}
		cout<<walker->data<<endl;
	}
}

void insert(string input){
	node* walker;
	walker = listHead;
	
	while(walker->next!= NULL && walker->next->data <input){
		walker = walker->next;
	}

	if(walker->next!=NULL && walker->next->data == input){
		walker->next->count++;
	}		
	else{
		node* temp = new node(input);
		temp->next = walker->next;
		walker->next = temp;
	}
}




