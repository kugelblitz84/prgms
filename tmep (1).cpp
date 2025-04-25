#include <iostream>
#include <windows.h>

using namespace std;

class node{
public:
    int data;
    node* link;
    node(int);  //constructor
};

//constructor fucntion
node :: node(int n){
    data=n;
    link=NULL;
}
node *root=NULL;

void append()
{
    int n;
    cout<<"Enter data :\n";
    cin>>n;
    node *temp=new node(n);
    if(root==NULL){
        root=temp;
    }else{
        node *p;
        p=root;
        while(p->link!=NULL){
            p=p->link;
        }
        p->link=temp;
    }
    system("cls");
    cout<<"appended value : "<<n<<endl;
    Sleep(1000);
    system("cls");
}

void beg_dlt(){
    root=root->link;
}
void end_dlt(int n){
    node* temp;
    temp=root;
    for(int i=0;i<n-1;i++){
        temp=temp->link;
    }
    temp->link=NULL;
}

void mid_dlt(int n){
    node* temp;
    temp=root;
    for(int i=1;i<n;i++){
        temp=temp->link;
    }
    temp=temp->link->link;
}

void dlt(){
    int n;
    node* temp;
    if(root!=NULL){
       cout<<"Enter  nth node to delete: ";
       cin>>n;
       temp=root;
       int i;
      for(i=0;temp!=NULL;i++){
        temp=temp->link;
      }
      if(n==1 and i==1){
        root=NULL;
      }else if(i>n and n==1){
        beg_dlt();
      }else if(i==n){
        end_dlt(i);
      }else if(i>n) mid_dlt(n);
      else {
        cout<<"the node doesnt exist";
        Sleep(1000);
        system("cls");
      }

    }else cout<<"list empty"<<endl;

    cout<<endl<<"node :"<<n<<"deleted"<<endl;
    Sleep(1000);
    system("cls");


}

void insrt(){
    if(root==NULL){
        cout<<"list empty please append a node first!\n";
        Sleep(2000);
        system("cls");
        return;
    }else{
        cout<<"enter value :\n";
        int n;
        cin>>n;
        node *temp=new node(n);
        node *p;
        cout<<"enter position to insert: "<<endl;
        cin >>n;
        if(n==1){
            temp->link=root;
            root=temp;
            return ;
        }
        p=root;
        for(int i=1;i<n;i++){
            p=p->link;
        }
        temp->link=p->link;
        p->link=temp;
    }
}
void dspl(){
    node* temp;
    temp=root;
    if(root=NULL) cout<<"list empty";
    else{
        while(temp!=NULL){
            cout<<temp->data<<"-->";
            temp=temp->link;
        }
        system("cls");
        cout<<"NULL";
        cout<<"\n\n\n\n";

    }
}

void def(){
    cout<<"invalid"<<endl;
    Sleep(1000);
    system("cls");
}
int main()
{

    while(1){
        int n;
        cout<<"Linked list operations :\n1.append\n2.delete\n3.insert\n4.display\n5.quit\nEnter choice:";
        cin>>n;
        if(n==1) append();
        else if(n==2) dlt();
        else if(n==3) insrt();
        else if(n==4) dspl();
        else if(n==5) break;
        else def();

    }
    return 0;
}
