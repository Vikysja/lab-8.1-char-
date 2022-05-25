// 8.1(char).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Квецко Вікторії
//Варіант 32

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int CountIncludes(char* str, const char* part);
char* Change(char* str, const char* fromPart, const char* toPart);

int main()
{
    const int strLength = 101;

    char str[strLength];

    cout << "Enter string:" << endl;
    cin.getline(str, strLength - 1);

    char letters[] = "BASIC";

    cout << endl;

    cout << "String contained " << CountIncludes(str, letters)
        << " letters of word: " << letters << endl << endl;

    char* dest = new char[strLength * 1.5];
    dest = Change(str, "BASIC", "Delphi");

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    return 0;
}

int CountIncludes(char* str, const char* part)
{
    int count = 0;
    int pos = 0;

    char* pointer;

    while (pointer = strpbrk(str + pos, part))
    {
        pos = pointer - str + 1;
        count++;
    }

    return count;
}

char* Change(char* str, const char* fromPart, const char* toPart)
{
    char* temp = new char[strlen(str)];
    char* pointer;

    int posStart = 0;
    int posEnd = 0;

    const int fromPartLen = strlen(fromPart);

    *temp = '\0';

    while (pointer = strstr(str + posStart, fromPart))
    {
        posEnd = pointer - str + fromPartLen;
        strncat(temp, str + posStart, posEnd - posStart - fromPartLen);
        strcat(temp, toPart);
        posStart = posEnd;
    }

    strcat(temp, str + posStart);

    return temp;
}