.\00_HomeWork_2\homework.md

Домашнее задание - рекурсия
---------------------------
  ЗАДАНИЕ:
 Пользователь вводит натуральное число N.
 Нужно вывести все способы разложить его на слагаемые.
 Способы отличающиеся только
 порядком слагаемых считаются одинаковыми.

Например N = 4:
* 4 = 4
* 4 = 3 + 1
* 4 = 2 + 2
* 4 = 2 + 1 + 1
* 4 = 1 + 1 + 1 + 1

.\00_HomeWork_2\main.cpp

Вычисление минимума
``` cpp
#define MIN(x,y) (x < y) ? x : y

int MIN2(int x, int y) {
  return (x < y) ? x : y;
}

template <class T>
T MIN3(T x, T y) {
  return (x < y) ? x : y;
}
```

``` cpp
int NN; // Для разложения

// N - оставшееся число для разложения
// m - последнее слагаемое в сумме
//    (из уже имеющихся слагаемых)
//   4 = 3 + 1
void sum(int N, int m) {
  // Слагаемые
  static int A[MAX_N];
  // Количество слагаемых
  static int K = 0;

  // Если от суммы ничего не осталось
  // => окончание рекурсии
  //  выводим ответ.
  if(N == 0) {
    cout << NN << " = ";

    // все слагаемые кроме последнего
    // с ' + '
    // последнее слагаемое с переводом строки
    for(int i = 0; i < K; ++i)
      cout << A[i] <<
           ((i < K - 1) ? " + " : "\n");

    // Вывели ответ => дальше нечего
    // делать в этой ветке рекурсии
    // выходим
    return;
  }

  // N - число, которое надо разложить
  // m - последнее слагаемое
  //   5 = 2 + ...   и ещё есть 4
  //    тогда следующее слагаемое 2, 1
  //   5 = 4 + ...   ещё есть 1
  //    следующее слагаемое максимум 1
  for(int x = min(N, m); x >= 1; --x) {
    // x - текущее слагаемое
    A[K] = x;
    K++;
    // Сумма уменьшилась на x
    // Максимальное слагаемое - x
    // Идём вглубь рекурсии
    sum(N - x, x);
    // Убираем последнее слагаемое x
    K--;
    // 4 = 2 + 1 + 1
    // 4 = 2 + 1 + ... <-- вернулись
    // надо убрать последнее 1
    // 4 = 2 + ...
    // 4 = 1 + 1 + 1 + 1
  }
}

void sum(int N) {
  sum(N, N);
}

int main() {
  // Вводим число N
  cout << "N = ";
  cin >> NN;
  // Вывод разложения на слагаемые
  sum(NN);
  return 0;
}
```

.\01_Assert\main.cpp

Утверждения: assert, TDD
------------------------
Утверждения нужны для автоматической проверки (тестирования).

Разработка через тестирование (TDD, test-driven development) -
техника разработки программного обеспечения,
которая основывается на повторении очень коротких циклов разработки:
* сначала пишется **тест**, покрывающий желаемое изменение,
* затем пишется **код**, который позволит пройти тест,
* и под конец проводится **рефакторинг** нового кода.

Для создания автоматических тестов можно использовать
функцию **assert**
``` cpp
#include <assert.h>
```

Разрабатываем функцию вычисления факториала.
Контракт - какие обязательства берёт на себя
вызывающая сторона.
``` cpp
long long fact(int n) {
  assert(n >= 0); // Контракт

  if(0 == n)
    return 1;

  return n * fact(n - 1);
}
```

Автоматические тесты
Модульное тестирование
``` cpp
  assert( fact(1) == 1 );
  assert( fact(2) == 2 );
  assert( fact(3) == 6 );
  assert( fact(3) == 1 * 2 * 3);
  assert( fact(4) == 1 * 2 * 3 * 4 );
  assert( fact(5) == 1 * 2 * 3 * 4 * 5 );
  assert( fact(6) == 1 * 2 * 3 * 4 * 5 * 6 );
  assert( fact(7) == 1 * 2 * 3 * 4 * 5 * 6 * 7 );
  assert( fact(0) == 1 );
```

Ручное тестирование функции:
``` cpp
  int N;
  cout << "N = ";
  cin >> N;
  cout << "fact(" << N << ") = " << fact(N) << endl;

  return 0;
```

.\01_sizeof\main.cpp

.\01_task_rec\main.cpp

Генерация правильных скобочных последовательностей
--------------------------------------------------
N = 1
* ()

N = 2
* (())
* ()()

N = 3
* ((()))
* (()())
* ...

Строка в C
----------
Заканчивается на символ 0.
"ABC" -> 'A', 'B', 'C', код 0
strlen(S) - считает символы в строке.
``` cpp
// Готовая строка скобок
char* S;
// N - сколько пар скобок надо поставить
int N;

// На текущий момент:
// a - сколько открывающих уже стоит
// b - сколько закрывающих уже стоит
// a + b - текущая позиция в строке
void rec(int a, int b) {
  assert(0 <= a);
  assert(0 <= b);
  assert(a <= N);
  assert(b <= N);
  int k = a + b; // Текущая позиция в строке

  // Если расставили все скобки
  if(a == N && b == N) {
    S[k] = 0;
    cout << S << endl;
    return;
  }

  // Можем ли поставить открывающую?
  // Да, если открывающие ещё не кончились
  if(a < N) {
    S[k] = '('; // Ставим открывающую
    rec(a + 1, b); // Рекурсия
  }

  // Можем ли поставить закрывающую?
  // Если закрывающие ещё остались
  // и открывающих больше чем закрывающих
  if(b < N && a > b) {
    S[k] = ')'; // Ставим закрывающую
    rec(a, b + 1); // Рекурсия
  }
}

void rec() {
  //strcpy(S, "()");
  //rec(1, 1);
  rec(0, 0);
}

int main() {
  //N = 2;
  cout << "N = ";
  cin >> N;
  // Отводим память
  S = new char[N * 2 + 1];
  // Заполняем строчку нулями
  // memset( указатель, чем_заполнять, размер )
  memset(S, 0, N * 2 + 1);

  rec();

  // Очищаем память
  delete[] S;
  return 0;
}
```

