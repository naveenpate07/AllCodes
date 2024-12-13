#include <bits/stdc++.h>
using namespace std;

class parkingVechile {
public:
	string vechileNumber;
	string personName;
	string vechileType;
	time_t entry;
	time_t out;

	parkingVechile(string number, string name, string nameVechile) : vechileNumber(number), personName(name), vechileType(nameVechile), entry(time(0)) {}

	int getAmount() const {
		if (vechileType == "Emergency") return 2;
		if (vechileType == "VIP") return 8;
		else return 1;
	}
};

struct compareVechile {
	bool operator()(const parkingVechile& A, const parkingVechile& B) {
		if (A.vechileType == "Emergency" && B.vechileType != "Emergency") return true;
		if (A.vechileType != "Emergency" && B.vechileType == "Emergency") return false;
		if (A.vechileType == "VIP" && B.vechileType != "VIP") return true;
		if (A.vechileType != "VIP" && B.vechileType == "VIP") return false;
		return false;
	}
};

class Parking {
private:
	int revenue;
	int totalParking;
	queue<parkingVechile> q;
	priority_queue<parkingVechile, vector<parkingVechile>, compareVechile> pq;
	stack<parkingVechile> st;

public:
	Parking(int slots) : totalParking(slots), revenue(0) {}

	void entry(string plateNumber, string pName, string vType) {
		parkingVechile park(plateNumber, pName, vType);
		// if stack is not full and we have vechiles at pq
		while (!pq.empty() && st.size() < totalParking) {
			parkingVechile pqVehicle = pq.top();
			pq.pop();
			st.push(pqVehicle);
		}

		// if stack not full then park the vechiles
		if (st.size() < totalParking) {
			st.push(park);
			cout << "Vehicle parked in the parking .\n";
		}
		// if stack is full
		else {
			if (vType == "Emergency") {
				// replace top vechile with Emergency
				parkingVechile temp = st.top();
				st.pop();
				pq.push(temp);
				st.push(park);
				cout << "Emergency vehicle parked in the parking , replaced the top vehicle.\n";
			}
			// if vip
			else if (vType == "VIP") {
				pq.push(park);
				cout << "VIP vehicle added to the priority queue.\n";
			}
			// else push into queue
			else {
				q.push(park);
				cout << "Normal vehicle added to the waiting queue.\n";
			}
		}
	}

void exits(string vNumber) {
    // Loop until vehicle found and pop the elements and store in another stack for access
    stack<parkingVechile> tempStack;
    while (!st.empty() && st.top().vechileNumber != vNumber) {
        tempStack.push(st.top());
        st.pop();
    }

    // If vehicle found
    if (!st.empty() && st.top().vechileNumber == vNumber) {
        // Set the exit time
        st.top().out = time(0); 

        
        double duration = st.top().out - st.top().entry;  
        int charge = static_cast<int>(duration) * st.top().getAmount(); 

        revenue += charge;
        cout << "Total Revenue now:" << revenue << endl;
        st.pop();
    }

    // Push the temp stack vehicles back into the main stack
    while (!tempStack.empty()) {
        st.push(tempStack.top());
        tempStack.pop();
    }

    // If stack is not full, place the pq vehicles
    while (st.size() < totalParking && !pq.empty()) {
        parkingVechile pqVehicle = pq.top();
        pq.pop();
        st.push(pqVehicle);
    }

    // If stack is not full, place the queue vehicles
    while (st.size() < totalParking && !q.empty()) {
        parkingVechile qVehicle = q.front();
        q.pop();
        st.push(qVehicle);
    }
}


	void showParkingStatus() {
		cout << "Vehicles in the Parking  (Stack):\n";
		if (st.empty()) {
			cout << "Parking bay is empty.\n";
		} else {
			stack<parkingVechile> tempStack = st;
			while (!tempStack.empty()) {
				cout << "Plate Number: " << tempStack.top().vechileNumber << ", Owner: " << tempStack.top().personName
				     << ", Vehicle Type: " << tempStack.top().vechileType << endl;
				tempStack.pop();
			}
		}

		cout << "\nVehicles in the Waiting Queue (Normal Vehicles):\n";
		if (q.empty()) {
			cout << "Waiting queue is empty.\n";
		} else {
			queue<parkingVechile> tempQueue = q;
			while (!tempQueue.empty()) {
				cout << "Plate Number: " << tempQueue.front().vechileNumber<< ", Owner: " << tempQueue.front().personName
				     << ", Vehicle Type: " << tempQueue.front().vechileType << endl;
				tempQueue.pop();
			}
		}

		cout << "\nVehicles in the Priority Queue (VIP & Emergency Vehicles):\n";
		if (pq.empty()) {
			cout << "Priority queue is empty.\n";
		} else {
			priority_queue<parkingVechile, vector<parkingVechile>, compareVechile> tempPQ = pq;
			while (!tempPQ.empty()) {
				cout << "Plate Number: " << tempPQ.top().vechileNumber<< ", Owner: " << tempPQ.top().personName
				     << ", Vehicle Type: " << tempPQ.top().vechileType << endl;
				tempPQ.pop();
			}
		}
	}

	void showRevenue() {
		cout << "Total Revenue: " << revenue << endl;
	}
};

int main() {
	int totalSlots;
	cout << "Enter total number of parking slots: ";
	cin >> totalSlots;

	Parking parkingSystem(totalSlots);

	while (true) {
		cout << "Menu:\n";
		cout << "1. Vehicle Entry\n";
		cout << "2. Vehicle Exit\n";
		cout << "3. Show Parking Status\n";
		cout << "4. Show Total Revenue\n";
		cout << "5. Exit\n";
		int choice;
		cin >> choice;

		if (choice == 1) {
			string plateNumber, personName, vehicleType;
			cout << "Enter Vehicle Plate Number: ";
			cin >> plateNumber;
			cout << "Enter Person Name: ";
			cin >> personName;
			cout << "Enter Vehicle Type (Emergency / VIP / Normal): ";
			cin >> vehicleType;

			parkingSystem.entry(plateNumber, personName, vehicleType);
		}
		else if (choice == 2) {
			string plateNumber;
			cout << "Enter Vehicle Plate Number: ";
			cin >> plateNumber;

			parkingSystem.exits(plateNumber);
		}
		else if (choice == 3) {
			parkingSystem.showParkingStatus();
		}
		else if (choice == 4) {
			parkingSystem.showRevenue();
		}
		else if (choice == 5) {
			break;
		}
		else {
			cout << "Invalid choice! Try again.\n";
		}
	}

	return 0;
}
