using namespace std;
#include <iostream>
#include <cstdlib>
#include <string>
class Booking {
public:
	Booking();

	void printStatus();
	int getid() { return id; }
	int getreserved(){ return reserved; }
	int getcapacity(){ return capacity; }
	void edit(int nid, int res);
	void create(int nid, int cap);
	void deleteF();
	bool reserveSeats(int number_ob_seats);
	bool cancelReservations(int number_ob_seats);
  void cancel(int nid, int res);
	bool valid();
private:
	int id;
	int capacity;
	int reserved;
};
Booking::Booking()
{
	id = 0; capacity = 0; reserved = 0;
}
void Booking::printStatus()
{
	int per = (double)getreserved() / (double)getcapacity() * 100;

	cout << "Booking " << getid() << ": " << getreserved() << "/" << getcapacity() << "(" << per << "%) seats taken" << endl;
}
bool Booking::reserveSeats(int seats)
{
	if (getreserved() + seats > getcapacity() * 1.05)
		return false;
	else
		return true;
}


bool Booking::cancelReservations(int seats)
{
	if (getreserved() - seats >= 0)
		return true;
	else
		return false;
}

void Booking::edit(int nid, int res)
{
	if (res < 0){
		res = 0;
	}

	reserved = reserved + res;

	int per = (double)getreserved() / (double)getcapacity() * 100;
	while (per > 105)
	{
		reserved--;
		per = (double)reserved / (double)capacity * 100;
	}
}
bool Booking::valid()
{
	if (id == 0)
		return false;
	else
		return true;
}
void Booking::create(int nid, int cap)
{
	id = nid;
	capacity = cap;
}
void Booking::deleteF()
{
	id = 0;
	capacity = 0;
	reserved = 0;
}
void Booking::cancel(int nid, int res)
{
	if (res < 0){
		res = 0;
	}

	reserved = reserved - res;

	int per = (double)getreserved() / (double)getcapacity() * 100;
	while (per > 105)
	{
		reserved--;
		per = (double)reserved / (double)capacity * 100;
	}
}

// ...

