/*
	����� ��������� ����� �������� ��
		�������� �������������,
		���������� ��� ����������� ������, � ��� ����� ��������� ��������
		�������� �������, �������� ��������� ���������
		����� ����������� �������� ���������������� �����, ����� ��� ������ � ���������
		� �������� ������ ����� ���������:
			����������, ���������, ����������� � ������������ �������, ������������������ �� ����

			�����: ��������� ������, ������� ����������������� ������� ��� ������� ������� �����������
*/

#define classArray class
#define CellAuto class
#define lattice_type //��� �������         -    ���������
#define space_chape  //����� ������������  -     ���������
#define neig         //������ ���������
//��������� �������������
#include "file_name" //etc...
struct SimpleData 
{
	int number;
	char[] symbols;
};
//�������� ������ ���������� �������
classArray SimpleLattice <lattice_type, space_chape> 
{
	//����� ����� ������ ����� ������!
	int posix;
	bool flag;
	SimpleData data;
	float arr[];

	//������� ���������, ����� ���������� ���������
	neig T = { #{0}, #{1}, #{2}, #{1, 0}, #{1, 1, 2} };

	//������� ������:
		
};

//�������� ���������� ��������
CellAuto automataName 
{
	//����������, ���������, ��������� ������� ������ (��� �������� ������� �����������)
	int t, l;
    float bar;
	SimpleLatticeOther innerCell;

	//������ ���������� ���������� ����� ����������� (��������� ������)
	//������������� ����� ���� ���������, � ���������� ���������� ���������
	AutomataName(SimpleLattice A)
   {
	  sys1: A;//��������� ��������� ����������� � ��������� ������, � ����� ����� ��������
	  sys2: A;
   }

	AutomataName(OtherLattice B) 
	{
	  sys1: B;
	}
	
	//������� ������������ �����������
	System sys1 : C //���������� �������� - ��������� ������, � ������� �������� ��������� �������
	{
		//������������ �����������
	  Q1: (var x1, C.#[i].bar), (var x2, C.#[i].t) &                 //���� - ������ � ������� ���������� ��������
		  isRandom(true), nextCell(var k) ->                         //�������� - ������� ���������� �����������, ��� ����� ���� ����������
		  (x2, C.#[0].bar), (x1, C.#[0].t), (0,C.#[k].l) ~           //������ ��� �����������
		  for (int i = 0; i < 8; i++);                               //���� �����������

	        //� ����������� ����������� ������ ���������� ��������� �� ������� ������
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
    //tran ������� - ��� ���������� ����� �������� ������ � ������ ����� �����������
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
    //tran ������� ���������� ���� ������ ������, ��������������� ��������
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


//��������� ������� ���������� ��������
