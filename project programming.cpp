#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string name;
    int score = 0;
    int roll_no;
    char userAnswer;

    // 1. LOGIN SECTION
    cout << "------------------------" << endl;
    cout << "   QUIZ       " << endl;
    cout << "------------------------" << endl;
    cout << "Enter your name to start: ";
    getline(cin, name);
    cout<<"Enter your roll no:";
    cin>>roll_no;
    cout << "\nWelcome " << name << "! Answer with A, B, C, or D.\n";

    // 2. QUESTIONS DATA (10 Questions with 4 Options Each)
    string questions[10] = {
        "1. Which header file is used for Input/Output?",
        "2. Which of these is NOT a data type in C++?",
        "3. How do you start a single-line comment?",
        "4. Which operator is used for comparison?",
        "5. What is the size of an 'int' typically?",
        "6. Which loop is guaranteed to run at least once?",
        "7. Which keyword is used to create a class?",
        "8. Who created C++?",
        "9. What is the extension for C++ files?",
        "10. Which command is used to print output?"
    };

    string options[10] = {
        "A) iostream  B) string  C) fstream  D) math",
        "A) int  B) decimal  C) float  D) double",
        "A) //  B) /*  C) #  D) <!--",
        "A) =  B) ==  C) !=  D)Both B & C",
        "A) 1 byte  B) 2 bytes  C) 4 bytes  D) 8 bytes",
        "A) for  B) while  C) do-while  D) if",
        "A) struct  B) void  C) class  D) object",
        "A) Dennis Ritchie  B) Bjarne Stroustrup  C) James Gosling  D) Bill Gates",
        "A) .cpp  B) .c  C) .txt  D) .exe",
        "A) cin  B) cout  C) print  D) scanf"
    };

    char correctAnswers[10] = {'A', 'B', 'A', 'D', 'C', 'C', 'C', 'B', 'A', 'B'};

    // 3. QUIZ EXECUTION LOOP
    for (int i = 0; i < 10; i++) {
        cout << "\n" << questions[i] << endl;
        cout << options[i] << endl;
        cout << "Your Answer: ";
        cin >> userAnswer;

        // Check if answer is correct (converts lowercase to uppercase)
        if (toupper(userAnswer) == correctAnswers[i]) {
            cout << "Result: Correct!" << endl;
            score++;
        } else {
            cout << "Result: Wrong! (Correct: " << correctAnswers[i] << ")" << endl;
        }
    }

    // 4. DISPLAY RESULTS
    cout << "\n----------------------------------" << endl;
    cout << name<<" TOTAL SCORE: " << score << " / 10" << endl;
    cout << "----------------------------------" << endl;

    // 5. FILE HANDLING (Saving the Record)
    ofstream file;
    file.open("quiz_records.txt", ios::app); // Opens file and adds to the end
    if (file.is_open()) {
        file << "Name: " << name <<"| Roll_no: "<<roll_no<< " | Final Score: " << score << "/10" << endl;
        file.close();
        cout << "System: Record successfully saved to 'quiz_records.txt'." << endl;
    } else {
        cout << "System Error: Could not save the record." << endl;
    }

    return 0;
}