.\01_union\main.cpp

Объединения - union
-------------------
Два и более объекта занимают одну и ту же ячейку памяти
Пример:
``` cpp
union HH {
  int a;
  int b;
  char c;
};
```

Как выглядит переменная какого-то типа в памяти?

Чтобы абстрагироваться от конкретного типа
используем **typedef**:
typedef Определение_типа Имя_нового_типа;
``` cpp
typedef unsigned long MyType;
```

Объединение:
``` cpp
union InMemoryPresentation {
  MyType field; // Поле нашего типа
  unsigned char b[sizeof(MyType)]; // Массив байт того же размера
};
```

``` cpp
  InMemoryPresentation u;
  u.field = 5; // 'A';

  for(int i = 0; i < sizeof(MyType); ++i) {
    cout << i << ". ";

    for(int b = 7; b >= 0; --b) {
      unsigned char byte = u.b[i];
      // Число:    01101110  00001101
      // Ном.бита: 76543210         1
      cout << ((byte >> b) & 1);
    }

    cout << endl;
  }

```

.\02_var_reference\main.cpp

Значение / ссылка / указатель
-----------------------------
Передача параметров
``` cpp
// По значению
void f1(int i) {
  i++;
  SHOW(i)
}

// По ссылке (только C++)
void f2(int& i) {
  i++;
  SHOW(i)
}

// По указателю
void f3(int* i) {
  (*i)++;
  SHOW(*i)
}

int main() {
  int i = 0;
  SHOW(i);

  f1(i);
  SHOW(i);
  f2(i);
  SHOW(i);
  f3(&i);
  SHOW(i);

  return 0;
}
```

.\03_references\main.cpp

``` cpp
int main() {
  int a = 10;
  int& b = a; // Ссылка
  // int &bb;  // error: 'bb' declared as
  // reference but not initialized
  int d = 22;
  // &b = d; // Нельзя переопределять ссылки

  cout << "a = " << a << endl;
  cout << "b = " << b << endl;

  b = 11;
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;

  int* ptr; // Указатель можно не инициализировать

  // Указывает на переменную a
  ptr = &a;
  cout << "*ptr = " << *ptr << endl;

  ptr = &d;
  cout << "*ptr = " << *ptr << endl;

  ptr = NULL;

  return 0;
}
```

.\04_ref_demo\main.cpp

``` cpp
void f1(int value) {
  value++;
  cout << "f1 = " << value << endl;
}

void f2(int& value) {
  value++;
  cout << "f2 = " << value << endl;
}

void f3(int* value) {
  (*value)++;
  cout << "f3 = " << *value << endl;
}


int main() {

  int value = 1;

  f1(value);
  cout << "after f1 = " << value << endl;

  f2(value);
  cout << "after f2 = " << value << endl;

  f3(&value);
  cout << "after f3 = " << value << endl;


  value = 11;
  // int & - объявляем ссылку
  int& b = value; // b и value - одна и та же переменная
  // только с 2-мя именами
  b = 10; // изменилось value
  value = 12; // изменилось b

  int* ptrA, valueA; // ptrA - указатель, valueA - значение
  valueA = 122;

  ptrA = &value; // Указатель ptrA указывает на
  // переменную value

  // *ptrA и value - одна и та же переменная
  value = 1000; // изменится и *ptrA
  *ptrA = 111; // изменится и value

  int d;
  ptrA = &d;

  return 0;
}
```

.\04_refs_array\main.cpp

``` cpp
int main() {
  int A[100];
  int* X;
  A[0] = 42;
  A[1] = 56;

  int* B = A; // B - второе имя для массива A
  // int& B[100] = A;
  int*& Y = X; // Y - второй имя для переменной X

  int K = 10;

  //cout << &*Y /* <=> */ Y

  cout << A[0] << endl;
  cout << *A << endl;

  cout << A[1] << endl;
  cout << *(A + 1) << endl;

  cout << B[0] << endl;
  cout << *B << endl;

  cout << B[1] << endl;
  cout << *(B + 1) << endl;

  return 0;
}
```

.\05_DebugMacro\main.cpp

Макросы для отладки
-------------------
``` cpp
#define MY_DEBUG
#ifdef MY_DEBUG
#define SHOW(x) cout << __FILE__ << ":" << __LINE__ << " " << #x << " = " << x << endl;
#else
#define SHOW(x) ;
#endif

#define ASSERT_EQ(a,b) ((a == b) ? (void)0 : _assert(#a" != "#b, __FILE__, __LINE__))
```

.\06_0_static_stack\main.c

Виды памяти
-----------
``` cpp
int data[100000000]; // Статическая память

void f(int N) { // Стек
  //int localArray[100];
  printf("f(%d)\n", N);
  f(N + 1);
}

int main() {
  int data2[100000]; // Стек
  int i;
  f(1);

  for(i = 0; i < 4000; i++) {
    // Динамическая память
    if(malloc(1000000) == NULL) {
      printf("NULL\n");
      break;
    }

    printf("i = %d\n", i);
  }

  return 0;
}
```

.\06_malloc_free\main.c

Динамическая память: malloc / free
----------------------------------
``` cpp
  int* intArray;
  intArray = malloc(100); // Отводим память - 100 байт
  intArray = malloc(70 * sizeof(int)); // 70 целых чисел

  if(intArray == NULL) {
    // Памяти не хватило
    printf("No memory :(");
    return;
  }

  intArray[0] = 10;

  // Освобождение памяти
  free(intArray);
```

