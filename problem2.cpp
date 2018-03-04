#include<iostream>
#include<vector>
#include<string>

using namespace std;

typedef struct Data{
    string name;
    int age;
    int grade;
}Data;

int main()
{
    vector<Data> list;
    int inputNum;
    Data inputData;

    cin>>inputNum;
    for(int i=0;i<inputNum;i++)
    {
        string inputName;
        cin>>inputData.name;
        cin>>inputData.age;
        cin>>inputData.grade;
        list.push_back(inputData);
    }
    for(int i=0;i<inputNum;i++)
    {
        for(int j=i;j<inputNum;j++)
        {
            if((list[i].grade>list[j].grade)||((list[i].grade==list[j].grade)&&(list[i].grade>list[i].grade)))
            {
                Data temp;
                temp.age=list[i].age;
                temp.grade=list[i].grade;
                temp.name=list[i].name;
                list[i].age=list[j].age;
                list[i].grade=list[j].grade;
                list[i].name=list[j].name;
                list[j].age=temp.age;
                list[j].grade=temp.grade;
                list[j].name=temp.name;
            }
        }
    }
    for(int i=0;i<inputNum;i++)
    {
        cout<<list[i].name<<" ";
        cout<<list[i].age<<" ";
        cout<<list[i].grade<<endl;
    }
    return 0;
}