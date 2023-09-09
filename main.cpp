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
    FILE *fp = fopen("data.txt", "r+"); // �������� ����� � �������, ����������  ������ ������ + ������
    char **string = (char**)malloc(sizeof(char*)); // �������� ������ ��� ������� ������ + ������ ��� ������
    while (!feof(fp)) // �������� ������ �� �����
    {
        string[i] = (char*)malloc(sizeof(char)* 256); //�������� ������ ��� 256 �������� 
        fgets(string[i], 256, fp); //���������� �� <=256 �������� (���������)
        i++;
        string = (char**)realloc(string, sizeof(char*)*(i + 1)); // ������� ������ ������
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