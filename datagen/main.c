/*
 * main.c
 *
 * This file is released under the terms of the Artistic License.  Please see
 * the file LICENSE, included in this package, for details.
 *
 * Copyright (C) 2002 Mark Wong & Open Source Development Lab, Inc.
 *
 * 16 may 2002
 * Based on TPC-C Standard Specification Revision 5.0.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <common.h>

#define CUSTOMER_DATA "customer.data"
#define DISTRICT_DATA "district.data"
#define HISTORY_DATA "history.data"
#define ITEM_DATA "item.data"
#define NEW_ORDER_DATA "new_order.data"
#define ORDER_DATA "order.data"
#define ORDER_LINE_DATA "order_line.data"
#define STOCK_DATA "stock.data"
#define WAREHOUSE_DATA "warehouse.data"

#define DELIMITER ','

#define CUSTOMER_CARDINALITY 3000
#define DISTRICT_CARDINALITY 10
#define ITEM_CARDINALITY 100000
#define ORDER_CARDINALITY 3000
#define STOCK_CARDINALITY 100000
#define NEW_ORDER_CARDINALITY 900

int gen_customers(int warehouses);
int gen_districts(int warehouses);
int gen_history(int warehouses);
int gen_items();
int gen_new_order(int warehouses);
int gen_orders(int warehouses);
int gen_stock(int warehouses);
int gen_warehouses(int warehouses);

/* Clause 4.3.3.1 */
int gen_customers(int warehouses)
{
	FILE *output;
	int i, j, k;
	char a_string[512];
	struct tm *tm1;
	time_t t1;

	printf("Generating customer table data...\n");

	output = fopen(CUSTOMER_DATA, "w");
	if (output == NULL)
	{
		printf("cannot open %s\n", CUSTOMER_DATA);
		return ERROR;
	}

	for (i = 0; i < warehouses; i++)
	{
		for (j = 0; j < DISTRICT_CARDINALITY; j++)
		{
			for (k = 0; k < CUSTOMER_CARDINALITY; k++)
			{
				/* c_id */
				fprintf(output, "\"%d\"", k + 1);
				fprintf(output, "%c", DELIMITER);

				/* c_d_id */
				fprintf(output, "\"%d\"", j + 1);
				fprintf(output, "%c", DELIMITER);

				/* c_w_id */
				fprintf(output, "\"%d\"", i + 1);
				fprintf(output, "%c", DELIMITER);

				/* c_first */
				get_a_string(a_string, 8, 16);
				fprintf(output, "\"%s\"", a_string);
				fprintf(output, "%c", DELIMITER);

				/* c_middle */
				fprintf(output, "\"OE\"");
				fprintf(output, "%c", DELIMITER);

				/* c_last Clause 4.3.2.7 */
				get_c_last(a_string, get_random(1000));
				fprintf(output, "\"%s\"", a_string);
				fprintf(output, "%c", DELIMITER);

				/* c_street_1 */
				get_a_string(a_string, 10, 20);
				fprintf(output, "\"%s\"", a_string);
				fprintf(output, "%c", DELIMITER);

				/* c_street_2 */
				get_a_string(a_string, 10, 20);
				fprintf(output, "\"%s\"", a_string);
				fprintf(output, "%c", DELIMITER);

				/* c_city */
				get_a_string(a_string, 10, 20);
				fprintf(output, "\"%s\"", a_string);
				fprintf(output, "%c", DELIMITER);

				/* c_state */
				get_l_string(a_string, 2, 2);
				fprintf(output, "\"%s\"", a_string);
				fprintf(output, "%c", DELIMITER);

				/* c_zip */
				get_n_string(a_string, 4, 4);
				fprintf(output, "\"%s11111\"", a_string);
				fprintf(output, "%c", DELIMITER);

				/* c_phone */
				get_n_string(a_string, 16, 16);
				fprintf(output, "\"%s\"", a_string);
				fprintf(output, "%c", DELIMITER);

				/* c_since */
				/*
				 * Milliseconds are not calculated.  This should also
				 * be the time when the data is loaded, I think.
				 */
				time(&t1);
				tm1 = localtime(&t1);
				fprintf(output, "\"%04d%02d%02d%02d%02d%02d000000\"",
					tm1->tm_year + 1900, tm1->tm_mon + 1, tm1->tm_mday,
					tm1->tm_hour, tm1->tm_min, tm1->tm_sec);
				fprintf(output, "%c", DELIMITER);

				/* c_credit */
				if (get_percentage() < .10)
				{
					fprintf(output, "\"BC\"");
				}
				else
				{
					fprintf(output, "\"GC\"");
				}
				fprintf(output, "%c", DELIMITER);

				/* c_credit_lim */
				fprintf(output, "\"50000.00\"");
				fprintf(output, "%c", DELIMITER);

				/* c_discount */
				fprintf(output, "\"0.%04d\"", get_random(5001));
				fprintf(output, "%c", DELIMITER);

				/* c_balance */
				fprintf(output, "\"-10.00\"");
				fprintf(output, "%c", DELIMITER);

				/* c_ytd_payment */
				fprintf(output, "\"10.00\"");
				fprintf(output, "%c", DELIMITER);

				/* c_payment_cnt */
				fprintf(output, "\"1\"");
				fprintf(output, "%c", DELIMITER);

				/* c_delivery_cnt */
				fprintf(output, "\"0\"");
				fprintf(output, "%c", DELIMITER);

				/* c_data */
				get_a_string(a_string, 300, 500);
				fprintf(output, "\"%s\"", a_string);

				fprintf(output, "\n");
			}
		}
	}
	fclose(output);
	return OK;
}

