#include <string>
#include <unordered_map>

using namespace std;

struct Identification {
    int id;
    string color;
    bool status;
};

struct HiveCell {
    int id;
    Identification occupants[2];
    bool emergency_state;
    int adjacent_cell_ids[6];
};

struct Bee {
    Identification id;
};

struct Hornet {
    Identification id;

    void AttackCell(HiveCell &cell); // Function to attack any cell.
};



struct Hive {
    unordered_map<int, HiveCell> cells;
    unordered_map<int, Bee> bees; // Time complexity of locating bee would be 0(1)
    unordered_map<int, Hornet> hornet;
};

int main() {
    return 0;
}
