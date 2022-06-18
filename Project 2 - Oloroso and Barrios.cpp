/*Project 2 in CPP
by Andrew R. Oloroso and Armand Angelo C. Barrios*/
#include <iostream>
#include <iomanip> //for setprecision
#include <fstream>
#include <windows.h>
#include <time.h>
#define MAX 50
using namespace std;
typedef struct node { //self-referecial structre
    int plus1,minus1,divide1,multiply1;
    int plus2,minus2,divide2,multiply2;
    int plus3,minus3,divide3,multiply3;
    int plus4,minus4,divide4,multiply4;
    int plus5,minus5,divide5,multiply5;
    float ave1,ave2,ave3,ave4,ave5;
    string name;
    string pass;
    struct node * next;
} NODE;

class MyClass {
private:
    NODE *head;
    int locate(string n);
    bool isEmpty();
public:
    void init();
    void logIn();
    void leaderboard();
    void display();
    void save();
    void retrieve();
};
void gotoxy(int x, int y);
void box();
void smallbox();

void gotoxy(int x,int y){
    COORD coord = {0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void box(){
    int i;
    int l = 186, ul=201,ur=187,w=205,dr=188,dl=200;
    gotoxy(40,5);cout<<(char)ul;
    gotoxy(90,5);cout<<(char)ur;
    gotoxy(90,13);cout<<(char)dr;
    gotoxy(40,13);cout<<(char)dl;
    for (i=0;i<=6;i++){
         gotoxy(40,6+i);cout<<(char)l;
         gotoxy(90,6+i);cout<<(char)l;
    }
    for (i=0;i<49;i++){
        gotoxy(41+i,5);cout<<(char)w;
        gotoxy(41+i,13);cout<<(char)w;
    }
}

void smallbox(){
    int i;
    int l = 186, ul=201,ur=187,w=205,dr=188,dl=200;
    gotoxy(33,4);cout<<(char)ul;
    gotoxy(48,4);cout<<(char)ur;
    gotoxy(48,10);cout<<(char)dr;
    gotoxy(33,10);cout<<(char)dl;
    for(i=0;i<=4;i++){
        gotoxy(33,5+i);cout<<(char)l;
        gotoxy(48,5+i);cout<<(char)l;
    }
    for (i=0;i<14;i++){
        gotoxy(34+i,4);cout<<(char)w;
        gotoxy(34+i,10);cout<<(char)w;
    }
}
void MyClass::init(){
    head=NULL;
}

void MyClass::logIn(){
    NODE *p, *q, *newNode;
    p=q=head; newNode = new NODE;
    cout <<"Enter Username/UserID: "; cin.ignore();getline(cin,name);
    int l = locate(name);
}

int MyClass::locate(string n){

}

bool MyClass::isEmpty(){
    return(head==NULL);
}

void TitleScreen(){
    string game_title[21][98]=
    {
        {"##################################################################################################"},
        {"                                                                                                  "},
        {" ..:::::..::..:::::..::....:::::..:::::..:::::..::..:::::..::........:::::..:::::....:::......::: "},
        {" :::'###::::'########::'####:'########:'##::::'##:'##::::'##:'########:'########:'####::'######:: "},
        {" ::'## ##::: ##.... ##:. ##::... ##..:: ##:::: ##: ###::'###: ##.....::... ##..::. ##::'##... ##: "},
        {" :'##:. ##:: ##:::: ##:: ##::::: ##:::: ##:::: ##: ####'####: ##:::::::::: ##::::: ##:: ##:::..:: "},
        {" '##:::. ##: ########::: ##::::: ##:::: #########: ## ### ##: ######:::::: ##::::: ##:: ##::::::: "},
        {" .#########: ##.. ##:::: ##::::: ##:::: ##.... ##: ##. #: ##: ##...::::::: ##::::: ##:: ##::::::: "},
        {" .##.... ##: ##::. ##::: ##::::: ##:::: ##:::: ##: ##:.:: ##: ##:::::::::: ##::::: ##:: ##::: ##: "},
        {" .##:::: ##: ##:::. ##:'####:::: ##:::: ##:::: ##: ##:::: ##: ########:::: ##::::'####:. ######:: "},
        {"                             :.::::::.:...::::::.::..:::::..::........::                          "},
        {"                             :'######::::::'###::::'##::::'##:'########:                          "},
        {"                             '##... ##::::'## ##::: ###::'###: ##.....::                          "},
        {"                             .##:::..::::'##:. ##:: ####'####: ##:::::::                          "},
        {"                             .##::'####:'##:::. ##: ## ### ##: ######:::                          "},
        {"                             .##::: ##:: #########: ##. #: ##: ##...::::                          "},
        {"                             .##::: ##:: ##.... ##: ##:.:: ##: ##:::::::                          "},
        {"                             ..######::: ##:::: ##: ##:::: ##: ########:                          "},
        {"                             :......::::..:::::..::..:::::..::........::                          "},
        {"                                                                                                  "},
        {"##################################################################################################"}
    };
    for (int x=0; x<21; x++) // for looop for printing the title screen
    {
        cout <<"\t";
        for (int y=0; y<98; y++)
        {
            cout <<game_title[x][y];
        }
        cout <<endl;
        system("COLOR 0A");
    }
    gotoxy(40,25);system("pause");
    system("cls");
}

int menu(){
    int num;
    system("cls");
    cout <<"Arithmetic Practice Game"<<endl;
    cout <<"=============MENU============="<<endl;
    cout <<"Press [1] for Addition"<<endl;
    cout <<"Press [2] for Subtraction"<<endl;
    cout <<"Press [3] for Division"<<endl;
    cout <<"Press [4] for Multiplication"<<endl;
    cout <<"Press [5] to Save and Exit"<<endl;
    cout <<"================================="<<endl;
    cout <<"What operation do you want to take? ";
    cin >> num;
    return num;
}

void MyClass::display(){
    system("cls");
    NODE *p;
    p=head;
    float ave;
    int i=1;
    cout <<"   Name   Quiz 1   Quiz 2   Quiz 3   Average   Remarks"<<endl;
    while (p!=NULL){
        ave = (p->q1 + p->q2 + p->q3)/3.0;
        cout <<i++<<".) "<<p->name<<"     "<<p->q1<<"     "<<p->q2<<"     "<<p->q3<<"     ";
        cout <<fixed<<setprecision(2)<<ave<<"     "<<(ave>=75?"PASSED\n":"FAILED\n"); //fixed setprecision(2) is to get 2 decimal numbers
        p=p->next;
      }
    system("pause");
}

void MyClass::save(){
    fstream fp;
    fp.open("BSCS-1CD.txt",ios::out);
    NODE *p;
    p=head;
    if(!fp){
        cout << "File Error"<<endl;
        system("pause");
    } else {
        while(p!=NULL){
            fp<<p->name<<endl<<p->q1<<" "<<p->q2<<" "<<p->q3<<endl;
            p=p->next;
        }
        fp.close();
    }
}

void MyClass::retrieve(){
    fstream fp;
    fp.open("BSCS-1CD.txt",ios::in);
    if (!fp){
        cout << "File error."<<endl;
        system("pause");
    } else {
         string NAME;
         int qq1,qq2,qq3;
         while(true){
            getline(fp,NAME);
            fp >> qq1 >> qq2 >> qq3;
            fp.ignore();
            if (!fp.eof()){
                add(NAME,qq1,qq2,qq3);
            }else{
                break;
            }
         }
    }
    fp.close();
}

int main(){
    MyClass obj;//Object
    srand(time(NULL));
    obj.init();
    obj.retrieve();
    obj.logIn();
    system("cls");
    TitleScreen();
    obj.leaderboard();
    while (true){
        switch(menu()){
        case 1: system("cls"); break;
        case 2: system("cls"); break;
        case 3: obj.display();break;
        case 4: obj.save();exit(0);
        default:cout <<"1 to 4 only."<<endl;system("pause");
        }
      }
    return 0;
}
