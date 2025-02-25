#include <iostream>
#include <iterator>
#include <vector>
#include <string>

using namespace std;

// Forward Declaration
struct Node;

// Airport Details
struct Airport {
    string code;
    string location;
    string phone;
};

// Represents a link with the value of the link and a vector of nodes or node point to the Airports.
struct Flight {
    int value;
    Node* destination = nullptr;
};

// Represents Airport Node
struct Node {
    Airport airport_info;
    vector<Flight> flights;
};

// Sample Run
int main() {
    //Plan to use a vector to store airport objects.
    vector<Node> airports;

    //Init Airport Nodes as test
    Node SFO;
    Node LGA;
    Node ICN;

    SFO.airport_info.code = "SFO";
    SFO.airport_info.location = "San Francisco";
    SFO.airport_info.phone = "(650)821-8211";

    LGA.airport_info.code = "LGA";
    LGA.airport_info.location = "New York";
    LGA.airport_info.phone = "(212) 435-7000";

    ICN.airport_info.code = "ICN";
    ICN.airport_info.location = "Seoul";
    ICN.airport_info.phone = "(82)1577-2600";


    // Assign SFO link to LGA AND ICN with the respected values.
    SFO.flights.push_back({20, &LGA});
    SFO.flights.push_back({30, &ICN});

    LGA.flights.push_back({25, &SFO});
    LGA.flights.push_back({35, &ICN});

    ICN.flights.push_back({40, &SFO});
    ICN.flights.push_back({50, &LGA});

    // Iterate Through SFO Flights vector.
    for (Flight num : SFO.flights) {
        Airport destination = num.destination->airport_info;

        cout << "SFO Flight to: " << destination.code << endl;
        cout << "Cost: $"  << num.value << endl;
        cout << destination.code << " Phone Number: "  << destination.phone << endl;
        cout << destination.code << " Location: " << destination.location << endl;
        cout << endl;
    };



    return 0;
}
