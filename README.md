# Philosophers Project

![Philosophers Diagram](img/philosophers.png)

42 Paris Philosophers  
For further information about 42cursus and its projects, please refer to the [42cursus repository](https://github.com/42cursus).

---

## 🔹 Jump to Section

[📜 About Project](#-about-project) · [🔷 Mandatory Part](#-mandatory-part) · [🌟 Bonus Part](#-bonus-part) · [👨‍💻 Usage](#-usage) · [🧠 Main Functions](#-main-functions) · [🎯 Objective](#-objective) · [💡 Skills Acquired](#-skills-acquired)

---

## 📜 About Project

The 42 School Philosophers project is based on Edsger Dijkstra's famous Dining Philosophers problem.  
The goal is to simulate a group of philosophers who alternate between eating, thinking, and sleeping, while sharing limited resources (forks) in a synchronized way to avoid deadlocks and starvation.

This project introduces the basics of **multithreading**, **multiprocessing**, **mutexes**, **semaphores**, and **shared memory synchronization**.

[Back to top](#philosophers-project)

---

## 🔷 Mandatory Part

- Threads and mutexes version.  
- Each philosopher is represented by a thread.  
- Philosophers share two forks: one to their left and one to their right.  
- The program must avoid race conditions and deadlocks.  
- Philosophers must eat, sleep, and think according to the specified timing.

[Back to top](#philosophers-project)

---

## 🌟 Bonus Part

- Implementation with **processes** and **semaphores**.  
- Shared memory is used to track philosophers' states.  
- Forks are managed with semaphores to prevent deadlocks.  
- Philosophers are monitored to detect starvation and stop the simulation if necessary.

[Back to top](#philosophers-project)

---

## 👨‍💻 Usage

### Compile and run

```bash
make
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
