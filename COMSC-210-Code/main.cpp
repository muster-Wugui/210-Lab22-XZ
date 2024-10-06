// COMSC-210 | Lab 19 | Xiao Zhang

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

struct Review {
    float score;
    string note;
    Review* next;
    Review(float s, const string& n) : score(s), note(n), next(nullptr) {} //constructor
};

// Movie class to hold movie details and reviews
class Movie {
public:
    string name;
    Review* reviews;
    Movie(const string& movieName) : name(movieName), reviews(nullptr) {}
    //destructor
    ~Movie() {
        while (reviews != nullptr) {
            Review* temp = reviews;
            reviews = reviews->next;
            delete temp;
        }
    }

    // Add review at the start of the list
    void addReview(float score, const string& note) {
        Review* newReview = new Review(score, note);
        newReview->next = reviews;
        reviews = newReview;
    }

    // Show all reviews
    void showReviews() {
        cout << "Reviews for: " << name << endl;
        Review* temp = reviews;
        while (temp != nullptr) {
            cout << "  - " << temp->score << ": " << temp->note << endl;
            temp = temp->next;
        }
    }
};

float randrating();
void defaltR(Movie& movie);
int main() {
    srand(static_cast<unsigned int>(time(0)));  // Seed for random numbers

    Movie movie1("The Matrix");
    Movie movie2("Inception");

    // If no files, add some default reviews
    defaltR(movie1);
    defaltR(movie2);

    movie1.showReviews();
    movie2.showReviews();

    return 0;
}

// Get random score between 1.0 and 5.0
float randrating() {
    return static_cast<float>(rand() % 41 + 10) / 10.0;
}

// Add some default reviews if I don't have files
void defaltR(Movie& movie) {
    string Dcomments[] = {
        "Great storyline!",
        "Loved the characters.",
        "Amazing visual.",
        "want to watch it again!",
    };
    for (int i = 0; i < 3; ++i) {  // Add three reviews randomly
        float score = randrating();
        movie.addReview(score, Dcomments[i % 5]);
    }
}


