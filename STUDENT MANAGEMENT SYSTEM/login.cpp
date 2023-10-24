#include"login.h"

int getch() {
    int ch;
    struct termios t_old, t_new;

    tcgetattr(STDIN_FILENO, &t_old);
    t_new = t_old;
    t_new.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t_new);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &t_old);
    return ch;
}

string getpass()
{
    bool show_asterisk=true;
    const char BACKSPACE=127;
    const char RETURN=10;

    string password;
    unsigned char ch=0;

    while((ch=getch())!=RETURN)
    {
        if(ch==BACKSPACE)
        {
            if(password.length()!=0)
            {
                if(show_asterisk)
                    cout <<"\b \b";
                password.resize(password.length()-1);
            }
            for(char ch: password){
                if(!isprint((ch))){
                    cout << "Non printable ASCII character detected \n";
                }
            }
        }
        else
        {
            password+=ch;
            cout <<'*';
        }
    }
    cout <<endl;
    return password;
}

void login(int &temp){
    int i =0;
    const char *correct_password = "passwd";
    const char *correct_username = "admin";

    while(temp!= 1) {
        string usname;
        string password;
        cout << "\n\n" << string(40,'>') << " !!!!!!!! WELCOME TO STUDENT MANAGEMENT SYSTEM !!!!!!!!  " << string(40, '<') << "\n\n";
        cout << string(40,'>') << " !!!!!!!! PLEASE ENTER THE USERNAME !!!!!!!!  " << string(40, '<') << "\n\n";
        getline(cin,usname);
        cout << string(40,'>') << " !!!!!!!! PLEASE ENTER THE PASSWORD !!!!!!!! !!" << string(40, '<') << "\n\n";
//      cin >> password;
        password = getpass();

        if (usname == "admin" && password == correct_password) {
            cout << string(40,'>') << " !!!!!!!! LOGIN SUCCESSFULLY !!!!!!!! " << string(40, '<') << "\n\n";
            temp = 1;
            break;
        } else {
            cout << string(40,'>') << " !!!!!!!! INVALID USERNAME or PASSWORD !!!!!!!! "<< string(40,'<') << "\n\n";
            i++;
        }
        if(i == 3){
            cout << string(40,'>') << " !!!!!!!! ENTERED WRONG DETAILS THREE TIMES !!!!!!!!"<< string(40,'<')<< "\n\n ";
            break;
        }
    }
}