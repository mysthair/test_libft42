#include "libft.h"
#include "test_libft.h"
#include "tests.h"

#include <unistd.h>
#include <stdio.h>
 #include <sys/types.h>
       #include <sys/wait.h>

 #include <errno.h>
  #include <stdlib.h>


int main_test_ft_strsub()
	{
		//strsub
		{
			char 	*abcde = "abcde";
			char	*r;
			if (!ft_strequ((r = ft_strsub(abcde, 2, 1)), "c"))
			{
				ft_putstr("ft_strsub(abcde, 2, 1) = \"");
				ft_putstr(r);
				ft_putstr("\"\n");
			}
			ft_strdel(&r);
			FAIL_IF_NOT(ft_strequ((r=ft_strsub(abcde, 2, 1)), "c"));
			ft_strdel(&r);
		}
		{
			char 	*abcde = "abcde";
			char	*r;
			FAIL_IF_NOT(ft_strequ((r=ft_strsub(abcde, 2, 3)), "cde"));
			ft_strdel(&r);
		}
		{
			char 	*abcde = "abcde";
			char	*r;
			FAIL_IF_NOT(ft_strequ((r=ft_strsub(abcde, 2, 10)), "cde"));
			ft_strdel(&r);
		}

		{
			char 	*abcde = "abcde";
			char	*r;
			FAIL_IF_NOT(ft_strequ((r = ft_strsub(abcde, 2, 0)), ""));
			ft_strdel(&r);
		}

		{
			char 	*abcde = "abcde";
			char	*ft_strsub_abcde_10_10;
			ft_strsub_abcde_10_10 = ft_strsub(abcde, 10, 10);
			if(!(ft_strsub_abcde_10_10 == NULL || ft_strequ(ft_strsub_abcde_10_10, "")))
			{
				INFO(ft_putstr("WARNING : ft_strsub(abcde, 10, 10) = ");
				ft_putendl(ft_strsub_abcde_10_10 ? ft_strsub_abcde_10_10 : "NULL"));
			}
			//WARNING_IF_NOT(ft_strsub_abcde_10_10 == NULL || ft_strequ(ft_strsub_abcde_10_10, ""));
			ft_strdel(&ft_strsub_abcde_10_10);
		}
		{
			char 	*vide = "";
			char	*ft_strsub_vide_10_10;
			ft_strsub_vide_10_10 = ft_strsub(vide, 10, 10);
			if(!(ft_strsub_vide_10_10 == NULL || ft_strequ(ft_strsub_vide_10_10, "")))
			{
				INFO(ft_putstr("WARNING : ft_strsub(vide, 10, 10) = ");
				ft_putendl(ft_strsub_vide_10_10 ? ft_strsub_vide_10_10 : "NULL"));
			}
			//FAIL_IF_NOT(ft_strsub_vide_10_10 == NULL || ft_strequ(ft_strsub_vide_10_10, ""));
			ft_strdel(&ft_strsub_vide_10_10);
		}

		{
			char 	*vide = "";
			char	*r;
			FAIL_IF_NOT(ft_strequ((r=ft_strsub(vide, 0, 0)), ""));
			ft_strdel(&r);
		}

		pid_t pid = fork();
		if (pid == -1)
		{
			perror("fork failed");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			char	*r;
			FAIL_IF_NOT(ft_strequ((r=ft_strsub(NULL, 10, 2)), ""));
			ft_strdel(&r);
			_exit(EXIT_SUCCESS);
		}
		else
		{
			int status;
			(void)waitpid(pid, &status, 0);
			if(status == -1)
			{
				switch(errno)
				{
					case ECHILD:
						ft_putendl("Fork : The calling process has no existing unwaited-for child processes");
						break;
					case EFAULT:
						ft_putendl("Fork : The status or rusage argument points to an illegal address (may not be detected before the exit of a child process).");
						break;
					case EINVAL:
						ft_putendl("Fork : Invalid or undefined flags are passed in the options argument.");
						break;
					case EINTR:
						ft_putendl("Fork : The call is interrupted by a caught signal or the signal does not have the SA_RESTART flag set.");
						break;
					default:
						ft_putendl("Fork : unknow status");
						break;
				}
				ft_putendl("\n   .. KO (6)");
			}
			else
			{
				INFO(ft_putendl("  .. OK (7)");)
			}
		}


		pid = fork();
		if (pid == -1)
		{
			perror("fork failed");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			char	*r;
			FAIL_IF_NOT(ft_strequ((r=ft_strsub(NULL, 2, 10)), ""));
			ft_strdel(&r);
		}
		else
		{
			int status;
			int ret = waitpid(pid, &status, 0);
			if (ret == 0)
				ft_putendl("\n  .. OK");
			else if (ret != -1)
			{
				if (WIFSIGNALED(status))
				{
					if (WTERMSIG(status) == SIGSEGV)
						ft_putstr("\033[33mSegmentation Fault\033[0m\n");
					/*else if (WTERMSIG(status) == SIGEMT)
						printf("\033[33mBus Error\033[0m\n");*/
					else if (WTERMSIG(status) == SIGILL)
						ft_putstr("\033[33mIllegal Instruction\033[0m\n");
					else
					{
						ft_putstr("\033[33mThe processus receive the signal ");
						ft_putnbr(WTERMSIG(status));
						ft_putstr("\033[0m\n");
					}
				}
			}
			else
				perror("fork error Waitpid");
		}

		{
			char	*r;
			FAIL_IF_NOT(ft_strequ((r=ft_strsub(NULL, 2, 0)), ""));
			ft_strdel(&r);
		}

		pid = fork();
		if (pid == -1)
		{
			perror("fork failed");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			char	*ft_strsub_NULL_0_2 = ft_strsub(NULL, 0, 2);
			FAIL_IF_NOT(ft_strsub_NULL_0_2 == NULL || ft_strequ(ft_strsub_NULL_0_2, ""));
			ft_strdel(&ft_strsub_NULL_0_2);
		}
		else
		{
			int status;
			int ret = waitpid(pid, &status, 0);
			if (ret == 0)
				ft_putendl("\n  .. OK");
			else if (ret != -1)
			{
				if (WIFSIGNALED(status))
				{
					if (WTERMSIG(status) == SIGSEGV)
						ft_putstr("\033[33mSegmentation Fault\033[0m\n");
					/*else if (WTERMSIG(status) == SIGEMT)
						ft_putstr("\033[33mBus Error\033[0m\n");*/
					else if (WTERMSIG(status) == SIGILL)
						ft_putstr("\033[33mIllegal Instruction\033[0m\n");
					else
					{	ft_putstr("\033[33mThe processus receive the signal ");
						ft_putnbr(WTERMSIG(status));
						ft_putstr("\033[0m\n");
					}
				}
			}
			else
				perror("Waitpid");
		}
		{
			char	*r;
			FAIL_IF_NOT(ft_strequ((r=ft_strsub(NULL, 0, 0)), ""));
			ft_strdel(&r);
		}

		{
			char *str = "Un jour je serai, le meilleur codeur ! ^^";

			char	* r1 = ft_strsub(str, 0, (size_t)-10);
			//			char	* r2 = ft_strsub2(str, 0, (size_t)-10);
			INFO(if (r1 == NULL)
				ft_putstr("ft_strsub(str, 0, (size_t)-10) == NULL)\n");
			else
			{
				SHOW_STRING("ft_strsub(str, 0, (size_t)-10) : ", r1);
			})
			FAIL_IF_NOT(r1 ==NULL);
			//			FAIL_IF_NOT(r2 != NULL && ft_strequ(r2, str));
			ft_strdel(&r1);
			//			ft_strdel(&r2);
		}
		{
			char 	*str = "Un jour je serai, le meilleur codeur ! ^^";

			char	*result = ft_strsub(str, 0, 0);
			INFO(if (result == NULL)
				ft_putstr("ft_strsub(str, 0, 0) == NULL)\n");
			else
			{
				SHOW_STRING("ft_strsub(str, 0, 0) : ", result);
			})
			FAIL_IF_NOT(result != NULL && ft_strequ(result, ""));
			ft_strdel(&result);
		}

		{

		  char *str = "Un jour je serai, le meilleur codeur ! ^^";
		  char	* r = ft_strsub(str, 19, (size_t)-10);

		  INFO(if (r == NULL)
		 	 ft_putstr("ft_strsub(str, 19, (size_t)-10) == NULL)\n");
		  else
		  {
		  	SHOW_STRING("ft_strsub(str, 19, (size_t)-10)", r);
		  })
		  FAIL_IF_NOT(r == NULL || ft_strcmp(r, str) == 0);
		  ft_strdel(&r);
		}
		{
			char    *str = "i just want this part #############";
			char	* r = ft_strsub(str, 5, 10);
			//				      1234567890
			FAIL_IF_NOT(ft_strequ(r, "t want thi"));
			ft_strdel(&r);
		}

		return(1);
	}