.\07_new_delete\main.cpp

Динамическая память new / delete
--------------------------------
``` cpp
struct MyStruct {
  int a, b;
  double d;
};

int main() {
  // Отводим динамическую память
  MyStruct* p = new MyStruct;

  // Освобождаем динамическую память
  delete p;

  // "Заводим" массив в динамической памяти
  int* intArray = new int[1000];

  // Освобождаем память
  delete[] intArray;

  return 0;
}
```

.\09_queue\main.cpp

Структура данных: очередь
-------------------------
``` cpp
// На базе массива.
//
//    -------------------------------
//  <-|  |  |  |  |  |  |  |  |  |  | <-
//    -------------------------------

const int QUEUE_LEN = 10000;

int data[QUEUE_LEN];

int head = 0; // Индекс первого элемента очереди
int tail = 0; // Индекс первой свободной ячейки очереди

// Добавить элемент в конец очереди
void put(int value) {
  cout << "put(" << value << ")" << endl;
  data[tail++ % QUEUE_LEN] = value;
  // tail++
}

// Получить значение из начала очереди
int get() {
  return data[head++ % QUEUE_LEN];
}

bool isEmpty() {
  return head <= tail;
}

int main() {
  // Положить в очередь
  for(int i = 1; i <= 7; i++)
    put(i);

  // Извлекаем из очереди
  while(!isEmpty())
    cout << "get() -> " << get() << endl;

  return 0;
}
```

.\10_list\main.cpp

Стуктура данных: динамический список
------------------------------------
``` cpp
struct ListElement {
  int value;
  ListElement* next;
};

// Указатель на первый элемент списка
ListElement* root = NULL;

// Добавить в начало списка
void addToBegin(int newValue) {
  cout << endl;
  cout << "addToBegin " << newValue << endl;
  ListElement* newElement = new ListElement;
  newElement->value = newValue;
  newElement->next = root; // NULL;

  root = newElement;
}

// Удалить первый элемент списка
void deleteFirst() {
  // Проверяем что список пуст
  // и если это так, выводим сообщение
  // об ошибке и выходим из функции
  if(root == NULL) {
    cout << "List is empty" << endl;
    return;
  }

  // Запоминаем ссылку на перый элемент
  ListElement* firstElement = root;
  cout << endl;
  cout << "deleteFirst " << firstElement->value << endl;

  // Переместим корень (указатель на начало
  // списка) на второй элемент
  root = firstElement->next;

  // Теперь мы можем удалить первый элемент
  // т.к. ссылка на второй элемент
  // уже сохранена
  delete firstElement;
}

void showList() {
  cout << "List: " << endl;
  ListElement* curElement = root;

  while(curElement != NULL) {
    cout << curElement->value << endl;
    curElement = curElement->next;
  }
}

int main() {
  addToBegin(2);
  showList();

  addToBegin(10);
  showList();

  addToBegin(-6);
  showList();

  deleteFirst();
  showList();

  deleteFirst();
  showList();

  deleteFirst();
  showList();

  deleteFirst();
  showList();

  return 0;
}
```

.\11_list\main.cpp

Реализация структуры данных "Список"
------------------------------------
Элемент списка
``` cpp
struct ListElement {
  int value; // Значение элемента списка
  ListElement* next; // Указатель на следующий элемент списка
};
```

Список целиком
``` cpp
struct List {
  ListElement* root; // Указатель на первый элемент

  // Конструктор
  List() {
    cout << "Constructor" << endl;
    root = NULL;
    // Так нельзя (!!!):
    // root->next = NULL;
  }

  // Деструктор - метод, который вызывается при
  // уничтожении объекта
  ~List() {
    cout << "Destructor" << endl;
    ListElement* cur = root;

    while(cur != NULL) {
      cur = cur->next;
      delete root;
      root = cur;
    }
  }

  // Добавить в начало списка
  void addToBegin(int newValue) {
    // Заводим новый элемент списка в динамической памяти
    ListElement* newElement = new ListElement;
    // Записываем в него новое значение
    newElement->value = newValue;
    // (*newElement).value = newValue;
    // Этот элемент должен встать в начало списка,
    // т.е. все остальные элементы будут после него.
    newElement->next = root;
    root = newElement;
  }

  // Показать список
  void show() {
    // Текущий элемент - сначала 1-ый
    int No = 0;

    for(ListElement* cur = root;
        cur != NULL; cur = cur->next)
      cout << ++No << ". " << cur->value << endl;
  }

  // Добавить элемент в конец списка
  void addToEnd(int newValue) {
    if(root == NULL) {
      addToBegin(newValue);
      return;
    }

    // Идём до последнего элемента
    ListElement* cur = root;

    while(cur->next != NULL)
      cur = cur->next;

    //for(ListElement* cur = root;
    //    cur->next != NULL; cur = cur->next)
    //    /* Ничего не надо делать :) */;

    // Создаём новый элемент
    ListElement* newElement = new ListElement;
    newElement->value = newValue;
    newElement->next = NULL;

    // Новый элемент ставим в конец списка
    cur->next = newElement;
  }

  // Удаляем элемент списка по значению
  void deleteByValue(int value) {
    cout << "deleteByValue(" << value << ")" << endl;

    // Если список пуст, то искать в нём нечего
    if(root == NULL)
      return;

    // Если первое значение подходит, то удаляем первый элемент
    if(root->value == value) {
      ListElement* toDelete = root;
      root = root->next;
      delete toDelete;
      return;
    }

    ListElement* cur = root;

    // Ищем значение
    while((cur->next != NULL) &&
          (cur->next->value != value))
      cur = cur->next;

    // Ничего не нашли
    if(cur->next == NULL) {
      cout << value << " not found!" << endl;
      return;
    }

    // Мы нашли элемент, который хотим удалить и это
    ListElement* toDelete = cur->next;
    // Соединяем "концы" цепочки
    cur->next = toDelete->next;

    delete toDelete;
  }

  // Удаляем элемент с заданным индексом
  void deleteAt(int index) {
    cout << "deleteAt(" << index << ")" << endl;

    // Если список пуст, то искать в нём нечего
    if(root == NULL)
      return;

    // Если первое значение подходит, то удаляем первый элемент
    if(index == 0) {
      ListElement* toDelete = root;
      root = root->next;
      delete toDelete;
      return;
    }

    ListElement* cur = root;
    // Ищем значение
    int curIndex = 1;

    while((cur->next != NULL) &&
          (curIndex != index)) {
      cur = cur->next;
      curIndex++;
    }

    // Ничего не нашли
    if(cur->next == NULL) {
      cout << "Index " << index << " not found :)" << endl;
      return;
    }

    // Мы нашли элемент, который хотим удалить и это
    ListElement* toDelete = cur->next;
    // Соединяем "концы" цепочки
    cur->next = toDelete->next;

    delete toDelete;
  }
};
```

