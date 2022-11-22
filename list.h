#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <stack>
#include <time.h>
#include <cstdlib>
#include <string>
using namespace std;

struct todoList{
    int dayList, monthList, yearList, hourList, minuteList;
    string titleList, descList;
    struct todoList *next;
};

struct habitList{
    string habitTitle;
    string habitDescription;
};

class List{
    public:
        void insertList (struct todoList** headRef, int day, int month, int year, int hour, int minute, string title, string desc);
        void displayList (struct todoList* list);
        void sortlist(struct todoList *unsorted_node);
        void deleteList(struct todoList ** headRef, int position);
};


void List:: insertList (struct todoList** headRef, int day, int month, int year, int hour, int minute, string title, string desc){
    todoList* newList = new todoList();
    newList->titleList = title;
    newList->dayList = day;
    newList->monthList = month;
    newList->yearList = year;
    newList->hourList = hour;
    newList->minuteList = minute;
    newList->descList = desc;
    newList->next = (*headRef);
    (*headRef) = newList;    
}

void List::deleteList(struct todoList **headRef, int position){
    if (*headRef == NULL){
        return;
    }
    struct todoList *temp = *headRef;
    if (position == 1){
        *headRef = temp->next;
        free(temp);
        return;
    }
    for (int i = 2; temp!= NULL && i<position-1; i++){
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL){
        return;
    }
    struct todoList *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

void List::displayList (struct todoList* list){
    int i = 1;
    if(list == NULL){
       cout<<"Empty"<<endl; 
    }
    while(list!=NULL){
        printf("%d) %.2d-%.2d-%d\n",i, list->dayList,list->monthList,list->yearList);
        cout<<list->titleList;
        printf(" (%.2d:%.2d)\n", list->hourList, list->minuteList);
        cout<<list->descList<<endl;
        list = list->next;
        cout<<"\n";
        i++;
    }
    cout<<"\n";
}

/*
void List::sortlist(struct todoList *unsorted_node){
    struct todoList *current = unsorted_node, *index = NULL;
    int tempYear, tempMonth, tempDay, tempHour, tempMinute;
    string temp_title, temp_desc;

    while(current!=NULL){
        index = current->next;
        while (index!=NULL){
            if(current->yearList > index->yearList){
             tempYear = current->yearList;
                current->yearList = index->yearList;
                index->yearList = tempYear;

                tempMonth = current->monthList;
                current->monthList = index->monthList;
                index->monthList = tempMonth;

                tempDay = current->dayList;
                current->dayList = index->dayList;
                index->dayList = tempDay;
                
                tempHour = current->hourList;
                current->hourList = index->hourList;
                index->minuteList = tempHour;
                
                tempMinute = current->minuteList;
                current->minuteList = index->minuteList;
                index->minuteList = tempMinute;
                
                temp_title = current->titleList;
                current->titleList = index->titleList;
                index->titleList = temp_title;
                
                temp_desc = current->descList;
                current->descList = index->descList;
                index->descList = temp_desc;
            } else if(current->yearList == index->yearList && current->monthList > index->monthList){
                
                tempMonth = current->monthList;
                current->monthList = index->monthList;
                index->monthList = tempMonth;

                tempDay = current->dayList;
                current->dayList = index->dayList;
                index->dayList = tempDay;
                
                tempHour = current->hourList;
                current->hourList = index->hourList;
                index->minuteList = tempHour;
                
                tempMinute = current->minuteList;
                current->minuteList = index->minuteList;
                index->minuteList = tempMinute;
                
                temp_title = current->titleList;
                current->titleList = index->titleList;
                index->titleList = temp_title;
                
                temp_desc = current->descList;
                current->descList = index->descList;
                index->descList = temp_desc;
                
            } else if(current->yearList == index->yearList && current->monthList == index->monthList && current->dayList > index->dayList){
                
                tempDay = current->dayList;
                current->dayList = index->dayList;
                index->dayList = tempDay;
                
                tempHour = current->hourList;
                current->hourList = index->hourList;
                index->minuteList = tempHour;
                
                tempMinute = current->minuteList;
                current->minuteList = index->minuteList;
                index->minuteList = tempMinute;
                
                temp_title = current->titleList;
                current->titleList = index->titleList;
                index->titleList = temp_title;
                
                temp_desc = current->descList;
                current->descList = index->descList;
                index->descList = temp_desc;
                
            } else if(current->yearList == index->yearList && current->monthList == index->monthList && current->dayList == index->dayList && current->hourList > index->hourList){
               
                tempHour = current->hourList;
                current->hourList = index->hourList;
                index->minuteList = tempHour;
                
                tempMinute = current->minuteList;
                current->minuteList = index->minuteList;
                index->minuteList = tempMinute;
                
                temp_title = current->titleList;
                current->titleList = index->titleList;
                index->titleList = temp_title;
                
                temp_desc = current->descList;
                current->descList = index->descList;
                index->descList = temp_desc;
                
            } else if(current->yearList == index->yearList && current->monthList == index->monthList && current->dayList == index->dayList && current->hourList == index->hourList && current->minuteList > index->minuteList){
                
                tempMinute = current->minuteList;
                current->minuteList = index->minuteList;
                index->minuteList = tempMinute;
                
                temp_title = current->titleList;
                current->titleList = index->titleList;
                index->titleList = temp_title;
                
                temp_desc = current->descList;
                current->descList = index->descList;
                index->descList = temp_desc;                
            }
            index = index->next;
        }
        current = current->next;
    }
}


void displayStackList (stack <struct habitList> stacks){
	if(stacks.empty()){
		cout<<"There is nothing here! Plan something!"<<endl;
	}
    int i = 1;
    while(!stacks.empty()){
        cout << i <<"] "<< stacks.top().habitTitle <<endl;
        cout<<"Description: "<< stacks.top().habitDescription<<endl;
        i++;
        stacks.pop();
        cout<<"\n";
    }
}
*/

#endif
