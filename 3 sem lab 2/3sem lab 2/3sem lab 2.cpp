
// 3sem lab 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>

using  namespace std;

class employee
{
private:
	
		int id=0;
		char name[40];
		int salary;
		friend class boogalter;
public:
	employee() {};                                                                           //констрктор по умолчанию
	employee( char* j);                                                                        //конструктор инициализации
	~employee() {};                                                              //деструктор
	friend void out(employee *nl,int i);
	friend void outsort(employee* nl, int j,int i);
	friend int delet(employee* nl, int j,int i);
	friend void change(employee* nl, int j,int i);
};
employee::employee( char* j)   // описание функции конструктора

{
	salary = 0;
	strcpy(name, j);
}
int  delet(employee* nl, int j, int i)
{
	employee k;
	if (j<0 ||j >= i) return i;
	for (int m = j; m < i; m++)
	{
		k = nl[m];
		nl[m] = nl[m + 1];
		nl[m + 1] = k;
	}
	return --i;
}
void change(employee* nl, int j,int i)
{
	char s[40];
	int d, flag1, g;
	if (j < 0 || j>= i)
	{
		cout << "\nInvalid number!!!";
		return;
	}
	cout << "ENTER THE EMPLOYEE'S FIRST NAME,LAST NAME AND PATRONYMIC: ";
	rewind(stdin);
	//cin.getline(nl[j].name, 40);
	cin.getline(s, 40);
	d = strlen(s);
	flag1 = 0;
	g = 0;
	for (int a = 0; a < d; a++)
	{
		if (((s[a] < 65) || (s[a] > 90)) && ((s[a] < 97) || (s[a] > 122)))
		{
			if (s[a] != 45)
			{
				if (s[a] != 32) flag1 = 1;
			}
			if (s[a] == 45)
			{
				g++;
				if (g > 1) flag1 = 1;
			}

		}
	}
	if (flag1 == 1)
	{
		cout << "\nERROR!";
	}
	else nl[j] = employee(s);
}
void out(employee* nl,int i)
{
	cout << "\n";
	for (int k = 0; k < 13; k++) cout << "-----";
	cout << "\n| ID:\t"<< "| EMPLOYEE:\t\t\t\t" << "| SALARY:\t|";
	for (int j = 0; j < i; j++)
	{
		cout << "\n";
		for (int k = 0; k < 13; k++) cout << "-----";
		nl[j].id = j;
		printf("\n| %-6d| %-38s| %-14d|", nl[j].id, nl[j].name, nl[j].salary);
	}
	cout << "\n";
	for (int k = 0; k < 13; k++) cout << "-----";
}
void outsort(employee* nl, int k,int i)
{
	cout << "\n";
	for (int k = 0; k < 13; k++) cout << "-----";
	cout << "\n| ID:\t" << "| EMPLOYEE:\t\t\t\t" << "| SALARY:\t|";
	for (int j = 0; j < i; j++)
	{
		if (k < nl[j].salary)
		{
			cout << "\n";
			for (int k = 0; k < 13; k++) cout << "-----";
			nl[j].id = j;
			printf("\n| %-6d| %-38s| %-14d|", nl[j].id, nl[j].name, nl[j].salary);
		}
	}
	cout << "\n";
	for (int k = 0; k < 13; k++) cout << "-----";
}
class boogalter
{
public:
	boogalter(int j,int y, employee* nl);
};
boogalter::boogalter(int j,int y, employee* nl)
{
	if (j < y && j >= 0)
	{
		cout << "\nENTER THE SALARY FOR EMPLOYEE NUMBER(ID):  ";
		while (!scanf("%d", &nl[j].salary))
		{
			cout << "\nError!!!\n\nENTER THE SALARY FOR EMPLOYEE NUMBER(ID):  ";
			rewind(stdin);
		}
	}
	else
	{
		cout << "YOU ENTERED AN INVALID ID!!!";
	}
}
int main()
{
	char s[40];
	employee k[100];
	int flag=10;
	int i = 0;
	int j;
	int g = 0;
	int flag1 = 0;
	int d;
	while (1)
	{
		cout  << "\n\n0--EXIT\n" << "1--ADD A EMPLOYEE\n" << "2--VIEW THE LIST OF EMPLOYEE'S\n" << "3--DELETE  A EMPLOYEE\n" <<"4--ADD A SALARY\n" <<"5--EMPLOYEE ADJUSTMENT\n" <<"6--SORTING EMPLOYEES BY SALARY >\n"<< "CHOSE THE ACTION:\n";

		while (!scanf("%d", &flag) || flag<0 || flag>6)
		{
			cout << "\nERROR!\n"<< "\n\n0--EXIT\n" << "1--ADD A EMPLOYEE\n" << "2--VIEW THE LIST OF EMPLOYEE'S\n" << "3--DELETE  A EMPLOYEE\n" << "4--ADD A SALARY\n" << "5--EMPLOYEE ADJUSTMENT\n" << "6--SORTING EMPLOYEES BY SALARY >\n" << "CHOSE THE ACTION:\n";
			rewind(stdin);
		}
		switch (flag)
		{
		case 0:
			break;
			break;
		case 1:
			cout << "ENTER THE EMPLOYEE'S FIRST NAME,LAST NAME AND PATRONYMIC: ";
			rewind(stdin);
			cin.getline(s, 40);
			d = strlen(s);
			flag1 = 0;
			g = 0;
			for (int a = 0; a < d; a++)
			{
				if  ( ( (s[a] < 65) ||(s[a] >90) )  && ( (s[a] < 97) || (s[a] >122) ) )
				{
					if (s[a] != 45)
					{
						if(s[a] != 32) flag1 = 1;
					}
					if (s[a] == 45)
					{
						g++;
						if (g > 1) flag1 = 1;
					}
					
				}
			}
			if (flag1 == 1)
			{
				cout << "\nERROR!";
				break;
			}
			k[i]=employee(s);
			i++;
			break;
		case 2:
			out(k,i);
			break;
		case 3:
			cout << "\nENTER THE EMPLOYEE ID NUMBER TO DELETE (0--" << i-1 << "):  ";
			while (!scanf("%d", &j))
			{
				cout << "\nError!!!\n" << "\nENTER THE EMPLOYEE ID NUMBER TO DELETE(0--"<< i-1 << ") : ";  
				rewind(stdin);
			}
			i = delet(k,j, i);
			break;
		case 4:
			cout << "\nENTER THE EMPLOYEE ID NUMBER TO SET THE SALARY (0--" << i-1 <<"):  ";
			
			while (!scanf("%d", &j) )
			{
				cout << "\nError!!!\nENTER THE EMPLOYEE ID NUMBER TO SET THE SALARY (0--" << i - 1 << "):  ";
				rewind(stdin);
			}
             boogalter(j,i,k);
			break;
		case 5:
			cout << "\nENTER THE EMPLOYEE ID NUMBER TO ADJUSTMENT (0--" << i - 1 << "):  ";
			while (!scanf("%d", &j))
			{
				cout << "\nError!!!\nENTER THE EMPLOYEE ID NUMBER TO ADJUSTMENT (0--" << i - 1 << "): ";
				rewind(stdin);
			}
			change(k, j,i);
			break;
		case 6:
			cout << "\nENTER THE SALARY TO SORT:   ";
			while (!scanf("%d", &j))
			{
				cout << "\nError!!!\nENTER THE SALARY TO SORT: ";
				rewind(stdin);
			}
			outsort(k, j, i);
			break;	
		}
		if (flag == 0) break;
		flag = 10;
	}
	return 0;
}