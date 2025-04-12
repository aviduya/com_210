#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

// Forward Declaration
struct Node;

// Airport Details
struct Airport {
    string code;
    string location;
    string phone;
};

// Represents a link with the value of the link and a pointer to the destination airport Node.
struct Flight {
    int value;
    Node* destination = nullptr;
};

// Represents an Airport Node
struct Node {
    Airport airport_info;
    unordered_map<string, Flight> flights;
};

// Function to load airport data from a file
void loadAirports(const string & filename, unordered_map<string, Node> & airports) {
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string code, location, phone;
        ss >> code >> location >> phone;
        Airport airport = {code, location, phone};
        Node node = {airport};
        airports[code] = node;
    }
}

// Function to load flight data from a file
void loadFlights(const string & filename, unordered_map<string, Node> & airports) {
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string sourceCode, destinationCode;
        int value;
        ss >> sourceCode >> value >> destinationCode;

        // Ensure both airports exist before adding the flight
        if (airports.find(sourceCode) != airports.end() && airports.find(destinationCode) != airports.end()) {
            Flight flight = {value, &airports[destinationCode]};
            airports[sourceCode].flights[destinationCode] = flight;
        }
    }
}

// Function to display directly connected airports (Phase 1 query)
void displayConnectedAirports(const string & airportCode, const unordered_map<string, Node> & airports) {
    auto it = airports.find(airportCode);
    if (it != airports.end()) {
        cout << "The directly connected airports: ";
        for (const auto & flightPair : it->second.flights) {
            cout << flightPair.first << " ";
        }
        cout << endl;
    } else {
        cout << "Airport code not found!" << endl;
    }
}

// New function to display routes with up to 2 stops (Phase 2 query)
void displayRoutes(const string & query, const unordered_map<string, Node> & airports) {
    // Parse the query; expected format: "FROM-TO"
    size_t dashPos = query.find('-');
    if (dashPos == string::npos) {
        cout << "Invalid query format. Use FROM-TO format." << endl;
        return;
    }

    string from = query.substr(0, dashPos);
    string to = query.substr(dashPos + 1);

    // Verify that both airports exist
    if (airports.find(from) == airports.end()) {
        cout << "From airport " << from << " not found!" << endl;
        return;
    }
    if (airports.find(to) == airports.end()) {
        cout << "To airport " << to << " not found!" << endl;
        return;
    }

    // Containers to store the routes by number of stops
    vector<string> routes0; // Direct flights (0 stops)
    vector<string> routes1; // 1 stop routes
    vector<string> routes2; // 2 stops routes

    // 0 stop: Check for a direct flight from 'from' to 'to'
    if (airports.at(from).flights.find(to) != airports.at(from).flights.end()) {
        routes0.push_back(from + "-" + to);
    }

    // 1 stop: Look for routes from 'from' -> intermediate -> 'to'
    for (const auto & f1 : airports.at(from).flights) {
        string intermediate = f1.first;
        if (intermediate == to) continue;  // Already counted as direct
        if (airports.at(intermediate).flights.find(to) != airports.at(intermediate).flights.end()) {
            routes1.push_back(from + "-" + intermediate + "-" + to);
        }
    }

    // 2 stops: Look for routes from 'from' -> firstStop -> secondStop -> 'to'
    for (const auto & f1 : airports.at(from).flights) {
        string firstStop = f1.first;
        if (firstStop == to) continue;  // Skip direct flight
        for (const auto & f2 : airports.at(firstStop).flights) {
            string secondStop = f2.first;
            // Avoid cycles: ensure that secondStop is not the same as 'from' or firstStop
            if (secondStop == from || secondStop == firstStop) continue;
            // If secondStop equals 'to', then it's a 1 stop route (already counted)
            if (secondStop == to) continue;
            // Check if there's a flight from secondStop to 'to'
            if (airports.at(secondStop).flights.find(to) != airports.at(secondStop).flights.end()) {
                routes2.push_back(from + "-" + firstStop + "-" + secondStop + "-" + to);
            }
        }
    }

    // Display the found routes
    if (!routes0.empty()) {
        cout << "0 stop: ";
        for (const auto & route : routes0) {
            cout << route << " ";
        }
        cout << endl;
    }
    if (!routes1.empty()) {
        cout << "1 stop: ";
        for (const auto & route : routes1) {
            cout << route << " ";
        }
        cout << endl;
    }
    if (!routes2.empty()) {
        cout << "2 stops: ";
        for (const auto & route : routes2) {
            cout << route << " ";
        }
        cout << endl;
    }

    if (routes0.empty() && routes1.empty() && routes2.empty()) {
        cout << "No routes found from " << from << " to " << to << " with up to 2 stops." << endl;
    }
}

// Main
int main() {
    unordered_map<string, Node> airports;

    // Load data from files
    loadAirports("airports.txt", airports);
    loadFlights("flights.txt", airports);

    string input;

    cout << "Enter 'Stop' to end the query." << endl;
    cout << "Enter an airport symbol to display directly connected airports, or" << endl;
    cout << "enter a route query (e.g., LGA-ICN) to display routes with up to 2 stops." << endl;

    while (true) {
        cout << "Enter: ";
        getline(cin, input);

        if (input == "Stop") {
            break;
        }

        // If the input contains a hyphen, assume it's a route query; otherwise, use the airport query.
        if (input.find('-') != string::npos) {
            displayRoutes(input, airports);
        } else {
            displayConnectedAirports(input, airports);
        }
    }

    return 0;
}
