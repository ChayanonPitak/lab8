#include<iostream>
#include<iomanip> //For using setw(), setprecision(), ...
using namespace std;

int main(){	
	double CurrentLoan, InterestRate, AnnualPayAmount;
	cout << "Enter initial loan: ";
	cin >> CurrentLoan;
	cout << "Enter interest rate per year (%): ";
	cin >> InterestRate;
	cout << "Enter amount you can pay per year: ";
	cin >> AnnualPayAmount;

	//use 'setw' to set width of table and 'left' to set left-alignment
	//you can change input argument of 'setw()' to see the effect
	//Try to change from 'left' to 'right' and see the effect
	cout << setw(13) << left << "EndOfYear#"; 
	cout << setw(13) << left << "PrevBalance"; 
	cout << setw(13) << left << "Interest"; 
	cout << setw(13) << left << "Total";
	cout << setw(13) << left << "Payment";
	cout << setw(13) << left << "NewBalance";
	cout << "\n";

	int YearCount = 1;
	
	while(true)
	{
		//use 'fixed' and 'setprecision' to fix the number of decimal digits for displaying
		//you can change input argument of 'setprecision()' to see the effect
		cout << fixed << setprecision(2); 
		cout << setw(13) << left << YearCount; 
		cout << setw(13) << left << CurrentLoan;
		cout << setw(13) << left << CurrentLoan * InterestRate / 100;
		CurrentLoan += CurrentLoan * InterestRate / 100;
		cout << setw(13) << left << CurrentLoan;
		cout << setw(13) << left << (CurrentLoan >= AnnualPayAmount ? AnnualPayAmount : CurrentLoan);
		CurrentLoan -= (CurrentLoan >= AnnualPayAmount ? AnnualPayAmount : CurrentLoan);
		cout << setw(13) << left << CurrentLoan;
		if (CurrentLoan == 0) break;
		YearCount++;
		cout << "\n";
	}
	return 0;
}
