#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdlib.h>

using namespace std;

int PARKING_NUMER = 20;
int PARKING_COUNTER = 0;

int SINGLE_ROOM = 10;
int SINGLE_COUNTER = 0;

int APARTAMENT_ROOM = 5;
int APARTAMENT_COUNTER = 0;

int DOUBLE_ROOM = 5;
int DOUBLE_COUNTER = 0;

int FAMILY_ROOM = 5;
int FAMILY_COUNTER = 0;

int ROOMS_SUM = SINGLE_ROOM + APARTAMENT_ROOM + DOUBLE_ROOM + FAMILY_ROOM;
int ROOMS_COUNTER = SINGLE_COUNTER + APARTAMENT_COUNTER + DOUBLE_COUNTER + FAMILY_COUNTER;

int COUNTER = 0;

struct GuestData {
    int age;
    int fee;
    string firstName;
    string lastName;
    int type;
    string parking;
    string room;
    bool access;
    struct GuestData* next;
    struct GuestData* prev;
};

struct GuestData* ELEMENTS_LIST = 0;

struct Guest {
    GuestData data;
    Guest* next;
};

struct Access {
    Access* next;
};

typedef Guest* pointer;
typedef Access* pointerA;


bool CheckParkingAvailable()
{
    if (PARKING_COUNTER < PARKING_NUMER) return true;
    return false;
}

//void insert_Front(struct GuestData** head, )

void insert_front(struct GuestData** head, int age, int fee, string firstName, string lastName, int type, string parking, string room, bool access)
{
    struct GuestData* listData = new GuestData;
    listData->age = age;
    listData->fee = fee;
    listData->firstName = firstName;
    listData->lastName = lastName;
    listData->type = type;
    listData->parking = parking;
    listData->room = room;
    listData->access = access;
    listData->next = (*head);
    listData->prev = 0;

    if ((*head) != 0)
    {
        (*head)->prev = listData;
        (*head) = listData;
    }

    cout << "Uzytko metody insert_front" << endl;
    cout << "Dodano element: " << firstName << ", " << lastName << endl;
}

void insert_after(struct GuestData* prev, int age, int fee, string firstName, string lastName, int type, string parking, string room, bool access)
{
    if (prev == 0)
    {
        cout << "Brakuje ostatniego elementu :)" << endl;
        return;
    }

    struct GuestData* listData = new GuestData;
    listData->age = age;
    listData->fee = fee;
    listData->firstName = firstName;
    listData->lastName = lastName;
    listData->type = type;
    listData->parking = parking;
    listData->room = room;
    listData->access = access;
    
    listData->next = prev->next;
    prev->next = listData;
    listData->prev = prev;

    if (listData->next!=0)
    {
        listData->next->prev = listData;
    }

    cout << "Uzytko metody insert_after" << endl;
    cout << "Dodano element: " << firstName << ", " << lastName << endl;
}


void insert_back(struct GuestData** head, int age, int fee, string firstName, string lastName, int type, string parking, string room, bool access)
{
    struct GuestData* listData = new GuestData;
    struct GuestData* last = *head;

    listData->age = age;
    listData->fee = fee;
    listData->firstName = firstName;
    listData->lastName = lastName;
    listData->type = type;
    listData->parking = parking;
    listData->room = room;
    listData->access = access;
    listData->next = 0;

    if ((*head) == 0)
    {
        listData->prev = 0;
        *head = listData;
        return;
    }

    

    cout << "Uzytko metody insert_back" << endl;
    cout << "Dodano element: " << firstName << ", " << lastName << endl;
}

void display(struct GuestData* listData)
{
    struct GuestData* last;

    while (listData != 0)
    {
        cout << "Imie: " << listData->firstName << endl;
        cout << "Nazwisko: " << listData->lastName << endl;
        cout << "Wiek: " << listData->age << endl;
        cout << "Kwota do zaplaty: " << listData->fee << endl;
        cout << "Typ: " << listData->type << endl;
        cout << "Czy parking?: " << listData->parking << endl;
        cout << "Pokoj: " << listData->room << endl;
        cout << "Dostepny?: " << listData->access << endl;

        last = listData;
        listData = listData->next;
    }

    if (listData == 0)
    {
        cout << "Brak elementow do wyswietlenia" << endl;
        return;
    }
}


