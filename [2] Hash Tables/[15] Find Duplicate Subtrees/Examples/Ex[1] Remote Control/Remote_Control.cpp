#include <iostream>
#include <string>

struct Student{
    std::string name;
    int grade;
};

void updateGrade(Student* s, int newGrade){
    //We will use -> to access the Member through a pointer.
    s->grade = newGrade;
}

int main(){
    Student u;
    u.name  = "Umar";
    u.grade = 70;

    std::cout<<u.grade<<std::endl;

    updateGrade(&u,95); //We use &u to Pass the Address of Student u. Also it does not make a copy of the u and instead update happens on the Student u directly.
    std::cout<<u.grade<<std::endl;


}
