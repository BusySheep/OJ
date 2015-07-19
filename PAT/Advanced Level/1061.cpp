//16:23
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

void printWeekDay(int day)
{
	switch (day)
	{
	case 1:printf("MON"); break;
	case 2:printf("TUE"); break;
	case 3:printf("WED"); break;
	case 4:printf("THU"); break;
	case 5:printf("FRI"); break;
	case 6:printf("SAT"); break;
	case 7:printf("SUN"); break;
	}
}

int main()
{
	char sa[61];
	char sb[61];
	char sc[61];
	char sd[61];
	scanf("%s%s%s%s", sa, sb, sc, sd);
	bool flag = false;
	int day;
	int hour;
	int minute;
	for (int i = 0; sa[i] && sb[i]; i++)
	{
		if (flag == true && ((sa[i] >= '0' && sa[i] <= '9') || (sa[i] >= 'A' && sa[i] <= 'N')) && sa[i] == sb[i])
		{
			if (sa[i] >= '0' && sa[i] <= '9')
			{
				hour = sa[i] - '0';
			}
			else
			{
				hour = sa[i] - 'A' + 10;
			}
			break;
		}
		if (flag == false && (sa[i] >= 'A' && sa[i] <= 'G' && sa[i] == sb[i]))
		{
			flag = true;
			day = sa[i] - 'A' + 1;
		}
	}
	for (int i = 0; sc[i] && sd[i]; i++)
	{
		if ((sc[i] >= 'a' && sc[i] <= 'z' || sc[i] >= 'A' && sc[i] <= 'Z') && sc[i] == sd[i])
		{
			minute = i;
		}
	}
	printWeekDay(day);
	putchar(' ');
	printf("%02d:%02d\n", hour, minute);
	system("pause");
	return 0;
}
//16:49
