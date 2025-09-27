# Philosophers

Projet 42 – simulation du problème classique des philosophes mangeurs, avec gestion de threads et synchronisation.

---

## Comment utiliser

- **Compiler le programme :**  
```bash
make
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

make bonus
./philo_bonus number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

Objectif

Écrire un programme qui simule le problème des philosophes mangeurs en respectant les contraintes suivantes :

Chaque philosophe pense, mange et dort.

Pour manger, un philosophe doit prendre deux fourchettes (ou sémaphores en version bonus).

Le programme doit éviter les deadlocks et gérer correctement la synchronisation des threads ou des processus.

La sortie doit être cohérente : chaque action (prendre une fourchette, manger, dormir, mourir) doit être affichée avec un timestamp précis.

Le projet a deux versions : mandatory avec threads et mutex, bonus avec processus et sémaphores.

Fonctionnalités principales

ft_routine(void *philo)
Routine principale de chaque philosophe : pense, prend les fourchettes, mange, puis dort, en boucle jusqu’à la fin des conditions.

ft_take_forks(t_philo *philo)
Gestion de la prise des fourchettes avec mutex ou sémaphores pour éviter les conflits.

ft_eat(t_philo *philo)
Simule l’action de manger : met à jour le timestamp de dernier repas, incrémente le compteur de repas et gère le délai d’alimentation.

ft_sleep_think(t_philo *philo)
Simule le sommeil puis la réflexion du philosophe.

ft_monitoring(t_table *table)
Thread ou processus détaché qui surveille la santé des philosophes et détecte les morts éventuelles.

ft_create_threads(t_table *table)
Crée les threads pour chaque philosophe (ou processus en bonus) et lance la routine.

Connaissances acquises

Maîtrise des threads (pthread_create, pthread_detach, pthread_join) et mutex pour la synchronisation.

Gestion des processus et sémaphores dans la version bonus.

Synchronisation fine pour éviter deadlocks et conditions de compétition.

Gestion du temps précis avec gettimeofday pour les timestamps.

Gestion des sorties standard de manière atomique pour éviter les logs mélangés.

Découpage fonctionnel et architecture modulaire claire.

Création et utilisation d’un Makefile respectant les normes 42.

Compréhension approfondie de la programmation concurrente et des contraintes systèmes.
