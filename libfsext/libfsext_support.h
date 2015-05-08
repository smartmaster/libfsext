/*
 * Support functions
 *
 * Copyright (C) 2010-2015, Joachim Metz <joachim.metz@gmail.com>
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

#if !defined( _LIBFSEXT_SUPPORT_H )
#define _LIBFSEXT_SUPPORT_H

#include <common.h>
#include <types.h>

#include "libfsext_extern.h"
#include "libfsext_libbfio.h"
#include "libfsext_libcerror.h"

#if defined( __cplusplus )
extern "C" {
#endif

#if !defined( HAVE_LOCAL_LIBFSEXT )

LIBFSEXT_EXTERN \
const char *libfsext_get_version(
             void );

LIBFSEXT_EXTERN \
int libfsext_get_access_flags_read(
     void );

LIBFSEXT_EXTERN \
int libfsext_get_codepage(
     int *codepage,
     libcerror_error_t **error );

LIBFSEXT_EXTERN \
int libfsext_set_codepage(
     int codepage,
     libcerror_error_t **error );

#endif /* !defined( HAVE_LOCAL_LIBFSEXT ) */

LIBFSEXT_EXTERN \
int libfsext_check_volume_signature(
     const char *filename,
     libcerror_error_t **error );

#if defined( HAVE_WIDE_CHARACTER_TYPE )

LIBFSEXT_EXTERN \
int libfsext_check_volume_signature_wide(
     const wchar_t *filename,
     libcerror_error_t **error );

#endif /* defined( HAVE_WIDE_CHARACTER_TYPE ) */

LIBFSEXT_EXTERN \
int libfsext_check_volume_signature_file_io_handle(
     libbfio_handle_t *file_io_handle,
     libcerror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif
