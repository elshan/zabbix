/*
** Zabbix
** Copyright (C) 2001-2019 Zabbix SIA
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
**/

#ifdef ZBX_CUNIT
#include <malloc.h>

#define __USE_GNU
#include <dlfcn.h>

#include "common.h"
#include "zbxtypes.h"
#include "zbxgetopt.h"
#include "dbcache.h"
#include "zbxcunit.h"

/* auto generated by make test */
#include "cu_modules.h"

#define ZBX_CU_ASSERT_ARGS_LENGTH	1024
#define ZBX_CU_ASSERT_DESC_LENGTH	256
#define ZBX_CU_ASSERT_OP_LENGTH		16
#define ZBX_CU_ASSERT_BUFFER_SIZE	(ZBX_CU_ASSERT_ARGS_LENGTH * 2 + ZBX_CU_ASSERT_DESC_LENGTH + 16 + \
		ZBX_CU_ASSERT_OP_LENGTH)

static char	cu_buffer[ZBX_CU_ASSERT_BUFFER_SIZE];

const char	*zbx_cu_assert_args_str(const char *description, const char *operation, const char *expression1,
		const char *actual, const char *expression2, const char *expected)
{
	size_t	offset = 0;

	offset = zbx_snprintf(cu_buffer + offset, ZBX_CU_ASSERT_DESC_LENGTH, "ASSERT %s: ",
			(NULL == description ? "string compare" : description));

	offset += zbx_snprintf(cu_buffer + offset, ZBX_CU_ASSERT_ARGS_LENGTH, "%s (%s)", expression1, actual);
	offset += zbx_snprintf(cu_buffer + offset, ZBX_CU_ASSERT_OP_LENGTH, " %s ", operation);
	offset += zbx_snprintf(cu_buffer + offset, ZBX_CU_ASSERT_ARGS_LENGTH, "%s (%s)", expression2, expected);

	return cu_buffer;
}

const char	*zbx_cu_assert_args_str_n(const char *description, const char *operation, const char *expression1,
		const char *actual, const char *expression2, const char *expected, size_t n)
{
	size_t	offset = 0;
	char	tmp[ZBX_CU_ASSERT_BUFFER_SIZE];

	offset = zbx_snprintf(cu_buffer + offset, ZBX_CU_ASSERT_DESC_LENGTH, "ASSERT %s: ",
			(NULL == description ? "string compare" : description), n);

	zbx_strlcpy(tmp, actual, MIN(ZBX_CU_ASSERT_BUFFER_SIZE, n + 1));
	offset += zbx_snprintf(cu_buffer + offset, ZBX_CU_ASSERT_ARGS_LENGTH, "%s (%s)", expression1, tmp);

	offset += zbx_snprintf(cu_buffer + offset, ZBX_CU_ASSERT_OP_LENGTH, " %s ", operation);

	zbx_strlcpy(tmp, expected, MIN(ZBX_CU_ASSERT_BUFFER_SIZE, n + 1));
	offset += zbx_snprintf(cu_buffer + offset, ZBX_CU_ASSERT_ARGS_LENGTH, "%s (%s)", expression2, tmp);
	offset += zbx_snprintf(cu_buffer + offset, ZBX_CU_ASSERT_ARGS_LENGTH, " // first " ZBX_FS_SIZE_T " bytes",
			(zbx_fs_size_t)n);

	return cu_buffer;
}

const char	*zbx_cu_assert_args_ui64(const char *description, const char *operation, const char *expression1,
		zbx_uint64_t actual, const char *expression2, zbx_uint64_t expected)
{
	size_t	offset = 0;

	offset = zbx_snprintf(cu_buffer + offset, ZBX_CU_ASSERT_DESC_LENGTH, "ASSERT %s: ",
			(NULL == description ? "uint64 compare" : description));

	offset += zbx_snprintf(cu_buffer + offset, ZBX_CU_ASSERT_ARGS_LENGTH, "%s (" ZBX_FS_UI64 ")", expression1,
			actual);
	offset += zbx_snprintf(cu_buffer + offset, ZBX_CU_ASSERT_OP_LENGTH, " %s ", operation);
	offset += zbx_snprintf(cu_buffer + offset, ZBX_CU_ASSERT_ARGS_LENGTH, "%s (" ZBX_FS_UI64 ")", expression2,
			expected);

	return cu_buffer;
}

