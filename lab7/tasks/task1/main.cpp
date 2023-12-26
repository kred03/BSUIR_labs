#include "sports.cpp"

int main() {
    Athlete* athletes;
    int size;

    createAthleteArray(athletes, size);

    delete[] athletes;

    menu();

    return 0;
}