#include "Register.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

enum Transactions{RESTAURANT, MERCHANDISE, UTLITY, COFFEESHOP, AUTOMOTIVE, DEPOSIT, OTHER};
vector<string> transData;

Register::Register(){}

string Register::getFileName(){
  string name;

  while(true){
    cout<<"\tPlease enter the filename: ";
    cin>>name;
    cout<<"\tOpening the file <"<<name<<">"<<endl;

    ifstream regFile;
    regFile.open(name);
    if(regFile){
      return name;
    } else {
      cout<<"Error opening file. Please retry."<<endl;
    }
  }
}

void Register::setFileName(string name_){
  name = name_;
}

bool Register::processTransaction(){
  bool success;
  string runAgain;

  setFileName(getFileName());

  if(readFromFile()){
    success = true;
  } else {
    success = false;
  }

  printFile();
    
   
bool loop= true;
  while(loop==true){
    cout<<"Would you like to process another transaction register? (y/n): ";
    cin>>runAgain;
    if(runAgain=="y" ||runAgain=="Y"){
      loop=false;
      processTransaction();
    }
    else if(runAgain=="n" || runAgain=="N"){
      cout << endl;
      loop=false;
    }
    else{
      cout<< "Invalid Input! Please choose again." << endl;
    }
  }

  return success;
}

bool Register::readFromFile(){
  bool success = true;
  string line;
  fstream regFile;

  transData.clear();
  regFile.open(name);

  while(getline(regFile, line)){
    transData.push_back(line);
  }

  return success;
}


void Register::printFile(){
  cout << "Printing Transaction Ledger" << endl;

  for(const string &line : transData){
    vector<string> tokens;
    size_t pos = 0, found;
    while((found = line.find_first_of(' ', pos)) != std::string::npos) {
      tokens.push_back(line.substr(pos, found - pos));
      pos = found+1;
    }
    tokens.push_back(line.substr(pos));

    // Properly capitalize the transaction type
    string transactionType = tokens[1];
    for(char &c : transactionType){
      c = tolower(c);
    }
    transactionType[0] = toupper(transactionType[0]);
    double moneyValue = stod(tokens[3]);

    cout << right << setw(10) << tokens[0] << " |";
    cout << right << setw(15) << tokens[2] << " |";
    cout << fixed << setprecision(2) << right << setw(10) << moneyValue << " |";
    cout << right << setw(20) << transactionType << endl << endl;
  }
  cout << endl;
}