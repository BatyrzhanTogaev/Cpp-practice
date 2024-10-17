#include <iostream>

using namespace std;

int main() {
    int *nums = new int[2];
    cout << "Введите первое число" << endl;
    cin >> nums[0];
    cout << "Введите второе число" << endl;
    cin >> nums[1];

    char add = '+';
    char sub = '-';
    char mul = '*';
    char div = '/';

    short chouse_operator;
    cout << "Выберите оператор" << endl;
    cout << "1: " << add << endl;
    cout << "2: " << sub << endl;
    cout << "3: " << mul << endl;
    cout << "4: " << div << endl;
    cin >> chouse_operator;
    if (chouse_operator == 1) {
        cout << nums[0] + nums[1] << endl;
    }
    else if (chouse_operator == 2){
        cout << nums[0] - nums[1] << endl;
    }
    else if (chouse_operator == 3){
        cout << nums[0] * nums[1] << endl;
    }
    else if (chouse_operator == 4){
        if (nums[0] == 0 || nums[1] == 0){
            cout << "На 0 делить нельзя" << endl;
        }
        else{
        cout << nums[0] / nums[1] << endl;
        }
    }
    else {
        cout << "Неправльное значение";
    }

    delete[] nums;
    return 0;
}