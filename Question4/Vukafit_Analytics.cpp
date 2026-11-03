#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(){

    //setting the number of days as constants 
    const int NUM_OF_DAYS = 5;
    const int NUM_OF_PROGRAMMES = 3;

    //Declaring and populating the 1D and 2D arrays
    
    string programmes[NUM_OF_PROGRAMMES] = {"Yoga", "Strength", "Wellness Workshop"};
    string days[NUM_OF_DAYS] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

    int attendance[NUM_OF_PROGRAMMES][NUM_OF_DAYS] = 
    {

        {24, 31, 28, 35, 30},
        {38 , 42, 36, 45, 41},
        {18, 22, 25, 20, 27}

    };

    int programTotals[NUM_OF_PROGRAMMES] = {0};
    int dayTotals[NUM_OF_DAYS] = {0};
    int highDemand = 0;
    int grandTotal = 0;

    cout << "==========================================================================" << endl;
    cout << "                    VUKAFIT WEEKLY ATTENDANCE REPORT                      " << endl;
    cout << "==========================================================================" << endl;

    //setting the display headers
    cout << left << setw(20) << "Programme";
    for (int d = 0; d < NUM_OF_DAYS; d++){
        cout << right << setw(10)<<days[d];
    }
    cout << endl;
    cout << "--------------------------------------------------------------------------" << endl;

    //Displaying attendance grid
    for (int p = 0; p < NUM_OF_PROGRAMMES; p++){
        cout << left << setw(20) << programmes[p];
        for (int d = 0; d< NUM_OF_DAYS; d++){
            cout << right << setw(10) << attendance[p][d];

            //Programme totals
            programTotals[p] += attendance[p][d];
            dayTotals[d] += attendance[p][d];
            grandTotal += attendance[p][d];

            //check for high demand pro
            if (attendance[p][d] >= 40){
                highDemand++;
            }

        } cout << endl;
    }

    cout << "==========================================================================" << endl;

    //The Programme stats and peak days
    cout << "\n======================== PROGRAMME PERFORMANCE ========================" << endl;
    int maxProgramIndex = 0;

    cout << fixed << setprecision(2);
    for (int p = 0; p < NUM_OF_PROGRAMMES; p++){
        double average = static_cast<double>(programTotals[p]) / NUM_OF_DAYS;

        //Look for the day with the highest attendance for the programme
        int maxDayIndex = 0;
        for (int d = 1; d < NUM_OF_DAYS; d++) {
            if (attendance[p][d] > attendance[p][maxDayIndex]){
                maxDayIndex = d;
            }
        }
       
        cout << programmes[p] << ":" << endl;
        cout << "  Weekly Total            : " << programTotals[p] << endl;
        cout << "  Daily Average           : " << average << endl;
        cout << "  Highest Attendance Day  : " << days[maxDayIndex] 
             << " (" << attendance[p][maxDayIndex] << " attendees)" << endl;

        //Track the most requested program
        if (programTotals[p] > programTotals[maxProgramIndex] ){ 
            
            maxProgramIndex = p;
        }

        

        
    }
        
    //Weekday Totals and the busiest day
        cout << "\n========================== WEEKDAY BREAKDOWN ==========================" << endl;
        int busyDayIndex = 0;

        for (int d = 0; d < NUM_OF_DAYS; d++){

            cout << left << setw(12) << days[d] << ":";
            cout << right << setw(4) << dayTotals[d] << " attendees" << endl;

            if (dayTotals[d] > dayTotals[busyDayIndex]) {

                busyDayIndex = d;
            }

        }

        //Overall Summary
        double overallAverage = static_cast<double>(grandTotal)/ (NUM_OF_DAYS * NUM_OF_PROGRAMMES);

        cout << "\n=========================== OVERALL SUMMARY ===========================" << endl;
        cout << "Top Programme (Highest Total) : " << programmes[maxProgramIndex] 
            << " (" << programTotals[maxProgramIndex] << " attendees)" << endl;
        cout << "Overall Busiest Weekday       : " << days[busyDayIndex] 
            << " (" << dayTotals[busyDayIndex] << " attendees)" << endl;
        cout << "High Demand Sessions (>= 40)  : " << highDemand << endl;
        cout << "Grand Total Attendance        : " << grandTotal << endl;
        cout << "Overall Average Attendance    : " << overallAverage << endl;
        cout << "=======================================================================" << endl;
}