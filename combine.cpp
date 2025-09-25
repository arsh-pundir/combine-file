#include <iostream>
#include <string>
using namespace std;

class Participant {
public:
    string name;
    int score;
    int rank;

    void input() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter score: ";
        cin >> score;
        rank = 1;
    }

    void show() {
        cout << "Name: " << name << " | Score: " << score << " | Rank: " << rank << endl;
    }
};

void swap(Participant &a, Participant &b) {
    Participant temp = a;
    a = b;
    b = temp;
}

int main() {
    Participant p[100];
    int n = 0;
    int choice;

    do {
        cout << "\n------ RANK ANALYZER MENU ------\n";
        cout << "1. Add Students\n";
        cout << "2. Calculate Average, Rank, Highest & Lowest\n";
        cout << "3. Search by Name\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            char more;
            do {
                cout << "\nParticipant " << n + 1 << ":\n";
                p[n].input();
                n++;
                cout << "Add more? (y/n): ";
                cin >> more;
            } while (more == 'y' || more == 'Y');
            break;
        }

        case 2: {
            if (n == 0) {
                cout << "No students added yet.\n";
                break;
            }

            for (int i = 0; i < n; i++) {
                p[i].rank = 1;
                for (int j = 0; j < n; j++) {
                    if (p[j].score > p[i].score)
                        p[i].rank++;
                }
            }

            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < n - i - 1; j++) {
                    if (p[j].rank > p[j + 1].rank) {
                        swap(p[j], p[j + 1]);
                    }
                }
            }

            int total = 0;
            int highest = p[0].score;
            int lowest = p[0].score;

            for (int i = 0; i < n; i++) {
                if (p[i].score > highest) highest = p[i].score;
                if (p[i].score < lowest) lowest = p[i].score;
                total += p[i].score;
            }

            float average = (float)total / n;

            cout << "\n--- RANK LIST (Sorted by Rank) ---\n";
            for (int i = 0; i < n; i++) {
                p[i].show();
            }

            cout << "\nTop Performer(s):\n";
            for (int i = 0; i < n; i++) {
                if (p[i].score == highest)
                    cout << p[i].name << " with score " << p[i].score << "\n";
            }

            cout << "\n--- Participants Grouped by Rank ---\n";
            for (int r = 1; r <= n; r++) {
                cout << "Rank " << r << ": ";
                bool found = false;
                for (int i = 0; i < n; i++) {
                    if (p[i].rank == r) {
                        cout << p[i].name << " ";
                        found = true;
                    }
                }
                if (found)
                    cout << endl;
            }

            cout << "\nHighest Score : " << highest;
            cout << "\nLowest Score  : " << lowest;
            cout << "\nAverage Score : " << average << endl;

            break;
        }

        case 3: {
            if (n == 0) {
                cout << "No students added yet.\n";
                break;
            }
            string searchName;
            cout << "Enter name to search: ";
            cin >> searchName;
            bool found = false;

            for (int i = 0; i < n; i++) {
                if (p[i].name == searchName) {
                    cout << "\nParticipant Found:\n";
                    p[i].show();
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Participant not found.\n";
            break;
        }

        case 4: {
            cout << "Exiting program...\n";
            break;
        }

        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}
DEFAULT ARGUEMENTS:


#include <iostream>
#include <string>
using namespace std;

class Participant {
public:
    string name;
    int score;
    int rank;

    void input() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter score: ";
        cin >> score;
        rank = 1;
    }

    void show() {
        cout << "Name: " << name << "  Score: " << score << "  Rank: " << rank << endl;
    }

    void addStudent(Participant p[], int &n, int count = 1) {
        char more;
        for (int i = 0; i < count; i++) {
            cout << "\nParticipant " << n + 1 << ":\n";
            p[n].input();
            n++;
        }
        cout << "Add more (y/n): ";
        cin >> more;
        if (more == 'y') {
            addStudent(p, n);
        }
    }

    void average(Participant p[], int n, string message = "Average Score") {
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += p[i].score;
        }
        float avg = (float)total / n;
        cout << "\n" << message << ": " << avg << endl;
    }

    void assignRanks(Participant p[], int n, bool display = true) {
        for (int i = 0; i < n; i++) {
            p[i].rank = 1;
            for (int j = 0; j < n; j++) {
                if (p[j].score > p[i].score)
                    p[i].rank++;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (p[j].rank > p[j + 1].rank)
                    swap(p[j], p[j + 1]);
            }
        }

        if (display) {
            cout << "\nRank List:\n";
            for (int i = 0; i < n; i++) {
                p[i].show();
            }

            cout << "\nParticipants Grouped by Rank:\n";
            for (int r = 1; r <= n; r++) {
                bool found = false;
                cout << "Rank " << r << ": ";
                for (int i = 0; i < n; i++) {
                    if (p[i].rank == r) {
                        cout << p[i].name << " ";
                        found = true;
                    }
                }
                if (found) cout << endl;
            }
        }
    }

    void displayHighest(Participant p[], int n) {
        int highest = p[0].score;
        for (int i = 1; i < n; i++) {
            if (p[i].score > highest)
                highest = p[i].score;
        }
        cout << "\nTop Performer(s):\n";
        for (int i = 0; i < n; i++) {
            if (p[i].score == highest)
                cout << p[i].name << " with score " << p[i].score << "\n";
        }
        cout << "Highest Score: " << highest << endl;
    }

    void displayLowest(Participant p[], int n) {
        int lowest = p[0].score;
        for (int i = 1; i < n; i++) {
            if (p[i].score < lowest)
                lowest = p[i].score;
        }
        cout << "Lowest Score: " << lowest << endl;
    }

    void searchName(Participant p[], int n) {
        string searchName;
        cout << "Enter name to search: ";
        cin >> searchName;
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (p[i].name == searchName) {
                cout << "\nParticipant Found:\n";
                p[i].show();
                found = true;
                break;
            }
        }
        if (!found)
            cout << "Participant not found.\n";
    }

    void exitProgram() {
        cout << "Exiting program...\n";
    }
};

