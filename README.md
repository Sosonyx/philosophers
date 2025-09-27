# Philosophers

![Diagramme des philosophes](img/philosophers.png "Diagramme des philosophes")

Projet 42 – simulation du problème classique des philosophes mangeurs, avec gestion de threads et synchronisation.

---

## Comment utiliser

- **Compiler** le programme :  

    make
    ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

    make bonus
    ./philo_bonus number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

---

## Objectif

Écrire un programme qui simule le problème des philosophes mangeurs en respectant les contraintes suivantes :

- Chaque philosophe pense, mange et dort.  
- Pour manger, un philosophe doit prendre deux fourchettes (ou sémaphores en version bonus).  
- Le programme doit éviter les **deadlocks** et gérer correctement la synchronisation des threads ou des processus.  
- La sortie doit être cohérente : chaque action (prendre une fourchette, manger, dormir, mourir) doit être affichée avec un timestamp précis.  
- Le projet a deux versions :  
  - **Mandatory** → threads et mutex  
  - **Bonus** → processus et sémaphores

---

## Fonctions principales

- `main(int argc, char **argv)` : parse les arguments, initialise la table et lance la simulation.  
- Parsing sécurisé et validation des arguments (nombres valides, supérieurs à zéro).  
- `routine(void *arg)` : routine principale de chaque philosophe (prendre les fourchettes, manger, dormir, penser).  
- `take_forks(t_philo *philo)` : gestion de la prise des fourchettes avec synchronisation.  
- `eat(t_philo *philo)` : met à jour le temps du dernier repas et incrémente le compteur de repas.  
- `sleep(t_philo *philo)` : simule le sommeil puis la réflexion du philosophe.  
- `monitoring(void *ptr)` : surveille la santé des philosophes et arrête la simulation si l’un d’eux meurt.  
- Gestion des threads (`pthread_create`, `pthread_join`) et des mutex pour la version mandatory.  
- Gestion des processus et sémaphores (`sem_open`, `sem_wait`, `sem_post`) pour la version bonus.

---

## Exemple d’exécution

    ./philo 4 410 200 200
    0 1 has taken a fork
    0 1 has taken a fork
    0 1 is eating
    200 1 is sleeping
    210 2 has taken a fork
    210 2 has taken a fork
    210 2 is eating
    ...

---

## Connaissances acquises

- Utilisation des **threads** et **mutex** pour gérer la concurrence.  
- Maîtrise des **sémaphores** et **processus** dans la version bonus.  
- Synchronisation précise pour éviter les **deadlocks** et conditions de course.  
- Gestion des **timestamps** avec `gettimeofday` pour afficher le temps écoulé.  
- Affichage **atomique** des logs pour éviter les sorties entremêlées.  
- Parsing robuste et vérification des arguments en entrée.  
- Architecture modulaire claire et code conforme aux normes 42.  
- Approfondissement de la **programmation concurrente** et de la synchronisation système.