/* Clause 4.3.3.1 */
int gen_districts(int warehouses)
{
	FILE *output;
	int i, j;
	char a_string[32];

	printf("Generating district table data...\n");

	output = fopen(DISTRICT_DATA, "w");
	if (output == NULL)
	{
		printf("cannot open %s\n", DISTRICT_DATA);
		return ERROR;
	}

	for (i = 0; i < warehouses; i++)
	{
		for (j = 0; j < DISTRICT_CARDINALITY; j++)
		{
			/* d_id */
			fprintf(output, "\"%d\"", j + 1);
			fprintf(output, "%c", DELIMITER);

			/* d_w_id */
			fprintf(output, "\"%d\"", i + 1);
			fprintf(output, "%c", DELIMITER);

			/* d_name */
			get_a_string(a_string, 6, 10);
			fprintf(output, "\"%s\"", a_string);
			fprintf(output, "%c", DELIMITER);

			/* d_street_1 */
			get_a_string(a_string, 10, 20);
			fprintf(output, "\"%s\"", a_string);
			fprintf(output, "%c", DELIMITER);

			/* d_street_2 */
			get_a_string(a_string, 10, 20);
			fprintf(output, "\"%s\"", a_string);
			fprintf(output, "%c", DELIMITER);

			/* d_city */
			get_a_string(a_string, 10, 20);
			fprintf(output, "\"%s\"", a_string);
			fprintf(output, "%c", DELIMITER);

			/* d_state */
			get_l_string(a_string, 2, 2);
			fprintf(output, "\"%s\"", a_string);
			fprintf(output, "%c", DELIMITER);

			/* d_zip */
			get_n_string(a_string, 4, 4);
			fprintf(output, "\"%s11111\"", a_string);
			fprintf(output, "%c", DELIMITER);

			/* d_tax */
			fprintf(output, "\"0.%04d\"", get_random(2001));
			fprintf(output, "%c", DELIMITER);

			/* d_ytd */
			fprintf(output, "\"30000.00\"");
			fprintf(output, "%c", DELIMITER);

			/* d_next_o_id */
			fprintf(output, "\"3001\"");

			fprintf(output, "\n");
		}
	}
	fclose(output);
	return OK;
}

