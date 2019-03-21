/*
	текст программы может состоять из
		директив препроцессора,
		объявлений или определений данных, в том числе клеточных массивов
		описаний функций, описаний клеточных автоматов
		также допускаются описания пользовательских типов, таких как классы и структуры
		В качестве данных могут выступать:
			переменные, константы, статические и динамические массивы, специализированные КА типы

			новое: структуры данных, которые специализированно созданы для величин внешних воздействий
*/

#define classArray class
#define CellAuto class
#define lattice_type //тип решетки         -    константы
#define space_chape  //форма пространства  -     константы
#define neig         //шаблон соседства
//директивы препроцессора
#include "file_name" //etc...
struct SimpleData 
{
	int number;
	char[] symbols;
};
//описание класса клеточного массива
classArray SimpleLattice <lattice_type, space_chape> 
{
	//набор полей данных одной клетки!
	int posix;
	bool flag;
	SimpleData data;
	float arr[];

	//шаблоны соседства, можно определять несколько
	neig T = { #{0}, #{1}, #{2}, #{1, 0}, #{1, 1, 2} };

	//типовые методы:
		
};

//описание клеточного автомата
CellAuto automataName 
{
	//переменные, константы, клеточные массивы данных (для значений внешних воздействий)
	int t, l;
    float bar;
	SimpleLatticeOther innerCell;

	//список параметров передается через конструктор (клеточный массив)
	//конструкторов может быть несколько, с различными клеточными массивами
	AutomataName(SimpleLattice A)
   {
	  sys1: A;//указываем требуемую подстановку и клеточный массив, с каким хотим работать
	  sys2: A;
   }

	AutomataName(OtherLattice B) 
	{
	  sys1: B;
	}
	
	//система параллельных подстановок
	System sys1 : C //формальный параметр - клеточный массив, с которым работает клеточный автомат
	{
		//параллельные подстановки
	  Q1: (var x1, C.#[i].bar), (var x2, C.#[i].t) &                 //база - клетки с данными предыдущей итерации
		  isRandom(true), nextCell(var k) ->                         //контекст - условие выполнения подстановки, или какие либо вычисления
		  (x2, C.#[0].bar), (x1, C.#[0].t), (0,C.#[k].l) ~           //клетки для подстановки
		  for (int i = 0; i < 8; i++);                               //цикл подстановки

	        //в контекстную подстановку скрыто передается указатель на текущую клетку
	        context bool isRandom
        	{
		        if (C.bar > 10)
			      return true;
		     	else
			      return false;
	        }

		    context int nextCell
		    {
			   if (0 < randf() <= 0.25) return 1;
			   else if (0.25 < randf() <= 0.5) return 2;
			   else if (0.5 < randf() <= 0.75) return 3;
			   else if (0.75 < randf() <= 1) return 4;
			   else return 0;
 		    }
    }
    //tran функции - для вычисления новых значений клеток в правой части подстановки
    bool isAlive()
	{
		int sum = 0;
		for (int i = 1; i < A.T.Size; i++)
			sum + = A.T.[i].f;
		if (A.f == true)
			if (sum == 2 || sum == 3)
				return true;
			else
				return false;
		else
			if (sum == 3)
				return true;
			else
				return false;
	}
    //tran функция вычисления поля данных клетки, представленного массивом
	void calculateCells(SimpleLattice A)
	{
		for (int i = 1; i < A.arr.Size; i++)
		{
			A.arr[i] = (A.arr[i - 1] + A.arr[i]) / 2;
		}
	}

    System sys2 :  F
    {

    }

};


//Синтаксис запуска клеточного автомата
