#!/bin/sh

# init_env.sh
#
# This file is released under the terms of the Artistic License.  Please see
# the file LICENSE, included in this package, for details.
#
# Copyright (C) 2002 Mark Wong & Open Source Development Lab, Inc.
#
# 01 May 2003

. ./init_env.sh

# Create tables
psql -d $DB_NAME -f create_tables.sql

# Load tables
echo "Loading customer table..."
psql -d $DB_NAME -c "COPY customer FROM '/tmp/customer.data' WITH NULL AS '';"
echo "Loading district table..."
psql -d $DB_NAME -c "COPY district FROM '/tmp/district.data' WITH NULL AS '';"
echo "Loading history table..."
psql -d $DB_NAME -c "COPY history FROM '/tmp/history.data' WITH NULL AS '';"
echo "Loading item table..."
psql -d $DB_NAME -c "COPY item FROM '/tmp/item.data' WITH NULL AS '';"
echo "Loading new_order table..."
psql -d $DB_NAME -c "COPY new_order FROM '/tmp/new_order.data' WITH NULL AS '';"
echo "Loading order_line table..."
psql -d $DB_NAME -c "COPY order_line FROM '/tmp/order_line.data' WITH NULL AS '';"
echo "Loading orders table..."
psql -d $DB_NAME -c "COPY orders FROM '/tmp/order.data' WITH NULL AS '';"
echo "Loading stock table..."
psql -d $DB_NAME -c "COPY stock FROM '/tmp/stock.data' WITH NULL AS '';"
echo "Loading warehouse table..."
psql -d $DB_NAME -c "COPY warehouse FROM '/tmp/warehouse.data' WITH NULL AS '';"