# ITPPA-Formative-Mowbray-EDUV4976773

# Overview

The VukaFit Campus Wellness Management System is a modular C++ program built on the principles of procedural programming to help modernise the administrative and analytical workflows of the VikaFit Campus Wellness Centre. This system replaces the manual methods of tracking, such as spreadsheets and paper forms, with four distinct procedural programs:

1. Membership Quotation(VukaFit_Quotation.cpp): This calculates the quotation by using selection structures to validate membership tiers, discounts, durations and optional assessments.
2. Booking Modules(Booking_Modules.cpp): A small group fitness booking system broken down into seven modular functions with value returning and reference parameters.
3. Check-In Porcessor(VukaFit_CheckIn.cpp): An attendance tracker which is loop-driven. It records daily visits, validates input rules, puts session lengths into categories and monitors the duration limits as well as computing statistics without division-by-0 errors.
4. Attendance Analytics (VukaFit_Analytics): An analytics program for processing a 3 by 5 multi-dimensional array to obtain weekly program totals, daily averages, peak days busiest weeks and high demand session alerts

# Program Design, Implementation and Testing

## Question 1: Membership Quotation

### 1.1 Membership Quotation Input, Processing and Output Chart

| Input                                                                                                                                                    | Processing                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           | Output                                                                                                                                                                                                                         |
| :------------------------------------------------------------------------------------------------------------------------------------------------------- | :------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| • `studentNumber` (`string`)• `studentName` (`string`)• `membershipCode` (`int`)• `months` (`int`)• `assessmentChoice` (`char`) | 1. Prompt and read student credentials (`studentNumber`, `studentName`).2. Prompt for `membershipCode` (1 to 3):&nbsp;&nbsp;&nbsp;&nbsp;• If < 1 or > 3, display error and terminate.&nbsp;&nbsp;&nbsp;&nbsp;• If valid, map tier: 1 = R220, 2 = R350, 3 = R480.3. Prompt for `months` (1 to 6):&nbsp;&nbsp;&nbsp;&nbsp;• If < 1 or > 6, display error and terminate.4. Calculate `subtotal = monthlyRate * months`.5. Determine commitment discount rate:&nbsp;&nbsp;&nbsp;&nbsp;• If `months == 6`: discount rate = 12%&nbsp;&nbsp;&nbsp;&nbsp;• Else if `months >= 3`: discount rate = 7%&nbsp;&nbsp;&nbsp;&nbsp;• Else: discount rate = 0%6. Prompt for `assessmentChoice` ('Y'/'N'):&nbsp;&nbsp;&nbsp;&nbsp;• If 'Y' or 'y', `assessmentFee = 180.00`; else `0.00`.7. Compute `finalAmount = subtotal - discount + assessmentFee`. | • Quotation header• Student Number and Name• Membership tier name• Number of months• Monthly fee (R)• Subtotal (R)• Discount amount (R)• Assessment fee (R)• Final amount due (R)• Error messages for invalid inputs |

### 1.2 Membership Quotation Algorithm and Pseudocode