Тестирование
``` cpp
  List list; // Создали список
  // List - класс
  // list - объект этого класса
  list.addToBegin(5); // Добавляем 5 в начало
  list.addToBegin(3);
  list.addToBegin(43);
  list.addToBegin(56);
  list.addToEnd(111);
  list.show();

  list.deleteByValue(43);
  list.show();

  list.deleteByValue(102);
  list.show();

  cout << "Delete from begining" << endl;
  list.deleteByValue(56);
  list.show();

  cout << "Delete from end of list" << endl;
  list.deleteByValue(111);
  list.show();

  cout << "-- Delete by index tests --" << endl;
  list.addToBegin(5);
  list.addToEnd(8);
  list.show();
  cout << "Delete from begining" << endl;
  list.deleteAt(0);
  list.show();
  cout << "Delete from end of list" << endl;
  list.deleteAt(2);
  list.show();

  list.deleteAt(2);
  list.show();
```

.\12_OOP_Simplest\00_intro.md

﻿ООП - принципы: классы, объекты, прототипы
==========================================

Объектно-ориентированное программирование (ООП, OOP): абстракция, инкапсуляция, наследование и полиморфизм
----------------------------------------------------------------------------------------------------------

Парадигма программирования, в которой основные концепции: **объект** и **класс**.

**Класс** - является описанием ещё не существующей сущности (объекта).
 Фактически он описывает устройство объекта, являясь своего рода "чертежом".
Обычно классы разрабатывают таким образом, чтобы их объекты соответствовали объектам предметной области.

**Объект** - сущность, которой можно посылать сообщения, и которая может на них реагировать,
используя свои данные. **Объект** = **экземпляр класса**.
Данные объекта скрыты от остальной программы. Сокрытие данных называется инкапсуляцией.

**Объект** - экземпляр класса, сущность в адресном пространстве вычислительной системы,
появляющаяся при создании экземпляра класса или копирования прототипа.

**Абстрагирование** - выделение набора значимых характеристик объекта, исключая из рассмотрения незначимые.

**Абстракция** - набор всех характеристик объекта, значимых с точки зрения решаемых задач.

**Инкапсуляция** - свойство системы, позволяющее объединить данные и методы,
работающие с ними в классе, и скрыть детали реализации от пользователя.

**Наследование** - свойство системы, позволяющее описать новый класс
на основе уже существующего с частично или полностью заимствующейся функциональностью (данными и методами).
Класс, от которого производится наследование, называется **базовым**, **родительским** или **суперклассом**.
Новый класс - **потомком**, **наследником** или **производным** классом.

**Полиморфизм** - возможность использовать объекты с одинаковым
интерфейсом без передачи информации о типе и внутренней структуре объекта.

**Прототип** - объект-образец, по образу и подобию которого создаются другие объекты.
Объекты-копии могут сохранять связь с родительским объектом,
автоматически наследуя изменения в прототипе; эта особенность определяется в рамках конкретного языка.
В языках с прототипированием (например, JavaScript) вместо классов используются объекты-прототипы.

.\12_OOP_Simplest\main.cpp

Объявление класса
-----------------
Храним координаты точек как 2 отдельных массива
``` cpp
double x[100], y[100];
```

Создали структуру точка
``` cpp
struct Point {
  double x, y;
};

// Массив из точек
Point p[140];
```

Обращение: p[0].x, p[0].y

Класс = данные + методы работы
``` cpp
class Point2D {
 public:
  double x, y;

  void move(double dx, double dy) {
    x += dx;
    y += dy;
  }

  // Повернуть точку относительно начала координат
  void rotate(double angle) {
    // ...
  }
};
```

Модификаторы доступа: public / private / protected
Создание экземпляра
-------------------
Пример использования:
``` cpp
int main() {
  // Два отдельных массива
  x[0] = 1;
  y[0] = 2;
  // ООП
  p[0].x = 1;
  p[0].y = 2;

  Point p1;
  p1.x = 2;

  Point2D p2;
  p2.x = 2;

  Point2D points[100];
  points[10].x = 10.1;
  points[10].y = 10.3;
  points[0].move(1, 2);
  points[1].rotate(1.2);

  Point2D A, B, C;
  A.move(10, 2);

  /*  x[10] = 1;
    y[20] = 2;
    move_point(10, 10, 2); */

  // Динамическая память
  Point2D* p;
  //...
  p = new Point2D;
  p->x = 2;
  p->move(10, 11);
  (*p).move(1, 2);
  delete p;

  // Создаю массив объектов в
  // динамической памяти
  Point2D* pp = new Point2D[10];

  // Удаляю
  delete[] pp;

  return 0;
}
```

