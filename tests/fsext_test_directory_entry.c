/*
 * Library directory_entry type test program
 *
 * Copyright (C) 2010-2018, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <file_stream.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "fsext_test_libcerror.h"
#include "fsext_test_libfsext.h"
#include "fsext_test_macros.h"
#include "fsext_test_memory.h"
#include "fsext_test_unused.h"

#include "../libfsext/libfsext_directory_entry.h"

#if defined( __GNUC__ ) && !defined( LIBFSEXT_DLL_IMPORT )

/* Tests the libfsext_directory_entry_initialize function
 * Returns 1 if successful or 0 if not
 */
int fsext_test_directory_entry_initialize(
     void )
{
	libcerror_error_t *error                    = NULL;
	libfsext_directory_entry_t *directory_entry = NULL;
	int result                                  = 0;

#if defined( HAVE_FSEXT_TEST_MEMORY )
	int number_of_malloc_fail_tests             = 1;
	int number_of_memset_fail_tests             = 1;
	int test_number                             = 0;
#endif

	/* Test regular cases
	 */
	result = libfsext_directory_entry_initialize(
	          &directory_entry,
	          &error );

	FSEXT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FSEXT_TEST_ASSERT_IS_NOT_NULL(
	 "directory_entry",
	 directory_entry );

	FSEXT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfsext_directory_entry_free(
	          &directory_entry,
	          &error );

	FSEXT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FSEXT_TEST_ASSERT_IS_NULL(
	 "directory_entry",
	 directory_entry );

	FSEXT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfsext_directory_entry_initialize(
	          NULL,
	          &error );

	FSEXT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FSEXT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	directory_entry = (libfsext_directory_entry_t *) 0x12345678UL;

	result = libfsext_directory_entry_initialize(
	          &directory_entry,
	          &error );

	FSEXT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FSEXT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	directory_entry = NULL;

#if defined( HAVE_FSEXT_TEST_MEMORY )

	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test libfsext_directory_entry_initialize with malloc failing
		 */
		fsext_test_malloc_attempts_before_fail = test_number;

		result = libfsext_directory_entry_initialize(
		          &directory_entry,
		          &error );

		if( fsext_test_malloc_attempts_before_fail != -1 )
		{
			fsext_test_malloc_attempts_before_fail = -1;

			if( directory_entry != NULL )
			{
				libfsext_directory_entry_free(
				 &directory_entry,
				 NULL );
			}
		}
		else
		{
			FSEXT_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			FSEXT_TEST_ASSERT_IS_NULL(
			 "directory_entry",
			 directory_entry );

			FSEXT_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
	for( test_number = 0;
	     test_number < number_of_memset_fail_tests;
	     test_number++ )
	{
		/* Test libfsext_directory_entry_initialize with memset failing
		 */
		fsext_test_memset_attempts_before_fail = test_number;

		result = libfsext_directory_entry_initialize(
		          &directory_entry,
		          &error );

		if( fsext_test_memset_attempts_before_fail != -1 )
		{
			fsext_test_memset_attempts_before_fail = -1;

			if( directory_entry != NULL )
			{
				libfsext_directory_entry_free(
				 &directory_entry,
				 NULL );
			}
		}
		else
		{
			FSEXT_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			FSEXT_TEST_ASSERT_IS_NULL(
			 "directory_entry",
			 directory_entry );

			FSEXT_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
#endif /* defined( HAVE_FSEXT_TEST_MEMORY ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( directory_entry != NULL )
	{
		libfsext_directory_entry_free(
		 &directory_entry,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfsext_directory_entry_free function
 * Returns 1 if successful or 0 if not
 */
int fsext_test_directory_entry_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libfsext_directory_entry_free(
	          NULL,
	          &error );

	FSEXT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FSEXT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfsext_directory_entry_clone function
 * Returns 1 if successful or 0 if not
 */
int fsext_test_directory_entry_clone(
     void )
{
	libcerror_error_t *error                                = NULL;
	libfsext_directory_entry_t *destination_directory_entry = NULL;
	libfsext_directory_entry_t *source_directory_entry      = NULL;
	int result                                              = 0;

	/* Initialize test
	 */
	result = libfsext_directory_entry_initialize(
	          &source_directory_entry,
	          &error );

	FSEXT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FSEXT_TEST_ASSERT_IS_NOT_NULL(
	 "source_directory_entry",
	 source_directory_entry );

	FSEXT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfsext_directory_entry_clone(
	          &destination_directory_entry,
	          source_directory_entry,
	          &error );

	FSEXT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FSEXT_TEST_ASSERT_IS_NOT_NULL(
	 "destination_directory_entry",
	 destination_directory_entry );

	FSEXT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfsext_directory_entry_free(
	          &destination_directory_entry,
	          &error );

	FSEXT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FSEXT_TEST_ASSERT_IS_NULL(
	 "destination_directory_entry",
	 destination_directory_entry );

	FSEXT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfsext_directory_entry_clone(
	          &destination_directory_entry,
	          NULL,
	          &error );

	FSEXT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FSEXT_TEST_ASSERT_IS_NULL(
	 "destination_directory_entry",
	 destination_directory_entry );

	FSEXT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfsext_directory_entry_clone(
	          NULL,
	          source_directory_entry,
	          &error );

	FSEXT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FSEXT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	destination_directory_entry = (libfsext_directory_entry_t *) 0x12345678UL;

	result = libfsext_directory_entry_clone(
	          &destination_directory_entry,
	          source_directory_entry,
	          &error );

	FSEXT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FSEXT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	destination_directory_entry = NULL;

#if defined( HAVE_FSEXT_TEST_MEMORY )

	/* Test libfsext_directory_entry_clone with malloc failing
	 */
	fsext_test_malloc_attempts_before_fail = 0;

	result = libfsext_directory_entry_clone(
	          &destination_directory_entry,
	          source_directory_entry,
	          &error );

	if( fsext_test_malloc_attempts_before_fail != -1 )
	{
		fsext_test_malloc_attempts_before_fail = -1;

		if( destination_directory_entry != NULL )
		{
			libfsext_directory_entry_free(
			 &destination_directory_entry,
			 NULL );
		}
	}
	else
	{
		FSEXT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		FSEXT_TEST_ASSERT_IS_NULL(
		 "destination_directory_entry",
		 destination_directory_entry );

		FSEXT_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}

	/* Test libfsext_directory_entry_clone with memcpy failing
	 */
	fsext_test_memcpy_attempts_before_fail = 0;

	result = libfsext_directory_entry_clone(
	          &destination_directory_entry,
	          source_directory_entry,
	          &error );

	if( fsext_test_memcpy_attempts_before_fail != -1 )
	{
		fsext_test_memcpy_attempts_before_fail = -1;

		if( destination_directory_entry != NULL )
		{
			libfsext_directory_entry_free(
			 &destination_directory_entry,
			 NULL );
		}
	}
	else
	{
		FSEXT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		FSEXT_TEST_ASSERT_IS_NULL(
		 "destination_directory_entry",
		 destination_directory_entry );

		FSEXT_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
#endif /* defined( HAVE_FSEXT_TEST_MEMORY ) */

	/* Clean up
	 */
	result = libfsext_directory_entry_free(
	          &source_directory_entry,
	          &error );

	FSEXT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FSEXT_TEST_ASSERT_IS_NULL(
	 "source_directory_entry",
	 source_directory_entry );

	FSEXT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( destination_directory_entry != NULL )
	{
		libfsext_directory_entry_free(
		 &destination_directory_entry,
		 NULL );
	}
	if( source_directory_entry != NULL )
	{
		libfsext_directory_entry_free(
		 &source_directory_entry,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfsext_directory_entry_get_utf8_name_size function
 * Returns 1 if successful or 0 if not
 */
int fsext_test_directory_entry_get_utf8_name_size(
     void )
{
	libcerror_error_t *error                    = NULL;
	libfsext_directory_entry_t *directory_entry = NULL;
	size_t utf8_name_size                       = 0;
	int result                                  = 0;
	int utf8_name_size_is_set                   = 0;

	/* Initialize test
	 */
	result = libfsext_directory_entry_initialize(
	          &directory_entry,
	          &error );

	FSEXT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FSEXT_TEST_ASSERT_IS_NOT_NULL(
	 "directory_entry",
	 directory_entry );

	FSEXT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfsext_directory_entry_get_utf8_name_size(
	          directory_entry,
	          &utf8_name_size,
	          &error );

	FSEXT_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FSEXT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf8_name_size_is_set = result;

	/* Test error cases
	 */
	result = libfsext_directory_entry_get_utf8_name_size(
	          NULL,
	          &utf8_name_size,
	          &error );

	FSEXT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FSEXT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	if( utf8_name_size_is_set != 0 )
	{
		result = libfsext_directory_entry_get_utf8_name_size(
		          directory_entry,
		          NULL,
		          &error );

		FSEXT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		FSEXT_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Clean up
	 */
	result = libfsext_directory_entry_free(
	          &directory_entry,
	          &error );

	FSEXT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FSEXT_TEST_ASSERT_IS_NULL(
	 "directory_entry",
	 directory_entry );

	FSEXT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( directory_entry != NULL )
	{
		libfsext_directory_entry_free(
		 &directory_entry,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfsext_directory_entry_get_utf8_name function
 * Returns 1 if successful or 0 if not
 */
int fsext_test_directory_entry_get_utf8_name(
     void )
{
	uint8_t utf8_name[ 512 ];

	libcerror_error_t *error                    = NULL;
	libfsext_directory_entry_t *directory_entry = NULL;
	int result                                  = 0;
	int utf8_name_is_set                        = 0;

	/* Initialize test
	 */
	result = libfsext_directory_entry_initialize(
	          &directory_entry,
	          &error );

	FSEXT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FSEXT_TEST_ASSERT_IS_NOT_NULL(
	 "directory_entry",
	 directory_entry );

	FSEXT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfsext_directory_entry_get_utf8_name(
	          directory_entry,
	          utf8_name,
	          512,
	          &error );

	FSEXT_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FSEXT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf8_name_is_set = result;

	/* Test error cases
	 */
	result = libfsext_directory_entry_get_utf8_name(
	          NULL,
	          utf8_name,
	          512,
	          &error );

	FSEXT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FSEXT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	if( utf8_name_is_set != 0 )
	{
		result = libfsext_directory_entry_get_utf8_name(
		          directory_entry,
		          NULL,
		          512,
		          &error );

		FSEXT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		FSEXT_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );

		result = libfsext_directory_entry_get_utf8_name(
		          directory_entry,
		          utf8_name,
		          0,
		          &error );

		FSEXT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		FSEXT_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );

		result = libfsext_directory_entry_get_utf8_name(
		          directory_entry,
		          utf8_name,
		          (size_t) SSIZE_MAX + 1,
		          &error );

		FSEXT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		FSEXT_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Clean up
	 */
	result = libfsext_directory_entry_free(
	          &directory_entry,
	          &error );

	FSEXT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FSEXT_TEST_ASSERT_IS_NULL(
	 "directory_entry",
	 directory_entry );

	FSEXT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( directory_entry != NULL )
	{
		libfsext_directory_entry_free(
		 &directory_entry,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfsext_directory_entry_get_utf16_name_size function
 * Returns 1 if successful or 0 if not
 */
int fsext_test_directory_entry_get_utf16_name_size(
     void )
{
	libcerror_error_t *error                    = NULL;
	libfsext_directory_entry_t *directory_entry = NULL;
	size_t utf16_name_size                      = 0;
	int result                                  = 0;
	int utf16_name_size_is_set                  = 0;

	/* Initialize test
	 */
	result = libfsext_directory_entry_initialize(
	          &directory_entry,
	          &error );

	FSEXT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FSEXT_TEST_ASSERT_IS_NOT_NULL(
	 "directory_entry",
	 directory_entry );

	FSEXT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfsext_directory_entry_get_utf16_name_size(
	          directory_entry,
	          &utf16_name_size,
	          &error );

	FSEXT_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FSEXT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf16_name_size_is_set = result;

	/* Test error cases
	 */
	result = libfsext_directory_entry_get_utf16_name_size(
	          NULL,
	          &utf16_name_size,
	          &error );

	FSEXT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FSEXT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	if( utf16_name_size_is_set != 0 )
	{
		result = libfsext_directory_entry_get_utf16_name_size(
		          directory_entry,
		          NULL,
		          &error );

		FSEXT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		FSEXT_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Clean up
	 */
	result = libfsext_directory_entry_free(
	          &directory_entry,
	          &error );

	FSEXT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FSEXT_TEST_ASSERT_IS_NULL(
	 "directory_entry",
	 directory_entry );

	FSEXT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( directory_entry != NULL )
	{
		libfsext_directory_entry_free(
		 &directory_entry,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfsext_directory_entry_get_utf16_name function
 * Returns 1 if successful or 0 if not
 */
int fsext_test_directory_entry_get_utf16_name(
     void )
{
	uint16_t utf16_name[ 512 ];

	libcerror_error_t *error                    = NULL;
	libfsext_directory_entry_t *directory_entry = NULL;
	int result                                  = 0;
	int utf16_name_is_set                       = 0;

	/* Initialize test
	 */
	result = libfsext_directory_entry_initialize(
	          &directory_entry,
	          &error );

	FSEXT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FSEXT_TEST_ASSERT_IS_NOT_NULL(
	 "directory_entry",
	 directory_entry );

	FSEXT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfsext_directory_entry_get_utf16_name(
	          directory_entry,
	          utf16_name,
	          512,
	          &error );

	FSEXT_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FSEXT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf16_name_is_set = result;

	/* Test error cases
	 */
	result = libfsext_directory_entry_get_utf16_name(
	          NULL,
	          utf16_name,
	          512,
	          &error );

	FSEXT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FSEXT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	if( utf16_name_is_set != 0 )
	{
		result = libfsext_directory_entry_get_utf16_name(
		          directory_entry,
		          NULL,
		          512,
		          &error );

		FSEXT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		FSEXT_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );

		result = libfsext_directory_entry_get_utf16_name(
		          directory_entry,
		          utf16_name,
		          0,
		          &error );

		FSEXT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		FSEXT_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );

		result = libfsext_directory_entry_get_utf16_name(
		          directory_entry,
		          utf16_name,
		          (size_t) SSIZE_MAX + 1,
		          &error );

		FSEXT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		FSEXT_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Clean up
	 */
	result = libfsext_directory_entry_free(
	          &directory_entry,
	          &error );

	FSEXT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FSEXT_TEST_ASSERT_IS_NULL(
	 "directory_entry",
	 directory_entry );

	FSEXT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( directory_entry != NULL )
	{
		libfsext_directory_entry_free(
		 &directory_entry,
		 NULL );
	}
	return( 0 );
}

#endif /* defined( __GNUC__ ) && !defined( LIBFSEXT_DLL_IMPORT ) */

/* The main program
 */
#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc FSEXT_TEST_ATTRIBUTE_UNUSED,
     wchar_t * const argv[] FSEXT_TEST_ATTRIBUTE_UNUSED )
#else
int main(
     int argc FSEXT_TEST_ATTRIBUTE_UNUSED,
     char * const argv[] FSEXT_TEST_ATTRIBUTE_UNUSED )
#endif
{
	FSEXT_TEST_UNREFERENCED_PARAMETER( argc )
	FSEXT_TEST_UNREFERENCED_PARAMETER( argv )

#if defined( __GNUC__ ) && !defined( LIBFSEXT_DLL_IMPORT )

	FSEXT_TEST_RUN(
	 "libfsext_directory_entry_initialize",
	 fsext_test_directory_entry_initialize );

	FSEXT_TEST_RUN(
	 "libfsext_directory_entry_free",
	 fsext_test_directory_entry_free );

	FSEXT_TEST_RUN(
	 "libfsext_directory_entry_clone",
	 fsext_test_directory_entry_clone );

	/* TODO: add tests for libfsext_directory_entry_read_data */

#ifdef TODO

	FSEXT_TEST_RUN(
	 "libfsext_directory_entry_get_utf8_name_size",
	 fsext_test_directory_entry_get_utf8_name_size );

	FSEXT_TEST_RUN(
	 "libfsext_directory_entry_get_utf8_name",
	 fsext_test_directory_entry_get_utf8_name );

	FSEXT_TEST_RUN(
	 "libfsext_directory_entry_get_utf16_name_size",
	 fsext_test_directory_entry_get_utf16_name_size );

	FSEXT_TEST_RUN(
	 "libfsext_directory_entry_get_utf16_name",
	 fsext_test_directory_entry_get_utf16_name );

#endif /* TODO */

#endif /* defined( __GNUC__ ) && !defined( LIBFSEXT_DLL_IMPORT ) */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

