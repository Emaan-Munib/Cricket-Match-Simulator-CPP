
# 🏏 Cricket Match Simulator & Live Scoreboard

### C++ | Object-Oriented Programming | Match Simulation | File Handling

A console-based **Cricket Match Simulator and Live Scoreboard** developed in C++ using Object-Oriented Programming (OOP) principles.

The application simulates cricket matches between international teams, generating ball-by-ball scores, wickets, match commentary, and results. It supports multiple cricket formats, interactive scoreboard updates, team selection, match replays, and super-over scenarios.

The project was developed to apply **inheritance, encapsulation, constructors, destructors, operator overloading, file handling, and STL containers** in a practical simulation.

---

## 🌟 Features

### 🏟️ Multiple Cricket Formats

The simulator supports four match types:

| Match Format | Configured Overs |
|---|---:|
| International Test | 120 |
| 3-Day Match | 70 |
| One-Day International (ODI) | 50 |
| T20 | 20 |

Each format has its own score-generation method, allowing different simulation behavior.

### 🌍 International Team Selection

Users can select from three matchups:

- Pakistan vs India
- Pakistan vs Australia
- Pakistan vs New Zealand

Team information is loaded from external text files.

### 🎲 Automated Match Simulation

The application generates cricket events using randomized values.

Features include:

- Ball-by-ball run generation
- Wicket generation
- Match-format-specific scoring methods
- Innings simulation
- Target calculation
- Winner determination
- Tie handling with a super over

The simulation also applies custom rules to limit the frequency of certain scoring events and wickets.

### 📊 Interactive Live Scoreboard

The console displays match progress as the innings unfolds.

The scoreboard includes:

- Team name
- Total runs
- Wickets
- Overs completed
- Run rate
- Match commentary

The simulation uses timed updates to create a live-scoreboard experience.

During score playback, the user can press a key to enter a replacement ball outcome.

### 🎙️ Dynamic Match Commentary

The simulator displays commentary for selected match events, including:

- Boundaries
- Sixes
- Wickets
- Potential hat-tricks
- Bowling performances

Commentary is presented using console text and ANSI color codes.

### 🪙 Toss and Match Setup

Before a match begins, the application simulates a toss and determines which team bats first.

It also presents match information, including:

- Venue
- Umpires
- Commentators
- Ground staff
- Broadcasting partners
- Team lineups

The simulator includes a countdown before match play.

### 🏆 Match Results and Super Overs

At the end of a match, the application compares the teams' total runs and announces the winner.

If the scores are tied, the program contains a super-over simulation to determine the result.

### 🔄 Match Replay

The program stores match objects in an STL vector during execution.

Users can:

- View the ball-by-ball score sequence
- Select a previously simulated match
- Replay its scoring sequence
- Start a new match

Match history is maintained in memory during the current program session.

---

## 🛠️ Technology Stack

| Category | Technology |
|---|---|
| Programming Language | C++ |
| Programming Paradigm | Object-Oriented Programming |
| User Interface | Console / Command Line |
| Data Structures | `std::vector`, `std::string` |
| File Handling | `std::ifstream` |
| Randomization | `rand()`, `srand()` |
| Timing | Windows `Sleep()` |
| Keyboard Input | `<conio.h>` |
| Console Operations | Windows console commands |
| Development Environment | Windows-compatible C++ compiler |

---

## 🧠 Object-Oriented Programming Concepts

This project demonstrates several fundamental OOP concepts.

### 1. Inheritance

The implementation uses a multilevel class hierarchy:

```text
Fast_Scoreboad
      |
      v
    Match
      |
      v
    Team
```

The `Cricket` class manages match-level behavior using team objects and inherited functionality.

The hierarchy separates scoring data, match simulation, and team-related operations.

### 2. Encapsulation

Classes group related state and operations.

Examples include:

- Runs and wickets
- Overs and balls
- Match format
- Team names
- Target scores
- Match results

Methods provide the functionality needed to initialize, simulate, and display match information.

### 3. Constructors and Destructors

Constructors initialize match and scoreboard properties, including:

