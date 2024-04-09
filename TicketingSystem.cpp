#include <bits/stdc++.h>
using namespace std;

class Ticket {
private:
    vector<int> guests;

public:
    Ticket(vector<int> _guests) : guests(_guests) {}

    void displayTicketDetails() {
        cout << "Ticket Details:" << endl;
        for (int i = 0; i < guests.size(); ++i) {
            cout << "Guest " << i + 1 << " (age: " << guests[i] << ")" << endl;
        }
    }

    vector<int> getGuests() const {
        return guests;
    }

    int calculateTotalCharges() const {
        int totalCharges = 0;
        for (int age : guests) {
            if (age <= 2)
                totalCharges += 0;
            else if (age < 18)
                totalCharges += 100;
            else if (age < 60)
                totalCharges += 500;
            else
                totalCharges += 300;
        }
        return totalCharges;
    }
};

class ZooTicketingSystem {
public:
    static Ticket issueTicket(int numGuests) {
        vector<int> guests;
        int age;
        for (int i = 0; i < numGuests; ++i) {
            cout << "Enter age of guest " << i + 1 << ": " << endl;
            cin >> age;
            guests.push_back(age);
        }
        return Ticket(guests);
    }
};

int main() {
    int numGuests;
    cout << "Enter number of guests: " << endl;
    cin >> numGuests;

    Ticket ticket = ZooTicketingSystem::issueTicket(numGuests);

    int totalCharges = ticket.calculateTotalCharges();

    cout << "Total Charges: INR " << totalCharges << endl;
    ticket.displayTicketDetails();

    // Simulation of security personnel validating the ticket
    cout << "\nSecurity Personnel Ticket Validation:" << endl;
    ticket.displayTicketDetails();

    return 0;
}
