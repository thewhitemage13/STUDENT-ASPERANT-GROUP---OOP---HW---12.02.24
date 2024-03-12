using namespace std;
#include "Student.h"
#include "Date.h"
#include "Group.h"
#include "Fraction.h"

class Asperant : public Student{
private:
    string thesis_topic;
public:

    Asperant(string surname, string name, string middlname, string adress, string phonenumber, string thesis_topic) : Student(surname, name, middlname, adress, phonenumber){
        SetThesisTopic(thesis_topic);
    }

    void SetThesisTopic(string thesis_topic){
        this->thesis_topic = thesis_topic;
    }

    string GetThesisTopic() {
        return thesis_topic;
    }

    void PrintStudent(){
        cout << "Surname:    " << GetSurname() << "\n";
        cout << "Name:       " << GetName() << "\n";
        cout << "Midlname:   " << GetMiddlName() << "\n";
        cout << "Adress:     " << GetAdress() << "\n";
        cout << "Phonnumber: " <<GetPhone() << "\n";
        PrintExam();
        PrintHomeWork();
        PrintPractic();
        cout << "Thesis Topic: " << GetThesisTopic() << "\n";
    }
};

int operator - (const Date& date_now, const Date& other_date)
{
    int thisDays = date_now.GetDay() + 31 * (date_now.GetMonth() - 1);
    int otherDays = other_date.GetDay() + 31 * (other_date.GetMonth() - 1);

    thisDays += (date_now.GetYear() % 4 == 0 && date_now.GetMonth() > 2);
    otherDays += (other_date.GetYear() % 4 == 0 && other_date.GetMonth() > 2);

    thisDays += (date_now.GetMonth() > 1);
    otherDays += (other_date.GetMonth() > 1);

    thisDays += date_now.GetMonth() / 2 + ((date_now.GetMonth() % 2 == 0 && date_now.GetMonth() > 7));
    otherDays += other_date.GetMonth() / 2 + ((other_date.GetMonth() % 2 == 0 && other_date.GetMonth() > 7));

    thisDays += 365 * (date_now.GetYear() - 1);
    otherDays += 365 * (other_date.GetYear() - 1);

    return thisDays - otherDays;
}
//Student
bool operator > (const Student& a, const Student& b)
{
    return a.GetAverageGrade() > b.GetAverageGrade();
}

bool operator<(const Student& left, const Student& right)
{
    return left.GetAverageGrade() < right.GetAverageGrade();
}

bool operator >= (const Student& a, const Student& b)
{
    return a.GetAverageGrade() > b.GetAverageGrade();
}

bool operator <= (const Student& a, const Student& b)
{
    return a.GetAverageGrade() <= b.GetAverageGrade();
}

bool operator == (const Student& a, const Student& b)
{
    return a.GetAverageGrade() == b.GetAverageGrade();
}

bool operator != (const Student& a, const Student& b)
{
    return a.GetAverageGrade() != b.GetAverageGrade();
}
//Group: 
bool operator > (const Group& a, const  Group& b)
{
    return a.GetCountOfStudent() > b.GetCountOfStudent();
}

bool operator < (const Group& left, const Group& right) 
{
    return left.GetCountOfStudent() < right.GetCountOfStudent();
}

bool operator >= (const Group& a, const  Group& b)
{
    return a.GetCountOfStudent() >= b.GetCountOfStudent();
}

bool operator <= (const Group& a, const  Group& b)
{
    return a.GetCountOfStudent() <= b.GetCountOfStudent();
}

bool operator == (const Group& a, const Group& b)
{
    return a.GetCountOfStudent() == b.GetCountOfStudent();
}

bool operator != (const Group& a, const Group& b)
{
    return a.GetCountOfStudent() != b.GetCountOfStudent();
}
//Student
istream& operator >> (const istream& i, Student& d)
{
    cout << "surname: ";
    string answear;
    cin >> answear;
    d.SetSurname(answear);
    
    cout << "name: ";
    cin >> answear;
    d.SetName(answear);
    
    cout << "middle name: ";
    cin >> answear;
    d.SetMiddlName(answear);
    
    cout << "adress: ";
    cin >> answear;
    d.SetAdress(answear);
    
    cout << "phonnumber: ";
    cin >> answear;
    d.SetPhone(answear);
    
    cout << "adress: ";
    cin >> answear;
    d.SetAdress(answear);
    
    return cin;  
}

ostream& operator << ( ostream& i, Student& d)
{
    d.PrintStudent();
    d.PrintExam();
    d.PrintPractic();
    d.PrintHomeWork();
    return cout;
}

istream& operator >> (istream& i, Group& g)
{
    cout << "Group Name: ";
    string answear;
    cin >> answear;
    g.SetGroupName(answear);

    cout << "Group Specification: ";
    cin >> answear;
    g.SetSpecification(answear);

    cout << "Course: ";
    unsigned short amswear2;
    cin >> amswear2;
    g.SetNumberOfCourse(amswear2);

    return cin;
}

ostream& operator << (ostream& i, Group& d)
{
    d.Print();
    return cout;
}

istream& operator >> (istream& i, Fraction& f)
{
    cout << "numerator: ";
    int answear;
    cin >> answear;
    f.SetNumerator(answear);

    cout << "denominator: ";
    cin >> answear;
    f.SetDenominator(answear);

    return cin;
}

ostream& operator << (ostream& i, Fraction& f)
{
    f.Print();
    return cout;
}

int main()
{    
    Asperant a("Lolo", "Mukhammed", "Kamel", "12", "12121212", "oop");
    a.AddExam(12);
    a.AddHomeWork(12);
    a.AddPractic(12);
    a.PrintStudent();
}