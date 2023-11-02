#include <iostream>
#include <stdlib.h>

using namespace std;

class CreditManager {

public:
	CreditManager() : credits(0.0) {}

	double getCredits() const {
		return credits;
	}

	void loadCredits(double amount) {
		credits += amount;
		cout << "Beep Card loaded " << amount << " credits. \nTotal credits: P" << credits << endl;
		cout << "\n";
	}

	void makePurchase(double amount) {
		if (amount <= credits) {
			credits -= amount;
			cout << "Ticket purchase successful. P" << amount << " deducted. Remaining balance: P" << credits << endl;
			cout << "\n";
		}
		else {
			cout << "Insufficient credits. Purchase failed." << endl;
		}
	}

private:
	double credits;
};

class MyClass {
public:

	int beepMatrix[13][13] = {
	{13,15,16,18,19,21,22,23,25,26,28,31,33},
	{15,13,15,17,18,19,21,22,24,25,27,29,32},
	{16,15,13,15,16,18,19,20,22,23,26,28,30},
	{18,17,15,13,15,16,17,19,20,22,24,26,29},
	{19,18,16,15,13,14,16,17,19,20,22,24,27},
	{21,19,18,16,14,13,15,16,18,19,21,23,26},
	{22,21,19,17,16,15,13,15,16,18,20,22,25},
	{23,22,20,19,17,16,15,13,15,16,19,21,23},
	{25,24,22,20,19,18,16,15,13,14,17,19,22},
	{26,25,23,22,20,19,18,16,14,13,16,18,21},
	{28,27,26,24,22,21,20,19,17,16,13,15,18},
	{31,29,28,26,24,23,22,21,19,18,15,13,16},
	{33,32,30,29,27,26,25,23,22,21,18,16,13},
	};

	int sjMatrix[13][13] = {
	{0,15,20,20,20,25,25,25,25,30,30,35,35},
	{15,0,15,20,20,20,25,25,25,25,30,30,35},
	{20,15,0,15,20,20,20,20,25,25,30,30,30},
	{20,20,15,0,15,20,20,20,20,25,25,30,30},
	{20,20,20,15,0,15,20,20,20,20,25,25,30},
	{25,20,20,20,15,0,15,20,20,20,25,25,30},
	{25,25,20,20,20,15,0,15,20,20,20,25,25},
	{25,25,20,20,20,20,15,0,15,20,20,25,25},
	{25,25,25,20,20,20,20,15,0,15,20,20,25},
	{30,25,25,25,20,20,20,20,15,0,20,20,25},
	{30,30,30,25,25,25,20,20,20,20,0,15,20},
	{35,30,30,30,25,25,25,25,20,20,15,0,20},
	{35,35,30,30,30,30,25,25,25,25,20,20,0},
	};

	int ticketopt, beep_disc1_ans, beep_disc2_ans, sj_disct1_ans, sj_disc2_ans, entryPoint, station, beep_existing_ans, beep_new_ans;
	void sj_disc2();
	void sj_disc1();
	void beep_existing();
	void beep_disc1();
	void beep_new();
	void beep_disc2();
	void beep_load();
	void welcome();
	void sj_prog();
};

void MyClass::sj_prog() {

	// Display the available train lines and their entry points
	cout << "LRT 2 Stations:" << endl;
	string lrt2Destinations[13] = { "Recto", "Legarda", "Pureza", "V. Mapa", "J. Ruiz", "Gilmore", "Betty Go-Belmonte", "Araneta Center-Cubao", "Anonas", "Katipunan", "Santolan", "Marikina", "Antipolo" };
	for (int i = 0; i < 13; i++) {
		cout << (i + 1) << ". " << lrt2Destinations[i] << endl;
	}

	// Prompt the user to choose an entry point
	cout << "Choose your entry point (1-13): ";
	cin >> entryPoint;
	cout << "\n";

	// Prompt the user to choose a destination
	cout << "Choose your destination (1-13): ";
	cin >> station;
	cout << "\n";

	if (sj_disc2_ans == 1) {
		int sourceIndex = entryPoint - 1;
		int destIndex = station - 1;
		int minCost = sjMatrix[sourceIndex][destIndex];

		cout << "To pay to reach destination: " << minCost - (minCost * 0.20) << " pesos." << endl;
		cout << "\n";
	}
	else if (sj_disc2_ans == 2 || sj_disct1_ans == 2) {
		int sourceIndex = entryPoint - 1;
		int destIndex = station - 1;
		int minCost = sjMatrix[sourceIndex][destIndex];

		cout << "To pay to reach destination: " << minCost << " pesos." << endl;
		cout << "\n";
	}
}

