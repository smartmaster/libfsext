/*
 * Info handle
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

#if !defined( _INFO_HANDLE_H )
#define _INFO_HANDLE_H

#include <common.h>
#include <file_stream.h>
#include <types.h>

#include "fsexttools_libbfio.h"
#include "fsexttools_libcerror.h"
#include "fsexttools_libfsext.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct info_handle info_handle_t;

struct info_handle
{
	/* The volume offset
	 */
	off64_t volume_offset;

	/* The libbfio input file IO handle
	 */
	libbfio_handle_t *input_file_io_handle;

	/* The libfsext input volume
	 */
	libfsext_volume_t *input_volume;

	/* The notification output stream
	 */
	FILE *notify_stream;

	/* Value to indicate if abort was signalled
	 */
	int abort;
};

int fsexttools_system_string_copy_from_64_bit_in_decimal(
     const system_character_t *string,
     size_t string_size,
     uint64_t *value_64bit,
     libcerror_error_t **error );

int info_handle_initialize(
     info_handle_t **info_handle,
     libcerror_error_t **error );

int info_handle_free(
     info_handle_t **info_handle,
     libcerror_error_t **error );

int info_handle_signal_abort(
     info_handle_t *info_handle,
     libcerror_error_t **error );

int info_handle_set_volume_offset(
     info_handle_t *info_handle,
     const system_character_t *string,
     libcerror_error_t **error );

int info_handle_open_input(
     info_handle_t *info_handle,
     const system_character_t *filename,
     libcerror_error_t **error );

int info_handle_close_input(
     info_handle_t *info_handle,
     libcerror_error_t **error );

int info_handle_posix_time_value_fprint(
     info_handle_t *info_handle,
     const char *value_name,
     uint32_t value_32bit,
     libcerror_error_t **error );

int info_handle_file_system_hierarchy_fprint_file_entry(
     info_handle_t *info_handle,
     libfsext_file_entry_t *file_entry,
     int indentation_level,
     libcerror_error_t **error );

int info_handle_file_system_hierarchy_fprint(
     info_handle_t *info_handle,
     libcerror_error_t **error );

int info_handle_inode_fprint(
     info_handle_t *info_handle,
     uint32_t inode_number,
     libcerror_error_t **error );

int info_handle_inodes_fprint(
     info_handle_t *info_handle,
     libcerror_error_t **error );

int info_handle_file_entry_fprint(
     info_handle_t *info_handle,
     const system_character_t *path,
     libcerror_error_t **error );

int info_handle_volume_fprint(
     info_handle_t *info_handle,
     libcerror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _INFO_HANDLE_H ) */

