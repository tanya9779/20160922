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
int find_first( List * list, Node * n) // поиск первого совпадения - возвращает индекс или -1
{
        int i=0;
        Node * temp = list->head;  // Временно указываем на адрес первого элемента
        while( temp != NULL )      // Пока не встретим пустое значение
        {
               if (temp->x == n->x && temp->y == n->y) {
                           return i;
               }            
               i++;
               temp = temp->next;
        }
        return -1;
}    

int main()
{
    List * my_list = new List;
    Node * nodes = new Node[20];
    for (int i=0; i<20;i++) {
        nodes[i].x = rand()+100;
        nodes[i].y = rand()+100;
        add(my_list, nodes[i]);
    }    
    print(my_list);
    int rand_ind = rand()%20;
    Node * ff = &nodes[rand_ind];
    cout << "find first (" << ff->x << "," << ff->y << ") found index " << find_first(my_list, ff) << "\n";
    
  // только для отладки
  //  int z;
  //  cin >> z;
}