void MyClass::sj_disc2() {

	cout << "-- Would you like to avail a 20% discount for your fare?" << endl;
	cout << "[1] Yes" << endl;
	cout << "[2] No" << endl;
	cout << "Enter your choice: ";
	cin >> sj_disc2_ans;
	cout << "\n";

	if (sj_disc2_ans == 1) {
		sj_prog();
	}
	else if (sj_disc2_ans == 2) {
		sj_prog();
	}
	else {
		cout << "Invalid input. Try again." << endl;
		cout << "\n";
		welcome();
	}
}

void MyClass::sj_disc1() {

	cout << "-- Are you a student, senior citizen, or PWD?" << endl;
	cout << "[1] Yes" << endl;
	cout << "[2] No" << endl; // proceed to main program
	cout << "Enter your choice: ";
	cin >> sj_disct1_ans;
	cout << "\n";

	if (sj_disct1_ans == 1) {
		sj_disc2();
	}
	else if (sj_disct1_ans == 2) {
		sj_prog();
	}
	else {
		cout << "Invalid input. Try again." << endl;
		cout << "\n";
		welcome();
	}
}

void MyClass::beep_existing() {
	cout << "-- Do you have an existing beep card?" << endl;
	cout << "[1] Yes" << endl; // proceed to are you a senior citizen
	cout << "[2] No" << endl; // proceed to would you like to avail a beep card
	cout << "Enter your choice: ";
	cin >> beep_existing_ans;
	cout << "\n";

	if (beep_existing_ans == 1) {
		beep_disc1();
	}
	else if (beep_existing_ans == 2) {
		beep_new();
	}
	else {
		cout << "Invalid input. Try again." << endl;
		cout << "\n";
		welcome();
	}
}

void MyClass::beep_new() {
	cout << "-- Would you like to avail a new beep card? (No discount, P30 Pesos)" << endl;
	cout << "[1] Yes" << endl; // proceed
	cout << "[2] No" << endl; // restart whole program
	cout << "Enter your choice: ";
	cin >> beep_new_ans;
	cout << "\n";
	if (beep_new_ans == 1) {
		beep_disc1();
	}
	else if (beep_new_ans == 2) {
		cout << "Try again." << endl;
		cout << "\n";
		welcome();
	}
	else {
		cout << "Invalid input. Try again." << endl;
		cout << "\n";
		welcome();
	}
}

void MyClass::beep_disc1() {
	cout << "-- Are you a student, senior citizen, or PWD?" << endl;
	cout << "[1] Yes" << endl;
	cout << "[2] No" << endl;
	cout << "Enter your choice: ";
	cin >> beep_disc1_ans;
	cout << "\n";

	if (beep_disc1_ans == 1) {
		beep_disc2();
	}
	else if (beep_disc1_ans == 2) {
		beep_load();
	}
	else {
		cout << "Invalid input. Try again." << endl;
		cout << "\n";
		welcome();
	}
}

void MyClass::beep_disc2() {
	cout << "-- Would you like to avail a new Concessionary Card? (20% discount for fares, P30 Pesos)" << endl;
	cout << "[1] Yes" << endl; // proceed
	cout << "[2] No" << endl; // go back to new beep card
	cout << "Enter your choice: ";
	cin >> beep_disc2_ans;
	cout << "\n";

	if (beep_disc2_ans == 1) {
		beep_load();
	}
	else if (beep_disc2_ans == 2) {
		beep_new();
	}
	else {
		cout << "Invalid input. Try again." << endl;
		cout << "\n";
		welcome();
	}
}

