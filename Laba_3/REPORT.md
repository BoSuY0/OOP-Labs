# Лабораторна робота №3
## Тема: Наслідування класів

### Мета роботи
Ознайомитися з наслідуванням, розширенням базового класу та поліморфізмом у C++.

### Код програми
Файл: `main.cpp`

```cpp
#include <iostream>
#include <string>

class Person {
protected:
    std::string name;
    int age;

public:
    Person(const std::string& name, int age) : name(name), age(age) {}
    virtual ~Person() = default;

    virtual void show() const {
        std::cout << "Person: " << name << ", " << age << '\n';
    }
};

class Student : public Person {
    std::string specialty;

public:
    Student(const std::string& name, int age, const std::string& specialty)
        : Person(name, age), specialty(specialty) {}

    void show() const override {
        std::cout << "Student: " << name << ", " << age << ", " << specialty << '\n';
    }
};

int main() {
    Person person("Ivan", 30);
    Student student("Maria", 19, "Computer Science");

    Person* people[] = {&person, &student};

    for (Person* p : people) {
        p->show();
    }

    return 0;
}
```

### Що демонструє програма
- `Person` є базовим класом з полями `name` і `age`.
- `Student` наслідує `Person` через `public` і додає поле `specialty`.
- Конструктор `Student` викликає конструктор `Person` у списку ініціалізації.
- Метод `show()` перевизначається у похідному класі.
- Поліморфізм показано через масив покажчиків `Person*`.

### Приклад виконання

Компіляція:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic -o lab3 main.cpp
```

Запуск:

```bash
./lab3
```

Результат:

```text
Person: Ivan, 30
Student: Maria, 19, Computer Science
```

### Скриншоти
Скриншоти виконання можна зберегти в папці `screenshots/`.

### Відповіді на контрольні питання

**1. У чому полягає перевага наслідування?**  
Наслідування дозволяє повторно використовувати код базового класу та розширювати його без дублювання. Наприклад, `Student` успадковує поля `name` і `age` з `Person` та додає лише власне поле `specialty`.

**2. Як вирішуються конфлікти при множинному наслідуванні?**  
Конфлікти вирішуються явним уточненням, з якого базового класу викликати метод або поле, або перевизначенням цього методу в похідному класі. Для "діамантової проблеми" використовують `virtual` наслідування.
