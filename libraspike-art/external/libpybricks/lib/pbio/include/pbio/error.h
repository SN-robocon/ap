// SPDX-License-Identifier: MIT
// Copyright (c) 2018-2022 The Pybricks Authors

/**
 * @addtogroup Error pbio/error: Error handling
 * @{
 */


#ifndef _PBIO_ERROR_H_
#define _PBIO_ERROR_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Error code.
 */
typedef enum {
    PBIO_SUCCESS,               /**< No error */
    PBIO_ERROR_FAILED,          /**< Unspecified error (used when no other error code fits) */
    PBIO_ERROR_INVALID_ARG,     /**< Invalid argument */
    PBIO_ERROR_IO,              /**< General I/O error */
    PBIO_ERROR_BUSY,            /**< Device or resource is busy */
    PBIO_ERROR_NO_DEV,          /**< Device is not connected */
    PBIO_ERROR_NOT_IMPLEMENTED, /**< Feature is not yet implemented */
    PBIO_ERROR_NOT_SUPPORTED,   /**< Feature is not supported on this device */
    PBIO_ERROR_AGAIN,           /**< Function should be called again later */
    PBIO_ERROR_INVALID_OP,      /**< Operation is not permitted in the current state */
    PBIO_ERROR_TIMEDOUT,        /**< The operation has timed out */
    PBIO_ERROR_CANCELED         /**< The operation was canceled */
} pbio_error_t;

const char *pbio_error_str(pbio_error_t err);

#ifdef __cplusplus
}
#endif

#endif // _PBIO_ERROR_H_

/** @} */
