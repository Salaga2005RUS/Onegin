#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    int i = 0;
    int n_counter = 0;

    char data[] = "data.txt";
    FILE *fp = fopen("data.txt", "r+"); // Открытие файла с текстом, присвоение  режима чтения + записи
    char **string = (char**)malloc(sizeof(char*)); // Выделяем память для массива текста + запись его адреса
    while (!feof(fp)) // Начинаем бежать по файлу
    {
        string[i] = (char*)malloc(sizeof(char)* 256); //Выделяем память под 256 символов 
        fgets(string[i], 256, fp); //Записываем по <=256 символов (построчно)
        i++;
        string = (char**)realloc(string, sizeof(char*)*(i + 1)); // Срезает лишнюю память
    } // TODO fread;

    i = 0;    

    while (string [i] != "EOF")
    {
        if (string [i] == "\n") n_counter++;
    }

    printf ("there are %d lines in this file", n_counter);

    // TODO free all allocated memory

    return 0;

}