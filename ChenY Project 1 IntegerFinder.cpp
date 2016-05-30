//Yan Chen 
//We have a given data file (data.txt) which contains integers.
//We are interested in finding 1: Largest 2: Smallest 3: Total integers 4: Average of all the integers

#include <iostream>   //0) prepare everything that needed for program
#include<fstream>
using namespace std;

int main(){
    //1)initialize all variables
    int largest = -9999;
    int smallest = 9999;
    int sum = 0;
    int counter = 0;
    double avg = 0;
    int input = 0;
    
    ifstream inFile;
    inFile.open("data.txt"); //2) open input text file then....
    
    while(inFile){  
      //2)read data file one integer in each read                       
      inFile>>input;  
      
      //3) Assume data input is integer
      counter++;
      sum+=input;
      if(input>largest)
        largest = input;
      if(input<smallest)
        smallest = input;
        
      if( inFile.eof() ) 
          break;  
    }//4) repeat until no mroe data in text file
    
    //5)calculate average
    avg =(double)sum/counter; 
    
    //6)close file and print result
    cout<<"Smallest is "<<smallest<<endl;
    cout<<"largest is "<<largest<<endl;
    cout<<"Average is "<<avg<<endl;
    inFile.close();
    
    system("PAUSE");
}
