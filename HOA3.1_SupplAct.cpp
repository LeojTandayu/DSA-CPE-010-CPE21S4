#include <iostream>
#include <string>
using namespace std;

class Song {
public:
    string title;
    Song* next;

    Song(string t) : title(t), next(nullptr) {}
};

class Playlist {
private:
    Song* head;

public:
    Playlist() : head(nullptr) {}

    void addSong(string title) {
        Song* newSong = new Song(title);
        if (!head) {
            head = newSong;
            newSong->next = head;
        } else {
            Song* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newSong;
            newSong->next = head;
        }
        cout << "Added: " << title << endl;
    }

    void removeSong(string title) {
        if (!head) {
            cout << "Playlist is empty." << endl;
            return;
        }

        Song* current = head;
        Song* previous = nullptr;

        do {
            if (current->title == title) {
                if (previous) {
                    previous->next = current->next;
                } else {
                    Song* last = head;
                    while (last->next != head) {
                        last = last->next;
                    }
                    last->next = current->next;
                    head = current->next;
                }
                delete current;
                cout << "Removed: " << title << endl;
                return;
            }
            previous = current;
            current = current->next;
        } while (current != head);

        cout << "Song not found: " << title << endl;
    }

    void playAll() {
        if (!head) {
            cout << "Playlist is empty." << endl;
            return;
        }

        Song* current = head;
        do {
            cout << "Playing: " << current->title << endl;
            current = current->next;
        } while (current != head);
    }
};

int main() {
    Playlist myPlaylist;

    myPlaylist.addSong("Song 1");
    myPlaylist.addSong("Song 2");
    myPlaylist.addSong("Song 3");

    myPlaylist.playAll();

    myPlaylist.removeSong("Song 2");

    myPlaylist.playAll();

    return 0;
}
