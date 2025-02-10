#include <iostream>
#include <cstdlib>
#include <vector>
#include <windows.h>
#include <conio.h>
#include <algorithm>

using namespace std;

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };

Direction dir;
bool gameOver = false;
int gameScore = 0;
int high_score;
char c;
int Speed;

class Food;
class Snake;
class gameBoard;

void welcome();
void gameOverScreen(Food &food);
void logic(Snake & snake, Food & food, gameBoard & board);
void input();
void gotoxy(int x, int y);
void hideCursor();
void showCursor();

class gameBoard
{
    public:
        int width;
        int height;
    gameBoard(int width, int height)
    {
        this -> width = width;
        this -> height = height;
    }
    void display(const Food & food, const Snake & snake);
};

class Food
{
    public:
        int width, height, FoodX, FoodY;

        Food(int width, int height)
        {
            this -> width = width;
            this -> height = height;
            FoodX = rand() % width;
            FoodY = rand() % height;
        }
        void generateFood(Snake & snake);
};

class Snake
{
    public:
        int headX;
        int headY;
        vector<pair<int,int>> Body;
        Snake(int width, int height)
        {
            headX = width / 2;
            headY = height / 2;
            Body.push_back(make_pair(headX - 1, headY));
        }
};


int main(void)
{
    SetConsoleOutputCP(CP_UTF8);
    system("cls");
    welcome();
    Sleep(3000);
    system("cls");
    bool play = true;
    while (play)
    {
        FILE* ptr1 = fopen("high_score.txt", "r");
        system("cls");
        cout << "\033[93m\n";
        cout << "\n";
        cout << "\t\t\t\t\t\t\t\t\t=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\n";
        cout << "\t\t\t\t\t\t\t\t\t\033[94m                🐍  RULES TO PLAY 🐍 \033[93m\n";
        cout << "\t\t\t\t\t\t\t\t\t=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\n";
        cout << "\033[92m\n";
        cout << "\t\t\t\t\t\t\t\t\t📌 \033[95mControls:\n";
        cout << "\t\t\t\t\t\t\t\t\t   \033[92m👉 Use \033[94m'W'\033[92m (Up), \033[94m'A'\033[92m (Left), \033[94m'S'\033[92m (Down), \033[94m'D'\033[92m (Right)\n";
        cout << "\t\t\t\t\t\t\t\t\t     \033[92m to move the snake.\n";
        cout << "\t\t\t\t\t\t\t\t\t📌 \033[95mObjective:\n";
        cout << "\t\t\t\t\t\t\t\t\t   \033[92m👉 Eat the \033[91m🍎\033[92m to grow longer and gain points!\n";
        cout << "\n";
        cout << "\t\t\t\t\t\t\t\t\t📌 \033[95mAvoid:\n";
        cout << "\t\t\t\t\t\t\t\t\t   \033[92m❌ Hitting the walls 🧱\n";
        cout << "\t\t\t\t\t\t\t\t\t   ❌ Biting yourself 🐍\n";
        cout << "\n";
        cout << "\t\t\t\t\t\t\t\t\t📌 \033[95mGame Modes:\n";
        cout << "\t\t\t\t\t\t\t\t\t   \033[92m🎯 Press \033[94m(A)\033[92m for Constant Speed Mode.\n";
        cout << "\t\t\t\t\t\t\t\t\t   🚀 Press Any Other Key for Dynamic Speed Mode.\n";
        cout << "\t\t\t\t\t\t\t\t\t\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\033[91m-\033[93m=\n";
        cout << "\033[0m";
        c = _getch();
        system("cls");
        fscanf(ptr1, "%d", &high_score);
        srand(time(0));
        gameOver = false;
        gameScore = 0;
        gameBoard Board(30, 20);  
        Food food(Board.width, Board.height);
        Snake snake(Board.width, Board.height);
        hideCursor();
        if (c == 'a')
        {
            Speed = 125;
        }
        else
        {
            Speed = 200;
        }
        while(!gameOver)
        {
            Board.display(food, snake);
            input();
            logic(snake, food, Board);
            Sleep(Speed);
        }
        cout << "👉 Press (P) to Play Again.\n👉 Press Any Other Key to Quit.\n";
        char choice = _getch();
        if (choice != 'p')
        {
            play = false;
        }
        showCursor();
        fclose(ptr1);
    }
    return 0;
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void gameBoard :: display(const Food & food, const Snake & snake)
{
    gotoxy(0, 0);
    for (int i = 0; i < height + 2; i++)
    {
        for (int j = 0; j < width + 2; j++)
        {
            if (i == 0 || i == height + 1 || j == 0 || j == width + 1)
            {
                cout << "🧱";
            }
            else if (i == food.FoodY + 1 && j == food.FoodX + 1)
            {
                cout << "🍎";
            }
            else if (i == snake.headY + 1 && j == snake.headX + 1)
            {
                cout << "🐲";
            }
            else
            {
                bool isBody = false;
                for (const auto& bodyPart : snake.Body)
                {
                    if (i == bodyPart.second + 1 && j == bodyPart.first + 1)
                    {
                        cout << "🐍";
                        isBody = true;
                        break;
                    }
                }
                if (!isBody)
                {
                    cout << "  ";
                }
            }
        }
        cout << endl;
    }
    cout << "Score: " << gameScore << endl << "Speed: " << Speed << endl;
}

void logic(Snake & snake, Food & food, gameBoard & Board)
{
    int temp1 = snake.headX;
    int temp2 = snake.headY;
    switch(dir)
    {
        case LEFT:
            snake.headX--;
            rotate(snake.Body.rbegin(), snake.Body.rbegin() + 1, snake.Body.rend());
            snake.Body[0].first = temp1;
            snake.Body[0].second = temp2;
            break;
        case RIGHT:
            snake.headX++;
            rotate(snake.Body.rbegin(), snake.Body.rbegin() + 1, snake.Body.rend());
            snake.Body[0].first = temp1;
            snake.Body[0].second = temp2;
            break;
        case UP:
            snake.headY--;
            rotate(snake.Body.rbegin(), snake.Body.rbegin() + 1, snake.Body.rend());
            snake.Body[0].first = temp1;
            snake.Body[0].second = temp2;
            break;
        case DOWN:
            snake.headY++;
            rotate(snake.Body.rbegin(), snake.Body.rbegin() + 1, snake.Body.rend());
            snake.Body[0].first = temp1;
            snake.Body[0].second = temp2;
            break;
    }
    for (const auto& bodyPart : snake.Body)
    {
        if (snake.headX == bodyPart.first && snake.headY == bodyPart.second)
        {
            gameOver = true;
        }
    }
    if(snake.headX == food.FoodX && snake.headY == food.FoodY)
    {
        snake.Body.push_back(make_pair(snake.Body.back().first, snake.Body.back().second));
        food.generateFood(snake);
        gameScore += 10;
        if (c != 'a' && gameScore % 40 == 0)
        {
            Speed -= 20;
        }
    }
    else if(snake.headX >= Board.width || snake.headY >= Board.height || snake.headX < 0 || snake.headY < 0)
    {
        gameOver = true;
    }
    if (gameOver)
    {
        if (gameScore > high_score)
        {
            FILE* ptr2 = fopen("high_score.txt", "w");
            cout << "Hurray! You made a New High-Score!!!\nNew High-Score: " << gameScore << endl;
            fprintf(ptr2, "%d", gameScore);
            fclose(ptr2);
        }
        else
        {
            cout << "Current High-Score: " << high_score << endl;
        }
        gameOverScreen(food);
        gotoxy(0, food.height + 6);
    }
}

void input()
{
    if(_kbhit())
    {
        switch(_getch())
        {
            case 'w':
                if (dir == DOWN)
                {
                    break;
                }
                dir = UP;
                break;
            case 's':
                if (dir == UP)
                {
                    break;
                }
                dir = DOWN;
                break;
            case 'd':
                if (dir == LEFT)
                {
                    break;
                }
                dir = RIGHT;
                break;
            case 'a':
                if (dir == RIGHT)
                {
                    break;
                }
                dir = LEFT;
                break;
            case 'x':
                gameOver = true;
        }
        if (dir == STOP) 
        {
            dir = RIGHT;
        }
    }
}

void hideCursor()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false;  // Set cursor visibility to false
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void showCursor()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = true;   // Set cursor visibility to true
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void Food :: generateFood(Snake & snake)
{
    while (true)
    {
        bool flag = true;
        FoodX = rand() % width;
        FoodY = rand() % height;
        for (const auto& bodyPart : snake.Body)
        {
            if (FoodX == bodyPart.first && FoodY == bodyPart.second)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            break;
        }
    }
}

void welcome()
{
    cout << "\033[91m\n";
    cout << "          \033[91m   8.\033[96m`888b                 ,8'\033[0m \033[93m8 \033[95m8888888888   \033[94m8 \033[93m8888         \033[92m,o888888o.        \033[91m,o888888o.           \033[93m,8.       ,8.          \033[92m8 \033[96m8888888888" << endl;
    cout << "          \033[91m   `8.\033[96m`888b               ,8'\033[0m  \033[93m8 \033[95m8888         \033[94m8 \033[93m8888        \033[92m8888     `88.   \033[96m. \033[91m8888     `88.        \033[93m,888.     ,888.         \033[92m8 \033[96m8888" << endl;
    cout << "          \033[91m    `8.\033[96m`888b             ,8'\033[0m   \033[93m8 \033[95m8888         \033[94m8 \033[93m8888     \033[95m,8 \033[92m8888       `8. \033[96m,8 \033[91m8888       `8b      \033[95m.\033[93m`8888.   \033[95m.\033[93m`8888.        \033[92m8 \033[96m8888" << endl;
    cout << "          \033[91m     `8.\033[96m`888b     .b    ,8'\033[0m    \033[93m8 \033[95m8888         \033[94m8 \033[93m8888     \033[95m88 \033[92m8888           \033[96m88 \033[91m8888        `8b    \033[95m,8.\033[93m`8888. \033[95m,8.\033[93m`8888.       \033[92m8 \033[96m8888" << endl;
    cout << "          \033[91m      `8.\033[96m`888b    88b  ,8'\033[0m     \033[93m8 \033[95m888888888888 \033[94m8 \033[93m8888     \033[95m88 \033[92m8888           \033[96m88 \033[91m8888         88   \033[95m,8'8.\033[93m`8888\033[95m,8^8.\033[93m`8888.      \033[92m8 \033[96m888888888888" << endl;
    cout << "          \033[91m       `8.\033[96m`888b .`888b,8'\033[0m      \033[93m8 \033[95m8888         \033[94m8 \033[93m8888     \033[95m88 \033[92m8888           \033[96m88 \033[91m8888         88  \033[95m,8' `8.\033[93m`88 \033[95m8' `8.\033[93m`8888.     \033[92m8 \033[96m8888" << endl;
    cout << "          \033[91m        `8.\033[96m`888b8.`8888'\033[0m       \033[93m8 \033[95m8888         \033[94m8 \033[93m8888     \033[95m88 \033[92m8888           \033[96m88 \033[91m8888        ,8P \033[95m,8'    8.\033[93m\033[95m88'    `8.\033[93m`8888.    \033[92m8 \033[96m8888" << endl;
    cout << "          \033[91m         `8.\033[96m`888\033[91m`8.\033[96m`88'\033[0m        \033[93m8 \033[95m8888         \033[94m8 \033[93m8888     \033[95m`8 \033[92m8888       .8' \033[96m`8 \033[91m8888       ,8P \033[95m,8'     `8.8'     `8.\033[93m`8888.   \033[92m8 \033[96m8888" << endl;
    cout << "          \033[91m          `8.\033[0m\033[91m`8' 8,'\033[0m           \033[93m8 \033[95m8888         \033[94m8 \033[93m8888        \033[92m8888     ,88'   \033[96m` \033[91m8888     ,88' \033[95m,8'       `8        `8.\033[93m`8888.  \033[92m8 \033[96m8888" << endl;
    cout << "          \033[91m            8.\033[0m   \033[91m`8'\033[0m           \033[93m8 \033[95m888888888888 \033[94m8 \033[93m888888888888 \033[92m`8888888P'        \033[91m`8888888P'  \033[95m,8'         `         `8.\033[93m`8888. \033[92m8 \033[96m888888888888" << endl
         << endl;

    cout << "                                                                     \033[91m8888888 \033[93m8888888888 \033[96m,o888888o.         " << endl;
    cout << "                                                                           \033[91m8 \033[93m8888    \033[95m. \033[96m8888     `88.       " << endl;
    cout << "                                                                           \033[91m8 \033[93m8888   \033[95m,8 \033[96m8888       `8b      " << endl;
    cout << "                                                                           \033[91m8 \033[93m8888   \033[95m88 \033[96m8888        `8b     " << endl;
    cout << "                                                                           \033[91m8 \033[93m8888   \033[95m88 \033[96m8888         88     " << endl;
    cout << "                                                                           \033[91m8 \033[93m8888   \033[95m88 \033[96m8888         88     " << endl;
    cout << "                                                                           \033[91m8 \033[93m8888   \033[95m88 \033[96m8888        ,8P     " << endl;
    cout << "                                                                           \033[91m8 \033[93m8888   \033[95m`8 \033[96m8888       ,8P" << endl;
    cout << "                                                                           \033[91m8 \033[93m8888   \033[95m ` \033[96m8888     ,88'" << endl;
    cout << "                                                                           \033[91m8 \033[93m8888       \033[96m`8888888P'" << endl
         << endl;

    cout << "    \033[96md888888o.   \033[95mb.             8          \033[93m.8.          \033[95m8 \033[92m8888     ,88' \033[91m8 \033[96m8888888888              \033[91m,o888888o.          \033[93m.8.                   \033[92m,8.       ,8.          \033[95m8 \033[96m8888888888" << endl;
    cout << "  \033[91m.\033[96m`8888:' `88. \033[95m888o.          8         \033[93m.888.         \033[95m8 \033[92m8888    ,88'  \033[91m8 \033[96m8888                   \033[91m8888     `88.       \033[93m.888.                 \033[92m,888.     ,888.         \033[95m8 \033[96m8888" << endl;
    cout << "  \033[91m8.\033[96m`8888.   Y8 \033[95mY88888o.       8        \033[93m:88888.        \033[95m8 \033[92m\033[92m8888   ,88'   \033[91m8 \033[96m8888                ,8 \033[91m8888       `8.     \033[93m:88888.               \033[94m.\033[92m`8888.   \033[94m.\033[92m`8888.        \033[95m8 \033[96m8888" << endl;
    cout << "  \033[91m`8.\033[96m`8888.     \033[93m.\033[95m`Y888888o.    8       \033[94m. \033[93m`88888.       \033[95m8 \033[92m8888  ,88'    \033[91m8 \033[96m8888                88 \033[91m8888              \033[95m. \033[93m`88888.             \033[94m,8.\033[92m\033[92m`8888. \033[94m,8.\033[92m`8888.       \033[95m8 \033[96m8888" << endl;
    cout << "   \033[91m`8.\033[96m`8888.    \033[93m8o. \033[95m`Y888888o. 8      \033[94m.8. \033[93m`88888.      \033[95m8 \033[92m8888 ,88'     \033[91m8 \033[96m888888888888        88 \033[91m8888             \033[95m.8. \033[93m`88888.           \033[94m,8'8.\033[92m`8888\033[94m,8^8.\033[92m`8888.      \033[95m8 \033[96m888888888888" << endl;
    cout << "    \033[91m`8.\033[96m`8888.   \033[93m8`Y8o. \033[95m`Y88888o8     \033[94m.8`8. \033[93m\033[93m`88888.     \033[95m8 \033[92m8888 88'      \033[91m8 \033[96m8888                88 \033[91m8888            \033[95m.8`8. \033[93m`88888.         \033[94m,8' `8.\033[92m`88\033[94m 8' `8.\033[92m`8888.     \033[95m8 \033[96m8888" << endl;
    cout << "     \033[91m`8.\033[96m`8888.  \033[93m8   `Y8o. \033[95m`Y8888    \033[94m.8' `8. \033[93m`88888.    \033[95m8 \033[92m888888<       \033[91m8 \033[96m8888                88 \033[91m8888   8888888 \033[95m.8' `8. \033[93m`88888.       \033[94m,8'   `8.\033[94m`8\033[94m8'   `8.\033[92m`8888.    \033[95m8 \033[96m8888" << endl;
    cout << " \033[91m8b   `8.\033[96m`8888. \033[93m8      `Y8o. \033[95m`Y8   \033[94m.8'   `8. \033[93m`88888.   \033[95m8 \033[92m8888 `Y8.     \033[91m8 \033[96m8888                `8 \033[91m8888       .8'\033[95m.8'   `8. \033[93m`88888.     \033[94m,8'     `8.8'     `8.\033[92m`8888.   \033[95m8 \033[96m8888" << endl;
    cout << " \033[91m`8b.  ;8.\033[96m`8888 \033[93m8         Y8o.\033[95m    \033[94m.888888888. \033[93m`88888.  \033[95m8 \033[92m8888   `Y8.   \033[91m8 \033[96m8888                   \033[91m8888     ,88'\033[95m.888888888. \033[93m`88888.   \033[94m,8'       `8        `8.\033[92m`8888.  \033[95m8 \033[96m8888" << endl;
    cout << "  \033[91m`Y8888P \033[96m,88P' \033[93m8            `Yo \033[94m.8'       `8. \033[93m`88888. \033[95m8 \033[92m8888     `Y8. \033[91m8 \033[96m888888888888            \033[91m`8888888P' \033[95m.8'       `8. \033[93m`88888. \033[94m,8'         `         `8.\033[92m`8888. \033[95m8 \033[96m888888888888" << endl;
    cout << "\033[0m\n";
}

void gameOverScreen(Food &food)
{
    int boardWidth = food.width; 
    int startX = boardWidth + 40; 
    int startY = 5;
    int getaside = 13; 
    gotoxy(startX, startY);cout << "\033[91m\n";
    gotoxy(startX + getaside, startY + 1);cout <<"  sSSSSs   .S_SSSs     .Ss   sS.     sSSs           sSSSSSs      .S    S.     sSSs   .s_SSSs   "; 
    gotoxy(startX + getaside, startY + 2);cout <<" d%%%%SP  .SS~SSSSS   .SS~S S~SS.   d%%SP         d%%SP~YS%%b   .SS    SS.   d%%SP  .SS~YS%%b  "; 
    gotoxy(startX + getaside, startY + 3);cout <<"d%S'      S%S   SSSS  S%S `Y' S%S  d%S'          d%S'     `S%b  S%S    S%S  d%S'    S%S   `S%b "; 
    gotoxy(startX + getaside, startY + 4);cout <<"S%S       S%S    S%S  S%S     S%S  S%S           S%S       S%S  S%S    S%S  S%S     S%S    S%S "; 
    gotoxy(startX + getaside, startY + 5);cout <<"S&S       S%S SSSS%S  S%S     S%S  S&S           S&S       S&S  S&S    S%S  S&S     S%S    d*S "; 
    gotoxy(startX + getaside, startY + 6);cout <<"S&S       S&S  SSS%S  S&S     S&S  S&S_Ss        S&S       S&S  S&S    S&S  S&S_Ss  S&S   .S*S "; 
    gotoxy(startX + getaside, startY + 7);cout <<"S&S       S&S    S&S  S&S     S&S  S&S~SP        S&S       S&S  S&S    S&S  S&S~SP  S&S_sdSSS  "; 
    gotoxy(startX + getaside, startY + 8);cout <<"S&S sSSs  S&S    S&S  S&S     S&S  S&S           S&S       S&S  S&S    S&S  S&S     S&S~YSY%b  "; 
    gotoxy(startX + getaside, startY + 9);cout <<"S*b `S%%  S*S    S&S  S*S     S*S  S*b           S*b       d*S  S*b    S*S  S*b     S*S   `S%b "; 
    gotoxy(startX + getaside, startY + 10);cout <<"S*S   S%  S*S    S*S  S*S     S*S  S*S.          S*S.     .S*S  S*S.   S*S  S*S.    S*S    S%S "; 
    gotoxy(startX + getaside, startY + 11);cout <<" SS_sSSS  S*S    S*S  S*S     S*S   SSSbs         SSSbs_sdSSS    SSSbs_S*S   SSSbs  S*S    S&S "; 
    gotoxy(startX + getaside, startY + 12);cout <<"  Y~YSSY  SSS    S*S  SSS     S*S    YSSP          YSSP~YSSY      YSSP~SSS    YSSP  S*S    SSS "; 
    gotoxy(startX + getaside, startY + 13);cout <<"                 SP           SP                                                    SP         "; 
    gotoxy(startX + getaside, startY + 14);cout <<"                 Y            Y                                                     Y          ";
    gotoxy(startX + getaside, startY + 15);cout << "\033[0m\n";
}