- Runs
- Wickets
- Match type
- Maximum overs
- Team name

Destructors are also defined for cleanup of class-owned containers.

### 4. Operator Overloading

The implementation demonstrates custom operator behavior, including:

- `operator()` for initializing or reconfiguring objects
- `operator<<` for displaying match information
- `operator[]` in the `Cricket` class

These examples demonstrate how operators can be customized for user-defined classes.

### 5. STL Containers

The project uses `std::vector` to manage:

- Team information
- Ball-by-ball scores
- Match history
- Player-related statistics containers

The main menu stores match objects in:

```cpp
vector<Cricket> matches;
```

### 6. File Handling

The simulator reads team information from text files.

Example:

```cpp
ifstream infile(Teamname + ".txt");

string line;

while (getline(infile, line)) {
    team.push_back(line);
}

infile.close();
```

This allows team data to be maintained separately from the source code.

---

## 🏗️ Application Architecture

```text
                   MAIN MENU
                       |
                Select Teams
                       |
              Select Match Type
                       |
                 Cricket Class
                       |
          +------------+------------+
          |                         |
       Team A                    Team B
          |                         |
       Team Data                 Team Data
          |                         |
          +------------+------------+
                       |
                  Toss Result
                       |
                First Innings
                       |
                Second Innings
                       |
              Score Comparison
                       |
              +--------+--------+
              |                 |
           Winner              Tie
                                |
                            Super Over
                       |
                  Match Result
                       |
               Post-Match Menu
                       |
        +--------------+--------------+
        |              |              |
   Ball-by-Ball      Replay        New Match
      Scores          Match
```

---

## 📂 Project Structure

The main source files are:

```text
Cricket-Match-Simulator-CPP/
|
|-- Fast_Scoreboad.cpp
|-- Fast_Scoreboad.h
|-- Menu.cpp
|-- Try.cpp
|
|-- Pakistan.txt
|-- India.txt
|-- Australia.txt
|-- New Zealand.txt
|
|-- README.md
```

**Note:** The header file and team text files are required for the complete project. The structure above reflects the source-file references; the contents of the uploaded ZIP could not be verified.

### Main Files

**`Fast_Scoreboad.cpp`**

Contains the implementation of the cricket simulation classes and supporting functionality, including:

- Match scoring algorithms
- Scoreboard updates
- Match commentary
- Toss simulation
- Match initialization
- Team loading
- Super-over handling
- Winner determination
- Replay logic

**`Fast_Scoreboad.h`**

Referenced by the main source files and expected to contain class declarations.

**`Menu.cpp`**

Contains the main application entry point and interactive menus for:

- Selecting teams
- Selecting match formats
- Starting matches
- Viewing ball-by-ball scores
- Replaying matches
- Starting new matches
- Exiting the application

**`Try.cpp`**

Contains a small file-reading helper function that demonstrates loading and printing text-file content.

---

## ⚙️ Installation and Execution

### Prerequisites

- Windows operating system
- A C++ compiler supporting the project's language features
- Visual Studio with the Desktop development with C++ workload, or another compatible Windows C++ environment

The application uses:

```cpp
#include <windows.h>
#include <conio.h>
```

These are Windows-specific dependencies.

### 1. Clone the Repository

```bash
git clone https://github.com/Emaan-Munib/Cricket-Match-Simulator-CPP.git
cd Cricket-Match-Simulator-CPP
```

### 2. Prepare Project Files

Ensure the required source files, header files, and team text files are available.

The application opens team files using relative paths, such as:

```text
Pakistan.txt
India.txt
Australia.txt
New Zealand.txt
```

These files must be accessible from the program's working directory.

### 3. Compile the Application

Using a compatible Windows C++ compiler, compile the main application and simulation implementation.

For example, with MinGW-w64:

```bash
g++ Menu.cpp Fast_Scoreboad.cpp -o CricketSimulator.exe
```

The project may require source-level fixes or compiler-specific adjustments before compilation succeeds.

`Try.cpp` contains a separate helper function and is not required as an additional entry point.

### 4. Run the Simulator

```bash
CricketSimulator.exe
```

