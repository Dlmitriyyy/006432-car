#include <iostream>
#include <string>
using namespace std;

class Engine
{
private:
    string engine_type, fuel_type;
    int horsepower;

public:
    Engine() : engine_type("V6"), fuel_type("Дизель"), horsepower(220) {}

    void Display_engine()
    {
        cout << "Тип двигуна    : " << engine_type << endl;
        cout << "Тип палива     : " << fuel_type << endl;
        cout << "Потужність     : " << horsepower << "HP" << endl;
    }

    void Set_Engine_Info()
    {
        cout << endl << "Введіть тип двигуна: ";
        getline(cin, engine_type);

        cout << endl << "Введіть тип палива: ";
        getline(cin, fuel_type);

        do
        {
            cout << endl << "Введіть потужність двигуна у кінських силах: ";
            cin >> horsepower;

            if (cin.fail())
            {
                cerr << "Помилка. Потужність двигуна повинна бути цілим невід'ємним числом. Нажміть 'Enter' для продовження." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if (horsepower < 40 || horsepower > 1500)
            {
                cerr << "Помилка. Потужність двигуна повинна бути в діапазоні від 40 до 1500HP.  Нажміть 'Enter' для продовження." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (cin.fail() || horsepower < 40 || horsepower > 1500);

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }


};

class Car
{
private:
    int wheels;
    string model, body_type, body_color;
    Engine car_Engine;

public:
    Car() : wheels(4), model("Audi"), body_type("Седан"), body_color("Чорний"), car_Engine() {}

    void Display_car()
    {
        cout << endl << "------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Інформація про автомобіль: ";
        cout << endl << "------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Марка авто     : " << model << endl;
        cout << "Тип кузова     : " << body_type << endl;
        cout << "Колір кузова   : " << body_color << endl;
        cout << "Кількість коліс: " << wheels << endl;
        car_Engine.Display_engine();
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    }

    void Set_Num_Wheels()
    {
        do
        {
            cout << "Введіть кількість колес: ";
            cin >> wheels;

            if (cin.fail())
            {
                cerr << endl << "Помилка. Кількість коліс повинна бути цілим невід'ємним числом. Нажміть 'Enter' для продовження." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if (wheels < 4)
            {
                cerr << endl << "Помилка. Кількість коліс не може бути меншою за 4." << endl << endl;
            }
            else if (wheels > 18)
            {
                cerr << endl << "Помилка. Кількість коліс не може бути більше 18." << endl << endl;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        } while (cin.fail() || wheels < 4 || wheels > 18);
    }

    void Set_Model()
    {
        cout << "Введіть марку авто: ";
        getline(cin, model);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } 

    void Set_Color()
    {
        cout << "Введіть колір авто: ";
        getline(cin, body_color);
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }

    void Set_body_type()
    {
        cout << "Введіть тип кузова: ";
        getline(cin, body_type);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void Set_Engine_Info()
    {
        car_Engine.Set_Engine_Info();
    }

    void Set_Car_Info()
    {
        Set_Model();
        Set_body_type();
        Set_Color();
        Set_Num_Wheels();
        car_Engine.Set_Engine_Info();
    }
};

int main()
{
    system("chcp 1251>nul");

    string choice;

    Car car1;
    Car car2;

    car1.Set_Car_Info();
    car1.Display_car();

    cout << endl << "Авто з конструктора за замовчуванням: " << endl;
    car2.Display_car();

    cout << endl << "Створення Car_3 через копіювання Car_1. Зауважте наступні зміни будуть відноситись до Car_3." << endl;
    Car car3 = car1;

    while (true)
    {
        cout << endl << "Для зміни кількості колес введіть 'Wheels', для зміни моделі 'Model', для зміни кольору 'Color', для зміни типу кузова  'Body', для зміни інформації про двигун 'Engine', для відображення інформації про авто 'Car_1','Car_2','Car_3', для     завершення програми 'Exit': ";
        getline(cin, choice);

        if (choice == "Wheels")
        {
            car3.Set_Num_Wheels();
        }
        else if (choice == "Model")
        {
            car3.Set_Model();
        }
        else if (choice == "Color")
        {
            car3.Set_Color();
        }
        else if (choice == "Body")
        {
            car3.Set_body_type();
        }
        else if (choice == "Engine")
        {
            car3.Set_Engine_Info();
        }
        else if (choice == "Car_1")
        {
            car1.Display_car();
        }
        else if (choice == "Car_2")
        {
            car2.Display_car();
        }
        else if (choice == "Car_3")
        {
            car3.Display_car();
        }
        else if (choice == "Exit")
        {
            cout << endl << "------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "Завершення програми. " << endl;
            cout << "------------------------------------------------------------------------------------------------------------------------" << endl << endl;
            break;
        }
        else
        {
            cerr << endl << "Виникла помилка при вводі. Спробуйте знову." << endl;
        }
    }
    return 0;
}