int main() {
    Participant p[100];
    int n = 0;
    int choice;

    do {
        cout << "\nRANK ANALYZER MENU\n";
        cout << "1. Add Students\n";
        cout << "2. Calculate Average\n";
        cout << "3. Assign and Display Ranks\n";
        cout << "4. Display Highest Score\n";
        cout << "5. Display Lowest Score\n";
        cout << "6. Search Name\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            p[0].addStudent(p, n);
            break;
        case 2:
            if (n == 0)
                cout << "No students added yet.\n";
            else
                p[0].average(p, n);
            break;
        case 3:
            if (n == 0)
                cout << "No students added yet.\n";
            else
                p[0].assignRanks(p, n);
            break;
        case 4:
            if (n == 0)
                cout << "No students added yet.\n";
            else
                p[0].displayHighest(p, n);
            break;
        case 5:
            if (n == 0)
                cout << "No students added yet.\n";
            else
                p[0].displayLowest(p, n);
            break;
        case 6:
            if (n == 0)
                cout << "No students added yet.\n";
            else
                p[0].searchName(p, n);
            break;
        case 7:
            p[0].exitProgram();
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 7);

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

class Participant {
private:
    string name;
    int score;
    int rank;

public:
    Participant() {
        name = "null";
        score = 0;
        rank = 0;
    }

    Participant(string n, int s) {
        name = n;
        score = s;
        rank = 1;
    }

    Participant(const Participant &p) {
        name = p.name;
        score = p.score;
        rank = p.rank;
    }

    void input() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter score: ";
        cin >> score;
        rank = 1;
    }

    void show() {
        cout << "Name: " << name << "  Score: " << score << "  Rank: " << rank << endl;
    }

    void addStudent(Participant p[], int& n, int count = 2) {
        char more;
        for (int i = 0; i < count; i++) {
            cout << "\nParticipant " << n + 1 << ":\n";
            p[n].input();
            n++;
        }
        cout << "Add more (y/n): ";
        cin >> more;
        if (more == 'y') {
            addStudent(p, n);
        }
    }

    void average(Participant p[], int n, string message = "Average Score") {
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += p[i].score;
        }
        float avg = (float)total / n;
        cout << "\n" << message << ": " << avg << endl;
    }

    void assignRanks(Participant p[], int n, bool display = true) {
        for (int i = 0; i < n; i++) {
            p[i].rank = 1;
            for (int j = 0; j < n; j++) {
                if (p[j].score > p[i].score)
                    p[i].rank++;
            }
        }
        if (display) {
            cout << "\nRank List:\n";
            for (int i = 0; i < n; i++) {
                p[i].show();
            }
        }
    }

    void searchName(Participant p[], int n) {
        string searchName;
        cout << "Enter name to search: ";
        cin >> searchName;
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (p[i].name == searchName) {
                cout << "\nParticipant Found:\n";
                p[i].show();
                found = true;
                break;
            }
        }
        if (!found)
            cout << "Participant not found.\n";
    }

    void exitProgram() {
        cout << "Exiting program\n";
    }

    friend void compareParticipants(const Participant, const Participant);
};

