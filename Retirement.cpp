#include <cmath>
#include <iomanip>
#include "Retirement.h"
#include <iostream>
#include <limits>

using namespace std;

//calculates the amount in a retirement fun
//returns the amount at retirement
double Retirement::estimateEarnings(int a, int r, double c, double m, double p){
    int totalYears, months;
    double totalAmount, returnAmount, monthlyGain, totalGain, monthlyReturn;

    totalYears= r - a;
    totalAmount = c;
    months = totalYears * 12.00;
    returnAmount = p / 100.00;
    monthlyReturn = returnAmount / 12.00;
    monthlyGain = m;
    totalGain = 0.00;

    while(months > 0){
        totalGain += (totalAmount) * monthlyReturn;
        totalAmount += (totalAmount) * monthlyReturn;
        totalAmount += monthlyGain;
        months = months - 1;
    }

    cout << fixed << setprecision(2);
    cout << endl <<"Estimated Retirement Savings: $" << totalAmount << endl;
    cout << "Estimated Retirement Growth: $" << totalGain << endl << endl;
    return totalAmount;
}



//begins the calculation function for retirements by prompting user for input on info
void Retirement::estimateDriver(){
  int age, retireAge;
  double current, monthly,returnP;
  string option;

  cout<<"Estimate Savings at Retirement"<<endl<<"Disclaimer: This is only a rough estimate!"<<endl;
  cout << endl << "\tEnter your current age in years: ";
    while (!(cin >> age) || age <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\tAge cannot be 0 or less." << endl;
        cout << "\tRe-enter your age in years: ";
    }

  cout << "\tEnter your target retirement age: ";
    while (!(cin >> retireAge) || retireAge <= age) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\tYour target age cannot be less than or equal your current age." << endl;
        cout << "\tRe-enter your target age in years: ";
    }

  cout << "\tHow much have you saved towards retirement?: $";
    while (!(cin >> current) || current < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\tYour savings cannot be negative." << endl;
        cout << "\tRe-enter your savings: $";
    }

  cout << "\tEnter your monthly contribution to retirement: $";
    while (!(cin >> monthly) || monthly <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\tYour monthly contribution cannot be less than or equal to zero." << endl;
        cout << "\tRe-enter your monthly contribution: $";
    }

  cout << "\tEnter the estimated annual return on investment (in percent): ";
    while (!(cin >> returnP) || returnP < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\tYour rate cannot be less than zero." << endl;
        cout << "\tRe-enter your rate (in percent): ";
    }
  cout<<"." << endl<< "."<< endl <<"...calculating"<<endl;
  estimateEarnings(age,retireAge,current,monthly,returnP);

  bool loop= true;
  while(loop==true){
    cout<<"Calculate another estimate? (y/n): ";
    cin>>option;
    if(option=="y" ||option=="Y"){
      loop=false;
      estimateDriver();
    }
    else if(option=="n" || option=="N"){
      cout << endl;
      loop=false;
    }
    else{
      cout<< "Invalid Input! Please choose again." << endl;
    }
  }
}