Module main()

    // Constant Declarations
    Constant Real BASIC_ACCESS = 220.00
    Constant Real ACTIVE_PLUS = 350.00
    Constant Real COMPLETE_WELLNESS_RATE = 480.00
    Constant Real DISCOUNT_3_TO_5_MONTHS = 0.07
    Constant Real DISCOUNT_6_MONTHS = 0.12
    Constant Real ASSESSMENT_FEE = 180.00

    // Variable Declarations
    Declare String studentNumber, studentName, selectedMembershipPlanName
    Declare Integer membershipChoice, membershipDuration
    Declare Character include_assessment
    Declare Real initialMonthlyRate, membershipSubtotal, discountRate
    Declare Real discountAmount, assessmentCharge, fullAmountDue

    // Input Student Details
    Display "Please enter your Student Number: "
    Input studentNumber
    Display "Please enter your full name: "
    Input studentName

    // Plan Selection
    Display "Please select a Plan (1: Basic, 2: Active Plus, 3: Complete Wellness): "
    Input membershipChoice

    Select membershipChoice
        Case 1:
            Set selectedMembershipPlanName = "Basic Access"
            Set initialMonthlyRate = BASIC_ACCESS
        Case 2:
            Set selectedMembershipPlanName = "Active Plus"
            Set initialMonthlyRate = ACTIVE_PLUS
        Case 3:
            Set selectedMembershipPlanName = "Complete Wellness"
            Set initialMonthlyRate = COMPLETE_WELLNESS_RATE
        Default:
            Display "Error: You have entered an invalid membership code"
            Exit Module
    End Select

    // Duration Input and Validation
    Display "May you select the duration you'd like to sign up for (1-6): "
    Input membershipDuration

    If membershipDuration < 1 Or membershipDuration > 6 Then
        Display "Error: Duration must be between 1 and 6 months"
        Exit Module
    Else
        Set membershipSubtotal = initialMonthlyRate * membershipDuration
    End If

    // Discount Calculation
    If membershipDuration == 6 Then
        Set discountRate = DISCOUNT_6_MONTHS
    Else If membershipDuration >= 3 Then
        Set discountRate = DISCOUNT_3_TO_5_MONTHS
    Else
        Set discountRate = 0.00
    End If

    Set discountAmount = membershipSubtotal * discountRate

    // Optional Assessment
    Display "Would you require a fitness assessment as well? (Y/N): "
    Input include_assessment

    If ToLower(include_assessment) == 'y' Then
        Set assessmentCharge = ASSESSMENT_FEE
    Else
        Set assessmentCharge = 0.00
    End If

    // Final Total Calculation
    Set fullAmountDue = membershipSubtotal - discountAmount + assessmentCharge

    // Output Invoice Breakdown
    Display "======================= VUKAFIT MEMBERSHIP QUOTATION =========================="
    Display "Student        : ", studentName, " - ", studentNumber
    Display "Membership     : ", selectedMembershipPlanName
    Display "Months         : ", membershipDuration
    Display "Monthly Fee    : R", initialMonthlyRate
    Display "Subtotal       : R", membershipSubtotal
    Display "Discount       : R", discountAmount
    Display "Assessment     : R", assessmentCharge
    Display "FINAL AMOUNT   : R", fullAmountDue
End Module

#### 1.3. Test Execution Table

| Test Case        | Scenario / Logic Tested                                                     | Inputs                                                                                | Expected Output                                                                                                                  | Actual Output    | Pass/Fail      |
| :--------------- | :-------------------------------------------------------------------------- | :------------------------------------------------------------------------------------ | :------------------------------------------------------------------------------------------------------------------------------- | :--------------- | :------------- |
| **TC 1.1** | Tier 3, 6-Month Commitment with Assessment *(Mandatory Minimum Case)*     | Student No: `VF1008`Name: `Thapelo Gama`Tier: `3`Months: `6`Assessment: `Y` | Tier: Complete WellnessMonthly Fee: R480.00Subtotal: R2880.00Discount (12%): R345.60Assessment Fee: R180.00Final Total: R2714.40 | Matches Expected | **Pass** |
| **TC 1.2** | Tier 2, 6-Month Commitment with Assessment *(Sample Output Verification)* | Student No: `VF1008`Name: `Thapelo Gama`Tier: `2`Months: `6`Assessment: `Y` | Tier: Active PlusMonthly Fee: R350.00Subtotal: R2100.00Discount (12%): R252.00Assessment Fee: R180.00Final Total: R2028.00       | Matches Expected | **Pass** |
| **TC 1.3** | 7% Discount Bracket Check (Tier 1, 3 Months, No Assessment)                 | Student No: `VF1015`Name: `Sarah Adams`Tier: `1`Months: `3`Assessment: `N`  | Tier: Basic AccessMonthly Fee: R220.00Subtotal: R660.00Discount (7%): R46.20Assessment Fee: R0.00Final Total: R613.80            | Matches Expected | **Pass** |
| **TC 1.4** | 0% Discount Bracket Check (Tier 2, 2 Months, No Assessment)                 | Student No: `VF1020`Name: `John Doe`Tier: `2`Months: `2`Assessment: `N`     | Tier: Active PlusMonthly Fee: R350.00Subtotal: R700.00Discount (0%): R0.00Assessment Fee: R0.00Final Total: R700.00              | Matches Expected | **Pass** |
| **TC 1.5** | Invalid Tier Code Boundary Trapping (`code ∉ 1..3`)                      | Student No: `VF1030`Name: `Jane Smith`Tier: `4`                                 | Error message: Invalid membership tier code.Immediate program termination.                                                       | Matches Expected | **Pass** |
| **TC 1.6** | Duration Boundary Trapping (`months > 6`)                                 | Student No: `VF1035`Name: `Mike Ross`Tier: `1`Months: `7`                     | Error message: Duration must be between 1 and 6 months.Immediate program termination.                                            | Matches Expected | **Pass** |