void compareParticipants(const Participant p1, const Participant p2) {
    cout << "\nComparing First Two Participants:\n";
    cout << p1.name << " (Score: " << p1.score << ") vs "
         << p2.name << " (Score: " << p2.score << ")\n";

    if (p1.score > p2.score)
        cout << p1.name << " has a higher score.\n";
    else if (p2.score > p1.score)
        cout << p2.name << " has a higher score.\n";
    else
        cout << "Both have equal scores.\n";
}

int main() {
    Participant p[100];
    int n = 0;
    int choice;

    do {
        cout << "\nRANK ANALYZER MENU\n";
        cout << "1. Add Students\n";
        cout << "2. Calculate Average\n";
        cout << "3. Assign and Display Ranks\n";
        cout << "4. Search Name\n";
        cout << "5. Exit\n";
        cout << "6. Compare First Two Participants (Friend Function)\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            p[0].addStudent(p, n);
            break;
        case 2:
            if (n == 0)
                cout << "No students added yet.\n";
            else
                p[0].average(p, n);
            break;
        case 3:
            if (n == 0)
                cout << "No students added yet.\n";
            else
                p[0].assignRanks(p, n);
            break;
        case 4:
            if (n == 0)
                cout << "No students added yet.\n";
            else
                p[0].searchName(p, n);
            break;
        case 5:
            p[0].exitProgram();
            break;
        case 6:
            if (n < 2)
                cout << "At least 2 students required to compare.\n";
            else
                compareParticipants(p[0], p[1]);
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}


#include <iostream>
#include <string>
using namespace std;

class Participant {
private:
    string name;
    int score;
    int rank;

public:
    Participant() {
        name = "";
        score = 0;
        rank = 0;
    }

    Participant(string n, int s) {
        name = n;
        score = s;
        rank = 1;
    }

    Participant(const Participant &p) {
        name = p.name;
        score = p.score;
        rank = p.rank;
    }

    void input() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter score: ";
        cin >> score;
        rank = 1;
    }

    void show() {
        cout << "Name: " << name << "  Score: " << score << "  Rank: " << rank << endl;
    }

    void addStudent(Participant p[], int& n, int count = 2) {
        char more;
        for (int i = 0; i < count; i++) {
            cout << "\nParticipant " << n + 1 << ":\n";
            p[n].input();
            n++;
        }
        cout << "Add more (y/n): ";
        cin >> more;
        if (more == 'y') {
            addStudent(p, n);
        }
    }

    void average(Participant p[], int n, string message = "Average Score") {
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += p[i].score;
        }
        float avg = (float)total / n;
        cout << "\n" << message << ": " << avg << endl;
    }

    void assignRanks(Participant p[], int n, bool display = true) {
        for (int i = 0; i < n; i++) {
            p[i].rank = 1;
            for (int j = 0; j < n; j++) {
                if (p[j].score > p[i].score)
                    p[i].rank++;
            }
        }
        if (display) {
            cout << "\nRank List:\n";
            for (int i = 0; i < n; i++) {
                p[i].show();
            }
        }
    }

    void searchName(Participant p[], int n) {
        string searchName;
        cout << "Enter name to search: ";
        cin >> searchName;
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (p[i].name == searchName) {
                cout << "\nParticipant Found:\n";
                p[i].show();
                found = true;
                break;
            }
        }
        if (!found)
            cout << "Participant not found.\n";
    }

    void exitProgram() {
        cout << "Exiting program\n";
    }

    friend void compareParticipants(const Participant, const Participant);
};

