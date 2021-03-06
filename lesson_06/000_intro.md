﻿Введение в Qt, Qt Creator, QtCore, QtGui, отладка
=================================================

Ссылки для скачивания
---------------------
* Qt Creator: http://qt-project.org/downloads
* http://www.qt.io/download-open-source/ 

При установке снимите галочку с **msvc 2013 ..** и поставьте на **MinGW 4.9.1**.

QT - история
------------

Первый выход в свет библиотеки Qt состоялся в мае 1995 года. 
Первоначально она разрабатывалась Хаавардом Нордом (главный управляющий Trolltech) и Эриком Чамбенгом (президент компании Trolltech). 
Хаавард и Эрик встретились в стенах Норвежского Технологического Института, в городе Тронхейме, где они получали высшее образование.

В 1991 году Хаавард написал первые несколько классов, из которых потом и появилась Qt. 
Эрик занялся разработкой общего дизайна библиотеки. 
На следующий год Эрику пришла в голову идея реализации "сигналов и слотов" - простой но очень мощной парадигмы программирования графического интерфейса. 
Хаавард подхватил идею и воплотил ее в код. 
К 1993 году они завершили разработку первого графического ядра и приступили к созданию визуальных компонентов (widgets). 
В конце года Хаавард предложил Эрику открыть совместное дело и выпустить "лучшую в мире библиотеку реализации графического интерфейса на C++".

**Сигнал** генерируется когда происходит определенное событие. 

**Слот** - функция (обработчик), которая вызывается в ответ на определенный сигнал.

В качестве префикса в именах классов был выбран символ "Q", поскольку Хааварду очень нравилось как он выглядел в Emacs. 
Символ "t" был выбран потому, что с него начиналось слово "toolkit", по аналогии с "Xt" -- "X toolkit". 
Компания была зарегистрирована 4 марта 1994 года под названием "Quasar Technologies", которое затем было преобразовано в "Troll Tech", а затем и в "Trolltech".

В апреле 1997 года вышла Qt 1.2.

В 2001 году вышла Qt 3. 

Летом 2005 года была выпущена Qt 4.0. 
Имея около 500 классов и более 9000 функций, Qt 4 оказалась больше и богаче любой предыдущей версии; 
она была разбита на несколько библиотек, чтобы разработчики могли использовать только нужные им части Qt. 
Версия Qt 4 представляет собой большой шаг вперёд по сравнению с предыдущими версиями; 
она содержит полностью новый набор эффективных и простых в применении классов-контейнеров, усовершенствованную функциональность архитекторы модель/представление, 
быстрый и гибкий фреймфорк графики 2D и мощные классы для просмотра и редактирования текста в кодировке Unicode, 
не говоря уже о тысячах небольших улучшений по всему спектру классов Qt. 
Qt 4 является первой версией Qt, доступной на всех поддерживаемых платформах как для коммерческой разработки, так и для разработки с открытым исходным кодом.

2012 год - выход Qt 5.0.
Главные изменения в Qt5 связаны с модульностью Qt и активным переходом на декларативное описание интерфейса (Qt Quick). 
Это не значит, что Qt перепишут на JavaScript, 
просто C++ будет использоваться для написания критичных ко времени выполнения или сложных вещей. 
Сохраняется и базовая обратная совместимость: в Qt 5 вошли почти все компоненты Qt 4, кроме устаревших, 
большинство модулей из Qt Mobility (теперь это уже не отдельный продукт) и некоторые экспериментальные разработки.

Установка и запуск Qt Creator. Qt Designer
------------------------------------------

Создание простейшего приложения. Сигналы и слоты. Обработка событий
-------------------------------------------------------------------

Проектирование пользовательского интерфейса с учётом требований эргономичности (компоненты, события, сигналы, слоты в Qt)
-------------------------------------------------------------------------------------------------------------------------

