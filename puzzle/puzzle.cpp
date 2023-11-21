
#include <iostream>

class Puzzle
{
public:
    Puzzle()
    {
        std::cout << "size" << std::endl;
        std::cin >> num;
        arr = new char*[num+1];
        for (int i = 0; i < num+1; i++)
        {
            arr[i] = new char[num+1];
        }
        std::cout << "Puzzle" << std::endl;
        for (int i = 0; i < num; i++)
        {
            for (int j = 0; j < num; j++)
            {
                std::cin>>arr[i][j];
            }
        }
    }
    void Move(int ,int);
    void print()
    {
        for (int i = 0; i < num; i++)
        {
            for (int j = 0; j < num; j++)
            {
                std::cout << arr[i][j];
            }
            std::cout << std::endl;
        }
    }
private:
    char** arr;
    int num;
};



void Puzzle::Move(int x=1,int y=1)
{
    if (arr[y][x] == '@')
    {
        std::cout << "get it" << "exit:" << x << "," << y << std::endl;
        exit(0);
        //return;
    }
    arr[y][x] = '#';
    std::cout << "Now:"<<std::endl;
    print();
    if (arr[y][x + 1] != '0'&& arr[y][x + 1] != '#')
   {
       x += 1;
       Move(x, y);
   }
    if (arr[y + 1][x] != '0' && arr[y + 1][x] != '#')
    {
        y += 1;
        Move(x, y);
    }
    if (arr[y][x - 1] != '0' && arr[y][x - 1] != '#')
    {
        x -= 1;
        Move(x, y);
    }
    if (arr[y - 1][x] != '0' && arr[y - 1][x] != '#')
   {
       y -= 1;
       Move(x, y);
   }
   return;

}

int main()
{
    int x, y;
    Puzzle p;
    std::cout << "startx,y" << std::endl;
    std::cin >> x >> y;
    p.Move(x,y);
}

