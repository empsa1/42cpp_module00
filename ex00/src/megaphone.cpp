#include <iostream>
#include <cctype>

int main(int argc, char* argv[]) 
{
    int i;
    char *p;
    
    i = 0;
    if (argc == 1) 
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (1);
    }
    while (++i < argc)
    {
        p = argv[i];
        while (*p)
        {
            *p = std::toupper(*p);
            p++;
        }
        std::cout << argv[i] << " ";
    }
    std::cout << std::endl;
    return (0);
}