const char	*zbx_cu_assert_args_dbl(const char *description, const char *operation, const char *expression1,
		double actual, const char *expression2, double expected)
{
	size_t	offset = 0;

	offset = zbx_snprintf(cu_buffer + offset, ZBX_CU_ASSERT_DESC_LENGTH, "ASSERT %s: ",
			(NULL == description ? "double compare" : description));

	offset += zbx_snprintf(cu_buffer + offset, ZBX_CU_ASSERT_ARGS_LENGTH, "%s (%f)", expression1, actual);
	offset += zbx_snprintf(cu_buffer + offset, ZBX_CU_ASSERT_OP_LENGTH, " %s ", operation);
	offset += zbx_snprintf(cu_buffer + offset, ZBX_CU_ASSERT_ARGS_LENGTH, "%s (%f)", expression2, expected);

	return cu_buffer;
}

const char	*zbx_cu_assert_args_int(const char *description, const char *operation, const char *expression1,
		int actual, const char *expression2, int expected)
{
	size_t	offset = 0;

	offset = zbx_snprintf(cu_buffer + offset, ZBX_CU_ASSERT_DESC_LENGTH, "ASSERT %s: ",
			(NULL == description ? "int compare" : description));

	offset += zbx_snprintf(cu_buffer + offset, ZBX_CU_ASSERT_ARGS_LENGTH, "%s (%d)", expression1, actual);
	offset += zbx_snprintf(cu_buffer + offset, ZBX_CU_ASSERT_OP_LENGTH, " %s ", operation);
	offset += zbx_snprintf(cu_buffer + offset, ZBX_CU_ASSERT_ARGS_LENGTH, "%s (%d)", expression2, expected);

	return cu_buffer;
}

const char	*zbx_cu_assert_args_char(const char *description, const char *operation, const char *expression1,
		char actual, const char *expression2, char expected)
{
	size_t	offset = 0;

	offset = zbx_snprintf(cu_buffer + offset, ZBX_CU_ASSERT_DESC_LENGTH, "ASSERT %s: ",
			(NULL == description ? "int compare" : description));

	offset += zbx_snprintf(cu_buffer + offset, ZBX_CU_ASSERT_ARGS_LENGTH, "%s (%c %d)", expression1, actual,
			(int)actual);
	offset += zbx_snprintf(cu_buffer + offset, ZBX_CU_ASSERT_OP_LENGTH, " %s ", operation);
	offset += zbx_snprintf(cu_buffer + offset, ZBX_CU_ASSERT_ARGS_LENGTH, "%s (%c %d)", expression2,
			expected, (int)expected);

	return cu_buffer;

}

/******************************************************************************
 *                                                                            *
 * Function: zbx_cu_run_suite                                                 *
 *                                                                            *
 * Purpose: run the specified suite (test)                                    *
 *                                                                            *
 * Parameters: suite_name - [IN] the suite/test name in format suite[:test]   *
 *                                                                            *
 ******************************************************************************/
static void	zbx_cu_run_suite(char *suite_name)
{
	CU_Suite	*suite;
	CU_Test		*test;
	char		*test_name;

	if (NULL != (test_name = strchr(suite_name, ':')))
		*test_name++ = '\0';

	for (suite = CU_get_registry()->pSuite; NULL != suite; suite = suite->pNext)
	{
		if (0 == strcmp(suite_name, suite->pName))
		{
			if (NULL == test_name)
			{
				CU_basic_run_suite(suite);
				return;
			}

			for (test = suite->pTest; NULL != test; test = test->pNext)
			{
				if (0 == strcmp(test_name, test->pName))
				{
					CU_basic_run_test(suite, test);
					return;
				}
			}
		}
	}
}

/* long options */
static struct zbx_option	longopts[] =
{
	{"test",		2,	NULL,	't'},
	{"output",		2,	NULL,	'o'},
	{NULL}
};


/* short options */
static char	shortopts[] = "t::o::";