void MyClass::beep_load() {

	CreditManager creditManager;
	int counter = 0; // for deducting Php 30 for availing beep card.

	while (true) {

		cout << "Current Balance: P" << creditManager.getCredits() << endl;
		cout << "Choose an option:" << endl;
		cout << "1. Load/Reload Credits" << endl;
		cout << "2. Go To Station" << endl;
		cout << "3. Exit" << endl;
		cout << "Enter your choice: ";

		int choice;
		cin >> choice;
		cout << "\n";

		switch (choice) {
		case 1: {

			//created a condition to check if new beep card to deduct 30 pesos one time only.
			double amount;

			cout << "Enter the amount to load: ";
			cin >> amount;
			cout << "\n";

			if ((beep_new_ans == 1 || (beep_existing_ans == 1 && beep_disc2_ans == 1)) && counter == 0) {
				// if availing a new beep card or existing that wants to avail concessionary card
				if (amount > 30 && amount < 10000) { // amount to load must be greater than 30 and less than 10k to deduct for availing beep card
					amount = amount - 30;
					cout << "Php 30 deducted for availing a new beep card. " << endl;
					creditManager.loadCredits(amount);
					counter++; //increment 1, this condition will run once only.
				}
				else if (amount >= 10000) {
					amount = 10000 - 30;
					cout << "Max Credit is 10000. " << endl;
					cout << "Php 30 deducted for availing a new beep card. " << endl;
					creditManager.loadCredits(amount);
					counter++; //increment 1, this condition will run once only.

				}
				else { // if not greater than 30
					cout << "Not enough amount to load (Php30 for availing beep card). " << endl;
				}
			}

			else if (creditManager.getCredits() >= 10000) { //check if the credit is more than or equal to 10k
				cout << "Maxed Credit. " << endl;
			}

			// check if the added amount will exceed to 10k and set the credit to 10k
			else if ((creditManager.getCredits() + amount) >= 10000) {
				cout << "Max Credit is 10000. " << endl;
				amount = 10000 - creditManager.getCredits();
				creditManager.loadCredits(amount);
			}

			else if (amount < 10000) {
				creditManager.loadCredits(amount);
			}

			else {
				cout << "Invalid amount. Try again." << endl; // added for invalid input
			}

			break;
		}
		case 2: {

			// Display the available train lines and their entry points
			cout << "LRT 2 Stations:" << endl;
			string lrt2Destinations[13] = { "Recto", "Legarda", "Pureza", "V. Mapa", "J. Ruiz", "Gilmore", "Betty Go-Belmonte", "Araneta Center-Cubao", "Anonas", "Katipunan", "Santolan", "Marikina", "Antipolo" };
			for (int i = 0; i < 13; i++) {
				cout << (i + 1) << ". " << lrt2Destinations[i] << endl;
			}

			// Prompt the user to choose an entry point
			cout << "Choose your entry point (1-13): ";
			cin >> entryPoint;
			cout << "\n";

			// Prompt the user to choose a destination
			cout << "Choose your destination (1-13): ";
			cin >> station;
			cout << "\n";

			if (beep_new_ans == 1 && beep_disc1_ans == 1 && beep_disc2_ans == 1) { //new beep card  and pwd and concessionary

				int sourceIndex = entryPoint - 1;
				int destIndex = station - 1;
				int minCost = beepMatrix[sourceIndex][destIndex];
				int amount = minCost - (minCost * 0.20);

				cout << "Minimum cost to reach destination: " << amount << " pesos." << endl;
				cout << "\n";
				creditManager.makePurchase(amount);
			}
			else if (beep_new_ans == 1 && beep_disc1_ans == 2) { //new beep card and  NOT student, senior, pwd
				int sourceIndex = entryPoint - 1;
				int destIndex = station - 1;
				int minCost = beepMatrix[sourceIndex][destIndex];
				int amount = minCost;

				cout << "Minimum cost to reach destination: " << amount << " pesos." << endl;
				cout << "\n";
				creditManager.makePurchase(amount);
			}
			else if (beep_existing_ans == 1 && beep_disc1_ans == 1 && beep_disc2_ans == 1) { //existing and pwd and concessionary card
				int sourceIndex = entryPoint - 1;
				int destIndex = station - 1;
				int minCost = beepMatrix[sourceIndex][destIndex];
				int amount = minCost - (minCost * 0.20);

				cout << "Minimum cost to reach destination: " << amount << " pesos." << endl;
				cout << "\n";
				creditManager.makePurchase(amount);
			}
			else if (beep_existing_ans == 1 && beep_disc1_ans == 2) { //existing and NOT student,senior,pwd
				int sourceIndex = entryPoint - 1;
				int destIndex = station - 1;
				int amount = beepMatrix[sourceIndex][destIndex];

				cout << "Minimum cost to reach destination: " << amount << " pesos." << endl;
				cout << "\n";
				creditManager.makePurchase(amount);
			}
			break;
		}
		case 3: {
			exit(0);
		}
		default:
			cout << "Invalid choice. Please select a valid option.\n";
			break;
		}
	}
}

void MyClass::welcome() {

	cout << "Welcome to the LRT 2 Ticket Computation System (L2TCS)." << endl;
	cout << "\n";
	cout << "Choose your ticket: " << endl;
	cout << "[1] Single Journey Fare" << endl;
	cout << "[2] Stored Value Card (Beep Card)" << endl;
	cout << "Enter your choice: ";
	cin >> ticketopt;
	cout << "\n";

	if (ticketopt == 1) {
		sj_disc1();
	}
	else if (ticketopt == 2) {
		beep_existing();
	}
	else {
		cout << "Invalid input. Try again." << endl;
		cout << "\n";
		welcome();
	}
}

int main()
{
	// Program signature
	cout << "Name: Cristen Lei D. Tolentino" << endl;
	cout << "Section: TE21" << endl;
	cout << "Activity: Homework #2" << endl;
	cout << "\n" << endl;

	MyClass obj;
	obj.welcome();
	return 0;
}


