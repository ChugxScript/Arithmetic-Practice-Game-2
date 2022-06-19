/*Project 2 in CPP
by Andrew R. Oloroso and Armand Angelo C. Barrios*/
#include <iostream>
#include <iomanip> //for setprecision
#include <fstream>
#include <windows.h>
#include <time.h>
#include <conio.h>
#define MAX 50
using namespace std;
typedef struct playerRec { //self-referecial structre
    int plus1,minus1,divide1,multiply1;
    int plus2,minus2,divide2,multiply2;
    int plus3,minus3,divide3,multiply3;
    int plus4,minus4,divide4,multiply4;
    int plus5,minus5,divide5,multiply5;
    float ave1,ave2,ave3,ave4,ave5;
    string name;
    string pass;
} SREC; SREC PLAYER [MAX];

class MyClass {
private:
    int items=10,counter,marker,marker2,level,start;
    char c;
    int locate(string n);
    void score();
    void AddRec(SREC pl);
    void AllLead(); void AllLead2(); void AllLead3(); void AllLead4(); void AllLead5();
    void AddLead(); void AddLead2(); void AddLead3(); void AddLead4(); void AddLead5();
    void SubLead(); void SubLead2(); void SubLead3(); void SubLead4(); void SubLead5();
    void DivLead(); void DivLead2(); void DivLead3(); void DivLead4(); void DivLead5();
    void MulLead(); void MulLead2(); void MulLead3(); void MulLead4(); void MulLead5();
public:
    void init();
    void logIn();
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
    marker = -1;
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
    SREC player;
    system("cls"); box();
    gotoxy(45,6);cout<<"Enter Username/UserID: ";cin.ignore();getline(cin,player.name); //prompt the user's username/ID
    int l = locate(player.name); //check if name is already in the list
    if(l > -1){
            here: system("cls"); box();
            gotoxy(45,6);cout<<"Welcome back, "<<player.name<<"!"; //prompt the player's password
            gotoxy(45,7);cout<<"Enter Password: "; cin.ignore();getline(cin,player.pass);
            //check if password is correct
            for(int x=0;x<=marker;x++){
                if (player.pass==PLAYER[x].pass){ //check if in the array structure if correct proceed to next part
                    gotoxy(45,9);system("pause");marker2=l;break;
                }else{
                    gotoxy(45,9);cout<<"Wrong password.";
                    gotoxy(45,11);system("pause");
                    goto here; //goto here is responsible to loop if wrong password
                }
            }
        }else{ //will create new account if not in the list
            marker++;
            PLAYER[marker].name=player.name;
            system("cls"); box();
            gotoxy(45,6);cout<<"A NEW CHALLENGER!";
            gotoxy(45,7);cout<<"Enter Password: "; //prompt the new player's password
            cin.ignore();getline(cin,PLAYER[marker].pass);
            gotoxy(45,12);marker2=marker;system("pause");
        }
}

