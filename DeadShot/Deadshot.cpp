/* 
Игра на выбывание в котором игрок и компьютер ходят по очереди
В зависимости от рандома происходить выстрел либо холостыми либо боевыми патронами
Игрок сам выбирает сложность путем передачи данных
 */

//Импортируем неоходимые модули
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std; //Упрощаем обращение к библеотеке STD

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
            print("--------------------");
            print("Твой ход...");
            print("Нажми enter чтобы выстрелить");
            cin.get(); // Ждем нажатия Enter

            //Проверка на количество холостых патронов
            if (blank_cartridges == 0) {
                print("выстрел боевым патроном.");
                user_live--;
                live_ammunition--;
                print("Твои жизни: ", user_live);

                if (user_live == 0) {
                    print("Вы погибли");
                    break;
                }
            }
            //Если есть патроны оба типа зупускается рандом для выстрела
            else {
                short random_number = (rand() % 2) + 1;
                if (random_number == 1 && blank_cartridges > 0) {
                    print("Ха, повезло! Холостой патрон.");
                    blank_cartridges--;
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
        } 
        
        else {
            print("--------------------");
            print("Ход компьютера... ВЫСТРЕЛ");
            //Проверка на количество холостых патронов            
            if (blank_cartridges == 0) {
                print("Компьютер выстрелил боевым патроном.");
                comp_live--;
                live_ammunition--;
                print("Жизни компьютера: ", comp_live);

                if (comp_live == 0) {
                    print("Компьютер погиб");
                    break;
                }
            } 
            
            //Если есть патроны оба типа зупускается рандом для выстрела
            else {
                short random_number = (rand() % 2) + 1;

                if (random_number == 1 && blank_cartridges > 0) {
                    print("Компьютеру повезло! Холостой патрон.");
                    blank_cartridges--;
                } 
                
                else if (random_number == 2 && live_ammunition > 0) {
                    print("Компьютер выстрелил боевым патроном. Минус жизнь.");
                    comp_live--;
                    live_ammunition--;
                    print("Жизни компьютера: ", comp_live);

                    if (comp_live == 0) {
                        print("Компьютер погиб");
                        break;
                    }
                }
            }
        }

        //Меняем ход путем измение булевого значения
        change_stroke = !change_stroke;
    }

    return 0;
}
