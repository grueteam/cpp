.\!x\00_class\main.cpp
.\!x\01_arrays_const\main.cpp
Применение модификатора const в ООП
Метод не модифицирует состояние объекта
.\!x\01_contructor_destructor\main.cpp
Создание объекта
1. Отводится память sizeof(размер_объекта)
2. Присваиваются значения полям
3. Список инициализации из вызванного
конструктора
4. Выполняется код конструктора
Уничтожение объекта
1. Выполняется код деструктора
2. Очищается память занятая объектом
.\!x\02_bitfields\main.cpp
cout
.\!x\02_copy_constructor\main.cpp
Конструктор копирования
.\!x\03_inheritance\main.cpp
до первого private наследования
privateA = 2; // Недоступен
т.к. private доступны только внутри класса
protected - наследуем класс A
только для себя и наследников
privateA = 2; // Недоступен
т.к. private доступны только внутри класса
В наследнике C доступны те же поля
privateA = 2; // Недоступен
т.к. private доступны только внутри класса
private - наследуем класс A
только для себя (без наследников)
privateA = 2; // Недоступен
т.к. private доступны только внутри класса
Недоступно ничего из A
A -> private B -> public C
publicA = 1;
privateA = 2; // Недоступен
т.к. private доступны только внутри класса
protectedA = 3;
a.privateA = 10; // Недоступно
a.protectedA = 10; // Недоступно
bPublic.privateA = 10; // Недоступно
bPublic.protectedA = 10; // Недоступно
bProtected.publicA = 111;
C.publicA = 12;
.\!x\04_DoubleLinkedList\main.cpp
Добавить элемент в начало списка
Тот элемент, который раньше был первым
теперь должен ссылаться на новый первый элемент
Добавляем элемент в конец списка
Список не пустой
Идея: найти последний элемент списка
Для "старого" последнего элемента
следующий элемент - новый элемент
Для нового элемента: предыдущий -
"старый" последний элемент
Удалить первый элемент списка
Мы удаляем первый элемент, поэтому
предыдущего элемента нет
Удаляем из памяти
Ищем элемент по значению
Нашли элемент с заданным значением!
Если есть следующий
У следующего prev заменяем на на prev
Если есть предыдущий
У предыдущего next заменяем на наш next
Мы удаляем первый элемент, поэтому
root должен указывать на второй
Удалить по индексу
Удалим первый элемент
Снова посмотрим список
Удаляем средний
Удаляем первый элемент
Удаляем единственный элемент
Удаляем последний элемент
.\!x\04_Shapes\main.cpp
Базовый класс: Фигура
Имя фигуры (строка)
Конструктор для вызова из наследников
Каждая фигура показывает своё имя
Наследники Shape:
Конструктор
Внутри 2 точки
Конструктор
Одна точка и радиус
Конструктор
Везде метод show() -> показывает свойства фигуры
.\!x\06_Class_static\main.cpp
Ключевое слово: static -
поле/метод относится к классу целиком
а не к конкретному объекту.
за всё время работы программы объектов
(экземпляров) класса MyClass
т.е. оно только увеличивается и не
уменьшается при удалении объекта
Идентификатор - уникальный номер
данного экземпляра класса
Конструктор - специальный метод
который вызывается сразу после
отведения памяти под объект
Деструктор - специальный метод
который вызывается прямо перед
удалением объекта из памяти
Инициализируем статическое поле класса
.\!x\06_polymorph\main.cpp
abstract
interface  C# / Java
.\!x\07_inherit_simple\main.cpp
Класс A - предок класса B
Класс B - наследник класса A
.\!x\07_poly_check\main.cpp
.\!x\08_inherit_2\main.cpp
B - наследует поля и методы и из A и из A2
error: reference to 'x' is ambiguous|
x = 2;
Если уникальна
Хоть var из A2 и не видно, всё равно надо
указать класс
.\!x\08_inherit_order\main.cpp
..
Квадрат - частный случай прямоугольника
.\!x\09_cout_my_class\main.cpp
os = cout - типа ostream
Point = P
.\!x\09_private_public_protected\main.cpp
Только для "частного" использования
т.е. внутри класса Base
и в наследниках
privateVar = 122; // Недоступна
Так же, как при public-наследовании
privateVar = 122; // Недоступна
Наследуем поля только для себя
privateVar = 122; // Недоступна
base.privateVar = 1;
pub.privateVar - недоступна
p.publicVar = 11;
.\!x\10_public_protected_private_combinations\main.cpp
Доступны и x и y
.\!x\12_virtual\main.cpp
.\!x\13_InheritShapes\main.cpp
Фигура
Название фигуры
Цвет фигуры
Количество точек
Толщина границы (бордюра)
"ABC\0"
Точка
Квадрат
Левый правый угол
Сторона
Окружность
Координаты центра
Радиус окружности
Shape s("222",3,3,3);
.\!x\14_template_in_template\main.cpp
Шаблонная функция вычисления минимума
Стек заданной длины
T - тип элементов
Size - максимальное количество
(размер стека)
Массив для хранения данных
Количество элементов
Положить в стек значение
Извлечь с вершины стека значение
Очередь заданной длины
Голова и хвост очереди
Количество элементов
Положить в конец очереди
Взять из начала очереди
TODO: Разобрать пример на следующем занятии
Шаблонная функция для печати любой коллекции
.\!x\99_virtual\task1.cpp
.\!x\HomeWork\main.cpp
typedef long long ll;
НОД - Наибольший общий делитель
Рациональная дробь: p/q
Сокращение дроби
TODO: Конструктор
TODO: Ввод с клавиатуры
TODO: Показать дробь на экран (в консоль)
TODO: Сложение дробей
a + b
this - указатель на текущий объект
*this - текущий объект
TODO: прибавить к дроби целое число
TODO: прибавить к целому число дробь
TODO: вычитание
TODO: вычитание
Конструктор копирования
cout - типа ostream
stream - поток
thread - поток/нить
Rational c = b + a;
.\!x\PointStuct\main.cpp
Точка
Point(){};
Отрезок
p1.x = x1;  p1.y = y1;
p2.x = x2;  p2.y = y2;
Длина отрезка
Point p(2,3);
cout << "p.x = " << p.x << "  p.y = " << p.y << endl;
.\!x\StructNew\main.cpp
scanf("%s",c);
for(int i = 20; i < 10000; i--)
c[i] = 124;
.\!x\StructStaticCount\main.cpp
...
.\!x\TemplateFunction\main.cpp
.\!x\cont_textfiles\main.cpp
Перевод
Как ввести строку целиком?
Как читать
system("chcp 65001");
SetConsoleCP(65001);
SetConsoleOutputCP(65001);
freopen("out.txt","w",stdout);
Ключ - слово по-английски,
значение - слово по-русски
Словарь = Ассоциативный массив
int p = 1;
fclose(stdin); // !!!
cin >> p;
Считываем
Смотрим в словаре
const int strLen = 1024;
char phrase[strLen];
cin.getline(phrase, strLen);
cout << phrase << endl;
Ищем слово из словаря в строке
cout << inEnglish << " pos " << pos << endl;
.\!x\copy_constructor\main.cpp
потому что в строке символ 0 - окончание строки
Создает копии динамических переменных и ресурсов
SetConsoleCP(65001);
SetConsoleOutputCP(65001);
Добавить в конец кусок строки
Строка должна стать "TestEnd" после этой операции
.\!x\map_dict\main.cpp
Контейнеры:
vector
set
map
Ассоциативный массив
A["Hi"] = "Привет";
map<key, value>
dict[3] = 4;
dict[3] = 5;
.\!x\map_example\main.cpp
Итератор в строке пробегает по буквам
с первой буквы до последней по одной
Очередная буква строки
Не нашли букву => она первый раз
.\!x\memory_leaks\main.cpp
Утечки памяти
-------------
TODO: SmartPtr для обработки этой ситуации
delete intArray;
delete[] intArray;
.\!x\oop\main.cpp