int MyClass::locate(string n){
    for(int x=0;x<=marker;x++)
        if (n==PLAYER[x].name)
            return x;
    return -1;
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
            score();
            smallbox();
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
        system("cls");
        if(level == 10){ //will store the score acording to the level
            PLAYER[marker2].plus1 = counter;
        }else if(level == 20){
            PLAYER[marker2].plus2 = counter;
        }else if(level == 50){
            PLAYER[marker2].plus3 = counter;
        }else if(level == 80){
            PLAYER[marker2].plus4 = counter;
        }else if(level == 100){
            PLAYER[marker2].plus5 = counter;
        }
        gotoxy(40,7);cout<<"Do you want to use this operation again? ";
        gotoxy(45,8);cout<<" [Y] if Yes. [N] if No.";
        c = getch();
    }while(c == 'y' || c == 'Y');
        if(c == 'n' || c == 'N'){
            gotoxy(40,10);cout<<"Do you want to go to menu?";
            gotoxy(40,11);cout<<" [Y] if Yes. [N] to Exit.";
            c = getch();
            if(c == 'n' || c == 'N'){
                leaderboard();
                save();
                exit(0);
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
            score();
            smallbox();
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
        system("cls");
        if(level == 10){ //will store the score acording to the level
            PLAYER[marker2].minus1 = counter;
        }else if(level == 20){
            PLAYER[marker2].minus2 = counter;
        }else if(level == 50){
            PLAYER[marker2].minus3 = counter;
        }else if(level == 80){
            PLAYER[marker2].minus4 = counter;
        }else if(level == 100){
            PLAYER[marker2].minus5 = counter;
        }
        gotoxy(40,7);cout<<"Do you want to use this operation again? ";
        gotoxy(45,8);cout<<" [Y] if Yes. [N] if No.";
        c = getch();
    }while(c == 'y' || c == 'Y');
        if(c == 'n' || c == 'N'){
            gotoxy(40,10);cout<<"Do you want to go to menu?";
            gotoxy(40,11);cout<<" [Y] if Yes. [N] to Exit.";
            c = getch();
            if(c == 'n' || c == 'N'){
                leaderboard();
                save();
                exit(0);
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
            score();
            smallbox();
            gotoxy(35,3);cout<<"Problem #" <<x+1;
            for(int i=0;i<7;i++){
                gotoxy(38+i,7);cout<<(char)ul;
            }
            temp = y*z; //to have divisible numbers
            y = temp;
            gotoxy(40,5);cout<<"  "<<y;
            gotoxy(40,6);cout<<s<<" "<<z;
            gotoxy(41,8);cin>>answer;
            if(answer == y/z){
                gotoxy(33,12);cout<<"Correct!";
                counter++;score();
            }else{
                gotoxy(33,12);cout<<"Wrong. The correct answer is "<<y/z;
            }
            gotoxy(33,14);system("pause");
        }
        system("cls");
        if(level == 10){ //will store the score acording to the level
            PLAYER[marker2].divide1 = counter;
        }else if(level == 20){
            PLAYER[marker2].divide2 = counter;
        }else if(level == 50){
            PLAYER[marker2].divide3 = counter;
        }else if(level == 80){
            PLAYER[marker2].divide4 = counter;
        }else if(level == 100){
            PLAYER[marker2].divide5 = counter;
        }
        gotoxy(40,7);cout<<"Do you want to use this operation again? ";
        gotoxy(45,8);cout<<" [Y] if Yes. [N] if No.";
        c = getch();
    }while(c == 'y' || c == 'Y');
        if(c == 'n' || c == 'N'){
            gotoxy(40,10);cout<<"Do you want to go to menu?";
            gotoxy(40,11);cout<<" [Y] if Yes. [N] to Exit.";
            c = getch();
            if(c == 'n' || c == 'N'){
                leaderboard();
                save();
                exit(0);
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
            score();
            smallbox();
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
        system("cls");
        if(level == 10){ //will store the score acording to the level
            PLAYER[marker2].multiply1 = counter;
        }else if(level == 20){
            PLAYER[marker2].multiply2 = counter;
        }else if(level == 50){
            PLAYER[marker2].multiply3 = counter;
        }else if(level == 80){
            PLAYER[marker2].multiply4 = counter;
        }else if(level == 100){
            PLAYER[marker2].multiply5 = counter;
        }
        gotoxy(40,7);cout<<"Do you want to use this operation again? ";
        gotoxy(45,8);cout<<" [Y] if Yes. [N] if No.";
        c = getch();
    }while(c == 'y' || c == 'Y');
        if(c == 'n' || c == 'N'){
            gotoxy(40,10);cout<<"Do you want to go to menu?";
            gotoxy(40,11);cout<<" [Y] if Yes. [N] to Exit.";
            c = getch();
            if(c == 'n' || c == 'N'){
                leaderboard();
                save();
                exit(0);
            }
        }
}

void MyClass::score(){ //display updated score
    gotoxy(90,2);cout<<"Score: "<<counter<<"/"<<items<<":"<<fixed<<setprecision(2)<<(float)counter/items*100;
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

void MyClass::save(){ //will save the data from array structure to the txt file
    fstream fp;
    fp.open("BSCS-1CD-Leaderboard.txt",ios::out);
    int x;
    if (!fp){
        gotoxy(40,5);cout<<"Error 404. Saved file was not found.";
        gotoxy(40,10);system("pause");
    }
    else {
        for (x=0;x<=marker;x++){
            fp<<PLAYER[x].name<<endl<<PLAYER[x].pass<<endl
              <<PLAYER[x].plus1<<" "<<PLAYER[x].minus1<<" "<<PLAYER[x].divide1<<" "<<PLAYER[x].multiply1<<"\t"
              <<PLAYER[x].plus2<<" "<<PLAYER[x].minus2<<" "<<PLAYER[x].divide2<<" "<<PLAYER[x].multiply2<<"\t"
              <<PLAYER[x].plus3<<" "<<PLAYER[x].minus3<<" "<<PLAYER[x].divide3<<" "<<PLAYER[x].multiply3<<"\t"
              <<PLAYER[x].plus4<<" "<<PLAYER[x].minus4<<" "<<PLAYER[x].divide4<<" "<<PLAYER[x].multiply4<<"\t"
              <<PLAYER[x].plus5<<" "<<PLAYER[x].minus5<<" "<<PLAYER[x].divide5<<" "<<PLAYER[x].multiply5<<endl;
        }
        fp.close();
    }
}

void MyClass::retrieve(){ //will scan the txt file
    fstream fp;
    fp.open("BSCS-1CD-Leaderboard.txt",ios::in);
    SREC players;
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
                AddRec(players);
            }else{
                break;
            }
        }
        fp.close();
   }
}

void MyClass::AddRec(SREC pl){
    //check if array is full
    if (marker == MAX-1){
        cout<<"Array is Full";
        system("\npause");
    }else{
        //will add the record from the file to the array structure
        marker++;
        PLAYER[marker]=pl;
    }
}

