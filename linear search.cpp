#include<stdio.h>
#include<conio.h>
int main()
{
	int a[5]={10,20,30,40,50},i=0,item;
	clrscr();
	printf("input searching item..");
	scan("/d,&item");
	while(i<5)
	{
		if(a[i]==item)
		{
			printf("item found location=/d",i);
			break;
		}
		i++;
	}
	if(i>=5)
	printf("item not found");
	getch();
		}
	}
}


