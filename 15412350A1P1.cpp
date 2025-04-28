/*References:1.https ://stackoverflow.com/questions/69093185/how-to-get-read-text-file-from-a-url-using-c
                Author:Magnus
              2. https://github.com/Arwa-Fawzy/Browser-History-Using-Stack-CPP/blob/main/main.cpp
                 Author: Arwa-Fawzy
               3.  C++ Programming. Publisher: Cengage.
                   Author: D.S. Malik
*/

#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

// Creating a Node structure for the linked stack
struct Node {
    string data;
    Node* next;
    Node(const string& url) : data(url), next(nullptr) {}
};

class BrowserHistoryTracker {
private:
    Node* current; // Pointer to the current page
    Node* backStack; // Linked stack for backward navigation
    Node* forwardStack; // Linked stack for forward navigation

    bool validateURL(const string& url) {
        // Simple regex pattern: starts with "www." and contains at least one period (.)
        regex pattern("www\\..+\\..+");
        return regex_match(url, pattern);
    }

public:
    BrowserHistoryTracker() : current(nullptr), backStack(nullptr), forwardStack(nullptr) {}

    // Function to add a new URL to the history
    void addURL(const string& url);

    // Function to navigate back to the previous URL
    void navigateBack();

    // Function to navigate forward to the next URL
    void navigateForward();

    // Function to read initial URLs from a file
    void readInitialURLs(const string& filename);
};

void BrowserHistoryTracker::addURL(const string& url) {
    // Check if the URL is valid
    if (!validateURL(url)) {
        cout << "Invalid URL format!" << endl;
        return;
    }


void BrowserHistoryTracker::navigateBack() {
    if (backStack == nullptr) {
        cout << "No previous page to navigate back to!" << endl;
        return;
    }

void BrowserHistoryTracker::navigateForward() {
    if (forwardStack == nullptr) {
        cout << "No forward page to navigate to!" << endl;
        return;
    }


void BrowserHistoryTracker::readInitialURLs(const string& filename) {// function implementation to read url from file
    ifstream file(filename);// if file name is found then it will open
    if (file.is_open()) {
        string url;
        while (getline(file, url)) {
            addURL(url);
        }
        file.close();
    }
    else {
        cout << "Unable to open file: " << filename << endl;
    }
}

int main() {
    BrowserHistoryTracker historyTracker;
    historyTracker.readInitialURLs("C:\\Data\\BrowserHistory"); //to read Url from text file

    int choice;
    do {
        cout << "\nMenu:\n1. Add a new URL\n2. Navigate back\n3. Navigate forward\n4. Exit\n";//creating menu
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1: {// using switch cases for user input
            string url;
            cout << "Enter the URL: ";
            cin >> url;
            historyTracker.addURL(url);
            break;
        }
        case 2:
            historyTracker.navigateBack();
            break;
        case 3:
            historyTracker.navigateForward();
            break;
        case 4:
            cout << "Exiting...";
            break;
        default:
            cout << "Invalid choice! Please try again.";
        }
    } while (choice != 4);

    return 0;
}

