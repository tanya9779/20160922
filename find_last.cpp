﻿#include <stdlib.h>
#include <iostream.h>

struct Node       //Структура являющаяся звеном списка
{
        int x;     //Значение x будет передаваться в список
        int y;     //
        Node *next,*prev; //Указатели на адреса следующего и предыдущего элементов списка
};


struct List   //Создаем тип данных Список
{
        Node *head;
        Node *tail;  //Указатели на адреса начала списка и его конца
};


void add( List *list, Node n )
{
        Node *temp = new Node; // Выделение памяти под новый элемент структуры
        temp->next = NULL;       // Указываем, что изначально по следующему адресу пусто
        temp->x = n.x;             // Записываем значение в структуру
        temp->y = n.y;

        if ( list->head != NULL ) // Если список не пуст
        {
                temp->prev = list->tail; // Указываем адрес на предыдущий элемент в соотв. поле
                list->tail->next = temp; // Указываем адрес следующего за хвостом элемента
                list->tail = temp;       //Меняем адрес хвоста
        }
        else //Если список пустой
        {
                temp->prev = NULL; // Предыдущий элемент указывает в пустоту
                list->head = list->tail = temp;    // Голова=Хвост=тот элемент, что сейчас добавили
        }
}

void print( List * list )
{
        Node * temp = list->head;  // Временно указываем на адрес первого элемента
        while( temp != NULL )      // Пока не встретим пустое значение
        {
                cout << "(" << temp->x <<", " << temp->y << ") "; //Выводим значение на экран
                temp = temp->next;     //Смена адреса на адрес следующего элемента
        }
        cout<<"\n";
}
int find_last( List * list, Node * n) // поиск последнего совпадения - возвращает индекс или -1
{
        int i=0;
        int last_find = -1;
        Node * temp = list->head;  // Временно указываем на адрес первого элемента
        while( temp != NULL )      // Пока не встретим пустое значение
        {
               if (temp->x == n->x && temp->y == n->y) {
                           last_find = i;
               }            
               i++;
               temp = temp->next;
        }
        return last_find;
}    

int main()
{
    List * my_list = new List;
    Node * nodes = new Node[20];
    for (int i=0; i<10;i++) {  // первые 10 элементов случайный
        nodes[i].x = rand()+100;
        nodes[i].y = rand()+100;
        add(my_list, nodes[i]);
    } 
    for (int i=10;i<20;i++) {  // последние 10 элементов дублируют первые 10 элементов
        nodes[i].x = nodes[i-10].x;
        nodes[i].y = nodes[i-10].y;
        add(my_list, nodes[i]);
    }
    print(my_list);  // выведем массив на экран
    int rand_ind = rand()%10;  // случайный элемент выбираем
    Node * ff = &nodes[rand_ind];
    // поищем этот случайный элемент в массиве
    cout << "find last (" << ff->x << "," << ff->y << ") found index " << find_last(my_list, ff) << "\n";
    
  // только для отладки
  //  int z;
  //  cin >> z;
}

