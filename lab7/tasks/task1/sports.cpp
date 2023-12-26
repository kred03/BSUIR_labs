#include <iostream>
#include "func.h"

bool isOnlyLetters(const std::string& str) {
    for (char c : str) {
        if (!std::isalpha(c)) {
            return false;
        }
    }
    return true;
}

void createAthleteArray(Athlete*& athletes, int& size) {
    std::cout << "Enter the number of athletes: ";
    while (!(std::cin >> size) || size <= 0) {
        std::cout << "Invalid input. Please enter a positive number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    athletes = new Athlete[size];

    for (int i = 0; i < size; ++i) {
        std::cout << "Enter details for Athlete " << i + 1 << ":\n";
        std::cout << "Country: ";
        std::cin.ignore();
        std::getline(std::cin, athletes[i].country);

        while (!isOnlyLetters(athletes[i].country)) {
            std::cout << "Invalid input. Please enter letters only: ";
            std::getline(std::cin, athletes[i].country);
        }

        std::cout << "Team: ";
        std::cin.ignore();
        std::getline(std::cin, athletes[i].team);

        std::cout << "Full Name: ";
        std::getline(std::cin, athletes[i].fullName);

        while (!isOnlyLetters(athletes[i].fullName)) {
            std::cout << "Invalid input. Please enter letters only: ";
            std::getline(std::cin, athletes[i].fullName);
        }

        std::cout << "Jersey Number: ";
        while (!(std::cin >> athletes[i].jerseyNumber) || athletes[i].jerseyNumber <= 0) {
            std::cout << "Invalid input. Please enter a positive number: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "Age: ";
        while (!(std::cin >> athletes[i].age) || athletes[i].age <= 0) {
            std::cout << "Invalid input. Please enter a positive number: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "Height: ";
        while (!(std::cin >> athletes[i].height) || athletes[i].height <= 0) {
            std::cout << "Invalid input. Please enter a positive number: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "Weight: ";
        while (!(std::cin >> athletes[i].weight) || athletes[i].weight <= 0) {
            std::cout << "Invalid input. Please enter a positive number: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void viewAthleteArray(const Athlete* athletes, int size) {
    if (athletes == nullptr || size <= 0) {
        std::cout << "Invalid athlete array or size.\n";
        return;
    }

    std::cout << "Athlete Details:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << "Athlete " << i + 1 << ":\n";
        std::cout << "Country: " << athletes[i].country << "\n";
        std::cout << "Team: " << athletes[i].team << "\n";
        std::cout << "Full Name: " << athletes[i].fullName << "\n";
        std::cout << "Jersey Number: " << athletes[i].jerseyNumber << "\n";
        std::cout << "Age: " << athletes[i].age << "\n";
        std::cout << "Height: " << athletes[i].height << "\n";
        std::cout << "Weight: " << athletes[i].weight << "\n\n";
    }
}

void addAthlete(Athlete*& athletes, int& size) {
    Athlete* tempArray = new Athlete[size + 1];
    for (int i = 0; i < size; ++i) {
        tempArray[i] = athletes[i];
    }

    std::cout << "Enter details for the new athlete:\n";

    std::cout << "Country: ";
    std::cin.ignore();
    std::getline(std::cin, tempArray[size].country);
    while (!isOnlyLetters(tempArray[size].country)) {
        std::cout << "Invalid input. Please enter a valid country name (letters only): ";
        std::getline(std::cin, tempArray[size].country);
    }

    std::cout << "Team: ";
    std::getline(std::cin, tempArray[size].team);

    std::cout << "Full Name: ";
    std::getline(std::cin, tempArray[size].fullName);
    while (!isOnlyLetters(tempArray[size].fullName)) {
        std::cout << "Invalid input. Please enter a valid full name (letters only): ";
        std::getline(std::cin, tempArray[size].fullName);
    }

    std::cout << "Jersey Number: ";
    while (!(std::cin >> tempArray[size].jerseyNumber) || tempArray[size].jerseyNumber <= 0) {
        std::cout << "Invalid input. Please enter a positive number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Age: ";
    while (!(std::cin >> tempArray[size].age) || tempArray[size].age <= 0) {
        std::cout << "Invalid input. Please enter a positive number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Height: ";
    while (!(std::cin >> tempArray[size].height) || tempArray[size].height <= 0) {
        std::cout << "Invalid input. Please enter a positive number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Weight: ";
    while (!(std::cin >> tempArray[size].weight) || tempArray[size].weight <= 0) {
        std::cout << "Invalid input. Please enter a positive number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    delete[] athletes;
    athletes = tempArray;
    size++;
}

void searchAthlete(const Athlete* athletes, int size, int searchAge) {
    bool found = false;

    std::cout << "Athletes with age greater than " << searchAge << ":\n";

    for (int i = 0; i < size; ++i) {
        if (athletes[i].age > searchAge) {
            std::cout << athletes[i].fullName << "\n";
            found = true;
        }
    }

    if (!found) {
        std::cout << "No athletes found with age greater than " << searchAge << "\n";
    }
}

void deleteAthlete(Athlete*& athletes, int& size, int searchAge) {
    int deleteCount = 0;

    for (int i = 0; i < size; ++i) {
        if (athletes[i].age > searchAge) {
            deleteCount++;
        }
    }

    if (deleteCount == 0) {
        std::cout << "No athletes found with age greater than " << searchAge << ". Deletion aborted.\n";
        return;
    }

    Athlete* tempArray = new Athlete[size - deleteCount];
    int index = 0;

    for (int i = 0; i < size; ++i) {
        if (athletes[i].age <= searchAge) {
            tempArray[index] = athletes[i];
            index++;
        }
    }

    delete[] athletes;
    athletes = tempArray;
    size -= deleteCount;

    std::cout << "Deletion completed. " << deleteCount << " athletes removed.\n";
}

void shellSort(Athlete* athletes, int size) {
    int gap, i, j;
    Athlete temp;

    for (gap = size / 2; gap > 0; gap /= 2) {
        for (i = gap; i < size; ++i) {
            temp = athletes[i];

            for (j = i; j >= gap && athletes[j - gap].age < temp.age; j -= gap) {
                athletes[j] = athletes[j - gap];
            }

            athletes[j] = temp;
        }
    }
}

void sortAthleteArray(Athlete* athletes, int size) {
    shellSort(athletes, size);

    std::cout << "Athlete Details (Sorted by Age in Descending Order):\n";
    for (int i = 0; i < size; ++i) {
        std::cout << "Athlete " << i + 1 << ":\n";
        std::cout << "Country: " << athletes[i].country << "\n";
        std::cout << "Team: " << athletes[i].team << "\n";
        std::cout << "Full Name: " << athletes[i].fullName << "\n";
        std::cout << "Jersey Number: " << athletes[i].jerseyNumber << "\n";
        std::cout << "Age: " << athletes[i].age << "\n";
        std::cout << "Height: " << athletes[i].height << "\n";
        std::cout << "Weight: " << athletes[i].weight << "\n\n";
    }
}

void menu() {
    Athlete* athletes = nullptr;
    int size = 0;
    int choice;
    int searchAge;

    do {
        std::cout << "Menu:\n";
        std::cout << "1. Create Athlete Array\n";
        std::cout << "2. View Athlete Array\n";
        std::cout << "3. Add Athlete\n";
        std::cout << "4. Search Athlete by Age\n";
        std::cout << "5. Delete Athlete by Age\n";
        std::cout << "6. Sort Athlete Array by Age\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";

        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Aborting.\n";
            delete[] athletes;
            return;
        }

        switch (choice) {
        case 1:
            createAthleteArray(athletes, size);
            break;
        case 2:
            viewAthleteArray(athletes, size);
            break;
        case 3:
            addAthlete(athletes, size);
            break;
        case 4:
            std::cout << "Enter the age to search: ";
            if (!(std::cin >> searchAge)) {
                std::cout << "Invalid input. Aborting.\n";
                delete[] athletes;
                return;
            }
            searchAthlete(athletes, size, searchAge);
            break;
        case 5:
            std::cout << "Enter the age to delete: ";
            if (!(std::cin >> searchAge)) {
                std::cout << "Invalid input. Aborting.\n";
                delete[] athletes;
                return;
            }
            deleteAthlete(athletes, size, searchAge);
            break;
        case 6:
            sortAthleteArray(athletes, size);
            break;
        case 7:
            std::cout << "Exiting program...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }

        std::cout << "\n";
    } while (choice != 7);

    delete[] athletes;
}