/* Clause 4.3.3.1 */
int gen_history(int warehouses)
{
	FILE *output;
	int i, j, k;
	char a_string[32];
	struct tm *tm1;
	time_t t1;

	printf("Generating history table data...\n");

	output = fopen(HISTORY_DATA, "w");
	if (output == NULL)
	{
		printf("cannot open %s\n", HISTORY_DATA);
		return ERROR;
	}

	for (i = 0; i < warehouses; i++)
	{
		for (j = 0; j < DISTRICT_CARDINALITY; j++)
		{
			for (k = 0; k < CUSTOMER_CARDINALITY; k++)
			{
				/* h_c_id */
				fprintf(output, "\"%d\"", k + 1);
				fprintf(output, "%c", DELIMITER);

				/* h_c_d_id */
				fprintf(output, "\"%d\"", j + 1);
				fprintf(output, "%c", DELIMITER);

				/* h_c_w_id */
				fprintf(output, "\"%d\"", i + 1);
				fprintf(output, "%c", DELIMITER);

				/* h_d_id */
				fprintf(output, "\"%d\"", j + 1);
				fprintf(output, "%c", DELIMITER);

				/* h_w_id */
				fprintf(output, "\"%d\"", i + 1);
				fprintf(output, "%c", DELIMITER);

				/* h_date */
				/*
				 * Milliseconds are not calculated.  This should also
				 * be the time when the data is loaded, I think.
				 */
				time(&t1);
				tm1 = localtime(&t1);
				fprintf(output, "\"%04d%02d%02d%02d%02d%02d000000\"",
					tm1->tm_year + 1900, tm1->tm_mon + 1, tm1->tm_mday,
					tm1->tm_hour, tm1->tm_min, tm1->tm_sec);
				fprintf(output, "%c", DELIMITER);

				/* h_amount */
				fprintf(output, "\"10.00\"");
				fprintf(output, "%c", DELIMITER);

				/* h_data */
				get_a_string(a_string, 12, 24);
				fprintf(output, "\"%s\"", a_string);

				fprintf(output, "\n");
			}
		}
	}
	fclose(output);
	return OK;
}

/* Clause 4.3.3.1 */
int gen_items()
{
	FILE *output;
	int i;
	char a_string[64];
	int j;

	printf("Generating item table data...\n");

	output = fopen(ITEM_DATA, "w");
	if (output == NULL)
	{
		printf("cannot open %s\n", ITEM_DATA);
		return ERROR;
	}

	for (i = 0; i < ITEM_CARDINALITY; i++)
	{
		/* i_id */
		fprintf(output, "\"%d\"", i + 1);
		fprintf(output, "%c", DELIMITER);

		/* i_im_id */
		fprintf(output, "\"%d\"", get_random(10000) + 1);
		fprintf(output, "%c", DELIMITER);

		/* i_name */
		get_a_string(a_string, 14, 24);
		fprintf(output, "\"%s\"", a_string);
		fprintf(output, "%c", DELIMITER);

		/* i_price */
		fprintf(output, "\"%0.2f\"", ((double) get_random(9901) + 100) / 100.0);
		fprintf(output, "%c", DELIMITER);

		/* i_data */
		get_a_string(a_string, 26, 50);
		if (get_percentage() < .10)
		{
			j = get_random(strlen(a_string) - 7);
			strncpy(a_string + j, "ORIGINAL", 8);
		}
		fprintf(output, "\"%s\"", a_string);

		fprintf(output, "\n");
	}
	fclose(output);
	return OK;
}