bool CheckRoomAvailable(int type)
{
    if (type == 1)
    {
        if (SINGLE_COUNTER < SINGLE_ROOM) return true;
        return false;
    }
    if (type == 2)
    {
        if (DOUBLE_COUNTER < DOUBLE_ROOM) return true;
        return false;
    }
    if (type == 3)
    {
        if (APARTAMENT_COUNTER < APARTAMENT_ROOM) return true;
        return false;
    }
    if (type == 4)
    {
        if (FAMILY_COUNTER < FAMILY_ROOM) return true;
        return false;
    }
}

 void guestData() {
   // int age, int fee, string firstName, string lastName, int type, string room, bool parking, bool access, string option

   

     if (ROOMS_COUNTER < ROOMS_SUM)
     {

         int age;
         int fee = 0;
         string firstName;
         string lastName;
         int type;
         string room;
         string parking;
         bool access = 0;
         char option='N';




         cout << "Podaj wiek: ";
         cin >> age;

         if (age < 18)
             cout << "Aby sie zarejestrowac musisz miec conajmnmiej 18 lat." << endl;
         else
             cout << "Podaj imie: ";
         cin >> firstName;
         cout << "Podaj nazwisko: ";
         cin >> lastName;

         cout << "Podaj opcje ktora Cie interesuje (1 - Pojedynczy pokoj (150zl), 2 - Pokoj dwuosobowy (250zl), 3 - Apartament (350zl), 4 - Pokoj rodzinny (350zl). : ";
         cin >> type;

      

         while (type > 4) {
             cout << "Podana opcja nie istnieje, sprobuj jeszcze raz";
             if (type == 1) {
                 if (CheckRoomAvailable(1))
                 {
                     room = "Single";
                     fee += 150;
                     SINGLE_ROOM++;
                 }
                 cout << "Pokoje pojedyncze nie sa dostepne" << endl;
             }

             if (type == 2) {
                 if (CheckRoomAvailable(2)) {
                     room = "Double";
                     fee += 250;
                     DOUBLE_ROOM++;
                   }
             cout << "Pokoje podw�jne nie sa dostepne" << endl;
         }

             if (type == 3) {
                 if (CheckRoomAvailable(3)) {
                     room = "Apartament";
                     fee += 350;
                     APARTAMENT_ROOM++;
                 }
                 cout << "Apartament nie jest dostepny" << endl;
             }
             if (type == 4) {
                 if (CheckRoomAvailable(4)) {
                     room = "Family";
                     fee += 350;
                     FAMILY_ROOM++;
                 }
                 cout << "Pokoje rodzinne nie sa dostepne" << endl;
             }

         }

         cout << "Czy chcesz rowniez zarezerwowac miejsce parkingowe ? (T/N): ";


         cin >> option;






         if (option == 'T')
         {
             if (CheckParkingAvailable())
             {
                 PARKING_COUNTER++;
                 parking = "Tak";
                 
             }
             else
             {
                 cout << "Parking nie jest dostepny" << endl;
                 parking = "Nie";
                 option = 'N';
             }
         }
         else
         {
             cout << "Nie wybrano miejsca parkingowego" << endl;
         }

         //Jezeli lista jest psuta to dodajesz pierwszy element listy jako ostatni
         if (ELEMENTS_LIST == 0)
         {
             insert_back(&ELEMENTS_LIST, age, fee, firstName, lastName, type, parking, room, access);
         }
         else
         {
             //w innym przypadku dodajemy nowe elementy z przodu listy
             insert_front(&ELEMENTS_LIST, age, fee, firstName, lastName, type, parking, room, access);
         }


     }
     else
     {
         cout << "Wszystkie pokoje sa zajete" << endl;
      }
    
}






void saveToFile(struct GuestData* listData)
{

    ofstream myfile;
    myfile.open("example.txt");

    struct GuestData* last;

    while (listData != 0)
    {

        myfile << "Imie: " << listData->firstName << endl;
        myfile << "Nazwisko: " << listData->lastName << endl;
        myfile << "Wiek: " << listData->age << endl;
        myfile << "Kwota do zaplaty: " << listData->fee << endl;
        myfile << "Typ: " << listData->type << endl;
        myfile << "Czy parking?: " << listData->parking << endl;
        myfile << "Pokoj: " << listData->room << endl;
        myfile << "Dostepny?: " << listData->access << endl;

        last = listData;
        listData = listData->next;
    }

    if (listData == 0)
    {
        cout << "Brak elementow do wyswietlenia" << endl;
        return;
    }

    myfile.close();
}


void openFile()
{
    string s;

    ifstream myfile;
    myfile.open("example.txt");

    if (myfile.is_open())
    {
        while (getline(myfile, s))
        {
            cout << s << endl;
        }
    }
    else
    {
        cout << "Problem z plikiem" << endl;
    }
}







int main()
{

    pointer guests = 0;
    pointerA access = 0;


    int option = 0;



    //readGuestsFromFile(&guests);


        cout << "Dziekujemy, ze chcesz zarezerwowac pobyt w naszym hotelu. Kliknij 1, aby kontynuowac" << endl;
        
    
    
    while (cin >> option)
    {
    
      cout << "\n 1. Rezerwacja";
      cout << "\n 2. Wyswietl go�ci";
      cout << "\n 3. Zakoncz program" << endl;


      cout << "Wybierz opcje: ";
      cin >> option;
      cout << endl;



      switch (option) {

      case 1:
      {
          guestData();
          saveToFile(ELEMENTS_LIST);
          break;
      }
      case 2:
      {
          //showGuests(guests);
          openFile();
          break;
      }
      case 3:
      {
          cout << "Dziekujemy, za korzystanie z naszych us�ug";
          return 0;
          break;
      }
      default: {
          cout << "Nie ma takiej opcji";
          break;
      }
           
      }

      


    }


  

}





