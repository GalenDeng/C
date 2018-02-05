// 理解fork的执行过程--一次调用执行两次
#include <stdio.h>
#include <unistd.h>

int main(void)
{
        int i;
        for(i = 0;i<2;i++) {
                fork();

                printf("ppid =%d,pid = %d,i=%d\n",getppid(),getpid(),i);
        }
        sleep(10);
        return 0;
}


/*
 * LINUX - UBUNTU调试结果: 打印6次
galen@66:~/fork/fork_exam2$ vim fork_exam2.c
galen@66:~/fork/fork_exam2$ gcc -o fork_exam2 fork_exam2.c 
galen@66:~/fork/fork_exam2$ ls
fork_exam2  fork_exam2.c
galen@66:~/fork/fork_exam2$ ./fork_exam2 
ppid =4605,pid = 5238,i=0
ppid =4605,pid = 5238,i=1
ppid =5238,pid = 5240,i=1
ppid =5238,pid = 5239,i=0
ppid =5238,pid = 5239,i=1
ppid =5239,pid = 5241,i=1
galen@66:~/fork/fork_exam2$
*/