// COMSC-210 | Lab 18 | Xiao Zhang

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Review struct to store rating and comments
struct Review {
    double rating; // Movie rating (0.0 - 5.0)
    string text; // Review text
    Review* next; // Pointer to next review
};

void addToHead(Review*& head, double rating, string& text);
void addToTail(Review*& head, double rating, string& text);
void showAll(Review* head);
double getAvg(Review* head);

int main() {
    Review* head;
    int option;
    double rating;
    string text;
    char more;

    // Pick where to add new nodes
    cout << "Which method to add reviews?\n";
    cout << "    [1] Add to head\n";
    cout << "    [2] Add to tail\n";
    cout << "Choice: ";
    cin >> option;


    do {
        // Get review details
        cout << "Enter rating (0-5): ";
        cin >> rating;

        // Validate rating input
        while (rating < 0.0 || rating > 5.0) {
            cout << "Invalid. Only between 0 to 5: ";
            cin >> rating;
        }

        cin.ignore(); // Skip leftover newline, I learned this online again
        cout << "Enter comments: ";
        getline(cin, text);

        // Add review based on choice
        if (option == 1) {
            addToHead(head, rating, text);
        } else {
            addToTail(head, rating, text);
        }

        cout << "Add another review? Y/N: ";
        cin >> more;

    } while (more == 'Y' || more == 'y');

    // Show reviews and calculate average
    cout << "\nReviews:\n";
    showAll(head);

    double avg = getAvg(head);
    cout << "> Average: " << avg << endl;

    return 0;
}

// Adds new review at head
void addToHead(Review*& head, double rating, string& text) {
    Review* newReview = new Review;
    newReview->rating = rating;
    newReview->text = text;
    newReview->next = head; // Point to old head
    head = newReview; // Set as new head
}

// Adds new review at tail
void addToTail(Review*& head, double rating, string& text) {
    Review* newReview = new Review; // Allocate new node
    newReview->rating = rating;
    newReview->text = text;
    newReview->next = nullptr;

    if (head == nullptr) {
        head = newReview;
    } else {
        Review* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newReview;
    }
}

// Show all reviews
void showAll(Review* head) {
    int num = 1;
    Review* temp = head;
    while (temp != nullptr) {
        cout << "    > Review #" << num << ": " << temp->rating << ": " << temp->text << endl;
        temp = temp->next;
        num++;
    }
}

// Get average rating
double getAvg(Review* head) {
    int count = 0;
    double total = 0.0;
    Review* temp = head;

    // Calculate total and count
    while (temp != nullptr) {
        total += temp->rating;
        count++;
        temp = temp->next;
    }
        return total / count;
    }
