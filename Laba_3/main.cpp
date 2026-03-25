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
