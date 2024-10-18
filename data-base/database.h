#ifndef DATABASE_H
#define DATABASE_H

#include "record.h"

#define MAX_RECORDS 1000

typedef struct {
    Record records[MAX_RECORDS]; 
    int count;
} Database;

void init_database(Database* db);

int add_record(Database* db, Record record);

Record* find_record_by_id(Database* db, int id);

int delete_record(Database* db, int id);

int update_record(Database* db, int id, const char* new_name, int new_age);

int save_database_to_file(Database* db, const char* filename);

int load_database_from_file(Database* db, const char* filename);

void print_all_records(Database* db);

#endif // DATABASE_H
