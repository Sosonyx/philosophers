# Logo
Philosophers Project  
42 Paris Philosophers  

For further information about 42cursus and its projects, please refer to 42cursus repo.

---

📜 **About Project · 🔷 Mandatory Part · 🌟 Bonus Part · 👨‍💻 Usage**

---

## 📜 About Project

42 School Philosophers project designed around Edsger Dijkstra's famous dining philosophers problem.  
For this project, we must learn about concurrent programming and shared memory synchronization.

For detailed information, refer to the subject of this project.

🚀 **TLDR:** This project is an introduction to the basics of multithreading and multiprocessing.  
Work on the same memory space, learn about mutexes, semaphores, and shared memory.

---

### Note

Because of 42 School norm requirements:

- Each function can't have more than 25 lines of code.  
- All variables are declared and aligned at the top of each function.  
- Project should be created just with allowed functions otherwise it's cheating.


## Main Functions

- `main(int argc, char **argv)` : parses the arguments, initializes the table, and starts the simulation.  
- Secure argument parsing and validation (valid numbers, greater than zero).  
- `routine(void *arg)` : main routine for each philosopher (taking forks, eating, sleeping, thinking).  
- `take_forks(t_philo *philo)` : manages taking forks with proper synchronization.  
- `eat(t_philo *philo)` : updates the last meal time and increments the meal counter.  
- `sleep(t_philo *philo)` : simulates the philosopher sleeping and then thinking.  
- `monitoring(void *ptr)` : monitors the philosophers' health and stops the simulation if one dies.  
- Thread management (`pthread_create`, `pthread_join`) and mutexes for the mandatory version.  
- Process and semaphore management (`sem_open`, `sem_wait`, `sem_post`) for the bonus version.

---

## Example Execution

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

## Skills Acquired

- Use of **threads** and **mutexes** for concurrency management.  
- Mastery of **semaphores** and **processes** in the bonus version.  
- Precise synchronization to avoid **deadlocks** and race conditions.  
- Management of **timestamps** with `gettimeofday` to display elapsed time.  
- **Atomic** logging to prevent mixed outputs.  
- Robust argument parsing and validation.  
- Clear modular architecture and code compliant with 42 school norms.  
- Deepened understanding of **concurrent programming** and system synchronization.
