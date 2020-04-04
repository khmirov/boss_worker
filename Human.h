//
// Created by 7 on 01.04.2020.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;




class Human {
private:
    string post;
    string name;
    int age;
    int salary;

public:
    void (*error) (string message);

    string GetPost ()
    {
        return post;
    }
    string GetName ()
    {
        return name;
    }
    int GetAge()
    {
        return age;
    }
    int GetSalary()
    {
        return salary;
    }

    void SetPost(string post)
    {
        this->post = post;
    }
    void SetName(string name)
    {
        this->name = name;
    }
    void SetAge(int age)
    {
        if (age < 0 || age > 100)
        {
            error("!!! Invalid age !!!");
            this->age = age;

        } else {
            this->age = age;
        }
    }
    void SetSalary(int salary)
    {
        try
        {
            if (salary < 0)
            {
                throw 506;
            }
        }

        catch (int i)
        {
            cout << "Error #" << i << " - salary smallest than zero" << endl << endl;
        }
        this->salary = salary;
    }

    void Show()
    {
        cout << "Post: " << post << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Salary: " << salary << endl;

    }

};

class Worker : public Human
{
public:
    Worker() {}
    Worker (string post, string name, int age, int salary)
    {
        SetPost(post);
        SetName(name);
        SetAge(age);
        SetSalary(salary);
    }
};

class Boss : public Human
{
private:
    vector <Worker> people;
public:
    Boss() {}
    Boss (string post, string name, int age, int salary)
    {
        SetPost(post);
        SetName(name);
        SetAge(age);
        SetSalary(salary);
    }

    vector <Worker> GetVector ()
    {
        return people;
    }

    void AddWorker (Worker worker)
    {
        people.push_back(worker);
    }

    void ShowSubordinates()
    {

        for (auto i : people) {
            cout << "Post: " << i.GetPost() << endl;
            cout << "Name: " << i.GetName() << endl;
            cout << "Age: " << i.GetAge() << endl;
            cout << "Salary: " << i.GetSalary() << endl;
            cout << endl;
        }
    }
};