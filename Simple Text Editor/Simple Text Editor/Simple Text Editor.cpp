// Simple Text Editor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void displayMenu() {
	cout << "\n Simple Text Editor\n";
	cout << "1. Open File\n";
	cout << "2. Edit File (Append Text)\n";
	cout << "3. Save File\n";
	cout << "4. Exit\n";
	cout << "Choose an option: ";
}

void openFile(const string& filename) {
	ifstream file(filename);
	if (!file.is_open()) {
		cout << "File not found.\n";
		return;
	}

	string line;
	cout << "\n--- File Content ---\n";
	while (getline(file, line)) {
		cout << line << endl;
	}
	cout << "----------------------\n";
	file.close();
}

void editFile(string& contentBuffer) {
	cout << "Enter text (type 'lineend' on a new line to stop editing): \n";
	string line;
	while (true) {
		getline(cin, line);
		if (line == "lineend") break;
		contentBuffer += line + "\n";
	}
}

void saveFile(const string& filename, const string& contentBuffer) {
	ofstream file(filename, ios::app);
	file << contentBuffer;
	file.close();
	cout << "File save succesfully. \n";
}

int main()
{
	string filename;
	string contentBuffer;
	int choice;

	cout << "Enter filename to work with: \n";
	getline(cin, filename);


	do {
		displayMenu();
		cin >> choice;
		cin.ignore();

		switch (choice) {
			case 1:
				openFile(filename);
				break;
			case 2:
				editFile(contentBuffer);
				break;
			case 3:
				saveFile(filename, contentBuffer);
				contentBuffer = " ";
				break;
			case 4:
				cout << "Exiting editor.\n";
				break;
			default: cout << "Invalid choice\n";
		}
	} while (choice != 4); {
		return 0;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
