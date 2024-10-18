#include <stdio.h>
#include <string.h>
#include "database.h"

void init_database(Database* db){
    db->count =  0;
}

int add_record(Database* db, Record record){
    if(db->count >= MAX_RECORDS){
        printf("full\n");
        return 0;
    }
    db->records[db->count] = record;
    db->count++;
    return 1;
}

Record* find_record_by_id(Database* db, int userId) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].userId == userId) {
            return &db->records[i];
        }
    }
    return NULL;
}

int delete_record(Database* db, int id){
     for (int i = 0; i < db->count; i++) {
        if (db->records[i].userId == id) {
            for (int j = i; j < db->count - 1; j++) {
                db->records[j] = db->records[j + 1];
            }
            db->count--;
            return 1;
        }
    }
    return 0; 
}

int update_record(Database* db, int id, const char* new_name, int new_age){
    Record* record = find_record_by_id(db, id);
    if (record == NULL) {
        printf("not found \n");
        return 0;
    }
    strncpy(record->name, new_name, sizeof(record->name) - 1); 
    record->name[sizeof(record->name) - 1] = '\0'; 
    record->age = new_age;
    return 1;
}

int save_database_to_file(Database* db, const char* filename){
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("error in open the file. \n");
        return 0;
    }
    fwrite(&db->count, sizeof(int), 1, file); 
    fwrite(db->records, sizeof(Record), db->count, file);
    fclose(file);
    return 1;
}

int load_database_from_file(Database* db, const char* filename){
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("error in open the file. \n");
        return 0;
    }
    fread(&db->count, sizeof(int), 1, file);
    fread(db->records, sizeof(Record), db->count, file);  
    fclose(file);
    return 1;
}

void print_all_records(Database* db){
    for (int i = 0; i < db->count; i++) {
        print_record(&db->records[i]);
    }
}