#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Player {
    std::string name;
    int id;
public:
    Player(const std::string& name, int id) : name(name), id(id) {}
    std::string getName() const { return name; }
    int getId() const { return id; }
    void print() const { std::cout << "Player{" << name << ", id=" << id << "}\n"; }
};

class Team {
    std::string teamName;
    std::vector<Player*> players;
public:
    Team(const std::string& name) : teamName(name) {}
    void addPlayer(Player* p) { players.push_back(p); }
    void removePlayer(Player* p) {
        players.erase(std::remove(players.begin(), players.end(), p), players.end());
    }
    void show() const {
        std::cout << "Team: " << teamName << "\n";
        for (auto* p : players) { std::cout << "  "; p->print(); }
    }
};

class Room {
    std::string type;
public:
    Room(const std::string& t) : type(t) {}
    std::string getType() const { return type; }
};

class House {
    std::vector<Room> rooms;
public:
    House() {
        rooms.emplace_back("Bedroom");
        rooms.emplace_back("Kitchen");
        rooms.emplace_back("Bathroom");
    }
    void show() const {
        std::cout << "House has " << rooms.size() << " rooms:\n";
        for (auto& r : rooms) std::cout << "  " << r.getType() << "\n";
    }
};

int main() {
    Player p1("Alice", 1);
    Player p2("Bob", 2);
    Team team("SuperStars");
    team.addPlayer(&p1);
    team.addPlayer(&p2);
    team.show();
    std::cout << "Player p1 exists independently: ";
    p1.print();

    House house;
    house.show();
    return 0;
}
