<a name="readme-top"></a>
<div align="center">
  <!-- Logo -->
  <a href="https://github.com/dpetrosy/42-Philosophers">
    <img src="README_files/logo.png" alt="Logo" width="80" height="80">
  </a>

  <!-- Project Name -->
  <h1>Philosophers Project</h1>

  <!-- Short Description -->
  <p align="center">
    <b>42 Yerevan Philosophers</b><br>
    For further information about 42cursus and its projects, see <a href="https://github.com/dpetrosy/42cursus"><b>42cursus repo</b></a>.
  </p>

  <!-- Badges -->
  <p>
    <img src="https://img.shields.io/badge/score-125%20%2F%20100-success?style=for-the-badge" />
    <img src="https://img.shields.io/github/repo-size/dpetrosy/42-Philosophers?style=for-the-badge&logo=github">
    <img src="https://img.shields.io/github/languages/count/dpetrosy/42-Philosophers?style=for-the-badge" />
    <img src="https://img.shields.io/github/languages/top/dpetrosy/42-Philosophers?style=for-the-badge" />
    <img src="https://img.shields.io/github/last-commit/dpetrosy/42-Philosophers?style=for-the-badge" />
  </p>

  <!-- Menu -->
  <div style="font-size:1.3em; line-height:2;">
    <span><a href="#about-project" style="text-decoration:none; color:inherit;">📜 About Project</a></span>
    &nbsp;&bull;&nbsp;
    <span><a href="#mandatory-part" style="text-decoration:none; color:inherit;">🔷 Mandatory Part</a></span>
    &nbsp;&bull;&nbsp;
    <span><a href="#bonus-part" style="text-decoration:none; color:inherit;">🌟 Bonus Part</a></span>
    &nbsp;&bull;&nbsp;
    <span><a href="#usage" style="text-decoration:none; color:inherit;">👨‍💻 Usage</a></span>
  </div>
</div>

## <a name="about-project"></a>📜 About Project

> 42 School Philosophers project based on Edsger Dijkstra's famous [Dining Philosophers Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem).  
> Learn **concurrent programming** and **shared memory synchronization**.

For full details, see the [project subject](README_files/philo_subject.pdf).

🚀 **TL;DR**: Introduction to multithreading and multiprocessing.  
- Work on shared memory between threads/processes.  
- Use **mutexes**, **semaphores**, and coordinate access.

> **Note:**  
> - Functions ≤ 25 lines.  
> - Variables declared at the top.  
> - Only allowed functions.

---

## <a name="mandatory-part"></a>🔷 Mandatory Part

- Philosophers sit at a **round table**.  
- A **bowl of spaghetti** is in the center.  
- Eating requires **two forks** (one per hand).  
- Philosophers alternate **eating**, **sleeping**, **thinking**.  
- If a philosopher doesn’t eat in time → **dies of starvation**.  
- No communication between philosophers.

### Program Arguments

```bash
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
