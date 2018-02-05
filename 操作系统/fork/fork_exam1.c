// fork_exam1
// 理解父进程和子进程的不同点
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int  i = 1;
	if (!fork()) i++;			// 执行fork后，子进程返回0,父进程返回子进程的ID
	printf("%d\n", i);
	if (!fork()) i++;
	printf("%d\n", i);
	return 0;
}

/*
 * Linux - Ubuntu的调试结果:
galen@66:~/fork/fork_exam1$ gcc -o fork_exam1 fork_exam1.c
galen@66:~/fork/fork_exam1$ ./fork_exam1 
1
2
1
galen@66:~/fork/fork_exam1$ 2
2
3
*/