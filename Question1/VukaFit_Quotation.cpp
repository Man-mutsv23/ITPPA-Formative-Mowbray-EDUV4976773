// ITPPA-Formative-Mowbray-EDUV4976773.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std; 

int main()
{
	//student variables
	string studentNumber;
	string studentName; 

	//Constant Membership variables
	const double BASIC_ACCESS = 220.00;
	const double ACTIVE_PLUS = 350.00;
	const double COMPLETE_WELLNESS_RATE = 480.00;

	//Discount Rates
	const double DISCOUNT_3_TO_5_MONTHS = 0.07;
	const double DISCOUNT_6_MONTHS = 0.12;
	const double DISCOUNT_1_TO_2_MONTHS = 0.00;

	//Fitness Assessment fee (optional)
	const double ASSESSMENT_FEE = 180.00;
	

	//Membership selection and duration tracking
	int membershipChoice;
	int membershipDuration;
	string selectedMembershipPlanName;

	//Calculations
	double initialMonthlyRate = 0.0;
	double membershipSubtotal = 0.0;
	double discountRate = 0.0;
	double discountAmount = 0.0;
	double assessmentCharge = 0.0;
	double fullAmountDue = 0.0;

	// Optional add-on choice
	char include_assessment;
	
	//Capture Student Details
	cout << "Please enter your Student Number: ";
	getline(cin, studentNumber);
	cout << "Please enter your full name: ";
	getline(cin, studentName);

	cout << "Hello, " << studentName << " and welcome to VukaFit.\nWe have 3 Packages available for you to choose from: " << endl;

	//Display and accept a membership selection
	cout << "\nPlease select a Plan\n1: Basic Access:\tR220\n2: Active Plus:\t\tR350\n3: Complete Wellness:\tR480 " << endl;
	cin >> membershipChoice;

	switch (membershipChoice) {
	case 1: 
		selectedMembershipPlanName = "Basic Access";
		initialMonthlyRate = BASIC_ACCESS;
		break;
	case 2: 
		selectedMembershipPlanName = "Active Plus";
		initialMonthlyRate = ACTIVE_PLUS;
		break;
	case 3:
		selectedMembershipPlanName = "Complete Wellness";
		initialMonthlyRate = COMPLETE_WELLNESS_RATE;
		break;
	default:
		cout << "\nError: You have entered an invalid membership code ";
		
		return 0; 
		

	}

	//Discount calculation and number of months selection

	cout << "May you select the duration you'd like to sign up for(1-6): "<< endl;
	cin >> membershipDuration;

	//If the user selects a duration outside the range then execute this if statement
	if (membershipDuration < 1 || membershipDuration > 6) {

		cout << "\n Error: Duration must be between 1 and 6 months"<< endl;
		return 0;
	}
	else
	{
		membershipSubtotal = initialMonthlyRate * membershipDuration;
	}

	//Calculating the discount depending on the duration picked
	if (membershipDuration == 6) {

		discountRate = DISCOUNT_6_MONTHS;
	}
	else if (membershipDuration >= 3) {

		discountRate = DISCOUNT_3_TO_5_MONTHS;

	}
	else {

		discountRate = DISCOUNT_1_TO_2_MONTHS; 
	}

	discountAmount = membershipSubtotal * discountRate;

	//Checking if user needs an assessment 
	cout << "Would you require a fitness assessment as well? It would require an additional R180. (Enter Y/N): ";
	cin >> include_assessment;
	
	if (tolower(include_assessment) == 'y') {

		assessmentCharge = ASSESSMENT_FEE;
	}
	else if (tolower(include_assessment) == 'n') {
		
		assessmentCharge = 0.00;
	}

	//Final amount 
	fullAmountDue = membershipSubtotal - discountAmount + assessmentCharge;

	cout << fixed << setprecision(2);
	//The invoice display
	cout << "=======================VUKAFIT MEMBERSHIP QUOTATION=========================="<<endl;
	cout << "Student\t\t\t:" << studentName << " -" << studentNumber << endl;
	cout << "Membership\t\t:" << selectedMembershipPlanName<<endl;
	cout << "Months\t\t\t:" << membershipDuration << endl;
	cout << "Monthly Fee\t\t:R" << initialMonthlyRate << endl;
	cout << "Subtotal\t\t:R" << membershipSubtotal << endl;
	cout << "Discount\t\t:R" << discountAmount << endl;
	cout << "Assessment\t\t:R" << assessmentCharge << endl;
	cout << "FINAL AMOUNT\t\t:R" << fullAmountDue;

	


	
}


