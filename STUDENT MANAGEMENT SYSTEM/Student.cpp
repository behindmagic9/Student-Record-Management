#include"Student.h"

student::student(int long long roll_num, string name ,string fat_nm, float grd) : roll_no(roll_num), sname(name),fath_name(fat_nm), grade(grd) {
}
student::~student() {

}
void student::add(){
    string name;
    int long long roll_num{};
    float grade;
    string FathName;
    bool success = false;

// Enter the roll number of the student
    cin.ignore();
    roll_num = searchh();
    cin.ignore();

    cout << "\nEnter the name of student\n";
    while(true) {
        try{getline(cin, name);
            break;
        }catch(exception& e){
            cerr << "Error : " << e.what()<< endl;
            cout << "Please try again!! \n";
            continue;
        }
    }
    cout << "Enter the overall grade/pointer of student " << name << "\n";
    while (true) {
        cin >> grade;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (!cin.fail()) {
            break;
        }
        cout << "Invalid input. Please try again: ";
    }
    cin.ignore();

    cout << "Enter the father's name\n";
    while(true) {
        try{getline(cin, FathName);
            break;
        }catch(exception& e){
            cerr << "Error : " << e.what()<< endl;
            cout << "Please try again!! \n";
            continue;
        }
    }



    student s1(roll_num, name, FathName, grade);
    s1.Students.push_back(s1);
    success = true;
    if(success ){
        ofstream file_op;
        file_op.open("students.txt", ios::app);
        if(!file_op) {
            throw ios_base::failure("Error opening File!!  ");
        }

//        file_op << std::left << setw(2) << " | " << std::setw(20) <<  "ROLL NUMBER" << " | " <<  std::setw(20) << "NAME" << " | " <<  std::setw(20) << "FATHER'S NAME" << " | " <<  std::right <<std::setw(20) << "GRADE"<< " | \n"  ;
        file_op << std::left << setw(2) << " | " << std::setw(20) << s1.get_roll_no() << " | " << std::setw(20)
                << s1.get_name() << " | " << std::setw(20) << s1.getFathName() << " | " << std::right
                << std::setw(20)
                << s1.getGrade() << " | " << std::endl;
        file_op.close();
        cout << "\n>>>>>>>>>>>>>>>>>>>>>>>  Student registered successfully!!  <<<<<<<<<<<<<<<<<<<<<\n\n\n";

    }
}

void view() {
//    char roll[15];
//    char data[20];
    string data;
    string roll;
    string fr;
    cout << "Enter the Roll number to found for  - ";
    while (true) {
        cin >> roll;
        if (cin.fail()) {
            cin.clear();
            //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (!cin.fail()) {
            break;
        }

        cout << "Invalid input. Please try again: ";
    }
    ifstream srchfile;
    srchfile.open("students.txt",ios::in);
    if (srchfile.is_open()) {
        while (srchfile.good()) {
            while (srchfile >> data) {
                if (strcmp(data.c_str(), roll.c_str()) == 0) {
                    cout << std::left << setw(2) << " | " << std::setw(20) << "ROLL NUMBER" << " | " << std::setw(20) << "NAME" << " | "
                         << std::setw(20) << "FATHER'S NAME" << " | " << std::right << std::setw(20) << "GRADE" << " | " << std::endl;
                    srchfile >> fr;
                    getline(srchfile,fr);
                    cout << std::left << setw(2) << " | " << std::setw(20) << data << " |" << fr << "\n";
                    srchfile.close();
//                  cout << std::left << setw(2) << " | " << std::setw(20) << data << " | "  ; srchfile >> data ;srchfile >> data ; cout << std::setw(20)  << " | "; srchfile >> data ; cout << data  <<  std::setw(20)  << data  << " | "; srchfile >> data ; cout <<  std::right <<std::setw(20) << data  << " | \n" ;
//                  cout << data << "\n";
                }
            }
        }
    } else {
        cout << "Could'nt open the file!!\n";
    }


}

void viewall() {
    string data;
    ifstream infile;
    infile.open("students.txt");
    if(infile.is_open()) {
        while(infile.good()){
            getline(infile,data);
            cout << data << "\n";
        }
    }
    else{
        cout << "Could'nt open the file!!\n";
    }

}