/* Clause 4.3.3.1 */
int gen_new_orders(int warehouses)
{
	FILE *output;
	int i, j, k;

	printf("Generating new-order table data...\n");

	output = fopen(NEW_ORDER_DATA, "w");
	if (output == NULL)
	{
		printf("cannot open %s\n", NEW_ORDER_DATA);
		return ERROR;
	}

	for (i = 0; i < warehouses; i++)
	{
		for (j = 0; j < DISTRICT_CARDINALITY; j++)
		{
			for (k = ORDER_CARDINALITY - NEW_ORDER_CARDINALITY;
				k < ORDER_CARDINALITY; k++)
			{
				/* no_o_id */
				fprintf(output, "\"%d\"", k + 1);
				fprintf(output, "%c", DELIMITER);

				/* no_d_id */
				fprintf(output, "\"%d\"", j + 1);
				fprintf(output, "%c", DELIMITER);

				/* no_w_id */
				fprintf(output, "\"%d\"", i + 1);

				fprintf(output, "\n");
			}
		}
	}
	fclose(output);

	return OK;
}
/* Clause 4.3.3.1 */
int gen_orders(int warehouses)
{
	FILE *order, *order_line;
	int i, j, k, l;
	char a_string[32];
	struct tm *tm1;
	time_t t1;

	struct node_t
	{
		int value;
		struct node_t *next;
	};
	struct node_t *head;
	struct node_t *current;
	struct node_t *prev;
	struct node_t *new_node;
	int count, iter;

	int o_ol_cnt;

	printf("Generating order and order-line table data...\n");

	order = fopen(ORDER_DATA, "w");
	if (order == NULL)
	{
		printf("cannot open %s\n", ORDER_DATA);
		return ERROR;
	}

	order_line = fopen(ORDER_LINE_DATA, "w");
	if (order_line == NULL)
	{
		printf("cannot open %s\n", ORDER_LINE_DATA);
		return ERROR;
	}

	for (i = 0; i < warehouses; i++)
	{
		for (j = 0; j < DISTRICT_CARDINALITY; j++)
		{
			/* Create a random list of numbers from 1 to 3000 for o_c_id. */
			head = (struct node_t *) malloc(sizeof(struct node_t));
			head->value = 1;
			head->next = NULL;
			for (k = 2; k <= 3000; k++)
			{
				current = prev = head;

				/* Find a random place in the list to insert a number. */
				iter = get_random(k);
				while (iter > 0)
				{
					prev = current;
					current = current->next;
					--iter;
				}

				/* Insert the number. */
				new_node = (struct node_t *) malloc(sizeof(struct node_t));
				if (current == prev)
				{
					/* Insert at the head of the list. */
					new_node->next = head;
					head = new_node;
				}
				else if (current == NULL)
				{
					/* Insert at the tail of the list. */
					prev->next = new_node;
					new_node->next = NULL;
				}
				else
				{
					/* Insert somewhere in the middle of the list. */
					prev->next = new_node;
					new_node->next = current;
				}
				new_node->value = k;
			}

			for (k = 0; k < ORDER_CARDINALITY; k++)
			{
				/* o_id */
				fprintf(order, "\"%d\"", k + 1);
				fprintf(order, "%c", DELIMITER);

				/* o_c_id */
				current = head;
				head = head->next;
				fprintf(order, "\"%d\"", current->value);
				fprintf(order, "%c", DELIMITER);
				free(current);

				/* o_d_id */
				fprintf(order, "\"%d\"", j + 1);
				fprintf(order, "%c", DELIMITER);

				/* o_w_id */
				fprintf(order, "\"%d\"", i + 1);
				fprintf(order, "%c", DELIMITER);

				/* o_entry_d */
				/*
				 * Milliseconds are not calculated.  This should also
				 * be the time when the data is loaded, I think.
				 */
				time(&t1);
				tm1 = localtime(&t1);
				fprintf(order, "\"%04d%02d%02d%02d%02d%02d000000\"",
					tm1->tm_year + 1900, tm1->tm_mon + 1, tm1->tm_mday,
					tm1->tm_hour, tm1->tm_min, tm1->tm_sec);
				fprintf(order, "%c", DELIMITER);

				/* o_carrier_id */
				if (k < 2101)
				{
					fprintf(order, "\"%d\"", get_random(10) + 1);
				}
				else
				{
					fprintf(order, "\"\"");
				}
				fprintf(order, "%c", DELIMITER);

				/* o_ol_cnt */
				o_ol_cnt = get_random(11) + 5;
				fprintf(order, "\"%d\"", o_ol_cnt);
				fprintf(order, "%c", DELIMITER);

				/* o_all_local */
				fprintf(order, "\"1\"");

				fprintf(order, "\n");

				/* Generate data in the order-line table for this order. */
				for (l = 0; l < o_ol_cnt; l++)
				{
					/* ol_o_id */
					fprintf(order_line, "\"%d\"", k + 1);
					fprintf(order_line, "%c", DELIMITER);

					/* ol_d_id */
					fprintf(order_line, "\"%d\"", j + 1);
					fprintf(order_line, "%c", DELIMITER);

					/* ol_w_id */
					fprintf(order_line, "\"%d\"", i + 1);
					fprintf(order_line, "%c", DELIMITER);

					/* ol_number */
					fprintf(order_line, "\"%d\"", l + 1);
					fprintf(order_line, "%c", DELIMITER);

					/* ol_i_id */
					fprintf(order_line, "\"%d\"",
						get_random(ITEM_CARDINALITY) + 1);
					fprintf(order_line, "%c", DELIMITER);

					/* ol_supply_w_id */
					fprintf(order_line, "\"%d\"", i + 1);
					fprintf(order_line, "%c", DELIMITER);

					/* ol_delivery_d */
					if (k < 2101)
					{
						/*
						 * Milliseconds are not calculated.  This should also
						 * be the time when the data is loaded, I think.
						 */
						time(&t1);
						tm1 = localtime(&t1);
						fprintf(order_line,
							"\"%04d%02d%02d%02d%02d%02d000000\"",
							tm1->tm_year + 1900, tm1->tm_mon + 1, tm1->tm_mday,
							tm1->tm_hour, tm1->tm_min, tm1->tm_sec);
					}
					else
					{
						fprintf(order_line, "\"\"");
					}
					fprintf(order_line, "%c", DELIMITER);

					/* ol_quantity */
					fprintf(order_line, "\"5\"");
					fprintf(order_line, "%c", DELIMITER);

					/* ol_amount */
					if (k < 2101)
					{
						fprintf(order_line, "\"0.00\"");
					}
					else
					{
						fprintf(order_line, "\"%f\"",
							(double) (get_random(999999) + 1) / 100.0);
					}
					fprintf(order_line, "%c", DELIMITER);

					/* ol_dist_info */
					get_l_string(a_string, 24, 24);
					fprintf(order_line, "\"%s\"", a_string);

					fprintf(order_line, "\n");
				}
			}
		}
	}
	fclose(order);
	fclose(order_line);
	return OK;
}