Follow the interactive console menus to select teams and a match format.

---

## 🎮 How to Use

### Step 1: Select Teams

The main menu presents the following options:

```text
MAIN MENU

1. Pakistan vs India
2. Pakistan vs Australia
3. Pakistan vs New Zealand
4. Exit
```

### Step 2: Choose a Match Format

```text
SELECT MATCH TYPE

1. International Test
2. 3-Day Match
3. One-Day Match
4. T20 Match
5. Back
```

### Step 3: Watch the Simulation

The program presents match setup information, performs a toss, and starts the simulated innings.

The scoreboard updates as runs and wickets are processed.

### Step 4: View the Result

After both teams complete their simulated innings, the program determines the match result.

### Step 5: Explore Post-Match Options

```text
OTHER OPTIONS

1. Ball by Ball Score
2. Replay Match
3. New Match
4. Exit
```

---

## 🔍 Key Implementation Details

### Match Format Configuration

The maximum number of overs depends on the selected format.

```cpp
if (MatchType == 1)
    MaxOvers = 120;
else if (MatchType == 2)
    MaxOvers = 70;
else if (MatchType == 3)
    MaxOvers = 50;
else if (MatchType == 4)
    MaxOvers = 20;
```

### Score Generation

The simulator generates possible ball outcomes using randomized values.

```cpp
Num = rand() % 8 - 1;
```

A negative value represents a wicket in the scoring logic.

Different match formats use separate methods:

```cpp
TestScore()
ThreeDScore()
ODIScore()
T20Score()
```

### Run Rate

The simulator calculates a run-rate value during scoreboard updates.

The existing implementation uses its numeric over representation in the calculation. This can produce inaccuracies because cricket overs are expressed as completed overs and balls rather than ordinary decimal fractions.

### Match Replay

Previously simulated matches are stored in memory and can be selected for replay.

```cpp
vector<Cricket> matches;
```

The replay feature reuses stored score sequences rather than loading matches from a persistent database.

---

## ⚠️ Known Limitations

This is an academic OOP project designed to demonstrate C++ programming concepts and simulation logic.

The existing implementation has some limitations:

- **Windows dependency:** Uses Windows-specific console functions.
- **Randomness:** Relies on `rand()` and repeated calls to `srand(time(NULL))`.
- **T20 wicket tracking:** The wicket counter is reset inside the scoring loop.
- **Winner comparison:** The tie-handling condition uses assignment instead of equality comparison.
- **Team loading:** One constructor loads the first team's filename for both teams.
- **Run rate:** Overs are represented using decimal-style notation rather than a precise ball count.
- **Replay selection:** The user-provided replay index is not bounds-checked.
- **Persistence:** Match history is not saved between application sessions.
- **Simulation accuracy:** The scoring logic is simplified and does not fully reproduce professional cricket rules.

These issues are potential areas for further development.

---

## 🚀 Future Improvements

- Fix existing scoring and winner-detection issues
- Improve wicket tracking across all match formats
- Calculate run rate using completed legal deliveries
- Use modern C++ random number generators
- Improve user input validation
- Add detailed player statistics
- Implement persistent match history
- Support additional international teams
- Add customizable team lineups
- Implement more realistic Test match innings
- Improve super-over rules
- Separate simulation logic from console presentation
- Add automated tests for match outcomes and scoring
- Improve portability across Windows, Linux, and macOS
- Add a graphical user interface

---

## 🎯 Learning Outcomes

Through this project, the following programming concepts were explored:

- Object-oriented application design
- Multilevel inheritance
- Encapsulation and class relationships
- Constructors and destructors
- Operator overloading
- Dynamic data management using STL vectors
- File input/output
- Randomized simulations
- Conditional logic and loops
- Console-based user interaction
- Managing multiple objects and application state

---

## 📌 Project Status

**Academic C++ Object-Oriented Programming Project**

The application demonstrates a console-based cricket match simulation with multiple formats, dynamic scoring, match commentary, and replay functionality.

The repository is intended to showcase C++ programming and OOP concepts. Further debugging and validation are recommended before treating the simulator as a fully reliable cricket scoring application.
