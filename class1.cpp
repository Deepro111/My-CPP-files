#include<iostream>
using namespace std;

class student{
    
    int roll_num;
    string name;
    public:
    void setdata(int n){
        roll_num = n;
    }
    
    void getname(string s){
        name = s;
    }
    void getdata();
};


class Exam : public student{
    float marks;
    public:
    int getmarks(int a){
        marks = a;
        return marks;
    }
};

void student :: getdata(){
    Exam e;
    int marks = e.getmarks(87);
    cout<<name <<" is having Roll number "<<roll_num<< " have got "<< marks <<" marks";
}


int main(){
    student std;
    Exam e;

    std.setdata(3);
    std.getname("Deepak");
    std.getdata();

    return 0;
}