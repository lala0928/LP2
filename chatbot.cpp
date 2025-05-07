//  Develop an elementary chatbot for any suitable customer interaction application
#include <iostream>  // Required for input/output operations (cin, cout)
#include <string>    // Required to use the 'string' class and its functions
#include <algorithm>  // Needed for std::transform

using namespace std; // Allows usage of standard C++ objects without prefixing with 'std::'

// Function to generate bot responses based on user input
string generateResponse(const string& userInput) {
    // Simple if-else logic to handle known user inputs and generate responses

    if (userInput == "hello") {
        return "Hi there! How can I assist you today?";  // Respond to greeting
    } else if (userInput == "how are you?") {
        return "I'm just a program, but thanks for asking!";  // Respond politely
    } else if (userInput == "bye") {
        return "Goodbye! Have a great day!";  // Exit message
    } else {
        return "Sorry, I didn't understand that. Can you please rephrase?";  // Default fallback
    }
}

int main() {
    string userInput;  // To store user’s input

    // Welcome message displayed once at the start of the chat
    cout << "Welcome! How can I assist you today?" << endl;
    cout << "You can start typing your questions or messages." << endl;
    cout << "Type 'bye' to exit the chat." << endl;

    // Main loop to keep the chat running until the user types "bye"
    while (true) {
        cout << "You: ";          // Prompt user input
        getline(cin, userInput);  // Read full line of input from the user

        // Convert user input to lowercase for case-insensitive comparison
        transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);

        // Check if the user wants to end the conversation
        if (userInput == "bye") {
            cout << "Bot: Goodbye! Have a great day!" << endl;  // Farewell message
            break;  // Exit the loop and end the program
        }

        // Generate and display bot’s response using the response-generating function
        cout << "Bot: " << generateResponse(userInput) << endl;
    }

    return 0;  // End of program
}

// you: hello
// Bot: Hi there! How can I assist you today?
// you:how are you?
// Bot: I'm just a program, but thanks for asking!
// You: what can you do?
// Bot: Sorry, I didn't understand that. Can you please rephrase?
// You: BYE
// Bot: Goodbye! Have a great day!


