#include <__config>
#include <iostream>
#include <unordered_map>
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

// Represents a Flight (Edge in the Graph)
struct Flight {
    int value;
    Node* destination = nullptr;
};

// Represents an Airport Node
struct Node {
    Airport airport_info;
    unordered_map<string, Flight> flights;

    // Constructor with initialization list
    Node(string code, string location, string phone) {
        airport_info.code = code;
        airport_info.location = location;
        airport_info.phone = phone;
    }

    // Function to add a flight connection
    void addFlight(int value, Node* destination) {
        flights[destination->airport_info.code] = Flight{value, destination};
    }

    // Function to remove a flight connection
    void removeFlight(string destinationCode) {
        if (flights.find(destinationCode) != flights.end()) {
            flights.erase(destinationCode);
            cout << "Flight to " << destinationCode << " removed successfully.\n";
        } else {
            cout << "No flight found to " << destinationCode << ".\n";
        }
    }
};

// Main
int main() {
    // Creating airport nodes
    Node SFO("SFO", "San Francisco", "(650)821-8211");
    Node LGA("LGA", "New York", "(212) 435-7000");
    Node ICN("ICN", "Seoul", "(82)1577-2600");

    // Adding flights (edges)
    SFO.addFlight(300, &LGA); // Flight from SFO to LGA
    LGA.addFlight(500, &ICN); // Flight from LGA to ICN

    // Print flight details
    cout << "Flight from " << SFO.airport_info.code << " to "
         << SFO.flights["LGA"].destination->airport_info.code
         << " costs $" << SFO.flights["LGA"].value << endl;

    cout << "Flight from " << LGA.airport_info.code << " to "
         << LGA.flights["ICN"].destination->airport_info.code
         << " costs $" << LGA.flights["ICN"].value << endl;





    return 0;
}
