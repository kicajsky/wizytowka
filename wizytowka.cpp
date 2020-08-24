#include <iostream>
#include <string>
#include <locale.h> //libka odpowiada za polskie znaki
#include <algorithm> //funkcja szukajaca max
using namespace std;

void dataLoad(string& imie, string& nazwisko, string& telefon, string& mail, string& opis)
{
    cout << "To jest twoja wizytowka. Podaj imie i nazwisko:\n";
    cin >> imie >> nazwisko;
    cout << "Podaj nr tel oraz mail:\n";
    cin >> telefon >> mail;
    cout << "Napisz coś o sobie:\n";
    getline(cin, opis);
}
int calculateRow(string& imie, string& nazwisko, string& telefon, string& mail, string& opis)
{
    int rowWidth1 = imie.size() + nazwisko.size();
    int rowWidth2 = telefon.size() + mail.size();
    int rowWidth3 = opis.size();
    return max({ rowWidth1, rowWidth2, rowWidth3 });
}
int main()
{
    setlocale(LC_CTYPE, "Polish");
    string imie, nazwisko, telefon, mail, opis;
    dataLoad(imie, nazwisko, telefon, mail, opis);
    int rowWidth = calculateRow(imie, nazwisko, telefon, mail, opis) + 4;
    cout << ' ';
    for (int i = 0; i < rowWidth; i++)
        cout << '_';
    cout << " \n|";
    for (int i = 0; i < rowWidth; i++)
        cout << ' ';
    cout << "|\n|"; //================================================= row1
    int nameLenght = imie.size() + nazwisko.size() + 1;
    int halfRow = (rowWidth - 2 - nameLenght) / 2 + 1;
    for (int i = 0; i < halfRow; i++) //centrowanie tekstu w rzędzie
        cout << ' ';    //rysowanie spacji przed tekstem
    cout << imie << ' ' << nazwisko;
    for (int i = halfRow + nameLenght; i < rowWidth; i++)
        cout << ' ';    //rysowanie spacji po tekscie
    cout << "|\n|";
    for (int i = 0; i < rowWidth; i++)
        cout << '=';
    cout << "|\n|"; //================================================= row2
    nameLenght = telefon.size() + mail.size() + 1;
    halfRow = (rowWidth - 2 - nameLenght) / 2 + 1;
    for (int i = 0; i < halfRow; i++)   //centrowanie tekstu w rzędzie
        cout << ' ';    //rysowanie spacji przed tekstem
    cout << telefon << ' ' << mail;
    for (int i = halfRow + nameLenght; i < rowWidth; i++)
        cout << ' ';    //rysowanie spacji po tekscie
    cout << "|\n|";
    for (int i = 0; i < rowWidth; i++)
        cout << '=';
    cout << "|\n|"; //================================================= row3
    nameLenght = opis.size();
    halfRow = (rowWidth - 2 - nameLenght) / 2 + 1;
    for (int i = 0; i < halfRow; i++) //centrowanie tekstu w rzędzie
        cout << ' ';    //rysowanie spacji przed tekstem
    cout << opis;
    for (int i = halfRow + nameLenght; i < rowWidth; i++)
        cout << ' ';    //rysowanie spacji po tekscie
    cout << "|\n|";
    for (int i = 0; i < rowWidth; i++)
        cout << '_';
    cout << "|\n"; //=================================================
}