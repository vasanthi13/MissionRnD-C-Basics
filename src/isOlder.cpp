/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int isOlder(char *dob1, char *dob2) {
	int r, i, j, k, d1 = 0, m1 = 0, y1 = 0,d2=0,m2=0,y2=0;
	if ((dob1[2] != '-' || dob1[5] != '-') ||(dob1[8]=='\0')||(dob2[8]=='\0')|| (dob1[2] != '-' || dob1[5] != '-'))
		return -1;
	else
	{
		for (i = 0; dob1[i] != '-'; i++)
		{
			r = (int)dob1[i] - 48;
			d1 = d1 * 10 + r;
			r = (int)dob2[i] - 48;
			d2 = d2 * 10 + r;
		}
		for (j = i + 1; dob1[j] != '-'; j++)
		{
			r = (int)dob1[j] - 48;
			m1 = m1 * 10 + r;
			r = (int)dob2[j] - 48;
			m2 = m2 * 10 + r;
		}
		for (k = j + 1; dob1[k] != '\0'; k++)
		{
			r = (int)dob1[k] - 48;
			y1 = y1 * 10 + r;
			r = (int)dob2[k] - 48;
			y2 = y2 * 10 + r;
		}
		if (d1 == 0 || m1 == 0 || y1 == 0 || d2 == 0 || m2 == 0 || y2 == 0)  return -1;
		if (m1 > 12 || m2 > 12) return -1;
		if (m1 == 1 || m2 == 1 || m1 == 3 || m2 == 3 || m1 == 5 || m2 == 5 || m1 == 7 || m2 == 7 || m1 == 8 || m2 == 8 || m1 == 10 || m2 == 10 || m1 == 12 || m2 == 12)
		{
			if (d1 > 31 || d2 > 31) return -1;
		}
		if (m1 == 4 || m2 == 4 || m1 == 6 || m2 == 6 || m1 == 9 || m2 == 9 || m1 == 11 || m2 == 11)
		{
			if (d1 > 30 || d2 > 30)  return -1;
		}
		if (y1 % 100 == 0)
		{
			if (y1 % 400 == 0)
			{
				if (m1 == 2)
				{
					if (d1 > 29)
						return -1;
				}
			}
		}
		else if (y1 % 4 == 0)
		{
				if (m1 == 2)
				{
					if (d1 > 29)
						return -1;
				}
		}
		else
		{
			if (m1 == 2)
			{
				if (d1 > 28)
					return -1;
			}
		}
		if (y2 % 100 == 0)
		{
			if (y2 % 400 == 0)
			{
				if (m2 == 2)
				{
					if (d2 > 29)
						return -1;
				}
			}
		}
		else  if (y2 % 4 == 0)
		{
				if (m2 == 2)
				{
					if (d2 > 29)
						return -1;
				}

		}
		else
		{
			if (m2 == 2)
			{
				if (d2 > 28)
					return -1;
			}
		}
		if (y1 > y2) return 2;
		if (y1 < y2) return 1;
		if (y1 == y2)
		{
			if (m1 > m2) return 2;
			if (m1 < m2) return 1;
			if (m1 == m2)
			{
				if (d1 > d2) return 2;
				if (d1 < d2) return 1;
				if (d1 == d2) return 0;
			}
		}
	}
}
