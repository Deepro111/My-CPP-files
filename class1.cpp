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
    void getmarks(int a){
        marks = a;
    }
};


int main(){
    student std;

    std.setdata(3);
    std.getname("Deepak");
    std.getdata();

    
    
    return 0;
}