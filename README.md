# test_libft42
===================
Notice explicative:
===================

Placer le rep du dépot de votre libft au même niveau que celui du testeur, car celui-ci va recuperer vos ft*.c dans ../libft/ Si besoin vous pouvez aussi creer un lien symbolique vers ce repertoire.

Soyons bref: tapez les lignes suivantes:

	mkdir testonslalibft
	cd testonslalibft
	#remplacer <lechemindemalibft> par le chemin de votre libft
	ln -s <lechemindemalibft> libft
	git clone https://github.com/mysthair/test_libft42 
	cd test_libft42
	make

Remarque concernant les Linuxiens : certaines fonctions sont manquantes dans la librairie standart glibc et donc il m'a faut les ajouter pour pouvoir compiler le testeur. Je ne suis pas certain des implementations que j'ai inserer dans test_libft.c. Leur compilation dépend de la macro HAVE_STRLCPY qui est gérée depuis le Makefile. Mais inutile de s'en occuper : c'est automatique.

#ici la traduction en english :
(TODO : traduct the notice :P)
