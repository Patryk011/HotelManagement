#include <iostream>

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

struct GuestData* ELEMENTS_LIST = NULL;

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

void insert_front(struct GuestData** head, int age, int fee, string firstName, string lastName, int type, bool parking, string room, bool access)
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
    listData->prev = NULL;

    if ((*head) != NULL)
    {
        (*head)->prev = listData;
        (*head) = listData;
    }

    cout << "Uzytko metody insert_front" << endl;
    cout << "Dodano element: " << firstName << ", " << lastName << endl;
}

void insert_after(struct GuestData* prev, int age, int fee, string firstName, string lastName, int type, string parking, string room, bool access)
{
    if (prev == NULL)
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

    if (listData->next!=NULL)
    {
        listData->next->prev = listData;
    }

    cout << "Uzytko metody insert_after" << endl;
    cout << "Dodano element: " << firstName << ", " << lastName << endl;
}


void insert_back(struct GuestData** head, int age, int fee, string firstName, string lastName, int type, bool parking, string room, bool access)
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
    listData->next = NULL;

    if ((*head) == NULL)
    {
        listData->prev = NULL;
        *head = listData;
        return;
    }

    

    cout << "Uzytko metody insert_back" << endl;
    cout << "Dodano element: " << firstName << ", " << lastName << endl;
}

void display(struct GuestData* listData)
{
    struct GuestData* last;

    while (listData != NULL)
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

    if (listData == NULL)
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
         bool parking = 0;
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




         /* if (option == 'T' && option == 'N')
          {
              cout << "Dodano miejsce parkingowe" << endl;
              parking = true;
          }
          else
          {
              while (option != 'T' && option != 'N')
              {
                  cout << "Mozesz podac tylko T (tak) lub N (nie). Sprobuj jeszcze raz.";
                  cin >> option;
                  if (option == 'N') {
                      parking = false;
                  }
                  else {
                      parking = true;
                      fee += 20;

                  }
              }
          }*/


         if (option == 'T')
         {
             if (CheckParkingAvailable())
             {
                 PARKING_COUNTER++;
             }
             else
             {
                 cout << "Parking nie jest dostepny" << endl;
                 option = 'N';
             }
         }
         else
         {
             cout << "Nie wybrano miejsca parkingowego" << endl;
         }

         //Jezeli lista jest psuta to dodajesz pierwszy element listy jako ostatni
         if (ELEMENTS_LIST == NULL)
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



//void addGuest(GuestData *data) {
//    //if ((*guests) == NULL) {
//    //   pointer newGuest;
//    //   newGuest = (Guest*)malloc(sizeof(Guest));
//    //     newGuest->data = data;
//    //    newGuest->next = NULL;
//    //    (*guests) = newGuest;
//    //   }
//    //    else
//    //      addGuest(&(*guests)->next, data);
//    guestData();
//  }
//        

void showGuests(pointer guests) {
    if (guests == NULL) {
        cout << "W bazie nie ma zadnych gosci";
    }
    while (guests != NULL) {
        cout << guests->data.firstName << " " << guests->data.lastName;
        cout << "Pokoj: " << guests -> data.room;
        cout << "Oplata: " << guests -> data.fee;
        cout << "Parking: " << guests->data.parking;
    }
}





void saveGuestToFile(pointer guests) {

    FILE* file;
    int size = sizeof(GuestData);
    file = fopen("guests.dat", "wb");
    if (file == NULL)
        return;
    while (guests != NULL) {
        fwrite(&(guests->data), size, 1, file);
        guests = guests->next;
    }
    fclose(file);
}

void readGuestsFromFile(pointer* guests) {
    FILE* file;
    int size = sizeof(GuestData);
    GuestData data;
    file = fopen("guests.dat", "rb");
    if (file == NULL)
        return;
   /* while (fread(&data, size, 1, file) == 1)
        addGuest(&(*guests), data);*/
    fclose(file);
}







int main()
{

    pointer guests = NULL;
    pointerA access = NULL;


    int option = 0;



    readGuestsFromFile(&guests);


        cout << "Dziekujemy, ze chcesz zarezerwowac pobyt w naszym hotelu." << endl;
      cout << "\n 1. Rezerwacja";
      cout << "\n 2. Wyswietl go�ci";
      cout << "\n 3. Zakoncz program" << endl;
    
    while (cin >> option)
    {
            cout << "Dziekujemy, ze chcesz zarezerwowac pobyt w naszym hotelu." << endl;
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
          break;
      }
      case 2:
      {
          showGuests(guests);
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


    //while (option != 3) {
    //    cout << "Dziekujemy, ze chcesz zarezerwowac pobyt w naszym hotelu." << endl;
    //    cout << "\n 1. Rezerwacja";
    //    cout << "\n 2. Wyswietl go�ci";
    //    cout << "\n 3. Zakoncz program" << endl;


    //    cout << "Wybierz opcje: ";
    //    cin >> option;
    //    cout << endl;



    //    switch (option) {

    //    case 1:
    //    {
    //        
    //        guestData();
    //        break;
    //    }
    //    case 2:
    //    {
    //        showGuests(guests);
    //        break;
    //    }
    //    case 3:
    //    {
    //        cout << "Dziekujemy, za korzystanie z naszych us�ug";
    //        break;
    //    }
    //    default: {
    //        cout << "Nie ma takiej opcji";
    //        break;
    //    }
    //           system("cls");
    //    }

    //    saveGuestToFile(guests);


    //    return 0;

    //}

}





