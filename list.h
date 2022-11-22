#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <stack>
#include <time.h>
#include <cstdlib>
#include <string>
using namespace std;

/* ==================  3 =================== */  
struct todoList{
    int list_day, list_month, list_year, list_hour, list_minute;
    string list_title, list_desc;
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
    todoList* new_list = new todoList();
    new_list->list_title = title;
    new_list->list_day = day;
    new_list->list_month = month;
    new_list->list_year = year;
    new_list->list_hour = hour;
    new_list->list_minute = minute;
    new_list->list_desc = desc;
    new_list->next = (*headRef);
    (*headRef) = new_list;    
}

/* ==================  4 =================== */  
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
       cout<<"There is nothing here! Plan something!"<<endl; 
    }

    while(list!=NULL){
        printf("%d) %.2d-%.2d-%d\n",i, list->list_day,list->list_month,list->list_year);
        cout<<list->list_title;
        printf(" (%.2d:%.2d)\n", list->list_hour, list->list_minute);
        cout<<list->list_desc<<endl;
        list = list->next;
        cout<<"\n";
        i++;
    }
    cout<<"\n";
}

/* ==================  5  =================== */  
void List::sortlist(struct todoList *unsorted_node){
    struct todoList *current = unsorted_node, *index = NULL;
    int tempYear, tempMonth, tempDay, tempHour, tempMinute;
    string temp_title, temp_desc;

    while(current!=NULL){
        index = current->next;
        while (index!=NULL){
            if(current->list_year > index->list_year){
             tempYear = current->list_year;
                current->list_year = index->list_year;
                index->list_year = tempYear;

                tempMonth = current->list_month;
                current->list_month = index->list_month;
                index->list_month = tempMonth;

                tempDay = current->list_day;
                current->list_day = index->list_day;
                index->list_day = tempDay;
                
                tempHour = current->list_hour;
                current->list_hour = index->list_hour;
                index->list_minute = tempHour;
                
                tempMinute = current->list_minute;
                current->list_minute = index->list_minute;
                index->list_minute = tempMinute;
                
                temp_title = current->list_title;
                current->list_title = index->list_title;
                index->list_title = temp_title;
                
                temp_desc = current->list_desc;
                current->list_desc = index->list_desc;
                index->list_desc = temp_desc;
            } else if(current->list_year == index->list_year && current->list_month > index->list_month){
                
                tempMonth = current->list_month;
                current->list_month = index->list_month;
                index->list_month = tempMonth;

                tempDay = current->list_day;
                current->list_day = index->list_day;
                index->list_day = tempDay;
                
                tempHour = current->list_hour;
                current->list_hour = index->list_hour;
                index->list_minute = tempHour;
                
                tempMinute = current->list_minute;
                current->list_minute = index->list_minute;
                index->list_minute = tempMinute;
                
                temp_title = current->list_title;
                current->list_title = index->list_title;
                index->list_title = temp_title;
                
                temp_desc = current->list_desc;
                current->list_desc = index->list_desc;
                index->list_desc = temp_desc;
                
            } else if(current->list_year == index->list_year && current->list_month == index->list_month && current->list_day > index->list_day){
                
                tempDay = current->list_day;
                current->list_day = index->list_day;
                index->list_day = tempDay;
                
                tempHour = current->list_hour;
                current->list_hour = index->list_hour;
                index->list_minute = tempHour;
                
                tempMinute = current->list_minute;
                current->list_minute = index->list_minute;
                index->list_minute = tempMinute;
                
                temp_title = current->list_title;
                current->list_title = index->list_title;
                index->list_title = temp_title;
                
                temp_desc = current->list_desc;
                current->list_desc = index->list_desc;
                index->list_desc = temp_desc;
                
            } else if(current->list_year == index->list_year && current->list_month == index->list_month && current->list_day == index->list_day && current->list_hour > index->list_hour){
               
                tempHour = current->list_hour;
                current->list_hour = index->list_hour;
                index->list_minute = tempHour;
                
                tempMinute = current->list_minute;
                current->list_minute = index->list_minute;
                index->list_minute = tempMinute;
                
                temp_title = current->list_title;
                current->list_title = index->list_title;
                index->list_title = temp_title;
                
                temp_desc = current->list_desc;
                current->list_desc = index->list_desc;
                index->list_desc = temp_desc;
                
            } else if(current->list_year == index->list_year && current->list_month == index->list_month && current->list_day == index->list_day && current->list_hour == index->list_hour && current->list_minute > index->list_minute){
                
                tempMinute = current->list_minute;
                current->list_minute = index->list_minute;
                index->list_minute = tempMinute;
                
                temp_title = current->list_title;
                current->list_title = index->list_title;
                index->list_title = temp_title;
                
                temp_desc = current->list_desc;
                current->list_desc = index->list_desc;
                index->list_desc = temp_desc;                
            }
            index = index->next;
        }
        current = current->next;
    }
}

/* ==================  6  =================== */  
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


#endif