/* Clause 4.3.3.1 */
int gen_stock(int warehouses)
{
	FILE *output;
	int i, j, k;
	char a_string[64];

	printf("Generating stock table data...\n");

	output = fopen(STOCK_DATA, "w");
	if (output == NULL)
	{
		printf("cannot open %s\n", STOCK_DATA);
		return ERROR;
	}

	for (i = 0; i < warehouses; i++)
	{
		for (j = 0; j < STOCK_CARDINALITY; j++)
		{
			/* s_i_id */
			fprintf(output, "\"%d\"", j + 1);
			fprintf(output, "%c", DELIMITER);

			/* s_w_id */
			fprintf(output, "\"%d\"", i + 1);
			fprintf(output, "%c", DELIMITER);

			/* s_quantity */
			fprintf(output, "\"%d\"", get_random(91) + 10);
			fprintf(output, "%c", DELIMITER);

			/* s_dist_01 */
			get_l_string(a_string, 24, 24);
			fprintf(output, "\"%s\"", a_string);
			fprintf(output, "%c", DELIMITER);

			/* s_dist_02 */
			get_l_string(a_string, 24, 24);
			fprintf(output, "\"%s\"", a_string);
			fprintf(output, "%c", DELIMITER);

			/* s_dist_03 */
			get_l_string(a_string, 24, 24);
			fprintf(output, "\"%s\"", a_string);
			fprintf(output, "%c", DELIMITER);

			/* s_dist_04 */
			get_l_string(a_string, 24, 24);
			fprintf(output, "\"%s\"", a_string);
			fprintf(output, "%c", DELIMITER);

			/* s_dist_05 */
			get_l_string(a_string, 24, 24);
			fprintf(output, "\"%s\"", a_string);
			fprintf(output, "%c", DELIMITER);

			/* s_dist_06 */
			get_l_string(a_string, 24, 24);
			fprintf(output, "\"%s\"", a_string);
			fprintf(output, "%c", DELIMITER);

			/* s_dist_07 */
			get_l_string(a_string, 24, 24);
			fprintf(output, "\"%s\"", a_string);
			fprintf(output, "%c", DELIMITER);

			/* s_dist_08 */
			get_l_string(a_string, 24, 24);
			fprintf(output, "\"%s\"", a_string);
			fprintf(output, "%c", DELIMITER);

			/* s_dist_09 */
			get_l_string(a_string, 24, 24);
			fprintf(output, "\"%s\"", a_string);
			fprintf(output, "%c", DELIMITER);

			/* s_dist_10 */
			get_l_string(a_string, 24, 24);
			fprintf(output, "\"%s\"", a_string);
			fprintf(output, "%c", DELIMITER);

			/* s_ytd */
			fprintf(output, "\"0\"");
			fprintf(output, "%c", DELIMITER);

			/* s_order_cnt */
			fprintf(output, "\"0\"");
			fprintf(output, "%c", DELIMITER);

			/* s_remote_cnt */
			fprintf(output, "\"0\"");
			fprintf(output, "%c", DELIMITER);

			/* s_data */
			get_a_string(a_string, 26, 50);
			if (get_percentage() < .10)
			{
				k = get_random(strlen(a_string) - 7);
				strncpy(a_string + k, "ORIGINAL", 8);
			}
			fprintf(output, "\"%s\"", a_string);

			fprintf(output, "\n");
		}
	}
	fclose(output);
	return OK;
}

