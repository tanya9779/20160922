#include <stdlib.h>
#include <iostream.h>

struct Node       //Структура являющаяся звеном списка
{
        int x;     // Значение x будет передаваться в список
        int y;     // Значение y
        Node *next,*prev; // Указатели на адреса следующего и предыдущего элементов списка
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
void insert(List * list, int index, Node * n) // вставка нового элемента в позицию index
{                                           // если такой позиции нет то в конец списка

    Node *temp = new Node; // Выделение памяти под новый элемент структуры
    temp->next = NULL;       // Указываем, что изначально по следующему адресу пусто
    temp->x = n->x;             // Записываем значение в структуру
    temp->y = n->y;
    int i =0;
    Node * current = list->head;  // Временно указываем на адрес первого элемента
    while (i<index && current) { // пока есть что перебирать
        current = current->next; // двигаемся к следующему
        i++;
    }
    if (current) { // вставляем новый элемент перед current, разрывая список
        current->prev->next = temp; 
        temp->prev = current->prev;
        current->prev = temp;
        temp->next = current;
        if (list->head == current) {
             list->head = temp;
        }               
    }
    else { // вставка в конец
        add(list, *n);
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

int main()
{
    List * my_list = new List;
    Node * nodes = new Node[20];
    for (int i=0; i<20;i++) {  // первые 10 элементов случайный
        nodes[i].x = i;
        nodes[i].y = i;
        add(my_list, nodes[i]);
    } 
    print(my_list);  // выведем массив на экран
    int rand_ind = rand()%20;  // случайный элемент выбираем
    Node * nn = new Node;
    nn->x = rand()%100+100;
    nn->y = rand()%100+100;
    insert(my_list, rand_ind, nn);
    // выведем измененный массив на экран
    print(my_list);  // выведем массив на экран
    
  // только для отладки
  int z;
  cin >> z;
}