.\12_StackDemo\main.cpp

``` cpp
class Stack {
  const static int STACK_SIZE = 100;
  int data[STACK_SIZE];
  // Текущий размер стека
  int count = 0;
 public:
  // Положить данные на вершину стека
  void push(int value) {
    if(count == STACK_SIZE) {
      cout << "Stack is full!" << endl;
      return;
    }

    data[count++] = value;
  }
  // Забрать данные с вершины стека
  int pop() {
    if(count == 0) {
      cout << "Stack is empty!" << endl;
      return -1;
    }

    return data[--count];
  }
};
```

.\12_vectors\main.cpp

Конструктор - вызывается после создания объекта в памяти
Деструктор - вызывается перед удалением объекта из памяти
Конструктор копирования
.\13_constructor_destructor\main.cpp

Конструкторы и деструкторы
--------------------------
``` cpp
// struct - С
// class - С++

// Ключевое слово class
// Имя_класса
class MyClass {
  // Количество объектов
  static int count;
  // Идентификатор данного объекта
  int id;
  int* data;
 public:
  // Конструктор
  MyClass();
  // Деструктор
  ~MyClass();
};

// Инициализация static-переменной
int MyClass::count = 0;

MyClass::MyClass() {
  count++;
  id = count;
  cout << "Constructor #" << id << endl;

  data = new int[1000];
  data[0] = 10;
}

MyClass::~MyClass() {
  cout << "Destructor #" << id << endl;

  cout << data << " " << data[0] << endl;
  delete[] data;
}

struct A {
  int w;
  A(int v) {
    w = v;
  }
};
```

.\14_copy_contructor\main.cpp

Конструктор копирования
-----------------------
``` cpp
// Класс "строка"
class string {
  static int count; // Количество строк
  char*    Str;
  int     size;
 public:
  int id; // Идентификатор данной строки
  string(string&); // Конструктор копирования
  // Конструктор
  string(const char* str) {
    id = ++count;
    std::cout << "Constructor #" << id << " \"" << str << "\"" << std::endl;
    size = strlen(str); // "ABC\0"
    Str = new char[size + 1];
    strcpy(Str, str);
  };
  // Вывод строки на экран
  void show() {
    std::cout << Str << std::endl;
  }
  // Деструктор
  ~string() {
    std::cout << "Destructor #" << id << std::endl;
    delete[] Str; // Очищаем динамическую память
  }
  // Перегрузка операции присваивания
  string& operator=(string& right) {
    if(Str != NULL)
      delete[] Str;

    std::cout << "= #" << id << std::endl;
    // if(Str != NULL)
    //   delete[] Str;
    Str = new char[right.size + 1];
    size = right.size;
    strcpy(Str, right.Str);
  }
};

// Конструктор копирования
// Создает копии динамических переменных и ресурсов
string::string(string& x) {
  id = ++count;
  std::cout << "Copy constructor #" << id << std::endl;
  // if(Str != NULL)
  //   delete[] Str;
  Str = new char[x.size + 1];
  size = x.size;
  strcpy(Str, x.Str);
}

int string::count = 0;
```

.\15_ListExample\main.cpp

Один элемент списка
следующий элемент списка
Список целиком, с всеми операциями
Указатель на первый элемент списка
ListElement *root = NULL;
Конструктор - метод, который вызывается
при создании объекта (экземпляра класса)
NULL - означает что нет ни одного элемента в списке
Деструктор (очистка памяти)
Запоминаем 2-ой элемент списка
(следующий после первого элемента)
Удаляем первый элемент списка
delete:
1. Вызывается деструктор (если есть)
2. Освобождается динамическая память
Показать список
cur->value <-> (*cur).value
Добавить элемент в начало
Заводим новый элемент в динамической памяти
Заполняем новый элемент
Подвешиваем к новому элементу старый список
Теперь root должен ссылаться на новый элемент
Добавить элемент в конец
Если список пуст, то добавить в конец
это то же что и добавить в начало
Ищем последний элемент
Убеждаемся в том, что это последний элемент
списка
Заводим новый элемент
Подвешиваем новый элемент в конец списка
.\16_inherit\00_intro.md

﻿Наследование и уровни доступа
-----------------------------


.\16_inherit\main.cpp

Наследование и уровни доступа
-----------------------------
**Наследование** - способность производного класса
наследовать характеристики существующего базового класса
``` cpp
class A {
 public: // Доступно всем
  int a;
 protected: // Доступно себе и наследникам
  int forChilds;
 private:  // Доступно только мне
  int privateA;
};

class B : public A {
 public:
  int a;
  int b;
  void method1() {
    a = 1;
    b = 2;
    forChilds = 10;
    A::a = 10;
    B::a = 11;
    // privateA = 1; // Невозможно
  }
};

class C : public B {
 public:
  int c;
};

int main() {
  A a1, a2;
  a1.a = 1;
  B b1;
  b1.a = 2;
  b1.b = 3;
  //b1.forChilds = 5;

  return 0;
}
```

.\16_inherit_sameName\main.cpp

Наследование: поле с тем же имененем
------------------------------------
Пусть есть класс **A**
с полем **x** и методом **show**
``` cpp
class A {
 public:
  int x = -1;
  void show() {
    cout << "x = " << x << endl;
  }
};
```

И его наследник **B**
тоже с полем **x** и методом **show**
``` cpp
class B : public A {
 public:
  int x = -2;
  void show() {
    A::x++;
    cout << "A::x = " << A::x << endl;
    cout << "B::x = " << B::x << endl;
  }
};
```

Как получить доступ к каждому из полей **x**?
``` cpp
int main() {
  A a;
  B b;
  a.x = 1;
  a.show();
  b.x = 2;
  b.show();
  return 0;
}
```