void compareParticipants(const Participant p1, const Participant p2) {
    cout << "\nComparing First Two Participants:\n";
    cout << p1.name << " (Score: " << p1.score << ") vs "
         << p2.name << " (Score: " << p2.score << ")\n";

    if (p1.score > p2.score)
        cout << p1.name << " has a higher score.\n";
    else if (p2.score > p1.score)
        cout << p2.name << " has a higher score.\n";
    else
        cout << "Both have equal scores.\n";
}

int main() {
    Participant p[100];
    int n = 0;
    int choice;

    do {
        cout << "\nRANK ANALYZER MENU\n";
        cout << "1. Add Students\n";
        cout << "2. Calculate Average\n";
        cout << "3. Assign and Display Ranks\n";
        cout << "4. Search Name\n";
        cout << "5. Exit\n";
        cout << "6. Compare First Two Participants \n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            p[0].addStudent(p, n);
            break;
        case 2:
            if (n == 0)
                cout << "No students added yet.\n";
            else
                p[0].average(p, n);
            break;
        case 3:
            if (n == 0)
                cout << "No students added yet.\n";
            else
                p[0].assignRanks(p, n);
            break;
        case 4:
            if (n == 0)
                cout << "No students added yet.\n";
            else
                p[0].searchName(p, n);
            break;
        case 5:
            p[0].exitProgram();
            break;
        case 6:
            if (n < 2)
                cout << "At least 2 students required to compare.\n";
            else
                compareParticipants(p[0], p[1]);
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}

#include <iostream>
using namespace std;

class Patient {
public:
    double calculateBill(int days) {
        return days * 500;
    }

    double calculateBill(int days, char roomType) {
        double rate;
        if(roomType == 'S') rate = 1000;
        else if(roomType == 'D') rate = 700;
        else rate = 500;
        return days * rate;
    }

    double calculateBill(int days, char roomType, double testsCost) {
        return calculateBill(days, roomType) + testsCost;
    }
};

int main() {
    Patient p;
    int days;
    char roomType;
    double testsCost;

    cout << "Enter number of days admitted: ";
    cin >> days;
    cout << "Enter room type (S=Single, D=Double, G=General): ";
    cin >> roomType;
    cout << "Enter total cost of tests: ";
    cin >> testsCost;

    double totalBill = p.calculateBill(days, roomType, testsCost);

    cout << "Total hospital bill: Rs " << totalBill << endl;

    return 0;
}
#include <iostream>
using namespace std;

class Patient {
public:
    double calculateBill(int days) {
        return days * 500;
    }

    double calculateBill(int days, char roomType) {
        double rate;
        if(roomType == 'S') rate = 1000;
        else if(roomType == 'D') rate = 700;
        else rate = 500;
        return days * rate;
    }

    double calculateBill(int days, char roomType, double testsCost) {
        return calculateBill(days, roomType) + testsCost;
    }
};

int main() {
    Patient p;
    int days;
    char roomType;
    double testsCost;

    cout << "Enter number of days admitted: ";
    cin >> days;
    cout << "Enter room type (S=Single, D=Double, G=General): ";
    cin >> roomType;
    cout << "Enter total cost of tests: ";
    cin >> testsCost;

    double totalBill = p.calculateBill(days, roomType, testsCost);

    cout << "Total hospital bill: Rs " << totalBill << endl;

    return 0;
}


#include <iostream>
using namespace std;

class Patient {
public:
    double calculateBill(int days) {
        return days * 500;
    }

    double calculateBill(int days, char roomType) {
        double rate;
        if(roomType == 'S') rate = 1000;
        else if(roomType == 'D') rate = 700;
        else rate = 500;
        return days * rate;
    }

    double calculateBill(int days, char roomType, double testsCost) {
        return calculateBill(days, roomType) + testsCost;
    }
};

int main() {
    Patient p;
    int days;
    char roomType;
    double testsCost;

    cout << "Enter number of days admitted: ";
    cin >> days;
    cout << "Enter room type (S=Single, D=Double, G=General): ";
    cin >> roomType;
    cout << "Enter total cost of tests: ";
    cin >> testsCost;

    double totalBill = p.calculateBill(days, roomType, testsCost);

    cout << "Total hospital bill: Rs " << totalBill << endl;

    return 0;
}
#include <iostream>
using namespace std;

class Patient {
public:
    double calculateBill(int days) {
        return days * 500;
    }

    double calculateBill(int days, char roomType) {
        double rate;
        if(roomType == 'S') rate = 1000;
        else if(roomType == 'D') rate = 700;
        else rate = 500;
        return days * rate;
    }

    double calculateBill(int days, char roomType, double testsCost) {
        return calculateBill(days, roomType) + testsCost;
    }
};

int main() {
    Patient p;
    int days;
    char roomType;
    double testsCost;

    cout << "Enter number of days admitted: ";
    cin >> days;
    cout << "Enter room type (S=Single, D=Double, G=General): ";
    cin >> roomType;
    cout << "Enter total cost of tests: ";
    cin >> testsCost;

    double totalBill = p.calculateBill(days, roomType, testsCost);

    cout << "Total hospital bill: Rs " << totalBill << endl;

    return 0;
}

binary operator overloading:

#include <iostream>
using namespace std;

class MedicineStock {
public:
    int tablets, syrups;

    MedicineStock(int t = 0, int s = 0) {
        tablets = t;
        syrups = s;
    }

    MedicineStock operator + (const MedicineStock& other) {
        MedicineStock result;
        result.tablets = tablets + other.tablets;
        result.syrups = syrups + other.syrups;
        return result;
    }

    MedicineStock operator - (const MedicineStock& other) {
        MedicineStock result;
        result.tablets = tablets - other.tablets;
        result.syrups = syrups - other.syrups;
        return result;
    }

    void display() {
        cout << "Tablets: " << tablets << ", Syrups: " << syrups << endl;
    }
};

int main() {
    int t1, s1, t2, s2;

    cout << "Enter stock for Pharmacy (Tablets Syrups): ";
    cin >> t1 >> s1;

    cout << "Enter stock delivered to pharmacy (Tablets Syrups): ";
    cin >> t2 >> s2;

    MedicineStock pharmacyStock(t1, s1);
    MedicineStock deliveredStock(t2, s2);

    MedicineStock updatedStock = pharmacyStock + deliveredStock;
    cout << "\nStock after delivery: ";
    updatedStock.display();

    cout << "\nEnter stock transferred to another pharmacy (Tablets Syrups): ";
    cin >> t2 >> s2;
    MedicineStock transferStock(t2, s2);

    MedicineStock remainingStock = updatedStock - transferStock;
    cout << "\nRemaining stock after transfer: ";
    remainingStock.display();

    return 0;
}

#include <iostream>
#include <string>
using namespace std;


class Patient {
protected:
    string name;
    int age;
public:
    void inputPatientDetails() {
        cout << "Enter Patient Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
    }

    void displayPatientDetails() {
        cout << "\nPatient Name: " << name;
        cout << "\nAge: " << age;
    }
};


class MedicalTest {
protected:
    float bp;      
    float sugar;    
    float temp;   
public:
    void inputTestResults() {
        cout << "Enter Blood Pressure (mmHg): ";
        cin >> bp;
        cout << "Enter Blood Sugar (mg/dL): ";
        cin >> sugar;
        cout << "Enter Body Temperature (°F): ";
        cin >> temp;
    }

    void displayTestResults() {
        cout << "\nBlood Pressure: " << bp << " mmHg";
        cout << "\nBlood Sugar: " << sugar << " mg/dL";
        cout << "\nTemperature: " << temp << " °F";
    }
};


class Report : public Patient, public MedicalTest {
public:
    void displayReport() {
       

        cout << "\n\n--- Health Analysis ---";

        
        if (bp > 140)
            cout << "\nHigh Blood Pressure detected!";
        else if (bp < 90)
            cout << "\nLow Blood Pressure detected!";
        else
            cout << "\nBlood Pressure is Normal.";

        if (sugar > 140)
            cout << "\nHigh Sugar Level detected!";
        else if (sugar < 70)
            cout << "\nLow Sugar Level detected!";
        else
            cout << "\nSugar Level is Normal.";

        if (temp > 99.5)
            cout << "\nFever Detected!";
        else
            cout << "\nTemperature is Normal.";
    }
};


int main() {
    Report r;
    cout << "=== Enter Patient Details ===\n";
    r.inputPatientDetails();
    cout << "\n=== Enter Medical Test Results ===\n";
    r.inputTestResults();

    cout << "\n=== Patient Medical Report ===\n";
    r.displayReport();

    return 0;
}








