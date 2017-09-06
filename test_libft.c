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

#ifndef DEBUG
/* THX/seen at https://openclassrooms.com/courses/la-programmation-systeme-en-c-sous-unix/les-processus-1 */

/* Pour les constantes EXIT_SUCCESS et EXIT_FAILURE */
#include <stdlib.h>
/* Pour fprintf() */
#include <stdio.h>
/* Pour fork() */
#include <unistd.h>
/* Pour perror() et errno */
#include <errno.h>
/* Pour le type pid_t */
#include <sys/types.h>
/* Pour wait() */
#include <sys/wait.h>

/* Pour faire simple, on déclare status en globale à la barbare */
int status;

/* La fonction create_process duplique le processus appelant et retourne
   le PID du processus fils ainsi créé */
pid_t create_process(void)
{
    /* On crée une nouvelle valeur de type pid_t */
    pid_t pid;

    /* On fork() tant que l'erreur est EAGAIN */
    do {
	pid = fork();
    } while ((pid == -1) && (errno == EAGAIN));

    /* On retourne le PID du processus ainsi créé */
    return pid;
}

/* La fonction child_process effectue les actions du processus fils */
void child_process(int (*f)())
{
    TRACE(printf(" Nous sommes dans le fils !\n"
	   " Le PID du fils est %d.\n"
	   " Le PPID du fils est %d.\n", (int) getpid(), (int) getppid()));
     if ((*f)()){
      TRACE(ft_putendl(GREEN_OK);)
 			_exit(EXIT_SUCCESS);
      // return(SUCCESS);
 		}else{
 			ft_putendl(RED_KO);
 			_exit(EXIT_FAILURE);
 		}
}

/* La fonction father_process effectue les actions du processus père */
void father_process(int child_pid)
{
    (void)child_pid;
    TRACE(printf(" Nous sommes dans le père !\n"
	   " Le PID du fils est %d.\n"
	   " Le PID du père est %d.\n", (int) child_pid, (int) getpid()));

    if (wait(&status) == -1) {
	    perror("wait :");
	    exit(EXIT_FAILURE);
    }

    if (WIFEXITED(status)) {
	TRACE(printf(" Terminaison normale du processus fils.\n"
	       " Code de retour : %d.\n", WEXITSTATUS(status)));
         ft_putendl(!WEXITSTATUS(status) ? GREEN_OK : RED_KO);
    }

    if (WIFSIGNALED(status)) {
      ft_putstr(RED_KO);
	    ft_putstr("  signal ");
      ft_putnbr(WTERMSIG(status));
      ft_putstr(" intercepted\n");
  		TRACE(_exit(EXIT_FAILURE));
	  }
}

int		fork_test(int (*f)())
{
    pid_t pid = create_process();

    switch (pid) {
	/* Si on a une erreur irrémédiable (ENOMEM dans notre cas) */
      return 0;
    case -1:
    	perror("fork");
    	return EXIT_FAILURE;
  	break;
    	/* Si on est dans le fils */
    case 0:
    	child_process(f);
  	break;
    	/* Si on est dans le père */
    default:
    	father_process(pid);
  	break;
    }
    return 1;
}
#else
int		fork_test(int (*f)())
{
   	if ((*f)()){
			ft_putendl(" .. OK");
			//_exit(EXIT_SUCCESS);
      return(SUCCESS);
		}else{
			ft_putendl(" .. KO");
			_exit(EXIT_FAILURE);
		}
}
#endif




int main()
{
//#undef FORK_TEST
//#define FORK_TEST(f) f()

#if 0
	FORK_TEST(main_test_ft_strnstr);
	//FORK_TEST(main_test_ft_strdup);
  FORK_TEST(main_test_ft_strcpy);
#else
	FORK_TEST(main_test_ft_memset);
	FORK_TEST(main_test_ft_bzero);
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
	FORK_TEST(main_test_ft_lstadd);
	FORK_TEST(main_test_ft_lstdelone);
	FORK_TEST(main_test_ft_lstdel);
	FORK_TEST(main_test_ft_lstiter);
	FORK_TEST(main_test_ft_strsub);
  FORK_TEST(main_test_ft_lstmap);

  FORK_TEST(main_test_ft_putchar);


#endif
	/*ft_putendl("#############################################################");
	ft_putendl("##############     ALL TESTS ARE "GREEN_OK"       ###################");
	ft_putendl("#############################################################");*/
	return (0);
}