### 1.4. How to run the program

Compile using any standard C++11 compliant compiler:

GCC/MinGW (Command line method):
**g++ -std=c++11 Question1/VukaFit_Quotation.cpp -o Question1/VukaFit_Quotation.exe
./Question1/VukaFit_Quotation.exe**

Visual Studio IDE:

Press `Ctrl + Shift + B` to compile the project then `Ctrl +F5` to run it.

### Step-by-Step Instructions

1. Enter your Student Number and Full Name.
2. Choose a membership tier: 1 (Basic Access, R220/mo), 2 (Active Plus, R350/mo), or 3 (Complete Wellness, R480/mo).
3. Enter the duration in months (1 to 6):

   6 months applies a 12% discount.

   3–5 months applies a 7% discount.

   1–2 months receives no discount.
4. Enter Y or N for the optional fitness assessment (adds R180.00 if it is selected).
5. The application displays an itemized quotation invoice and exits.


| Test Case | Scenario / Logic Tested | Inputs | Expected Output | Actual Output | Pass / Fail |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **TC 3.1** | Normal Valid Check-In (Gym Floor) | Student: `VF101`<br>Activity: `1`<br>Duration: `60`<br>Continue: `N` | Valid Check-Ins: 1<br>Total Mins: 60<br>Gym Floor: 1<br>Average: 60.00 mins | Matches Expected | **Pass** |
| **TC 3.2** | Short Visit Boundary (< 30 mins) | Student: `VF102`<br>Activity: `2`<br>Duration: `20`<br>Continue: `N` | Status: `SHORT VISIT`<br>Valid Check-Ins: 1<br>Group Class: 1<br>Average: 20.00 mins | Matches Expected | **Pass** |
| **TC 3.3** | Long Session Check Warning (≥ 120 mins) | Student: `VF103`<br>Activity: `3`<br>Duration: `125`<br>Continue: `N` | Status: `LONG SESSION CHECK`<br>Valid Check-Ins: 1<br>Consultations: 1<br>Average: 125.00 mins | Matches Expected | **Pass** |
| **TC 3.4** | Invalid Activity Code Trapping (∉ 1..3) | Student: `VF104`<br>Activity: `4`<br>Duration: `45`<br>Continue: `N` | Status: `INVALID CHECK-IN`<br>Invalid Attempts: 1<br>Valid Check-Ins: 0<br>Average: 0.00 mins | Matches Expected | **Pass** |
| **TC 3.5** | Duration Boundary Trapping (< 15 or > 180 mins) | Student: `VF105`<br>Activity: `1`<br>Duration: `10`<br>Continue: `N` | Status: `INVALID CHECK-IN`<br>Invalid Attempts: 1<br>Valid Check-Ins: 0<br>Average: 0.00 mins | Matches Expected | **Pass** |
| **TC 3.6** | Loop Cap Termination (10 Attempts Reached) | 10 consecutive entries with Continue: `Y` | System terminates loop automatically after 10th check-in without prompting; prints Daily Summary Report. | Matches Expected | **Pass** |