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

## Comment utiliser

- **Compiler le programme :**
```bash
make
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

make bonus
./philo_bonus number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
