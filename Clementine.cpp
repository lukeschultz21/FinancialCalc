// Luke Schultz
// CPSC 1071: 001
// Cyberbooleans

#include <iostream>
#include <cmath>
#include <iomanip>
#include "Loan.h"
#include "Retirement.h"
#include "Register.h"

using namespace std;


//controls the menu of the program
void runMenuSystem(){
  string option;
  bool loop=true;
  cout<<"Starting Clementine Financial Bank" << endl;
  while (loop==true){
  cout<< "******* Welcome to Clementine Financial *********"<<endl;
    cout<<endl;
    cout<<"Menu:"<<endl;
    cout<<"\t[E] Estimate how much money at retirement"<<endl;
    cout<<"\t[L] Loan payoff calculator"<<endl;
    cout<<"\t[R] Run transaction classifier"<<endl;
    cout<<"\t[Q] Quit program"<<endl;
    cout<<endl<<" Enter your choice and press enter: ";
    cin>>option;
    if (option=="e"||option=="E"){
      Retirement r;
      r.estimateDriver();
    }
    else if (option=="l"||option=="L"){
      Loan l;
      l.paymentDriver();
    }
    else if(option=="r"||option=="R"){
      Register reg;
      reg.processTransaction();
    }
    else if (option=="q"||option=="Q"){
      exit(0);
    }
    else{
      cout<< endl << "The provided choice was invalid! Please select again." << endl << endl;
    }
  }
}



//main
int main(){
  runMenuSystem();
  return 0;
}