/* Clause 4.3.3.1 */
int gen_warehouses(int warehouses)
{
	FILE *output;
	int i;
	char a_string[32];

	printf("Generating warehouse table data...\n");

	output = fopen(WAREHOUSE_DATA, "w");
	if (output == NULL)
	{
		printf("cannot open %s\n", WAREHOUSE_DATA);
		return ERROR;
	}

	for (i = 0; i < warehouses; i++)
	{
		/* w_id */
		fprintf(output, "\"%d\"", i + 1);
		fprintf(output, "%c", DELIMITER);

		/* w_name */
		get_a_string(a_string, 6, 10);
		fprintf(output, "\"%s\"", a_string);
		fprintf(output, "%c", DELIMITER);

		/* w_street_1 */
		get_a_string(a_string, 10, 20);
		fprintf(output, "\"%s\"", a_string);
		fprintf(output, "%c", DELIMITER);

		/* w_street_2 */
		get_a_string(a_string, 10, 20);
		fprintf(output, "\"%s\"", a_string);
		fprintf(output, "%c", DELIMITER);

		/* w_city */
		get_a_string(a_string, 10, 20);
		fprintf(output, "\"%s\"", a_string);
		fprintf(output, "%c", DELIMITER);

		/* w_state */
		get_l_string(a_string, 2, 2);
		fprintf(output, "\"%s\"", a_string);
		fprintf(output, "%c", DELIMITER);

		/* w_zip */
		get_n_string(a_string, 4, 4);
		fprintf(output, "\"%s11111\"", a_string);
		fprintf(output, "%c", DELIMITER);

		/* w_tax */
		fprintf(output, "\"0.%04d\"", get_random(2001));
		fprintf(output, "%c", DELIMITER);

		/* w_ytd */
		fprintf(output, "\"300000.00\"");

		fprintf(output, "\n");
	}
	fclose(output);
	return OK;
}

int main(int argc, char *argv[])
{
	FILE *p;
	int warehouses;
	char pwd[256];
	char cmd[256];

	if (argc != 2)
	{
		printf("usage: %s <warehouses>\n", argv[0]);
		return 1;
	}

	init_common();

	warehouses = atoi(argv[1]);

	printf("Generating data files for %d warehouse(s)...\n", warehouses);
	gen_items();
	gen_warehouses(warehouses);
	gen_stock(warehouses);
	gen_districts(warehouses);
	gen_customers(warehouses);
	gen_history(warehouses);
	gen_orders(warehouses);
	gen_new_orders(warehouses);

	/*
	 * In my environment, I don't have enough /tmp space to put the data files
	 * in /tmp.
	 */
	p = popen("pwd", "r");
	fscanf(p, "%s", pwd);

	printf("creating links in /tmp to data files...\n");

	sprintf(cmd, "ln -fs %s/%s /tmp/%s", pwd, ITEM_DATA, ITEM_DATA);
	popen(cmd, "r");

	sprintf(cmd, "ln -fs %s/%s /tmp/%s", pwd, WAREHOUSE_DATA, WAREHOUSE_DATA);
	popen(cmd, "r");

	sprintf(cmd, "ln -fs %s/%s /tmp/%s", pwd, STOCK_DATA, STOCK_DATA);
	popen(cmd, "r");

	sprintf(cmd, "ln -fs %s/%s /tmp/%s", pwd, DISTRICT_DATA, DISTRICT_DATA);
	popen(cmd, "r");

	sprintf(cmd, "ln -fs %s/%s /tmp/%s", pwd, CUSTOMER_DATA, CUSTOMER_DATA);
	popen(cmd, "r");

	sprintf(cmd, "ln -fs %s/%s /tmp/%s", pwd, HISTORY_DATA, HISTORY_DATA);
	popen(cmd, "r");

	sprintf(cmd, "ln -fs %s/%s /tmp/%s", pwd, ORDER_DATA, ORDER_DATA);
	popen(cmd, "r");

	sprintf(cmd, "ln -fs %s/%s /tmp/%s", pwd, ORDER_LINE_DATA, ORDER_LINE_DATA);
	popen(cmd, "r");

	sprintf(cmd, "ln -fs %s/%s /tmp/%s", pwd, NEW_ORDER_DATA, NEW_ORDER_DATA);
	popen(cmd, "r");

	return 0;
}