int main() {
  int n = 0;
  int flight;
  int reserved = 0;
  int capacity = 0;
  bool check;
  Booking booking[10];
  for (int i = 0; i < 10; i++){
    booking[i] = Booking();
  }   
  Booking shipbooking[10];
  for (int i = 0; i < 10; i++){
    shipbooking[i] = Booking();
  } 
  Booking busbooking[10];
  for (int i = 0; i < 10; i++){
    busbooking[i] = Booking();
  } 
  bool johann = true;
  while (johann = true){
    string val = "";
    cout << "Valmynd : " << endl << "1. Flights" << endl << "2. Ships" << endl << "3. Busses" << endl << "0. Quit" << endl;
    cin >> val;   
    bool petur = true; 
    while (petur = true)
    {
      if (val == "1"){
        for (int i = 0; i < 10; i++){
          if (booking[i].valid()){
            check = true;
          }
        }
        if (check == 0){
          cout << "No flights in system." << endl;
        }
        else{
          for (int i = 0; i < 10; i++){
            if (booking[i].valid())
            booking[i].printStatus();
          }
        }
        string command = "";
        cout << "What would you like to do?: ";
        cin >> command;
        if (command == "add"){
          cout << "Which flight?" << endl;
          cin >> flight;
          cout << "How many seats?" << endl;
          cin >> n;
          for (int i = 0; i < 10; i++){
            if (booking[i].getid() == flight){
              if (booking[i].reserveSeats(n) == 1)
                booking[i].edit(flight, reserved + n);
              else
                cout << "Cannot perform this operation, the reserved seats exceed 105% of available seats" << endl;
                break;
            }
          }
          cin.ignore();
        }
        else if (command == "cancel"){
          cout << "Which flight?" << endl;
          cin >> flight;
          cout << "How many seats?" << endl;
          cin >> n;

          for (int i = 0; i < 10; i++){
            if (booking[i].getid() == flight){
              if (booking[i].cancelReservations(n) == true)
                booking[i].cancel(flight, n);
              else
                cout << "Cannot perform this operation" << endl;
              break;
            }
          }
          cin.ignore();
        }
        else if (command == "create"){
          cout << "Enter Flight Number" << endl;
          cin >> flight;
          cout << "Enter capacity" << endl;
          cin >> capacity;
          for (int i = 0; i < 10; i++){
            if (booking[i].getid() == flight){
              cout << "Cannot perform this operation, a flight with the same id already exists" << endl;
              break;
            }
            if (!booking[i].valid()){
              booking[i].create(flight, capacity);
              break;
            }
          }
          cin.ignore();
        }
        else if (command == "delete"){
          cout << "Enter Flight Number to delete" << endl;
          cin >> flight;
          for (int i = 0; i < 10; i++){
            if (booking[i].getid() == flight){
              booking[i].deleteF();
              break;
            }
          }
          cin.ignore();
        }
        else if (command == "quit"){
          cout << "Exiting Program..." << endl;
          break;
        }
        check = false;
      }
      else if (val == "2"){
        for (int i = 0; i < 10; i++){
          if (shipbooking[i].valid()){
            check = true;
          }
        }
        if (check == 0){
          cout << "No flights in system." << endl;
        }
        else{
          for (int i = 0; i < 10; i++){
            if (shipbooking[i].valid())
            shipbooking[i].printStatus();
          }
        }
        string command = "";
        cout << "What would you like to do?: ";
        cin >> command;
        if (command == "add"){
          cout << "Which flight?" << endl;
          cin >> flight;
          cout << "How many seats?" << endl;
          cin >> n;
          for (int i = 0; i < 10; i++){
            if (shipbooking[i].getid() == flight){
              if (shipbooking[i].reserveSeats(n) == 1)
                shipbooking[i].edit(flight, reserved + n);
              else
                cout << "Cannot perform this operation, the reserved seats exceed 105% of available seats" << endl;
                break;
            }
          }
          cin.ignore();
        }
        else if (command == "cancel"){
          cout << "Which flight?" << endl;
          cin >> flight;
          cout << "How many seats?" << endl;
          cin >> n;

          for (int i = 0; i < 10; i++){
            if (shipbooking[i].getid() == flight){
              if (shipbooking[i].cancelReservations(n) == true)
                shipbooking[i].cancel(flight, n);
              else
                cout << "Cannot perform this operation" << endl;
              break;
            }
          }
          cin.ignore();
        }
        else if (command == "create"){
          cout << "Enter Flight Number" << endl;
          cin >> flight;
          cout << "Enter capacity" << endl;
          cin >> capacity;
          for (int i = 0; i < 10; i++){
            if (shipbooking[i].getid() == flight){
              cout << "Cannot perform this operation, a flight with the same id already exists" << endl;
              break;
            }
            if (!shipbooking[i].valid()){
              shipbooking[i].create(flight, capacity);
              break;
            }
          }
          cin.ignore();
        }
        else if (command == "delete"){
          cout << "Enter Flight Number to delete" << endl;
          cin >> flight;
          for (int i = 0; i < 10; i++){
            if (shipbooking[i].getid() == flight){
              shipbooking[i].deleteF();
              break;
            }
          }
          cin.ignore();
        }
        else if (command == "quit"){
          cout << "Exiting Program..." << endl;
          break;
        }
        check = false;
      }
      else if (val == "3"){
        for (int i = 0; i < 10; i++){
          if (busbooking[i].valid()){
            check = true;
          }
        }
        if (check == 0){
          cout << "No flights in system." << endl;
        }
        else{
          for (int i = 0; i < 10; i++){
            if (busbooking[i].valid())
            busbooking[i].printStatus();
          }
        }
        string command = "";
        cout << "What would you like to do?: ";
        cin >> command;
        if (command == "add"){
          cout << "Which flight?" << endl;
          cin >> flight;
          cout << "How many seats?" << endl;
          cin >> n;
          for (int i = 0; i < 10; i++){
            if (busbooking[i].getid() == flight){
              if (busbooking[i].reserveSeats(n) == 1)
                busbooking[i].edit(flight, reserved + n);
              else
                cout << "Cannot perform this operation, the reserved seats exceed 105% of available seats" << endl;
                break;
            }
          }
          cin.ignore();
        }
        else if (command == "cancel"){
          cout << "Which flight?" << endl;
          cin >> flight;
          cout << "How many seats?" << endl;
          cin >> n;

          for (int i = 0; i < 10; i++){
            if (busbooking[i].getid() == flight){
              if (busbooking[i].cancelReservations(n) == true)
                busbooking[i].cancel(flight, n);
              else
                cout << "Cannot perform this operation" << endl;
              break;
            }
          }
          cin.ignore();
        }
        else if (command == "create"){
          cout << "Enter Flight Number" << endl;
          cin >> flight;
          cout << "Enter capacity" << endl;
          cin >> capacity;
          for (int i = 0; i < 10; i++){
            if (busbooking[i].getid() == flight){
              cout << "Cannot perform this operation, a flight with the same id already exists" << endl;
              break;
            }
            if (!busbooking[i].valid()){
              busbooking[i].create(flight, capacity);
              break;
            }
          }
          cin.ignore();
        }
        else if (command == "delete"){
          cout << "Enter Flight Number to delete" << endl;
          cin >> flight;
          for (int i = 0; i < 10; i++){
            if (busbooking[i].getid() == flight){
              busbooking[i].deleteF();
              break;
            }
          }
          cin.ignore();
        }
        else if (command == "quit"){
          cout << "Exiting Program..." << endl;
          break;
        }
        check = false;
      } 
      else if (val == "0"){
        return 0;
      }
      else{
        cout << "Rangur innsláttur!" << endl;
        break;
      }
    }
	}
  return 0;
}
