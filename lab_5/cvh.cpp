#include <iostream>
#include <string>

// Класс Microwave
class Microwave {
private:
    bool isPoweredOn;       // Включена ли печь
    std::string currentMode; // Режим работы
    int timer;              // Таймер (в минутах)

public:
    // Конструктор по умолчанию
    Microwave() : isPoweredOn(false), currentMode("Ожидание"), timer(0) {}

    // Конструктор с параметрами
    Microwave(bool power, std::string mode, int time)
        : isPoweredOn(power), currentMode(mode), timer(time) {}

    // Включение/выключение питания
    void togglePower() {
        isPoweredOn = !isPoweredOn;
        if (!isPoweredOn) {
            currentMode = "Ожидание";
            timer = 0;
        }
    }

    // Установка режима
    void setMode(const std::string& mode) {
        if (!isPoweredOn) {
            std::cout << "Микроволновка выключена. Сначала включите её.\n";
            return;
        }
        if (mode == "Разогрев" || mode == "Разморозка") {
            currentMode = mode;
        } else {
            std::cout << "Неверный режим. Выберите 'Разогрев' или 'Разморозка'.\n";
        }
    }

    // Установка таймера
    void setTimer(int time) {
        if (!isPoweredOn) {
            std::cout << "Микроволновка выключена. Сначала включите её.\n";
            return;
        }
        if (time >= 0 && time <= 60) {
            timer = time;
        } else {
            std::cout << "Неверное время. Установите значение от 0 до 60 минут.\n";
        }
    }

    // Обновление таймера
    void updateTimer() {
        if (isPoweredOn && timer > 0) {
            timer--;
            if (timer == 0) {
                currentMode = "Ожидание";
                std::cout << "Таймер завершён. Микроволновка перешла в режим ожидания.\n";
            }
        }
    }

    // Отображение текущего состояния
    void displayState() const {
        std::cout << "Состояние микроволновки:\n";
        std::cout << "Включена: " << (isPoweredOn ? "Да" : "Нет") << "\n";
        std::cout << "Режим: " << currentMode << "\n";
        std::cout << "Таймер: " << timer << " минут\n";
    }
};

// Функция отображения меню
void displayMenu() {
    std::cout << "\nМеню:\n";
    std::cout << "1. Включить/выключить питание\n";
    std::cout << "2. Установить режим\n";
    std::cout << "3. Установить таймер\n";
    std::cout << "4. Обновить таймер\n";
    std::cout << "5. Показать текущее состояние\n";
    std::cout << "0. Выход\n";
}

// Главная функция программы
int main() {
    Microwave microwave; // Создание объекта
    int choice;

    do {
        displayMenu();
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                microwave.togglePower();
                break;
            case 2: {
                std::string mode;
                std::cout << "Введите режим ('Разогрев' или 'Разморозка'): ";
                std::cin >> mode;
                microwave.setMode(mode);
                break;
            }
            case 3: {
                int time;
                std::cout << "Введите таймер (0-60 минут): ";
                std::cin >> time;
                microwave.setTimer(time);
                break;
            }
            case 4:
                microwave.updateTimer();
                break;
            case 5:
                microwave.displayState();
                break;
            case 0:
                std::cout << "Выход из программы...\n";
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте ещё раз.\n";
        }
    } while (choice != 0);

    return 0;
}

