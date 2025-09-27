# Philosophers Project

![Diagram](img/philosophers.png)

42 Yerevan – Dining Philosophers Project

---

## 📜 Table of Contents

- [About Project](#about-project)  
- [🔷 Mandatory Part](#mandatory-part)  
- [🌟 Bonus Part](#bonus-part)  
- [👨‍💻 Usage](#usage)  

---

## About Project

42 School Philosophers project based on Dijkstra's dining philosophers problem.  
Learn concurrent programming, shared memory synchronization, mutexes, and semaphores.

---

## 🔷 Mandatory Part

- Threads and mutexes version  
- Each philosopher runs in its own thread  
- Proper synchronization to avoid deadlocks  
- Functions: `routine`, `take_forks`, `eat`, `sleep`, `monitoring`  

[Back to top](#philosophers-project)

---

## 🌟 Bonus Part

- Processes and semaphores version  
- Each philosopher runs in its own process  
- Shared memory for state tracking  
- Semaphore-based fork management  

[Back to top](#philosophers-project)

---

## 👨‍💻 Usage

**Compile and run:**

    make
    ./philo 4 410 200 200

**Bonus version:**

    make bonus
    ./philo_bonus 4 410 200 200

**Example output:**

    0 1 has taken a fork
    0 1 has taken a fork
    0 1 is eating
    200 1 is sleeping


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
