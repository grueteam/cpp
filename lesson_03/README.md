.\000_README.md
﻿



Конструкторы и деструкторы
--------------------------

Перегрузка операторов в C++. Вывод в поток
------------------------------------------

Оператор в C++ - это некоторое действие или функция обозначенная специльным символом (символами).
Чтобы распространять действие операторов на новые (свои) типы данных в C++ их можно перегружать.

Для перегрузки используется ключевое слово **operator** вместе с прототипом и объявлением функции.


Прототипы
---------


.\01_Russian\README.md
﻿Список всех поддерживаемых консолей?
------------------------------------

Unix / MacOS
``` bash
locale -a
```

.\01_Russian\c.cpp
.\01_Russian\hw_cp866.c
.\01_Russian\hw_cp866.cpp
.\01_Russian\hw_utf8.cpp
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

.\01_Russian\hw_utf8_2.cpp
C++
Вывод в консоль по-русски:
``` cpp
  //setlocale(LC_ALL, "Russian_Russia.65001");
  setlocale(LC_ALL, "Russian.UTF-8");
  //SetConsoleCP(CP_UTF8);
  SetConsoleOutputCP(CP_UTF8);
```

.\01_Russian\show_cur_locale.cpp
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

.\04_DebugMacro\main.cpp
Макросы для отладки
-------------------
if(a != b){ cout << __LINE__ << " " << #a << "=" << a << " != " << #b << "=" << b << endl; };
assert(c != NULL);
.\05_malloc_free\main.c
Динамическая память: malloc / free
----------------------------------
``` cpp
  int* intArray;
  // Отводим память
  intArray = malloc(100);

  if(intArray == NULL) {
    // Памяти не хватило
    printf("No memory :(");
    return;
  }

  intArray[0] = 10;

  // Освобождение памяти
  free(intArray);
```

.\06_new_delete\main.cpp
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

  // Освобождаем динимическую память
  delete p;

  // "Заводим" массив в динамической памяти
  int* intArray = new int[1000];

  // Освобождаем память
  delete[] intArray;

  return 0;
}
```

