<div align="center">
  
  ![Philosophers Diagram](philo/philosophers.png)
  # Philosophers Project
</div>

<div align="center">
  <h2>
    <a href="#about-project" style="text-decoration:none;">📜 About Project</a> &nbsp;&bull;&nbsp;
    <a href="#mandatory-part" style="text-decoration:none;">🔷 Mandatory Part</a> &nbsp;&bull;&nbsp;
    <a href="#bonus-part" style="text-decoration:none;">🌟 Bonus Part</a> &nbsp;&bull;&nbsp;
    <a href="#skills-acquired" style="text-decoration:none;">💡 Skills Acquired</a>
  </h2>
</div>

## <a id="about-project"></a>📜 About Project
The **42 School Philosophers Project** is based on the [Dining Philosophers Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem).  
The main goal is to learn **concurrent programming** and **synchronization using shared resources**.

For full details, refer to the official project subject.

**🚀 TL;DR:**  
Learn the basics of multithreading and multiprocessing:  
- Manage shared memory between threads or processes.  
- Use **mutexes**, **semaphores**, and coordinate access to shared resources.

## <a id="mandatory-part"></a>🔷 Mandatory Part
The project simulates philosophers sitting at a **round table**:  
- A **bowl of spaghetti** is placed in the center.  
- Eating requires **two forks**, one for each hand.  
- Each philosopher alternates between **eating**, **sleeping**, and **thinking**.  
- If a philosopher doesn't eat within a certain time, they **die of starvation**.  
- Philosophers **cannot communicate** with each other.


### Program Arguments
```bash
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
