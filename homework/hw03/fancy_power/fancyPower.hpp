#ifndef FANCYPOWER_HPP
#define FANCYPOWER_HPP

int fancyPower(int n, int m)
{
	if (n == 0)
	return 1;
	else 
	return (m * fancyPower(n-1,m));
}

#endif
