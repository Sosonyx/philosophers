<a name="readme-top"></a>
<div align="center">
  <!-- Logo -->
  <a href="https://github.com/dpetrosy/42-Philosophers">
    <img src="philo/philosophers.png" alt="Logo" width="120" height="120">
  </a>

  <!-- Project Name -->
  <h1>Philosophers Project</h1>

  <!-- Short Description -->
  <p align="center">
    For further information about 42cursus and its projects, see <a href="https://42.fr/le-campus-de-paris/diplome-informatique/"><b>42cursus repo</b></a>.
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

./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]

- **`number_of_philosophers`**: total number of philosophers around the table  
- **`time_to_die`**: time in milliseconds a philosopher can live without eating after their last meal  
- **`time_to_eat`**: time in milliseconds it takes a philosopher to eat (holds two forks during this time)  
- **`time_to_sleep`**: time in milliseconds a philosopher spends sleeping  
- **`number_of_times_each_philosopher_must_eat`** (optional): simulation stops if all philosophers have eaten at least this many times; otherwise, simulation continues until a philosopher dies

### Logs Format

The program outputs actions of philosophers as follows (X is philosopher ID):

timestamp_in_ms X has taken a fork  
timestamp_in_ms X is eating  
timestamp_in_ms X is sleeping  
timestamp_in_ms X is thinking  
timestamp_in_ms X died

---

## 🌟 Bonus Part

- Philosophers are **processes** instead of threads  
- Forks are **counting semaphores**, freely taken from the center  
- Program arguments are identical to the mandatory part, but executable is `philo_bonus`

---

## 👨‍💻 Usage

### Requirements

- C language  
- GCC compiler  
- Standard C libraries

### Compiling the Program

**Mandatory Part:**

cd path/to/philo && make

**Bonus Part:**

cd path/to/philo_bonus && make

### Running the Program

./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]

**Example:**

./philo 5 800 200 200 7

- The program outputs actions until a philosopher dies or all have eaten the required number of times.  
- For the bonus part, run the `philo_bonus` executable instead.
"""
