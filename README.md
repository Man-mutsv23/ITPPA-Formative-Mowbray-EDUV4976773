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

| Input | Processing | Output |
| :--- | :--- | :--- |
| • `studentNumber` (`string`)<br>• `studentName` (`string`)<br>• `membershipCode` (`int`)<br>• `months` (`int`)<br>• `assessmentChoice` (`char`) | 1. Prompt and read student credentials (`studentNumber`, `studentName`).<br>2. Prompt for `membershipCode` (1 to 3):<br>&nbsp;&nbsp;&nbsp;&nbsp;• If < 1 or > 3, display error and terminate.<br>&nbsp;&nbsp;&nbsp;&nbsp;• If valid, map tier: 1 = R220, 2 = R350, 3 = R480.<br>3. Prompt for `months` (1 to 6):<br>&nbsp;&nbsp;&nbsp;&nbsp;• If < 1 or > 6, display error and terminate.<br>4. Calculate `subtotal = monthlyRate * months`.<br>5. Determine commitment discount rate:<br>&nbsp;&nbsp;&nbsp;&nbsp;• If `months == 6`: discount rate = 12%<br>&nbsp;&nbsp;&nbsp;&nbsp;• Else if `months >= 3`: discount rate = 7%<br>&nbsp;&nbsp;&nbsp;&nbsp;• Else: discount rate = 0%<br>6. Prompt for `assessmentChoice` ('Y'/'N'):<br>&nbsp;&nbsp;&nbsp;&nbsp;• If 'Y' or 'y', `assessmentFee = 180.00`; else `0.00`.<br>7. Compute `finalAmount = subtotal - discount + assessmentFee`. | • Quotation header<br>• Student Number and Name<br>• Membership tier name<br>• Number of months<br>• Monthly fee (R)<br>• Subtotal (R)<br>• Discount amount (R)<br>• Assessment fee (R)<br>• Final amount due (R)<br>• Error messages for invalid inputs |

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
| Test Case | Scenario / Logic Tested | Inputs | Expected Output | Actual Output | Pass/Fail |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **TC 1.1** | Tier 3, 6-Month Commitment with Assessment *(Mandatory Minimum Case)* | Student No: `VF1008`<br>Name: `Thapelo Gama`<br>Tier: `3`<br>Months: `6`<br>Assessment: `Y` | Tier: Complete Wellness<br>Monthly Fee: R480.00<br>Subtotal: R2880.00<br>Discount (12%): R345.60<br>Assessment Fee: R180.00<br>Final Total: R2714.40 | Matches Expected | **Pass** |
| **TC 1.2** | Tier 2, 6-Month Commitment with Assessment *(Sample Output Verification)* | Student No: `VF1008`<br>Name: `Thapelo Gama`<br>Tier: `2`<br>Months: `6`<br>Assessment: `Y` | Tier: Active Plus<br>Monthly Fee: R350.00<br>Subtotal: R2100.00<br>Discount (12%): R252.00<br>Assessment Fee: R180.00<br>Final Total: R2028.00 | Matches Expected | **Pass** |
| **TC 1.3** | 7% Discount Bracket Check (Tier 1, 3 Months, No Assessment) | Student No: `VF1015`<br>Name: `Sarah Adams`<br>Tier: `1`<br>Months: `3`<br>Assessment: `N` | Tier: Basic Access<br>Monthly Fee: R220.00<br>Subtotal: R660.00<br>Discount (7%): R46.20<br>Assessment Fee: R0.00<br>Final Total: R613.80 | Matches Expected | **Pass** |
| **TC 1.4** | 0% Discount Bracket Check (Tier 2, 2 Months, No Assessment) | Student No: `VF1020`<br>Name: `John Doe`<br>Tier: `2`<br>Months: `2`<br>Assessment: `N` | Tier: Active Plus<br>Monthly Fee: R350.00<br>Subtotal: R700.00<br>Discount (0%): R0.00<br>Assessment Fee: R0.00<br>Final Total: R700.00 | Matches Expected | **Pass** |
| **TC 1.5** | Invalid Tier Code Boundary Trapping (`code ∉ 1..3`) | Student No: `VF1030`<br>Name: `Jane Smith`<br>Tier: `4` | Error message: Invalid membership tier code.<br>Immediate program termination. | Matches Expected | **Pass** |
| **TC 1.6** | Duration Boundary Trapping (`months > 6`) | Student No: `VF1035`<br>Name: `Mike Ross`<br>Tier: `1`<br>Months: `7` | Error message: Duration must be between 1 and 6 months.<br>Immediate program termination. | Matches Expected | **Pass** |
    
