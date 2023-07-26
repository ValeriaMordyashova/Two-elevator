#include <iostream>
#include <string>

using namespace std;


class ElevatorCabin {
private:
    int floor;
    std::string state;

public:
    ElevatorCabin() : floor(1), state("стоит с закрытыми дверьми") {}

    void pressFloorButton(int destinationFloor) {
        if (destinationFloor >= 1 && destinationFloor <= 20) {
            if (destinationFloor!=floor && destinationFloor!= 15)
                std::cout << "Нажата кнопка этажа " << destinationFloor << std::endl;
            if (destinationFloor >= floor) {
                state = "едет вверх";
            }
            else if (destinationFloor < floor) {
                state = "едет вниз";
            }
            else {
                state = "открывает двери";
            }
            floor = destinationFloor;
            std::cout  << "Состояние: " << state << ", текущий этаж: " << floor << std::endl;
        }
        else {
            std::cout << "Ошибка: введите корректный номер этажа (1-20)" << std::endl;
        }
    }

    void pressOpenButton() {
        state = "открывает двери";
        std::cout << "Нажата кнопка открытия дверей" << std::endl;
        std::cout << "Текущее состояние: " << state << std::endl;
    }

    void OpenDoors() {
        state = "открывает двери";
        cout << "Лифт "<< state<< endl;
    }
    void pressCloseButton() {
        state = "закрывает двери";
        std::cout << "Нажата кнопка закрытия дверей" << std::endl;
        std::cout << "Текущее состояние: " << state << std::endl;
    }

    void pressDispatcherButton() {
        std::cout << "Нажата кнопка вызова диспетчера" << std::endl;
        std::cout << "Текущее состояние: " << state;
        std::cout << " на этаже : " << floor << std::endl;
    }

    void cabinSensorMove() {
        std::cout << "Датчик кабины фиксирует движение между дверьми" << std::endl;
    }

    void cabinSensorNoMove() {
        std::cout << "Датчик кабины фиксирует отсутствие движения между дверьми" << std::endl;
    }
};

class Floor {
private:
    int currentFloor;
    std::string cabin1Status;
    int currentFloorCabin2;
    std::string cabin2Status;
    bool callButtonStatus;

public:
    Floor() : currentFloor(1), cabin1Status("стоит с закрытыми дверьми"),
        currentFloorCabin2(1), cabin2Status("стоит с закрытыми дверьми"), callButtonStatus(false) {}

    void pressCallButton() {
        callButtonStatus = true;
        std::cout << "Нажата кнопка вызова лифта" << std::endl;
        std::cout << "Статус кнопки вызова лифта: " << (callButtonStatus ? "вызван" : "не вызван") << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    ElevatorCabin cabin1;
    Floor floor1;
    cout << "Действие с первым лифтом" << endl;

    cabin1.pressDispatcherButton(); // Нажатие кнопки вызова диспетчера
    floor1.pressCallButton();       // Нажатие кнопки вызова лифта

    cabin1.OpenDoors();             //Открытие дверей
    cabin1.cabinSensorMove();       // Датчик кабины фиксирует движение между дверьми
    cabin1.pressCloseButton();      // Нажатие кнопки закрытия дверей
    cabin1.pressFloorButton(14);     // Нажатие кнопки этажа 14

    cabin1.pressOpenButton();       // Нажатие кнопки открытия дверей
    cabin1.cabinSensorMove();       // Датчик кабины фиксирует движение между дверьми
    
    cout << endl << "Действие с вторым лифтом" << endl;
    ElevatorCabin cabin2;

    cabin2.pressDispatcherButton(); // Нажатие кнопки вызова диспетчера
    floor1.pressCallButton();       // Нажатие кнопки вызова лифта
    cabin2.pressFloorButton(15);    // Нажатие кнопки этажа 15

    cabin2.OpenDoors();             //Открытие дверей
    cabin2.cabinSensorMove();       // Датчик кабины фиксирует движение между дверьми
    cabin2.pressCloseButton();      // Нажатие кнопки закрытия дверей
    
    cabin2.pressFloorButton(1);

    cabin2.pressOpenButton();       // Нажатие кнопки открытия дверей
    cabin2.cabinSensorMove();       // Датчик кабины фиксирует движение между дверьми
    
    return 0;
}
