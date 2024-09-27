#include<iostream>
#include<string>
using namespace std;

class student
{
  protected :
    string name;
    int rollno;
    int age;
    string sec;
    char gender[1];
  public:
    student()
    {
        cout<<"\nEnter Name :"<<endl;
        cin>>name;
        cout<<"Enter Roll No. :"<<endl;
        cin>>rollno;
        cout<<"Enter Section :"<<endl;
        cin>>sec;
        cout<<"Enter Age :"<<endl;
        cin>>age;
        cout<<"Enter Gender[M/F] :"<<endl;
        cin>>gender;
    }
};
class test : public student
{
    protected :
        int marks[5];
    public :
    test()
    {
    cout<<"Enter Marks Of Five Subject :"<<endl;
    for(int i=1;i<=5;i++)
        {
            cout<<"Marks Of Subject :"<<i<<endl;
            cin>>marks[i];
        }
    }
};
class sports : public test
{
    protected :
        int markssports;
    public:
        sports()
        {
            cout<<"Enter The Marks Of Sports :"<<endl;
            cin>>markssports;
        }
};

class result : public sports
{
    protected :
        int total_marks;
        float percentage;
    public :
        result()
        {
            total_marks=0;
            for(int i=1;i<=5;i++)
            {
                total_marks += marks[i];
            }
            total_marks=total_marks+markssports;
            percentage=total_marks/6;
        }   
        void showdata()
        {
            cout<<endl;
             cout<<"<--------------------------------------------->"<<endl;
             cout<<"\n\n";
             cout<<"Name :"<<name<<endl;
             cout<<"Roll No. :"<<rollno<<endl;
             cout<<"Section :"<<sec<<endl;
             cout<<"Age :"<<age<<endl;
             cout<<"Gender :"<<gender<<endl;
             cout<<"Marks Of Five Subjects :"<<endl;
             for(int i=1;i<=5;i++)
            {
                cout<<"Marks Obtained In subject "<<i<<" :"<<marks[i]<<endl;
            }
             cout<<"Marks Obtained In Sports :"<<markssports<<endl;
             cout<<"Total Marks :"<<total_marks<<endl;
             cout<<"Percentage :"<<percentage<<endl;
        }
};

int main()
{
    long int num;
    cout<<"Please Enter The Strength Of Class :"<<endl;
    cin>>num;
    result obj [num];
    for(int i=0;i<num;i++)
    {
    obj[i].showdata();
    }
    return 0;
}
