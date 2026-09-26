# 🏥 Smart Hospital & Resource Allocation System

## 📌 Project Overview

The **Smart Hospital & Resource Allocation System** is an individual programming assignment developed for **CSC 1012 – Introduction to Computer Programming** at the **University of Sri Jayewardenepura, Faculty of Applied Sciences**.

The project is a **modular, menu-driven system written in C** that simulates essential hospital operations such as patient registration, emergency triage, doctor specialty selection, bed allocation, waiting-time estimation, medical billing, and hospital performance reporting.

The system demonstrates fundamental C programming concepts including **arrays, 2D arrays, functions, strings, loops, conditional statements, mathematical calculations, sorting algorithms, and file handling**.

---

## 🎯 Project Objectives

The main objectives of this project are to:

* Register and manage patient information.
* Handle emergency and triage priorities.
* Manage doctor specialties and consultation details.
* Allocate hospital beds based on ward availability.
* Calculate estimated patient waiting times.
* Calculate consultation fees, emergency surcharges, ward costs, and discounts.
* Generate the final amount payable for each patient.
* Sort patients according to emergency priority.
* Generate hospital performance and revenue reports.
* Store important information using files for future system runs.

---

## ⚙️ Main Features

### 1. 🩺 Doctor Specialty Management

The system contains predefined doctor specialties with their corresponding:

* Specialty ID
* Specialty name
* Base consultation fee
* Average consultation time
* Daily patient capacity

Available specialties include:

* General Practice (OPD)
* Paediatrics
* Cardiology
* Neurology

---

### 2. 🛏️ Hospital Ward & Bed Management

The system manages different hospital wards and their bed capacities.

| Ward            | Daily Rate | Capacity |
| --------------- | ---------: | -------: |
| General Ward    |  LKR 3,000 |       20 |
| Paediatric Ward |  LKR 6,000 |       10 |
| Surgical Ward   | LKR 12,000 |       10 |
| ICU             | LKR 25,000 |        5 |

A **2D integer array** is used to track bed occupancy, where:

* `0` = Available
* `1` = Occupied

---

### 3. 👤 Patient Registration

During registration, the system collects:

* Patient name
* Patient age
* Emergency/Triage level
* Preferred medical specialty
* Ward admission status
* Ward ID
* Number of admission days

Triage levels are:

* **Level 1 – Normal**
* **Level 2 – Urgent**
* **Level 3 – Critical**

---

### 4. ⏱️ Waiting Time Calculation

The estimated waiting time is calculated using:

**Waiting Time = Current Queue Count × Average Consultation Time**

The specialty queue count is updated whenever a new patient is registered.

---

### 5. 💰 Medical Billing

The system automatically calculates the patient's total bill using the assignment's specified formulas.

The calculation includes:

* Base consultation fee
* Emergency surcharge
* Ward stay cost
* Gross bill
* Age-based subsidy discount
* Final payable amount

Emergency surcharges are:

| Urgency Level | Surcharge |
| ------------- | --------: |
| Normal        |        0% |
| Urgent        |       20% |
| Critical      |       50% |

Patients **below 5 years or above 65 years** receive a **15% discount on the gross bill**.

---

### 6. 🚨 Emergency Priority Sorting

Registered patients can be displayed according to their emergency priority.

The priority order is:

1. **Critical – Level 3**
2. **Urgent – Level 2**
3. **Normal – Level 1**

If two patients have the same urgency level, their **registration order** is maintained as the secondary priority.

A sorting algorithm such as **Selection Sort or Bubble Sort** is used for this functionality.

---

### 7. 📊 Performance Reports & Analytics

The system provides summary reports containing:

* Total number of registered patients
* Patient count by urgency level
* Total revenue generated
* Total discounts granted
* Bed occupancy percentage for each ward
* Highest-paying patient's name
* Highest-paying patient's total bill

---

### 8. 📁 File Handling

File handling is implemented as an additional feature for storing data between program runs.

The system can use:

* `beds_status.txt` – Stores and loads bed occupancy information.
* `patient_records.txt` – Maintains permanent patient billing records.

This functionality is included as **bonus marks** in the assignment.

---

## 🧠 Programming Concepts Used

This project demonstrates the following C programming concepts:

* Variables and data types
* Constants
* `if`, `else if`, and `else`
* `switch` statements
* `for` and `while` loops
* 1D arrays
* 2D arrays
* Parallel arrays
* Strings and string functions
* User-defined functions
* Mathematical calculations
* Searching and sorting
* Menu-driven programming
* File handling
* Input validation
* Modular programming

The assignment permits the use of **C structures (`struct`)**, although they are optional; the system can also be implemented using parallel arrays.

---

## 🗂️ Suggested Project Structure

```text
Smart-Hospital-Resource-Allocation/
│
├── main.c
├── functions.c
├── functions.h
├── beds_status.txt
├── patient_records.txt
├── README.md
└── Project_Report.pdf
```

> The exact file structure may vary depending on the implementation.

---

## ▶️ How to Run

### Step 1 – Clone the Repository

```bash
git clone <your-github-repository-url>
```

### Step 2 – Open the Project Folder

```bash
cd Smart-Hospital-Resource-Allocation
```

### Step 3 – Compile the Program

Using GCC:

```bash
gcc main.c functions.c -o hospital
```

### Step 4 – Run the Program

On Windows:

```bash
hospital.exe
```

On Linux/macOS:

```bash
./hospital
```

If your project uses only `main.c`, compilation can simply be:

```bash
gcc main.c -o hospital
```

---

## 🖥️ System Workflow

```text
Start
  │
  ▼
Main Menu
  │
  ├── Register Patient
  │       │
  │       ├── Enter Patient Details
  │       ├── Select Specialty
  │       ├── Select Ward
  │       ├── Allocate Bed
  │       └── Calculate Bill
  │
  ├── View Patient Records
  │
  ├── Emergency Priority List
  │
  ├── Hospital Reports
  │
  ├── Bed Occupancy
  │
  └── Exit
          │
          ▼
         End
```

---

## 📋 Sample Billing Output

```text
====================================================
        SMART HOSPITAL ADMISSION & BILL
----------------------------------------------------
Patient ID        : PAT-1001
Patient Name      : Mr. Kamal Perera
Age               : 70 Years
Specialty         : Cardiology
Assigned Ward     : ICU
Bed Number        : 01
Urgency Level     : Level 3 (Critical)
----------------------------------------------------
Base Consultation Fee : LKR 4,500.00
Emergency Surcharge   : LKR 2,250.00
Ward Stay Cost        : LKR 50,000.00
----------------------------------------------------
Gross Total Bill      : LKR 56,750.00
Age Subsidy Discount  : LKR 8,512.50
----------------------------------------------------
Final Payable Amount  : LKR 48,237.50
Estimated Waiting Time: 0.00 mins
====================================================
```

This follows the sample output format provided in the assignment specification.






