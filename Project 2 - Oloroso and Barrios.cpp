/*Project 2 in CPP
by Andrew R. Oloroso and Armand Angelo C. Barrios*/
#include <iostream>
#include <iomanip> //for setprecision
#include <fstream>
#include <windows.h>
#include <time.h>
#include <conio.h>
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
    NODE *head, *lead;
    int items=10,counter,level,start,operation;
    string marker;
    char c;
    void score();
    void saveScore(int n);
    void AllLead(); void AllLead2(); void AllLead3(); void AllLead4(); void AllLead5();
    void AddLead(); void AddLead2(); void AddLead3(); void AddLead4(); void AddLead5();
    void SubLead(); void SubLead2(); void SubLead3(); void SubLead4(); void SubLead5();
    void DivLead(); void DivLead2(); void DivLead3(); void DivLead4(); void DivLead5();
    void MulLead(); void MulLead2(); void MulLead3(); void MulLead4(); void MulLead5();
    void allSort(NODE *t,int x); void allDisplay(int x);
public:
    void init();
    void logIn();
    void AddPlayer(NODE player);
    void AddRec(NODE *pl);
    void leaderboard();
    void addition();
    void subtraction();
    void division();
    void multiplication();
    void save();
    void retrieve();
    void GetLevel();
};

void gotoxy(int x,int y){
    COORD coord = {0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void MyClass::init(){
    head=NULL;
    lead=NULL;
}

void box(){ //box display using ascii value in log in
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
void smallbox(){ //box display using ascii value in the problems
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

void MyClass::logIn(){
    NODE player, *p, *q;
    p=q=head;
    system("cls"); box();
    gotoxy(45,6);cout<<"Enter Username/UserID: ";getline(cin,player.name); //prompt the user's username/ID
    while(p!=NULL && player.name!=p->name){
        q=p;
        p=p->next;
    }if(p==NULL){
        system("cls");
        box();
        gotoxy(45,6);cout<<"A NEW CHALLENGER!"<<endl;
        gotoxy(45,7);cout<<"Enter Password: ";getline(cin,player.pass);
        AddPlayer(player);
        marker=player.name;
    }else{
        here:
        system("cls");
        box();
        gotoxy(45,6);cout<<"Welcome back "<<player.name<<"!"<<endl;
        gotoxy(45,7);cout<<"Enter Password: ";getline(cin,player.pass);
        if(player.pass!=p->pass){
            gotoxy(45,9);cout<<"Incorrect Password";
            gotoxy(45,11);system("pause");
            goto here;
        }else{
            gotoxy(45,9);cout<<"Log in was successful!";
            marker=p->name;
            gotoxy(45,11);system("pause");
        }
    }
}

void MyClass::AddPlayer(NODE player){
    player.plus1=0;player.minus1=0;player.divide1=0;player.multiply1=0;
    player.plus2=0;player.minus2=0;player.divide2=0;player.multiply2=0;
    player.plus3=0;player.minus3=0;player.divide3=0;player.multiply3=0;
    player.plus4=0;player.minus4=0;player.divide4=0;player.multiply4=0;
    player.plus5=0;player.minus5=0;player.divide5=0;player.multiply5=0;
    AddRec(&player);
    gotoxy(45,9);cout<<"Log in was successful!";
    gotoxy(45,11);system("pause");
}

void MyClass::AddRec(NODE *pl){
    NODE *p, *q, *newNode;
    p=q=head;
    newNode = new NODE;
    *newNode = *pl;
    while (p!=NULL){
        q = p;
        p = p->next;
    }
    if (p==head){
        head = newNode;
    }else{
        q->next = newNode;
    }newNode->next = p;
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
    gotoxy(45,3);cout <<"Arithmetic Practice Game";
    gotoxy(40,6);cout <<"=============MENU=============";
    gotoxy(42,8);cout <<"Press [1] for Addition";
    gotoxy(42,9);cout <<"Press [2] for Subtraction";
    gotoxy(42,10);cout <<"Press [3] for Division";
    gotoxy(42,11);cout <<"Press [4] for Multiplication";
    gotoxy(42,12);cout <<"Press [5] to Save and Exit";
    gotoxy(40,14);cout <<"=================================";
    gotoxy(40,16);cout <<"What operation do you want to take? "; cin >> num;
    return num;
}

void MyClass::addition(){
    int x,y,z,answer,ul=196;
    GetLevel(); // get the value of start and level
    do{ //do while loop if the player wants to try again
        counter = 0;
        for (x=0;x<items;x++){ //number of items
            system("cls");
            //generate random numbers from start - level
            y = rand() % level + start;
            z = rand() % level + start;
            score(); smallbox();
            for(int i=0;i<7;i++){ //displaying box
                gotoxy(38+i,7);cout<<(char)ul;
            }
            gotoxy(35,3);cout<<"Problem #" <<x+1;
            gotoxy(40,5);cout<<"  "<<y<<" ";
            gotoxy(40,6);cout<<"+ "<<z<<" ";
            gotoxy(41,8);cin>>answer;
            if(answer == y+z){
                gotoxy(33,12);cout<<"Correct!";
                counter++;score();
            }else{
                gotoxy(33,12);cout<<"Wrong. The correct answer is "<<y+z;
            }
            gotoxy(33,14);system("pause");
        }
        system("cls"); operation = 1; saveScore(operation);
        gotoxy(40,7);cout<<"Do you want to use this operation again? ";
        gotoxy(45,8);cout<<" [Y] if Yes. [N] if No.";
        c = getch();
    }while(c == 'y' || c == 'Y');
        if(c == 'n' || c == 'N'){
            gotoxy(40,10);cout<<"Do you want to go to menu?";
            gotoxy(40,11);cout<<" [Y] if Yes. [N] to Exit.";
            c = getch();
            if(c == 'n' || c == 'N'){
                leaderboard(); save(); exit(0);
            }
        }
}

void MyClass::subtraction(){
    int x,y,z,answer,temp,ul=196;
    GetLevel();
    do{ //do while loop if the player wants to try again
        counter = 0;
        for (x=0;x<items;x++){
            system("cls");
            //generate random numbers from start to level
            y = rand() % level + start;
            z = rand() % level + start;
            score(); smallbox();
            gotoxy(35,3);cout<<"Problem #" <<x+1;
            for(int i=0;i<7;i++){ //display the box
                gotoxy(38+i,7);cout<<(char)ul;
            }
            if (y>z){
                temp=y-z;
                gotoxy(40,5);cout<<"  "<<y<<" ";
                gotoxy(40,6);cout<<"- "<<z<<" ";
            }
            else { //to have no negative answer switch to z - y
                temp=z-y;
                gotoxy(40,5);cout<<"  "<<z<<" ";
                gotoxy(40,6);cout<<"- "<<y<<" ";
            }
            gotoxy(41,8);cin>>answer;
            if(answer == temp){
                gotoxy(33,12);cout<<"Correct!";
                counter++;score();
            }else{
                gotoxy(33,12);cout<<"Wrong. The correct answer is "<<temp;
            }
            gotoxy(33,14);system("pause");
        }
        system("cls");operation = 2;saveScore(operation);
        gotoxy(40,7);cout<<"Do you want to use this operation again? ";
        gotoxy(45,8);cout<<" [Y] if Yes. [N] if No.";
        c = getch();
    }while(c == 'y' || c == 'Y');
        if(c == 'n' || c == 'N'){
            gotoxy(40,10);cout<<"Do you want to go to menu?";
            gotoxy(40,11);cout<<" [Y] if Yes. [N] to Exit.";
            c = getch();
            if(c == 'n' || c == 'N'){
                leaderboard();save();exit(0);
            }
        }
}

void MyClass::division(){
    int x,y,z,answer,temp,ul=196,s=246;
    GetLevel();
    do{ //do while loop if the player wants to try again
        counter = 0;
        for (x=0;x<items;x++){
            system("cls");
            //generate random numbers from start to level
            y = rand() % level + start;
            z = rand() % level + start;
            score();smallbox();
            gotoxy(35,3);cout<<"Problem #" <<x+1;
            for(int i=0;i<7;i++){
                gotoxy(38+i,7);cout<<(char)ul;
            }
            temp = y*z; //to have divisible numbers
            y = temp;
            gotoxy(40,5);cout<<"  "<<y;
            gotoxy(40,6);cout<<(char)s<<" "<<z;
            gotoxy(41,8);cin>>answer;
            if(answer == y/z){
                gotoxy(33,12);cout<<"Correct!";
                counter++;score();
            }else{
                gotoxy(33,12);cout<<"Wrong. The correct answer is "<<y/z;
            }
            gotoxy(33,14);system("pause");
        }
        system("cls");operation = 3;saveScore(operation);
        gotoxy(40,7);cout<<"Do you want to use this operation again? ";
        gotoxy(45,8);cout<<" [Y] if Yes. [N] if No.";
        c = getch();
    }while(c == 'y' || c == 'Y');
        if(c == 'n' || c == 'N'){
            gotoxy(40,10);cout<<"Do you want to go to menu?";
            gotoxy(40,11);cout<<" [Y] if Yes. [N] to Exit.";
            c = getch();
            if(c == 'n' || c == 'N'){
                leaderboard();save();exit(0);
            }
        }
}

void MyClass::multiplication(){
    int x,y,z,answer,ul=196;
    GetLevel();
    do{ //do while loop if the player wants to try again
        counter = 0;
        for (x=0;x<items;x++){
            system("cls");
            //generate random numbers from start to level
            y = rand() % level + start;
            z = rand() % level + start;
            score();smallbox();
            gotoxy(35,3);cout<<"Problem #" <<x+1;
            for(int i=0;i<7;i++){
                gotoxy(38+i,7);cout<<(char)ul;
            }
            gotoxy(40,5);cout<<"  "<<y<<" ";
            gotoxy(40,6);cout<<"x "<<z<<" ";
            gotoxy(41,8);cin>>answer;
            if(answer == y*z){
                gotoxy(33,12);cout<<"Correct!";
                counter++;score();
            }else{
                gotoxy(33,12);cout<<"Wrong. The correct answer is "<<y*z;
            }
            gotoxy(33,14);system("pause");
        }
        system("cls");operation = 4;saveScore(operation);
        gotoxy(40,7);cout<<"Do you want to use this operation again? ";
        gotoxy(45,8);cout<<" [Y] if Yes. [N] if No.";
        c = getch();
    }while(c == 'y' || c == 'Y');
        if(c == 'n' || c == 'N'){
            gotoxy(40,10);cout<<"Do you want to go to menu?";
            gotoxy(40,11);cout<<" [Y] if Yes. [N] to Exit.";
            c = getch();
            if(c == 'n' || c == 'N'){
                leaderboard();save();exit(0);
            }
        }
}

void MyClass::score(){ //display updated score
    gotoxy(90,2);cout<<"Score: "<<counter<<"/"<<items<<":"<<fixed<<setprecision(2)<<(float)counter/items*100<<"%";
}

void MyClass::GetLevel(){ //assign the value of start and level according to chosen difficulty
    int l;
    system("cls");
    gotoxy(40,5);cout<<"Select level";
    gotoxy(40,6);cout<<"Level 1: Very Easy";
    gotoxy(40,7);cout<<"Level 2: Easy";
    gotoxy(40,8);cout<<"Level 3: Medium";
    gotoxy(40,9);cout<<"Level 4: Hard";
    gotoxy(40,10);cout<<"Level 5: Very Hard";
    gotoxy(40,13);cout<<"Choose level: ";
    gotoxy(55,13);cin>>l;
    switch (l){
        case 1: level = 10; start = 1; break;
        case 2: level = 20; start = 10; break;
        case 3: level = 50; start = 20; break;
        case 4: level = 80; start = 50; break;
        case 5: level = 100; start = 80; break;
        default: printf("1-5 only"); break;
    }
}

void MyClass::saveScore(int n){
    NODE *p, *q;
    p=q=head;
    while(marker!=p->name){
        q=p;
        p=p->next;
    }
    switch(n){
        case 1: if(level == 10){ //will store the score acording to the level
                    p->plus1 = counter;
                }else if(level == 20){
                    p->plus2 = counter;
                }else if(level == 50){
                    p->plus3 = counter;
                }else if(level == 80){
                    p->plus4 = counter;
                }else if(level == 100){
                    p->plus5 = counter;
                }break;
        case 2: if(level == 10){ //will store the score acording to the level
                    p->minus1 = counter;
                }else if(level == 20){
                    p->minus2 = counter;
                }else if(level == 50){
                    p->minus3 = counter;
                }else if(level == 80){
                    p->minus4 = counter;
                }else if(level == 100){
                    p->minus5 = counter;
                }break;
        case 3: if(level == 10){ //will store the score acording to the level
                    p->divide1 = counter;
                }else if(level == 20){
                    p->divide2 = counter;
                }else if(level == 50){
                    p->divide3 = counter;
                }else if(level == 80){
                    p->divide4 = counter;
                }else if(level == 100){
                    p->divide5 = counter;
                }break;
        case 4: if(level == 10){ //will store the score acording to the level
                    p->multiply1 = counter;
                }else if(level == 20){
                    p->multiply2 = counter;
                }else if(level == 50){
                    p->multiply3 = counter;
                }else if(level == 80){
                    p->multiply4 = counter;
                }else if(level == 100){
                    p->multiply5 = counter;
                }break;
    }
}

void MyClass::save(){ //will save the data from array structure to the txt file
    fstream fp;
    fp.open("BSCS-1CD-Leaderboard.txt",ios::out);
    NODE *p;
    p=head;
    if(!fp){
        cout << "File Error"<<endl;
        system("pause");
    }
    else {
        while(p!=NULL){
            fp<<p->name<<endl<<p->pass<<endl
              <<p->plus1<<" "<<p->minus1<<" "<<p->divide1<<" "<<p->multiply1<<"\t"
              <<p->plus2<<" "<<p->minus2<<" "<<p->divide2<<" "<<p->multiply2<<"\t"
              <<p->plus3<<" "<<p->minus3<<" "<<p->divide3<<" "<<p->multiply3<<"\t"
              <<p->plus4<<" "<<p->minus4<<" "<<p->divide4<<" "<<p->multiply4<<"\t"
              <<p->plus5<<" "<<p->minus5<<" "<<p->divide5<<" "<<p->multiply5<<endl;
            p=p->next;
        }
        fp.close();
    }
}

void MyClass::retrieve(){ //will scan the txt file
    fstream fp;
    fp.open("BSCS-1CD-Leaderboard.txt",ios::in);
    //SREC players;
    NODE players;
    if (!fp){
        system("cls");
        gotoxy(40,5);cout<<"Error 404.";
        gotoxy(40,6);cout<<"BSCS-1CD-Leaderboard.txt was not found.";
        gotoxy(40,10);system("pause");
    }
    else {
        while(true){
            getline(fp,players.name); getline(fp,players.pass);
            fp>>players.plus1>>players.minus1>>players.divide1>>players.multiply1
              >>players.plus2>>players.minus2>>players.divide2>>players.multiply2
              >>players.plus3>>players.minus3>>players.divide3>>players.multiply3
              >>players.plus4>>players.minus4>>players.divide4>>players.multiply4
              >>players.plus5>>players.minus5>>players.divide5>>players.multiply5;
            fp.ignore();
            if (!fp.eof()){
                AddRec(&players);
            }else{
                break;
            }
        }
        fp.close();
   }
}

void MyClass::leaderboard(){
    system("cls");
    NODE *p;
    p=head;
    while(p!=NULL){
        float ave1 = (p->plus1 + p->minus1 + p->divide1 + p->multiply1) / 4.0;
        p->ave2 = (p->plus2 + p->minus2 + p->divide2 + p->multiply2) / 4.0;
        p->ave3 = (p->plus3 + p->minus3 + p->divide3 + p->multiply3) / 4.0;
        p->ave4 = (p->plus4 + p->minus4 + p->divide4 + p->multiply4) / 4.0;
        p->ave5 = (p->plus5 + p->minus5 + p->divide5 + p->multiply5) / 4.0;
        p=p->next;
    }
    gotoxy(44,5);cout<<"LEADERBOARDS";
    gotoxy(34,6);cout<<"Score at least 1 point to qualify";
    gotoxy(47,7);cout<<"Level 1";
    AddLead(); SubLead(); DivLead(); MulLead();
    cout<<endl<<endl<<"\t\t\t\t\t";system("pause");
    system("cls");
    gotoxy(44,5);cout<<"LEADERBOARDS";
    gotoxy(34,6);cout<<"Score at least 1 point to qualify";
    gotoxy(47,7);cout<<"Level 2";
    AddLead2(); SubLead2(); DivLead2(); MulLead2();
    cout<<endl<<endl<<"\t\t\t\t\t";system("pause");
    system("cls");
    gotoxy(44,5);cout<<"LEADERBOARDS";
    gotoxy(34,6);cout<<"Score at least 1 point to qualify";
    gotoxy(47,7);cout<<"Level 3";
    AddLead3(); SubLead3(); DivLead3(); MulLead3();
    cout<<endl<<endl<<"\t\t\t\t\t";system("pause");
    system("cls");
    gotoxy(44,5);cout<<"LEADERBOARDS";
    gotoxy(34,6);cout<<"Score at least 1 point to qualify";
    gotoxy(47,7);cout<<"Level 4";
    AddLead4(); SubLead4(); DivLead4(); MulLead4();
    cout<<endl<<endl<<"\t\t\t\t\t";system("pause");
    system("cls");
    gotoxy(44,5);cout<<"LEADERBOARDS";
    gotoxy(34,6);cout<<"Score at least 1 point to qualify";
    gotoxy(47,7);cout<<"Level 5";
    AddLead5(); SubLead5(); DivLead5(); MulLead5();
    cout<<endl<<endl<<"\t\t\t\t\t";system("pause");
    system("cls");
    gotoxy(44,5);cout<<"LEADERBOARDS";
    gotoxy(34,6);cout<<"Score at least 1 point to qualify";
    AllLead(); AllLead2(); AllLead3(); AllLead4(); AllLead5();
    cout<<endl<<endl<<"\t\t\t\t\t";system("pause");
    system("cls");
}
void MyClass::allSort(NODE *t,int x){
    NODE *p, *q, *newNode;
    p=q=lead;
    newNode = new NODE;
    *newNode = *t;
    switch(x){
        case 1: while (p!=NULL && t->plus1 < p->plus1){
                    q = p;
                    p = p->next;
                }if (p==lead){
                    lead = newNode;
                }else{
                    q->next = newNode;
                }newNode->next=p;break;
        case 2: while (p!=NULL && t->minus1 < p->minus1){
                    q = p;
                    p = p->next;
                }if (p==lead){
                    lead = newNode;
                }else{
                    q->next = newNode;
                }newNode->next=p;break;
        case 3: while (p!=NULL && t->divide1 < p->divide1){
                    q = p;
                    p = p->next;
                }if (p==lead){
                    lead = newNode;
                }else{
                    q->next = newNode;
                }newNode->next=p;break;
        case 4: while (p!=NULL && t->multiply1 < p->multiply1){
                    q = p;
                    p = p->next;
                }if (p==lead){
                    lead = newNode;
                }else{
                    q->next = newNode;
                }newNode->next=p;break;
        case 5: while (p!=NULL && t->plus2 < p->plus2){
                    q = p;
                    p = p->next;
                }if (p==lead){
                    lead = newNode;
                }else{
                    q->next = newNode;
                }newNode->next=p;break;
        case 6: while (p!=NULL && t->minus2 < p->minus2){
                    q = p;
                    p = p->next;
                }if (p==lead){
                    lead = newNode;
                }else{
                    q->next = newNode;
                }newNode->next=p;break;
        case 7: while (p!=NULL && t->divide2 < p->divide2){
                    q = p;
                    p = p->next;
                }if (p==lead){
                    lead = newNode;
                }else{
                    q->next = newNode;
                }newNode->next=p;break;
        case 8: while (p!=NULL && t->multiply2 < p->multiply2){
                    q = p;
                    p = p->next;
                }if (p==lead){
                    lead = newNode;
                }else{
                    q->next = newNode;
                }newNode->next=p;break;
        case 9: while (p!=NULL && t->plus3 < p->plus3){
                    q = p;
                    p = p->next;
                }if (p==lead){
                    lead = newNode;
                }else{
                    q->next = newNode;
                }newNode->next=p;break;
        case 10: while (p!=NULL && t->minus3 < p->minus3){
                    q = p;
                    p = p->next;
                }if (p==lead){
                    lead = newNode;
                }else{
                    q->next = newNode;
                }newNode->next=p;break;
        case 11: while (p!=NULL && t->divide3 < p->divide3){
                    q = p;
                    p = p->next;
                }if (p==lead){
                    lead = newNode;
                }else{
                    q->next = newNode;
                }newNode->next=p;break;
        case 12: while (p!=NULL && t->multiply3 < p->multiply3){
                    q = p;
                    p = p->next;
                }if (p==lead){
                    lead = newNode;
                }else{
                    q->next = newNode;
                }newNode->next=p;break;
        case 13: while (p!=NULL && t->plus4 < p->plus4){
                    q = p;
                    p = p->next;
                }if (p==lead){
                    lead = newNode;
                }else{
                    q->next = newNode;
                }newNode->next=p;break;
        case 14: while (p!=NULL && t->minus4 < p->minus4){
                    q = p;
                    p = p->next;
                }if (p==lead){
                    lead = newNode;
                }else{
                    q->next = newNode;
                }newNode->next=p;break;
        case 15: while (p!=NULL && t->divide4 < p->divide4){
                    q = p;
                    p = p->next;
                }if (p==lead){
                    lead = newNode;
                }else{
                    q->next = newNode;
                }newNode->next=p;break;
        case 16: while (p!=NULL && t->multiply4 < p->multiply4){
                    q = p;
                    p = p->next;
                }if (p==lead){
                    lead = newNode;
                }else{
                    q->next = newNode;
                }newNode->next=p;break;
        case 17:while (p!=NULL && t->plus5 < p->plus5){
                    q = p;
                    p = p->next;
                }if (p==lead){
                    lead = newNode;
                }else{
                    q->next = newNode;
                }newNode->next=p;break;
        case 18:while (p!=NULL && t->minus5 < p->minus5){
                    q = p;
                    p = p->next;
                }if (p==lead){
                    lead = newNode;
                }else{
                    q->next = newNode;
                }newNode->next=p;break;
        case 19:while (p!=NULL && t->divide5 < p->divide5){
                    q = p;
                    p = p->next;
                }if (p==lead){
                    lead = newNode;
                }else{
                    q->next = newNode;
                }newNode->next=p;break;
        case 20:while (p!=NULL && t->multiply5 < p->multiply5){
                    q = p;
                    p = p->next;
                }if (p==lead){
                    lead = newNode;
                }else{
                    q->next = newNode;
                }newNode->next=p;break;
        case 21:while (p!=NULL && t->ave1 < p->ave1){
                    q = p;
                    p = p->next;
                }if (p==lead){
                    lead = newNode;
                }else{
                    q->next = newNode;
                }newNode->next=p;break;
        case 22:while (p!=NULL && t->ave2 < p->ave2){
                    q = p;
                    p = p->next;
                }if (p==lead){
                    lead = newNode;
                }else{
                    q->next = newNode;
                }newNode->next=p;break;
        case 23:while (p!=NULL && t->ave3 < p->ave3){
                    q = p;
                    p = p->next;
                }if (p==lead){
                    lead = newNode;
                }else{
                    q->next = newNode;
                }newNode->next=p;break;
        case 24:while (p!=NULL && t->ave4 < p->ave4){
                    q = p;
                    p = p->next;
                }if (p==lead){
                    lead = newNode;
                }else{
                    q->next = newNode;
                }newNode->next=p;break;
        case 25:while (p!=NULL && t->ave5 < p->ave5){
                    q = p;
                    p = p->next;
                }if (p==lead){
                    lead = newNode;
                }else{
                    q->next = newNode;
                }newNode->next=p;break;
    }
}
void MyClass::allDisplay(int x){
    int z=0;
    //will print "---" if new player and display score if old player
    switch(x){
        case 1: while(lead!=NULL){
                    if(lead->plus1==0){
                        gotoxy(19,9);cout<<"  PLAYER\t  SCORE(%)";
                        gotoxy(17,10+z);cout<<z+1<<".  "<<lead->name;
                        gotoxy(25,10+z);cout<<"\t  ---";
                    }else{
                    float p1 = (lead->plus1/(float)items)*100;
                    gotoxy(19,9);cout<<"  PLAYER\t  SCORE(%)";
                    gotoxy(17,10+z);cout<<z+1<<".  "<<lead->name;
                    gotoxy(25,10+z);cout<<"\t"<<lead->plus1<<" ("<<fixed<<setprecision(2)<<p1<<"%)"<<endl;
                    }z++;lead=lead->next;
                }break;
        case 2:while(lead!=NULL){
                    if(lead->minus1==0){
                        gotoxy(59,9);cout<<"  PLAYER\t  SCORE(%)";
                        gotoxy(57,10+z);cout<<z+1<<".  "<<lead->name;
                        gotoxy(65,10+z);cout<<"\t  ---";
                    }else{
                    gotoxy(59,9);cout<<"  PLAYER\t  SCORE(%)";
                    gotoxy(57,10+z);cout<<z+1<<".  "<<lead->name;
                    gotoxy(65,10+z);cout<<"\t"<<lead->minus1<<" ("<<fixed<<setprecision(2)<<(float)lead->minus1/items*100<<"%)"<<endl;
                    }
                    z++;lead=lead->next;
                }break;
        case 3:while(lead!=NULL){
                    if(lead->divide1==0){
                        gotoxy(59,20);cout<<"  PLAYER\t  SCORE(%)";
                        gotoxy(57,21+z);cout<<z+1<<".  "<<lead->name;
                        gotoxy(65,21+z);cout<<"\t  ---";
                    }else{
                    gotoxy(59,20);cout<<"  PLAYER\t  SCORE(%)";
                    gotoxy(57,21+z);cout<<z+1<<".  "<<lead->name;
                    gotoxy(65,21+z);cout<<"\t"<<lead->divide1<<" ("<<fixed<<setprecision(2)<<(float)lead->divide1/items*100<<"%)"<<endl;
                    }
                    z++;lead=lead->next;
                }break;
        case 4:while(lead!=NULL){
                    if(lead->multiply1==0){
                        gotoxy(19,20);cout<<"  PLAYER\t  SCORE(%)";
                        gotoxy(17,21+z);cout<<z+1<<".  "<<lead->name;
                        gotoxy(25,21+z);cout<<"\t  ---";
                    }else{
                    gotoxy(19,20);cout<<"  PLAYER\t  SCORE(%)";
                    gotoxy(17,21+z);cout<<z+1<<".  "<<lead->name;
                    gotoxy(25,21+z);cout<<"\t"<<lead->multiply1<<" ("<<fixed<<setprecision(2)<<(float)lead->multiply1/items*100<<"%)"<<endl;
                    }
                    z++;lead=lead->next;
                }break;
        case 5:while(lead!=NULL){
                    if(lead->plus2==0){
                        gotoxy(19,9);cout<<"  PLAYER\t  SCORE(%)";
                        gotoxy(17,10+z);cout<<z+1<<".  "<<lead->name;
                        gotoxy(25,10+z);cout<<"\t  ---";
                    }else{
                    float p1 = (lead->plus2/(float)items)*100;
                    gotoxy(19,9);cout<<"  PLAYER\t  SCORE(%)";
                    gotoxy(17,10+z);cout<<z+1<<".  "<<lead->name;
                    gotoxy(25,10+z);cout<<"\t"<<lead->plus2<<" ("<<fixed<<setprecision(2)<<p1<<"%)"<<endl;
                    }z++;lead=lead->next;
                }break;
        case 6:while(lead!=NULL){
                    if(lead->minus2==0){
                        gotoxy(59,9);cout<<"  PLAYER\t  SCORE(%)";
                        gotoxy(57,10+z);cout<<z+1<<".  "<<lead->name;
                        gotoxy(65,10+z);cout<<"\t  ---";
                    }else{
                    float p1 = (lead->minus2/(float)items)*100;
                    gotoxy(59,9);cout<<"  PLAYER\t  SCORE(%)";
                    gotoxy(57,10+z);cout<<z+1<<".  "<<lead->name;
                    gotoxy(65,10+z);cout<<"\t"<<lead->minus2<<" ("<<fixed<<setprecision(2)<<p1<<"%)"<<endl;
                    }z++;lead=lead->next;
                }break;
        case 7:while(lead!=NULL){
                    if(lead->divide2==0){
                        gotoxy(59,20);cout<<"  PLAYER\t  SCORE(%)";
                        gotoxy(57,21+z);cout<<z+1<<".  "<<lead->name;
                        gotoxy(65,21+z);cout<<"\t  ---";
                    }else{
                    float p1 = (lead->divide2/(float)items)*100;
                    gotoxy(59,20);cout<<"  PLAYER\t  SCORE(%)";
                    gotoxy(57,21+z);cout<<z+1<<".  "<<lead->name;
                    gotoxy(65,21+z);cout<<"\t"<<lead->divide2<<" ("<<fixed<<setprecision(2)<<p1<<"%)"<<endl;
                    }z++;lead=lead->next;
                }break;
        case 8:while(lead!=NULL){
                    if(lead->multiply2==0){
                        gotoxy(19,20);cout<<"  PLAYER\t  SCORE(%)";
                        gotoxy(17,21+z);cout<<z+1<<".  "<<lead->name;
                        gotoxy(25,21+z);cout<<"\t  ---";
                    }else{
                    float p1 = (lead->multiply2/(float)items)*100;
                    gotoxy(19,20);cout<<"  PLAYER\t  SCORE(%)";
                    gotoxy(17,21+z);cout<<z+1<<".  "<<lead->name;
                    gotoxy(25,21+z);cout<<"\t"<<lead->multiply2<<" ("<<fixed<<setprecision(2)<<p1<<"%)"<<endl;
                    }z++;lead=lead->next;
                }break;
        case 9:while(lead!=NULL){
                    if(lead->plus3==0){
                        gotoxy(19,9);cout<<"  PLAYER\t  SCORE(%)";
                        gotoxy(17,10+z);cout<<z+1<<".  "<<lead->name;
                        gotoxy(25,10+z);cout<<"\t  ---";
                    }else{
                    float p1 = (lead->plus3/(float)items)*100;
                    gotoxy(19,9);cout<<"  PLAYER\t  SCORE(%)";
                    gotoxy(17,10+z);cout<<z+1<<".  "<<lead->name;
                    gotoxy(25,10+z);cout<<"\t"<<lead->plus3<<" ("<<fixed<<setprecision(2)<<p1<<"%)"<<endl;
                    }z++;lead=lead->next;
                }break;
        case 10:while(lead!=NULL){
                    if(lead->minus3==0){
                        gotoxy(59,9);cout<<"  PLAYER\t  SCORE(%)";
                        gotoxy(57,10+z);cout<<z+1<<".  "<<lead->name;
                        gotoxy(65,10+z);cout<<"\t  ---";
                    }else{
                    float p1 = (lead->minus3/(float)items)*100;
                    gotoxy(59,9);cout<<"  PLAYER\t  SCORE(%)";
                    gotoxy(57,10+z);cout<<z+1<<".  "<<lead->name;
                    gotoxy(65,10+z);cout<<"\t"<<lead->minus3<<" ("<<fixed<<setprecision(2)<<p1<<"%)"<<endl;
                    }z++;lead=lead->next;
                }break;
        case 11:while(lead!=NULL){
                    if(lead->divide3==0){
                        gotoxy(59,20);cout<<"  PLAYER\t  SCORE(%)";
                        gotoxy(57,21+z);cout<<z+1<<".  "<<lead->name;
                        gotoxy(65,21+z);cout<<"\t  ---";
                    }else{
                    float p1 = (lead->divide3/(float)items)*100;
                    gotoxy(59,20);cout<<"  PLAYER\t  SCORE(%)";
                    gotoxy(57,21+z);cout<<z+1<<".  "<<lead->name;
                    gotoxy(65,21+z);cout<<"\t"<<lead->divide3<<" ("<<fixed<<setprecision(2)<<p1<<"%)"<<endl;
                    }z++;lead=lead->next;
                }break;
        case 12:while(lead!=NULL){
                    if(lead->multiply3==0){
                        gotoxy(19,20);cout<<"  PLAYER\t  SCORE(%)";
                        gotoxy(17,21+z);cout<<z+1<<".  "<<lead->name;
                        gotoxy(25,21+z);cout<<"\t  ---";
                    }else{
                    float p1 = (lead->multiply3/(float)items)*100;
                    gotoxy(19,20);cout<<"  PLAYER\t  SCORE(%)";
                    gotoxy(17,21+z);cout<<z+1<<".  "<<lead->name;
                    gotoxy(25,21+z);cout<<"\t"<<lead->multiply3<<" ("<<fixed<<setprecision(2)<<p1<<"%)"<<endl;
                    }z++;lead=lead->next;
                }break;
        case 13:while(lead!=NULL){
                    if(lead->plus4==0){
                        gotoxy(19,9);cout<<"  PLAYER\t  SCORE(%)";
                        gotoxy(17,10+z);cout<<z+1<<".  "<<lead->name;
                        gotoxy(25,10+z);cout<<"\t  ---";
                    }else{
                    float p1 = (lead->plus4/(float)items)*100;
                    gotoxy(19,9);cout<<"  PLAYER\t  SCORE(%)";
                    gotoxy(17,10+z);cout<<z+1<<".  "<<lead->name;
                    gotoxy(25,10+z);cout<<"\t"<<lead->plus4<<" ("<<fixed<<setprecision(2)<<p1<<"%)"<<endl;
                    }z++;lead=lead->next;
                }break;
        case 14:while(lead!=NULL){
                    if(lead->minus4==0){
                        gotoxy(59,9);cout<<"  PLAYER\t  SCORE(%)";
                        gotoxy(57,10+z);cout<<z+1<<".  "<<lead->name;
                        gotoxy(65,10+z);cout<<"\t  ---";
                    }else{
                    float p1 = (lead->minus4/(float)items)*100;
                    gotoxy(19,9);cout<<"  PLAYER\t  SCORE(%)";
                    gotoxy(17,10+z);cout<<z+1<<".  "<<lead->name;
                    gotoxy(25,10+z);cout<<"\t"<<lead->minus4<<" ("<<fixed<<setprecision(2)<<p1<<"%)"<<endl;
                    }z++;lead=lead->next;
                }break;
        case 15:while(lead!=NULL){
                    if(lead->divide4==0){
                        gotoxy(59,20);cout<<"  PLAYER\t  SCORE(%)";
                        gotoxy(57,21+z);cout<<z+1<<".  "<<lead->name;
                        gotoxy(65,21+z);cout<<"\t  ---";
                    }else{
                    float p1 = (lead->divide4/(float)items)*100;
                    gotoxy(59,20);cout<<"  PLAYER\t  SCORE(%)";
                    gotoxy(57,21+z);cout<<z+1<<".  "<<lead->name;
                    gotoxy(65,21+z);cout<<"\t"<<lead->divide4<<" ("<<fixed<<setprecision(2)<<p1<<"%)"<<endl;
                    }z++;lead=lead->next;
                }break;
        case 16:while(lead!=NULL){
                    if(lead->multiply4==0){
                        gotoxy(19,20);cout<<"  PLAYER\t  SCORE(%)";
                        gotoxy(17,21+z);cout<<z+1<<".  "<<lead->name;
                        gotoxy(25,21+z);cout<<"\t  ---";
                    }else{
                    float p1 = (lead->multiply4/(float)items)*100;
                    gotoxy(19,20);cout<<"  PLAYER\t  SCORE(%)";
                    gotoxy(17,21+z);cout<<z+1<<".  "<<lead->name;
                    gotoxy(25,21+z);cout<<"\t"<<lead->multiply4<<" ("<<fixed<<setprecision(2)<<p1<<"%)"<<endl;
                    }z++;lead=lead->next;
                }break;
        case 17:while(lead!=NULL){
                    if(lead->plus5==0){
                        gotoxy(19,9);cout<<"  PLAYER\t  SCORE(%)";
                        gotoxy(17,10+z);cout<<z+1<<".  "<<lead->name;
                        gotoxy(25,10+z);cout<<"\t  ---";
                    }else{
                    float p1 = (lead->plus5/(float)items)*100;
                    gotoxy(19,9);cout<<"  PLAYER\t  SCORE(%)";
                    gotoxy(17,10+z);cout<<z+1<<".  "<<lead->name;
                    gotoxy(25,10+z);cout<<"\t"<<lead->plus5<<" ("<<fixed<<setprecision(2)<<p1<<"%)"<<endl;
                    }z++;lead=lead->next;
                }break;
        case 18:while(lead!=NULL){
                    if(lead->minus5==0){
                        gotoxy(59,9);cout<<"  PLAYER\t  SCORE(%)";
                        gotoxy(57,10+z);cout<<z+1<<".  "<<lead->name;
                        gotoxy(65,10+z);cout<<"\t  ---";
                    }else{
                    float p1 = (lead->minus5/(float)items)*100;
                    gotoxy(59,9);cout<<"  PLAYER\t  SCORE(%)";
                    gotoxy(57,10+z);cout<<z+1<<".  "<<lead->name;
                    gotoxy(65,10+z);cout<<"\t"<<lead->minus5<<" ("<<fixed<<setprecision(2)<<p1<<"%)"<<endl;
                    }z++;lead=lead->next;
                }break;
        case 19:while(lead!=NULL){
                    if(lead->divide5==0){
                        gotoxy(59,20);cout<<"  PLAYER\t  SCORE(%)";
                        gotoxy(57,21+z);cout<<z+1<<".  "<<lead->name;
                        gotoxy(65,21+z);cout<<"\t  ---";
                    }else{
                    float p1 = (lead->divide5/(float)items)*100;
                    gotoxy(59,20);cout<<"  PLAYER\t  SCORE(%)";
                    gotoxy(57,21+z);cout<<z+1<<".  "<<lead->name;
                    gotoxy(65,21+z);cout<<"\t"<<lead->divide5<<" ("<<fixed<<setprecision(2)<<p1<<"%)"<<endl;
                    }z++;lead=lead->next;
                }break;
        case 20:while(lead!=NULL){
                    if(lead->multiply5==0){
                        gotoxy(19,20);cout<<"  PLAYER\t  SCORE(%)";
                        gotoxy(17,21+z);cout<<z+1<<".  "<<lead->name;
                        gotoxy(25,21+z);cout<<"\t  ---";
                    }else{
                    float p1 = (lead->multiply5/(float)items)*100;
                    gotoxy(19,20);cout<<"  PLAYER\t  SCORE(%)";
                    gotoxy(17,21+z);cout<<z+1<<".  "<<lead->name;
                    gotoxy(25,21+z);cout<<"\t"<<lead->multiply5<<" ("<<fixed<<setprecision(2)<<p1<<"%)"<<endl;
                    }z++;lead=lead->next;
                }break;
        case 21:while(lead!=NULL){
                    if(lead->plus1==0||lead->minus1==0||lead->multiply1==0||lead->divide1==0){
                        gotoxy(19,9);cout<<"  PLAYER\t  AVERAGE SCORE(%)";
                        gotoxy(17,10+z);cout<<z+1<<".  "<<lead->name;
                        gotoxy(25,10+z);cout<<"\t  DATA UNAVAILABLE";
                    }else{
                    gotoxy(19,9);cout<<"  PLAYER\t  AVERAGE SCORE(%)";
                    gotoxy(17,10+z);cout<<z+1<<".  "<<lead->name<<"\t      "<<fixed<<setprecision(2)<<lead->ave1<<endl;
                    }z++;lead=lead->next;
                }break;
        case 22:while(lead!=NULL){
                    if(lead->plus2==0||lead->minus2==0||lead->multiply2==0||lead->divide2==0){
                        gotoxy(59,9);cout<<"  PLAYER\t  AVERAGE SCORE(%)";
                        gotoxy(57,10+z);cout<<z+1<<".  "<<lead->name;
                        gotoxy(65,10+z);cout<<"\t  DATA UNAVAILABLE";
                    }else{
                    gotoxy(59,9);cout<<"  PLAYER\t  AVERAGE SCORE(%)";
                    gotoxy(57,10+z);cout<<z+1<<".  "<<lead->name<<"\t      "<<fixed<<setprecision(2)<<lead->ave2<<endl;
                    }z++;lead=lead->next;
                }break;
        case 23:while(lead!=NULL){
                    if(lead->plus3==0||lead->minus3==0||lead->multiply3==0||lead->divide3==0){
                        gotoxy(19,20);cout<<"  PLAYER\t  AVERAGE SCORE(%)";
                        gotoxy(17,21+z);cout<<z+1<<".  "<<lead->name;
                        gotoxy(25,21+z);cout<<"\t  DATA UNAVAILABLE";
                    }else{
                    gotoxy(19,20);cout<<"  PLAYER\t  AVERAGE SCORE(%)";
                    gotoxy(17,21+z);cout<<z+1<<".  "<<lead->name<<"\t      "<<fixed<<setprecision(2)<<lead->ave3<<endl;
                    }z++;lead=lead->next;
                }break;
        case 24:while(lead!=NULL){
                    if(lead->plus4==0||lead->minus4==0||lead->multiply4==0||lead->divide4==0){
                        gotoxy(59,20);cout<<"  PLAYER\t  AVERAGE SCORE(%)";
                        gotoxy(57,21+z);cout<<z+1<<".  "<<lead->name;
                        gotoxy(65,21+z);cout<<"\t  DATA UNAVAILABLE";
                    }else{
                    gotoxy(59,20);cout<<"  PLAYER\t  AVERAGE SCORE(%)";
                    gotoxy(57,21+z);cout<<z+1<<".  "<<lead->name<<"\t      "<<fixed<<setprecision(2)<<lead->ave4<<endl;
                    }z++;lead=lead->next;
                }break;
        case 25:while(lead!=NULL){
                    if(lead->plus5==0||lead->minus5==0||lead->multiply5==0||lead->divide5==0){
                        gotoxy(44,32);cout<<"  PLAYER\t  AVERAGE SCORE(%)";
                        gotoxy(42,33+z);cout<<z+1<<".  "<<lead->name;
                        gotoxy(52,33+z);cout<<"\t  DATA UNAVAILABLE";
                    }else{
                    gotoxy(44,32);cout<<"  PLAYER\t  AVERAGE SCORE(%)";
                    gotoxy(42,33+z);cout<<z+1<<".  "<<lead->name<<"\t      "<<fixed<<setprecision(2)<<lead->ave5<<endl;
                    }z++;lead=lead->next;
                }break;
    }
}
void MyClass::AddLead(){
    NODE *temp;
    temp = head;
    gotoxy(26,8);cout<<"Addition";
    //checking every single player and sort in descending order according to the addition score
    while(temp!=NULL){
        allSort(temp,1);
        temp=temp->next;
    }
    allDisplay(1);
}
void MyClass::SubLead(){
    NODE *temp;
    temp = head;
    gotoxy(66,8);cout<<"Subtraction";
    //checking every single player and sort in descending order according to the addition score
    while(temp!=NULL){
        allSort(temp,2);
        temp=temp->next;
    }
    allDisplay(2);
}
void MyClass::DivLead(){
    NODE *temp;
    temp = head;
    gotoxy(66,19);cout<<"Division";
    //checking every single player and sort in descending order according to the addition score
    while(temp!=NULL){
        allSort(temp,3);
        temp=temp->next;
    }
    allDisplay(3);
}
void MyClass::MulLead(){
    NODE *temp;
    temp = head;
    gotoxy(23,19);cout<<"Multiplication";
    //checking every single player and sort in descending order according to the addition score
    while(temp!=NULL){
        allSort(temp,4);
        temp=temp->next;
    }
    allDisplay(4);
}
void MyClass::AddLead2(){
    NODE *temp;
    temp = head;
    gotoxy(26,8);cout<<"Addition";
    //checking every single player and sort in descending order according to the addition score
    while(temp!=NULL){
        allSort(temp,5);
        temp=temp->next;
    }
    allDisplay(5);
}
void MyClass::SubLead2(){
    NODE *temp;
    temp = head;
    gotoxy(66,8);cout<<"Subtraction";
    //checking every single player and sort in descending order according to the addition score
    while(temp!=NULL){
        allSort(temp,6);
        temp=temp->next;
    }
    allDisplay(6);
}
void MyClass::DivLead2(){
    NODE *temp;
    temp = head;
    gotoxy(66,19);cout<<"Division";
    //checking every single player and sort in descending order according to the addition score
    while(temp!=NULL){
        allSort(temp,7);
        temp=temp->next;
    }
    allDisplay(7);
}
void MyClass::MulLead2(){
    NODE *temp;
    temp = head;
    gotoxy(23,19);cout<<"Multiplication";
    //checking every single player and sort in descending order according to the addition score
    while(temp!=NULL){
        allSort(temp,8);
        temp=temp->next;
    }
    allDisplay(8);
}
void MyClass::AddLead3(){
    NODE *temp;
    temp = head;
    gotoxy(26,8);cout<<"Addition";
    //checking every single player and sort in descending order according to the addition score
    while(temp!=NULL){
        allSort(temp,9);
        temp=temp->next;
    }
    allDisplay(9);
}
void MyClass::SubLead3(){
    NODE *temp;
    temp = head;
    gotoxy(66,8);cout<<"Subtraction";
    //checking every single player and sort in descending order according to the addition score
    while(temp!=NULL){
        allSort(temp,10);
        temp=temp->next;
    }
    allDisplay(10);
}
void MyClass::DivLead3(){
    NODE *temp;
    temp = head;
    gotoxy(66,19);cout<<"Division";
    //checking every single player and sort in descending order according to the addition score
    while(temp!=NULL){
        allSort(temp,11);
        temp=temp->next;
    }
    allDisplay(11);
}
void MyClass::MulLead3(){
    NODE *temp;
    temp = head;
    gotoxy(23,19);cout<<"Multiplication";
    //checking every single player and sort in descending order according to the addition score
    while(temp!=NULL){
        allSort(temp,12);
        temp=temp->next;
    }
    allDisplay(12);
}
void MyClass::AddLead4(){
    NODE *temp;
    temp = head;
    gotoxy(26,8);cout<<"Addition";
    //checking every single player and sort in descending order according to the addition score
    while(temp!=NULL){
        allSort(temp,13);
        temp=temp->next;
    }
    allDisplay(13);
}
void MyClass::SubLead4(){
    NODE *temp;
    temp = head;
    gotoxy(66,8);cout<<"Subtraction";
    //checking every single player and sort in descending order according to the addition score
    while(temp!=NULL){
        allSort(temp,14);
        temp=temp->next;
    }
    allDisplay(14);
}
void MyClass::DivLead4(){
    NODE *temp;
    temp = head;
    gotoxy(66,19);cout<<"Division";
    //checking every single player and sort in descending order according to the addition score
    while(temp!=NULL){
        allSort(temp,15);
        temp=temp->next;
    }
    allDisplay(15);
}
void MyClass::MulLead4(){
    NODE *temp;
    temp = head;
    gotoxy(23,19);cout<<"Multiplication";
    //checking every single player and sort in descending order according to the addition score
    while(temp!=NULL){
        allSort(temp,16);
        temp=temp->next;
    }
    allDisplay(16);
}
void MyClass::AddLead5(){
    NODE *temp;
    temp = head;
    gotoxy(26,8);cout<<"Addition";
    //checking every single player and sort in descending order according to the addition score
    while(temp!=NULL){
        allSort(temp,17);
        temp=temp->next;
    }
    allDisplay(17);
}
void MyClass::SubLead5(){
    NODE *temp;
    temp = head;
    gotoxy(66,8);cout<<"Subtraction";
    //checking every single player and sort in descending order according to the addition score
    while(temp!=NULL){
        allSort(temp,18);
        temp=temp->next;
    }
    allDisplay(18);
}
void MyClass::DivLead5(){
    NODE *temp;
    temp = head;
    gotoxy(66,19);cout<<"Division";
    //checking every single player and sort in descending order according to the addition score
    while(temp!=NULL){
        allSort(temp,19);
        temp=temp->next;
    }
    allDisplay(19);
}
void MyClass::MulLead5(){
    NODE *temp;
    temp = head;
    gotoxy(23,19);cout<<"Multiplication";
    //checking every single player and sort in descending order according to the addition score
    while(temp!=NULL){
        allSort(temp,20);
        temp=temp->next;
    }
    allDisplay(20);
}
void MyClass::AllLead(){
    NODE *temp;
    temp = head;
    gotoxy(26,8);cout<<"Level 1 Overall Rankings";
    //checking every single player and sort in descending order according to the addition score
    while(temp!=NULL){
        allSort(temp,21);
        temp=temp->next;
    }
    allDisplay(21);
}
void MyClass::AllLead2(){
    NODE *temp;
    temp = head;
    gotoxy(66,8);cout<<"Level 2 Overall Rankings";
    //checking every single player and sort in descending order according to the addition score
    while(temp!=NULL){
        allSort(temp,22);
        temp=temp->next;
    }
    allDisplay(22);
}
void MyClass::AllLead3(){
    NODE *temp;
    temp = head;
    gotoxy(23,19);cout<<"Level 3 Overall Rankings";
    //checking every single player and sort in descending order according to the addition score
    while(temp!=NULL){
        allSort(temp,23);
        temp=temp->next;
    }
    allDisplay(23);
}
void MyClass::AllLead4(){
    NODE *temp;
    temp = head;
    gotoxy(66,19);cout<<"Level 4 Overall Rankings";
    //checking every single player and sort in descending order according to the addition score
    while(temp!=NULL){
        allSort(temp,24);
        temp=temp->next;
    }
    allDisplay(24);
}
void MyClass::AllLead5(){
    NODE *temp;
    temp = head;
    gotoxy(48,31);cout<<"Level 5 Overall Rankings";
    //checking every single player and sort in descending order according to the addition score
    while(temp!=NULL){
        allSort(temp,25);
        temp=temp->next;
    }
    allDisplay(25);
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
            case 1: obj.addition();break;
            case 2: obj.subtraction();break;
            case 3: obj.division();break;
            case 4: obj.multiplication();break;
            case 5: obj.leaderboard();obj.save();exit(0);break;
            default:system("cls");
                    gotoxy(40,5);cout<<"Numbers 1-5 only.";
                    gotoxy(40,6);system("pause");break;
        }
    }
return 0;
}
