//main.cpp
/*
 break down so far
 operation
 key
 input file
 auto generate key,IV,if not fiven
 try catch errors
 Create Class object
 class object functions public:
 modifyIV(string), modifyKey(string), c(int,string);
 */

// Libraries
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <bitset>

using namespace std;

int main(int argc, char* argv[]){
    
/******** Store variables given from terminal ********************/
    ifstream ifile;
    ofstream ofile;
    string x;
    stringstream a;
    string eOrC = "";// this is what the input file goes to string it is passed to DES
    string command = "";// for output of openssl
    string t = "NO"; // this is for resulting text of DES will go into output file
    string eORd = argv[1]; //encryption or decryption
    string IV = argv [3];
    string key = argv [5];
    string text = argv[7];//input file name
    //string cORp = argv [6];//cipher or plain text
    string fOut = argv [9];//output file name
    
    
    if(IV.size() != 16 && IV != "R"){
        
        cerr << "Error: Invalid IV check size or characters."<<endl;
        exit(1);
    }
    if(key.size() != 16 && key != "R"){
        
        cerr << "Error: Invalid key check size or characters."<<endl;
        exit(1);
    }
    if((text.substr(text.length()-4, text.length()) != ".txt")){
        
        cerr << "Error: input File name must have Extension '.txt'."<<endl;
        exit(1);
    }
    if((fOut.substr(fOut.length()-4, fOut.length()) != ".txt")){
        
        cerr << "Error: output File name must have Extension '.txt'."<<endl;
        exit(1);
    }
    if(eORd != "-e" && eORd !="-d"){
        
        cerr << "Error: Invalid command request must be encrypt(-e), decrypt(-d)" << endl;
        exit(1);
        
    }
        
   /* cout << "You want to: "<< eORd << "  (encrypt(-e), decrypt(-d))" << endl;
    cout << "IV is: "<< IV << endl;
    cout << "Key is: "<< key << endl;
    cout << "You have entered: "<< cORp << "  (cipher Text(-c), plain text(-p))" << endl;
    */
    
    
    //Determine if it's cipher text or plain text
  /*  if ( cORp == "-c"){
        cipher = argv [7];
        cout << "cipher: "<< cipher <<endl;
    }
    else if (cORp == "-p"){
        pText =argv [7];
        cout << "Plain Text: "<< pText <<endl;
    }
    else
        cout << "Invalid input"<<endl;
   
    cout << "Output will be saved in: "<< fOut << endl;
    */
    
    if( eORd == "e") command =" -des-cbc -nosalt -K ";
    else command = " -des-cbc -nopad -nosalt -K ";
    cout << "*openssl enc -" <<eORd << command << key <<" -iv "<< IV <<"*"<< endl;

    
    
/******** Divide plain text/cipher into 64 bit blocks ********************/
    
    //If we're reading from file
    //(pText.substr(pText.length()-3, pText.length()) == "txt" || pText.substr(cipher.length()-3, cipher.length()) == "txt" )
    try {
        ifile.open(text);
        while(ifile >> x){
            a << x <<" ";
        }
        eOrC = a.str();
        ifile.close();
    }
    //If text was given
    catch (exception e){
        cerr<<"Error:  File not found"<<endl;
        exit(1);
    }
    
    ofile.open(fOut);
    ofile << t;
    ofile.close();
    
    return 0;
}//end of main
