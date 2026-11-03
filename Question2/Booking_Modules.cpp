#include <iostream>
#include <string>
#include <cctype>

using namespace std;

//Display Session
void displaySessionMenu(){

    cout << "1. Yoga Fundamentals - R75" << endl;
    cout << "2. Strength Circuit - R110" << endl;
    cout << "3. Stress Management - R90" << endl;


}

//getting the user's preferred session code
double getSessionRate(int sessionCode){
    
    double sessionRate = 0.0;
    

    switch (sessionCode)
    {
    case 1:
        
        sessionRate = 75;
        break;
    
    case 2:
        
        sessionRate = 110;
        break;
    
    case 3:
        
        sessionRate = 90;
        break;
    
    default:
       cout << "Error: Invalid code! Please select a code between 1 and 3";
        break;
    }
    return sessionRate;

}

bool validParticipants(int participants){
   if (participants >=1 && participants <= 12) {
    return true;
   }
   else{
    cout << "You can only have between 1 and 12 participants";
    return false;
   }
    
}

double calculateSubtotal(double rate, int participants){
    
    double subtotal = rate * participants;
    return subtotal;
}

double calculateDiscount(double subtotal, int participants){
    double discount;
    if (participants >= 8){

        discount = subtotal * 0.10;
    }

    else {

        discount = 0.0;
    }
    return discount;
}

double calculateWeekendSurcharge(double amountAfterDiscount, char saturday){
    double surcharge = 0.0;

    if (tolower(saturday) == 'y'){
        surcharge = amountAfterDiscount * 0.15;
    }
    else if (tolower(saturday) == 'n'){
        surcharge = 0.0;
    }
    else{
        cout << "Error! Invalid input. Please input either Y or N" << endl;
    }

    return surcharge;
}

void displayBookingSummary(string bookingRef, string sessionName,
    int participants, double subtotal,
    double discount, double surcharge,
    double finalTotal, double sessionRate){
        // The invoice display
        cout << "========== VUKAFIT BOOKING SUMMARY ==========" << endl;
        cout << "Booking Ref\t\t: " << bookingRef << endl;
        cout << "Session\t\t\t: " << sessionName << endl;
        cout << "Participants\t\t: " << participants << endl;
        cout << "Subtotal\t\t: R" << subtotal << endl;
        cout << "Group Discount\t\t: R" << discount << endl;
        cout << "Weekend Surcharge\t: R" << surcharge << endl;
        cout << "Final Total\t\t: R" << finalTotal << endl;
        cout << "Cost per participant\t: R" << (finalTotal / participants) << endl;
    }

int main(){

    int sessionCode;
    string sessionName;
    double rate;
    string bookingRef;
    int participants;
    char saturday = 'N';

    cout << "Welcome to the VukaFit Session Booking page!"<<endl;

    //Get booking reference
    cout << "What is your booking Reference?: ";
    cin >> bookingRef;

    cout << "Please take a look at the menu below and select the session you'd like to book\n";

    //Display the available sessions
    displaySessionMenu();

    //Ask user for the session they want to join 
    cout<< "Enter code (1-3)\n";
    cin >> sessionCode;

    //Validate the session selected by the user
    while (sessionCode < 1 || sessionCode > 3){

        cout << "Please enter a code between 1 and 3";
        cin >> sessionCode;
    }

    //get the price of the selected session
    rate = getSessionRate(sessionCode);

   // assign session code to a session name 
    switch (sessionCode)
    {
    case 1:
        
        sessionName = "Yoga Fundamentals";
        break;
    
    case 2:
        
        sessionName = "Strength Circuit";
        break;
    
    case 3:
        
        sessionName = "Stress Management";
        break;

    }

    //Get the number of participants joining the session
    cout << "How many participants will be joining(1-12)?: ";
    cin >> participants;

    cout << "Saturday Booking(Y/N)??: ";
    cin >> saturday;

    //Make sure there is between 1 and 12 participants in a group
    while (!validParticipants(participants)){

        cout << "\nEnter valid number of participants: ";
        cin >> participants;
    }
    //Subtootal calculation
    double subtotal = calculateSubtotal(rate, participants);

    //Group Discount calculation
    double discount = calculateDiscount(subtotal, participants);

    //The amount after the discount is applied
    double amountAfterDiscount = subtotal - discount;

    //Apply surcharge if it is a Saturday
    double surcharge = calculateWeekendSurcharge(amountAfterDiscount, saturday);

    //Final amount after the surcharge is applied
    double finalTotal = amountAfterDiscount + surcharge;
    
    displayBookingSummary(bookingRef, sessionName, participants, subtotal, discount, surcharge, finalTotal, rate);
    
    
}