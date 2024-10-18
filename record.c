#include <stdio.h>
#include <string.h>
#include "record.h"

Record create_record(int userId ,const char* name , int age){
    Record record;
    record.userId = userId;
    strncpy(record.name, name, sizeof(record.name) - 1); 
    record.name[sizeof(record.name) - 1] = '\0';
    record.age = age ; 
    return record;
}

void print_record(const Record* record){
    if(record == NULL) {
        printf("record is empty\n");
        return;
    }
    printf(" id : %d\n name : %s\n age : %d\n certificateNumber : %s" , record->userId , record->name , record->age);
}

int compare_records_by_id(const Record* r1, const Record* r2) {
    if (r1->userId < r2->userId) {
        return -1;
    } else if (r1->userId > r2->userId) {
        return 1;
    } else {
        return 0;
    }
}