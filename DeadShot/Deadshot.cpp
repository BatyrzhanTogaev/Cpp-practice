/* 
Игра на выбывание в котором игрок и компьютер ходят по очереди
В зависимости от рандома происходить выстрел либо холостыми либо боевыми патронами
Игрок сам выбирает сложность путем передачи данных
 */

//Импортируем неоходимые модули
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std; //Упрощаем обращение к библеотеке STD

//Фугкция принимает число и останавливает код на заданое время
void pause(short second){
    this_thread::sleep_for(chrono::seconds(second));
}

//Функция принимает данные любого типа и выводить на экран
template <typename T>
void print(T value) {
    cout << value << endl;
}

//Функция принимает две данных любого типа и выводить на экран
template <typename T, typename U>
void print(T message, U value) {
    cout << message << value << endl;
}

int main() {
    /*
    blank_cartridges - Холостые патроны, live_ammunition - Боевые патроны;
    user_live - жизни Игрока, comp_live - жизни Компьютера;
    change_stroke - булевый тип данных для определенние хода;
    */
    short blank_cartridges = 0, live_ammunition = 0;
    short user_live = 0, comp_live = 0;
    bool change_stroke;

    print("Выбери количество холостых патронов");
    cin >> blank_cartridges;

    print("Выбери количество боевых патронов");
    cin >> live_ammunition;
    
    print("Выберите количество Ваших жизней");
    cin >> user_live;
    print("Выберите количество жизней Компьютера");
    cin >> comp_live;

    while (user_live >= live_ammunition && comp_live >= live_ammunition){
        print("Жизни должны меньше чем боевые патроны");
        print("Выберите количество Ваших жизней");
        cin >> user_live;
        print("Выберите количество жизней Компьютера");
        cin >> comp_live;
    }

    print("Хотите начать ход?");
    print("1  - Да");
    print("0 - Нет");
    cin >> change_stroke;


    srand(static_cast<unsigned>(std::time(0))); //инициализирует генератор случайных чисел


    while (user_live > 0 && comp_live > 0) {
        if (change_stroke) {
            pause(1);
            print("--------------------");
            print("Твой ход...");
            print("Нажми enter чтобы выстрелить");
            cin.get(); // Ждем нажатия Enter

            short random_number = (rand() % 2) + 1;
                
            if (random_number == 1) {
                if (blank_cartridges > 0){
                print("Ха, повезло! Холостой патрон.");
                blank_cartridges--;
                }
                else {
                    print("БОЕВООООЙ... минус жизнь");
                    live_ammunition--;
                    user_live--;
                    print("Твои жизни: ", user_live);

                    if (user_live == 0) {
                        print("Вы погибли");
                        break;
                    }
                }
            }
            
            else if (random_number == 2 && live_ammunition > 0) {
                print("Упс, боевой патрон. Минус жизнь.");
                user_live--;
                live_ammunition--;
                print("Твои жизни: ", user_live);

                if (user_live == 0) {
                    print("Вы погибли");
                    break;
                }
            }
            }
        
        else {
            short random_number = (rand() % 2) + 1;
            
            pause(3);
            print("--------------------");
            print("Ход компьютера... ВЫСТРЕЛ");
            

            if (random_number == 1) {
                if (blank_cartridges > 0){
                print("Ха, повезло! Холостой патрон.");
                blank_cartridges--;
                }
                else {
                    print("БОЕВООООЙ... минус жизнь");
                    live_ammunition--;
                    comp_live--;
                    print("Жизни компьютера: ", comp_live);

                    if (user_live == 0) {
                        print("Компьютер погиб");
                        print("Вы выйграли");
                        break;
                    }
                }
            } 
            
            else if (random_number == 2 && live_ammunition > 0) {
                print("Упс, боевой патрон. Минус жизнь.");
                comp_live--;
                live_ammunition--;
                print("Жизни компьютера: ", comp_live);

                if (user_live == 0) {
                    print("Компьютер погиб");
                    print("Вы выйграли");
                    break;
                }
            }
        }

    change_stroke = !change_stroke; //Меняем ход путем измение булевого значения
    }


    return 0;
}
