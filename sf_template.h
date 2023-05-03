#ifndef SF_TEMPLATE_H
#define SF_TEMPLATE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

// Change these values to match your application
#define SF_MAX_PATH_LENGTH 4096
#define SF_DEFAULT_FOLDER_PERMISSIONS S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH
#define SF_DEFAULT_FILE_PERMISSIONS S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH
#define SF_INVALID_HANDLE_VALUE -1
#define SF_PATH_SEPARATOR "/"

// Definition of a file handle
typedef int SF_HANDLE;

// Definition of a folder
typedef struct {
    char path[SF_MAX_PATH_LENGTH];
} SF_FOLDER;

// Definition of a file
typedef struct {
    char path[SF_MAX_PATH_LENGTH];
    SF_HANDLE handle;
} SF_FILE;

// Definition of a result code
typedef enum {
    SF_OK = 0,
    SF_ERROR = -1
} SF_RESULT;

// Initializes a folder object
SF_RESULT sf_folder_init(SF_FOLDER* folder, const char* path);

// Creates a folder
SF_RESULT sf_folder_create(const char* path, mode_t permissions);

// Deletes a folder and all its contents
SF_RESULT sf_folder_delete(const char* path);

// Checks if a folder exists
bool sf_folder_exists(const char* path);

// Opens a file for reading and/or writing
SF_HANDLE sf_file_open(const char* path, int flags, mode_t permissions);

// Closes a file
SF_RESULT sf_file_close(SF_HANDLE handle);

// Reads from a file
SF_RESULT sf_file_read(SF_HANDLE handle, void* buffer, size_t size, size_t* bytesRead);

// Writes to a file
SF_RESULT sf_file_write(SF_HANDLE handle, const void* buffer, size_t size, size_t* bytesWritten);

// Seeks to a position in a file
SF_RESULT sf_file_seek(SF_HANDLE handle, off_t offset, int whence);

// Gets the size of a file
SF_RESULT sf_file_get_size(const char* path, size_t* size);

// Deletes a file
SF_RESULT sf_file_delete(const char* path);

// Checks if a file exists
bool sf_file_exists(const char* path);

// Returns the last error that occurred
int sf_get_last_error();

// TGHC(-1,0,1) functions
SF_RESULT sf_tghc_minus_one(const char* path);
SF_RESULT sf_tghc_zero(const char* path);
SF_RESULT sf_tghc_plus_one(const char* path);

#endif