void dlt() {
    string roll;
    string data;
    bool goot ;
    bool check;
    int count{};
    ifstream srchfile;
    srchfile.open("students.txt",ios::in);
    if (srchfile.is_open()) {
        while (srchfile.good()) {
            do {
                cout << "\nEnter the Roll number to delete - \n";
                while (true) {
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                    cin >> roll;
                    if (!cin.fail()) {
                        break;
                    }

                    cout << "Invalid input. Please try again: ";
                }
                while (srchfile >> data) {
                    if (strcmp(data.c_str(), roll.c_str()) == 0) {
                        count = getCurrentLine(srchfile);
                        cout << "!!!! Found ROll Number  !!!!"<< "\n" << endl;
                        check = true;
                    }
                }
                if(check == false) {
                    goot = false;
                }
                if(check == true) {goot = true; break;}
            }while(goot!= false);
        }
    } else {
        cout << "Could'nt open the file!!\n";
    }
    srchfile.close();
    ifstream is;
    is.open("students.txt");
    ofstream temp;
    temp.open("temp.txt");
    if (!is.is_open() || !temp.is_open()) {
        std::cerr << "Error opening file" << std::endl;

    }
    int lineNumber = 1;
    string line;;
    while(getline(is,line)){
        if(lineNumber != count){
            temp << line << endl;
        }
        lineNumber++;
    }
    temp.close();
    is.close();
    remove("students.txt");
    rename("temp.txt","students.txt");
    cout << "\n\n >>>>>>>>>>> Student deleted successfully!! <<<<<<<<<<<<<<<<<<<<<\n\n";
}
int long long searchh(){
    string roll;
    string data;
    char back;
    bool goot ;
    bool check;
    ifstream srchfile;
    srchfile.open("students.txt",ios::in);
    if (srchfile.is_open()) {
        while (srchfile.good()) {
            do {
                cout << "\nEnter the Roll number - \n";
                while (true) {
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                    cin >> roll;
                    if (!cin.fail()) {
                        break;
                    }

                    cout << "Invalid input. Please try again: ";
                }
                while (srchfile >> data) {
                    if (strcmp(data.c_str(), roll.c_str()) == 0) {
                        cout << "!!!! Alreaady registreed !!!!    !!!!! Please Try To Enter a Correct ROll Number  !!!!" << endl;
                        check = true;
                        break;
                    }
                }
                if(check == false) {
                    goot = true;
                    break;
                }
                if(check == true) {goot = false;}
            }while(goot!= false);
        }
    } else {
        cout << "Could'nt open the file!!\n";
    }
    srchfile.close();
    int long long x = stol(roll);
    return x;
}
int getCurrentLine(std::istream& is)
{
    int lineCount = 1;
    is.clear();     // need to clear error bits otherwise tellg returns -1.
    auto originalPos = is.tellg();
    is.seekg(0);
    char c;
    while ((is.tellg() < originalPos) && is.get(c))
    {
        if (c == '\n') ++lineCount;
    }
    return lineCount;
}


std::vector<student> student::loadStudentData(const std::string& filename,std::vector<student> &students) {

        std::ifstream infile(filename);

        if (!infile) {
            std::cerr << "Error opening file." << std::endl;
            return students; // Return an empty vector in case of an error
        }
    std::string line;
    bool firstLine = true; // Flag to skip the first line

    while (std::getline(infile, line)) {
        if (firstLine) {
            firstLine = false;
            continue; // Skip the first line
        }
          // Remove leading '|' characters
	    while (!line.empty() && line[0] == '|') {
		line = line.substr(1);
	    }


        std::istringstream iss(line);
        std::string token;
        std::string token1;


        int long long roll_num;
        std::string name, fat_nm;
        float grade;
	std::string tag;
	
            if (!(std::getline(iss >> std::ws , tag , '|' ) &&
            std::getline(iss >> std::ws, token, '|') &&
                  std::getline(iss >> std::ws, name, '|') &&
                  std::getline(iss >> std::ws, fat_nm, '|') &&
                  std::getline(iss >> std::ws, token1, '|'))) {
                std::cerr << "Error parsing data: " << line << std::endl;
                continue; // Skip this line and move to the next
            }

	    std::cout << "roll nu is " << token << std::endl;
    	    std::cout << "name nu is " << name << std::endl;
    	    std::cout << "fath_name nu is " << fat_nm << std::endl;
    	    std::cout << "grade is " << token1 << std::endl;


            try {
                roll_num = std::stoll(token);
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error parsing roll_num: " << token << std::endl;
                continue; // Skip this line and move to the next
            }

            try {
                grade = std::stof(token1);
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error parsing grade: " << token << std::endl;
                continue; // Skip this line and move to the next
            }
	    try{
            students.emplace_back(roll_num, name, fat_nm, grade);
            std::cout << "success \n" ;
            }catch(std::exception &e){
            	std::cout << e.what() << std::endl;
            }
            
        }

        infile.close();
        return students;
    }

void student::update() {
	student s1;
	s1.Students = s1.loadStudentData("students.txt",s1.Students);
    int long long rollToUpdate;
    std::cout << "Enter the Roll number of the student to update: ";
    std::cin >> rollToUpdate;

    bool found = false;
    for (student& s : s1.Students) {
        if (s.get_roll_no() == rollToUpdate) {
            found = true;
            std::cout << "Enter the new name: ";
            std::cin.ignore(); // Ignore the newline character left in the buffer
            std::string name;
            std::getline(std::cin, name); // Update the name field (you can update other fields similarly)
            s.set_name(name);
            break; // No need to continue searching
        }
    }

    if (!found) {
        std::cout << "Student with Roll number " << rollToUpdate << " not found." << std::endl;
        return;
    }

    std::ofstream outfile("students.txt");
    if (!outfile) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }
	
    outfile << std::left << setw(2) << " | " << std::setw(20) <<  "ROLL NUMBER" << " | " <<  std::setw(20) << "NAME" << " | " <<  std::setw(20) << "FATHER'S NAME" << " | " <<  std::right <<std::setw(20) << "GRADE"<< " | \n"  ;
    for(student& s : s1.Students){
        outfile << std::left << setw(2) << " | " << std::setw(20) << s.get_roll_no() << " | " << std::setw(20) << s.get_name() << " | " << std::setw(20) << s.getFathName() << " | " << std::right << std::setw(20) << s.getGrade() << " | " << std::endl;
    }

    outfile.close();

    std::cout << "Student record updated successfully." << std::endl;
}



