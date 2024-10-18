#ifndef RECORD_H
#define RECORD_H
typedef struct record
{
    int userId ;
    char name[100];
    int age;
    // char certificateNumber[10];
} Record;

Record create_record(int useriId,const char* name,int age);

void print_record(const Record* record);

int compare_records_by_id(const Record* r1, const Record* r2);

#endif