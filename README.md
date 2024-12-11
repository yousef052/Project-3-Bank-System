Project Title: Client Management System
This is a console-based client management system that applies Object-Oriented Programming (OOP) principles to organize the functionalities efficiently. It allows users to manage client data, transactions, user authentication, and currency exchange. The application is divided into several screens, each responsible for a specific task, and demonstrates key OOP concepts such as Encapsulation, Abstraction, Inheritance, and Polymorphism.

OOP Principles Applied:
Encapsulation:

Each screen (such as clsClientListScreen, clsAddNewClientScreen, etc.) is encapsulated in its own class to manage its internal data and behavior. This ensures that only relevant information is exposed to the user, and implementation details are hidden from them. For example, client management functionalities are encapsulated within the clsClientListScreen and other related classes, exposing only what is necessary for user interaction.
Abstraction:

The system uses abstraction to simplify interactions. The clsMainScreen class abstracts away the complexity of handling multiple screens and only exposes a simple interface for the user to choose between different actions (view clients, add new clients, manage transactions, etc.). Users interact with high-level operations without needing to understand the details behind each screen.
Inheritance:

The project demonstrates inheritance through the use of a base class clsScreen, which is inherited by all other screen classes like clsClientListScreen, clsAddNewClientScreen, and others. This allows shared functionality (such as displaying menus or handling user input) to be centralized in the base class, promoting code reuse and reducing redundancy.
Polymorphism:

Polymorphism is applied by overriding functions in derived classes to handle different types of screens (e.g., client management, user management). This makes it easy to manage different screen functionalities and ensures flexibility in modifying or extending the system.
Modular Design:

The application is modular, with each screen representing a separate class with its own responsibilities. This modular approach follows the Single Responsibility Principle, where each class is focused on one specific task, such as displaying the client list or handling user login.
Key Features:
Client Management: Add, delete, update, and view client information.
Transactions: Manage and view transactions.
User Management: Add, update, or remove users.
Currency Exchange: Access currency exchange functionalities.
Login/Registration: Secure user authentication system.
By leveraging OOP principles, this system maintains scalability, readability, and flexibility, ensuring that new features can be added or existing features modified without breaking the core functionality.