.\17_inherit\main.cpp

Наследование
------------
struct A <--> class A { public:
class A <--> struct A { private:
``` cpp
struct A {
  static int staticInClass;
  int a; // Поле доступно отовсюду

  void doA() {
    cout << "doA()" << endl;
    onlyInA = 2;
    cout << "onlyInA = " << onlyInA << endl;
    forChilds = 10;
  };
 private:
  int onlyInA; // Только внутри класса A
 protected:
  int forChilds; // Внутри класса A и в наследниках
};
```

B - наследник A
``` cpp
struct B : public A {
  int b;
  int forChilds; // Поле с тем же именем
  void doB() {
    cout << "doB()" << endl;
    //onlyInA = 2; // Недоступно в наследниках
    doA();
    //cout << "onlyInA = " << onlyInA << endl;
    A::forChilds = 12;
    forChilds = 20; // Работает
    this->forChilds = 20; // Работает

    cout << "A::forChilds = " << A::forChilds << endl;
    cout << "B::forChilds = " << B::forChilds << endl;
  };
};
```


Множественное наследование
show(); // Ошибка компиляции
Мы должны явно указать из какого предка вызываем метод
потому что это глобальная переменная
a.onlyInA = 3; // 'int A::onlyInA' is private
'int A::forChilds' is protected
cout << a.forChilds << endl;
Нет доступа, т.к. onlyInA private
b.onlyInA = 10;
c.a = 1; // Ошибка из-за protected наследования
c.b = 2; // Ошибка из-за protected наследования
c.doA();
c.doB();
x.doL();
.\18_polymorph\main.cpp

``` cpp
// Фигура
struct Shape {
  //virtual void show(){
  //  cout << "Shape" << endl;
  //};
  virtual void show() = 0; // Абстрактный метод
 protected:
  // virtual void doA() = 0;
  // virtual void doB() = 0;
  // virtual void doC() = 0;
  // virtual void doD() = 0;
  // virtual void doE() = 0;
  //int x;
 private:
  char c1;
  char c2;
  char c3;
  char c4;
  char c5;
} __attribute__((packed));
```

Квадрат
``` cpp
struct Square : public Shape {
  double side;
  Square(double s) : side(s) { }
  void show() {
    cout << "Square side = " << side << endl;
  }
};
```

Прямоугольник
``` cpp
struct Rectangle : public Shape {
  double height, width;
  Rectangle(double h, double w) :
    height(h), width(w) { }
  void show() {
    cout << "Rectangle " << height <<
         " x " << width << endl;
  }
};
```

``` cpp
int main() {
  // Shape shape; // Ошибка компиляции
  cout << sizeof(Shape) << endl;
  Shape* s[] = {
    new Square(10),
    new Rectangle(2, 3),
    new Square(15),
    // new Shape(),
  };

  for(int i = 0; i < 3; ++i)
    s[i]->show();

  return 0;
}
```

.\19_setter_getter\main.cpp

``` cpp
struct A {
 private:
  int a;

 public:
  A() {
    a = 33;
  }

  // setter - метод для установки значения поля
  void setA(int value) {
    cout << "a = " << value << endl;
    a = value;
  }
  // getter - метод для получения значения поля
  int getA() {
    return a;
  }
};


int main() {
  A a1; // A - класс, a1 - объект
  a1.setA(20);
  cout << a1.getA() << endl;
  return 0;
}
```

.\20_getter_setter_square\main.cpp

Зачем нужны get/set методы?
---------------------------
Don’t Repeat Yourself
http://ru.wikipedia.org/wiki/Don%E2%80%99t_repeat_yourself
.\20_getter_setter_square\square.cpp

side = sqrt(value);
.\20_getter_setter_square\square.h

Инкапсуляция
private: // Инкапсуляция
double side;
Получить сторону квадрата
return side;
Задать сторону квадрата
side = value;
Получить площадь
return side*side;
Задать площадь
.\21_task_rational\main.cpp

Перегрузка операторов в C++. Вывод в поток
------------------------------------------
**Оператор в C++** - это некоторое действие или функция обозначенная специльным символом (символами).
Чтобы распространять действие операторов на новые (свои) типы данных в C++ их можно перегружать.
Для перегрузки используется ключевое слово **operator** вместе с прототипом и объявлением функции.
Практика: класс "рациональная дробь"
------------------------------------
Сокращение типа
``` cpp
typedef long long ll;
```

НОД - Наибольший общий делитель.
GCD - Greatest common divisor.
``` cpp
long GCD(long a, long b) {
  return (b == 0) ? a : GCD(b, a % b);
}
```

``` cpp
// Рациональная дробь: p/q
class Rational {
  long p, q; // p - числитель, q - знаменатель
  // Сокращение дроби
  void normalize() {
    long d = GCD(p, q); // Вычисляем наибольший общий делитель
    p /= d; // делим на него числитель
    q /= d; // делим на него знаменатель
  }
  void show(ostream& os) const {
    // Сокращаем дробь если надо
    long d = GCD(p, q); // Вычисляем наибольший общий делитель
    long px = p / d; // делим на него числитель
    long qx = q / d; // делим на него знаменатель

    if(qx < 0) {
      px = -px;
      qx = -qx;
    }

    // Если знаменатель равен 1
    // то это целое число
    if(qx == 1)   // Условие (1)
      os << px << endl;
    else {
      // Целая часть
      long whole = px / qx;

      if(whole != 0)
        os << whole << " ";
      else if(px < 0)
        os << "-";

      px -= whole * qx;
      px = abs(px);
      assert(px > 0);
      // Если число целое, то должно было сработать
      // первое условие (1)
      assert(px % qx != 0);
      os << px << "/" << qx << endl;
    }
  }
 public:
  // TODO: Конструктор
  Rational(long pi, long qi) :
    p(pi), q(qi) {
    assert(q != 0);
    //if(q == 0){
    //  cout << "q == 0" << endl;
    //  halt(1);
    //}
  }
  Rational(const char* message) {
    cout << message << " ";
    cout << "p = ";
    cin >> p;
    cout << "q = ";
    cin >> q;
    normalize();
  }
  // Показать дробь на экран (в консоль)
  void show() {
    show(cout);
  }

  // Сложение дробей
  void add(Rational& right) {
    //   p    right.p
    //  --- + -------
    //   q    right.q
    p = p * right.q + right.p * q;
    //  --------------------------
    q =       q * right.q;

    // Для предотвращения переполнений
    normalize();
  }

  // a + b
  const Rational operator+(Rational& right) {
    Rational res = *this;
    res.add(right);
    return res;
  }

  Rational operator+(int right) {
    Rational res = *this;
    Rational r(right, 1);
    res.add(r);
    return res;
  }

  friend
  Rational
  operator+(long left, Rational& right) {
    Rational res(left, 1);
    res.add(right);
    return res;
  }

  void sub(Rational& right) {
    p = p * right.q - right.p * q;
    //  --------------------------
    q =       q * right.q;

    normalize();
  }

  Rational operator-(Rational& right) {
    Rational res = *this;
    res.sub(right);
    return res;
  }

  // Конструктор копирования
  /* Rational(const Rational &r){
     //cout << r.p << "/" << r.q << endl;
     p = r.p;
     q = r.q;
     //cout << "Copy contructor " << p << "/" << q << endl;
   } */

  friend ostream& operator <<(ostream& os, const Rational& r) {
    r.show(os);
    return os;
  }
};

#define SHOW(x) { cout << #x << " = " << (x) << endl; }

int main() {
  /* Rational x(3, 1);
   x.show();

   Rational y(6, 4);
   y.show(); */

  Rational aa(2, 6), bb(3, 6);
  SHOW(aa);
  SHOW(bb);
  SHOW(aa - bb);

  Rational a(4, 6), b(11, 2);
  SHOW(a);
  SHOW(b);
  Rational c = a + b;
  SHOW(c);
  SHOW(a + b);
  SHOW(a - b);
  SHOW(a / b);
  SHOW(a * b);
  SHOW(a);
  SHOW(b);

  // Rational c = b + a;

  int i = 2, j = 3;
  int tt = i + j;
  Rational c1 = i + b;

  b.show();
  c1.show();

  Rational x(4, 6), y(1, 3);
  x.add(y);
  x.show();

  Rational yy("Vvedite:");
  yy.show();

  return 0;
}
```

.\22_this_demo\main.cpp

Работа с this
-------------
``` cpp
class Boy;

class Girl {
 public:
  Boy* boy;
  void reg(Boy* b) {
    boy = b;
  }
  void answer();
};

class Boy {
 public:
  Girl* girl;
  void reg(Girl* g) {
    girl = g;
    girl->reg(this);
  }
  void dialog() {
    cout << "Boy: hi!" << endl;
    girl->answer();
  }
  void answer() {
    cout << "Boy: I'm find! And how are you?" << endl;
  }
};

void Girl::answer() {
  cout << "Girl: Hi! How are you?" << endl;
  boy->answer();
}


int main() {
  Girl g;
  Boy b;
  b.reg(&g);

  b.dialog();

  return 0;
}
```

.\23_diamond_inherit\main.cpp

Diamond Inheritance
-------------------
``` cpp
//   A
//  / \
// B   C
//  \ /
//   D
#include <iostream>

using namespace std;

struct X {
  void show() {
    cout << "X" << endl;
  };
};

struct A {
  char name;
  A() : name('A') {};
  virtual
  void show() {
    cout << "show_A " << name << endl;
  };
};

struct B : virtual public A {
  B() {
    A::name = 'B';
  };
  void show() {
    cout << "show_B " << name << endl;
  };
};

struct C : virtual public A {
  C() {
    A::name = 'C';
  };
  void show() {
    cout << "show_C " << name << endl;
  };
};

struct D : public B, public C {
  D() {
    B::name = 'D';
  };
  void show() {
    cout << "show_D " << B::name << endl;
    B::show();
    C::show();
    C::A::show();
    B::A::show();
  };
};

int main() {
  /*A a;
  a.show();
  B b;
  b.show();
  C c;
  c.show(); */

  D d;
  d.show();

  /*A* x[4] = {new A, new B, new C, new D};
  for(int i = 0; i < 4; ++i)
    x[i]->show();
  */
  // Полиморфизм
  A* x[4] = { new B, new A, new C, new D };
  /* A* x[4];
   x[0] = new C;
   x[1] = new B;
   x[2] = new A;
   x[3] = new D; */

  cout << "sizeof(X) = " << sizeof(X) << endl;
  cout << "sizeof(*X) = " << sizeof(X*) << endl;

  cout << "+ VMT" << endl;
  cout << "sizeof(A) = " << sizeof(A) << endl;
  cout << "sizeof(*A) = " << sizeof(A*) << endl;

  for(int i = 0; i < 4; ++i)
    x[i]->show();

  for(int i = 0; i < 4; ++i)
    delete x[i];

  return 0;
}
```

.\25_iterator\main.cpp

Итерируемся по set
for(vector<int>)
.\26_private_constructor_singletone\main.cpp

Для чего использовать private-конструкторы?
-------------------------------------------
Шаблон проектирования Singletone
``` cpp
// Создаем класс S
// Задача: сделать чтобы в программе
// был только один экземпляр этого класса
// Singletone / Одиночка
class S {
  //private: // по-умолчанию и так private
  static int count;
  int id;
  // private (частный) конструктор
  S() {
    count++;
    id = count;
    cout << "Constructor #" << id << endl;
  }
  // Один-единственный экземпляр класса S
  static S* instance;
 public:
  // Единственный способ получить экземпляр
  // класса S - вызвать этот метод
  static S& getInstance() {
    if(instance == NULL)
      instance = new S;

    return *instance;
  }
  void show() {
    cout << "S #" << id << endl;
  }
  ~S() {
    cout << "Destructor: #" << id << endl;
  }
};

int S::count = 0;
S* S::instance = NULL;

int main() {
  //S s1;
  //S *s = new S;
  S a = S::getInstance(), b = S::getInstance();
  a.show();
  b.show();
  S c = S::getInstance();
  c.show();
  return 0;
}
```

.\27_string_overflow\main.cpp

Переполнение строки
-------------------
``` cpp
union Bytes {
  int i; // Тип int занимает 4 байта
  char bytes[4]; // Он же в виде 4-х отдельных
};
```

``` cpp
struct Shape {
  char type; // type = 'C' - круг, 'S' - квадрат
  double x, y;
  union {
    double R;
    double Side;
  };
};
```

``` cpp
struct Point {
  double x, y;

  // Расстояние между точками
  double dist(Point b) {
    return sqrt(pow(x - b.x, 2) +
                pow(y - b.y, 2));
  }

};
```

SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
SetConsoleOutputCP(1251); // Вывод на консоль в кодировке 1251.
``` cpp
  char str[10]; // Строка до 9 символов, последний символ 0

  cout << "Введите строку больше 10 символов: ";
  cin >> str;

  freopen("result.txt", "w", stdout);
  cout << str << endl;
```

.\28_Russian\README.md

﻿Список всех поддерживаемых консолей?
------------------------------------

Unix / MacOS
``` bash
locale -a
```

.\28_Russian\c.cpp

.\28_Russian\hw_cp866.c

.\28_Russian\hw_cp866.cpp

.\28_Russian\hw_utf8.cpp

C++
Вывод в консоль по-русски:
``` cpp
  system("chcp 65001");
  SetConsoleOutputCP(CP_UTF8);
  std::locale::global(std::locale ("en_US.UTF-8"));
  printf("Это моя первая программа!\n");
  cout << "Текст в UTF-8" << endl;
  cout << "И он нормально читается в Windows-консоли!" << endl;
```

.\28_Russian\hw_utf8_2.cpp

C++
Вывод в консоль по-русски:
``` cpp
  //setlocale(LC_ALL, "Russian_Russia.65001");
  setlocale(LC_ALL, "Russian.UTF-8");
  //SetConsoleCP(CP_UTF8);
  SetConsoleOutputCP(CP_UTF8);
```

.\28_Russian\show_cur_locale.cpp

Получаем параметры текущей локали
``` cpp
#include <windows.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
  char language[256] = {0}, country[256] = {0};
  GetLocaleInfo(
    GetUserDefaultLCID(),
    LOCALE_SENGLANGUAGE,
    language, sizeof(language));
  GetLocaleInfo(
    GetUserDefaultLCID(),
    LOCALE_SENGCOUNTRY,
    country, sizeof(country));

  UINT OEM_CP = GetOEMCP(); // Возвращает системную OEM кодовую страницу как число
  // UINT ANSI_CP = GetANSICP();

  printf("%s_%s %d\n", language, country, OEM_CP);

  cout << language << "_" << country << "." << OEM_CP << endl;
}
```

.\HomeWork\main.cpp

Домашняя работа
---------------
``` cpp
// Элемент стека и очереди
struct E {
  int value; // Значение элемента
  E* next; // Указатель на следующий элемент
};

// Стек
struct Stack {
  E* top; // Вершина стека
  // Конструктор
  Stack() : top(NULL) {}
  // Значение поместить на вершину стека
  void push(int value) {
    // TODO: реализовать
  }
  // Взять значение с вершины стека
  int pop() {
    // TODO: реализовать
  }
};

// Очередь
struct Queue {
  E* head; // "Голова" - начало очереди
  E* tail; // "Хвост" - конец очереди
  // Конструктор
  Queue() : head(NULL), tail(NULL) {};
  // В конец очереди
  void put(int value) {
    // TODO: реализовать
  }
  // Забрать первый элемент из очереди
  int get() {
    // TODO: реализовать
  }
};

int main() {
  Stack s;
  s.push(2);
  s.push(3);
  cout << "3 - " << s.pop() << endl;
  cout << "2 - " << s.pop() << endl;

  Stack s2;
  s2.push(10);
  s.push(11);
  cout << "11 - " << s.pop() << endl;
  cout << "10 - " << s2.pop() << endl;

  Queue q;
  q.put(10);
  q.put(14);
  cout << "10 - " << q.get() << endl;
  cout << "14 - " << q.get() << endl;

  return 0;
}
```

.\HomeWork\task.cpp

Домашнее задание:
Реализовать стек и очередь
Элемент стека и очереди
Стек
Конструктор
Значение поместить на вершину стека
Взять значение с вершины стека
Конструктор
В конец очереди
Забрать первый элемент из очереди
.\HomeWork_1\README.md

Домашнее задание - структуры данных
-----------------------------------

Определить структуру данных "точка"
(на плоскости, с 2-мя координатами
 x и y)

Реализовать функции сложения и вычитания.
Как для векторов.
Точка (1, 2) - вектор (1, 2).




.\HomeWork_1\main.cpp

Домашнее задание - структуры данных
-----------------------------------
Определить структуру данных "точка"
(на плоскости, с 2-мя координатами
x и y)
Реализовать функции сложения и вычитания.
Как для векторов.
Точка (1, 2) - вектор (1, 2)
Сумма
TODO: Реализовать
Разность
TODO: Реализовать
Скалярное произведение векторов
TODO: Реализовать
Тестирование
