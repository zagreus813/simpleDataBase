#include <stdio.h>
#include "database.h"

int main() {
    Database db;
    init_database(&db);

    add_record(&db, create_record(1, "John Doe", 25));
    add_record(&db, create_record(2, "Jane Smith", 30));
    add_record(&db, create_record(3, "Alice Johnson", 22));

    printf("list of all record : \n");
    print_all_records(&db);

    save_database_to_file(&db, "database.dat");

    Record* record = find_record_by_id(&db, 2);
    if (record != NULL) {
        printf("\n find!! \n");
        print_record(record);
        update_record(&db, 2, "Jane Doe", 31);
        printf("update!!\n");
        print_record(record);
    } else {
        printf("cannot find record by id.\n");
    }

    delete_record(&db, 1);
    printf("\n record delet it.\n list of record after delete : \n");
    print_all_records(&db);

    Database db_from_file;
    load_database_from_file(&db_from_file, "database.dat");
    printf("\ndata base after load : \n");
    print_all_records(&db_from_file);

    return 0;
}