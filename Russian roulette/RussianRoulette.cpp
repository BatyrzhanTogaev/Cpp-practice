#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename T>
void print(T value){
    cout << value << endl;
}


int user_choise(){
    print("1. Да");
    print("2. Нет");
    int nums;
    cin >> nums;
    return nums;
}

int main(){
    srand(static_cast<unsigned short>(std::time(0))); //Даем начальное значение на основе текущего времени
    short random_number = (std::rand() % 6) + 1;

    print(random_number);
    cout << random_number << endl;
    print("Хотите ходить первым?");
    int choise = user_choise();
    if (choise == 1){
        if (random_number % 2 == 0){
            print("Вы выйграли");
        }
        else {
            print("Вы проиграли");
        }
    }
        
    return 0;
}