void MyClass::leaderboard(){
    int i;
    system("cls");
    for (i=0;i<=marker2;i++){ //assigning the value of average of every player per level
        PLAYER[i].ave1 = (PLAYER[i].plus1 + PLAYER[i].minus1 + PLAYER[i].divide1 + PLAYER[i].multiply1) / 4.0;
        PLAYER[i].ave2 = (PLAYER[i].plus2 + PLAYER[i].minus2 + PLAYER[i].divide2 + PLAYER[i].multiply2) / 4.0;
        PLAYER[i].ave3 = (PLAYER[i].plus3 + PLAYER[i].minus3 + PLAYER[i].divide3 + PLAYER[i].multiply3) / 4.0;
        PLAYER[i].ave4 = (PLAYER[i].plus4 + PLAYER[i].minus4 + PLAYER[i].divide4 + PLAYER[i].multiply4) / 4.0;
        PLAYER[i].ave5 = (PLAYER[i].plus5 + PLAYER[i].minus5 + PLAYER[i].divide5 + PLAYER[i].multiply5) / 4.0;
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

void MyClass::AllLead(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(26,8);cout<<"Level 1 Overall Rankings";
    //checking every single player and sort in descending order according to the average
    for(int x=0;x<=marker2;x++){
        for(int y=0;y<marker2;y++){
            if (PLAYER[y].ave1 < PLAYER[y+1].ave1){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    //will print "DATA UNAVAILABLE" if doesn't have a score yet in every operation
    for(int z=0;z<=marker2;z++){
        if(PLAYER[z].plus1==NULL||PLAYER[z].minus1==NULL||PLAYER[z].multiply1==NULL||PLAYER[z].divide1==NULL){
            gotoxy(19,9);cout<<"  PLAYER\t  AVERAGE SCORE(%%)";
            gotoxy(17,10+z);cout<<z+1<<".  "<<PLAYER[z].name;
            gotoxy(25,10+z);cout<<"\t  DATA UNAVAILABLE";
        }
        else{
        gotoxy(19,9);cout<<"  PLAYER\t  AVERAGE SCORE(%%)";
        gotoxy(17,10+z);cout<<z+1<<".  "<<PLAYER[z].name<<"\t      "<<fixed<<setprecision(2)<<PLAYER[z].ave1<<endl;
        }
    }
}
void MyClass::AddLead(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(26,8);cout<<"Addition";
    //checking every single player and sort in descending order according to the addition score
    for(int x=0;x<=marker2;x++){
        for(int y=0;y<marker2;y++){
            if (PLAYER[y].plus1 < PLAYER[y+1].plus1){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    //will print "---" if new player and display score if old player
    for(int z=0;z<=marker2;z++){
        if(PLAYER[z].plus1==NULL){
            gotoxy(19,9);cout<<"  PLAYER\t  SCORE(%%)";
            gotoxy(17,10+z);cout<<z+1<<".   "<<PLAYER[z].name;
            gotoxy(25,10+z);cout<<"\t  ---";
        }
        else{
        gotoxy(19,9);cout<<"  PLAYER\t  SCORE(%%)";
        gotoxy(17,10+z);cout<<z+1<<".   "<<PLAYER[z].name;
        gotoxy(25,10+z);cout<<"\t  "<<PLAYER[z].plus1<<" "<<fixed<<setprecision(2)<<(float)PLAYER[z].plus1/items*100<<"%%"<<endl;
        }
    }
}
void MyClass::SubLead(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(66,8);cout<<"Subtraction";
    //checking every single player and sort in descending order according to the subtraction score
    for(int x=0;x<=marker2;x++){
        for(int y=0;y<marker2;y++){
            if (PLAYER[y].minus1 < PLAYER[y+1].minus1){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    //will print "---" if new player and display score if old player
    for(int z=0;z<=marker2;z++){
        if(PLAYER[z].minus1==NULL){
            gotoxy(59,9);cout<<"  PLAYER\t  SCORE(%%)";
            gotoxy(57,10+z);cout<<z+1<<".   "<<PLAYER[z].name;
            gotoxy(65,10+z);cout<<"\t  ---";
        }
        else{
        gotoxy(59,9);cout<<"  PLAYER\t  SCORE(%%)";
        gotoxy(57,10+z);cout<<z+1<<".   "<<PLAYER[z].name;
        gotoxy(65,10+z);cout<<"\t  "<<PLAYER[z].minus1<<" "<<fixed<<setprecision(2)<<(float)PLAYER[z].minus1/items*100<<"%%"<<endl;
        }
    }
}
void MyClass::DivLead(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(66,19);cout<<"Division";
    //checking every single player and sort in descending order according to the division score
    for(int x=0;x<=marker2;x++){
        for(int y=0;y<marker2;y++){
            if (PLAYER[y].divide1 < PLAYER[y+1].divide1){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    //will print "---" if new player and display score if old player
    for(int z=0;z<=marker2;z++){
        if(PLAYER[z].divide1==NULL){
            gotoxy(59,20);cout<<"  PLAYER\t  SCORE(%%)";
            gotoxy(57,21+z);cout<<z+1<<".   "<<PLAYER[z].name;
            gotoxy(65,21+z);cout<<"\t  ---";
        }
        else{
        gotoxy(59,20);cout<<"  PLAYER\t  SCORE(%%)";
        gotoxy(57,21+z);cout<<z+1<<".   "<<PLAYER[z].name;
        gotoxy(65,21+z);cout<<"\t  "<<PLAYER[z].divide1<<" "<<fixed<<setprecision(2)<<(float)PLAYER[z].divide1/items*100<<"%%"<<endl;
        }
    }
}
void MyClass::MulLead(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(23,19);cout<<"Multiplication";
    //checking every single player and sort in descending order according to the multiplication score
    for(int x=0;x<=marker2;x++){
        for(int y=0;y<marker2;y++){
            if (PLAYER[y].multiply1 < PLAYER[y+1].multiply1){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    //will print "---" if new player and display score if old player
    for(int z=0;z<=marker2;z++){
        if(PLAYER[z].multiply1==NULL){
            gotoxy(19,20);cout<<"  PLAYER\t  SCORE(%%)";
            gotoxy(17,21+z);cout<<z+1<<".   "<<PLAYER[z].name;
            gotoxy(25,21+z);cout<<"\t  ---";
        }
        else{
        gotoxy(19,20);cout<<"  PLAYER\t  SCORE(%%)";
        gotoxy(17,21+z);cout<<z+1<<".   "<<PLAYER[z].name;
        gotoxy(25,21+z);cout<<"\t  "<<PLAYER[z].multiply1<<" "<<fixed<<setprecision(2)<<(float)PLAYER[z].multiply1/items*100<<"%%"<<endl;
        }
    }
}
void MyClass::AllLead2(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(66,8);cout<<"Level 2 Overall Rankings";
    //checking every single player and sort in descending order according to the average in level 2
    for(int x=0;x<=marker2;x++){
        for(int y=0;y<marker2;y++){
            if (PLAYER[y].ave2 < PLAYER[y+1].ave2){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    for(int z=0;z<=marker2;z++){
        if(PLAYER[z].plus2==NULL||PLAYER[z].minus2==NULL||PLAYER[z].multiply2==NULL||PLAYER[z].divide2==NULL){
            gotoxy(59,9);cout<<"  PLAYER\t  AVERAGE SCORE(%%)";
            gotoxy(57,10+z);cout<<z+1<<".  "<<PLAYER[z].name;
            gotoxy(65,10+z);cout<<"\t  DATA UNAVAILABLE";
        }
        else{
        gotoxy(59,9);cout<<"  PLAYER\t  AVERAGE SCORE(%%)";
        gotoxy(57,10+z);cout<<z+1<<".  "<<PLAYER[z].name<<"\t      "<<fixed<<setprecision(2)<<PLAYER[z].ave2;
        }
    }
}
void MyClass::AddLead2(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(26,8);cout<<"Addition";
    //checking every single player and sort in descending order according to the addition score in level 2
    for(int x=0;x<=marker2;x++){
        for(int y=0;y<marker2;y++){
            if (PLAYER[y].plus2 < PLAYER[y+1].plus2){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    //will print "---" if new player and display score if old player
    for(int z=0;z<=marker2;z++){
        if(PLAYER[z].plus2==NULL){
            gotoxy(19,9);cout<<"  PLAYER\t  SCORE(%%)";
            gotoxy(17,10+z);cout<<z+1<<".  "<<PLAYER[z].name;
            gotoxy(25,10+z);cout<<"\t  ---";
        }
        else{
        gotoxy(19,9);cout<<"  PLAYER\t  SCORE(%%)";
        gotoxy(17,10+z);cout<<z+1<<".   "<<PLAYER[z].name;
        gotoxy(25,10+z);cout<<"\t  "<<PLAYER[z].plus2<<" "<<fixed<<setprecision(2)<<(float)PLAYER[z].plus2/items*100<<"%%"<<endl;
        }
    }
}
void MyClass::SubLead2(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(66,8);cout<<"Subtraction";
    //checking every single player and sort in descending order according to the subtraction score in level  2
    for(int x=0;x<=marker2;x++){
        for(int y=0;y<marker2;y++){
            if (PLAYER[y].minus2 < PLAYER[y+1].minus2){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    //will print "---" if new player and display score if old player
    for(int z=0;z<=marker2;z++){
        if(PLAYER[z].minus2==NULL){
            gotoxy(59,9);cout<<"  PLAYER\t  SCORE(%%)";
            gotoxy(57,10+z);cout<<z+1<<".  "<<PLAYER[z].name;
            gotoxy(65,10+z);cout<<"\t  ---";
        }
        else{
        gotoxy(59,9);cout<<"  PLAYER\t  SCORE(%%)";
        gotoxy(57,10+z);cout<<z+1<<".   "<<PLAYER[z].name;
        gotoxy(65,10+z);cout<<"\t  "<<PLAYER[z].minus2<<" "<<fixed<<setprecision(2)<<(float)PLAYER[z].minus2/items*100<<"%%"<<endl;
        }
    }
}
void MyClass::DivLead2(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(66,19);cout<<"Division";
    //checking every single player and sort in descending order according to the division score in level 2
    for(int x=0;x<=marker2;x++){
        for(int y=0;y<marker2;y++){
            if (PLAYER[y].divide2 < PLAYER[y+1].divide2){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    //will print "---" if new player and display score if old player
    for(int z=0;z<=marker2;z++){
        if(PLAYER[z].divide2==NULL){
            gotoxy(59,20);cout<<"  PLAYER\t  SCORE(%%)";
            gotoxy(57,21+z);cout<<z+1<<".  "<<PLAYER[z].name;
            gotoxy(65,21+z);cout<<"\t  ---";
        }
        else{
        gotoxy(59,20);cout<<"  PLAYER\t  SCORE(%%)";
        gotoxy(57,21+z);cout<<z+1<<".   "<<PLAYER[z].name;
        gotoxy(65,21+z);cout<<"\t  "<<PLAYER[z].divide2<<" "<<fixed<<setprecision(2)<<(float)PLAYER[z].divide2/items*100<<"%%"<<endl;
        }
    }
}
void MyClass::MulLead2(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(23,19);cout<<"Multiplication";
    //checking every single player and sort in descending order according to the multiplication score in level 2
    for(int x=0;x<=marker2;x++){
        for(int y=0;y<marker2;y++){
            if (PLAYER[y].multiply2 < PLAYER[y+1].multiply2){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    //will print "---" if new player and display score if old player
    for(int z=0;z<=marker2;z++){
        if(PLAYER[z].multiply2==NULL){
            gotoxy(19,20);cout<<"  PLAYER\t  SCORE(%%)";
            gotoxy(17,21+z);cout<<z+1<<".  "<<PLAYER[z].name;
            gotoxy(25,21+z);cout<<"\t  ---";
        }
        else{
        gotoxy(19,20);cout<<"  PLAYER\t  SCORE(%%)";
        gotoxy(17,21+z);cout<<z+1<<".   "<<PLAYER[z].name;
        gotoxy(25,21+z);cout<<"\t  "<<PLAYER[z].multiply2<<" "<<fixed<<setprecision(2)<<(float)PLAYER[z].multiply2/items*100<<"%%"<<endl;
        }
    }
}

void MyClass::AllLead3(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(23,19);cout<<"Level 3 Overall Rankings";
    //checking every single player and sort in descending order according to the average in level 3
    for(int x=0;x<=marker2;x++){
        for(int y=0;y<marker2;y++){
            if (PLAYER[y].ave3 < PLAYER[y+1].ave3){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    for(int z=0;z<=marker2;z++){
        if(PLAYER[z].plus3==NULL||PLAYER[z].minus3==NULL||PLAYER[z].multiply3==NULL||PLAYER[z].divide3==NULL){
             gotoxy(19,20);cout<<"  PLAYER\t  AVERAGE SCORE(%%)";
            gotoxy(17,21+z);cout<<z+1<<".  "<<PLAYER[z].name;
            gotoxy(25,21+z);cout<<"\t  DATA UNAVAILABLE";
        }
        else{
        gotoxy(19,20);cout<<"  PLAYER\t  AVERAGE SCORE(%%)";
        gotoxy(17,21+z);cout<<z+1<<".  "<<PLAYER[z].name<<"\t      "<<fixed<<setprecision(2)<<PLAYER[z].ave3;
        }
    }
}
void MyClass::AddLead3(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(26,8);cout<<"Addition";
    //checking every single player and sort in descending order according to the addition score in level 3
    for(int x=0;x<=marker2;x++){
        for(int y=0;y<marker2;y++){
            if (PLAYER[y].plus3 < PLAYER[y+1].plus3){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    //will print "---" if new player and display score if old player
    for(int z=0;z<=marker2;z++){
        if(PLAYER[z].plus3==NULL){
            gotoxy(19,9);cout<<"  PLAYER\t  SCORE(%%)";
            gotoxy(17,10+z);cout<<z+1<<".  "<<PLAYER[z].name;
            gotoxy(25,10+z);cout<<"\t  ---";
        }
        else{
        gotoxy(19,9);cout<<"  PLAYER\t  SCORE(%%)";
        gotoxy(17,10+z);cout<<z+1<<".   "<<PLAYER[z].name;
        gotoxy(25,10+z);cout<<"\t  "<<PLAYER[z].plus3<<" "<<fixed<<setprecision(2)<<(float)PLAYER[z].plus3/items*100<<"%%"<<endl;
        }
    }
}
void MyClass::SubLead3(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(66,8);cout<<"Subtraction";
    //checking every single player and sort in descending order according to the subtraction score in level 3
    for(int x=0;x<=marker2;x++){
        for(int y=0;y<marker2;y++){
            if (PLAYER[y].minus3 < PLAYER[y+1].minus3){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    //will print "---" if new player and display score if old player
    for(int z=0;z<=marker2;z++){
        if(PLAYER[z].minus3==NULL){
            gotoxy(59,9);cout<<"  PLAYER\t  SCORE(%%)";
            gotoxy(57,10+z);cout<<z+1<<".  "<<PLAYER[z].name;
            gotoxy(65,10+z);cout<<"\t  ---";
        }
        else{
        gotoxy(59,9);cout<<"  PLAYER\t  SCORE(%%)";
        gotoxy(57,10+z);cout<<z+1<<".   "<<PLAYER[z].name;
        gotoxy(65,10+z);cout<<"\t  "<<PLAYER[z].minus3<<" "<<fixed<<setprecision(2)<<(float)PLAYER[z].minus3/items*100<<"%%"<<endl;
        }
    }
}
void MyClass::DivLead3(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(66,19);cout<<"Division";
    //checking every single player and sort in descending order according to the division score in level 3
    for(int x=0;x<=marker2;x++){
        for(int y=0;y<marker2;y++){
            if (PLAYER[y].divide3 < PLAYER[y+1].divide3){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    //will print "---" if new player and display score if old player
    for(int z=0;z<=marker2;z++){
        if(PLAYER[z].divide3==NULL){
            gotoxy(59,20);cout<<"  PLAYER\t  SCORE(%%)";
            gotoxy(57,21+z);cout<<z+1<<".  "<<PLAYER[z].name;
            gotoxy(65,21+z);cout<<"\t  ---";
        }
        else{
        gotoxy(59,20);cout<<"  PLAYER\t  SCORE(%%)";
        gotoxy(57,21+z);cout<<z+1<<".   "<<PLAYER[z].name;
        gotoxy(65,21+z);cout<<"\t  "<<PLAYER[z].divide3<<" "<<fixed<<setprecision(2)<<(float)PLAYER[z].divide3/items*100<<"%%"<<endl;
        }
    }
}
void MyClass::MulLead3(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(23,19);cout<<"Multiplication";
    //checking every single player and sort in descending order according to the multiplication score in level 3
    for(int x=0;x<=marker2;x++){
        for(int y=0;y<marker2;y++){
            if (PLAYER[y].multiply3 < PLAYER[y+1].multiply3){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    //will print "---" if new player and display score if old player
    for(int z=0;z<=marker2;z++){
        if(PLAYER[z].multiply3==NULL){
            gotoxy(19,20);cout<<"  PLAYER\t  SCORE(%%)";
            gotoxy(17,21+z);cout<<z+1<<".  "<<PLAYER[z].name;
            gotoxy(25,21+z);cout<<"\t  ---";
        }
        else{
        gotoxy(19,20);cout<<"  PLAYER\t  SCORE(%%)";
        gotoxy(17,21+z);cout<<z+1<<".   "<<PLAYER[z].name;
        gotoxy(25,21+z);cout<<"\t  "<<PLAYER[z].multiply3<<" "<<fixed<<setprecision(2)<<(float)PLAYER[z].multiply3/items*100<<"%%"<<endl;
        }
    }
}

void MyClass::AllLead4(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(66,19);cout<<"Level 4 Overall Rankings";
    //checking every single player and sort in descending order according to the average in level 4
    for(int x=0;x<=marker2;x++){
        for(int y=0;y<marker2;y++){
            if (PLAYER[y].ave4 < PLAYER[y+1].ave4){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    for(int z=0;z<=marker2;z++){
        if(PLAYER[z].plus4==NULL||PLAYER[z].minus4==NULL||PLAYER[z].multiply4==NULL||PLAYER[z].divide4==NULL){
            gotoxy(59,20);cout<<"  PLAYER\t  AVERAGE SCORE(%%)";
            gotoxy(57,21+z);cout<<z+1<<".  "<<PLAYER[z].name;
            gotoxy(65,21+z);cout<<"\t  DATA UNAVAILABLE";
        }
        else{
        gotoxy(59,20);cout<<"  PLAYER\t  AVERAGE SCORE(%%)";
        gotoxy(57,21+z);cout<<z+1<<".  "<<PLAYER[z].name<<"\t      "<<fixed<<setprecision(2)<<PLAYER[z].ave4;
        }
    }
}
void MyClass::AddLead4(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(26,8);cout<<"Addition";
    //checking every single player and sort in descending order according to the addition score in level 4
    for(int x=0;x<=marker2;x++){
        for(int y=0;y<marker2;y++){
            if (PLAYER[y].plus4 < PLAYER[y+1].plus4){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    //will print "---" if new player and display score if old player
    for(int z=0;z<=marker2;z++){
        if(PLAYER[z].plus4==NULL){
            gotoxy(19,9);cout<<"  PLAYER\t  SCORE(%%)";
            gotoxy(17,10+z);cout<<z+1<<".  "<<PLAYER[z].name;
            gotoxy(25,10+z);cout<<"\t  ---";
        }
        else{
        gotoxy(19,9);cout<<"  PLAYER\t  SCORE(%%)";
        gotoxy(17,10+z);cout<<z+1<<".  "<<PLAYER[z].name;
        gotoxy(25,21+z);cout<<"\t  "<<PLAYER[z].plus4<<" "<<fixed<<setprecision(2)<<(float)PLAYER[z].plus4/items*100<<"%%"<<endl;
        }
    }
}
void MyClass::SubLead4(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(66,8);cout<<"Subtraction";
    //checking every single player and sort in descending order according to the subtraction score in level 4
    for(int x=0;x<=marker2;x++){
        for(int y=0;y<marker2;y++){
            if (PLAYER[y].minus4 < PLAYER[y+1].minus4){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    //will print "---" if new player and display score if old player
    for(int z=0;z<=marker2;z++){
        if(PLAYER[z].minus4==NULL){
            gotoxy(59,9);cout<<"  PLAYER\t  SCORE(%%)";
            gotoxy(57,10+z);cout<<z+1<<".  "<<PLAYER[z].name;
            gotoxy(65,10+z);cout<<"\t  ---";
        }
        else{
        gotoxy(59,9);cout<<"  PLAYER\t  SCORE(%%)";
        gotoxy(57,10+z);cout<<z+1<<".  "<<PLAYER[z].name;
        gotoxy(65,10+z);cout<<"\t  "<<PLAYER[z].minus4<<" "<<fixed<<setprecision(2)<<(float)PLAYER[z].minus4/items*100<<"%%"<<endl;
        }
    }
}
void MyClass::DivLead4(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(66,19);cout<<"Division";
    //checking every single player and sort in descending order according to the division score in level 4
    for(int x=0;x<=marker2;x++){
        for(int y=0;y<marker2;y++){
            if (PLAYER[y].divide4 < PLAYER[y+1].divide4){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    //will print "---" if new player and display score if old player
    for(int z=0;z<=marker2;z++){
        if(PLAYER[z].divide4==NULL){
            gotoxy(59,20);cout<<"  PLAYER\t  SCORE(%%)";
            gotoxy(57,21+z);cout<<z+1<<".  "<<PLAYER[z].name;
            gotoxy(65,21+z);cout<<"\t  ---";
        }
        else{
        gotoxy(59,20);cout<<"  PLAYER\t  SCORE(%%)";
        gotoxy(57,21+z);cout<<z+1<<".  "<<PLAYER[z].name;
        gotoxy(65,21+z);cout<<"\t  "<<PLAYER[z].divide4<<" "<<fixed<<setprecision(2)<<(float)PLAYER[z].divide4/items*100<<"%%"<<endl;
        }
    }
}
void MyClass::MulLead4(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(23,19);cout<<"Multiplication";
    //checking every single player and sort in descending order according to the multiplication score in level 4
    for(int x=0;x<=marker2;x++){
        for(int y=0;y<marker2;y++){
            if (PLAYER[y].multiply4 < PLAYER[y+1].multiply4){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    //will print "---" if new player and display score if old player
    for(int z=0;z<=marker2;z++){
        if(PLAYER[z].multiply4==NULL){
            gotoxy(19,20);cout<<"  PLAYER\t  SCORE(%%)";
            gotoxy(17,21+z);cout<<z+1<<".  "<<PLAYER[z].name;
            gotoxy(25,21+z);cout<<"\t  ---";
        }
        else{
        gotoxy(19,20);cout<<"  PLAYER\t  SCORE(%%)";
        gotoxy(17,21+z);cout<<z+1<<".  "<<PLAYER[z].name;
        gotoxy(25,21+z);cout<<"\t  "<<PLAYER[z].multiply4<<" "<<fixed<<setprecision(2)<<(float)PLAYER[z].multiply4/items*100<<"%%"<<endl;
        }
    }
}

void MyClass::AllLead5(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(48,31);cout<<"Level 5 Overall Rankings";
    //checking every single player and sort in descending order according to the average in level 5
    for(int x=0;x<=marker2;x++){
        for(int y=0;y<marker2;y++){
            if (PLAYER[y].ave5 < PLAYER[y+1].ave5){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    for(int z=0;z<=marker2;z++){
        if(PLAYER[z].plus5==NULL||PLAYER[z].minus5==NULL||PLAYER[z].multiply5==NULL||PLAYER[z].divide5==NULL){
            gotoxy(44,32);cout<<"  PLAYER\t  AVERAGE SCORE(%%)";
            gotoxy(42,33+z);cout<<z+1<<".  "<<PLAYER[z].name;
            gotoxy(52,33+z);cout<<"\t  DATA UNAVAILABLE";
        }
        else{
        gotoxy(44,32);cout<<"  PLAYER\t  AVERAGE SCORE(%%)";
        gotoxy(42,33+z);cout<<z+1<<".  "<<PLAYER[z].name<<"\t      "<<fixed<<setprecision(2)<<PLAYER[z].ave5;
        }
    }
}
void MyClass::AddLead5(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(26,8);cout<<"Addition";
    //checking every single player and sort in descending order according to the addition score in level 5
    for(int x=0;x<=marker2;x++){
        for(int y=0;y<marker2;y++){
            if (PLAYER[y].plus5 < PLAYER[y+1].plus5){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    //will print "---" if new player and display score if old player
    for(int z=0;z<=marker2;z++){
        if(PLAYER[z].plus5==NULL){
            gotoxy(19,9);cout<<"  PLAYER\t  SCORE(%%)";
            gotoxy(17,10+z);cout<<z+1<<".  "<<PLAYER[z].name;
            gotoxy(25,10+z);printf("\t  ---");
        }
        else{
        gotoxy(19,9);cout<<"  PLAYER\t  SCORE(%%)";
        gotoxy(17,10+z);cout<<z+1<<".  "<<PLAYER[z].name;
        gotoxy(25,10+z);cout<<"\t  "<<PLAYER[z].plus5<<" "<<fixed<<setprecision(2)<<(float)PLAYER[z].plus5/items*100<<"%%"<<endl;
        }
    }
}
void MyClass::SubLead5(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(66,8);cout<<"Subtraction";
    //checking every single player and sort in descending order according to the subtraction score in level 5
    for(int x=0;x<=marker2;x++){
        for(int y=0;y<marker2;y++){
            if (PLAYER[y].minus5 < PLAYER[y+1].minus5){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    //will print "---" if new player and display score if old player
    for(int z=0;z<=marker2;z++){
        if(PLAYER[z].minus5==NULL){
            gotoxy(59,9);cout<<"  PLAYER\t  SCORE(%%)";
            gotoxy(57,10+z);cout<<z+1<<".  "<<PLAYER[z].name;
            gotoxy(65,10+z);cout<<"\t  ---";
        }
        else{
        gotoxy(59,9);cout<<"  PLAYER\t  SCORE(%%)";
        gotoxy(57,10+z);cout<<z+1<<".  "<<PLAYER[z].name;
        gotoxy(65,10+z);cout<<"\t  "<<PLAYER[z].minus5<<" "<<fixed<<setprecision(2)<<(float)PLAYER[z].minus5/items*100<<"%%"<<endl;
        }
    }
}
void MyClass::DivLead5(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(66,19);cout<<"Division";
    //checking every single player and sort in descending order according to the division score in level 5
    for(int x=0;x<=marker2;x++){
        for(int y=0;y<marker2;y++){
            if (PLAYER[y].divide5 < PLAYER[y+1].divide5){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    //will print "---" if new player and display score if old player
    for(int z=0;z<=marker2;z++){
        if(PLAYER[z].divide5==NULL){
            gotoxy(59,20);cout<<"  PLAYER\t  SCORE(%%)";
            gotoxy(57,21+z);cout<<z+1<<".  "<<PLAYER[z].name;
            gotoxy(65,21+z);cout<<"\t  ---";
        }
        else{
        gotoxy(59,20);cout<<"  PLAYER\t  SCORE(%%)";
        gotoxy(57,21+z);cout<<z+1<<".  "<<PLAYER[z].name;
        gotoxy(65,21+z);cout<<"\t  "<<PLAYER[z].divide5<<" "<<fixed<<setprecision(2)<<(float)PLAYER[z].divide5/items*100<<"%%"<<endl;
        }
    }
}
void MyClass::MulLead5(){
    SREC temp; //teporarily store the value of array structure
    gotoxy(23,19);cout<<"Multiplication";
    //checking every single player and sort in descending order according to the multiplication score in level 5
    for(int x=0;x<=marker2;x++){
        for(int y=0;y<marker2;y++){
            if (PLAYER[y].multiply5 < PLAYER[y+1].multiply5){
            temp = PLAYER[y];
            PLAYER[y] = PLAYER[y+1];
            PLAYER[y+1] = temp;
            }
        }
    }
    //will print "---" if new player and display score if old player
    for(int z=0;z<=marker2;z++){
        if(PLAYER[z].multiply5==NULL){
            gotoxy(19,20);cout<<"  PLAYER\t  SCORE(%%)";
            gotoxy(17,21+z);cout<<z+1<<".  "<<PLAYER[z].name;
            gotoxy(25,21+z);cout<<"\t  ---";
        }
        else{
        gotoxy(19,20);cout<<"  PLAYER\t  SCORE(%%)";
        gotoxy(17,21+z);cout<<z+1<<".  "<<PLAYER[z].name;
        gotoxy(25,21+z);cout<<"\t  "<<PLAYER[z].multiply5<<" "<<fixed<<setprecision(2)<<(float)PLAYER[z].multiply5/items*100<<"%%"<<endl;
        }
    }
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
