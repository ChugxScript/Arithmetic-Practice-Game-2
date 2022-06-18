/*Quiz 3 - Previous Machine Problem in CPP
by Andrew R. Oloroso*/
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
    bool isEmpty();
public:
    void init();
    void add(string n, int a1, int a2, int a3);
    void del(string n);
    void display();
    void save();
    void retrieve();
};

void MyClass::init(){
    head=NULL;
}

int menu(){
    int num;
    system("cls");
    cout <<"MENU"<<endl;
    cout <<"[1] Add Record"<<endl;
    cout <<"[2] Delete Record"<<endl;
    cout <<"[3] Display"<<endl;
    cout <<"[4] Save and Exit"<<endl;
    cout <<"Select(1-4): ";
    cin >> num;
    return num;
}

void MyClass::add(string n, int a1, int a2, int a3){
    NODE *p, *q, *newNode;
    p=q=head;
    newNode = new NODE;
    newNode->name = n;
    newNode->q1 = a1; newNode->q2 = a2; newNode->q3 = a3;
    while (p!=NULL && p->name<n){
        q = p;
        p = p->next;
    }
    if (head==p){
        head = newNode;//first element
    }else{
        q->next = newNode;
    }newNode->next = p;
}

void MyClass::del(string n){
    NODE *p, *q;
    p=q=head;
    if (isEmpty()){
        cout<<"List is empty."<<endl;
        system("pause");
    }else {
        while (p!=NULL && (n!=p->name)){
            q=p;
            p=p->next;
        }
        if (p==NULL){
            printf("Not found.\n");
            system("pause");
        }else{
            if (head==p)
               head=p->next;
            else
               q->next = p->next;
            free(p);
            cout<<endl<<"Student "<<n<<" is successfuly deleted."<<endl;
            system("pause");
        }
     }
}

bool MyClass::isEmpty(){
    return(head==NULL);
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
    string Name;
    int num,Q1,Q2,Q3;
    obj.init();
    obj.retrieve();
    while (true){
        num = menu();
        switch(num){
        case 1: system("cls");
                cout <<"Name: ";cin.ignore();getline(cin,Name);
                cout <<"Quiz 1: ";cin >>Q1;
                cout <<"Quiz 2: ";cin >>Q2;
                cout <<"Quiz 3: ";cin >>Q3;
                obj.add(Name,Q1,Q2,Q3);break;
        case 2: system("cls");
                cout <<"Name: ";cin.ignore();getline(cin,Name);
                obj.del(Name);break;
        case 3: obj.display();break;
        case 4: obj.save();exit(0);
        default:cout <<"1 to 4 only."<<endl;system("pause");
        }
      }
    return 0;
}
