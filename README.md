<div align="center">
  ![Philosophers Diagram](philo/philosophers.png)
</div>

# Philosophers Project

## [📜 About Project](About.md) · [🔷 Mandatory Part](Mandatory.md) · [🌟 Bonus Part](Bonus.md) · [💡 Skills Acquired](Skills.md)

# Usage

## 📜 About Project
The **42 School Philosophers Project** is based on the [Dining Philosophers Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem).  
The main goal is to learn **concurrent programming** and **synchronization using shared resources**.

For full details, refer to the official project subject.

**🚀 TL;DR:**  
Learn the basics of multithreading and multiprocessing:  
- Manage shared memory between threads or processes.  
- Use **mutexes**, **semaphores**, and coordinate access to shared resources.


---

## ⚠️ Note
Following **42 School coding norms**:  
- Functions must not exceed **25 lines**.  
- All variables should be **declared at the top** of each function.  
- Only **allowed functions** may be used.

---

## 🔷 Mandatory Part
The project simulates philosophers sitting at a **round table**:  
- A **bowl of spaghetti** is placed in the center.  
- Eating requires **two forks**, one for each hand.  
- Each philosopher alternates between **eating**, **sleeping**, and **thinking**.  
- If a philosopher doesn't eat within a certain time, they **die of starvation**.  
- Philosophers **cannot communicate** with each other.

### Program Arguments
```bash
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
