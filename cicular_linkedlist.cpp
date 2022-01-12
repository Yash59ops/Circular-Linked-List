#include<iostream>
#include<unordered_set>
using namespace std ;
class cll{
private:
    struct node{
    int data;
    node*next;
    };
node*last;
node*start;
public:
cll(){
last=NULL;
start=NULL;
}
void insertatfirst(int data){
node*n=new node;
n->data=data;
if(last==NULL){
n->next=n;
last=n;
}else{
n->next=last->next;
last->next=n;
}

}
void insertatlast(int data){
node*n=new node;
n->data=data;
if(last==NULL){
n->next=n;
last=n;
start=n;
}
else{
n->next=last->next;
last->next=n;
last=n;
}
}
void check(){
node*h=start;
unordered_set<node*>m;
int c=0;
while(h){
    if(m.find(h)!=m.end()){
       c++;
        break;
    }
    m.insert(h);
    h=h->next;
}
if(c!=0){
    cout<<"yes it is a circular list";
}
else{

    cout<<"no";
}
}
void delatfirst(){
node*t=last->next;
if(last==NULL){
    cout<<"underflow"<<endl;
}
else{
        if(last->next==NULL){
            delete last;
            last=NULL;
        }
        else{
last->next=t->next;
delete t;
}
}
}
void delatlast(){
node*t=last;
if(last==NULL){
    cout<<"underflow";
}else{
  if(last->next==NULL){
delete last;
last=NULL;
  }
    else{
while(t->next!=last){
    t=t->next;
}
t->next=last->next;
delete last;
last=t;
}
}
}
~cll(){
    delete last;
}
void display(){
node*t=start;
   do{
    cout<<t->data;
    t=t->next;
}while(t!=start);
}
void reverse(){
node*cur=start;
node*nextnode=start->next;
node*prev=NULL;
while(cur!=last){
    prev=cur;
    cur=nextnode;
    nextnode=cur->next;
cur->next=prev;
}
nextnode->next=last;
swap(last,start);
}
};
//void
int main(){
cll obj;
obj.insertatlast(1);
obj.insertatlast(2);
obj.insertatlast(3);
obj.insertatlast(4);
//obj.reverse();
obj.check();
//obj.tail();
//obj.display();

return 0;
}
