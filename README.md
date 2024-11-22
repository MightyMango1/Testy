# Testy
 
> Authors: <br>
 &emsp;\<[Nolan Kosmal](https://github.com/Mightymango1)\>
> <br>
 &emsp;\<[Morlae Letuli](https://github.com/mononomon)\>
> <br>
 &emsp;\<[Chao Wei Hsu](https://github.com/lowbabun)\>
> <br>
 &emsp;\<[Sweden Agunenye](https://github.com/swedenagu)\>
## Project Description
 Why is it important or interesting to you?
 > Our project is important because it helps academic achievers effectively study by reinforcing concepts in a fun and interactive way. Testy has the potential to transform how people learn and retain information. As developers, we're passionate about developing tools that make studying more engaging and accessible, and we find it fascinating how technology can be leveraged to personalize learning experiences for each user. With features like custom quizzes, spaced repetition, and flashcards, the app can adapt to individual learning styles, helping users study more efficiently and retain knowledge longer.

 What languages/tools/technologies do you plan to use? (This list may change over the course of the project)</u>
 > C++ / Node.js for the backend, Next.js & TailwindCSS for the frontend.
> We will use Next-auth for login authentication
> SQLite will act as the database to store user flashcard sets

 What will be the input/output of your project?
 >  Input will be buttons and text input from our UI. <br>
 > Output will be flashcards that the user had previously created.

 What are the features that the project provides?
 > - Account Creation and login
>  - Creating flashcard sets
 > - Adding and saving flashcards
 > - deleting flashcards
 > - editing flashcards
 > - creating quizzes using existing flashcards from a set

### User Epics
> Add study sets
> * Story: Add ability for the user to create their own study sets with flashcards

> Edit study sets
> * Story: Allow users to edit the flashcard decks and individual cards they make. This should include changes to the title or description of different flashcards as well as changing the order of the set.

> Title/description for cards
> * Story: Give users the option to make a front word/term and a back description for each card in a set

> Save edits to cards
> * Story: Integrate changes made by the user to individual cards or study sets. Think of how to best keep track of updates to different components of sets a user would make.

> Delete study sets + individual flashcards
> * Story: Allow users to delete flashcard decks instead of leaving them as duplicates or unused sets. Make sure users also have the option to delete individual flashcards.


### Navigation Diagram
> ![image](https://github.com/user-attachments/assets/2cef4ecc-9965-4202-b245-d89bf719466c)
> The navigation diagram shows the main functionality of the application and what to do in order to access each specific function (e.x profile or create new sets). 


### Screen Layouts
> <img width="301" alt="image" src="https://github.com/user-attachments/assets/81df02b0-4266-4537-a9b2-548d31b19cea">
> <br>
> Home Page: Shares the same navigation bar as most other pages. Main functions are to give a brief overview of the application and to bring the user to "Study Sets" page or login/signup page.
> <br>
> <img width="239" alt="image" src="https://github.com/user-attachments/assets/fd590aff-073f-4df5-8dfd-dbf1f297b69a">
> <br>
> Login and Signup pages: Does not include a navigation bar; only a button to return to the home page. Main function is to log the user into the application or sign up if they don't already have an account in the DB.
> <br>
> <img width="230" alt="image" src="https://github.com/user-attachments/assets/fc80401d-9f3a-40ff-b381-e89ec08c769f">
> <br>
> Study Sets page: Displays all the user's created study sets. Includes the option to create a new study set or generate a multiple choice quiz based on an existing study set.
> <br>
> <img width="302" alt="image" src="https://github.com/user-attachments/assets/12b9b341-fb7c-484a-9d3f-cd91326081e3">
> <br>
> Create Set page: Allows the user to create and save a study set by building individual flashcards. Allows the user to edit or delete existing flashcards within a set.
> <br>







## Class Diagram
<img width="703" src="https://github.com/user-attachments/assets/457cb296-0fb2-4620-a129-565d1522836f">



 
 > ## Phase III
1. Single Responsibility Principle (SRP)
* How it was applied:
> The creation of a database class separated concerns by isolating database-related operations (e.g., CRUD operations) into its own class.
> By removing or refactoring the user class, we ensured that this class focuses solely on user-specific logic, avoiding responsibilities like interacting directly with the > database.
* How this helped:
> Improved maintainability by reducing the scope of each class, making them easier to understand and modify independently.
> Allowed changes in database implementation (e.g., switching from MongoDB to SQLite) without affecting user-related logic.
2. Open/Closed Principle (OCP)
* How it was applied:
> Introducing new classes (e.g., database class) allows the code to be open for extension but closed for modification. We added new classes or methods instead of
> altering existing logic to support new features or behaviors.
* How this helped:
> Enabled easier scalability and the ability to add new functionality without breaking or modifying existing code.
> Reduced the risk of introducing bugs in existing code by encapsulating new functionality.
 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history.
>  * Each team member should also submit the Individual Contributions Form on Canvas for this final phase. In this form, you need to fill in the names of all team members, the percentage of work contributed by each member for the final phase, and a description of their contributions. Remember that each team member should submit the form individually.
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
