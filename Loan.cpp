#include <cmath>
#include <iomanip>
#include "Loan.h"
#include <iostream>

using namespace std;


//calculates the months and years required to pay off a loan
//returns months needed to pay off the loan
int Loan::paymentMonths(double principalAmount, double annualInterestRate, double monthlyPayment) {
    double monthlyInterestRate = (annualInterestRate / 100.0) / 12.0;
    double monthsToPayOff = (log(monthlyPayment) - log(monthlyPayment - monthlyInterestRate * principalAmount)) / log(1 + monthlyInterestRate);
    return static_cast<int>(round(monthsToPayOff));
}


void Loan::paymentDriver() {
    double principalAmount, annualInterestRate, monthlyPayment;
    string option;
    cout << "Loan Payment Calculator" << endl;
    cout << endl << "Enter the principal amount: $";
    cin >> principalAmount;
    cout << "Enter the annual interest rate (in percent): ";
    cin >> annualInterestRate;
    cout << "Enter the monthly payment: $";
    cin >> monthlyPayment;

    // Calculate the monthly interest rate
    double monthlyInterestRate = (annualInterestRate / 100.0) / 12.0;

    int monthsToPayOff = paymentMonths(principalAmount, annualInterestRate, monthlyPayment);
    double yearsToPayOff = static_cast<double>(monthsToPayOff) / 12.0;
    yearsToPayOff = round(yearsToPayOff * 10) / 10.0;

    // Calculate the additional rate
    monthlyPayment = monthlyPayment + 15;
    double additionalRate = (log(monthlyPayment)-log(monthlyPayment-monthlyInterestRate*principalAmount))/log(1+monthlyInterestRate);
    int additionalRateMonthsToPayOff = static_cast<int>(round(additionalRate));
    int monthsEarlier = monthsToPayOff - additionalRateMonthsToPayOff;

    cout << endl << "Calculating..." << endl;
    cout << endl << monthsToPayOff << " months (" << yearsToPayOff << " years) are needed to pay your loan off." << endl;
    cout << endl <<"Did you know if you paid an additional $15 per month, you would pay off your loan " << monthsEarlier << " months earlier?" << endl;
    
    bool loop= true;
        while(loop==true){
            cout << endl <<"Calculate another loan payoff? (y/n):";
            cin>>option;
            if(option=="y"){
            loop=false;
            paymentDriver();
            }
            else if(option=="n"){
            cout << endl;
            loop=false;
            }
            else{
            cout<< "Invalid Input! Please choose again.";
            }
        }
}