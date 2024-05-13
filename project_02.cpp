// Tic Tac Toe Game

#include<bits/stdc++.h> // Include necessary header files
#include<conio.h>
using namespace std;

// Function to add player's move to the board
void add(char a[3][3],char inp,char ch)
{
    int num=inp-49,row,col; // Convert input character to corresponding array index
    row=num/3,col=num%3;
    a[row][col]=ch; // Update board with player's move
}

// Function to display the current state of the board
void disp(char a[3][3])
{
    cout<<"\n\t\tPress Esc anytime to quit the game\n\n\n\n"; // Display instructions
    int i,j;
    for(i=0;i<3;i++)
    {
        cout<<"\t\t\t\t-------------\n\t\t\t\t"; // Print horizontal separators
        for(j=0;j<3;j++)
        {
            if(a[i][j]=='a') cout<<"|   "; // Print empty cell
            else
                cout<<"| "<<a[i][j]<<" "; // Print cell with player's move
        }
        cout<<"|"<<endl; // End of row
    }
    cout<<"\t\t\t\t-------------\n"; // Print bottom horizontal separator
}

// Function to check if the move is valid
int check(char a[3][3],char inp)
{
    int num=inp-48,row,col;
    if(num<=0 || num>=10) return 0; // Check if input is between 1 to 9
    num--;
    row=num/3;
    col=num%3;
    if(a[row][col]=='a') return 1; // Check if cell is empty
    else return 0;
}

// Function to check if the game is over and return the winner
char gameover(char a[3][3])
{
    char winner='a'; // Initialize winner as 'a' (no winner)
    if(a[0][0]==a[0][1] && a[0][0]==a[0][2] && a[0][0]!='a') winner=a[0][0]; // Check first row
    if(a[1][0]==a[1][1] && a[1][0]==a[1][2] && a[1][0]!='a') winner=a[1][0]; // Check second row
    if(a[2][0]==a[2][1] && a[2][0]==a[2][2] && a[2][0]!='a') winner=a[2][0]; // Check third row
    if(a[0][0]==a[1][0] && a[0][0]==a[2][0] && a[0][0]!='a') winner=a[0][0]; // Check first column
    if(a[0][1]==a[1][1] && a[0][1]==a[2][1] && a[0][1]!='a') winner=a[0][1]; // Check second column
    if(a[0][2]==a[1][2] && a[0][2]==a[2][2] && a[0][2]!='a') winner=a[0][2]; // Check third column
    if(a[0][0]==a[1][1] && a[0][0]==a[2][2] && a[0][0]!='a') winner=a[0][0]; // Check diagonal from top-left to bottom-right
    if(a[0][2]==a[1][1] && a[0][2]==a[2][0] && a[0][2]!='a') winner=a[0][2]; // Check diagonal from top-right to bottom-left
    return winner; // Return winner (if any)
}

// Function to check if the game is a draw
int draw(char a[3][3])
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(a[i][j]=='a')
                return 0; // If any cell is empty, return false
    return 1; // Otherwise, return true (draw)
}

// Main function
int main()
{
    cout<<"\n\n\n\n\t\t\tTic Tac Toe\n\n\n\t\tPress any key to continue"; // Print game title
    getch(); // Wait for user input
    char a[3][3],turn[2]={'X','O'},ch='X',inp,winner,res; // Declare variables
    do
    {
        a[0][0]=a[0][1]=a[0][2]=a[1][0]=a[1][1]=a[1][2]=a[2][0]=a[2][1]=a[2][2]='a'; // Initialize board with empty cells
        system("cls"); // Clear console screen
        disp(a); // Display the board
        cout<<"\n\n\t\t\t"<<ch<<"'s Turn\n\n"; // Print current player's turn
        int count=0; // Initialize move count
        while(1) // Infinite loop for player moves
        {
            inp=getch(); // Get user input
            system("cls"); // Clear console screen
            if(inp<=48 || inp>=58 || !check(a,inp)) // Check if input is valid
            {
                disp(a); // Display the board
                cout<<"\n\n\t\t\t"<<ch<<"'s Turn\n\n"; // Print current player's turn
                cout<<"INVALID MOVE!!\n\n"; // Print error message
            }
            else
            {
                add(a,inp,ch); // Add player's move to the board
                disp(a); // Display the board
                winner=gameover(a); // Check if game is over
                if(winner=='a') // If no winner yet
                {
                    if(draw(a)) // Check if it's a draw
                    {
                        cout<<"\n\n\t\t\tMatch Drawn !!\n"; // Print draw message
                        break; // End the game
                    }
                    ch=turn[(++count)%2]; // Switch player's turn
                    cout<<"\n\n\t\t\t"<<ch<<"'s Turn\n\n"; // Print current player's turn
                }
                else // If there's a winner
                {
                    cout<<"\n\n\t\t\t"<<winner<<" Won !!\n"; // Print winner message
                    break; // End the game
                }
            }        
        }
        getch(); // Wait for user input
        system("cls"); // Clear console screen
        cout<<"\n\n\n\n\t\t\tWant to play more ? (Y/N) : "; // Ask user to play again
        cin>>res; // Get user's response
    }while(res=='y' || res=='Y'); // Continue loop if user wants to play again
}
