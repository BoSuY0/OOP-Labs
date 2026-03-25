# Laba 3 Minimal Implementation Plan

> **For Claude:** REQUIRED SUB-SKILL: Use superpowers:executing-plans to implement this plan task-by-task.

**Goal:** скоротити лабораторну №3 до мінімальної реалізації, яка все ще виконує вимоги про наслідування та поліморфізм.

**Architecture:** у програмі лишаються тільки `Person` і `Student`. Базовий клас містить спільні поля й віртуальний метод `show()`, а похідний клас додає `specialty` і перевизначає цей метод. `main()` лише демонструє створення об'єктів і поліморфізм через `Person*`.

**Tech Stack:** C++17, `g++`, Markdown

---

### Task 1: Зафіксувати бажану поведінку

**Files:**
- Modify: `/home/tetra/Desktop/Projects/University/OOP/Laba_3/main.cpp`

**Step 1: Write the failing test**

Опис перевірки:
- програма має компілюватися
- у виводі мають бути блоки для `Person` і `Student`
- виклик через `Person*` має виводити інформацію про студента

**Step 2: Run test to verify it fails**

Run: `g++ -std=c++17 /home/tetra/Desktop/Projects/University/OOP/Laba_3/main.cpp -o /tmp/laba3_plan_check && /tmp/laba3_plan_check`

Expected:
- поточна версія проходить компіляцію, але не відповідає новій мінімальній структурі

### Task 2: Переписати `main.cpp`

**Files:**
- Modify: `/home/tetra/Desktop/Projects/University/OOP/Laba_3/main.cpp`

**Step 1: Write the failing test**

Перевірити, що нові очікувані рядки ще відсутні у поточному виводі:

Run: `g++ -std=c++17 /home/tetra/Desktop/Projects/University/OOP/Laba_3/main.cpp -o /tmp/laba3_before && /tmp/laba3_before`

Expected:
- немає точного мінімалістичного виводу нової версії

**Step 2: Write minimal implementation**

- залишити лише `Person`, `Student` і короткий `main()`

**Step 3: Run test to verify it passes**

Run: `g++ -std=c++17 /home/tetra/Desktop/Projects/University/OOP/Laba_3/main.cpp -o /tmp/laba3_after && /tmp/laba3_after`

Expected:
- компіляція без помилок
- короткий вивід із демонстрацією поліморфізму

### Task 3: Переписати `REPORT.md`

**Files:**
- Modify: `/home/tetra/Desktop/Projects/University/OOP/Laba_3/REPORT.md`

**Step 1: Write minimal implementation**

- прибрати все, що не стосується `Person` і `Student`
- залишити код, короткий опис, приклад запуску й відповіді на 2 контрольні питання

**Step 2: Verify content**

Run: `sed -n '1,220p' /home/tetra/Desktop/Projects/University/OOP/Laba_3/REPORT.md`

Expected:
- звіт короткий, відповідає завданню й новому коду

### Task 4: Фінальна перевірка

**Files:**
- Modify: `/home/tetra/Desktop/Projects/University/OOP/Laba_3/main.cpp`
- Modify: `/home/tetra/Desktop/Projects/University/OOP/Laba_3/REPORT.md`

**Step 1: Run verification**

Run: `g++ -std=c++17 -Wall -Wextra -pedantic /home/tetra/Desktop/Projects/University/OOP/Laba_3/main.cpp -o /tmp/laba3_verify && /tmp/laba3_verify`

Expected:
- код компілюється
- вивід показує `Person`, `Student` і поліморфний виклик

**Step 2: Verify report**

Run: `sed -n '1,240p' /home/tetra/Desktop/Projects/University/OOP/Laba_3/REPORT.md`

Expected:
- звіт узгоджений з кодом і без зайвих розділів
