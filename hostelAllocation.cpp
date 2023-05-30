#include <iostream>
#include <string>
using namespace std;

class Hostel {
private:
    string* students;//stores the names of the students
    int* roomNumbers;//stores the room numbers allocated
    int totalRooms;//the total number of rooms a student wants to book
public:
//initializing the private data members using the constructor
    Hostel(int rooms) {
        totalRooms = rooms;
      //initializing the length of the array(dynamically allocated using the new keyword)
        students = new string[totalRooms];
        roomNumbers = new int[totalRooms];
    }
//destructor
    ~Hostel() {
        delete[] students;
        delete[] roomNumbers;
    }
//function to allocate the room and the name of the student
    void allocateRoom(int room, string& student) {
        static int i = 0;
        roomNumbers[i] = room;
        students[i] = student;
        i ++;
    }
//function to display the details
    void displayRoomDetails() {
        for (int i = 0; i < totalRooms; i++) {
            cout << "Room " << roomNumbers[i] << ": " << students[i] << endl;
        }
    }
    friend void changeStudentName(Hostel& hostel, int room, string& newName);
};
//friend function to change the hostel room
void changeStudentName(Hostel& hostel, int room, string& newName) {
  for(int i = 0; i < hostel.totalRooms; i ++)
    {
      if(hostel.roomNumbers[i]==room)
      {
    hostel.students[i] = newName;
      }
    }
}

int main() {
    int totalRooms;
    cout << "Enter the total number of rooms: ";
    cin >> totalRooms;

    Hostel hostel(totalRooms);

    for (int i = 0; i < totalRooms; i++) {
        int roomNumber;
        string studentName;
        cout << "Enter room number for student " << i + 1 << ": ";
        cin >> roomNumber;
        cout << "Enter student name for room " << roomNumber << ": ";
        cin.ignore();
        getline(cin, studentName);

        hostel.allocateRoom(roomNumber, studentName);
    }//for loop end

    cout << "\nRoom allocation details:\n";
    hostel.displayRoomDetails();

    int roomToChange;
    string newName;
    cout << "\nEnter room number to change student name: ";
    cin >> roomToChange;
    cout << "Enter new student name: ";
    cin.ignore();
    getline(cin, newName);
//calling friendfunction to change the name of the student allocated for a particular room number
    changeStudentName(hostel, roomToChange, newName);

    cout << "\nUpdated room allocation details:\n";
    hostel.displayRoomDetails();

    return 0;
}//main end
