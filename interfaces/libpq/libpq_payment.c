/*
 * This file is released under the terms of the Artistic License.  Please see
 * the file LICENSE, included in this package, for details.
 *
 * Copyright (C) 2002 Mark Wong & Open Source Development Labs, Inc.
 *
 * 13 May 2003
 */

#include <pthread.h>
#include <stdio.h>
#include <postgresql/libpq-fe.h>

#include "common.h"
#include "logging.h"
#include "libpq_payment.h"

int execute_payment(PGconn *conn, struct payment_t *data)
{
	PGresult *res;
	char stmt[128];

	/* Start a transaction block. */
	res = PQexec(conn, "BEGIN");
	if (!res || PQresultStatus(res) != PGRES_COMMAND_OK) {
		LOG_ERROR_MESSAGE("BEGIN command failed.\n");
		PQclear(res);
		return ERROR;
	}
	PQclear(res);

	/* Create the query and execute it. */
	sprintf(stmt, "SELECT payment(%d, %d, %d, %d %d, '%s', %f)",
		data->w_id, data->d_id, data->c_id, data->c_w_id, data->c_w_id,
		data->c_last, data->h_amount);
	res = PQexec(conn, stmt);
	if (!res || PQresultStatus(res) != PGRES_COMMAND_OK) {
		LOG_ERROR_MESSAGE("SELECT failed\n");
		PQclear(res);
		return ERROR;
	}
	PQclear(res);

	/* Commit the transaction. */
	res = PQexec(conn, "COMMIT");
	PQclear(res);

	return OK;
}