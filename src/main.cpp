#include <iostream>
#include <vector>
#include <windows.h>
#include <conio.h>
#include "MyQueue.h"

struct MainMenu {
    MyQueue<int> foo;
    std::vector<int> bar;

    void showQueue() {
        if(bar.empty())
            return;

        for(int i = 0; i < bar.size(); i++)
            std::cout<<bar[i]<<" ";
    }

    void showMainMenu() {
        system("cls");

        std::cout<<"Q U E U E"<<std::endl;
        std::cout<<"-------------------------------------------------------------------------------"<<std::endl;
        showQueue();
        std::cout<<std::endl<<"-------------------------------------------------------------------------------"<<std::endl;
        std::cout<<"Current size: "<<foo.size()<<std::endl;
        std::cout<<"Empty: ";

        if(foo.empty())
            std::cout<<"Yes"<<std::endl<<std::endl;
        else
            std::cout<<"No"<<std::endl<<std::endl;

        std::cout<<"What do you want to do with it?"<<std::endl;
        std::cout<<"[1].push()"<<std::endl;
        std::cout<<"[2].pop()"<<std::endl;
        std::cout<<"[3].front()"<<std::endl;
        std::cout<<"[4].back()"<<std::endl;
        std::cout<<"[5].clear()"<<std::endl;
        std::cout<<"[6].Exit"<<std::endl;

        getUserInput();
    }

    void pushCase() {
        int number;
        std::vector<int>::iterator itr = bar.begin();

        std::cout<<"What do you want to push to the queue (integer): ";
        std::cin>>number;
        bar.insert(itr, number);
        foo.push(number);
        std::cout<<"Success"<<std::endl;
        Sleep(1000);
    }

    void popCase() {
        if(foo.empty()) {
            std::cout<<"There's nothing to pop!"<<std::endl;
        }
        else {
            foo.pop();
            bar.pop_back();
            std::cout<<"Success"<<std::endl;
        }

        Sleep(1000);
    }

    void frontCase() {
        if(foo.empty())
            std::cout<<"There's no first element!"<<std::endl;
        else
            std::cout<<"First element: "<<foo.front()<<std::endl;

        Sleep(1000);
    }

    void backCase() {
        if(foo.empty())
            std::cout<<"There's no last element!"<<std::endl;
        else
            std::cout<<"Last element: "<<foo.back()<<std::endl;

        Sleep(1000);
    }

    void clearCase() {
        if(foo.empty())
            std::cout<<"There's nothing to clear!"<<std::endl;
        else {
            foo.clear();
            bar.clear();
            std::cout<<"Success"<<std::endl;
        }

        Sleep(1000);
    }

    void getUserInput() {
        char choice = getch();

        std::cout<<std::endl;

        switch(choice) {
        case '1':
            pushCase();
            break;

        case '2':
            popCase();
            break;

        case '3':
            frontCase();
            break;

        case '4':
            backCase();
            break;

        case '5':
            clearCase();
            break;

        case '6':
            exit(1);
            break;

        default:
            std::cout<<"There's no such an option!"<<std::endl;
            Sleep(1000);
            break;
        }
    }
};

int main() {
    MainMenu menu;

    while(true) {
        menu.showMainMenu();
    }

    return 0;
}
