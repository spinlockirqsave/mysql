/*
 * @file    main.c
 * @author  Piotr Gregor <piotrek.gregor gmail com>
 * @brief   Usage of mysql.
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlrelay/sqlrclientwrapper.h>


sqlrcon	con;
sqlrcur	cur;

void checkSuccessString(const char *value, const char *success) {

	if (!success) {
		if (!value) {
			printf("success ");
			return;
		} else {
			printf("\"%s\"!=\"%s\"",value,success);
			printf("failure ");
			sqlrcur_free(cur);
			sqlrcon_free(con);
			exit(1);
		}
	}

	if (!strcmp(value,success)) {
		printf("success ");
	} else {
		printf("\"%s\"!=\"%s\"",value,success);
		printf("failure ");
		sqlrcur_free(cur);
		sqlrcon_free(con);
		exit(1);
	}
}

void checkSuccessInt(int value, int success) {

	if (value==success) {
		printf("success ");
	} else {
		printf("\"%d\"!=\"%d\"",value,success);
		printf("failure ");
		sqlrcur_free(cur);
		sqlrcon_free(con);
		exit(1);
	}
}

int
main(void)
{
	// instantiation
	con = sqlrcon_alloc("mysql", 3306, "/tmp/test.socket", "root","root", 0, 1);
	cur = sqlrcur_alloc(con);

	// get database type
	printf("IDENTIFY: \n");
	checkSuccessString(sqlrcon_identify(con), "mysql");

	// ping
	printf("PING: \n");
	checkSuccessInt(sqlrcon_ping(con), 1);
	printf("\n");
    return 0;
}
