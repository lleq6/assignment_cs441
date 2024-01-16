#include <iostream>
#include <algorithm>
#include <vector>
#include <stddef.h>

using namespace std;

class Event
{
    public:
        int State, Start, Finish;
};

class Room
{
    public:
        vector<Event> Events;
};

bool roomCompare(Event, Event);
vector<Room> GetRooms(Event[], int);
void InsertFirstRoom(vector<Room>&, Event[], int);
void InsertNextRoom(vector<Room>&, Event[], int);

bool roomCompare(Event r1, Event r2)
{
    return r1.Finish < r2.Finish;
}

vector<Room> GetRooms(Event Events[], int N)
{
    sort(Events, Events + N, roomCompare);
    vector<Room> Rooms;
    InsertFirstRoom(Rooms, Events, N);
    InsertNextRoom(Rooms, Events, N);
    return Rooms;
}

void InsertFirstRoom(vector<Room> &Rooms, Event Events[], int N)
{
    int i = 0;
    Room firstRoom;
    Events[i].State = 1;
    firstRoom.Events.push_back(Events[i]);
    for (int j = 1; j < N; j++)
    {
        if (Events[j].Start >= Events[i].Finish && Events[j].State == 0)
        {
            Events[j].State = 1;
            firstRoom.Events.push_back(Events[j]);
            i = j;
        }
    }
    Rooms.push_back(firstRoom);
}

void InsertNextRoom(vector<Room> &Rooms, Event Events[], int N)
{
    int i = 0, temp = 0;
    Room nextRoom;
    for (int j = 1; j < N; ++j)
    {
        if (Events[j].State == 0)
        {
            if (temp == 0)
            {
                Room newRoom = *new Room();
                Events[j].State = 1;
                newRoom.Events.push_back(Events[j]);
                nextRoom = newRoom;
                temp = Events[j].Finish;
            }
            if (Events[j].Start >= temp)
            {
                Events[j].State = 1;
                nextRoom.Events.push_back(Events[j]);
            }
            else
            {
                if (Events[j].State == 0)
                {
                    Room newRoom = *new Room();
                    Events[j].State = 1;
                    newRoom.Events.push_back(Events[j]);
                    Rooms.push_back(newRoom);
                }
            }
        }
    }
    Rooms.push_back(nextRoom);
}

int main()
{
    int N, K;
    cout << "Enter number of N : ";
    cin >> N;
    if (cin.fail())
    {
        cout << "Please enter numbers only.";
        return EXIT_FAILURE;
    }
    Event *Events = new Event[N];
    for (int i = 0; i < N; ++i)
    {
        Event event = *new Event();
        cout << "Enter start and finish of Event (" << i + 1 << ") (Ex. 4 6) : ";
        event.State = 0;
        cin >> event.Start;
        if (cin.fail())
        {
            cout << "Please enter numbers only.";
            return EXIT_FAILURE;
        }
        cin >> event.Finish;
        if (cin.fail())
        {
            cout << "Please enter numbers only.";
            return EXIT_FAILURE;
        }
        Events[i] = event;
    }
    cout << "Enter number of K : ";
    cin >> K;
    if (cin.fail())
    {
        cout << "Please enter numbers only.";
        return EXIT_FAILURE;
    }
    cout << "มีงานจำนวน " << N << " งาน" << endl;
    for (int i = 0; i < N; ++i)
    {
        Event Event = Events[i];
        cout << " - งานที่ " << i + 1 << " (Start: " << Event.Start << " Finish: " << Event.Finish << ")" << endl;
    }
    vector<Room> Rooms = GetRooms(Events, N);
    cout << "มีห้องทั้งหมด " << K << " ห้อง จัดงานทั้งหมด " << Rooms.size() << " ห้อง" << endl;
    for (int i = 0; i < K; ++i)
    {
        cout << " - ห้องที่ " << i + 1;
        if (i < Rooms.size())
        {
            Room Room = Rooms[i];
            for (int j = 0; j < Room.Events.size(); ++j)
            {
                Event Event = Room.Events[j];
                cout << " [" << j + 1 << " = (Start: " << Event.Start << " Finish: " << Event.Finish << ")]";
            }
        }
        else
        {
            cout << " [Empty]";
        }
        cout << endl;
    }
    return EXIT_SUCCESS;
}