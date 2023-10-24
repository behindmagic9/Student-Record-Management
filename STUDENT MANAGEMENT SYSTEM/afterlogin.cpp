#include "afterlogin.h"

void a_login(){
    int input;
    bool temp = false;
    while(true){
        cout << "ENTER 1 to ADD a STUDENT\n";
        cout << "ENTER 2 to VIEW a STUDENT\n";
        cout << "ENTER 3 to DELETE a STUDENT\n";
        cout << "Enter 4 to GET ALL STUDENTS DATA\n";
        cout << "ENTER 5 to EXIT\n";
        cout << "Enter 6 to UPDATE\n" ;
        do {
            if (cin >> input) {
                temp = true;
                break;
            } else {   // Clear the bad state
                cin.clear();

                // Ignore the rest of the line
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                temp = false;
                cout << "Thats a wrong input type correct it !! \n";
            }
        }while(temp == true);
        student s1;
    	//loadStudentData(s1.Students);
        
            switch (input) {

                case 1 :
                    s1.add();
                    break;
                case 2 :
                    view();
                    break;
                case 3 :
                    dlt();
                    break;
                case 4 :
                    viewall();
                    break;
                case 6 :
                      s1.update();
                case 5 :
                    cout
                            << "\n\n "<<string(40,'>') << "!!!!!!! THANKS FOR USING THE STUDENT MANAGEMENT SYSTEM !!!!!!" << string(40,'>') <<"\n\n";
                    exit(0);
                default:
                    cout << "\n\n "<< string(40,'>') << "!!!!! INCORRECT INPUT !!!!!!" << string(40,'>') <<"\n\n";
                    break;

        }
    }

}
