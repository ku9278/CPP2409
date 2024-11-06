#include <iostream>
#include <vector>
using namespace std;

class Movie{
private:
    string name;
    float score;
public:
    Movie(string n, float s){
        name = n;
        score = s;
    }
    string getName() { return name; }
    float getScore() { return score; }
    void Print(){
        cout << name << ": " << score << endl;
    }
};

int main(){
    Movie m1("titanic", 9.9);
    Movie m2("gone with the wind", 9.6);
    Movie m3("terminator", 9.7);

    vector<Movie> movies;
    movies.push_back(m1);
    movies.push_back(m2);
    movies.push_back(m3);

    for(Movie m : movies)
        m.Print();
    
    return 0;
}