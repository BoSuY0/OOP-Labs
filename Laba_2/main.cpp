#include <iostream>
#include <string>

class Student {
private:
    std::string firstName, lastName;
    int age;
public:
    Student(const std::string& f, const std::string& l, int a)
        : firstName(f), lastName(l), age(a) {
        std::cout << "[Конструктор] " << firstName << " " << lastName << "\n";
    }
    ~Student() {
        std::cout << "[Деструктор] " << firstName << " " << lastName << "\n";
    }
    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    int getAge() const { return age; }
    void setFirstName(const std::string& v) { firstName = v; }
    void setLastName(const std::string& v) { lastName = v; }
    void setAge(int v) { age = v; }
    void displayInfo() const {
        std::cout << "Студент: " << firstName << " " << lastName
                  << ", вік: " << age << "\n";
    }
};

int main() {
    Student s1("Олена", "Шевченко", 20);
    Student s2("Андрій", "Коваленко", 18);
    s1.displayInfo();
    s2.displayInfo();
    s1.setAge(21);
    std::cout << "Після зміни: ";
    s1.displayInfo();
    std::cout << "Ім'я: " << s2.getFirstName()
              << ", Прізвище: " << s2.getLastName()
              << ", Вік: " << s2.getAge() << "\n";
    return 0;
}
