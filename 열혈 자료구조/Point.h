#ifdef __POINT_H__
#define __POINT_H__

typedef struct _point//structure of point that is consisted by x, y position.
{
	int xpos;
	int ypos;
}Point;

void SetPointPos(Point *ppos, int xpos, int ypos);//setter

void ShowPointPos(Point *ppos);//printer

int PointComp(Point *pos1, Point *pos2);//comp

#endif
