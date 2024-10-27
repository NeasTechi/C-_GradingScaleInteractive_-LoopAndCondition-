#include <iostream>
//Storing grade scale
#include <vector> 
#include <fstream>
using namespace std;

// Function to determine the grade based on average
char determineGrade(double average) {
    if (average >= 90) {
        return 'A';
    } else if (average >= 80) {
        return 'B';
    } else if (average >= 70) {
        return 'C';
    } else if (average >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

// Function to predict the Grades of student's future
void predictFuture(char grade) {
    switch (grade) {
        case 'A':
            cout << "🌟 YOUR FUTURE IS GREAT! EXPECT MANY MONEY TO COME BECUASE OF YOUR SUCCESS AND  HAPPINESS." << endl;
            break;
        case 'B':
            cout << "🔮 YOUR FUTURE IS VERY NICE! JUST SIMPLE BUT OUTSTANDING... KEEP IT UP FOR A COMFY SUCCESS." << endl;
            break;
        case 'C':
            cout << "⚡️ YOUR FUTURE IS FULL OF SURPRISES! FIND IT, AND YOU WILL LEARN VAST KNOWLEDGE FOR YOUR SUCCESS." << endl;
            break;
        case 'D':
            cout << "🌧️ YOUR FUTURE IS PENDING FOR ACHIEVING GREAT SUCCESS!" << endl;
            break;
        default:
            cout << "🔮 YOUR FUTURE REMAINS UNCERTAIN AND MAY CAUSE YOU TROUBLE ALSO. BUILD UP YOUR SKILLS AND KNOWLEDGE FOR ACHIEVING YOUR STANDARD SUCCESS. " << endl;
    }
}

int main() {
    vector<char>gradeBook;

    char choice;
    do {
        double average;

        //Declare string name
        string name;

        //Input name
        cout << " ENTER NAME OR SUBJECT:_____";
        cin >> name;

        // Input average/grade
        cout << "ENTER AVERAGE OR GRADE: ";
        cin >> average;

        // Determine the grade
        char grade = determineGrade(average);

        // Display the result
        cout << "STUDENT GRADE IS: " << grade << endl;

        // Determine the future according to grade/avarage
        predictFuture(grade);

        //Save grade in ledger
        gradeBook.push_back(grade);

        // Print the grades in the ledger
        cout << "GRADES IN THE GRADEBOOK:" << endl;
        for (char grade : gradeBook) {
            cout << grade << " ";
        }
        cout << endl;

        //Save grade to file
        ofstream outputFile("grades.txt",ios::app);
        //Open the file append mode
        if (outputFile.is_open()) {
            outputFile << grade << " ";
        //Write the grade to the file
        outputFile.close();
        //Close the file
        cout << "GRADE SAVED TO grades.txt" << endl;
        cout << "ERROR OPENING FILE FOR WRITING." <<endl;
        }

        // Ask if the user wants to check another grade
        cout << "DO YOU WANT TO CHECK ANOTHER GRADE AGAIN (Y/N): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "IT'S A PLEASURE FOR USING MY SYSTEM... TY :)" << endl;

    return 0;
}