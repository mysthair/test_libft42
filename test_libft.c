/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:42:37 by jleblanc          #+#    #+#             */
/*   Updated: 2017/02/01 12:51:19 by jleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"
#include "libft.h"
#include "tests.h"

#include <string.h>
#include <stdlib.h>

#include <ctype.h>
#include <sys/wait.h>
#include <errno.h>

#include <unistd.h>

static void ft_perror(const char *msg)
{
	ft_putendl_fd(msg, 2);
}

int		fork_test(int (*f)())
{
	pid_t pid = fork();
	if (pid == -1) {
		ft_perror("fork failed");
		_exit(EXIT_FAILURE);
	}else if (pid == 0){
       
        if ((*f)())
			_exit(EXIT_SUCCESS);
		else
			_exit(EXIT_SUCCESS);
	}else{
		int status;
		(void)waitpid(pid, &status, 0);
		if(status == -1){
			switch(errno){
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
			ft_putendl("\n   .. KO");
			return (0);
		}else{
			ft_putendl("\n  .. OK");
			return (1);
		}
	}	
}















/*	{ ici
		FAIL_IF_NOT(0);
	}

	{
		FAIL_IF_NOT(0);
	}*/










int main()
{
#undef FORK_TEST
#define FORK_TEST(f) f()


	FORK_TEST(main_test_ft_memcpy);
	FORK_TEST(main_test_ft_memccpy);
	FORK_TEST(main_test_ft_memmove);
	FORK_TEST(main_test_ft_memchr);
	FORK_TEST(main_test_ft_memcmp);
	FORK_TEST(main_test_ft_strdup);
	FORK_TEST(main_test_ft_strlen);
	FORK_TEST(main_test_ft_strcpy);
	FORK_TEST(main_test_ft_strncpy);
	FORK_TEST(main_test_ft_strcat);
	FORK_TEST(main_test_ft_strncat);
	FORK_TEST(main_test_ft_strtrim);
	FORK_TEST(main_test_ft_strsplit);
	FORK_TEST(main_test_ft_strlcat);
	FORK_TEST(main_test_ft_strchr);
	FORK_TEST(main_test_ft_strrchr);
	FORK_TEST(main_test_ft_strstr);
	FORK_TEST(main_test_ft_strnstr);
	FORK_TEST(main_test_ft_strcmp);
	FORK_TEST(main_test_ft_strncmp);
	FORK_TEST(main_test_ft_isalpha);
	FORK_TEST(main_test_ft_isascii);
	FORK_TEST(main_test_ft_isdigit);
	FORK_TEST(main_test_ft_isalnum);
	FORK_TEST(main_test_ft_isprint);
	FORK_TEST(main_test_ft_toupper);
	FORK_TEST(main_test_ft_tolower);
	FORK_TEST(main_test_ft_memalloc);
	FORK_TEST(main_test_ft_memdel);
	FORK_TEST(main_test_ft_strdel);
	FORK_TEST(main_test_ft_strnew);
	FORK_TEST(main_test_ft_strclr);
	FORK_TEST(main_test_ft_striter);
	FORK_TEST(main_test_ft_striteri);
	FORK_TEST(main_test_ft_strmap);
	FORK_TEST(main_test_ft_strmapi);
	FORK_TEST(main_test_ft_strequ);
	FORK_TEST(main_test_ft_strnequ);
	FORK_TEST(main_test_ft_strjoin);
	FORK_TEST(main_test_ft_strsplit);
	FORK_TEST(main_test_ft_itoa);
//	FORK_TEST(main_test_ft_lstnew_stdelone_lstadd_lstdel_lstmap);
	FORK_TEST(main_test_ft_lstnew);
	FORK_TEST(main_test_ft_strsub);
	FORK_TEST(main_test_ft_lstmap);

	ft_putendl("#############################################################");
	ft_putendl("##############     ALL TESTS ARE OK       ###################");
	ft_putendl("#############################################################");
	return (0);
}
