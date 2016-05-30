#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class BstNode{	//node class
	public:
		int data;
		BstNode* left;
		BstNode* right;
		
		BstNode(int d, BstNode* l, BstNode* r);
};

BstNode::BstNode(int d, BstNode* l, BstNode* r){	//node constructor which initialize node 
	data= d;
	left = l;
	right = r;
}

//functions
BstNode* findSpot(BstNode* spot, int data);		//find the position to insert node
void leaftInsert(BstNode* spot, BstNode* newLeafNode); //when position is found insert the newly create node into positon
void printInOrder(BstNode* ptr);	//print all the data on the binary search tree in order fashion (sorted)
bool Search(BstNode* root, int data);	//search the tree for data


int main(){
	BstNode* root = new BstNode(9999, NULL, NULL); //step 1: root <- make new BstNode
	BstNode* spot = NULL;
	BstNode* newLeafNode = NULL;
	int data= 0;
	char input;
	
	string filename = "";
    cout<<"Enter your filename: ";
    cin>>filename;
    filename= "BinarySearchTree_Data.txt"; 	
    
    ifstream inFile (filename.c_str());
	while(inFile>>input){	//step 2: get data from file
		if(input == '+'){
			inFile>>data;
			spot = findSpot(root, data);	//step 3: spot<- findSpot (root, data)
			if(spot == NULL){	//Step 4: if Spot is NULL error message
				cout<<"cannot insert, "<<data<<" is already in file. \n";
			}
			else {
				newLeafNode= new BstNode(data, NULL, NULL); //Step 5a: newLeafNode<- new BSTNode(data, null, null)
				leaftInsert(spot, newLeafNode);	//step 5b: Call leafInsert (SPOT, newLeafNode)
			}	
		}
		
		else if(input == '*'){
			inFile>>data;
			if(Search(root->left, data))	//*root is dummy
				cout<<"  "<<data<<" is in tree. \n";
			else
				cout<<"  "<<data<<" is not in tree. \n";
		}
		
		else if(input == 'p'){
			printInOrder(root->left);	//*root is dummy
			cout<<endl;
		}
		else
			cout<<"invalid input";
	}//while(inFile>>input) step 6: repeat step 2 to step 5 until the file is empty
}

//search for input data in the tree
bool Search(BstNode* root, int data){	
	if(root == NULL);	//return false if root is null

	else if(root->data == data){	//if found print and return
		cout<<root->data<<"...";
		return true;
	}
	else if(data <= root->data){	//if data is less than current shfit left
		cout<<root->data<<"...";
		return Search(root->left, data);
	}
	else{	//if data is greater than current shift right
		cout<<root->data<<"...";
	 	return Search(root->right, data);
	}
}

//print the tree in inOrder fashion (sorted)
void printInOrder(BstNode* ptr){
	if(ptr != NULL){
		if(ptr->left != NULL){	//left
			printInOrder(ptr->left);
		}
		cout<<ptr->data<<"  ";	//print
		if(ptr->right != NULL){	//right
			printInOrder(ptr->right);
		}	
	}
	else{
		cout<< "The tree is empty\n";
	}
}

//place new node with input data into "spot"
void leaftInsert(BstNode* spot, BstNode* leafNode){
	if(spot->right == NULL && spot->left == NULL){	//when spot is leaf
		if(spot->data > leafNode->data)
			spot->left = leafNode;
		else
			spot->right = leafNode;
	}
	else if(spot->left == NULL){	//when spot has no left child
		spot->left = leafNode;
	}
	else{
		spot->right = leafNode;
	}
}
	
//find correct "spot" (under BST rule) to insert new data node
BstNode* findSpot(BstNode* spot, int data){ //find spot to insert the new data node
	if(spot->data == data)	//step 1: data exist already
		return NULL;
		
	if(spot->right == NULL && spot->left == NULL)	//step 2: when spot is leaf
		return spot;
		
	if(spot->right != NULL && spot->left != NULL){	 //step 3:  when spot has 2 children
		if(spot->data > data)
			findSpot(spot->left, data);
		else
			findSpot(spot->right, data);
	}
	else if(spot->right == NULL){	//when spot's right is null
		if (spot->data < data)
        	return spot;   
        else
			findSpot(spot->left, data); 
	}
	else if(spot->left == NULL){	//when spot's left is null
		if (spot->data > data)
        	return spot;   
        else
			findSpot(spot->right, data); 
	}
}