void	zbx_cu_run(int argc, char *argv[])
{
	const char			**module;
	char				ch, *suite = NULL, *output = NULL, buffer[MAX_STRING_LEN];
	int				run_tests = 0, automated = 0, ret = EXIT_FAILURE;
	zbx_cu_init_suite_func_t	init_func;

	while ((char)EOF != (ch = (char)zbx_getopt_long(argc, argv, shortopts, longopts, NULL)))
	{
		switch (ch)
		{
			case 't':
				run_tests = 1;
				if (NULL != zbx_optarg)
					suite = zbx_strdup(NULL, zbx_optarg);
				break;
			case 'o':
				automated = 1;
				if (NULL != zbx_optarg)
					output = zbx_strdup(NULL, zbx_optarg);
		}
	}

	if (0 == run_tests)
	{
		zbx_free(output);
		return;
	}

	if (CUE_SUCCESS != CU_initialize_registry())
	{
		fprintf(stderr, "Error while initializing CUnit registry: %s\n", CU_get_error_msg());
		goto out;
	}

	for (module = cu_modules; NULL != *module; module++)
	{
		zbx_snprintf(buffer, sizeof(buffer), "%s%s", ZBX_CU_SUITE_PREFIX_STR, *module);

		if (NULL != (init_func = dlsym(RTLD_DEFAULT, buffer)))
		{
			if (CUE_SUCCESS != init_func())
			{
				fprintf(stderr, "Error while initializing CUnit tests: %s\n", CU_get_error_msg());
				goto out;
			}
		}
	}

	if (0 == automated)
	{
		CU_basic_set_mode(CU_BRM_VERBOSE);

		if (NULL != suite)
		{
			zbx_cu_run_suite(suite);
		}
		else
			CU_basic_run_tests();

		if (0 == CU_get_number_of_tests_failed())
			ret = EXIT_SUCCESS;
	}
	else
	{
		if (NULL != output)
			CU_set_output_filename(output);

		CU_automated_run_tests();
		CU_list_tests_to_file();
		ret = EXIT_SUCCESS;
	}
out:
	zbx_free(suite);
	zbx_free(output);

	exit(ret);
}

/* garbage allocator */
void	*zbx_cu_galloc(void *old, size_t size)
{
	void	*new;
	char	*p;

	new = zbx_malloc(old, size);

	for (p = new; 0 < size; p++, size--)
		*p = rand();

	return new;
}

/* human readable item type string (like in frontend) */
const char	*zbx_cu_item_type_string(zbx_item_type_t item_type)
{
	switch (item_type)
	{
		case ITEM_TYPE_ZABBIX:
			return "Zabbix agent";
		case ITEM_TYPE_SNMPv1:
			return "SNMPv1 agent";
		case ITEM_TYPE_TRAPPER:
			return "Zabbix trapper";
		case ITEM_TYPE_SIMPLE:
			return "Simple check";
		case ITEM_TYPE_SNMPv2c:
			return "SNMPv2 agent";
		case ITEM_TYPE_INTERNAL:
			return "Zabbix internal";
		case ITEM_TYPE_SNMPv3:
			return "SNMPv3 agent";
		case ITEM_TYPE_ZABBIX_ACTIVE:
			return "Zabbix agent (active)";
		case ITEM_TYPE_AGGREGATE:
			return "Zabbix aggregate";
		case ITEM_TYPE_HTTPTEST:
			return "Web monitoring";
		case ITEM_TYPE_EXTERNAL:
			return "External check";
		case ITEM_TYPE_DB_MONITOR:
			return "Database monitor";
		case ITEM_TYPE_IPMI:
			return "IPMI agent";
		case ITEM_TYPE_SSH:
			return "SSH agent";
		case ITEM_TYPE_TELNET:
			return "TELNET agent";
		case ITEM_TYPE_CALCULATED:
			return "Calculated";
		case ITEM_TYPE_JMX:
			return "JMX agent";
		case ITEM_TYPE_SNMPTRAP:
			return "SNMP trap";
		case ITEM_TYPE_DEPENDENT:
			return "Dependent item";
		default:
			return "unknown";
	}
}

/* human readable poller type string (like in get_process_type_string()) */
const char	*zbx_cu_poller_type_string(unsigned char poller_type)
{
	switch (poller_type)
	{
		case ZBX_NO_POLLER:
			return "none";
		case ZBX_POLLER_TYPE_NORMAL:
			return "poller";
		case ZBX_POLLER_TYPE_UNREACHABLE:
			return "unreachable poller";
		case ZBX_POLLER_TYPE_IPMI:
			return "ipmi poller";
		case ZBX_POLLER_TYPE_PINGER:
			return "icmp pinger";
		case ZBX_POLLER_TYPE_JAVA:
			return "java poller";
		default:
			return "unknown";
	}
}

#endif

