#include <iostream>
#include <string>
#include <vector>
#include "Human.h"

using namespace std;

void ShowError(string message);

int main() {

    Boss ceo;
    Worker worker1;
    Worker worker2;
    ceo.error = ShowError;
    worker1.error = ShowError;
    worker2.error = ShowError;

    ceo.SetPost("Chef");
    ceo.SetName("Vladimir");
    ceo.SetAge(28);
    ceo.SetSalary(100000000000);

    worker1.SetPost("Mechanic");
    worker1.SetName("Andrey");
    worker1.SetAge(45);
    worker1.SetSalary(23000);

    worker2.SetPost("Welder");
    worker2.SetName("Tikhonovich");
    worker2.SetAge(95);
    worker2.SetSalary(3000);

    ceo.Show();
    cout << endl;


    ceo.AddWorker(worker1);
    ceo.AddWorker(worker2);
    ceo.ShowSubordinates();
    cout << endl;
}

void ShowError(string message)
{
    cout << endl << endl;
    cout << "!!! ERROR !!!" << endl;
    cout << message << endl;
    cout << endl;
}
