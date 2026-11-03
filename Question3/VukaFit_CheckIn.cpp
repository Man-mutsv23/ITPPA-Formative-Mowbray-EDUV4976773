#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;

int main(){
    const int MAX_ATTEMPTS = 10;

    
    
    //Attempt counters
    int attempts = 0;
    int validCheckIns = 0;
    int invalidAttempts = 0;

    //Visit category counters
    int shortVisits = 0;
    int longVisits = 0;
    int standardVisits = 0;
    int extendedVisits = 0;

    //Activity counters
    int gymFloorVisits = 0;
    int groupClassVisits = 0; 
    int consultations = 0;

    //total
    int totalValidMinutes = 0;
    double averageDuration = 0.0;

    //Control Flag for our loop
    char continueChoice = 'Y';

    while (attempts < MAX_ATTEMPTS && tolower(continueChoice) == 'y'){

        string studentNumber;
        int activityCode;
        int duration = 0;

        attempts++;

        cout << "\nPlease enter your student number: ";
        cin >> studentNumber;

        cout << "Please enter your desired activity code(1=Gym, 2=Group Class, 3=Consultation): " << endl;
        cin >> activityCode;

        cout << "Please enter the duration (15 -180): " << endl;
        cin >>  duration;

        bool validActivity = (activityCode>=1 && activityCode <=3);
        bool validDuration = (duration >= 15 && duration <= 180);

        if (!validActivity || !validDuration) {

            invalidAttempts++;
            cout << "INVALID CHECK IN";
            if (!validActivity){cout << " - invalid activity" << endl;}
            if (!validDuration){cout << " - invalid duration";}
            cout << endl;
        }
        else{

            validCheckIns++;
            totalValidMinutes += duration;
            
            //Activity Classification
            switch(activityCode)
            {
            case 1:
                gymFloorVisits++;
                break;
            case 2:
                groupClassVisits++;
                break;
            case 3:
                consultations++;
                break;
            }

            //Visit Duration Category
            if (duration >= 15 && duration <= 44)
            {
                shortVisits++;
                cout << "SHORT VISIT"<< endl;
            }
            else if (duration >= 45 && duration <= 89)
            {
                standardVisits++;
                cout << "STANDARD VISIT"<< endl;
            }
            else if (duration >= 90 && duration <= 180)
            {
                extendedVisits++;
                cout << "EXTENDED VISIT" << endl;
            }

            //Long session check
            if (duration>= 120)
            {
                cout << "LONG SESSION CHECK" << endl; 
            }

            
            //Average Duration check
            
            if (validCheckIns > 0) 
            {
                averageDuration = static_cast<double>(totalValidMinutes /validCheckIns);
            }

        }

        //if the continuation limit has not been reached, prompt for continuation
            if (attempts < 10){
                cout << "Do you want to process another check-in? (Y/N): ";
                cin >> continueChoice;
            }


    }
    

    // End-of-Day Summary Output
    cout << "\n================ VUKAFIT DAILY CHECK-IN SUMMARY ================" << endl;
    cout << "Valid Check-ins         : " << validCheckIns << endl;
    cout << "Invalid Attempts        : " << invalidAttempts << endl;
    cout << "Short Visits            : " << shortVisits << endl;
    cout << "Standard Visits         : " << standardVisits << endl;
    cout << "Extended Visits         : " << extendedVisits << endl;
    cout << "Gym Floor Visits        : " << gymFloorVisits << endl;
    cout << "Group Class Visits      : " << groupClassVisits << endl;
    cout << "Consultations           : " << consultations << endl;
    cout << "Total Valid Minutes     : " << totalValidMinutes << endl;
    cout << fixed << setprecision(2); //to set the decimal of the average duration to 2 decimal places
    cout << "Average Visit Duration  : " << averageDuration << endl;
    cout << "================================================================" << endl;

    return 0;
}