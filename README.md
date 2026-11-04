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
    //Declaring the main varia
    Declare String studentNumber, studentName, membershipName
    Declare Integer membershipCode, months
    Declare Character assessmentChoice
    Declare Real monthlyRate, subtotal, discount, assessmentFee, finalAmount
