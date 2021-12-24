#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Point.h"

void HanoiTowerMove(int num, char from, char by, char to)//from -> to by using by
{
	if(num==1)//stop condition
		printf("bar1 move to %c from %c\n", to, from);
	else
	{
		HanoiTowerMove(num-1, from, to, by);//bar num-1 move from->by for moving bar num move to first.
		printf("bar%d move to %c from %c\n", num, to, from);
		HanoiTowerMove(num-1, by, from, to);//left bar num-1 move by->to(that contains bar num already)
	}
}

int main()
{
	//p.71_Hanoi by recursive
	HanoiTowerMove(3, 'A', 'B', 'C');
	
	//p.96_Array Based List with Point(user defined struct0
	List list;
	Point compPos;//for comparing
	Point *ppos;//for allocation
	
	ListInit(&list);
	
	//save 4 data. Use malloc 4 times without free(Question!). (Realloc is used for RESIZING of allocated data)
	ppos=(Point*)malloc(sizeof(Point));//allocation for Point
	SetPointPos(ppos, 2, 1);//make data by set Point
	LInsert(&list, ppos);//insert
	
	ppos=(Point*)malloc(sizeof(Point));//Q. Can we reuse allocated data without free?
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);
	
	ppos=(Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);
	
	ppos=(Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);
	
	
	printf("Current amount of data: %d\n", LCount(&list));
	
	if(LFirst(&list, &ppos))//Print all
	{
		ShowPointPos(ppos);
		
		while(LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");
	
	
	compPos.xpos=2;//make compPos for testing PointComp function
	compPos.ypos=0;
	if(LFirst(&list, &ppos))//First, use LFirst. for initialization of curPosition, get first data by using curPosition
	{
		if(PointComp(ppos, &compPos)==1)//only x same not y
		{
			ppos=LRemove(&list);//remove list's element
			free(ppos);//free by using returned data by LRemove(&list). element delete!
		}
		
		while(LNext(&list, &ppos))//Next, use LNext
		{
			if(PointComp(ppos, &compPos)==1)
			{
				ppos=LRemove(&list);
				free(ppos);
			}
		}
	}
	
	printf("Current amount of data(after removing): %d\n", LCount(&list));
	
	if(LFirst(&list, &ppos))//Print all
	{
		ShowPointPos(ppos);
		
		while(LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");
		
	return 0;
}
