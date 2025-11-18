#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Algorithm 1 check if a student fails the lecture (from lab 13 pdf)
bool fail_lecture(const vector<int>& attendance_records) {
    int absent_count = 0;
    
    // QUESTION 1: FAULT -- for loop starts at i = 1, this means it only checks attendence from indices 1-9 instead of 0-9
    for (int i = 1; i < attendance_records.size(); ++i) {
        // checks if the student was absent 0
        // adds 1 to count if true 0 if false
        absent_count += (attendance_records[i] == 0); 
    }
    
    return absent_count >= 3;
}

// helper function to print test results cleanly
void run_test_case(string test_name, vector<int> records, bool expected_to_fail) {
    // heading for clarity
    cout << "--------------------------------------------------" << endl;
    cout << "Test: " << test_name << endl;
    cout << "Input: { ";
    for (int val : records) cout << val << " ";
    cout << "}" << endl;

    // run the fail_lecture function to obtain what it returns
    // returns true if student failed the course
    bool actually_failed = fail_lecture(records);

    // print the expected results vs the actual results
    cout << "Expected Result: " << (expected_to_fail ? "Student Fails" : "Student Passes") << endl;
    cout << "Actual Result:   " << (actually_failed ? "Student Fails" : "Student Passes") << endl;
    
    // compare the actual results to the expected result, if they are equal the bug did NOT affect the outcome
    if (actually_failed == expected_to_fail) {
        cout << "Status: [MATCH]" << endl;
    } else {
	// otherwise, the bug DID affect the outcome -> the bug was found/ failure detected
        cout << "Status: [FAILURE / BUG FOUND]" << endl;
    }
    cout << "--------------------------------------------------" << endl;
}

int main() {
    // -------------------------------------------------
    // QUESTION 2: test case that does not execute the fault
    // technically, it is impossible to not execute the fault because the for loop always runs
    // -------------------------------------------------
    vector<int> q2_input = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    bool q2_should_fail = false; // the student should pass the class
    run_test_case("Q2 (No Fault Execution)", q2_input, q2_should_fail);

    // -------------------------------------------------
    // QUESTION 3: executes fault but no error state
    // since index 0 is 1, skipping it does not change the absent count
    // -------------------------------------------------
    vector<int> q3_input = {1, 0, 0, 1, 1, 1, 1, 1, 1, 1};
    bool q3_should_fail = false; // the student should pass the class
    run_test_case("Q3 (Fault Executed, No Error State)", q3_input, q3_should_fail);

    // -------------------------------------------------
    // QUESTION 4: error state but no failure
    // index 0 is 0, so the absent count will be wrong (ERROR STATE)
    // however, the total absences is 2 so the return value of false is still correct (student passes the class)
    // -------------------------------------------------
    vector<int> q4_input = {0, 0, 1, 1, 1, 1, 1, 1, 1, 1};
    bool q4_should_fail = false; // the student should pass the class
    run_test_case("Q4 (Error State, No Failure)", q4_input, q4_should_fail);

    // -------------------------------------------------
    //  QUESTION 5: failure
    // index 0 is 0 and total absences is 3
    // should return true (the student should fail the class)
    // -------------------------------------------------
    vector<int> q5_input = {0, 0, 0, 1, 1, 1, 1, 1, 1, 1};
    bool q5_should_fail = true;
    run_test_case("Q5 (Failure)", q5_input, q5_should_fail);

    return 0;
}

