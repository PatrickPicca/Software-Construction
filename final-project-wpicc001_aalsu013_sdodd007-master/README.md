
# PlannerPlus

 
 Authors: 
 
 Amneh Alsuqi https://github.com/alsuqiamneh
 
 Sri Harshit Doddapaneni https://github.com/Harshi6  
 
 William Picca https://github.com/PatrickPicca
 
## Project Description

 * The implementation of a task scheduler helps us apply our knowledge of these design patterns as well as present a world use outside of the classroom setting. 

 * We will use C++. Other tools will be introduced if needed. 
 
 * Our inputs are tasks created by the user which include titles, descriptions, optional tags, priority, duration, and due dates.         
 * Our outputs will be a variety of visuals specified either by the user or through the program itself based on user preference, the information the user has stored to be displayed at a later day.


* The two design patterns we would use are composite pattern and strategy pattern.
* The strategy pattern allows us to implement various strategies for prioritizing given tasks from the user, along with giving the user the freedom to output tasks in different formats. For example, the user may want to implement multiple headers under a single task or choose to create a note for a task. Using the strategy pattern, we can implement these different algorithms so that the user has the ability to customize their tasks. 
* The composite pattern allows us to implement different features to tasks. Using the composite pattern also permits the user to create subtasks, lists that include multiple tasks, as well as descriptions pertaining to specified tasks. Problems that we expect to run into include accurately composing these objects into their respected tree structures so that they are ordered exactly how the user specifies. Inaccurately displaying the hierarchy the user wants would go against the overall purpose of the task scheduler and its features.  




## Class Diagram
![Untitled Diagram-2-2](https://user-images.githubusercontent.com/81607334/120364446-1b284500-c2c2-11eb-81dd-e6bb4dc98166.png)


 
 ## Screenshots
 The following are screenshots of the input/output after running PlannerPLUS:
 
 Creating a school task:
 
 ![Screen Shot 2021-05-31 at 7 23 25 PM](https://user-images.githubusercontent.com/81607334/120348970-89650b80-c2b2-11eb-8619-fd7f688aa981.png)
 
 Creating a personal task:
 
 ![Screen Shot 2021-05-31 at 7 23 45 PM](https://user-images.githubusercontent.com/81607334/120348999-908c1980-c2b2-11eb-95f8-587464589892.png)
 
 Editing a task:
 
 ![Screen Shot 2021-05-31 at 7 24 39 PM](https://user-images.githubusercontent.com/81607334/120349031-984bbe00-c2b2-11eb-8d15-04d8073d8a3c.png)
 
 Displaying Planner:
 
 ![Screen Shot 2021-05-31 at 7 24 52 PM](https://user-images.githubusercontent.com/81607334/120349063-9eda3580-c2b2-11eb-9095-bc87c86ce5a9.png)
 
 Sorting by highest priority:
 
 ![Screen Shot 2021-06-01 at 8 32 21 AM](https://user-images.githubusercontent.com/81607334/120350988-515ec800-c2b4-11eb-9fbe-57d54b581dbd.png)
 
 Filtering to only display personal tasks:
 
 ![Screen Shot 2021-06-01 at 8 32 38 AM](https://user-images.githubusercontent.com/81607334/120351072-650a2e80-c2b4-11eb-976d-6d83f4492f3b.png)

 
 ## Installation/Usage
 To use PlannerPlus, you must first clone this repository onto your platform.
After obtaining the necessary files, you will need to install CMake in order to run the application.
The following link gives instructions on how to install CMake, depending on your platform:

https://cmake.org/install/

Afterwards, paste the following into your command line:

cmake3 .

make

./tests

PlannerPlus will launch and be ready for user input. 
 ## Testing
 Our project was tested with both CI and unit tests for our files. We also made sure to create checks for user input, in case an invalid input occurs. In that case, PlannerPlus should prompt the user to try again with a valid input. Our README file does have a “passing badge”. 
 
 Screenshot of passing tests:
 
 ![image](https://user-images.githubusercontent.com/81607334/120365174-f7193380-c2c2-11eb-99cd-e6bddb31e89e.png)




 
