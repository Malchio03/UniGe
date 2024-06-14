#ifndef ALBUMLIBRARY_H
#define ALBUMLIBRARY_H

#include <vector>
#include <string>

struct Album {
    std::string title;
    std::string performer;
    unsigned int year;
};

typedef std::vector<Album> AlbumLibrary;

// Funzioni che dovete implementare
void sortAlbumLibrary(AlbumLibrary& AL);
void insertAlbum(const Album& A, AlbumLibrary& AL);


// Funzioni definite da noi. Se vi servono potete usarle
void readAlbumLibrary(const std::string& filename, AlbumLibrary& AL);
void printAlbumLibrary(const AlbumLibrary& AL);
void copyAlbum(const Album& source, Album& dest);
bool isSorted(const AlbumLibrary& AL);

#endif //ALBUMLIBRARY_H
