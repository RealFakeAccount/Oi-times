#include <cstdlib>
#include <cstdio>
#include <ctime>
int main()
{
	for(int i = 1; i <= 100; i++)
	{
		printf("subtask %d\n", i);
		system("D:\\Cp\\check\\random.exe");
		system("D:\\Cp\\check\\A.exe");
		system("D:\\Cp\\check\\A_bf.exe");
		if(system("fc D:\\Cp\\check\\data.ans D:\\Cp\\check\\data.out")){
			puts("wrong answer"); return 0;
		}
		puts("AC");
	}
	
	return 0;
}