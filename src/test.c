#include <unistd.h>

int main(void)
{
	char a;

	a = 65;
	write(1, &a, 1);
}